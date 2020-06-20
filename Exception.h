#pragma once
#include <exception>
#include <string>

namespace Ts
{
	class TabuSearchException : std::exception
	{
		std::string error;
	public:
		explicit TabuSearchException(const std::string& str) noexcept : error(str) {};
		const char* what() const noexcept override
		{
			return error.c_str();
		}
	};

	class FileTsException : TabuSearchException
	{
	public:
		explicit FileTsException(const std::string& str) noexcept : TabuSearchException(str) {};
	};

	class NegativeWeightException : TabuSearchException
	{
	public:
		explicit NegativeWeightException(const std::string& str) noexcept : TabuSearchException(str) {};
	};

	class MatrixIndexTsException : TabuSearchException
	{
	public:
		explicit MatrixIndexTsException(const std::string& str) noexcept : TabuSearchException(str) {};
	};
}