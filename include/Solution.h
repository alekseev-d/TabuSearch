#pragma once
#include <vector>
#include "Matrix.h"

namespace Ts
{
	class Solution
	{
		double score;
		int count;
		std::vector<int> solution_id;
		Matrix<double> matrix;

	public:
		Solution(const Matrix<double>& mtx, int num);
		Solution(const Solution& other);

		~Solution() = default;

		Solution(Solution&& other) = delete;

		Solution& operator = (const Solution& other) = delete;
		Solution& operator = (Solution&& other) = delete;

		void init_solution();

		int get_solution(int key);
		double get_score();

		void set(int key, int value);

		void print_result();
		void swap_solve(int i, int j);
	};
}