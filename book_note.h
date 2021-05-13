#include <stdbool.h>
#ifndef _BOOK_NOTE_H
#define _BOOK_NOTE_H

#define MAXCOMMENT 100
#define MAX_BOOK_LOG 100
#define MAX_LONG_COMMENTS 10000
#pragma warning(disable : 4996)
#define max(x,y) x>y?x:y 
#define OK 0
#define ERROR -1
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /* �洢�ռ��ʼ������ */
typedef int Status;	/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��TRUE�� */
#define HASHSIZE 300 // �����ϣ��Ϊ����ĳ���
#define NULLKEY -1
typedef int Status;
typedef struct book_note{
	//	����
	char title[30] ;
	//������
	char author[30];
	//����
	char comments[MAXCOMMENT] ;
	//��������Ǽ���*~*****��
	char star[10];
	//��ʾ����ʱ��
	char current_time[50];
	//��������
	int size_star;
	//�ṹ�峤��
	int length;
}note;
//����鼮��Ŀ��һ���ṹ��
typedef struct bookshelf {
	char title[30];
	int count;
}BookShelf;

typedef struct cache
{
	//int* elem; // ����Ԫ�ش洢��ַ����̬��������
	//int count; //  ��ǰ����Ԫ�ظ���
	char title[30];
	int count;
	struct cache* next;
}Cache;
//��ϣ��
typedef struct {
	Cache* elem; // ����Ԫ�ش洢��ַ����̬��������
	int count;	//  ��ǰ����Ԫ�ظ���
}HashTable;

typedef struct searched{
	char name[30];
	struct searched* next;
}Searched;

void add_book_record();
void fwrite_note(note new_record, FILE* fp);
void show_all_info();
//����
void nondecreasing_sort();
void nonincreasing_sort();
void appendix_comments();
Cache* statistics_author();
void long_comments();
void to_read();
void update_log();
void print_out_sort(note* book_log, int book_number);
const char* get_filename();
note* read_from_file();
void show_all_info();
void long_comment();
void search_author();
void print_author_times();
bool determine(Searched* head, char* author);
int
longest_common_sub(char* wordA, char* wordB);
Status searchHash(HashTable hash, char* key, int* addr);
void insertHash(HashTable* hash, char* key, int count);
int hashFun(char* key);
Status initHashTable(HashTable* hash);
void make_hashtable();
void
free_cacheList(Cache* List);
void
nonincreasing_author_sort();
//int length;
#endif // !BOOK_NOTE_H
