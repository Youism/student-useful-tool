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
#define MAXSIZE 100 /* 存储空间初始分配量 */
typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码，如TRUE等 */
#define HASHSIZE 300 // 定义哈希表长为数组的长度
#define NULLKEY -1
typedef int Status;
typedef struct book_note{
	//	书名
	char title[30] ;
	//作者名
	char author[30];
	//短评
	char comments[MAXCOMMENT] ;
	//你的评分星级（*~*****）
	char star[10];
	//显示当地时间
	char current_time[50];
	//接受评分
	int size_star;
	//结构体长度
	int length;
}note;
//存放书籍数目的一个结构体
typedef struct bookshelf {
	char title[30];
	int count;
}BookShelf;

typedef struct cache
{
	//int* elem; // 数据元素存储基址，动态分配数组
	//int count; //  当前数据元素个数
	char title[30];
	int count;
	struct cache* next;
}Cache;
//哈希表
typedef struct {
	Cache* elem; // 数据元素存储基址，动态分配数组
	int count;	//  当前数据元素个数
}HashTable;

typedef struct searched{
	char name[30];
	struct searched* next;
}Searched;

void add_book_record();
void fwrite_note(note new_record, FILE* fp);
void show_all_info();
//升序
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
