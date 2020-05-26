#pragma once
#include <string>
#include "Solution.h"
#include "Matrix.h"

namespace Ts
{
	class TabuSearch
	{
		int count;
		double best_score;

		Matrix<int> tabu_list;
		Matrix<int> tabu_f_list;

		Solution* s;

		friend class Solution;
	public:
		explicit TabuSearch(const std::string& file_path);
		~TabuSearch() noexcept;

		TabuSearch() = delete;
		TabuSearch(const TabuSearch& other) = delete;
		TabuSearch(TabuSearch&& other) = delete;

		TabuSearch& operator = (const TabuSearch& other) = delete;
		TabuSearch& operator = (TabuSearch&& other) = delete;

		void search(int count_candidate);
		Solution* get_best_interim_solution(int iterator);
		void reset_tabu();
	};
}
