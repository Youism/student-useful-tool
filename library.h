#ifndef LIBRARY_H
#define LIBRARY_H
/*
*   ����ͼ��Ľṹ��
*/
typedef struct bookinfo/*ϵͳͼ����Ϣ */
{
    char number[15];/*ͼ����*/
    char name[30];/*ͼ������*/
    char author[20];/*����*/
    char press[30];/*������*/
    char category[20]; /*���*/
    float price;/*����*/
    int  quantity;/*�ݲ���*/
    int  time;/*�������*/
}library_book;
#define BOOK_NUMBER 30
#define BOOK_INFO 100
#pragma warning(disable : 4996)//��������
int check_repeat_book(char number[BOOK_NUMBER]);
void add_book() /*�����½���ͼ����Ϣ*/;
void display_popular();
void display_book();
void display_price_lower();
void modify_book();
void delete_book();
void search_book();
#endif // !LIBRARY_H
