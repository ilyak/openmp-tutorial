#include <iostream>

int
main()
{
	double sum = 0.0;

#pragma omp parallel for reduction(+:sum)
	for (int i = 0; i < 10000; i++)
		sum += i;

	std::cout << "sum = " << sum << std::endl;
	return 0;
}

// XXX: there are other reduction operations
// XXX: reduction takes care of the scope
// XXX: what happens when we try to make 'sum' variable shared
