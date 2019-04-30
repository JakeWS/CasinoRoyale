// Coded by Matthew J.

#include <chrono>
#include <random>
#include "randGen.hpp"

using namespace std;

double randGen::randomDoubleGenerator()
{
	double random;
	unsigned int seed = chrono::system_clock::now().time_since_epoch().count();
	default_random_engine generator(seed);
	uniform_real_distribution<double> distribution(0,9);
	random = distribution(generator);
	return random;
}

int randGen::randomIntGenerator(int i)
{
	unsigned int random;
	unsigned int seed = chrono::system_clock::now().time_since_epoch().count();
	default_random_engine generator(seed);
	uniform_real_distribution<double> distribution(0,9);
	random = ((unsigned int)(distribution(generator)*1000000))%i;
	return random;
}
