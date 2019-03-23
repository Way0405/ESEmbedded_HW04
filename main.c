#include "blink.h"

int main(void)
{
	while(1)
	{
		if(user_button()==1)
			blink(LED_BLUE);
		else 
			;
	}
}
