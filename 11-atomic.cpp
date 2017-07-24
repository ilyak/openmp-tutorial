#include <iostream>

int
main()
{
	double sum = 0.0; // shared by default

#pragma omp parallel for
	for (int i = 0; i < 10000; i++) {
		sum += i;
	}

	std::cout << "sum = " << sum << std::endl;
}

// XXX: why the sum is incorrect?
// XXX: make addition atomic (omp atomic) to fix the bug
