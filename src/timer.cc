#include "timer.h"

	timer::timer()
	{
		start =0;
		end=0;
	}
	void timer::start_m()
	{
		start = clock();
	}
	void timer::end_m()
	{
		end = clock();
	}
	int timer::duration_t()
	{
		duration = end - start;
		return duration;
	}
