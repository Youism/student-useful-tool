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

/*	����������add_account
**	���������ܡ���������û��˻�������
**	��������ֵ����
**	������ֵ����
**	�����÷ǿ⺯����fwrite_account(account, fp);free(account);free_accountlist(accountlist);	
*/	

void add_account() {
	system("cls");

	Account* account = (Account*)malloc(sizeof(Account));
	account->next = NULL;
	//���������˻�
	Account* accountlist = fread_account();
	printf("\t\t\t�������˻�������λ���������,����[0]���������˻���\n");
	char acc[10];
	char passwd1[30];
	char passwd2[30];
	while (1)
	{
		fflush(stdin);
		//getchar();
		//printf("�ո��Ȼ�������˻���");
		//gets(acc);
		scanf("%s",acc);

		if (strcmp(acc, "0") == 0) //	�û����������ʺ�
		{
			return;
		}
		if (judge_acclegal(acc) == 0)//������˻����ȷǷ�
		{
			printf("\t\t\t��������˻�������λ�����������룺");
			continue;
		}
		else if (judge_acclegal(acc) == 1)//�˻���Ϊ�����ַǷ�
		{
			printf("\t\t\t��������˻������������ַ������������룺");
			continue;
		}
		else if (loc_account(acc, accountlist) != NULL)//�û����Ѿ�ע��
		{
			printf("\t\t\t��������˻��Ѿ����ڣ��˳�������[0])�����������룺");
			continue;
		}
		else//�˻��Ϸ�
		{
			break;
		}
		//	����������Ϸ�����ʾ����������
	}

		//	�������벿��

	LOOP:	//	������������
		printf("\t\t\t������8-16λ���룺");
		while (1) {
			fflush(stdin);
			//gets(passwd1);
			scanf("%s",passwd1);
			if (strlen(passwd1) > 16 || strlen(passwd1) < 8) {
				printf("\t\t\t�����������λ������8~16λ������������\n");
				continue;
			}
			else	//	��������Ϸ�
			{
				break;
			}

		

		}
		//	�ٴ���������
		system("cls");
		printf("\t\t\t���ٴ��������루����[0000]�����������룩��");
		while (1)
		{
			fflush(stdin);
			scanf("%s", passwd2);
			/*gets(passwd2);*/
			if (strcmp(passwd2, "0000")==0) {
				goto LOOP;
			}
			else if (strcmp(passwd2, passwd1) != 0) {
				printf("\t\t\t��������������벻һ�£�����������\n");
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
			printf("\t\t\t\t\t\tδ֪�����˻��ļ���ʧ��\n");
			return;
		}
		fwrite_account(account, fp);
		fclose(fp);
		free(account);
		free_accountlist(accountlist);
		system("cls");
		/*printf("�������\n\n\n");*/
		printf("\t\t\t\t\t\t������¼ϵͳ\n");
		sign_in();
}

//�ú��������ж������˻��Ƿ�Ϸ�������С��6����0���������ַ���1���Ϸ�����2
int judge_acclegal(char acc[]) {

	int len = strlen(acc);	//	��ȡ�˻��ĳ���
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
*	[������]fwirte_account
*	[������ֵ]Account*	FILE*
*	�ȵ��ü��ܺ������ʺź�������м��ܣ�Ȼ��
*/
void fwrite_account(Account* account, FILE* fp)
{
	encryption(account->str_acc);//�����˻�
	encryption(account->str_password);//��������
	fputc('!', fp);//д��ʱ��д��һ�������ַ���ʹ���ж��ļ�β��ʱʹ��fgetc�������Ӱ��
	fprintf(fp, "%s", account->str_acc);//����˻����ļ���ĩβ����ӻس�
	fprintf(fp, "%s\n", account->str_password);//����˻����뵽�ļ���ĩβ��ӻس�
}

/*	����������fread_account
**	���������ܡ���ȡ�ļ��е��˻�������
**	�������������	
**	����������ֵ��һ�������˻���Ϣ������
*/
Account* fread_account() {
	
	//���˻��ļ�
	FILE* fp = fopen("account.log","r");
	if (fp==NULL) {
		//�ļ�������ʱ�ʹ����ļ�
		fp = fopen("account.log","w");
		printf("\t\t\t�ļ������ڣ������´�����\n");
		return NULL;
	}
	if (fp == NULL)
	{
		printf("\t\t\tδ֪�����˻��ļ���ʧ�ܣ�\n");
		return NULL;
	}
	//�����½ڵ�
	Account* head = (Account*)malloc(sizeof(Account));
	head->next = NULL;
	//ָ��pָ�������β�ڵ�
	Account* p = head;	
	while (fgetc(fp)!=EOF)
	{
		Account* newacc = (Account*)malloc(sizeof(Account));
		//newacc->next = NULL;
		//���ļ����˻��������ȡ���������½��˻���
		fgets(newacc->str_acc, 7, fp);
		fgets(newacc->str_password, 17, fp);

		//������������Ǹ��ַ���������β�ı�־
		newacc->str_password[strlen(newacc->str_password) - 1] = '\0';

		//���˻���������н���
		decryption(newacc->str_acc);
		decryption(newacc->str_password);
		
		//����Ĳ���

		newacc->next = NULL;
		p->next = newacc;
		p = p->next;

	}

	p = head;
	head = head->next;
	//�ͷŵ���ͷ�ı�־�ڵ�
	free(p);
	fclose(fp);//�ر��ļ�
	//��������ָ��
	return head;
}

/*	����������loc_account
**	���������ܡ����������û����˻���
**	���������1���ַ�������Ҫ���ҵ��û���
**	���������2�����س�����������ָ��
**	����������ֵ������һ��ָ��ָ����Ҫ���ҵ��û���������
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

/*	����������free_accountlist
**	���������ܡ��ͷŵ��û�����
**	��������ֵ���û������ͷָ��
**	������ֵ����
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


//˵�����������ɸ����ļ����ĺ�������������
 
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
[������]sign_in
[����]��
[����]��¼�˻�
[���÷ǿ⺯��]fread_account
*/
void
sign_in() {

	//����
	system("cls");
	Account account0;
	Account* account;
	// ���嵱ǰ�˻�
	/*char current_account[8];*/

	printf("\t\t\t\t *==========================================================*\n\n");
	
	printf("\t\t\t\t		��ӭʹ��ѧ����������¼ϵͳ��\n\n");
	printf("\t\t\t\t		�����������û��˺�(����[0]�˳�ϵͳ)��\n\n");
	printf("\t\t\t\t *==========================================================*\n\n");

	//��ȡ�û���
	Account* accountlist = fread_account();
	while (1)
	{
		//getchar();
		fflush(stdin);
		//��ȡ�û�����
		printf("\t\t\t�˻�������������λ���˻�������");

		//�������
		scanf("%s", current_account);

		//gets_s(current_account,8);
		if (strcmp(current_account, "0") == 0) {
			return;
		}

		// ��λ��ǰ�����˻��ʹ洢���˻�����
		account = loc_account(current_account, accountlist);

		if (account == NULL) {
			printf("\t\t\t�û������ڣ������������û���\n");
		}
		else
		{
			break;
		}

	}
	char passwd[20];

	//����ѭ����������
	while (1)
	{
		printf("\t\t\t���������룺");
		scanf("%s", passwd);
		//gets_s(passwd,20);
		if (strcmp(passwd, "0") == 0)
		{
			return;
		}
		else if (strcmp(passwd, account->str_password) != 0) {
			printf("\t\t\t�û������������\n���������룺");
			//system("cls");
		}

		else {
			//printf("\t\t\t *======================================*\n");

			printf("\t\t\t\t\t		�˻���¼�ɹ���\n\n");
			printf("\n\n\t\t\t\t\t\t���ڽ���ϵͳ�����Ե�...");
			clock_delay();
			//printf("\t\t\t *======================================*\n");


			//����μ�Ŀ¼
			sub_menu();
			return;
		}
	}
}

void
clock_delay()/*ʱ����ʱ����*/
{
	clock_t tm;
	tm = clock();
	while (clock() < tm + 1500);
}
