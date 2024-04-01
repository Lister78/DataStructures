#include <time.h>

class timer
{
	private: 
		clock_t start;
		clock_t end;
		int duration;
	public:
		timer();
		void start_m();
		void end_m();
		int duration_t();

};
