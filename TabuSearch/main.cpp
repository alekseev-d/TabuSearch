#include <iostream>
#include "TabuSearch.h"
#include "Matrix.h"
#include <ctime>

int main(int argc, char* argv)
{
	try
	{
		unsigned int start_time = clock(); 
		Ts::TabuSearch test("tests/test.txt");
		test.search(10);
		unsigned int end_time = clock();
		std::cout << std::endl << "Working time: " << (double)(end_time - start_time)/1000;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}