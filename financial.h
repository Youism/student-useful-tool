#ifndef FINANCIAL_H
#define FINANCIAL_H
#pragma warning(disable : 4996)//��������

/* 
*	�����˵��Ľṹ��,�������룬֧����Ƿ����Ϣ�����õ��˵��Ľṹ��
*/
typedef struct bill {
	//���
	char money[10];
	//ԭ��
	char cause[20];
	//ָ��ýڵ��ָ��
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
