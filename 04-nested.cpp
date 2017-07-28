#include <stdio.h>
#include <omp.h>

int
main()
{
	omp_set_nested(1); // enable nested parallelism (also, OMP_NESTED)

#pragma omp parallel num_threads(2)
{
	printf("Level 1, thread %d of %d\n", omp_get_thread_num(),
	    omp_get_num_threads());
#pragma omp parallel num_threads(2)
{
	printf("Level 2, thread %d of %d\n", omp_get_thread_num(),
	    omp_get_num_threads());
}
}
	return 0;
}

// XXX: try disabling nested parallelism
// XXX: be careful - don't create too many threads in your programs
