#include<stdio.h>
#include<time.h>
#include"library.h"
#include <conio.h>
#include<string.h>

/*
*   @name       add_book
*   @param      newbook     新建书籍
*   @param      flag        用来判断退出还是继续录入
*   @version    1.0     
*   该模块用来用来添加图书，录入信息并把图书信息写道"library.log"的文件中
*/
void 
add_book() /*输入新进的图书信息*/
{
    char choice;
    FILE* p1;
    library_book newbook;
    int flag;
    system("cls");
    while (1)
    {
        flag = 0;
        fflush(stdin);
        printf("请输入图书编号:");
        //gets(newbook.number);
        scanf("%s",newbook.number);

        if (check_repeat_book(newbook.number))
        {
            printf("该图书编号已被使用！");
            printf("\n按任意键重新输入\n\n");
            getch();
            flag = 1;
        }
        else {
            //fflush(stdin);
            printf("请输入书名:");
            //gets(newbook.name);
            scanf("%s",newbook.name);

            //fflush(stdin);
            printf("请输入作者:");
            //gets(newbook.author);
            scanf("%s", newbook.author);


            printf("请输入出版社:");
            scanf("%s", newbook.press);
            //gets(newbook.press);

            printf("请输入类别(文学/科学/理学/工学/等):");
            scanf("%s", newbook.category);
            //gets(newbook.category);

            printf("请输入价格:");
            scanf("%f", &newbook.price);

            printf("请输入馆藏量:");
            scanf("%d", &newbook.quantity);

            printf("请输入借阅次数(新书输入0):");
            scanf("%d", &newbook.time);
            fflush(stdin);
            printf("是否保存该条书目(y/n):");
            choice = getch();
            while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
                choice = getch();
            printf("%c", choice);
            if (choice == 'Y' || choice == 'y')
            {
                p1 = fopen("library.log", "a");
                fprintf(p1, "%s %s %s %s %s %f %d %d\n",
                    newbook.number, newbook.name, newbook.author, newbook.press,
                    newbook.category, newbook.price, newbook.quantity, newbook.time);
                fclose(p1);
                printf("\n该条书目已添加到library.log文件中!\n");
            }
            else
            {
                printf("\n本条书目未保存!\n");
            }
            printf("\n\n是否继续添加书目(y/n):");
            choice = getch();
            while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
                choice = getch();

            printf("%c", choice);
            printf("\n");
            if (choice == 'Y' || choice == 'y' || flag == 1)
                continue;
            else
                break;
        }
        
    }
}

/*
*   @name       check_repeat_book
*   @param      bookinfo        读取书籍信息
*   @param      flag            用来判断退出还是继续录入
*   @version    1.0
*   用来判断是否有重复序号的书籍，如果有则返回1，如果没有返回0
*/
int 
check_repeat_book(char number[BOOK_NUMBER])
{
   
    library_book bookinfo[BOOK_INFO];
    int flag1 = 0, flag2 = 1, n, number_of_book;

    //char current_account[8]="111111";
    //extern char current_account[8];

    /*char library_filename[50];
    strcpy(library_filename, current_account);
    strcat(library_filename, "_library.log");*/

    FILE* fp = fopen("library.log", "r");
    number_of_book = 0;
    if (fp == NULL) {
        //文件不存在时就创建文件
        fp = fopen("library.log", "w");
        printf("\t\t\t文件不存在，已重新创建！\n");
        return NULL;
    }
    if (fp == NULL)
    {
        printf("\t\t\t未知错误！账户文件打开失败！\n");
        return NULL;
    }
    //如果文件没结束，则返回0
    while (!feof(fp))
    {
        fscanf(fp, "%s %s %s %s %s %f %d %d\n",
            bookinfo[number_of_book].number, bookinfo[number_of_book].name, bookinfo[number_of_book].author,
            bookinfo[number_of_book].press, bookinfo[number_of_book].category,
            &bookinfo[number_of_book].price, &bookinfo[number_of_book].quantity, &bookinfo[number_of_book].time);
        number_of_book++;
    }
    fclose(fp);

    for (n = 0; n < number_of_book; n++)
        if (strcmp(bookinfo[n].number, number) == 0)
        {
            flag1 = 1;
            break;
        }
    if (flag1)
    {
        return 1;
    }
    else {
        return 0;
    }
}

/*
*   @name       display_book()
*   @param      bookinfo        读取书籍信息
*   @param      fp              指向文件的指针
*   @param      current_account 全局变量，用来设置用户特有的文件名
*   @version    1.0
*   @function   用来输出图书馆中所有的书籍
*   
*/
void 
display_book()/*显示全部图书信息*/
{
    int n;
    library_book bookinfo[100];
    int number_of_book = 0;

    system("cls");
    fflush(stdin);
    //char library_filename[50];
    //extern char current_account[8];

    ////设计该用户特有文件名
    //strcpy(library_filename, current_account);
    //strcat(library_filename, "_library.log");
    FILE* fp = fopen("library.log", "r");

    if (fp == NULL) {
        //文件不存在时就创建文件
        fp = fopen("library.log", "w");
        printf("\t\t\t文件不存在，已重新创建！\n");
        return NULL;
    }
    if (fp == NULL)
    {
        printf("\t\t\t未知错误！账户文件打开失败！\n");
        return NULL;
    }

    while (!feof(fp))
    {
        fscanf(fp, "%s %s %s %s %s %f %d %d\n",
            bookinfo[number_of_book].number, bookinfo[number_of_book].name, bookinfo[number_of_book].author,
            bookinfo[number_of_book].press, bookinfo[number_of_book].category,
            &bookinfo[number_of_book].price, &bookinfo[number_of_book].quantity, &bookinfo[number_of_book].time);
        number_of_book++;
    }
    fclose(fp);

    printf("当前图书馆内有%d目书籍\n\n", number_of_book);

    if (bookinfo[0].quantity == 0)
    {
        printf("\n没有任何图书信息!\n\n");
    }
    else
    {
        n = 0;
        printf("|---------------------------------图书信息---------------------------------|\n");
        printf("|编号  书名        作者      出版社          类别    单价    馆藏量  借阅数|\n");
        printf("|                                                                          |\n");

        //输出书籍信息
        while (n < number_of_book)
        {
            printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f%-8d%-6d|\n", 
                bookinfo[n].number, bookinfo[n].name, bookinfo[n].author,
                bookinfo[n].press, bookinfo[n].category, bookinfo[n].price,
                bookinfo[n].quantity, bookinfo[n].time);
            n++;
        }
    }

    printf("\n\n按任意键返回上一级菜单!\n");
    getch();
}

/*  
*   @name       search_book
*   @param      *_compare       用来存放要查询的信息
*   @param      name_of_book    用来查询的书籍的序号
*   @param      flag            用来判断循环的条件
*   @function   根据书籍的情况搜索具体的书籍信息
*/
void 
search_book()/*根据图书名称显示图书的信息*/
{
    int flag = 1, flag1 = 1;
    char select;
    char name_compare[30] = "";/*name_compare用来存放要查询的书名*/
    char number_compare[30] = ""; /*number_compare用来存放要查询的书籍编号*/
    char author_compare[30] = "";/*author_compare用来存放要查询的作者姓名*/
    char search[30] = "";/*search是比对数组,将需要查找的数组读进比对数组*/
    char compare[30] = "";/*compare是比对数组,将书库中的数组读进比对数组*/
    int n = 0;
    char choice;
    library_book bookinfo[100];
    int number_of_book = 0;

    system("cls");
    fflush(stdin);
    FILE*  fp = fopen("library.log", "r");
    while (!feof(fp))
    {
        fscanf(fp, "%s %s %s %s %s %f %d %d\n",
            bookinfo[number_of_book].number, bookinfo[number_of_book].name, bookinfo[number_of_book].author,
            bookinfo[number_of_book].press, bookinfo[number_of_book].category,
            &bookinfo[number_of_book].price, &bookinfo[number_of_book].quantity, &bookinfo[number_of_book].time);
        number_of_book++;
    }
    fclose(fp);

    while (flag)
    {
        system("cls");
        while (flag1)
        {
            system("cls");
            fflush(stdin);
            getchar();

            printf("您想通过\n\n1.<-图书编号->\n\n2.<-书名->\n\n3.<-作者名->\n\n哪种方式查询图书:");

            //select = getch();
            scanf("%c",&select);
            
            printf("%c", select);
            printf("\n\n请您输入查找信息:");
            //循环输入
            switch (select)
            {
            case '1':
                //gets(number_compare); 
                scanf("%s",number_compare);
                strcpy(search, number_compare); 
                flag1 = 0; 
                break;
            case '2':
                //gets(name_compare); 
                scanf("%s", name_compare);

                strcpy(search, name_compare);
                flag1 = 0; 
                break;
            case '3':
                //gets(author_compare); 
                scanf("%s", author_compare);

                strcpy(search, author_compare); 
                flag1 = 0; 
                break;
            default:
                printf("\n不要输入菜单之外的数字~按任意键继续！");
                fflush(stdin);
                getch();
            }
        }

        flag1 = 1;
        if (bookinfo[0].quantity == 0)
        {
            printf("书库中没有任何信息!\n\n");
            printf("按任意键回到主菜单!\n\n");
            getch();
            break;
        }
        else
        {
            for (n = 0; n < number_of_book; n++)
            {
                switch (select)
                {
                case '1':
                    strcpy(compare, bookinfo[n].number); 
                    break;
                case '2':
                    strcpy(compare, bookinfo[n].name); 
                    break;
                case '3':
                    strcpy(compare, bookinfo[n].author); 
                    break;
                }

                if (strcmp(compare, search) == 0)
                {
                    printf("|---------------------------------图书信息---------------------------------|\n");
                    printf("|编号  书名        作者      出版社          类别    单价    馆藏量  借阅数|\n");
                    printf("|                                                                          |\n");
                    printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f%-8d%-6d|\n", bookinfo[n].number, bookinfo[n].name, bookinfo[n].author,
                        bookinfo[n].press, bookinfo[n].category, bookinfo[n].price, bookinfo[n].quantity, bookinfo[n].time);
                    break;
                }
            }
            if (n >= number_of_book)
                printf("\n没有查找符合您要求的书籍!\n");

            printf("\n\n是否继续查询(y/n):");

            choice = getch();
            while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
                choice = getch();
            printf("%c", choice);
            printf("\n");
            if (choice == 'Y' || choice == 'y')
                flag = 1;
            else
                flag = 0;

        }
    }
}

/***************************************
    > function name: delete_book
    > 函数功能：删除图书
    > 函数返回值：无
***************************************/
void 
delete_book()/*根据图书名称对图书信息进行删除*/
{
    char search[20] = "";/*search用来存放要删除的书名*/
    int n, i;
    FILE* fp;
    char choice;
    library_book bookinfo[100];
    int number_of_book;

    system("cls");
    while (1)
    {
        fflush(stdin);
        printf("输入要删除的书本名称:");
        //gets(search);
        scanf("%s",search);
        fp = fopen("library.log", "r");
        number_of_book = 0;
        while (!feof(fp))
        {
            fscanf(fp, "%s %s %s %s %s %f %d %d\n",
                bookinfo[number_of_book].number, 
                bookinfo[number_of_book].name,
                bookinfo[number_of_book].author,
                bookinfo[number_of_book].press, 
                bookinfo[number_of_book].category,
                &bookinfo[number_of_book].price, 
                &bookinfo[number_of_book].quantity, 
                &bookinfo[number_of_book].time);
            number_of_book++;
        }

        fclose(fp);

        if (bookinfo[0].quantity == 0)
        {
            printf("书库中没有任何信息!\n\n");
            printf("按任意键回到主菜单!\n\n");
            getch();
            break;
        }/*if结束*/
        else
        {
            for (n = 0; n < number_of_book; n++)
                if (strcmp(bookinfo[n].name, search) == 0)
                {
                    break;
                }
            if (n >= number_of_book)
                printf("\n没有查找该书的任何信息!\n");
            else
            {
                printf("\n是否确认需要删除该条书目(Y/N):");
                choice = getch();
                while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
                    choice = getch();
                printf("%c", choice);
                if (choice == 'Y' || choice == 'y')
                {
                    for (i = n; i < number_of_book - 1; i++)
                        bookinfo[i] = bookinfo[i + 1];
                    number_of_book--;
                    fp = fopen("library.log", "w");
                    for (n = 0; n < number_of_book; n++)
                        fprintf(fp, "%s %s %s %s %s %f %d %d\n",
                            bookinfo[n].number, 
                            bookinfo[n].name, 
                            bookinfo[n].author,
                            bookinfo[n].press, bookinfo[n].category, 
                            bookinfo[n].price, bookinfo[n].quantity, 
                            bookinfo[n].time);
                    fclose(fp);
                    printf("\n删除成功!");
                }
                else
                    printf("\n该条书目没有被删除!");
            }

            printf("\n\n是否继续进行删除操作(y/n):");
            choice = getch();
            while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
                choice = getch();
            printf("%c", choice);
            printf("\n");
            if (choice == 'Y' || choice == 'y')
                continue;
            else
                break;
        }
        /*else结束*/
    }
    /*while(1)结束*/
}

/***************************
*   >函数名    display_price_lower
*   >参数      无
*   >返回值    无
*   该功能会根据图书价格从低到高排序
****************************/
void 
display_price_lower()/*根据价格列出图书信息*/
{
    float price;
    FILE* p1;
    int n;
    int count = 0;
    library_book bookinfo[100];
    int number_of_book;

    system("cls");
    printf("请输入你的理想价格,我们将推荐比您理想价位稍低的书籍:");
    scanf("%f", &price);
    p1 = fopen("library.log", "r");
    number_of_book = 0;
    while (!feof(p1))
    {
        fscanf(p1, "%s %s %s %s %s %f %d %d\n",
            bookinfo[number_of_book].number, bookinfo[number_of_book].name, bookinfo[number_of_book].author,
            bookinfo[number_of_book].press, bookinfo[number_of_book].category,
            &bookinfo[number_of_book].price, &bookinfo[number_of_book].quantity, &bookinfo[number_of_book].time);
        number_of_book++;
    }
    fclose(p1);
    if (bookinfo[0].quantity == 0)
    {
        printf("\n没有任何图书信息!\n");
    }
    else
    {
        for (n = 0; n < number_of_book; n++)
        {
            if (bookinfo[n].price <= price)
                count++;
        }
        if (count == 0)
            printf("书库中没有比%.1f元价格更低的图书。", price);
        else
        {
            printf("\n价格低于%.1f元的图书信息有%d本\n", price, count);
            printf("|---------------------------------图书信息---------------------------------|\n");
            printf("|编号  书名        作者      出版社          类别    单价    馆藏量  借阅数|\n");
            printf("|                                                                          |\n");
            for (n = 0; n < number_of_book; n++)
            {
                if (bookinfo[n].price <= price)
                    printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f%-8d%-6d|\n", bookinfo[n].number, bookinfo[n].name, bookinfo[n].author,
                        bookinfo[n].press, bookinfo[n].category, bookinfo[n].price, bookinfo[n].quantity, bookinfo[n].time);
            }
        }
    }
    printf("\n\n按任意键回到主菜单!\n");
    getch();
}

/***********************************
*   >函数名  modify_book()  
*   >参数    无
*   提供修改图书信息的功能，根据书名修改图书任意信息
************************************/
void 
modify_book()
{
    int flag = 1, flag1 = 1, flag2, n;
    char change, choice;
    char number[15];/*图书编号*/
    char name[30];/*图书名称*/
    char author[20];/*作者*/
    char press[30];/*出版社*/
    char category[20];/*类别*/
    int  quantity;/*藏书量*/
    float price;/*单价*/

    char search[30];/*要修改的书名*/
    FILE* p1;
    library_book bookinfo[100];
    int number_of_book;
    while (flag)
    {
        flag2 = 0;
        system("cls");
        fflush(stdin);
        printf("输入要修改信息的书本名:");
        //gets(search);
        scanf("%s",search);
        p1 = fopen("library.log", "r");
        number_of_book = 0;
        while (!feof(p1))
        {
            fscanf(p1, "%s %s %s %s %s %f %d %d\n",
                bookinfo[number_of_book].number, 
                bookinfo[number_of_book].name, 
                bookinfo[number_of_book].author,
                bookinfo[number_of_book].press,
                bookinfo[number_of_book].category,
                &bookinfo[number_of_book].price,
                &bookinfo[number_of_book].quantity, 
                &bookinfo[number_of_book].time);
            number_of_book++;
        }
        fclose(p1);
        if (bookinfo[0].quantity == 0)
        {
            printf("书库中没有任何信息!\n\n");
            printf("按任意键回到主菜单!\n\n");
            getch();
            break;
        }
        else
        {
            for (n = 0; n < number_of_book; n++)
                if (strcmp(bookinfo[n].name, search) == 0)
                {
                    printf("\n");
                    printf("|---------------------------------图书信息---------------------------------|\n");
                    printf("|编号  书名        作者      出版社          类别    单价    馆藏量  借阅数|\n");
                    printf("|                                                                          |\n");
                    printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f%-8d%-6d|\n", 
                        bookinfo[n].number, 
                        bookinfo[n].name, 
                        bookinfo[n].author,
                        bookinfo[n].press, 
                        bookinfo[n].category, 
                        bookinfo[n].price, 
                        bookinfo[n].quantity, 
                        bookinfo[n].time);

                    while (flag1) {

                        printf("\n1.书籍编号\n2.书籍名称\n3.书籍作者\n4.出版社\n5.书籍类别\n6.书籍单价\n7.藏书量\n\n您想要修改的是:");
                        change = getch();
                        while (change != '1' && change != '2' && change != '3' && change != '4' && change != '5' && change != '6' && change != '7')
                            change = getch();
                        printf("%c", change);
                        printf("\n请输入新的字条:");

                        fflush(stdin);

                        switch (change)
                        {
                        case '1':
                            gets(number); 
                            flag1 = 0; 
                            flag2 = check_repeat_book(number);
                            if (!flag2)
                                strcpy(bookinfo[n].number, number);
                            break;
                        case '2':
                            gets(name); 
                            strcpy(bookinfo[n].name, name);
                            flag1 = 0;
                            break;
                        case '3':
                            gets(author); 
                            strcpy(bookinfo[n].author, 
                                author); flag1 = 0; 
                            break;
                        case '4':
                            gets(press); 
                            strcpy(bookinfo[n].press, 
                                press); flag1 = 0; 
                            break;
                        case '5':
                            gets(category); 
                            strcpy(bookinfo[n].category, category);
                            flag1 = 0; 
                            break;
                        case '6':
                            scanf("%f", &price);
                            bookinfo[n].price = price;
                            flag1 = 0; 
                            break;
                        case '7':
                            scanf("%d", &quantity);
                            bookinfo[n].quantity = quantity;
                            flag1 = 0; 
                            break;

                        default:break;
                        }
                    }
                    flag1 = 1;
                    break;
                }
            if (n >= number_of_book)
                printf("\n没有查找该书的任何信息!");
            else if (!flag2)
            {
                p1 = fopen("library.log", "w");
                for (n = 0; n < number_of_book; n++)
                    fprintf(p1, "%s %s %s %s %s %f %d %d\n",
                        bookinfo[n].number,
                        bookinfo[n].name,
                        bookinfo[n].author,
                        bookinfo[n].press,
                        bookinfo[n].category,
                        bookinfo[n].price, 
                        bookinfo[n].quantity, 
                        bookinfo[n].time);

                fclose(p1);

                printf("\n修改成功!");
            }
            else
                printf("您想修改的图书信息与馆内信息重复。");

            printf("\n是否继续进行修改(y/n):");
            choice = getch();

            while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
                choice = getch();

            printf("%c", choice);
            printf("\n");
            if (choice == 'Y' || choice == 'y')
                flag = 1;
            else
                flag = 0;
        }
    }
}

/****************************************
*   >函数名    display_popular()
*   >参数      无
*   >返回值    无
*   按照图书借出的次数排序
*****************************************/
void 
display_popular()/*图书受欢迎度排行榜*/
{
    FILE* p1;
    int n, i, j, k;
    int count = 0;
    library_book bookinfo[101];
    int number_of_book;

    system("cls");
    fflush(stdin);
    p1 = fopen("library.log", "r");
    number_of_book = 0;
    while (!feof(p1))
    {
        fscanf(p1, "%s %s %s %s %s %f %d %d\n",
            bookinfo[number_of_book].number, 
            bookinfo[number_of_book].name, 
            bookinfo[number_of_book].author,
            bookinfo[number_of_book].press,
            bookinfo[number_of_book].category,
            &bookinfo[number_of_book].price,
            &bookinfo[number_of_book].quantity,
            &bookinfo[number_of_book].time);
        number_of_book++;
    }
    fclose(p1);

    if (bookinfo[0].quantity == 0)
    {
        printf("没有任何图书信息!\n\n");
    }
    else
    {
        for (i = 0; i < number_of_book - 1; i++)
        {
            k = i;
            for (j = i + 1; j < number_of_book; j++)
                if (bookinfo[j].time > bookinfo[k].time)
                    k = j;
            if (k != i)
            {
                bookinfo[100] = bookinfo[i];
                bookinfo[i] = bookinfo[k];
                bookinfo[k] = bookinfo[100];
            }
        }

        printf("|---------------------------图书受欢迎度排行榜-----------------------------|\n");
        printf("|编号  书名        作者      出版社          类别    单价    馆藏量  借阅数|\n");
        printf("|                                                                          |\n");
        for (n = 0; n < number_of_book; n++)
        {
            printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f%-8d%-6d|\n", 
                bookinfo[n].number, bookinfo[n].name,
                bookinfo[n].author,
                bookinfo[n].press, 
                bookinfo[n].category, 
                bookinfo[n].price, 
                bookinfo[n].quantity, 
                bookinfo[n].time);
        }

    }
    printf("\n\n按任意键回到主菜单!\n");
    getch();
}