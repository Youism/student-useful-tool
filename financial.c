#include<stdio.h>
#include"financial.h"

/*
*	@name		income_fin
*	@parma		current_account	ȫ�ֱ���
*	@param		income_filename	�ļ���
*	@version	2.0
*	@function	�û���������������Լ�������Դ��
*					�����ü�¼������һ���ļ���
*/	
void  
income_fin() 
{
	system("cls");

	/*Bill *head=(Bill*)malloc(sizeof(Bill));
	head->next = NULL;*/

	//ָ��pָ�������Ϊ�ڵ�
	//Bill* p = head;

	//���ļ�
	extern char current_account[8];
	//char current_account[8];
	//scanf("%s",current_account);
	char* income_filename = (char*)malloc(sizeof(char));
	strcpy(income_filename, current_account);
	strcat(income_filename, "_income.log");
	/*char *income_filename=(char *)malloc(sizeof(char));
	income_filename=make_filename("_income.log");*/

	//char* income_filename = "test1.log";
	FILE * fp = fopen(income_filename, "a");
	if (fp == NULL)
	{
		fp = fopen(income_filename,"w");
		printf("�ѳɹ�Ϊ���Զ������ʽ�����ļ�\n");
		printf("--------------------------------------\n");
	}

	printf("��ӭ���������������ϵͳ��\n");
	while (1)
	{
		//��̬�����ʽ���ڴ�
		Bill* newbill = (Bill*)malloc(sizeof(Bill));

		printf("������������(��������λ��������[0100])��");
		printf("���롾0���˳�\n");
		scanf("%s",newbill->money);
		
		if (strcmp(newbill->money,"0")==0)
		{
			//exit(0);
			return;
		}
		printf("\n");
		printf("����������ԭ��(ע�ⲻҪ�ӿո�)��");
		scanf("%s",newbill->cause);
		
		//����Ϣд���ļ���
		fwrite_bill(newbill,fp);

		//β�巨���µĽڵ�����������
		/*newbill->next = NULL;
		p->next = newbill;
		p = p->next;*/

	}
	fclose(fp);
	

}
/*
**	@name		fwrite_bill
**	@param		Bill 
**	@param		FILE
**	@function	���������ԭ��д���ļ���
*/
void 
fwrite_bill(Bill* bill, FILE* fp)
{
	//д��ʱ��д��һ�������ַ���ʹ���ж��ļ�β��ʱʹ��fgetc�������Ӱ��
	fputc('!', fp);
	//����˻����ļ���ĩβ����ӻس�
	fprintf(fp, "%s", bill->money);
	//���ԭ���ļ���ĩβ��ӻس�
	fprintf(fp, "%s\n", bill->cause);
	if (fp == NULL) {
		printf("δ֪����");
	}
	
}
/*
*	@name		fread_fin
*	@param		FILE 
*	@param		Bill
*	@param		int
*	@version	1.4
*	@function	��ȡ������ļ��е����ݣ�Ȼ�󷵻�һ��ָ�����ݵ�ָ��,����һ����ֵ[0-2]��
*					0��ʾ��ȡ�����˵���Ϣ��1��ʾ��ȡ֧���˵���Ϣ��2��ʾǷ���˵���Ϣ			
*/	

Bill* 
fread_fin(int num)
{	

	//����һ��ָ�����飬�����ļ�����Ϣ
	//Ƿ���˵��ļ�����
	extern char current_account[8];

	char arrears_filename[50] ;
	strcpy(arrears_filename, current_account);
	strcat(arrears_filename, "_arrears.log");
	//֧���˵��ļ���	
	char  expense_filename[50];
	strcpy(expense_filename, current_account);
	strcat(expense_filename, "_expense.log");
	//�����˵��ļ�����
	char income_filename[50];
	strcpy(income_filename, current_account);
	strcat(income_filename, "_income.log");

	//�������鱣���ļ���
	char *s[] = { income_filename,expense_filename,arrears_filename };
	char *filename ;
	filename = s[num];
	
	//���˻��ļ�
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		//�ļ�������ʱ�ʹ����ļ�
		fp = fopen(filename, "w");
		printf("\t\t\t�ļ������ڣ������´�����\n");
		return NULL;
	}
	if (fp == NULL)
	{
		printf("\t\t\tδ֪�����˻��ļ���ʧ�ܣ�\n");
		return NULL;
	}

	//�����½ڵ�
	Bill* head = (Bill*)malloc(sizeof(Bill));
	head->next = NULL;
	//ָ��pָ�������β�ڵ�
	Bill* p = head;

	//���ж�ȡ����
	while (fgetc(fp) != EOF)
	{
		Bill* newbill = (Bill*)malloc(sizeof(Bill));
		//newacc->next = NULL;
		//���ļ����˻��������ȡ���������½��˻���
		fgets(newbill->money, 5, fp);
		
		//fscanf(fp,"%d",newbill->money);
		/*
		fscanf(fp,newbill->cause);*/

		fgets(newbill->cause, 17, fp);
		//������������Ǹ��ַ���������β�ı�־
		newbill->cause[strlen(newbill->cause) - 1] = '\0';
		
		//����Ĳ���
		newbill->next = NULL;
		p->next = newbill;
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

/*	
*	@name		free_billList
*	@parma		Bill 
*	@version	1.0
*	@fucntion	�����ͷŽ���ԭ�������	
*/
void 
free_billList(Bill* billList)
{
	Bill* p = billList;
	while (p != NULL)
	{
		billList = billList->next;
		free(p);
		p = billList;
	}
}

/*
*	@name		show_bill_list
*	@param		Bill
*	@version	1.0
*	@function	����һ��ָ�����������ָ�룬Ȼ��������е�����	
*/
void 
show_bill_list()
{
	system("cls");
	Bill* bill_list = (Bill*)malloc(sizeof(Bill));
	bill_list = fread_fin(0);
	while (bill_list != NULL)
	{
		printf("�������%d\t",atoi(bill_list->money));
		printf("������Դ��%s\n",bill_list->cause);

		//ʹָ��ָ����һ���ڵ�
		bill_list = bill_list->next;
	}
	system("pause");

}

/*
*	@name		show_arreaars_list
*	@param		Bill
*	@version	1.0
*	@function	����һ��ָ�����������ָ�룬Ȼ��������е�����
*/
void 
show_arrears_list()
{
	system("cls");
	Bill* arrears_list = (Bill*)malloc(sizeof(Bill));
	arrears_list = fread_fin(2);
	while (arrears_list != NULL)
	{
		printf("Ƿ�ѽ������%d\t", atoi(arrears_list->money));
		printf("Ƿ����Դ��%s\n", arrears_list->cause);

		//ʹָ��ָ����һ���ڵ�
		arrears_list = arrears_list->next;
	}
	system("pause");
}

/*
*	@name expense
*	@param Bill
*	���������ܡ���������һ���ȴ�֧���ĵ����������֧���Ľ��͵ȴ�֧����ԭ��
*	����������ֵ����
*/	

void 
expense()
{
	system("cls");

	/*Bill* head = (Bill*)malloc(sizeof(Bill));
	head->next = NULL;*/

	//ָ��pָ�������Ϊ�ڵ�
	

	//���ļ�
	extern char current_account[8];
	/*char* show_filename = strcat(current_account, "_stu.csv");*/
	char expense_filename[50];
	strcpy(expense_filename, current_account);
	strcat(expense_filename, "_expense.log");
	FILE* fp = fopen(expense_filename, "a");
	if (fp == NULL)
	{
		fp = fopen(expense_filename, "w");
		printf("�ѳɹ�Ϊ���Զ������ʽ�����ļ�\n");
		printf("--------------------------------------\n");
	}

	//printf("��ӭ���������������ϵͳ��\n");
	printf("��ӭ���Ľ���ϵͳ�ĵȴ�֧��ϵͳ��");
	while (1)
	{
		//��̬�����ʽ���ڴ�
		Bill* newbill = (Bill*)malloc(sizeof(Bill));

		printf("�������֧�����(��������λ��������[0100])��");
		printf("���롾0���˳�\n");
		scanf("%s", newbill->money);
		if (strcmp(newbill->money, "0") == 0)
		{
			//exit(0);
			return;
		}
		printf("\n");
		printf("������֧��ԭ��");
		scanf("%s", newbill->cause);

		//����Ϣд���ļ���
		fwrite_bill(newbill, fp);

		//β�巨���µĽڵ�����������
		/*newbill->next = NULL;
		p->next = newbill;
		p = p->next;*/

	}
	fclose(fp);

}

/*
*	@name show_expense_list
*	@param Bill 
*	[��������]��������ļ������е���Ϣ
*	[����ֵ]��
*/	
void 
show_expense_list()
{
	system("cls");
	Bill* bill_expense_list = (Bill*)malloc(sizeof(Bill));
	bill_expense_list = fread_fin(1);

	while (bill_expense_list != NULL)
	{
		printf("֧���������%d\t", atoi(bill_expense_list->money));
		printf("��֧��ȥ��%s\n", bill_expense_list->cause);

		//ʹָ��ָ����һ���ڵ�
		bill_expense_list = bill_expense_list->next;
	}
	free_billList(bill_expense_list);
	system("pause");

}

/*
*	[��������]�����֧�����ܽ����������飬��ô����ʾ���û���Ƿ�������
*			  �û�����¼��Ƿ�ѽ���ԭ��Ȼ������ļ���������
*	@function name :arrears
*	
*/
void 
arrears()
{
	//����������
	int sum_income	= 0;
	int sum_expense = 0;
	int arrears = 0;	/*����Ƿ�����*/

	//��ȡ�����˵��ļ���Ϣ
	Bill* income_read_list = (Bill*)malloc(sizeof(Bill));
	//Ƿ������Ϣ
	Bill* arrears_read_list = (Bill*)malloc(sizeof(Bill));

	//������ֵ0����ʾ��ȡ�����˵���Ϣ
	income_read_list=fread_fin(0);

	while (income_read_list != NULL)
	{
		sum_income+=atoi(income_read_list->money);
		income_read_list = income_read_list->next;
	}

	//��ȡ֧���˵��ļ���Ϣ
	Bill* expense_read_list = (Bill*)malloc(sizeof(Bill));
	//������ֵ1����ʾ��ȡ�����˵���Ϣ
	expense_read_list = fread_fin(1);

	while (expense_read_list != NULL)
	{
		sum_expense += atoi(expense_read_list->money);
		expense_read_list = expense_read_list->next;
	}

	if (sum_expense >= sum_income)
	{
		extern char current_account[8];
		char arrears_filename[50];
		strcpy(arrears_filename, current_account);
		strcat(arrears_filename, "_arrears.log");
		FILE *fp=fopen(arrears_filename, "a");
		if (fp == NULL)
		{
			fp = fopen(arrears_filename, "w");
			printf("�ѳɹ�Ϊ���Զ������ʽ�Ƿ�ѹ����ļ�\n");
			printf("--------------------------------------\n");
		}
		printf("���ã�Ŀǰ����Ƿ��\n");
		arrears = sum_expense - sum_income;
		printf("��Ŀǰ��������Ƿ��%2dԪ\n",arrears);
		printf("---------------------------\n");

		//�����Ѿ�Ƿ�ѣ������û�����Ƿ�����
		printf("����������Ƿ�������\n");
		while (1)
		{
			//��̬�����ʽ���ڴ�
			Bill* newbill_arrears = (Bill*)malloc(sizeof(Bill));

			printf("������Ƿ�ѽ��(��������λ��������[0100])��");
			printf("���롾0���˳�\n");
			scanf("%s", newbill_arrears->money);
			if (strcmp(newbill_arrears->money, "0") == 0)
			{
				//exit(0);
				return;
			}
			printf("\n");
			printf("������Ƿ��ԭ��ԭ��");
			scanf("%s", newbill_arrears->cause);

			//����Ϣд���ļ���
			fwrite_bill(newbill_arrears, fp);

			//β�巨���µĽڵ�����������
			/*newbill_arrears->next = NULL;
			p->next = newbill_arrears;
			p = p->next;*/

		}
		fclose(fp);

	}
	else
	{
		printf("���ã���Ŀǰû��Ƿ�������");
	}
	system("pause");
}

/*	
*	@name		loacate_income_cause
*	@param		Bill
*	@version	1.0
*	@function	������λ����Ľ��
*/
void 
locate_income_cause()
{
	system("cls");
	Bill* income_list = (Bill*)malloc(sizeof(Bill));
	char income_information[20];

	printf("\t\t\t\t=================================\n");
	printf("\t\t\t\t������������ҵ�������Ϣ��\n");

	scanf("%s",income_information);
	income_list=fread_fin(0);

	//�������������˵��������ض���Ϣ
	while (income_list != NULL)
	{
		/*printf("�������%d\t", atoi(bill_list->money));
		printf("������Դ��%s\n", bill_list->cause);*/
		if (strcmp(income_information, income_list->cause) == 0)
		{
			printf("\t\t\t\t�Ѳ鵽������Դ�������\n");
			printf("\t\t\t\t����%s����Ϊ��%s\n",income_list->cause,income_list->money);
		}
		//ʹָ��ָ����һ���ڵ�
		income_list = income_list->next;
	}
	printf("\t\t\t=================================\n");
	//system("pause");
}

void 
/*
*	@name		loacate_expense_cause
*	@param		Bill
*	@version	1.0
*	@function	������λ֧���Ľ��
*/
locate_expense_cause()
{
	system("cls");
	Bill* expense_list = (Bill*)malloc(sizeof(Bill));
	char expense_information[20];

	printf("\t\t\t\t=================================\n");
	printf("\t\t\t\t������������ҵ�������Ϣ��\n");

	scanf("%s", expense_information);
	expense_list = fread_fin(1);

	//�������������˵��������ض���Ϣ
	while (expense_list != NULL)
	{
		/*printf("�������%d\t", atoi(bill_list->money));
		printf("������Դ��%s\n", bill_list->cause);*/
		if (strcmp(expense_information, expense_list->cause) == 0)
		{
			printf("\t\t\t\t�Ѳ鵽������Դ�������\n");
			printf("\t\t\t\t����%s����Ϊ��%s\n", expense_list->cause, expense_list->money);
		}
		//ʹָ��ָ����һ���ڵ�
		expense_list = expense_list->next;
	}
	printf("\t\t\t=================================\n");
	//system("pause");
}