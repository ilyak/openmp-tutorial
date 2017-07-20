#include <iostream>
#include <omp.h>

int
main()
{
	int a = -1;

#pragma omp parallel default(none) private(a)
{
	int b; // not visible outside this scope; each thread has its own copy
	a = omp_get_thread_num() + 100;
	b = omp_get_thread_num() + 200;
}
	std::cout << "a = " << a << std::endl;
//	b = 0; // error
	return 0;
}

// XXX: make 'a' shared
