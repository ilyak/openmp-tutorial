#include <iostream>

// main OpenMP include header
#include <omp.h>

int
main()
{
	// omp_get_max_threads() and many other functions are declared in omp.h
	std::cout << "OpenMP will use " << omp_get_max_threads() <<
	    " threads maximum." << std::endl;
	return 0;
}

// XXX: execute with OMP_NUM_THREADS=2 and OMP_NUM_THREADS=3
