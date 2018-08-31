#include <iostream>
#include <ctime>

int main()
{
	time_t start_time;
	time_t end_time;

  time(&start_time);
  // Algorithm here
  time(&end_time);
	std::cout << "Operation time: " << difftime(end_time, start_time) << std::endl;
	return 0;
}
