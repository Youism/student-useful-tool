#include<stdio.h>
#include"safe.h"

/*	【函数名】encryption
**	【函数功能】用来给账户或者密码进行加密，防止被恶意窃取
**	【返回值】无
**	【传入参数】数组字符串
*/
void 
encryption(char a[]) 
{
	//获取a的长度
	int len = strlen(a);
	
	for (int i = 0; i < len;i++) {
		a[i] += (i+12);
	}
}

/*	【函数名】decryption
**	【函数功能】用来解码
**	【返回值】无
**	【传入参数】字符串
**/
void 
decryption(char a[]) 
{
	int len = strlen(a);

	for (int i = 0; i < len; i++)
	{
		a[i] -= (i + 12);
	}
}






