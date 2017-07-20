#include <stdio.h>
#include <omp.h>

int
main()
{
#pragma omp parallel sections num_threads(4)
{
#pragma omp section // independent thread
	{
		printf("section 1, thread %d\n", omp_get_thread_num());
	}
#pragma omp section // independent thread
	{
		printf("section 2, thread %d\n", omp_get_thread_num());
	}
#pragma omp section // independent thread
	{
		printf("section 3, thread %d\n", omp_get_thread_num());
	}
	// printf("not in omp section"); // error - code must be in section
}
	return 0;
}

// XXX: change num_threads to 2
