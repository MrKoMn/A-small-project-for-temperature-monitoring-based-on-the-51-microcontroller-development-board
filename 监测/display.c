#include "define.h"
/*
void writeCon(u8 con){ //д��������
	RS =0;
	RW =0;
	EN =0;
	P0 = con;
	delayms(1);
	EN =1;
	delayms(1);
	EN =0;
}

void writeData(u8 dat){ //д������
	RS =1;
	RW =0;
	EN =0;
	P0 =dat;
	delayms(1);
	EN =1;
	delayms(1);
	EN =0;
}

void init_ss1602(){      //��ʼ��
	writeCon(0x38);
	writeCon(0x0c);
	writeCon(0x06);
	writeCon(0x01);
}

void clear(){						//����
	 writeCon(0x01);
}


void display(u8 x,u8 y,u8 *str)
{
u8 i=0;
	if(y>1||x>15)return;//���в���������ǿ���˳�
	if(y<1) //�� 1 ����ʾ
		{
			while(*str!='\0')//�ַ�������'\0'��β��ֻҪǰ�������ݾ���ʾ
			{
				if(i<16-x)//����ַ����ȳ�����һ����ʾ��Χ�����ڵڶ��м�����ʾ
						{
							writeCon(0x80+i+x);//��һ����ʾ��ַ����
						}
				else
						{
							writeCon(0x40+0x80+i+x-16);//�ڶ�����ʾ��ַ����
						}
						writeData(*str);//��ʾ����
						str++;//ָ�����
						i++;
			}
		}
	else //�� 2 ����ʾ
		{
			while(*str!='\0')
		{
			if(i<16-x) //����ַ����ȳ����ڶ�����ʾ��Χ�����ڵ�һ�м�����ʾ
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
	   	switch(7-i)//λѡ
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
		SMG_A_DP_PORT=dat[i-pos_temp];//���Ͷ�ѡ����
		delay_10us(100);//��ʱһ��ʱ�䣬�ȴ���ʾ�ȶ�
		SMG_A_DP_PORT=0x00;//����
	}
}












