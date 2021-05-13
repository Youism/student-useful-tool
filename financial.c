#include<stdio.h>
#include"financial.h"

/*
*	@name		income_fin
*	@parma		current_account	全局变量
*	@param		income_filename	文件名
*	@version	2.0
*	@function	用户输入最近的收入以及收入来源，
*					并将该记录保存在一个文件下
*/	
void  
income_fin() 
{
	system("cls");

	/*Bill *head=(Bill*)malloc(sizeof(Bill));
	head->next = NULL;*/

	//指针p指向链表的为节点
	//Bill* p = head;

	//打开文件
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
		printf("已成功为您自动创建资金管理文件\n");
		printf("--------------------------------------\n");
	}

	printf("欢迎来到金融收入管理系统！\n");
	while (1)
	{
		//动态分配资金的内存
		Bill* newbill = (Bill*)malloc(sizeof(Bill));

		printf("请输入收入金额(请输入四位数，例如[0100])：");
		printf("输入【0】退出\n");
		scanf("%s",newbill->money);
		
		if (strcmp(newbill->money,"0")==0)
		{
			//exit(0);
			return;
		}
		printf("\n");
		printf("请输入入账原因(注意不要加空格)：");
		scanf("%s",newbill->cause);
		
		//将信息写入文件中
		fwrite_bill(newbill,fp);

		//尾插法将新的节点插入进链表中
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
**	@function	将收入金额和原因写入文件中
*/
void 
fwrite_bill(Bill* bill, FILE* fp)
{
	//写入时多写入一个无用字符，使得判断文件尾部时使用fgetc不会产生影响
	fputc('!', fp);
	//添加账户到文件，末尾不添加回车
	fprintf(fp, "%s", bill->money);
	//添加原因到文件，末尾添加回车
	fprintf(fp, "%s\n", bill->cause);
	if (fp == NULL) {
		printf("未知错误！");
	}
	
}
/*
*	@name		fread_fin
*	@param		FILE 
*	@param		Bill
*	@param		int
*	@version	1.4
*	@function	读取保存的文件中的数据，然后返回一个指向数据的指针,传入一个数值[0-2]，
*					0表示读取收入账单信息，1表示读取支出账单信息，2表示欠费账单信息			
*/	

Bill* 
fread_fin(int num)
{	

	//定义一个指针数组，保存文件名信息
	//欠费账单文件名字
	extern char current_account[8];

	char arrears_filename[50] ;
	strcpy(arrears_filename, current_account);
	strcat(arrears_filename, "_arrears.log");
	//支出账单文件名	
	char  expense_filename[50];
	strcpy(expense_filename, current_account);
	strcat(expense_filename, "_expense.log");
	//收入账单文件名字
	char income_filename[50];
	strcpy(income_filename, current_account);
	strcat(income_filename, "_income.log");

	//设置数组保存文件名
	char *s[] = { income_filename,expense_filename,arrears_filename };
	char *filename ;
	filename = s[num];
	
	//读账户文件
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		//文件不存在时就创建文件
		fp = fopen(filename, "w");
		printf("\t\t\t文件不存在，已重新创建！\n");
		return NULL;
	}
	if (fp == NULL)
	{
		printf("\t\t\t未知错误！账户文件打开失败！\n");
		return NULL;
	}

	//创建新节点
	Bill* head = (Bill*)malloc(sizeof(Bill));
	head->next = NULL;
	//指针p指向链表的尾节点
	Bill* p = head;

	//进行读取操作
	while (fgetc(fp) != EOF)
	{
		Bill* newbill = (Bill*)malloc(sizeof(Bill));
		//newacc->next = NULL;
		//将文件的账户和密码读取出来放在新建账户中
		fgets(newbill->money, 5, fp);
		
		//fscanf(fp,"%d",newbill->money);
		/*
		fscanf(fp,newbill->cause);*/

		fgets(newbill->cause, 17, fp);
		//将多读出来的那个字符变成数组结尾的标志
		newbill->cause[strlen(newbill->cause) - 1] = '\0';
		
		//链表的插入
		newbill->next = NULL;
		p->next = newbill;
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

/*	
*	@name		free_billList
*	@parma		Bill 
*	@version	1.0
*	@fucntion	用来释放金额和原因的链表	
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
*	@function	传入一个指向数据链表的指针，然后输出所有的数据	
*/
void 
show_bill_list()
{
	system("cls");
	Bill* bill_list = (Bill*)malloc(sizeof(Bill));
	bill_list = fread_fin(0);
	while (bill_list != NULL)
	{
		printf("金额数：%d\t",atoi(bill_list->money));
		printf("收入来源：%s\n",bill_list->cause);

		//使指针指向下一个节点
		bill_list = bill_list->next;
	}
	system("pause");

}

/*
*	@name		show_arreaars_list
*	@param		Bill
*	@version	1.0
*	@function	传入一个指向数据链表的指针，然后输出所有的数据
*/
void 
show_arrears_list()
{
	system("cls");
	Bill* arrears_list = (Bill*)malloc(sizeof(Bill));
	arrears_list = fread_fin(2);
	while (arrears_list != NULL)
	{
		printf("欠费金额数：%d\t", atoi(arrears_list->money));
		printf("欠费来源：%s\n", arrears_list->cause);

		//使指针指向下一个节点
		arrears_list = arrears_list->next;
	}
	system("pause");
}

/*
*	@name expense
*	@param Bill
*	【函数功能】用来创建一个等待支出的的链表，保存待支出的金额和等待支出的原因
*	【函数返回值】无
*/	

void 
expense()
{
	system("cls");

	/*Bill* head = (Bill*)malloc(sizeof(Bill));
	head->next = NULL;*/

	//指针p指向链表的为节点
	

	//打开文件
	extern char current_account[8];
	/*char* show_filename = strcat(current_account, "_stu.csv");*/
	char expense_filename[50];
	strcpy(expense_filename, current_account);
	strcat(expense_filename, "_expense.log");
	FILE* fp = fopen(expense_filename, "a");
	if (fp == NULL)
	{
		fp = fopen(expense_filename, "w");
		printf("已成功为您自动创建资金管理文件\n");
		printf("--------------------------------------\n");
	}

	//printf("欢迎来到金融收入管理系统！\n");
	printf("欢迎来的金融系统的等待支出系统！");
	while (1)
	{
		//动态分配资金的内存
		Bill* newbill = (Bill*)malloc(sizeof(Bill));

		printf("请输入待支出金额(请输入四位数，例如[0100])：");
		printf("输入【0】退出\n");
		scanf("%s", newbill->money);
		if (strcmp(newbill->money, "0") == 0)
		{
			//exit(0);
			return;
		}
		printf("\n");
		printf("请输入支出原因：");
		scanf("%s", newbill->cause);

		//将信息写入文件中
		fwrite_bill(newbill, fp);

		//尾插法将新的节点插入进链表中
		/*newbill->next = NULL;
		p->next = newbill;
		p = p->next;*/

	}
	fclose(fp);

}

/*
*	@name show_expense_list
*	@param Bill 
*	[函数功能]用来输出文件中所有的信息
*	[返回值]无
*/	
void 
show_expense_list()
{
	system("cls");
	Bill* bill_expense_list = (Bill*)malloc(sizeof(Bill));
	bill_expense_list = fread_fin(1);

	while (bill_expense_list != NULL)
	{
		printf("支出金额数：%d\t", atoi(bill_expense_list->money));
		printf("待支出去向：%s\n", bill_expense_list->cause);

		//使指针指向下一个节点
		bill_expense_list = bill_expense_list->next;
	}
	free_billList(bill_expense_list);
	system("pause");

}

/*
*	[函数功能]如果待支出的总金额大于收入板块，那么会显示出用户的欠费情况。
*			  用户可以录入欠费金额和原因，然后将这个文件保存起来
*	@function name :arrears
*	
*/
void 
arrears()
{
	//设置收入金额
	int sum_income	= 0;
	int sum_expense = 0;
	int arrears = 0;	/*设置欠费情况*/

	//读取收入账单文件信息
	Bill* income_read_list = (Bill*)malloc(sizeof(Bill));
	//欠费账信息
	Bill* arrears_read_list = (Bill*)malloc(sizeof(Bill));

	//传入数值0，表示读取收入账单信息
	income_read_list=fread_fin(0);

	while (income_read_list != NULL)
	{
		sum_income+=atoi(income_read_list->money);
		income_read_list = income_read_list->next;
	}

	//读取支出账单文件信息
	Bill* expense_read_list = (Bill*)malloc(sizeof(Bill));
	//传入数值1，表示读取收入账单信息
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
			printf("已成功为您自动创建资金欠费管理文件\n");
			printf("--------------------------------------\n");
		}
		printf("您好！目前您已欠费\n");
		arrears = sum_expense - sum_income;
		printf("您目前的收入已欠费%2d元\n",arrears);
		printf("---------------------------\n");

		//表明已经欠费，提醒用户输入欠费情况
		printf("请输入您的欠费情况：\n");
		while (1)
		{
			//动态分配资金的内存
			Bill* newbill_arrears = (Bill*)malloc(sizeof(Bill));

			printf("请输入欠费金额(请输入四位数，例如[0100])：");
			printf("输入【0】退出\n");
			scanf("%s", newbill_arrears->money);
			if (strcmp(newbill_arrears->money, "0") == 0)
			{
				//exit(0);
				return;
			}
			printf("\n");
			printf("请输入欠费原因原因：");
			scanf("%s", newbill_arrears->cause);

			//将信息写入文件中
			fwrite_bill(newbill_arrears, fp);

			//尾插法将新的节点插入进链表中
			/*newbill_arrears->next = NULL;
			p->next = newbill_arrears;
			p = p->next;*/

		}
		fclose(fp);

	}
	else
	{
		printf("您好！您目前没有欠费情况！");
	}
	system("pause");
}

/*	
*	@name		loacate_income_cause
*	@param		Bill
*	@version	1.0
*	@function	用来定位收入的金额
*/
void 
locate_income_cause()
{
	system("cls");
	Bill* income_list = (Bill*)malloc(sizeof(Bill));
	char income_information[20];

	printf("\t\t\t\t=================================\n");
	printf("\t\t\t\t请输入您想查找的消费信息：\n");

	scanf("%s",income_information);
	income_list=fread_fin(0);

	//遍历整个收入账单，查找特定信息
	while (income_list != NULL)
	{
		/*printf("金额数：%d\t", atoi(bill_list->money));
		printf("收入来源：%s\n", bill_list->cause);*/
		if (strcmp(income_information, income_list->cause) == 0)
		{
			printf("\t\t\t\t已查到收入来源的收入金额！\n");
			printf("\t\t\t\t您的%s收入为：%s\n",income_list->cause,income_list->money);
		}
		//使指针指向下一个节点
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
*	@function	用来定位支出的金额
*/
locate_expense_cause()
{
	system("cls");
	Bill* expense_list = (Bill*)malloc(sizeof(Bill));
	char expense_information[20];

	printf("\t\t\t\t=================================\n");
	printf("\t\t\t\t请输入您想查找的消费信息：\n");

	scanf("%s", expense_information);
	expense_list = fread_fin(1);

	//遍历整个收入账单，查找特定信息
	while (expense_list != NULL)
	{
		/*printf("金额数：%d\t", atoi(bill_list->money));
		printf("收入来源：%s\n", bill_list->cause);*/
		if (strcmp(expense_information, expense_list->cause) == 0)
		{
			printf("\t\t\t\t已查到收入来源的收入金额！\n");
			printf("\t\t\t\t您的%s收入为：%s\n", expense_list->cause, expense_list->money);
		}
		//使指针指向下一个节点
		expense_list = expense_list->next;
	}
	printf("\t\t\t=================================\n");
	//system("pause");
}