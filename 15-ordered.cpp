#include <stdio.h>
#include <omp.h>

int
main()
{
	const int niter = 10;

#pragma omp parallel for ordered // loop must be marked as ordered
	for (int i = 0; i < niter; i++) {
		int thr = omp_get_thread_num();
		printf("unordered iter %d of %d on thread %d\n", i, niter, thr);
#pragma omp ordered
		printf("ordered iter %d of %d on thread %d\n", i, niter, thr);
	}

	return 0;
}
