#include "define.h"

code u8 seg[] ={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};//1-9����

void main()
{	
	u8 i=0;//��������
   	int value;//���ڱ����������ֵ
	u8 temp[6];//����������
	init_ss1602();
	initds();//��ʼ��DS18B20

	while(1)
	{				
		i++;
		if(i%50==0)
			value = readTem()*10;//�����¶�ֵС����һλ
			value = -1213;
		 
		
		if(value<0)//���¶�
		{
			value=-value;
			temp[0]=0x40;//��ʾ����	
		}
		else
			temp[0]=0x00;//����ʾ
		temp[1]=seg[value/1000];//��λ
		temp[2]=seg[value%1000/100];//ʮλ
		temp[3]=seg[value%1000%100/10]|0x80;//��λ+С����
		temp[4]=seg[value%1000%100%10];//С�����һλ
		display(temp,4);
	}		
}