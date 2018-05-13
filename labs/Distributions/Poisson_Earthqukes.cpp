/* the exact amount of time until the next earthquake.
This function should return random numbers, but not the uniform kind of random
number produced by most generators. We want to generate random numbers in a way
that follows our exponential distribution.

Earthquakes: 13000/year
lambda = 1/40 (on average 1 earthquake happens every 40 minutes)

nextTime = -lnU/lambda

http://preshing.com/20111007/how-to-generate-random-timings-for-a-poisson-process/


*/


#include <cmath>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <random> // for std::random_device and std::mt19937

double simple_poisson(double rateParameter, double uniform) {
  return -log(1-uniform)/rateParameter;
}

double check_poisson(double rateParameter, double uniform, int iterations) {
  double sum = 0;
  for(int i=0; i<iterations;++i) {
    sum += simple_poisson(rateParameter, uniform);
  }
  return sum/iterations;
}

int main() {
  std::random_device rd;
  // Create a mersenne twister, seeded using the random device
	std::mt19937 mersenne(rd());
  // Create a reusable random number generator that generates uniform numbers between 0 and 1
  std::uniform_real_distribution<double> distr(0.0, 1.0);
  double lam = 1.0/40;
	for (int count = 1; count <= 48; ++count)
	{
		std::cout << simple_poisson(lam, distr(mersenne))<< "\t";
		// If we've printed 6 numbers, start a new row
		if (count % 6 == 0)
			std::cout << "\n";
	}
  for (int i = 0; i < 5; ++i)
  {
    std::cout << "Check "<< i << ": " << check_poisson(lam, distr(mersenne), 10000)<< std::endl;
  }
	return 0;
}
