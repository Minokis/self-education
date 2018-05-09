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
#include <stdio.h>
#include <time.h>

float nextTime(float rateParameter)
{
    return -(-1.0f/rateParameter) * log(1-static_cast<float>(rand())/(RAND_MAX+1));
}

double check_poisson(float rateParameter, int iterations) {
  double sum = 0;
  for(int i=0; i<iterations;++i) {
    sum += static_cast<double>(nextTime(rateParameter));
  }
  return sum/iterations;
}

int main() {
  //using namespace std;
  printf("RAND_MAX is %d\n", RAND_MAX);
  srand(time(NULL));
  float lam = 1.0f/40;
  for(int i=0; i<5;i++)
    printf("%lf\t", nextTime(lam));
    //TODO: find a bug. Check shows that calculations are wrong. Or check function is written wrong.
  printf("Check: %lf\n", check_poisson(lam, 1000) );
  return 0;
}
