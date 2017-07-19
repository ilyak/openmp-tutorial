#include <iostream>

int
main()
{
	const int size = 1000;
	int i = -1, a[size];

#pragma omp parallel for private(i)
	for (i = 0; i < size; i++)
		a[i] = i;

	std::cout << "i = " << i << std::endl;
	return 0;
}

// XXX: try changing private to lastprivate
