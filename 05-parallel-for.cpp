#include <iostream>

int
main()
{
	const int size = 50;
	int a[size];

#pragma omp parallel for
	for (int i = 0; i < size; i++)
		a[i] = i; // loop iterations are executed in parallel

	for (int i = 0; i < size; i++)
		std::cout << a[i] << std::endl;

	return 0;
}

// XXX: create a separate "omp parallel" region with a for-loop in it
