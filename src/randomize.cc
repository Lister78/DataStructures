#include "randomize.h"

	random_data_generator::random_data_generator()
	{	
			srand((unsigned) time(NULL));
			number=0;
	}
	int random_data_generator::rng_place_in_array(int range)
	{	
		number = rand() % (range+1);
		return number;
	}
	int random_data_generator::rng_data_to_array()
	{	
		number =  rand() % 200;
		return number;
	}
