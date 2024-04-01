#pragma once
#include <time.h>
#include <cstdlib>
class random_data_generator
{
	private:
		int number;
	public:
		random_data_generator();
		int rng_place_in_array(int);
		int rng_data_to_array();
};
