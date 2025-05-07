   #include<lpc21xx.h>
#define LCD_D 0xf<<20
   #define RS 1<<17
   #define RW 1<<18
   #define E 1<<19
   void LCD_INIT(void);
   void LCD_COMMAND(unsigned int);
   void LCD_STR(unsigned char *);
   void LCD_DATA(unsigned int);
    void delay_millisec(unsigned int s);


void LCD_INIT(void)
{
	IODIR1|=LCD_D|RS|RW|E;
	IOCLR1=RW;
	LCD_COMMAND(0X01);
	LCD_COMMAND(0X02);
	LCD_COMMAND(0X0C);
	LCD_COMMAND(0X28);
	LCD_COMMAND(0X80);
	
}

void LCD_COMMAND(unsigned int c)
{
	
	IOCLR1=LCD_D;
	IOSET1=(c&0xf0)<<16;
	IOCLR1=RS;
	IOSET1=E;
	delay_millisec(2);
	IOCLR1=E;

	IOCLR1=LCD_D;
	IOSET1=(c&0x0F)<<20;
	IOCLR1=RS;
	IOSET1=E;
	delay_millisec(2);
	IOCLR1=E;
}

void LCD_DATA(unsigned int d)
{
	IOCLR1=LCD_D;
	IOSET1=(d&0xf0)<<16;
	IOSET1=RS;
	IOSET1=E;
	delay_millisec(2);
	IOCLR1=E;

	IOCLR1=LCD_D;
	IOSET1=(d&0x0F)<<20;
	IOSET1=RS;
	IOSET1=E;
	delay_millisec(2);
	IOCLR1=E;
}

void LCD_STR(unsigned char *d)
{
	
	while(*d != '\0')
	{
		LCD_DATA(*d++);
	}

}
void LCD_SCROLL(char *s)
{
 int len=0,i,j;
 while(s[len]!='\0')
 len++;
 for(i=0;i<=len;i++)
 {
   LCD_COMMAND(0X80);
   for(j=0;j<16;j++)
   {
	if((i+j)<len)
     LCD_DATA(s[i+j]);
	else
	 LCD_DATA(' ');
   }
   delay_millisec(800);
 }
}

void delay_millisec(unsigned int s)
{
   	T0PR=15000-1;
	 	//T0TC=T0PC=0;
	 	T0TCR=0x1;
	  	while(T0TC<s);
	 	T0TCR=0x03;
	 	T0TCR = 0x00;		 

}
