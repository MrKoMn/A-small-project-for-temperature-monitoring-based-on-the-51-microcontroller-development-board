#include "define.h"
/*
void writeCon(u8 con){ //写控制命令
	RS =0;
	RW =0;
	EN =0;
	P0 = con;
	delayms(1);
	EN =1;
	delayms(1);
	EN =0;
}

void writeData(u8 dat){ //写入数据
	RS =1;
	RW =0;
	EN =0;
	P0 =dat;
	delayms(1);
	EN =1;
	delayms(1);
	EN =0;
}

void init_ss1602(){      //初始化
	writeCon(0x38);
	writeCon(0x0c);
	writeCon(0x06);
	writeCon(0x01);
}

void clear(){						//清屏
	 writeCon(0x01);
}


void display(u8 x,u8 y,u8 *str)
{
u8 i=0;
	if(y>1||x>15)return;//行列参数不对则强制退出
	if(y<1) //第 1 行显示
		{
			while(*str!='\0')//字符串是以'\0'结尾，只要前面有内容就显示
			{
				if(i<16-x)//如果字符长度超过第一行显示范围，则在第二行继续显示
						{
							writeCon(0x80+i+x);//第一行显示地址设置
						}
				else
						{
							writeCon(0x40+0x80+i+x-16);//第二行显示地址设置
						}
						writeData(*str);//显示内容
						str++;//指针递增
						i++;
			}
		}
	else //第 2 行显示
		{
			while(*str!='\0')
		{
			if(i<16-x) //如果字符长度超过第二行显示范围，则在第一行继续显示
				{
					writeCon(0x80+0x40+i+x);
				}
			else
				{
					writeCon(0x80+i+x-16);
				}
				writeData(*str);
				str++;
				i++;
			}
		}
	}
*/

void smg_display(u8 dat[],u8 pos)
{
	u8 i=0;
	u8 pos_temp=pos-1;

	for(i=pos_temp;i<8;i++)
	{
	   	switch(7-i)//位选
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
		SMG_A_DP_PORT=dat[i-pos_temp];//传送段选数据
		delay_10us(100);//延时一段时间，等待显示稳定
		SMG_A_DP_PORT=0x00;//消音
	}
}












