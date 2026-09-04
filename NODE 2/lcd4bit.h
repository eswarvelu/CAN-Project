#include<lpc21xx.h>
#include "header.h"

#define lcd_d 0xf<<23
#define rs 1<<28
#define en 1<<29

void lcd_init(void);
void lcd_command(unsigned char cmd);
void lcd_data(unsigned char data);
void lcd_int(int n);
void str(unsigned char *p);
void lcd_float(float f_val);

void lcd_init(void)
{
IODIR1=lcd_d|rs|en;
lcd_command(0x01);
lcd_command(0x02);
lcd_command(0x0c);
lcd_command(0x28);
}

void lcd_command(unsigned char cmd)
{
    //unsigned char lower,higher;

    IOCLR1 = lcd_d;   
    IOSET1 = (cmd & 0xF0) << 19;
    IOCLR1 = rs;
    IOSET1 = en;
    ms_delay(2);
    IOCLR1 = en;

    IOCLR1 = lcd_d;   
    IOSET1 = (cmd & 0x0F) << 23;    
    IOCLR1 = rs;
    IOSET1 = en;
    ms_delay(2);
    IOCLR1 = en;
}

void lcd_data(unsigned char d)
{
   IOCLR1= lcd_d;   
    IOSET1 = (d & 0xF0) << 19;
    IOSET1 = rs;
    IOSET1 = en;
    ms_delay(2);
    IOCLR1 = en;

    IOCLR1 = lcd_d;   
    IOSET1 = (d & 0x0F) << 23;    
    IOSET1 = rs;
    IOSET1 = en;
    ms_delay(2);
    IOCLR1 = en;

    
}

void lcd_int(int n)
{
int i=0;
unsigned char arr[5];
if(n==0)
{
lcd_data('0');
}
else
{
if(n<0)
{
lcd_data('-');
n=-n;
}
while(n>0)
{
arr[i++]=n%10;
n/=10;
}
for (--i;i>=0;i--)
{
lcd_data(48+arr[i]);
}
}
}

void str(unsigned char *p)
{
while(*p)
{
lcd_data(*p);
p++;
}
}

void lcd_float(float f_val)

{

  int number;

  number = f_val;

  lcd_int(number);

  lcd_data('.');

  number=(f_val-number)*100;

  lcd_int(number);	

}
