#include <iostream>
#include "TabuSearch.h"
#include "Matrix.h"

int main(int argc, char* argv)
{
	try
	{
		Ts::TabuSearch test("tests/test.txt");
		test.search(10);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}