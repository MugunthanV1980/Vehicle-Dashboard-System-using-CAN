/* main_nodeB_RX.c */
#include <LPC21xx.H>
#include "header.h"
void delay_ms(unsigned int ms);
#define led1 1<<17
#define led2 1<<18
#define led3 1<<19
unsigned char flag=0;
//#define MOTOR 1<<21
int main()
{	
	CAN2_MSG m1;
	
	can2_init();
	IODIR0|=led1|led2|led3;

	IOSET0|=led1|led2|led3;
	while(1)
	{		
        //IOSET0=led;
		can2_rx(&m1);
			   
	    if(m1.id==0X1)	        
		{	
			  if(!m1.byteB)
			  {

			  IOPIN0&=~led1;
			  delay_ms(200);
			  IOPIN0|=led1;
			  delay_ms(200);
			  }
			  else
			  {
			  IOPIN0|=led1;
			  }*/
			
			  //flag=1;
			 //flag=1;
		 }

		if(m1.id==0x2)

	    IOPIN0=led1;
	       //if(((IOPIN0>>sw)&1)==0)
			//while(((IOPIN0>>sw)&1)==0);			   
	       /*if(flag==0)
		       {
			   IOCLR0=led;
			   delay_ms(100);
			   flag=1;
			   }
			   else
			  {
			   IOSET0=led;
			   delay_ms(100);
			   flag=0;
			   } 
			   //delay_ms(100);   
			   //IOSET0=led;
			   //delay_ms(100);  
			 //while(((IOPIN0>>sw)&1)==0);
			  //flag=1;
			   } */


	 
	
	
}
}	


