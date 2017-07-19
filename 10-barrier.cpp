#include <stdio.h>
#include <omp.h>

int
main()
{
#pragma omp parallel
{
	printf("Hello from thread %d of %d\n", omp_get_thread_num(),
	    omp_get_num_threads());
#pragma omp barrier // all threads wait here
	printf("Thread %d of %d have passed the barrier\n",
	    omp_get_thread_num(), omp_get_num_threads());
}
	return 0;
}

// XXX: execute with OMP_NUM_THREADS=10
// XXX: try removing the barrier
