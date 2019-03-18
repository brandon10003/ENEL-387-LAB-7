#include "setupclock.h"
#include "uart.h"
int main()
{
	uint8_t x;		
	clockinit();
	inituart();
	
	while (1)
	{
		writeusart(0x24);
		x = readusart();
	}
}