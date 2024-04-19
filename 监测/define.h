#include <reg51.h>
#include <intrins.h>

#define u8 unsigned char
#define u16 unsigned int
	
sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;

sbit DS = P3^7;

sbit EN =P2^7;
sbit RS =P2^6;
sbit RW =P2^5;

extern void init_ss1602();
extern void delayms(u16 time);
extern void delay10us(u16 time);
extern u8 initds();
extern float readTem();
extern void display(u8 x,u8 y,u8 *str);