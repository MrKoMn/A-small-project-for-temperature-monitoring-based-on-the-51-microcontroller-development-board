#include "define.h"

code u8 seg[] ={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};//1-9段码

void main()
{	
	u8 i=0;//计数变量
   	int value;//用于保存读出来的值
	u8 temp[6];//存放数组段码
	init_ss1602();
	initds();//初始化DS18B20

	while(1)
	{				
		i++;
		if(i%50==0)
			value = readTem()*10;//保留温度值小数后一位
			value = -1213;
		 
		
		if(value<0)//负温度
		{
			value=-value;
			temp[0]=0x40;//显示负号	
		}
		else
			temp[0]=0x00;//不显示
		temp[1]=seg[value/1000];//百位
		temp[2]=seg[value%1000/100];//十位
		temp[3]=seg[value%1000%100/10]|0x80;//个位+小数点
		temp[4]=seg[value%1000%100%10];//小数点后一位
		display(temp,4);
	}		
}