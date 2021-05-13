#include<stdio.h>
#include"grades.h"
#include<stdlib.h>
#define MAXSUBJECT 100

//#define char* grades_filename strcat(current_account, "_stu.csv")


/*  这个功能用来分析学生成绩信息
**  通过权重以及丢失分数计算某一学科对于总成绩的影响
**  这里选用两处进行分析 ：
**  1、对于分数高于90的成绩，进行鼓励
**  2、对于对于自己总成绩造成最大影响的学科进行提醒
*/
void 
advice_grades() {
    //清理屏幕
    system("cls");
    //  该文件是存储用户成绩的文件，运用csv的格式进行存储
    extern char current_account[8];
    int count = 0;
    /*char* grades_filename = strcat(current_account, "_stu.csv");*/
    char* advice_filename = (char*)malloc(sizeof(char));
    advice_filename= strcpy(advice_filename,current_account);
    strcat(advice_filename,"_stu.csv");
    //char filename[] = "stu1.csv";
    //  定义一个三维数组，MAXSUBJECT行，3列，
    //  作为一个指针指向一个字符串大小不超过40的字符窜
    char grades[MAXSUBJECT][3][40] = { 0 };

    FILE* fp = fopen(advice_filename, "r");     // fp指向文件头部

    if (fp == NULL)
    {
        printf("\t\t\t未导入成绩新信息，请导入[用户名]_stu.csv的成绩信息！\n");
        printf("\t\t\t正在请求返回系统...\n");
        clock_delay();
        return;
        
    }
    for (int i = 0; i < MAXSUBJECT; i++)
        for (int j = 0; j < 3; j++) {
            fscanf(fp, "%[^,_\n]", grades[i][j]);   // 读到逗号或\n为止
            fgetc(fp);                              // 读取一个字符(逗号或\n)
        }


    //  定义一个数组，用来作为中间计算出对成绩影响最大的学科
    int a[MAXSUBJECT];

    printf("\t\t\t欢迎查看成绩信息分析系统！\n\t\t\t您所有成绩中大于90分的有：\n");
    for (int i = 0; i < MAXSUBJECT; i++)
    {
        //输出大于九十分的成绩
        if (atoi(grades[i + 1][2]) >= 90)
        {
            printf("\t\t\t--------------------------------\n");
            printf("\t\t\t\t%s\n", grades[i + 1][0]);
            count++;
        }
    }
    printf("\t\t\t恭喜您！一共有%d门大于90分的学科\n",count);

    //2、找到该同学成绩影响最大的学科，并输出
    for (int i = 0; i < MAXSUBJECT; i++) 
        a[i] = atoi(grades[i + 1][1]) * (100 - (atoi(grades[i + 1][2])));

    //找到最大值的下标，并用该下表输出对应的学科
    int max=0,maxIndex;
    
    //这个函数的功能是找到最大数值的下标
    for (int i = 0; i <MAXSUBJECT; i++)
    {
        if (max < a[i]) {
            max = a[i];
            maxIndex = i;
        }
    }
    printf("\t\t\t----------------------\n\n\n");
    printf("\t\t\t发现您有一学科存在较大问题:\n");
    printf("\t\t\t\t[%s]\t\n\n", grades[maxIndex+1][0]);

    printf("\t\t提醒!\n\t(这门学科对您的总成绩影响较大，或许是在学习中的某些方面还存在一些问题。\n\t如果做好相关的学习计划，或许会对将来学习有帮助哦！)\n");
    printf("\n\n\n");

    //free(advice_filename);
    system("pause");
    
}

/*  【函数名】cal_grades
**  【函数功能】用来计算录入仅文件的平均学分绩点，并且打印出来  
**  【函数传值】无
**  【函数返回值】无
*/
void 
cal_grades()
{
    system("cls");

    float sum = 0;
    float sum_credit = 0;
    float GPA = 0;
    //文件信息
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

    FILE* fp = fopen(cal_filename, "r");     // fp指向文件头部
    if (fp == NULL)
    {
        printf("\t\t\t未导入成绩新信息，请导入[用户名]_stu.csv的成绩信息！\n");
        printf("\t\t\t正在请求返回系统...\n");
        clock_delay();
        return;
    }
    for (int i = 0; i < MAXSUBJECT; i++)
        for (int j = 0; j < 3; j++) {
            fscanf(fp, "%[^,_\n]", grades[i][j]);  // 读到逗号或\n为止
            fgetc(fp); // 读取一个字符(逗号或\n)
        }

    //for (int i = 0; i < 2; i++) {
    //    for (int j = 0; j < 3; j++)
    //        printf("%s ", table[i][j]);   // -20:左对齐,占20个字符宽度
    //    printf("\n");
    //}
    //printf("%s %s", grades[0][0], grades[1][0]);

    for (int i = 0; i < 100; i++) {
        //  使用atoi函数将字符串的成绩和学分转换成数值型
        sum += atoi(grades[i + 1][1]) * atoi(grades[i + 1][2]);
        sum_credit += atoi(grades[i + 1][1]);
    }
    GPA = (sum / sum_credit - 50) / 10;

    printf("\t\t\t--------------------------------------\n");
    printf("\t\t\t您的平均学分绩点为：%.2f\n", GPA);
    printf("\t\t\t--------------------------------------\n");

    fclose(fp);
    //free(cal_filename);

    system("pause");

}
/*  【函数名】search_grades
**  【函数功能】用来查找输入的成绩相关的信息，包括学科名字，学分，以及分数
**  【函数返回值】无
**  【接收参数】无
*/
void 
search_grades() {

    system("cls");
    //extern char* grades_filename;

    char s[10];     //允许最大输入个数是十个，可以多设置几个
    //char filename[] = "stu1.csv";
    extern char current_account[8];
    /*char* grades_filename = strcat(current_account, "_stu.csv");*/
     
    char* search_filename = (char*)malloc(sizeof(char));
    search_filename = strcpy(search_filename, current_account);
    strcat(search_filename, "_stu.csv");
    char grades[MAXSUBJECT][3][40] = { 0 };
    int flag = 0;

input:
    printf("\t\t\t请输入您要查找的学科成绩，例如“高数上”：\n\t\t\t输入[0]返回\n");
    //gets_s(s, 7);//输入需要查找的学科
    scanf("%s",s);
    //s[10] = "高数上";

    //  读取文件并将其存储在grades的数组中
    FILE* fp = fopen(search_filename, "r");     // fp指向文件头部

    if (fp == NULL)
    {
        system("cls");
        printf("\t\t\t未导入成绩新信息，请导入[用户名]_stu.csv的成绩信息！\n");
        printf("\t\t\t正在请求返回系统...\n");
        clock_delay();
        return;
    }
    for (int i = 0; i < MAXSUBJECT; i++) {
        for (int j = 0; j < 3; j++) {
            fscanf(fp, "%[^,_\n]", grades[i][j]);  // 读到逗号或\n为止
            fgetc(fp); // 读取一个字符(逗号或\n)
        }
    }

    

    for (int i = 0; i < MAXSUBJECT; i++) {
        if (strcmp(s, grades[i][0]) == 0) {
            //清屏
            system("cls");

            printf("已查询到以下信息：\n");
            printf("\t\t\t--------------------------------------\n");
            //遍历打印出信息
            for (int k = 0; k < 3; k++)
                printf("\t\t\t%s\t", grades[0][k]);
            printf("\n");
         

            //  打印出该成绩对应的所有信息
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



    printf("输入不正确，请重新输入！\n");
    //回到输入阶段
    goto input;
    //free(search_filename);
}

/*  【函数名称】show_grades
**  【函数功能】用来展示录入进入文件的成绩信息
**  【函数传值】无
**  【函数返回值】无
*/
void 
show_grades() {
    system("cls");
    //extern char* grades_filename;

    //定义文件名
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
    
    FILE* fp = fopen(show_filename, "r");     // fp指向文件头部

    if (fp == NULL)
    {
        printf("\t\t\t未导入成绩新信息，请导入[用户名]_stu.csv的成绩信息！\n");
        printf("\t\t\t正在请求返回系统...\n");
        clock_delay();
        return;
    }
    for (int i = 0; i < MAXSUBJECT; i++)
        for (int j = 0; j < 3; j++) {
            fscanf(fp, "%[^,_\n]", grades[i][j]);  // 读到逗号或\n为止
            fgetc(fp); // 读取一个字符(逗号或\n)

            //如果不为空，就将信息打印出来
            if (strcmp(grades[i][j], "") != 0) {
                printf("%-20s", grades[i][j]);
                //每三个字符换一行
                if ((j + 1) % 3 == 0)
                    printf("\n");
            }
        }

    // 关闭文件
    fclose(fp);
    //filename = NULL;
    system("pause");
    
   
 }

//void get_filename()
//{
//    extern char current_account[8];
//    char* grades_filename = strcat(current_account, "_stu.csv");
//}