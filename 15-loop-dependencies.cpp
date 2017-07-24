#include <iostream>
#include <omp.h>

int
main()
{
	const int n = 10000;
	long a[n];

	for (int i = 0; i < n; i++)
		a[i] = i;

	for (int i = 1; i < n; i++)
		a[i] += a[i-1];

	std::cout << a[n-1];
	return 0;
}

// XXX: parallelize the second loop
// XXX: why the result is incorrect and how to fix it?
