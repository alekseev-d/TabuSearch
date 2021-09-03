#include <iostream>
#include <time.h>
#include "Solution.h"

namespace Ts
{
	Solution::Solution(const Matrix<double>& mtx, int num) : matrix(mtx)
	{
		count = num;
		solution_id.reserve(count);
		score = 0;
		init_solution();
	}

	Solution::Solution(const Solution& other)
	{
		score = other.score;
		count = other.count;
		solution_id = other.solution_id;
		matrix = other.matrix;
	}

	void Solution::init_solution()
	{
		for (int i = 0; i < count; i++)
		{
			solution_id.push_back(i);
		}
		srand(time(NULL));
		for (int i = (count - 1); i >= 0; i--)
		{
			int j = rand() % count;
			std::swap(solution_id[i], solution_id[j]);
		}
		get_score();
	}

	int Solution::get_solution(int key)
	{
		return solution_id[key];
	}

	double Solution::get_score()
	{
		score = 0;
		for (int i = 0; i < count - 1; ++i)
		{
			score += matrix[solution_id[i]][solution_id[i + 1]];
		}
		score += matrix[solution_id[count - 1]][solution_id[0]];
		return score;
	}

	void Solution::set(int key, int value)
	{
		solution_id[key] = value;
	}

	void Solution::print_result()
	{
		std::cout << "The best way: ";
		for (int i = 0; i < count - 1; i++)
		{
			std::cout << solution_id[i] + 1 << " -> ";
		}
		std::cout << solution_id[count - 1] + 1 << " -> " << solution_id[0] + 1 << std::endl;
		std::cout << "The best score: " << this->get_score() << std::endl;
	}

	void Solution::swap_solve(int i, int j)
	{
		std::swap(solution_id[i], solution_id[j]);
	}
}