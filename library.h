#ifndef LIBRARY_H
#define LIBRARY_H
/*
*   定义图书的结构体
*/
typedef struct bookinfo/*系统图书信息 */
{
    char number[15];/*图书编号*/
    char name[30];/*图书名称*/
    char author[20];/*作者*/
    char press[30];/*出版社*/
    char category[20]; /*类别*/
    float price;/*单价*/
    int  quantity;/*馆藏量*/
    int  time;/*借书次数*/
}library_book;
#define BOOK_NUMBER 30
#define BOOK_INFO 100
#pragma warning(disable : 4996)//消除警告
int check_repeat_book(char number[BOOK_NUMBER]);
void add_book() /*输入新进的图书信息*/;
void display_popular();
void display_book();
void display_price_lower();
void modify_book();
void delete_book();
void search_book();
#endif // !LIBRARY_H
