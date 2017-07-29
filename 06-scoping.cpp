#include <iostream>
#include <omp.h>

int
main()
{
	int a = -1;

#pragma omp parallel
{
	// "a" is shared by default. All threads have access to the same "a".

	int b; // not visible outside this scope; each thread has its own copy
	a = omp_get_thread_num() + 100;
	b = omp_get_thread_num() + 200;
}
	std::cout << "a = " << a << std::endl;
//	b = 0; // error
	return 0;
}

// XXX: add default(none)
// XXX: make "a" private
