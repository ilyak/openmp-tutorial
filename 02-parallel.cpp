#include <stdio.h>
#include <omp.h>

int
main()
{
#pragma omp parallel // OpenMP parallel region
{
	// this will be executed in parallel by N threads
	printf("Hello from thread %d of %d\n", omp_get_thread_num(),
	    omp_get_num_threads());
}
	return 0;
}

// XXX: execute with OMP_NUM_THREADS=2 and OMP_NUM_THREADS=3
// XXX: add num_threads(5) to pragma omp parallel
