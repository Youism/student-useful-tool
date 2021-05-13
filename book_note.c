#include<stdio.h>
#include<time.h>
#include<string.h>
#include"book_note.h"
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXCOMMENT 100
int m = 0; // 哈希表表长，全局变量


//读书笔记模块包括写入书名，作者名，不超过一百字的短评，个人的星级打分，
			//由时间函数自动给出的时间以及


void 
add_book_record()
{
	getchar();
	//生成个人文件名
	//extern char current_account[8];
	//FILE* fp;
	char current_account[8];
	strcpy(current_account, "111111");
	char* filename = (char*)malloc(sizeof(char));
	strcpy(filename, current_account);
	strcat(filename, "_note.log");
	//char filename[50];

	//strcpy(filename, get_filename());

	//FILE* fp = fopen(filename, "a");

	/*if (fp == NULL)
	{
		fp = fopen(filename, "w");
		printf("\t\t\t\t已成功为您自动创建读书记录文件\n");
		printf("\t\t\t\t--------------------------------------\n");
	}*/

	/*else
	{
		fp = fopen(filename, "a");

	}*/
	//getchar();
	printf("\t\t\t\t欢迎来到读书笔记添加系统！\n");
	while (1)
	{	
		system("cls");
		printf("\t\t\t\t请依次输入【书名】【作者名】【短评】【评分】\n");

		//获取时间
	/*	time_t curtime;
		time(&curtime);*/
		char choice;

		//note* new_record = (note*)malloc(sizeof(note));
		note new_record;
		/*extern int length;
		length = 0;*/
		new_record.length = 0;

		printf("请输入书名：\n");
		//scanf("%s",new_record.title);
		gets_s(new_record.title,20);
		printf("请输入作者名：\n");
		//scanf("%s", new_record.author);
		gets_s(new_record.author,20);
		printf("请输入不超过一百字的简评：\n");
		//scanf("%s", new_record.comments);
		gets_s(new_record.comments,MAXCOMMENT);
		printf("请打出您的分数用“*”表示（1-5分）：\n");
		//scanf("%s", new_record.star);
		gets_s(new_record.star,10);
		for (int i = 0; new_record.star[i] != '\0'; ++i) {
			new_record.size_star = i;
		}
		new_record.size_star += 1;
		// printf("%d\n",size_star);
		if (new_record.size_star >5)
		{
			printf("评级输入不规范，请重新输入用“*”表示（1-5分）");
			gets_s(new_record.star, 10);

		}
		//printf("当前时间=%s", ctime(&curtime));
		 
		//调用时间函数传入current_time中
		time_t rawtime;
		struct tm* info;
		// char buffer[80];

		time(&rawtime);

		
		strcpy(new_record.current_time, asctime(localtime(&rawtime)));
		new_record.current_time[24] = '\0';
		printf("%s\n", new_record.current_time);
		printf("是否保存该条书目(y/n):");
		//choice = getch();
		//getc(choice);
		scanf("%c", &choice);
		getchar();
		while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
		{
			choice = getch();
			fflush(stdin);
		}
		printf("%c", choice);
		if (choice == 'Y' || choice == 'y')
		{
			
			//fprintf(p1, "%s %s %s %s %s %f %d %d\n",
			//	newbook.number, newbook.name, newbook.author, newbook.press,
			//	newbook.category, newbook.price, newbook.quantity, newbook.time);
			//fclose(p1);
			FILE* fp = fopen(filename, "a");

			fwrite_note(new_record, fp);
			fclose(fp);

			printf("\n该条书目已添加到%s文件中!\n",filename);
			new_record.length++;
			printf("当前记录时间：%s\n", new_record.current_time);

		}
		else
		{
			printf("\n本条书目未保存!\n");
		}
		printf("\n\n是否继续添加书目(y/n):");
		choice = getch();
		while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
		{
			printf("输入错误！请重新输入：");
			choice = getch();

		}

		printf("%c", choice);
		printf("\n");
		if (choice == 'Y' || choice == 'y' )
			continue;
		else
			break;

	}

	// fclose(fp);
}

/*
*	传入指向信息的指针和文件指针，然后将信息写入文件中
*/
void
fwrite_note(note new_record,FILE*fp)
{
	//依次写入
	fprintf(fp, "%s %s %s %s %s %d\n", new_record.title, new_record.author, new_record.comments,
		new_record.star,new_record.current_time, new_record.size_star);
							   //new_record->current_time);

	//错误处理
	if (fp == NULL) {
		printf("未知错误！");
	}
	//fclose(fp);
}


//显示所有信息
void
show_all_info()
{
	system("cls");
	note* book_log;
	book_log = read_from_file();
	int length = book_log[0].length;
	//输出信息
	printf("|---------------------------------图书信息----------------------------------------------------\n");
	printf("|书名		 作者		评分		时间			短评					   \n");
	printf("|                                                                          \n");
	int i = 0;
	while (i < length)
	{

		printf("|%-16s%-12s%-12s%-20s%\t%s\n", (book_log + i)->title, (book_log + i)->author, 
			(book_log + i)->star,(book_log+i)->current_time, (book_log + i)->comments);
		//printf("|%-100s%-|\n", (book_log + i)->comments);
		i++;
	}
	system("pause");

}

//动态获取用户文件名，规则是【用户名+ _note.log后缀】
const char* get_filename()
{
	extern char current_account[8];
	//等下修改
	//strcpy(current_account, "111111");
	char *filename = (char*)malloc(sizeof(char));
	//char filename[50];
	strcpy(filename, current_account);
	strcat(filename, "_note.log");
	return filename;
}

//
//从文件中读取
//根据get_filename提供的文件名，动态读取数据，然后返回一个指向文件的指针

note*
read_from_file()
{
	char current_account[8];
	//等下修改
	strcpy(current_account, "111111");
	//char *filename = (char*)malloc(sizeof(char));
	char filename[50];
	strcpy(filename, current_account);
	strcat(filename, "_note.log");

	/*char filename[50];
	strcpy(filename ,get_filename());*/
	FILE* fp = fopen(filename, "r");

	note book_log[MAX_BOOK_LOG];

	//book_log[0].length = 0;
	int length = 0;
	while (!feof(fp))
	{
		fscanf(fp, "%s %s %s %s", book_log[length].title,
			book_log[length].author,
			book_log[length].comments,
			book_log[length].star
			//book_log[book_log[0].length].current_time	
		);
		fgets(book_log[length].current_time, 26, fp);
		//fgetc(book_log[book_log[0].length].size_star)
		fscanf(fp, "%d\n", &book_log[length].size_star);
		length++;
	}
	fclose(fp);
	for (int i = 0; i < length; ++i)
		book_log[i].length = length;
	return book_log;
}
//升序
void
nondecreasing_sort() 
{
	getchar();

	note *book_log;
	book_log = read_from_file();
	//插入排序
	note key;
	for (int j = 1; j < book_log[0].length; ++j) {
		int i = j - 1;
		key = book_log[j];
		while (book_log[i].size_star > key.size_star && i >= 0)
		{
			*(book_log+i+1) = *(book_log+i);
			i--;
		}
		book_log[i+1]= key;
	}
	printf("\t\t\t\t\t已按您的喜好由低到高排列：\n\n");
	print_out_sort(book_log, book_log[0].length);
	//system("pause");
}

//降序
void
nonincreasing_sort()
{
	getchar();
	note* book_log;
	book_log = read_from_file();
	//插入排序
	note key;
	for (int j = 1; j < book_log[0].length; ++j) {
		int i = j - 1;
		key = book_log[j];
		while (book_log[i].size_star < key.size_star && i >= 0)
		{
			*(book_log + i + 1) = *(book_log + i);
			i--;
		}
		book_log[i + 1] = key;
	}
	printf("\t\t\t\t\t已按您的喜好由高到低排列：\n\n");
	//调用输出函数
	print_out_sort(book_log, book_log[0].length);
	//system("pause");

}

void
nonincreasing_author_sort()
{
	getchar();
	Cache* book_count;
	book_count = statistics_author();
	Cache* cache = (Cache*)malloc(sizeof(Cache) * 100);
	Cache* p = book_count->next;
	int i = 0;
	int len;

	//将链表转换为数组
	for(i=0;p!=NULL;++i)
	{
		cache[i].count = p->count;
		strcpy(cache[i].title,p->title);
		//printf("\t\t\t\t\t\t%s %d\n", p->title, p->count);
		p = p->next;
		len = i;
	}
	//插入排序
	Cache key;
	for (int j = 1; j < len; ++j) {
		int i = j - 1;
		key = cache[j];
		while (cache[i].count < key.count&& i >= 0)
		{
			*(cache + i + 1) = *(cache + i);
			i--;
		}
		cache[i + 1] = key;
	}
	printf("\t\t\t\t\t您的作者喜爱程度如下：\n\n");
	int j;
	for (j = 0; j < len; ++j)
	{
		printf("\t\t\t\t\t%s %d\n", cache[j].title, cache[j].count);
	}
	system("pause");
	//调用输出函数
	//print_out_sort(book_log, book_log[0].length);
	//system("pause");

}
void
print_out_sort(note *book_log,int length)
{
	system("cls");

	//输出信息
	printf("\t\t\t\t\t|----------------图书信息----------------|\n");
	printf("\t\t\t\t\t|书名            作者           评分     |\n");
	printf("\t\t\t\t\t|                                        |\n");
	int i = 0;
	while (i <length)
	{
		
		printf("\t\t\t\t\t|%-16s%-16s%-8s%|\n", (book_log+i)->title, (book_log + i)->author, (book_log + i)->star);
		i++;
	}
	system("pause");
}
/*
void
appendix_comments()
{
	note* book_log;
	book_log = read_from_file();
	char filename[50];
	//int flag = 0;
	while (1)
	{


		printf("请输入您想要添加评论的书籍名：\n");

		char book_title[30];
		char add_comments[MAXCOMMENT] = {'\0'};
		scanf("%s", book_title);
		getchar();
		//1、遍历找到书籍
		int length = book_log[0].length;
		for (int i = 0; i < length; ++i)
		{
			if (strcmp(book_log[i].title,book_title)==0) {
				system("cls");
				printf("\t\t\t\t\t已经为您找到该书籍！\n");
				//打印该书籍信息
				print_out_sort(book_log + i, 1);
				//2、添加评论信息
				printf("请输入新的评论（建议在新的评论前加上“#”等你喜欢的标记以作区分）：\n");
				scanf("%s", add_comments);
				//gets_s(add_comments,50);
				//char div[10] = "||";
				//strcat(div, add_comments);
				strcat(book_log[i].comments,add_comments);
				//3、将所有信息重新写入文件中
				strcpy(filename, get_filename());
				FILE* fp = fopen(filename, "w");
				
				for (int i = 0; i < length; ++i)
				{
					fprintf(fp, "%s %s %s %s %s %d", book_log[i].title, book_log[i].author,
						book_log[i].comments, book_log[i].star,book_log[i].current_time, book_log[i].size_star);
				}
				
				printf("\n该条评论已添加到%s文件中!\n", filename);
				break;
			}
		}
		printf("您还想继续添加评论吗？(n/y)");
		char choice =getchar();
		while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
			choice = getch();

		printf("%c", choice);
		printf("\n");
		if (choice == 'Y' || choice == 'y' )
			continue;
		else
			return;
		
		
	}
}
*/
Cache*
statistics_author()
{
	//getchar();
	note* book_log;
	book_log = read_from_file();

	int i,j;
	int length = book_log->length;
	//作者和对应的统计
	Cache* book_count = (Cache*)malloc(sizeof(Cache));
	book_count->next = NULL;
	//已经统计过的作者对象
	Searched* head = (Searched*)malloc(sizeof(Searched));
	head->next = NULL;
	for (i = 0; i < length; ++i)
	{
		int count = 0;
		char item[50];

		strcpy(item,book_log[i].author);
		//char **searched=
		if (!determine(head, item)) {
			insert_searched(head, item);
			for (j = 0; j < length; ++j)
			{
				if (strcmp(item, book_log[j].author)==0)
				{
					count++;
				}
			}
			/*book_count[i].count = count;
			strcmp(book_count[i].title, item);*/
			//将作者名和统计数放进链表里面
			Cache* p = (Cache*)malloc(sizeof(Cache));
			p->count = count;
			strcpy(p->title, item); 
			p->next = book_count->next;
			book_count->next = p;

		}
		
	}
	return book_count;

}
void make_hashtable()
{
	int addr; // 哈希地址
	HashTable hash;

	// 初始化哈希表
	initHashTable(&hash);

	// 插入关键字到哈希表
	/*for (int i = 0; i < m; i++)
		insertHash(&hash, arr[i]);*/
	Cache* book_count = statistics_author();
	Cache* p = book_count->next;
	while (p)
	{
		insertHash(&hash, p->title, p->count);
		p = p->next;
	}
	/*char* key[] = { "红楼梦" ,"三国演义","水浒传" };
	for (int i = 0; i < 3; ++i) {
		insertHash(&hash, key[i], 5);
	}*/
	while (1)
	{
		//再次循环输入
		system("cls");
		printf("\t\t\t\t\t请输入您喜欢的作家：\n");
		char* author[30];
		scanf("%s", author);
		int result = searchHash(hash, author, &addr);
		if (result)
		{
			printf("\t\t\t\t\t您查找 %s 的总共计数为：%d\n\n", author, hash.elem[addr].count);
			printf("\t\t\t\t\t看的出来您很喜欢这位作家哟！\n");
			
		}
		else
		{
			printf("\t\t\t\t\t\t查找 %s 失败。\n\n", author);
			printf("\t\t\t\t\t\t可能您未收录该作者的书籍\n");
		}
		getchar();
		printf("想要继续查找吗？y/n\n");

		char yOrNo;
		//yOrNo = getchar();
		scanf("%c", &yOrNo);
		//getchar();
		if (yOrNo == 'n')
			return;
		else
		{
			continue;
		}
	}
		free_cacheList(book_count);
}

//打印每个作者的出现次数
void 
print_author_times() {
	Cache* book_count = statistics_author();
	Cache* p = book_count->next;
	while (p)
	{
		printf("\t\t\t\t\t\t%s %d\n", p->title, p->count);
		p = p->next;
	}
}

//判断队列里面是否有已经统计过该作者了，如果统计过则跳过
//如果为真则已经在队列中
bool determine(Searched* head, char* author) {
	Searched* p = head;
	//第一次判断需要特别提出来
	if (p ->next== NULL) {
		return false;
	}
	_Bool searched = false;
	while (p->next!=NULL)
	{
		if (strcmp(p->name, author)==0) 
		{
			searched = true;
		}
		p = p->next;
	}
	return searched;
}

//如果还没有统计过，则将作者添加进入链表
Status insert_searched(Searched*head,char*author)
{
	Searched* p = (Searched*)malloc(sizeof(Searched));
	p->next = NULL;
	strcpy(p->name, author);
	p->next = head->next;
	head->next = p;
	return OK;
}

void
long_comments()
{
	getchar();
	note* book_log;
	book_log = read_from_file();
	
	while (1)
	{

		printf("\t\t\t\t\t\t请输入您想要添加长评的书籍名：\n\n");
		printf("\t\t\t\t\t\t输入[quit]退出\n\n");
		//动态规划
		char book_name[50]= { 0 };
		scanf("%s", book_name);
		char comepare_name[] = "quit";
		if (strcmp(book_name, comepare_name)==0)
		{
			return;
		}
		int i;
		int length = book_log->length;
		for (i = 0; i < length; ++i)
		{
			if (strcmp(book_name, book_log[i].title) == 0)
			{
				break;
			}
			else
			{
				printf("\t\t\t\t\t\t抱歉,此书不在文件中，请先将书籍添加到文件中\n");
				return;
			}
		}
		strcat(book_name, "_comment.txt");
		FILE* fp = fopen(book_name, "a");
		if (fp == NULL)
		{
			printf("未知错误，请重新打开程序运行！\n");
			exit(-1);
		}
		printf("请开始输入你的长评吧！\n");

		char long_comments[MAX_LONG_COMMENTS];
		getchar();

		char c;
		fputc('\n', fp);
		while ((c=getchar())!=EOF)
		{
			fputc(c,fp);
		}
		//gets_s(long_comments, MAX_LONG_COMMENTS);
		//fputs(long_comments, fp);

		fputc('\n', fp);
		time_t rawtime;
		struct tm* info;
		char current_time[50] = { 0 };
		// char buffer[80];
		time(&rawtime);
		strcpy(current_time, asctime(localtime(&rawtime)));
		current_time[24] = '\0';
		fputs(current_time, fp);
		printf("\t\t\t\t\t\t长评论成功添加到文件中！\n");
		printf("\t\t\t\t\t\t创建时间：%s\n", current_time);
		
		fclose(fp);
	}
}

//用户标记想读书籍和对应作者
void
to_read()
{
	char current_account[8];
	strcpy(current_account, "111111");
	char* filename = (char*)malloc(sizeof(char));
	strcpy(filename, current_account);
	strcat(filename, "_toRead.log");
	printf("\t\t\t\t请添加您想要读的书籍！\n");
	while (1)
	{
		system("cls");
		printf("\t\t\t\t请依次输入【书名】【作者名】\n");

		char choice;

		note new_record;
		/*extern int length;
		length = 0;*/
		new_record.length = 0;

		printf("请输入书名：\n");
		gets_s(new_record.title, 20);
		printf("请输入作者名：\n");
		gets_s(new_record.author, 20);
	
		//printf("当前时间=%s", ctime(&curtime));

		//调用时间函数传入current_time中
		time_t rawtime;
		struct tm* info;
		// char buffer[80];

		time(&rawtime);


		strcpy(new_record.current_time, asctime(localtime(&rawtime)));
		new_record.current_time[24] = '\0';
		printf("%s\n", new_record.current_time);
		printf("是否保存该条书目(y/n):");
		//choice = getch();
		//getc(choice);
		scanf("%c", &choice);
		getchar();
		while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
		{
			choice = getch();
			fflush(stdin);
		}
		printf("%c", choice);
		if (choice == 'Y' || choice == 'y')
		{

			//fprintf(p1, "%s %s %s %s %s %f %d %d\n",
			//	newbook.number, newbook.name, newbook.author, newbook.press,
			//	newbook.category, newbook.price, newbook.quantity, newbook.time);
			//fclose(p1);
			FILE* fp = fopen(filename, "a");

			//fwrite_note(new_record, fp);
			fprintf(fp, "%s %s %s\n", new_record.title, new_record.author,new_record.current_time);
			//new_record->current_time);

			//异常处理
			if (fp == NULL) {
				printf("未知错误！");
			}
			fclose(fp);

			printf("\n该条书目已添加到%s文件中!\n", filename);
			new_record.length++;
			printf("当前记录时间：%s\n", new_record.current_time);

		}
		else
		{
			printf("\n本条书目未保存!\n");
		}
		printf("\n\n是否继续添加书目(y/n):");
		choice = getch();
		while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
		{
			printf("输入错误！请重新输入：");
			choice = getch();

		}

		printf("%c", choice);
		printf("\n");
		if (choice == 'Y' || choice == 'y')
			continue;
		else
			break;

	}

	// fclose(fp);
}

//检查想读和已读名单，如果用户已经读了将读清单，那么更新清单
void
update_log()
{

}


/*	输入作者或者书籍名，查找特带的读书记录
*/
void search_author() 
{
	//getchar();
	note* book_log;
	book_log = read_from_file();
	//获取总长度
	const int length = book_log[0].length;
	char book_name[50];
	while (1)
	{
	
		system("cls");
		printf("\t\t\t\t\t\t请输入您要查找的书籍名：\n");
		gets_s(book_name, 50);
		//if(strcmp(book_name,))
		int i;
		_Bool match = false;

		int flag = 0;
		for (i = 0; i < length; ++i) {
			if (strcmp(book_name, book_log[i].title) == 0)
			{
				match = true;
				flag = i;
				break;
			}
		}
		if (!match)
		{

			int count;
			BookShelf* book_match = (BookShelf*)malloc(sizeof(BookShelf) * length);
			//BookShelf book_match[length];
			for (i = 0; i < length; ++i) {
				count = longest_common_sub(book_name, book_log[i].title);
				(book_match + i)->count = count;

				strcpy((book_match + i)->title, book_log[i].title);

			}
			BookShelf key;
			for (int j = 1; j < length; ++j) {
				int i = j - 1;
				key = book_match[j];
				while (book_match[i].count < key.count && i >= 0)
				{
					*(book_match + i + 1) = *(book_match + i);
					i--;
				}
				book_match[i + 1] = key;
			}

			printf("没有找到您想要查找的书籍名，您是否想要查找：\n");
			for (i = 0; i < 3; ++i) {
				printf("[%s] ", book_match[i].title);
			}
			printf("\n");
			free(book_match);
			printf("想要继续查找吗？y/n\n");
			//getchar();

			char yOrNo = '\0';
			//yOrNo = getchar();
			scanf("%c", &yOrNo);
			getchar();
			if (yOrNo == 'n')
				return;
			else
			{
				continue;
			}
			
		}
		else
		{
			printf("\t\t\t|-----------------------图书信息------------------------|\n");
			printf("\t\t\t|书名            作者           评分		完成时间|\n");
			printf("\t\t\t													\n");
			printf("\t\t\t|%-16s%-16s%-8s%-16s%\n", (book_log + flag)->title,
				(book_log + flag)->author, (book_log + flag)->star,(book_log+flag)->current_time);
			printf("想要继续查找吗？y/n\n");
			//getchar();
			
			char yOrNo='\0';
			//yOrNo = getchar();
			scanf("%c",&yOrNo);
			getchar();
			if (yOrNo == 'n')
				return;
			else
			{
				continue;
			}
		}
	}
}

//动态规划算法算出最大的书籍对应
//智能纠错
int 
longest_common_sub(char *wordA,char *wordB) {
	int aSize = strlen(wordA);
	int bSize = strlen(wordB);
	int** table = (int**)malloc(aSize * sizeof(int*));
	int l;
	for (l = 0; l < aSize; ++l) {
		table[l] = (int*)malloc(sizeof(int) * bSize);
	}
	int max1 = 0;
	int i, j;
	for (i = 0; i < aSize; ++i)
		for (j = 0; j < bSize; ++j) {

			if (wordA[i] == wordB[j])
				if (i > 0 && j > 0) {
					table[i][j] = table[i - 1][j - 1] + 1;
					//					ma1x=table[i][j];
				}
				else
					table[i][j] = 1;
			else
				if (i > 0 && j > 0)
					table[i][j] = max(table[i - 1][j], table[i][j - 1]);
				else if (i == 0 && j > 0)
					table[i][j] = table[i][j - 1];
				else if (i > 0 && j == 0)
					table[i][j] = table[i - 1][j];
				else
					table[i][j] = 0;
			max1 = table[i][j];
		}
	/*for (i = 0; i < aSize; ++i) {
		printf("[ ");
		for (j = 0; j < bSize; ++j)
			printf("%d ", table[i][j]);
		printf("] \n");
	}*/
	//printf("%d\n", max1 / 2);
	return max1 / 2;
}
// 初始化哈希表
Status initHashTable(HashTable* hash)
{
	int i;

	m = HASHSIZE;
	hash->count = m;
	hash->elem = (Cache*)malloc(m * sizeof(Cache));
	for (i = 0; i < m; i++)
		hash->elem[i].count = NULLKEY;

	return TRUE;
}

// 构造哈希函数
//int hashFun(int key)
//{
//	return key % 161; // 构造方法为除留余数法
//}
int hashFun(char* key)
{
	int b = (unsigned char)key[1];
	return b % 161; // 构造方法为除留余数法
}

// 插入关键字进哈希表
void insertHash(HashTable* hash, char* key, int count)
{
	int addr = hashFun(key); // 求哈希地址
	//while (hash->elem[addr] != NULLKEY) // 如果不为空，则冲突
	//while (hash->*(elem+addr).count != NULLKEY) // 如果不为空，则冲突
	while (hash->elem[addr].count != NULLKEY)
	{
		addr = (addr + 1) % 161; // 开放定址法的线性探测
	}
	strcpy(hash->elem[addr].title, key); // 直到有空位后插入关键字
	hash->elem[addr].count = count;
}

// 哈希表查找关键字

Status searchHash(HashTable hash, char* key, int* addr)
{
	*addr = hashFun(key); // 求哈希地址，如果后面的hash.elem[*addr] == key，则说明查找成功，直接返回
	while (strcmp(hash.elem[*addr].title, key) != 0) // 否则，使用开放定址法继续查找
	{
		*addr = (*addr + 1) % 161; // 开放定址法的线性探测
		// 如果 查找到NULLKEY | 循环回到原点，则说明关键字不存在，返回FALSE
		if (hash.elem[*addr].count == NULLKEY || *addr == hashFun(key))
			return FALSE;
	}

	return TRUE;
}

//清理动态内存
void
free_cacheList(Cache* List)
{
	Cache* p = List;
	while (p != NULL)
	{
		List = List->next;
		free(p);
		p = List;
	}
}
