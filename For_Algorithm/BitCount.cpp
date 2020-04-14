#include "For_Algorithm.h"

//暴力循环
//O(n)
unsigned int BitCount(unsigned int n)
{
	auto cnt = 0;
	for (; n > 0; n >>= 1)
	{
		cnt += (n & 0x01);
	}
	return cnt;
}


//查表法
//O(1)
unsigned int BitCount2(unsigned int n)
{
	int Table[256] = { 0 };

	for (int i = 1; i < 256; i++)
		Table[i] = Table[i >> 1] + (i & 0x01);

	return Table[n & 0xFF] + Table[(n >> 8) & 0xFF] + Table[(n >> 16) & 0xFF] + Table[(n >> 24) & 0xFF];
}



//分支法
//O(log(n))
/*
	eg: n= (1101 1010)
	n&0x55		-> 获取得第1、3、5、7的1的个数并储存 : 结果为 0101 0000
	n>>1 &0x55	-> 获取得第0、2、4、6的1的个数并储存 : 结果为 0100 0101
	相加，= 1001 0101 ,即 01有2个1， 23有1个1， 45有1个1， 67有1个1 (因为相邻两个数的1的个数最多为2， 即10)
	下列0x33, 0x0F 同理
*/
unsigned int BitCount3(unsigned int n)
{
	n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
	n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
	n = (n & 0x0F0F0F0F) + ((n >> 4) & 0x0F0F0F0F);
	n = (n & 0x00FF00FF) + ((n >> 8) & 0x00FF00FF);
	return (n & 0x0000FFFF) + ((n >> 16) & 0x0000FFFF);
}


//三分法
unsigned int BitCount4(unsigned int n)
{
	unsigned int i = n - ((n >> 1) & 0x033333333333) - ((n >> 2) & 0x011111111111);
	return ((i + (i >> 3)) & 0x030707070707) % 63;
}


//仅用于MSVC
unsigned int BitCount_0(unsigned int n)
{
	return _mm_popcnt_u32(n);
}
