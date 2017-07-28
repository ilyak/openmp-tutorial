#include <iostream>
#include <omp.h>
#include <unistd.h>

int
main()
{
	omp_lock_t lock;

	omp_init_lock(&lock);

#pragma omp parallel num_threads(4)
{
	omp_set_lock(&lock); // mutual exclusion (mutex)
	std::cout << "Thread " << omp_get_thread_num() <<
	    " has acquired the lock. Sleeping 2 seconds..." << std::endl;
	sleep(2);
	std::cout << "Thread " << omp_get_thread_num() <<
	    " is releasing the lock..." << std:: endl;
	omp_unset_lock(&lock);
}
	omp_destroy_lock(&lock);
	return 0;
}
