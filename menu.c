#include<stdlib.h>
#include"menu.h"
#include"account.h"
#include"grades.h"
#include"financial.h"
#include"library.h"

/*
*	@name			main_menu
*	@version		1.0			��һ�ν�������
*	@version		2.0			�����˲˵���������棬ʹ����������
*	@function		����˵�¼�����ע�����ģ���ʾ�û����²���
*/
void 
main_menu()
{

	/*	�����ܡ�����ϵͳ�������棬���������ͻ���ָý���
	**	����¼���ܡ���1���ɽ����¼ϵͳ��¼
	**	��ע��ϵͳ���û�����2���ɽ����˻�ע��ϵͳ
	**	���˳�ϵͳ���û�����0�����˳�ϵͳ
	*/
	/*printf("\t\t\t��ӭ����ѧ���ۺ���Ϣ����ϵͳ��\t\n\n");
	printf("\t\t\t--------------------------------------\n");
	printf("\t\t\t--------------------------------------\n");
	printf("\t\t\t||����¼�˻���[1]��1�����¼ϵͳ��¼||\n");
	printf("\t\t\t||��ע���˻���[2]��2�����˻�ע��ϵͳ||\n");
	printf("\t\t\t||���˳�ϵͳ��[0]��0�˳�ϵͳ	    ||\n");
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
		printf("\t\t\t\t\t\t| |  [1]   ��¼�˻�                     | |\n");
		printf("\t\t\t\t\t\t| *                                     * |\n");
		printf("\t\t\t\t\t\t| |  [2]   �˻�ע��                     | |\n");
		printf("\t\t\t\t\t\t| *                                     * |\n");
		printf("\t\t\t\t\t\t| |  [0]   �˳�ϵͳ                     | |\n");
		printf("\t\t\t\t\t\t| *                                     * |\n");
		printf("\t\t\t\t\t\t| |  [4]   ���ڰ汾                     | |\n");
		printf("\t\t\t\t\t\t| *                                     * |\n");
		printf("\t\t\t\t\t\t|  * - * - * - * - * - * - * - * - * - *  |\n");
		printf("\t\t\t\t\t\t *=======================================*\n");

		int num;
		printf("\t\t\t��������Ҫ���еĲ�����");
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

/*	���������ܡ���ʾ�β˵�
**	���ɼ�������[1]����ɼ��������
**	��ͼ�������[2]����ͼ��������
**	�����������[3]�������������
**	���˳�����[0]�˳�ϵͳ
*/
void 
sub_menu() 
{
	
	//system("cls");
	//printf("���ɼ�����[1]\n");
	//printf("��ͼ�����[2]\n");
	//printf("���������[3]\n");
	//printf("���˳�ϵͳ��[0]\n");
	//printf("���������Ĳ���\n");
	int num;
	/*scanf("%d",&num);*/
	while (1)
	{
		system("cls");
		printf("\t\t\t\t\t\t��¼�ɹ�����ѡ���������ֽ�����Ӧ���\n");
		printf("\t\t\t\t\t\t|---------------|\n");
		printf("\t\t\t\t\t\t|���ɼ�����[1]|\n");
		printf("\t\t\t\t\t\t|��ͼ�����[2]|\n");
		printf("\t\t\t\t\t\t|���������[3]|\n");
		printf("\t\t\t\t\t\t|�������¼��[4]|\n");
		printf("\t\t\t\t\t\t|���˳�ϵͳ��[0]|\n");
		printf("\t\t\t\t\t\t|---------------|\n");

		printf("\t\t\t\t\t���������Ĳ�����");
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

/*	���������ܡ��ɼ�����˵�
*	������1��չʾ�ɼ�
*	������2�����óɼ����㺯��
*	������3�����ò��ҳɼ�����
*	������4�����óɼ���������
*	@version 1.0		���������˵��������Ǻ�����
*	@version 2.0		�����������ʽ���������������
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
		//printf("			|��ӭ����ɼ�����ϵͳ��\n�밴��������ʾ���в�����	\n");
		//printf("			|-------------------\n");
		//printf("			|[1]չʾ�ɼ�\t\t|\n");
		//printf("			|[2]����ƽ��ѧ��\t|\n");
		//printf("			|[3]�����ض��ɼ�\t|\n");
		//printf("			|[4]�ɼ�����������\t|\n");
		//printf("			|[0]�˳��ɼ�����ϵͳ\t|\n");
		//printf("			|-------------------\t|\n");
		//printf("			|����������Ҫ�Ĳ�����");

		printf("\t\t\t\t\t\t *======================================*\n");
		printf("\t\t\t\t\t\t| | * - * - * �ɼ�-����-���� * - * - * | |\n");
		printf("\t\t\t\t\t\t| *                                    * |\n");
		printf("\t\t\t\t\t\t| |  [1]   չʾ�ɼ�                    | |\n");
		printf("\t\t\t\t\t\t| *  [2]   ����ƽ��ѧ��                * |\n");
		printf("\t\t\t\t\t\t| |  [3]   ����ָ���ɼ�                | |\n");
		printf("\t\t\t\t\t\t| *  [4]   �ɼ�����������              * |\n");
		printf("\t\t\t\t\t\t| |  [0]   �˳��ɼ�����ϵͳ            | |\n");
		printf("\t\t\t\t\t\t| |                                    | |\n");
		printf("\t\t\t\t\t\t| * - * - * - * - * -- * - * - * - * - * |\n");
		printf("\t\t\t\t\t\t *======================================*\n");

		printf("\t\t\t\t\t\t|��ӭ����ɼ�����ϵͳ��\n�밴��������ʾ���в���\n");
		printf("����������Ҫ�Ĳ�����");
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
*	@version	2.0		�����˲˵����棬ʹ����������
*	@function	��ӡ���ڹ���ϵͳ�Ĳ˵�
*/
void 
financial_menu()
{
	int num;

	while (1)
	{
		system("cls");
	/*	printf("			|��ӭ������ڹ���ϵͳ��\n�밴��������ʾ���в�����	\n");
		printf("			|-------------------\n");
		printf("			|[1]¼��������Ϣ�����������˵�\t\t\n");
		printf("			|[2]¼��֧����Ϣ������֧���˵�\t|\n");
		printf("			|[3]�鿴Ƿ�����\t\n");
		printf("			|[4]�鿴�ض�������Ϣ\t\n");
		printf("			|[5]չʾ�û�ȫ��������Ϣ\t\n");
		printf("			|[6]չʾ�û�ȫ��������Ϣ\t\n");
		printf("			|[7]չʾ�û�ȫ��Ƿ����Ϣ\t\n");
		printf("			|[0]�˳����ڹ���ϵͳ\t\n");
		printf("			|-------------------\t\n");
		printf("			|����������Ҫ�Ĳ�����");*/

		printf("\n\n");
		printf("\t\t\t\t\t\t *======================================*\n");
		printf("\t\t\t\t\t\t| | * - * - * ��-��-��-��-�� * - * - * | |\n");
		printf("\t\t\t\t\t\t| *                                    * |\n");
		printf("\t\t\t\t\t\t| |  [1]   ¼��������Ϣ                | |\n");
		printf("\t\t\t\t\t\t| *  [2]   ¼��֧����Ϣ                * |\n");
		printf("\t\t\t\t\t\t| |  [3]   �鿴Ƿ�����                | |\n");
		printf("\t\t\t\t\t\t| *  [4]   �鿴ĳһ������Ϣ            * |\n");
		printf("\t\t\t\t\t\t| |  [5]   չʾ�û�ȫ��������Ϣ        | |\n");
		printf("\t\t\t\t\t\t| *  [6]   չʾ�û�ȫ��������Ϣ        * |\n");
		printf("\t\t\t\t\t\t| |  [7]   չʾ�û�ȫ��Ƿ����Ϣ        | |\n");
		printf("\t\t\t\t\t\t| *  [0]   �˳����ڹ���ϵͳ            * |\n");
		printf("\t\t\t\t\t\t| |                                    | |\n");
		printf("\t\t\t\t\t\t| * - * - * - * - * -- * - * - * - * - * |\n");
		printf("\t\t\t\t\t\t *======================================*\n");
		printf("\t\t\t\t\t\t|��ӭ������ڹ���ϵͳ��\n�밴��������ʾ���в���\n");
		printf("����������Ҫ�Ĳ�����");
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
	printf("\t\t\t\t||[1]����������Ϣ\n||");
	printf("\t\t\t\t||[1]����֧����Ϣ\n||");
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
*	�ú�������չʾͼ�����ϵͳ���棬���Ҹ���ָ���û�����
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
		printf("\t\t\t| | * - * - * ͼ��-����-���� * - * - * | |\n");
		printf("\t\t\t| *                                    * |\n");
		printf("\t\t\t| |  [1]   ���ͼ��                    | |\n");
		printf("\t\t\t| *  [2]   ɾ��ͼ��                    * |\n");
		printf("\t\t\t| |  [3]   �޸�ͼ����Ϣ                | |\n");
		printf("\t\t\t| *  [4]   ����ͼ����Ϣ                * |\n");
		printf("\t\t\t| |  [5]   ��ʾȫ��ͼ����Ϣ            | |\n");
		printf("\t\t\t| *  [6]   ��ʾͼ�黶ӭ�̶�            * |\n");
		printf("\t\t\t| |  [7]   ��λ�鼮�Ƽ�                | |\n");
		printf("\t\t\t| *  [0]   �˳�ͼ�����ϵͳ����        * |\n");
		printf("\t\t\t| |                                    | |\n");
		printf("\t\t\t| * - * - * - * - * -- * - * - * - * - * |\n");
		printf("\t\t\t *======================================*\n");
		printf("\t\t\t|��ӭ����ͼ�����ϵͳ��\n�밴��������ʾ���в���\n");
		printf("����������Ҫ�Ĳ�����");
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
		printf("\t\t\t\t\t\t| | * - * - * ����-��¼-���� * - * - * | |\n");
		printf("\t\t\t\t\t\t| *                                    * |\n");
		printf("\t\t\t\t\t\t| |  [1]   ��Ӽ�¼                    | |\n");
		printf("\t\t\t\t\t\t| *  [2]   ����������                  * |\n");
		printf("\t\t\t\t\t\t| *  [3]   �����ֽ���                  * |\n");
		printf("\t\t\t\t\t\t| *  [4]   ��ʾ���ж����¼            * |\n");
		printf("\t\t\t\t\t\t| |  [0]   �˳������¼ϵͳ            | |\n");
		printf("\t\t\t\t\t\t| |                                    | |\n");
		printf("\t\t\t\t\t\t| * - * - * - * - * -- * - * - * - * - * |\n");
		printf("\t\t\t\t\t\t *======================================*\n");

		printf("\t\t\t|��ӭ����ɼ�����ϵͳ��\n�밴��������ʾ���в���\n");
		printf("����������Ҫ�Ĳ�����");
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