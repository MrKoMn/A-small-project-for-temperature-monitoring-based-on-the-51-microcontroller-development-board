#include "define.h"


 
void display(u8 dat[])
{
	u8 i=0;
	u8 temp=3;

	for(i=temp;i<8;i++)
	{
	   	switch(i)//λѡ
		{
			case 0: LSC=1;LSB=1;LSA=1;break;
			case 1: LSC=1;LSB=1;LSA=0;break;
			case 2: LSC=1;LSB=0;LSA=1;break;
			case 3: LSC=1;LSB=0;LSA=0;break;
			case 4: LSC=0;LSB=1;LSA=1;break;
			case 5: LSC=0;LSB=1;LSA=0;break;
			case 6: LSC=0;LSB=0;LSA=1;break;
			case 7: LSC=0;LSB=0;LSA=0;break;
		}
		P0=dat[i-temp];//���Ͷ�ѡ����
		delay10us(100);//��ʱ
		P0=0x00;
	}
}

	



