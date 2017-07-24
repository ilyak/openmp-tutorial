#include <iostream>
#include <omp.h>

// omp critical -> execute by one thread at a time
// omp single   -> execute by any one thread
// omp master   -> execute by the master thread (id == 0)

int
main()
{
#pragma omp parallel num_threads(8)
{
#pragma omp critical
	std::cout << "Hello from thread " << omp_get_thread_num() << " of " <<
	    omp_get_num_threads() << std::endl;
}
	return 0;
}

// XXX: what happens when we change "critical" to "single"?
// XXX: what happens when we change "critical" to "master"?
