#include<stdio.h>
#include<time.h>
#include<string.h>
#include"book_note.h"
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXCOMMENT 100
int m = 0; // ��ϣ�����ȫ�ֱ���


//����ʼ�ģ�����д����������������������һ���ֵĶ��������˵��Ǽ���֣�
			//��ʱ�亯���Զ�������ʱ���Լ�


void 
add_book_record()
{
	getchar();
	//���ɸ����ļ���
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
		printf("\t\t\t\t�ѳɹ�Ϊ���Զ����������¼�ļ�\n");
		printf("\t\t\t\t--------------------------------------\n");
	}*/

	/*else
	{
		fp = fopen(filename, "a");

	}*/
	//getchar();
	printf("\t\t\t\t��ӭ��������ʼ����ϵͳ��\n");
	while (1)
	{	
		system("cls");
		printf("\t\t\t\t���������롾�����������������������������֡�\n");

		//��ȡʱ��
	/*	time_t curtime;
		time(&curtime);*/
		char choice;

		//note* new_record = (note*)malloc(sizeof(note));
		note new_record;
		/*extern int length;
		length = 0;*/
		new_record.length = 0;

		printf("������������\n");
		//scanf("%s",new_record.title);
		gets_s(new_record.title,20);
		printf("��������������\n");
		//scanf("%s", new_record.author);
		gets_s(new_record.author,20);
		printf("�����벻����һ���ֵļ�����\n");
		//scanf("%s", new_record.comments);
		gets_s(new_record.comments,MAXCOMMENT);
		printf("�������ķ����á�*����ʾ��1-5�֣���\n");
		//scanf("%s", new_record.star);
		gets_s(new_record.star,10);
		for (int i = 0; new_record.star[i] != '\0'; ++i) {
			new_record.size_star = i;
		}
		new_record.size_star += 1;
		// printf("%d\n",size_star);
		if (new_record.size_star >5)
		{
			printf("�������벻�淶�������������á�*����ʾ��1-5�֣�");
			gets_s(new_record.star, 10);

		}
		//printf("��ǰʱ��=%s", ctime(&curtime));
		 
		//����ʱ�亯������current_time��
		time_t rawtime;
		struct tm* info;
		// char buffer[80];

		time(&rawtime);

		
		strcpy(new_record.current_time, asctime(localtime(&rawtime)));
		new_record.current_time[24] = '\0';
		printf("%s\n", new_record.current_time);
		printf("�Ƿ񱣴������Ŀ(y/n):");
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

			printf("\n������Ŀ����ӵ�%s�ļ���!\n",filename);
			new_record.length++;
			printf("��ǰ��¼ʱ�䣺%s\n", new_record.current_time);

		}
		else
		{
			printf("\n������Ŀδ����!\n");
		}
		printf("\n\n�Ƿ���������Ŀ(y/n):");
		choice = getch();
		while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
		{
			printf("����������������룺");
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
*	����ָ����Ϣ��ָ����ļ�ָ�룬Ȼ����Ϣд���ļ���
*/
void
fwrite_note(note new_record,FILE*fp)
{
	//����д��
	fprintf(fp, "%s %s %s %s %s %d\n", new_record.title, new_record.author, new_record.comments,
		new_record.star,new_record.current_time, new_record.size_star);
							   //new_record->current_time);

	//������
	if (fp == NULL) {
		printf("δ֪����");
	}
	//fclose(fp);
}


//��ʾ������Ϣ
void
show_all_info()
{
	system("cls");
	note* book_log;
	book_log = read_from_file();
	int length = book_log[0].length;
	//�����Ϣ
	printf("|---------------------------------ͼ����Ϣ----------------------------------------------------\n");
	printf("|����		 ����		����		ʱ��			����					   \n");
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

//��̬��ȡ�û��ļ����������ǡ��û���+ _note.log��׺��
const char* get_filename()
{
	extern char current_account[8];
	//�����޸�
	//strcpy(current_account, "111111");
	char *filename = (char*)malloc(sizeof(char));
	//char filename[50];
	strcpy(filename, current_account);
	strcat(filename, "_note.log");
	return filename;
}

//
//���ļ��ж�ȡ
//����get_filename�ṩ���ļ�������̬��ȡ���ݣ�Ȼ�󷵻�һ��ָ���ļ���ָ��

note*
read_from_file()
{
	char current_account[8];
	//�����޸�
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
//����
void
nondecreasing_sort() 
{
	getchar();

	note *book_log;
	book_log = read_from_file();
	//��������
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
	printf("\t\t\t\t\t�Ѱ�����ϲ���ɵ͵������У�\n\n");
	print_out_sort(book_log, book_log[0].length);
	//system("pause");
}

//����
void
nonincreasing_sort()
{
	getchar();
	note* book_log;
	book_log = read_from_file();
	//��������
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
	printf("\t\t\t\t\t�Ѱ�����ϲ���ɸߵ������У�\n\n");
	//�����������
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

	//������ת��Ϊ����
	for(i=0;p!=NULL;++i)
	{
		cache[i].count = p->count;
		strcpy(cache[i].title,p->title);
		//printf("\t\t\t\t\t\t%s %d\n", p->title, p->count);
		p = p->next;
		len = i;
	}
	//��������
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
	printf("\t\t\t\t\t��������ϲ���̶����£�\n\n");
	int j;
	for (j = 0; j < len; ++j)
	{
		printf("\t\t\t\t\t%s %d\n", cache[j].title, cache[j].count);
	}
	system("pause");
	//�����������
	//print_out_sort(book_log, book_log[0].length);
	//system("pause");

}
void
print_out_sort(note *book_log,int length)
{
	system("cls");

	//�����Ϣ
	printf("\t\t\t\t\t|----------------ͼ����Ϣ----------------|\n");
	printf("\t\t\t\t\t|����            ����           ����     |\n");
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


		printf("����������Ҫ������۵��鼮����\n");

		char book_title[30];
		char add_comments[MAXCOMMENT] = {'\0'};
		scanf("%s", book_title);
		getchar();
		//1�������ҵ��鼮
		int length = book_log[0].length;
		for (int i = 0; i < length; ++i)
		{
			if (strcmp(book_log[i].title,book_title)==0) {
				system("cls");
				printf("\t\t\t\t\t�Ѿ�Ϊ���ҵ����鼮��\n");
				//��ӡ���鼮��Ϣ
				print_out_sort(book_log + i, 1);
				//2�����������Ϣ
				printf("�������µ����ۣ��������µ�����ǰ���ϡ�#������ϲ���ı���������֣���\n");
				scanf("%s", add_comments);
				//gets_s(add_comments,50);
				//char div[10] = "||";
				//strcat(div, add_comments);
				strcat(book_log[i].comments,add_comments);
				//3����������Ϣ����д���ļ���
				strcpy(filename, get_filename());
				FILE* fp = fopen(filename, "w");
				
				for (int i = 0; i < length; ++i)
				{
					fprintf(fp, "%s %s %s %s %s %d", book_log[i].title, book_log[i].author,
						book_log[i].comments, book_log[i].star,book_log[i].current_time, book_log[i].size_star);
				}
				
				printf("\n������������ӵ�%s�ļ���!\n", filename);
				break;
			}
		}
		printf("������������������(n/y)");
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
	//���ߺͶ�Ӧ��ͳ��
	Cache* book_count = (Cache*)malloc(sizeof(Cache));
	book_count->next = NULL;
	//�Ѿ�ͳ�ƹ������߶���
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
			//����������ͳ�����Ž���������
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
	int addr; // ��ϣ��ַ
	HashTable hash;

	// ��ʼ����ϣ��
	initHashTable(&hash);

	// ����ؼ��ֵ���ϣ��
	/*for (int i = 0; i < m; i++)
		insertHash(&hash, arr[i]);*/
	Cache* book_count = statistics_author();
	Cache* p = book_count->next;
	while (p)
	{
		insertHash(&hash, p->title, p->count);
		p = p->next;
	}
	/*char* key[] = { "��¥��" ,"��������","ˮ䰴�" };
	for (int i = 0; i < 3; ++i) {
		insertHash(&hash, key[i], 5);
	}*/
	while (1)
	{
		//�ٴ�ѭ������
		system("cls");
		printf("\t\t\t\t\t��������ϲ�������ң�\n");
		char* author[30];
		scanf("%s", author);
		int result = searchHash(hash, author, &addr);
		if (result)
		{
			printf("\t\t\t\t\t������ %s ���ܹ�����Ϊ��%d\n\n", author, hash.elem[addr].count);
			printf("\t\t\t\t\t���ĳ�������ϲ����λ����Ӵ��\n");
			
		}
		else
		{
			printf("\t\t\t\t\t\t���� %s ʧ�ܡ�\n\n", author);
			printf("\t\t\t\t\t\t������δ��¼�����ߵ��鼮\n");
		}
		getchar();
		printf("��Ҫ����������y/n\n");

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

//��ӡÿ�����ߵĳ��ִ���
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

//�ж϶��������Ƿ����Ѿ�ͳ�ƹ��������ˣ����ͳ�ƹ�������
//���Ϊ�����Ѿ��ڶ�����
bool determine(Searched* head, char* author) {
	Searched* p = head;
	//��һ���ж���Ҫ�ر������
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

//�����û��ͳ�ƹ�����������ӽ�������
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

		printf("\t\t\t\t\t\t����������Ҫ��ӳ������鼮����\n\n");
		printf("\t\t\t\t\t\t����[quit]�˳�\n\n");
		//��̬�滮
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
				printf("\t\t\t\t\t\t��Ǹ,���鲻���ļ��У����Ƚ��鼮��ӵ��ļ���\n");
				return;
			}
		}
		strcat(book_name, "_comment.txt");
		FILE* fp = fopen(book_name, "a");
		if (fp == NULL)
		{
			printf("δ֪���������´򿪳������У�\n");
			exit(-1);
		}
		printf("�뿪ʼ������ĳ����ɣ�\n");

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
		printf("\t\t\t\t\t\t�����۳ɹ���ӵ��ļ��У�\n");
		printf("\t\t\t\t\t\t����ʱ�䣺%s\n", current_time);
		
		fclose(fp);
	}
}

//�û��������鼮�Ͷ�Ӧ����
void
to_read()
{
	char current_account[8];
	strcpy(current_account, "111111");
	char* filename = (char*)malloc(sizeof(char));
	strcpy(filename, current_account);
	strcat(filename, "_toRead.log");
	printf("\t\t\t\t���������Ҫ�����鼮��\n");
	while (1)
	{
		system("cls");
		printf("\t\t\t\t���������롾����������������\n");

		char choice;

		note new_record;
		/*extern int length;
		length = 0;*/
		new_record.length = 0;

		printf("������������\n");
		gets_s(new_record.title, 20);
		printf("��������������\n");
		gets_s(new_record.author, 20);
	
		//printf("��ǰʱ��=%s", ctime(&curtime));

		//����ʱ�亯������current_time��
		time_t rawtime;
		struct tm* info;
		// char buffer[80];

		time(&rawtime);


		strcpy(new_record.current_time, asctime(localtime(&rawtime)));
		new_record.current_time[24] = '\0';
		printf("%s\n", new_record.current_time);
		printf("�Ƿ񱣴������Ŀ(y/n):");
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

			//�쳣����
			if (fp == NULL) {
				printf("δ֪����");
			}
			fclose(fp);

			printf("\n������Ŀ����ӵ�%s�ļ���!\n", filename);
			new_record.length++;
			printf("��ǰ��¼ʱ�䣺%s\n", new_record.current_time);

		}
		else
		{
			printf("\n������Ŀδ����!\n");
		}
		printf("\n\n�Ƿ���������Ŀ(y/n):");
		choice = getch();
		while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
		{
			printf("����������������룺");
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

//���������Ѷ�����������û��Ѿ����˽����嵥����ô�����嵥
void
update_log()
{

}


/*	�������߻����鼮���������ش��Ķ����¼
*/
void search_author() 
{
	//getchar();
	note* book_log;
	book_log = read_from_file();
	//��ȡ�ܳ���
	const int length = book_log[0].length;
	char book_name[50];
	while (1)
	{
	
		system("cls");
		printf("\t\t\t\t\t\t��������Ҫ���ҵ��鼮����\n");
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

			printf("û���ҵ�����Ҫ���ҵ��鼮�������Ƿ���Ҫ���ң�\n");
			for (i = 0; i < 3; ++i) {
				printf("[%s] ", book_match[i].title);
			}
			printf("\n");
			free(book_match);
			printf("��Ҫ����������y/n\n");
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
			printf("\t\t\t|-----------------------ͼ����Ϣ------------------------|\n");
			printf("\t\t\t|����            ����           ����		���ʱ��|\n");
			printf("\t\t\t													\n");
			printf("\t\t\t|%-16s%-16s%-8s%-16s%\n", (book_log + flag)->title,
				(book_log + flag)->author, (book_log + flag)->star,(book_log+flag)->current_time);
			printf("��Ҫ����������y/n\n");
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

//��̬�滮�㷨��������鼮��Ӧ
//���ܾ���
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
// ��ʼ����ϣ��
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

// �����ϣ����
//int hashFun(int key)
//{
//	return key % 161; // ���췽��Ϊ����������
//}
int hashFun(char* key)
{
	int b = (unsigned char)key[1];
	return b % 161; // ���췽��Ϊ����������
}

// ����ؼ��ֽ���ϣ��
void insertHash(HashTable* hash, char* key, int count)
{
	int addr = hashFun(key); // ���ϣ��ַ
	//while (hash->elem[addr] != NULLKEY) // �����Ϊ�գ����ͻ
	//while (hash->*(elem+addr).count != NULLKEY) // �����Ϊ�գ����ͻ
	while (hash->elem[addr].count != NULLKEY)
	{
		addr = (addr + 1) % 161; // ���Ŷ�ַ��������̽��
	}
	strcpy(hash->elem[addr].title, key); // ֱ���п�λ�����ؼ���
	hash->elem[addr].count = count;
}

// ��ϣ����ҹؼ���

Status searchHash(HashTable hash, char* key, int* addr)
{
	*addr = hashFun(key); // ���ϣ��ַ����������hash.elem[*addr] == key����˵�����ҳɹ���ֱ�ӷ���
	while (strcmp(hash.elem[*addr].title, key) != 0) // ����ʹ�ÿ��Ŷ�ַ����������
	{
		*addr = (*addr + 1) % 161; // ���Ŷ�ַ��������̽��
		// ��� ���ҵ�NULLKEY | ѭ���ص�ԭ�㣬��˵���ؼ��ֲ����ڣ�����FALSE
		if (hash.elem[*addr].count == NULLKEY || *addr == hashFun(key))
			return FALSE;
	}

	return TRUE;
}

//����̬�ڴ�
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
