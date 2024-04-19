#include "define.h"


void reset()//复位函数
{
	DS = 0;	
	delay10us(70);	//拉低700us
	DS = 1;	//DQ=1
	delay10us(2);	//20US
}

u8 check()  //检查ds18b20存在
{
	u8 time=0;

	while(DS&&time<20)	//等待DQ为低电平
	{
		time++;
		delay10us(1);	
	}
	if(time>=20)return 1;	//如果超时则强制返回1
	else time=0;
	while((!DS)&&time<20)	//等待DQ为高电平
	{
		time++;
		delay10us(1);
	}
	if(time>=20)return 1;	//如果超时则强制返回1
	return 0;
}

u8 readBit()						//读一位
{
	u8 dat=0;
	
	DS = 0;
	_nop_();_nop_();
	DS = 1;	
	_nop_();_nop_(); 
	if(DS)dat=1;	//如果总线上为1则数据dat为1，否则为0
	else dat=0;
	delay10us(5);
	return dat;
} 

u8 readByte()			//读字节
{
	u8 i=0;
	u8 dat=0;
	u8 temp=0;

	for(i=0;i<8;i++)//循环8次，每次读取一位，且先读低位再读高位
	{
		temp=readBit();
		dat=(temp<<7)|(dat>>1);
	}
	return dat;	
}

void writeBit(u8 temp){			//写比特
	if(temp)
		{
			DS = 0;
			_nop_();_nop_();
			DS = 1;	
			delay10us(6);
		}
		else
		{
			DS = 0;
			delay10us(6);
			DS = 1;
			_nop_();_nop_();	
		}
}

void writeByte(u8 dat)			//写字节
{
	u8 i=0;
	u8 temp=0;

	for(i=0;i<8;i++)//循环8次，每次写一位，且先写低位再写高位
	{
		temp=dat&0x01;//选择低位准备写入
		dat>>=1;//将次高位移到低位
		writeBit(temp);
	}	
}

void startds() //启动ds18b20
{
		reset();
		check();
		writeByte(0xcc);
    writeByte(0x44);
}

u8 initds()  		//初始化
{
	reset();
	return check();	
}

float readTem() //读取温度
{
	float temp;
	u8 dath=0;
	u8 datl=0;
	u16 value=0;

		startds();//开始转换
		reset();//复位
		check();
		writeByte(0xcc);//SKIP ROM
    writeByte(0xbe);//读存储器

	datl=readByte();//低字节
	dath=readByte();//高字节
	value=(dath<<8)+datl;

	if((value&0xf800)==0xf800)//判断符号位
	{
		value=(~value)+1; //数据取反再加1
		temp=value*(-0.0625);//乘以精度	
	}
	else 
	{
		temp=value*0.0625;	
	}
	return temp;
}











