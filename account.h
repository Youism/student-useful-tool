#ifndef ACCOUNT_H
#define ACCOUNT_H
#pragma warning(disable 4996)
#include<stdio.h>

//����ṹ�壬�ṹ��������û����Լ����룬����ָ����һ���ڵ��ָ��
//[�ṹ������]
//[��Ա]1���˻���2������3��ָ��ýṹ���ָ��

typedef struct account{
	char str_acc[7];//6 number
	char str_password[17];
	struct account*next;
}Account;

//���庯��
//����˻�����
void add_account();

//�ж��˻������Ƿ�Ϸ�����
int judge_acclegal(char acc[]);

//д���µ��˻����˻������빲ռ��һ��
void fwrite_account(Account* account, FILE* fp);

//�ͷ�����ĺ���
void free_accountlist(Account* accountlist);

//���ļ��ж�ȡ����ĺ���
Account* fread_account();

//��λ��ǰ�����˻��ĺ���
Account* loc_account(char a[], Account* account);

char* make_filename(char aname[50]);

void sign_in();
char current_account[8];
void clock_delay();
#endif // !ACCOUNT_H
