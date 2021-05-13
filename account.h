#ifndef ACCOUNT_H
#define ACCOUNT_H
#pragma warning(disable 4996)
#include<stdio.h>

//定义结构体，结构体包含了用户名以及密码，还有指向下一个节点的指针
//[结构体名称]
//[成员]1、账户名2、密码3、指向该结构体的指针

typedef struct account{
	char str_acc[7];//6 number
	char str_password[17];
	struct account*next;
}Account;

//定义函数
//添加账户函数
void add_account();

//判断账户名字是否合法函数
int judge_acclegal(char acc[]);

//写入新的账户，账户和密码共占用一行
void fwrite_account(Account* account, FILE* fp);

//释放链表的函数
void free_accountlist(Account* accountlist);

//从文件中读取链表的函数
Account* fread_account();

//定位当前输入账户的函数
Account* loc_account(char a[], Account* account);

char* make_filename(char aname[50]);

void sign_in();
char current_account[8];
void clock_delay();
#endif // !ACCOUNT_H
