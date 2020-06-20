#include "TabuSearch.h"
#include "Exception.h"
#include <fstream>
#include <iostream>
#include <algorithm>

namespace Ts
{
	const int TABU_LENGTH = 30;
	const int NUM_INTERATION = 100;
	const int PENAL_LONG_TERM = 10;
	const int LONG_TERM_LENGTH = 100;
	const int TIME_TRY = 500;

	TabuSearch::TabuSearch(const std::string& file_path)
	{
		std::ifstream file(file_path);

		if (!file.is_open())
		{
			throw FileTsException("Tabu Search Exception: File Open Error ");
		}

		file >> count;

		Matrix<double> matrix(count);
		for (int i = 0; i < count; ++i)
		{
			for (int j = 0; j < count; ++j)
			{
				file >> matrix[i][j];
				if (matrix[i][j] < 0)
				{
					throw NegativeWeightException("Tabu Search Exception: Negative Weight Error ");
				}
			}
		}

		s = new Solution(matrix, count);
		best_score = std::numeric_limits<double>::max();

		tabu_list.set_size(count);
		tabu_f_list.set_size(count);
		reset_tabu();
	}

	TabuSearch::~TabuSearch() noexcept
	{
		delete s;
	}

	void TabuSearch::reset_tabu()
	{
		tabu_list.reset();
		tabu_f_list.reset();
	}

	void TabuSearch::search(int count_candidate)
	{
		Solution best_solution(*s);
		double best_solution_score = best_solution.get_score();

		for (int i = 0; i < count_candidate; ++i)
		{
			s->init_solution();
			reset_tabu();
			best_score = std::numeric_limits<double>::max();

			int count_time = 0;
			for (int i = 0; i < NUM_INTERATION; i++)
			{
				s = get_best_interim_solution(i);
				double score = s->get_score();
				if (score < best_score)
				{
					best_score = score;
					count_time = 0;

					if (best_score < best_solution_score)
					{
						for (int j = 0; j < count; j++)
						{
							best_solution.set(j, s->get_solution(j));
						}
						best_solution_score = best_score;
					}
				}
				else
				{
					count_time++;
					if (count_time > TIME_TRY)
					{
						break;
					}
				}
			}
		}
		best_solution.print_result();
	}

	Solution* TabuSearch::get_best_interim_solution(int iterator)
	{
		double bestScore = std::numeric_limits<double>::max();;
		int vertexA = 0;
		int vertexB = 1;
		for (int i = 0; i < count; i++)
		{
			for (int j = (i + 1); j < count; j++)
			{
				s->swap_solve(i, j);
				double currentScore = s->get_score();
				double penalScore = currentScore + (double)PENAL_LONG_TERM * (double)tabu_f_list[i][j];
				if ((bestScore > penalScore&& tabu_list[i][j] <= iterator) || currentScore < best_score)
				{
					vertexA = i;
					vertexB = j;
					bestScore = penalScore;
					tabu_list[i][j] = (iterator + TABU_LENGTH);
					tabu_list[j][i] = (iterator + TABU_LENGTH);
				}
				s->swap_solve(j, i);
				if (tabu_f_list[i][j] > 0 && iterator > LONG_TERM_LENGTH)
				{
					tabu_f_list[i][j] -= 1;
				}
			}
		}
		tabu_f_list[vertexA][vertexB] += 2;
		s->swap_solve(vertexA, vertexB);
		return s;
	}
}

