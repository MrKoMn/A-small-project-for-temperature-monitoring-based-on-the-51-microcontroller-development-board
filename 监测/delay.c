#include "define.h"

void delayms(u16 time){
u8 i;
	while(time--){
	for(i=110;i>0;i--);
	}
}

void delay10us(u16 time){
	while(time--);
}