#include<string.h>
#include"account.h"
#include"safe.h"

//#include"sign.h"
#include<stdio.h>
#include"account.h"
#include<string.h>
#include<stdlib.h>
#include"menu.h"
#include<time.h>

/*	【函数名】add_account
**	【函数功能】用来添加用户账户及密码
**	【参数传值】无
**	【返回值】无
**	【调用非库函数】fwrite_account(account, fp);free(account);free_accountlist(accountlist);	
*/	

void add_account() {
	system("cls");

	Account* account = (Account*)malloc(sizeof(Account));
	account->next = NULL;
	//加载已有账户
	Account* accountlist = fread_account();
	printf("\t\t\t请输入账户名（六位纯数字组成,输入[0]放弃创建账户）\n");
	char acc[10];
	char passwd1[30];
	char passwd2[30];
	while (1)
	{
		fflush(stdin);
		//getchar();
		//printf("空格后然后输入账户：");
		//gets(acc);
		scanf("%s",acc);

		if (strcmp(acc, "0") == 0) //	用户放弃创建帐号
		{
			return;
		}
		if (judge_acclegal(acc) == 0)//输入的账户长度非法
		{
			printf("\t\t\t您输入的账户不是六位，请重新输入：");
			continue;
		}
		else if (judge_acclegal(acc) == 1)//账户不为纯数字非法
		{
			printf("\t\t\t您输入的账户包含非数字字符，请重新输入：");
			continue;
		}
		else if (loc_account(acc, accountlist) != NULL)//用户名已经注册
		{
			printf("\t\t\t您输入的账户已经存在（退出请输入[0])，请重新输入：");
			continue;
		}
		else//账户合法
		{
			break;
		}
		//	如果创建不合法，提示后重新输入
	}

		//	设置密码部分

	LOOP:	//	重新设置密码
		printf("\t\t\t请设置8-16位密码：");
		while (1) {
			fflush(stdin);
			//gets(passwd1);
			scanf("%s",passwd1);
			if (strlen(passwd1) > 16 || strlen(passwd1) < 8) {
				printf("\t\t\t您输入的密码位数不在8~16位，请重新输入\n");
				continue;
			}
			else	//	密码输入合法
			{
				break;
			}

		

		}
		//	再次输入密码
		system("cls");
		printf("\t\t\t请再次输入密码（输入[0000]重新设置密码）：");
		while (1)
		{
			fflush(stdin);
			scanf("%s", passwd2);
			/*gets(passwd2);*/
			if (strcmp(passwd2, "0000")==0) {
				goto LOOP;
			}
			else if (strcmp(passwd2, passwd1) != 0) {
				printf("\t\t\t您两次输入的密码不一致，请重新输入\n");
				continue;	
			}
			else {
				break;
			}
		}
		strcpy(account->str_acc, acc);
		strcpy(account->str_password, passwd1);

		FILE* fp = fopen("account.log", "a");
		if (fp == NULL)
		{
			printf("\t\t\t\t\t\t未知错误！账户文件打开失败\n");
			return;
		}
		fwrite_account(account, fp);
		fclose(fp);
		free(account);
		free_accountlist(accountlist);
		system("cls");
		/*printf("操作完成\n\n\n");*/
		printf("\t\t\t\t\t\t请您登录系统\n");
		sign_in();
}

//该函数用来判断输入账户是否合法，长度小于6返回0，不是数字返回1，合法返回2
int judge_acclegal(char acc[]) {

	int len = strlen(acc);	//	获取账户的长度
	if (len!= 6) {	// if !=6,illegal
		return 0;
	}
	for (int i = 0; i < len; i++)
	{
		if (acc[i] < '0' || acc[i]>'9')
			return 1;
	}
	return 2;

}

/*
*	[函数名]fwirte_account
*	[函数传值]Account*	FILE*
*	先调用加密函数对帐号和密码进行加密，然后
*/
void fwrite_account(Account* account, FILE* fp)
{
	encryption(account->str_acc);//加密账户
	encryption(account->str_password);//加密密码
	fputc('!', fp);//写入时多写入一个无用字符，使得判断文件尾部时使用fgetc不会产生影响
	fprintf(fp, "%s", account->str_acc);//添加账户到文件，末尾不添加回车
	fprintf(fp, "%s\n", account->str_password);//添加账户密码到文件，末尾添加回车
}

/*	【函数名】fread_account
**	【函数功能】读取文件中的账户和密码
**	【传入参数】无	
**	【函数返回值】一个包含账户信息的链表
*/
Account* fread_account() {
	
	//读账户文件
	FILE* fp = fopen("account.log","r");
	if (fp==NULL) {
		//文件不存在时就创建文件
		fp = fopen("account.log","w");
		printf("\t\t\t文件不存在，已重新创建！\n");
		return NULL;
	}
	if (fp == NULL)
	{
		printf("\t\t\t未知错误！账户文件打开失败！\n");
		return NULL;
	}
	//创建新节点
	Account* head = (Account*)malloc(sizeof(Account));
	head->next = NULL;
	//指针p指向链表的尾节点
	Account* p = head;	
	while (fgetc(fp)!=EOF)
	{
		Account* newacc = (Account*)malloc(sizeof(Account));
		//newacc->next = NULL;
		//将文件的账户和密码读取出来放在新建账户中
		fgets(newacc->str_acc, 7, fp);
		fgets(newacc->str_password, 17, fp);

		//将多读出来的那个字符变成数组结尾的标志
		newacc->str_password[strlen(newacc->str_password) - 1] = '\0';

		//对账户和密码进行解密
		decryption(newacc->str_acc);
		decryption(newacc->str_password);
		
		//链表的插入

		newacc->next = NULL;
		p->next = newacc;
		p = p->next;

	}

	p = head;
	head = head->next;
	//释放掉表头的标志节点
	free(p);
	fclose(fp);//关闭文件
	//返回链表指针
	return head;
}

/*	【函数名】loc_account
**	【函数功能】用来查找用户的账户名
**	【传入参数1】字符串：需要查找的用户名
**	【传入参数2】加载出来的链表首指针
**	【函数返回值】返回一个指针指向需要查找的用户名和密码
*/
Account* loc_account(char a[],Account*account) {
	Account* p = account;
	while (p!=NULL)
	{
		if (strcmp(a, p->str_acc) == 0)
		{
			return p;
		}
		else
		{
			p = p->next;
		}
	}
	return NULL;
}

/*	【函数名】free_accountlist
**	【函数功能】释放掉用户链表
**	【函数传值】用户链表的头指针
**	【返回值】无
*/
void free_accountlist(Account*accountlist) {
	Account* p = accountlist;
	while (p!=NULL)
	{
		accountlist = accountlist->next;
		free(p);
		p = accountlist;
	}
}


//说明：用来生成个性文件名的函数，后来放弃
 
//char* make_filename(char aname[50])
//{
//	//extern char current_account[8];
//	char current_account[8]="999999";
//
//	/*char* show_filename = strcat(current_account, "_stu.csv");*/
//	char filename[50];
//	strcpy(filename, current_account);
//	strcat(filename, aname);
//	return filename;
//}

/*
[函数名]sign_in
[参数]无
[功能]登录账户
[调用非库函数]fread_account
*/
void
sign_in() {

	//清屏
	system("cls");
	Account account0;
	Account* account;
	// 定义当前账户
	/*char current_account[8];*/

	printf("\t\t\t\t *==========================================================*\n\n");
	
	printf("\t\t\t\t		欢迎使用学生事务管理登录系统！\n\n");
	printf("\t\t\t\t		请输入您的用户账号(输入[0]退出系统)：\n\n");
	printf("\t\t\t\t *==========================================================*\n\n");

	//获取用户表
	Account* accountlist = fread_account();
	while (1)
	{
		//getchar();
		fflush(stdin);
		//获取用户输入
		printf("\t\t\t账户名（请输入六位的账户名）：");

		//获得输入
		scanf("%s", current_account);

		//gets_s(current_account,8);
		if (strcmp(current_account, "0") == 0) {
			return;
		}

		// 定位当前输入账户和存储的账户链表
		account = loc_account(current_account, accountlist);

		if (account == NULL) {
			printf("\t\t\t用户不存在！请重新输入用户名\n");
		}
		else
		{
			break;
		}

	}
	char passwd[20];

	//无限循环接受输入
	while (1)
	{
		printf("\t\t\t请输入密码：");
		scanf("%s", passwd);
		//gets_s(passwd,20);
		if (strcmp(passwd, "0") == 0)
		{
			return;
		}
		else if (strcmp(passwd, account->str_password) != 0) {
			printf("\t\t\t用户输入密码错误！\n请重新输入：");
			//system("cls");
		}

		else {
			//printf("\t\t\t *======================================*\n");

			printf("\t\t\t\t\t		账户登录成功！\n\n");
			printf("\n\n\t\t\t\t\t\t正在进入系统，请稍等...");
			clock_delay();
			//printf("\t\t\t *======================================*\n");


			//进入次级目录
			sub_menu();
			return;
		}
	}
}

void
clock_delay()/*时间延时函数*/
{
	clock_t tm;
	tm = clock();
	while (clock() < tm + 1500);
}
