#include <iostream>

double
two_body_energy(int i, int j)
{
	return (2.0 * i + 3.0 * j) / 10.0; // some dummy return value
}

int
main()
{
	const int nbodies = 1000;
	double energy = 0.0;

#pragma omp parallel for reduction(+:energy)
	for (int i = 0; i < nbodies; i++) {
		for (int j = i+1; j < nbodies; j++) {
			double eij = two_body_energy(i, j);
			energy += eij;
		}
	}

	std::cout << "energy = " << energy << std::endl;
	return 0;
}

// XXX: there are other reduction operations (* - && || max min ...)
// XXX: reduction takes care of the scope
// XXX: what happens when we change the initial value of energy?
// XXX: what happens when we try to make energy "shared"?
