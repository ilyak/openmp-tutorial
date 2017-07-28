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

	for (int i = 0; i < nbodies; i++) {
		for (int j = i+1; j < nbodies; j++) {
			double eij = two_body_energy(i, j);
			energy += eij;
		}
	}

	std::cout << "energy = " << energy << std::endl;
	return 0;
}

// XXX: parallelize the outer loop
// XXX: why is the result incorrect?
// XXX: use omp atomic to fix the bug
