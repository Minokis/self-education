/* the exact amount of time until the next earthquake.
This function should return random numbers, but not the uniform kind of random
number produced by most generators. We want to generate random numbers in a way
that follows our exponential distribution.

Earthquakes: 13000/year
lambda = 1/40 (on average 1 earthquake happens every 40 minutes)

nextTime = -lnU/lambda

http://preshing.com/20111007/how-to-generate-random-timings-for-a-poisson-process/


*/
