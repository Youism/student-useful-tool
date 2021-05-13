#ifndef FINANCIAL_H
#define FINANCIAL_H
#pragma warning(disable : 4996)//消除警告

/* 
*	定义账单的结构体,包括收入，支出，欠费信息都是用的账单的结构体
*/
typedef struct bill {
	//金额
	char money[10];
	//原因
	char cause[20];
	//指向该节点的指针
	struct bill* next;
}Bill;

void income_fin();
void history_in_fin();
void history_out_fin();
void fwrite_bill();
void expense();
void arrears();
void locate_expense_cause();
void locate_income_cause();
void show_expense_list();
void show_bill_list();
void show_arrears_list();
Bill* fread_fin(int);
void fwrite_bill(Bill*, FILE*);
void free_billList(Bill* billList);

#endif // !FINANCIAL_H
