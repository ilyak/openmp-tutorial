#include <stdio.h>
#include <omp.h>
#include <unistd.h>

int
main()
{
#pragma omp parallel sections num_threads(4)
{
#pragma omp section // independent thread
	{
		int thr = omp_get_thread_num();
		printf("section 1, thread %d - sleeping 1 second\n", thr);
		sleep(1);
		printf("section 1 done\n");
	}
#pragma omp section // independent thread
	{
		int thr = omp_get_thread_num();
		printf("section 2, thread %d - sleeping 2 second\n", thr);
		sleep(2);
		printf("section 2 done\n");
	}
#pragma omp section // independent thread
	{
		int thr = omp_get_thread_num();
		printf("section 3, thread %d - sleeping 3 second\n", thr);
		sleep(3);
		printf("section 3 done\n");
	}
	// printf("not in omp section"); // error - code must be in section
}
	return 0;
}

// XXX: what happens when we change num_threads to 2
