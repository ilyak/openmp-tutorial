#include <stdio.h>
#include <omp.h>

int
main()
{
	int i = 10;

#pragma omp parallel private(i)
{
	// 'i' is uninitialized here since it is thread-private
	printf("thread %d, i = %d\n", omp_get_thread_num(), i);
	i = 200 + omp_get_thread_num();
}
	printf("i = %d\n", i);
	return 0;
}

// XXX: change private to firstprivate to initialize 'i'
