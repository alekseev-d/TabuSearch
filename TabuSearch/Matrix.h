#pragma once
#include <iostream>
#include "Exception.h"

namespace Ts
{
	template<typename T>
	class Matrix
	{
		T** matrix;
		int size;

	public:
		Matrix() : size(0), matrix(nullptr) {}

		Matrix(int count) : size(count)
		{
			if (count == 0)
			{
				matrix = nullptr;
			}
			else
			{
				matrix = new T * [size];
				for (int i = 0; i < size; ++i)
				{
					matrix[i] = new T[size];
					for (int j = 0; j < size; ++j)
					{
						matrix[i][j] = 0;
					}
				}
			}
		}

		Matrix(const Matrix& other)
		{
			size = other.size;
			matrix = new T * [size];
			for (int i = 0; i < size; ++i)
			{
				matrix[i] = new T[size];
				for (int j = 0; j < size; ++j)
				{
					matrix[i][j] = other.matrix[i][j];
				}
			}
		}

		Matrix(Matrix&& other) = delete;

		Matrix& operator =(const Matrix& other)
		{
			if (other.size == 0)
			{
				matrix = nullptr;
			}
			else
			{
				size = other.size;
				matrix = new T * [size];
				for (int i = 0; i < size; ++i)
				{
					matrix[i] = new T[size];
					for (int j = 0; j < size; ++j)
					{
						matrix[i][j] = other.matrix[i][j];
					}
				}
			}
			return *this;
		}

		Matrix& operator =(Matrix&& other)
		{
			if (other.size == 0)
			{
				matrix = nullptr;
			}
			else
			{
				size = other.size;
				other.size = 0;

				matrix = new T * [size];
				for (int i = 0; i < size; ++i)
				{
					matrix[i] = new T[size];
					for (int j = 0; j < size; ++j)
					{
						matrix[i][j] = other.matrix[i][j];
					}
				}

				for (int i = 0; i < size; ++i)
				{
					delete[]other.matrix[i];
				}
				delete[]other.matrix;
			}
		}

		T* operator[](size_t index)
		{
			if (index < 0 || index >= size)
			{
				throw MatrixIndexTsException("Tabu Search Exception: Matrix Out of Range Error ");
			}
			return matrix[index];
		}

		friend std::ostream& operator<<(std::ostream& stream, const Matrix& mtx)
		{
			size_t size = mtx.get_size();
			for (size_t i = 0; i < size; ++i)
			{
				for (size_t j = 0; j < size; ++j)
				{
					std::cout << mtx.matrix[i][j] << "   ";
				}
				std::cout << std::endl;
			}
			return stream;
		}

		~Matrix()
		{
			for (int i = 0; i < size; ++i)
			{
				delete[]matrix[i];
			}
			delete[]matrix;
		}

		int get_size() const
		{
			return size;
		}

		void set_size(int count)
		{
			if (count == 0)
			{
				matrix = nullptr;
			}
			else
			{
				size = count;
				matrix = new T * [count];
				for (int i = 0; i < count; ++i)
				{
					matrix[i] = new T[count];
					for (int j = 0; j < count; ++j)
					{
						matrix[i][j] = 0;
					}
				}
			}
		}

		void reset()
		{
			for (int i = 0; i < size; ++i)
			{
				for (int j = 0; j < size; ++j)
				{
					matrix[i][j] = 0;
				}
			}
		}
	};
}