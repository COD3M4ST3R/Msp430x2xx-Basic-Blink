#include <msp430g2553.h>

/**
 * Nadir Suhan ILTER
 */

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	// Configuring P1DIR
	P1DIR |= 0x01;

	volatile unsigned int counter = 0;

	for(;;)
	{
	    if(counter > 10 && counter <= 20)
	    {
	        volatile unsigned int i;

	        P1OUT ^= 0x01;
	        counter = counter + 1;

	        i = 10000;

	        do i--;
	        while(i != 0);

	    }


	    if(counter <= 10)
	    {
	       volatile unsigned int i;    // volatile to prevent optimization

           P1OUT ^= 0x01;              // Toggle P1.0 using exclusive-OR
           counter = counter + 1;

           i = 100000;

           do i--;
           while(i != 0);
	    }

	    if(counter > 20)
	    {
	        counter = 0;
	    }

	 }

	return 0;
}
