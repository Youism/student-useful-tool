#include<stdio.h>
#include"safe.h"

/*	����������encryption
**	���������ܡ��������˻�����������м��ܣ���ֹ��������ȡ
**	������ֵ����
**	����������������ַ���
*/
void 
encryption(char a[]) 
{
	//��ȡa�ĳ���
	int len = strlen(a);
	
	for (int i = 0; i < len;i++) {
		a[i] += (i+12);
	}
}

/*	����������decryption
**	���������ܡ���������
**	������ֵ����
**	������������ַ���
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






