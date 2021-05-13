#include<stdio.h>
#include<time.h>
#include"library.h"
#include <conio.h>
#include<string.h>

/*
*   @name       add_book
*   @param      newbook     �½��鼮
*   @param      flag        �����ж��˳����Ǽ���¼��
*   @version    1.0     
*   ��ģ�������������ͼ�飬¼����Ϣ����ͼ����Ϣд��"library.log"���ļ���
*/
void 
add_book() /*�����½���ͼ����Ϣ*/
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
        printf("������ͼ����:");
        //gets(newbook.number);
        scanf("%s",newbook.number);

        if (check_repeat_book(newbook.number))
        {
            printf("��ͼ�����ѱ�ʹ�ã�");
            printf("\n���������������\n\n");
            getch();
            flag = 1;
        }
        else {
            //fflush(stdin);
            printf("����������:");
            //gets(newbook.name);
            scanf("%s",newbook.name);

            //fflush(stdin);
            printf("����������:");
            //gets(newbook.author);
            scanf("%s", newbook.author);


            printf("�����������:");
            scanf("%s", newbook.press);
            //gets(newbook.press);

            printf("���������(��ѧ/��ѧ/��ѧ/��ѧ/��):");
            scanf("%s", newbook.category);
            //gets(newbook.category);

            printf("������۸�:");
            scanf("%f", &newbook.price);

            printf("������ݲ���:");
            scanf("%d", &newbook.quantity);

            printf("��������Ĵ���(��������0):");
            scanf("%d", &newbook.time);
            fflush(stdin);
            printf("�Ƿ񱣴������Ŀ(y/n):");
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
                printf("\n������Ŀ����ӵ�library.log�ļ���!\n");
            }
            else
            {
                printf("\n������Ŀδ����!\n");
            }
            printf("\n\n�Ƿ���������Ŀ(y/n):");
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
*   @param      bookinfo        ��ȡ�鼮��Ϣ
*   @param      flag            �����ж��˳����Ǽ���¼��
*   @version    1.0
*   �����ж��Ƿ����ظ���ŵ��鼮��������򷵻�1�����û�з���0
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
        //�ļ�������ʱ�ʹ����ļ�
        fp = fopen("library.log", "w");
        printf("\t\t\t�ļ������ڣ������´�����\n");
        return NULL;
    }
    if (fp == NULL)
    {
        printf("\t\t\tδ֪�����˻��ļ���ʧ�ܣ�\n");
        return NULL;
    }
    //����ļ�û�������򷵻�0
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
*   @param      bookinfo        ��ȡ�鼮��Ϣ
*   @param      fp              ָ���ļ���ָ��
*   @param      current_account ȫ�ֱ��������������û����е��ļ���
*   @version    1.0
*   @function   �������ͼ��������е��鼮
*   
*/
void 
display_book()/*��ʾȫ��ͼ����Ϣ*/
{
    int n;
    library_book bookinfo[100];
    int number_of_book = 0;

    system("cls");
    fflush(stdin);
    //char library_filename[50];
    //extern char current_account[8];

    ////��Ƹ��û������ļ���
    //strcpy(library_filename, current_account);
    //strcat(library_filename, "_library.log");
    FILE* fp = fopen("library.log", "r");

    if (fp == NULL) {
        //�ļ�������ʱ�ʹ����ļ�
        fp = fopen("library.log", "w");
        printf("\t\t\t�ļ������ڣ������´�����\n");
        return NULL;
    }
    if (fp == NULL)
    {
        printf("\t\t\tδ֪�����˻��ļ���ʧ�ܣ�\n");
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

    printf("��ǰͼ�������%dĿ�鼮\n\n", number_of_book);

    if (bookinfo[0].quantity == 0)
    {
        printf("\nû���κ�ͼ����Ϣ!\n\n");
    }
    else
    {
        n = 0;
        printf("|---------------------------------ͼ����Ϣ---------------------------------|\n");
        printf("|���  ����        ����      ������          ���    ����    �ݲ���  ������|\n");
        printf("|                                                                          |\n");

        //����鼮��Ϣ
        while (n < number_of_book)
        {
            printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f%-8d%-6d|\n", 
                bookinfo[n].number, bookinfo[n].name, bookinfo[n].author,
                bookinfo[n].press, bookinfo[n].category, bookinfo[n].price,
                bookinfo[n].quantity, bookinfo[n].time);
            n++;
        }
    }

    printf("\n\n�������������һ���˵�!\n");
    getch();
}

/*  
*   @name       search_book
*   @param      *_compare       �������Ҫ��ѯ����Ϣ
*   @param      name_of_book    ������ѯ���鼮�����
*   @param      flag            �����ж�ѭ��������
*   @function   �����鼮���������������鼮��Ϣ
*/
void 
search_book()/*����ͼ��������ʾͼ�����Ϣ*/
{
    int flag = 1, flag1 = 1;
    char select;
    char name_compare[30] = "";/*name_compare�������Ҫ��ѯ������*/
    char number_compare[30] = ""; /*number_compare�������Ҫ��ѯ���鼮���*/
    char author_compare[30] = "";/*author_compare�������Ҫ��ѯ����������*/
    char search[30] = "";/*search�Ǳȶ�����,����Ҫ���ҵ���������ȶ�����*/
    char compare[30] = "";/*compare�Ǳȶ�����,������е���������ȶ�����*/
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

            printf("����ͨ��\n\n1.<-ͼ����->\n\n2.<-����->\n\n3.<-������->\n\n���ַ�ʽ��ѯͼ��:");

            //select = getch();
            scanf("%c",&select);
            
            printf("%c", select);
            printf("\n\n�������������Ϣ:");
            //ѭ������
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
                printf("\n��Ҫ����˵�֮�������~�������������");
                fflush(stdin);
                getch();
            }
        }

        flag1 = 1;
        if (bookinfo[0].quantity == 0)
        {
            printf("�����û���κ���Ϣ!\n\n");
            printf("��������ص����˵�!\n\n");
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
                    printf("|---------------------------------ͼ����Ϣ---------------------------------|\n");
                    printf("|���  ����        ����      ������          ���    ����    �ݲ���  ������|\n");
                    printf("|                                                                          |\n");
                    printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f%-8d%-6d|\n", bookinfo[n].number, bookinfo[n].name, bookinfo[n].author,
                        bookinfo[n].press, bookinfo[n].category, bookinfo[n].price, bookinfo[n].quantity, bookinfo[n].time);
                    break;
                }
            }
            if (n >= number_of_book)
                printf("\nû�в��ҷ�����Ҫ����鼮!\n");

            printf("\n\n�Ƿ������ѯ(y/n):");

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
    > �������ܣ�ɾ��ͼ��
    > ��������ֵ����
***************************************/
void 
delete_book()/*����ͼ�����ƶ�ͼ����Ϣ����ɾ��*/
{
    char search[20] = "";/*search�������Ҫɾ��������*/
    int n, i;
    FILE* fp;
    char choice;
    library_book bookinfo[100];
    int number_of_book;

    system("cls");
    while (1)
    {
        fflush(stdin);
        printf("����Ҫɾ�����鱾����:");
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
            printf("�����û���κ���Ϣ!\n\n");
            printf("��������ص����˵�!\n\n");
            getch();
            break;
        }/*if����*/
        else
        {
            for (n = 0; n < number_of_book; n++)
                if (strcmp(bookinfo[n].name, search) == 0)
                {
                    break;
                }
            if (n >= number_of_book)
                printf("\nû�в��Ҹ�����κ���Ϣ!\n");
            else
            {
                printf("\n�Ƿ�ȷ����Ҫɾ��������Ŀ(Y/N):");
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
                    printf("\nɾ���ɹ�!");
                }
                else
                    printf("\n������Ŀû�б�ɾ��!");
            }

            printf("\n\n�Ƿ��������ɾ������(y/n):");
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
        /*else����*/
    }
    /*while(1)����*/
}

/***************************
*   >������    display_price_lower
*   >����      ��
*   >����ֵ    ��
*   �ù��ܻ����ͼ��۸�ӵ͵�������
****************************/
void 
display_price_lower()/*���ݼ۸��г�ͼ����Ϣ*/
{
    float price;
    FILE* p1;
    int n;
    int count = 0;
    library_book bookinfo[100];
    int number_of_book;

    system("cls");
    printf("�������������۸�,���ǽ��Ƽ����������λ�Ե͵��鼮:");
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
        printf("\nû���κ�ͼ����Ϣ!\n");
    }
    else
    {
        for (n = 0; n < number_of_book; n++)
        {
            if (bookinfo[n].price <= price)
                count++;
        }
        if (count == 0)
            printf("�����û�б�%.1fԪ�۸���͵�ͼ�顣", price);
        else
        {
            printf("\n�۸����%.1fԪ��ͼ����Ϣ��%d��\n", price, count);
            printf("|---------------------------------ͼ����Ϣ---------------------------------|\n");
            printf("|���  ����        ����      ������          ���    ����    �ݲ���  ������|\n");
            printf("|                                                                          |\n");
            for (n = 0; n < number_of_book; n++)
            {
                if (bookinfo[n].price <= price)
                    printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f%-8d%-6d|\n", bookinfo[n].number, bookinfo[n].name, bookinfo[n].author,
                        bookinfo[n].press, bookinfo[n].category, bookinfo[n].price, bookinfo[n].quantity, bookinfo[n].time);
            }
        }
    }
    printf("\n\n��������ص����˵�!\n");
    getch();
}

/***********************************
*   >������  modify_book()  
*   >����    ��
*   �ṩ�޸�ͼ����Ϣ�Ĺ��ܣ����������޸�ͼ��������Ϣ
************************************/
void 
modify_book()
{
    int flag = 1, flag1 = 1, flag2, n;
    char change, choice;
    char number[15];/*ͼ����*/
    char name[30];/*ͼ������*/
    char author[20];/*����*/
    char press[30];/*������*/
    char category[20];/*���*/
    int  quantity;/*������*/
    float price;/*����*/

    char search[30];/*Ҫ�޸ĵ�����*/
    FILE* p1;
    library_book bookinfo[100];
    int number_of_book;
    while (flag)
    {
        flag2 = 0;
        system("cls");
        fflush(stdin);
        printf("����Ҫ�޸���Ϣ���鱾��:");
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
            printf("�����û���κ���Ϣ!\n\n");
            printf("��������ص����˵�!\n\n");
            getch();
            break;
        }
        else
        {
            for (n = 0; n < number_of_book; n++)
                if (strcmp(bookinfo[n].name, search) == 0)
                {
                    printf("\n");
                    printf("|---------------------------------ͼ����Ϣ---------------------------------|\n");
                    printf("|���  ����        ����      ������          ���    ����    �ݲ���  ������|\n");
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

                        printf("\n1.�鼮���\n2.�鼮����\n3.�鼮����\n4.������\n5.�鼮���\n6.�鼮����\n7.������\n\n����Ҫ�޸ĵ���:");
                        change = getch();
                        while (change != '1' && change != '2' && change != '3' && change != '4' && change != '5' && change != '6' && change != '7')
                            change = getch();
                        printf("%c", change);
                        printf("\n�������µ�����:");

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
                printf("\nû�в��Ҹ�����κ���Ϣ!");
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

                printf("\n�޸ĳɹ�!");
            }
            else
                printf("�����޸ĵ�ͼ����Ϣ�������Ϣ�ظ���");

            printf("\n�Ƿ���������޸�(y/n):");
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
*   >������    display_popular()
*   >����      ��
*   >����ֵ    ��
*   ����ͼ�����Ĵ�������
*****************************************/
void 
display_popular()/*ͼ���ܻ�ӭ�����а�*/
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
        printf("û���κ�ͼ����Ϣ!\n\n");
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

        printf("|---------------------------ͼ���ܻ�ӭ�����а�-----------------------------|\n");
        printf("|���  ����        ����      ������          ���    ����    �ݲ���  ������|\n");
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
    printf("\n\n��������ص����˵�!\n");
    getch();
}