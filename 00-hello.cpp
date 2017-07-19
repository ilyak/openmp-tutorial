#include <iostream>

int
main()
{
#ifdef _OPENMP
	std::cout << "Hello, OpenMP!" << std::endl;
#else
	std::cout << "OpenMP is not enabled." << std::endl;
#endif
	return 0;
}

// XXX: try compiling with and without -openmp compiler flag
