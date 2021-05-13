#include<stdio.h>
#include"grades.h"
#include<stdlib.h>
#define MAXSUBJECT 100

//#define char* grades_filename strcat(current_account, "_stu.csv")


/*  ���������������ѧ���ɼ���Ϣ
**  ͨ��Ȩ���Լ���ʧ��������ĳһѧ�ƶ����ܳɼ���Ӱ��
**  ����ѡ���������з��� ��
**  1�����ڷ�������90�ĳɼ������й���
**  2�����ڶ����Լ��ܳɼ�������Ӱ���ѧ�ƽ�������
*/
void 
advice_grades() {
    //������Ļ
    system("cls");
    //  ���ļ��Ǵ洢�û��ɼ����ļ�������csv�ĸ�ʽ���д洢
    extern char current_account[8];
    int count = 0;
    /*char* grades_filename = strcat(current_account, "_stu.csv");*/
    char* advice_filename = (char*)malloc(sizeof(char));
    advice_filename= strcpy(advice_filename,current_account);
    strcat(advice_filename,"_stu.csv");
    //char filename[] = "stu1.csv";
    //  ����һ����ά���飬MAXSUBJECT�У�3�У�
    //  ��Ϊһ��ָ��ָ��һ���ַ�����С������40���ַ���
    char grades[MAXSUBJECT][3][40] = { 0 };

    FILE* fp = fopen(advice_filename, "r");     // fpָ���ļ�ͷ��

    if (fp == NULL)
    {
        printf("\t\t\tδ����ɼ�����Ϣ���뵼��[�û���]_stu.csv�ĳɼ���Ϣ��\n");
        printf("\t\t\t�������󷵻�ϵͳ...\n");
        clock_delay();
        return;
        
    }
    for (int i = 0; i < MAXSUBJECT; i++)
        for (int j = 0; j < 3; j++) {
            fscanf(fp, "%[^,_\n]", grades[i][j]);   // �������Ż�\nΪֹ
            fgetc(fp);                              // ��ȡһ���ַ�(���Ż�\n)
        }


    //  ����һ�����飬������Ϊ�м������Գɼ�Ӱ������ѧ��
    int a[MAXSUBJECT];

    printf("\t\t\t��ӭ�鿴�ɼ���Ϣ����ϵͳ��\n\t\t\t�����гɼ��д���90�ֵ��У�\n");
    for (int i = 0; i < MAXSUBJECT; i++)
    {
        //������ھ�ʮ�ֵĳɼ�
        if (atoi(grades[i + 1][2]) >= 90)
        {
            printf("\t\t\t--------------------------------\n");
            printf("\t\t\t\t%s\n", grades[i + 1][0]);
            count++;
        }
    }
    printf("\t\t\t��ϲ����һ����%d�Ŵ���90�ֵ�ѧ��\n",count);

    //2���ҵ���ͬѧ�ɼ�Ӱ������ѧ�ƣ������
    for (int i = 0; i < MAXSUBJECT; i++) 
        a[i] = atoi(grades[i + 1][1]) * (100 - (atoi(grades[i + 1][2])));

    //�ҵ����ֵ���±꣬���ø��±������Ӧ��ѧ��
    int max=0,maxIndex;
    
    //��������Ĺ������ҵ������ֵ���±�
    for (int i = 0; i <MAXSUBJECT; i++)
    {
        if (max < a[i]) {
            max = a[i];
            maxIndex = i;
        }
    }
    printf("\t\t\t----------------------\n\n\n");
    printf("\t\t\t��������һѧ�ƴ��ڽϴ�����:\n");
    printf("\t\t\t\t[%s]\t\n\n", grades[maxIndex+1][0]);

    printf("\t\t����!\n\t(����ѧ�ƶ������ܳɼ�Ӱ��ϴ󣬻�������ѧϰ�е�ĳЩ���滹����һЩ���⡣\n\t���������ص�ѧϰ�ƻ��������Խ���ѧϰ�а���Ŷ��)\n");
    printf("\n\n\n");

    //free(advice_filename);
    system("pause");
    
}

/*  ����������cal_grades
**  ���������ܡ���������¼����ļ���ƽ��ѧ�ּ��㣬���Ҵ�ӡ����  
**  ��������ֵ����
**  ����������ֵ����
*/
void 
cal_grades()
{
    system("cls");

    float sum = 0;
    float sum_credit = 0;
    float GPA = 0;
    //�ļ���Ϣ
    extern char current_account[8];
    /*char* grades_filename = strcat(current_account, "_stu.csv");*/
    char* cal_filename = (char*)malloc(sizeof(char));
    cal_filename = strcpy(cal_filename, current_account);
    cal_filename= strcat(cal_filename, "_stu.csv");

    /*extern char* grades_filename=strcat(current_account,"_stu.csv");*/

 /*   if (grades_filename == NULL)
    {
        cal_filename = strcat(current_account, "_stu.csv");
    }
    else
    {
        cal_filename = strcpy(cal_filename, grades_filename);
    }

    cal_filename = strcpy(cal_filename, grades_filename);*/
    //char filename[] = "stu2.csv";

    char grades[MAXSUBJECT][3][40] = { 0 };

    FILE* fp = fopen(cal_filename, "r");     // fpָ���ļ�ͷ��
    if (fp == NULL)
    {
        printf("\t\t\tδ����ɼ�����Ϣ���뵼��[�û���]_stu.csv�ĳɼ���Ϣ��\n");
        printf("\t\t\t�������󷵻�ϵͳ...\n");
        clock_delay();
        return;
    }
    for (int i = 0; i < MAXSUBJECT; i++)
        for (int j = 0; j < 3; j++) {
            fscanf(fp, "%[^,_\n]", grades[i][j]);  // �������Ż�\nΪֹ
            fgetc(fp); // ��ȡһ���ַ�(���Ż�\n)
        }

    //for (int i = 0; i < 2; i++) {
    //    for (int j = 0; j < 3; j++)
    //        printf("%s ", table[i][j]);   // -20:�����,ռ20���ַ����
    //    printf("\n");
    //}
    //printf("%s %s", grades[0][0], grades[1][0]);

    for (int i = 0; i < 100; i++) {
        //  ʹ��atoi�������ַ����ĳɼ���ѧ��ת������ֵ��
        sum += atoi(grades[i + 1][1]) * atoi(grades[i + 1][2]);
        sum_credit += atoi(grades[i + 1][1]);
    }
    GPA = (sum / sum_credit - 50) / 10;

    printf("\t\t\t--------------------------------------\n");
    printf("\t\t\t����ƽ��ѧ�ּ���Ϊ��%.2f\n", GPA);
    printf("\t\t\t--------------------------------------\n");

    fclose(fp);
    //free(cal_filename);

    system("pause");

}
/*  ����������search_grades
**  ���������ܡ�������������ĳɼ���ص���Ϣ������ѧ�����֣�ѧ�֣��Լ�����
**  ����������ֵ����
**  �����ղ�������
*/
void 
search_grades() {

    system("cls");
    //extern char* grades_filename;

    char s[10];     //����������������ʮ�������Զ����ü���
    //char filename[] = "stu1.csv";
    extern char current_account[8];
    /*char* grades_filename = strcat(current_account, "_stu.csv");*/
     
    char* search_filename = (char*)malloc(sizeof(char));
    search_filename = strcpy(search_filename, current_account);
    strcat(search_filename, "_stu.csv");
    char grades[MAXSUBJECT][3][40] = { 0 };
    int flag = 0;

input:
    printf("\t\t\t��������Ҫ���ҵ�ѧ�Ƴɼ������硰�����ϡ���\n\t\t\t����[0]����\n");
    //gets_s(s, 7);//������Ҫ���ҵ�ѧ��
    scanf("%s",s);
    //s[10] = "������";

    //  ��ȡ�ļ�������洢��grades��������
    FILE* fp = fopen(search_filename, "r");     // fpָ���ļ�ͷ��

    if (fp == NULL)
    {
        system("cls");
        printf("\t\t\tδ����ɼ�����Ϣ���뵼��[�û���]_stu.csv�ĳɼ���Ϣ��\n");
        printf("\t\t\t�������󷵻�ϵͳ...\n");
        clock_delay();
        return;
    }
    for (int i = 0; i < MAXSUBJECT; i++) {
        for (int j = 0; j < 3; j++) {
            fscanf(fp, "%[^,_\n]", grades[i][j]);  // �������Ż�\nΪֹ
            fgetc(fp); // ��ȡһ���ַ�(���Ż�\n)
        }
    }

    

    for (int i = 0; i < MAXSUBJECT; i++) {
        if (strcmp(s, grades[i][0]) == 0) {
            //����
            system("cls");

            printf("�Ѳ�ѯ��������Ϣ��\n");
            printf("\t\t\t--------------------------------------\n");
            //������ӡ����Ϣ
            for (int k = 0; k < 3; k++)
                printf("\t\t\t%s\t", grades[0][k]);
            printf("\n");
         

            //  ��ӡ���óɼ���Ӧ��������Ϣ
            for (int k = 0; k <= 2; k++)
                printf("\t\t\t%s\t", grades[i][k]);
            printf("\n");
            printf("\t\t\t--------------------------------------\n");

            system("pause");
            return;
        }
        else if (strcmp(s, "0") == 0)
        {
            return;
        }
        //filename = NULL;

    }



    printf("���벻��ȷ�����������룡\n");
    //�ص�����׶�
    goto input;
    //free(search_filename);
}

/*  ���������ơ�show_grades
**  ���������ܡ�����չʾ¼������ļ��ĳɼ���Ϣ
**  ��������ֵ����
**  ����������ֵ����
*/
void 
show_grades() {
    system("cls");
    //extern char* grades_filename;

    //�����ļ���
    //char filename[] = "stu1.csv";
    extern char current_account[8];
    /*char* show_filename = strcat(current_account, "_stu.csv");*/
    char* show_filename = (char *)malloc(sizeof(char));
    show_filename= strcpy(show_filename, current_account);
    strcat(show_filename, "_stu.csv");
    char grades[MAXSUBJECT][3][40] = { 0 };
 
  /*  if (grades_filename == NULL)
    {
        show_filename = strcat(current_account, "_stu.csv");
    }
    else
    {
        show_filename = strcpy(show_filename, grades_filename);
    }*/
    
    FILE* fp = fopen(show_filename, "r");     // fpָ���ļ�ͷ��

    if (fp == NULL)
    {
        printf("\t\t\tδ����ɼ�����Ϣ���뵼��[�û���]_stu.csv�ĳɼ���Ϣ��\n");
        printf("\t\t\t�������󷵻�ϵͳ...\n");
        clock_delay();
        return;
    }
    for (int i = 0; i < MAXSUBJECT; i++)
        for (int j = 0; j < 3; j++) {
            fscanf(fp, "%[^,_\n]", grades[i][j]);  // �������Ż�\nΪֹ
            fgetc(fp); // ��ȡһ���ַ�(���Ż�\n)

            //�����Ϊ�գ��ͽ���Ϣ��ӡ����
            if (strcmp(grades[i][j], "") != 0) {
                printf("%-20s", grades[i][j]);
                //ÿ�����ַ���һ��
                if ((j + 1) % 3 == 0)
                    printf("\n");
            }
        }

    // �ر��ļ�
    fclose(fp);
    //filename = NULL;
    system("pause");
    
   
 }

//void get_filename()
//{
//    extern char current_account[8];
//    char* grades_filename = strcat(current_account, "_stu.csv");
//}