#include <iostream>
#include <sstream>
#include <omp.h>

int
main()
{
#pragma omp parallel
{
	std::cout << "Hello from thread " << omp_get_thread_num() << " of " <<
	    omp_get_num_threads() << std::endl;
}
	return 0;
}

// XXX: why the output is mangled?
// XXX: use std::stringstream to fix it
