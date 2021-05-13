#include<stdlib.h>
#include"menu.h"
#include"account.h"
#include"grades.h"
#include"financial.h"
#include"library.h"

/*
*	@name			main_menu
*	@version		1.0			第一次界面如下
*	@version		2.0			更新了菜单的输出界面，使他更加美观
*	@function		输出了登录界面和注册界面的，提示用户往下操作
*/
void 
main_menu()
{

	/*	【功能】管理系统的主界面，启动程序后就会出现该界面
	**	【登录功能】按1即可进入登录系统登录
	**	【注册系统】用户输入2即可进入账户注册系统
	**	【退出系统】用户输入0即可退出系统
	*/
	/*printf("\t\t\t欢迎进入学生综合信息管理系统！\t\n\n");
	printf("\t\t\t--------------------------------------\n");
	printf("\t\t\t--------------------------------------\n");
	printf("\t\t\t||【登录账户】[1]按1进入登录系统登录||\n");
	printf("\t\t\t||【注册账户】[2]按2进入账户注册系统||\n");
	printf("\t\t\t||【退出系统】[0]按0退出系统	    ||\n");
	printf("\t\t\t--------------------------------------\n");
	printf("\t\t\t--------------------------------------\n");*/
	//system("color E9");
	while (1)
	{
		system("cls");
		printf("\n\n");
		printf("\t\t\t\t\t\t *=======================================*\n");
		printf("\t\t\t\t\t\t|  * - * - * S-C-A-M-S PangCY	 * - * - *|\n");
		printf("\t\t\t\t\t\t| *                                     * |\n");
		printf("\t\t\t\t\t\t| |  [1]   登录账户                     | |\n");
		printf("\t\t\t\t\t\t| *                                     * |\n");
		printf("\t\t\t\t\t\t| |  [2]   账户注册                     | |\n");
		printf("\t\t\t\t\t\t| *                                     * |\n");
		printf("\t\t\t\t\t\t| |  [0]   退出系统                     | |\n");
		printf("\t\t\t\t\t\t| *                                     * |\n");
		printf("\t\t\t\t\t\t| |  [4]   关于版本                     | |\n");
		printf("\t\t\t\t\t\t| *                                     * |\n");
		printf("\t\t\t\t\t\t|  * - * - * - * - * - * - * - * - * - *  |\n");
		printf("\t\t\t\t\t\t *=======================================*\n");

		int num;
		printf("\t\t\t请输入您要进行的操作：");
		scanf("%d", &num);
		if (num == 0)
			exit(0);
		else if (num == 1)
			sign_in();
		else if (num == 2)
			add_account();
		system("cls");
	}
	

}

/*	【函数功能】显示次菜单
**	【成绩管理】按[1]进入成绩管理界面
**	【图书管理】按[2]进入图书管理界面
**	【财务管理】按[3]进入财务管理界面
**	【退出】按[0]退出系统
*/
void 
sub_menu() 
{
	
	//system("cls");
	//printf("【成绩管理】[1]\n");
	//printf("【图书管理】[2]\n");
	//printf("【财务管理】[3]\n");
	//printf("【退出系统】[0]\n");
	//printf("请输入您的操作\n");
	int num;
	/*scanf("%d",&num);*/
	while (1)
	{
		system("cls");
		printf("\t\t\t\t\t\t登录成功！请选择以下数字进入相应板块\n");
		printf("\t\t\t\t\t\t|---------------|\n");
		printf("\t\t\t\t\t\t|【成绩管理】[1]|\n");
		printf("\t\t\t\t\t\t|【图书管理】[2]|\n");
		printf("\t\t\t\t\t\t|【财务管理】[3]|\n");
		printf("\t\t\t\t\t\t|【读书记录】[4]|\n");
		printf("\t\t\t\t\t\t|【退出系统】[0]|\n");
		printf("\t\t\t\t\t\t|---------------|\n");

		printf("\t\t\t\t\t请输入您的操作：");
		scanf("%d", &num);
		if (num==1)
		{
			grades_menu();
		}
		if (num == 2)
		{
			library_menu();

		}

		if (num==3)
		{
			financial_menu();
		}
		if (num == 4)
		{
			book_note_menu();
		}
		if (num == 0)
		{
			return;
		}
	}
	
	

}

/*	【函数功能】成绩管理菜单
*	【输入1】展示成绩
*	【输入2】调用成绩计算函数
*	【输入3】调用查找成绩函数
*	【输入4】调用成绩分析函数
*	@version 1.0		添加了输出菜单，但不是很美观
*	@version 2.0		更新了输出方式，是输出更加美观
*/
void 
grades_menu()
{

	//extern char* grades_filename;
	//void get_filename();
	int num;
	//scanf("%d", &num);
	while (1)
	{
		system("cls");
		//printf("			|欢迎进入成绩管理系统！\n请按照以下提示进行操作：	\n");
		//printf("			|-------------------\n");
		//printf("			|[1]展示成绩\t\t|\n");
		//printf("			|[2]计算平均学分\t|\n");
		//printf("			|[3]查找特定成绩\t|\n");
		//printf("			|[4]成绩分析及建议\t|\n");
		//printf("			|[0]退出成绩管理系统\t|\n");
		//printf("			|-------------------\t|\n");
		//printf("			|请输入您想要的操作：");

		printf("\t\t\t\t\t\t *======================================*\n");
		printf("\t\t\t\t\t\t| | * - * - * 成绩-管理-界面 * - * - * | |\n");
		printf("\t\t\t\t\t\t| *                                    * |\n");
		printf("\t\t\t\t\t\t| |  [1]   展示成绩                    | |\n");
		printf("\t\t\t\t\t\t| *  [2]   计算平均学分                * |\n");
		printf("\t\t\t\t\t\t| |  [3]   查找指定成绩                | |\n");
		printf("\t\t\t\t\t\t| *  [4]   成绩分析及建议              * |\n");
		printf("\t\t\t\t\t\t| |  [0]   退出成绩管理系统            | |\n");
		printf("\t\t\t\t\t\t| |                                    | |\n");
		printf("\t\t\t\t\t\t| * - * - * - * - * -- * - * - * - * - * |\n");
		printf("\t\t\t\t\t\t *======================================*\n");

		printf("\t\t\t\t\t\t|欢迎进入成绩管理系统！\n请按照以下提示进行操作\n");
		printf("请输入您想要的操作：");
		scanf("%d", &num);

		if (num == 1) {
			show_grades();
			
		}
			
		if (num == 2)
		{
			cal_grades();
			
		}
			
		if (num == 3) {
			search_grades();
			
		}
			
		if (num == 4) {
			advice_grades();
			
		}
		if (num == 0)
			return;
			
			
		
	}
}

/*
*	@name		financial_menu
*	@version	2.0		更改了菜单界面，使他更加美观
*	@function	打印金融管理系统的菜单
*/
void 
financial_menu()
{
	int num;

	while (1)
	{
		system("cls");
	/*	printf("			|欢迎进入金融管理系统！\n请按照以下提示进行操作：	\n");
		printf("			|-------------------\n");
		printf("			|[1]录入收入信息：创建收入账单\t\t\n");
		printf("			|[2]录入支出信息：创建支出账单\t|\n");
		printf("			|[3]查看欠费情况\t\n");
		printf("			|[4]查看特定消费信息\t\n");
		printf("			|[5]展示用户全部收入信息\t\n");
		printf("			|[6]展示用户全部消费信息\t\n");
		printf("			|[7]展示用户全部欠费信息\t\n");
		printf("			|[0]退出金融管理系统\t\n");
		printf("			|-------------------\t\n");
		printf("			|请输入您想要的操作：");*/

		printf("\n\n");
		printf("\t\t\t\t\t\t *======================================*\n");
		printf("\t\t\t\t\t\t| | * - * - * 资-金-管-理-面 * - * - * | |\n");
		printf("\t\t\t\t\t\t| *                                    * |\n");
		printf("\t\t\t\t\t\t| |  [1]   录入收入信息                | |\n");
		printf("\t\t\t\t\t\t| *  [2]   录入支出信息                * |\n");
		printf("\t\t\t\t\t\t| |  [3]   查看欠费情况                | |\n");
		printf("\t\t\t\t\t\t| *  [4]   查看某一消费信息            * |\n");
		printf("\t\t\t\t\t\t| |  [5]   展示用户全部收入信息        | |\n");
		printf("\t\t\t\t\t\t| *  [6]   展示用户全部消费信息        * |\n");
		printf("\t\t\t\t\t\t| |  [7]   展示用户全部欠费信息        | |\n");
		printf("\t\t\t\t\t\t| *  [0]   退出金融管理系统            * |\n");
		printf("\t\t\t\t\t\t| |                                    | |\n");
		printf("\t\t\t\t\t\t| * - * - * - * - * -- * - * - * - * - * |\n");
		printf("\t\t\t\t\t\t *======================================*\n");
		printf("\t\t\t\t\t\t|欢迎进入金融管理系统！\n请按照以下提示进行操作\n");
		printf("请输入您想要的操作：");
		scanf("%d", &num);

		if (num == 1) {
			income_fin();

		}

		if (num == 2)
		{
			expense();

		}

		if (num == 3) {
			arrears();

		}

		if (num == 4) {
			locate_financial_information_menu();

		}
		if (num==5)
		{
			show_bill_list();
		}
		if (num == 6)
		{
			show_expense_list();
		}
		if (num == 7)
		{
			show_arrears_list();
		}
		if (num == 0)
			return;



	}
}

void 
locate_financial_information_menu()
{
	printf("\t\t\t\t========================\n");
	printf("\t\t\t\t||[1]查找收入信息\n||");
	printf("\t\t\t\t||[1]查找支出信息\n||");
	printf("\t\t\t\t========================\n");

	int num;
	scanf("%d",&num);
	if (num == 1)
	{
		locate_income_cause();
	}
	if (num == 2)
	{
		locate_expense_cause();
	}
}

/*
*	@name library_menu
*	该函数用来展示图书管理系统界面，并且附带指引用户操作
*/
void 
library_menu()
{
	int num=0;

	while (1)
	{
		system("cls");

		printf("\n\n");
		printf("\t\t\t *======================================*\n");
		printf("\t\t\t| | * - * - * 图书-管理-界面 * - * - * | |\n");
		printf("\t\t\t| *                                    * |\n");
		printf("\t\t\t| |  [1]   添加图书                    | |\n");
		printf("\t\t\t| *  [2]   删减图书                    * |\n");
		printf("\t\t\t| |  [3]   修改图书信息                | |\n");
		printf("\t\t\t| *  [4]   查找图书信息                * |\n");
		printf("\t\t\t| |  [5]   显示全部图书信息            | |\n");
		printf("\t\t\t| *  [6]   显示图书欢迎程度            * |\n");
		printf("\t\t\t| |  [7]   价位书籍推荐                | |\n");
		printf("\t\t\t| *  [0]   退出图书管理系统界面        * |\n");
		printf("\t\t\t| |                                    | |\n");
		printf("\t\t\t| * - * - * - * - * -- * - * - * - * - * |\n");
		printf("\t\t\t *======================================*\n");
		printf("\t\t\t|欢迎进入图书管理系统！\n请按照以下提示进行操作\n");
		printf("请输入您想要的操作：");
		scanf("%d", &num);

		if (num == 1) {
			add_book();

		}

		if (num == 2)
		{
			delete_book();

		}

		if (num == 3) {
			modify_book();

		}

		if (num == 4) {
			search_book();

		}
		if (num == 5)
			display_book();
		if (num == 6)
			display_popular();
		if (num == 7)
			display_price_lower();
		if (num == 0)
			return;

	}
}

void
book_note_menu()
{
	while (1)
	{
		system("cls");
		printf("\t\t\t\t\t\t *======================================*\n");
		printf("\t\t\t\t\t\t| | * - * - * 读书-记录-界面 * - * - * | |\n");
		printf("\t\t\t\t\t\t| *                                    * |\n");
		printf("\t\t\t\t\t\t| |  [1]   添加记录                    | |\n");
		printf("\t\t\t\t\t\t| *  [2]   按评分升序                  * |\n");
		printf("\t\t\t\t\t\t| *  [3]   按评分降序                  * |\n");
		printf("\t\t\t\t\t\t| *  [4]   显示所有读书记录            * |\n");
		printf("\t\t\t\t\t\t| |  [0]   退出读书记录系统            | |\n");
		printf("\t\t\t\t\t\t| |                                    | |\n");
		printf("\t\t\t\t\t\t| * - * - * - * - * -- * - * - * - * - * |\n");
		printf("\t\t\t\t\t\t *======================================*\n");

		printf("\t\t\t|欢迎进入成绩管理系统！\n请按照以下提示进行操作\n");
		printf("请输入您想要的操作：");
		int num = 0;
		scanf("%d", &num);

		if (num == 1) {
			add_book_record();

		}

		if (num == 2)
		{
			nondecreasing_sort();

		}

		if (num == 3) {
			nonincreasing_sort();

		}

		if (num == 4) {
			
			show_all_info();
		}
		if (num == 0)
			return;
	}
}