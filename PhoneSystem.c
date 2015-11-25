/**
@author-buaasoft QiWangming
PhoneSystem
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 10
#define N 15
//时间结构
struct date{
    int year;
    int month;
    int day;
}date;

//业务结构
struct business{
    struct date time;
    int type;
    int holdingTime;
}business[N];

//电话卡结构
struct card{
    char number[12];
    char name[12];
    float balance;
    struct business bs;
}card[M]={//可采用数据库或者文件进行动态读取
    {"13141454996","张三",20,{{0,0,0},0,0}},{"18203263771","李四",30,{{0,0,0},0,0}},//不符合现实软件设计
    {"13141459344","C君",10,{{0,0,0},0,0}},{"18203262475","王五",0,{{0,0,0},0,0}},
    {"15141493446","猴子",34,{{0,0,0},0,0}},{"18963524154","刘能",9,{{0,0,0},0,0}},
    {"18328688871","马老三",10,{{0,0,0},0,0}},{"12562314720","牛小宝",1,{{0,0,0},0,0}},
    {"13454993520","王二够",12,{{0,0,0},0,0}},{"12345678900","李小跑",11,{{0,0,0},0,0}}
};

int main()
{

    printf("========================欢迎使用电话卡余额管理系统========================\n");
    char num[12];//用于输入当前要操作的电话号码
    int j,i,flag=0,choice=1,count=0,control=0;//用于控制流程的计数器
    float money=0.0;//业务话费金额
    char *type="无业务操作";//标记业务类型

    printf("请输入电话号码：");
    while(choice!=0){
    //号码输入及错误的处理
        while(flag==0){
            scanf("%s",num);
            for(i=0;i<M;i++)
            {
                if(strcmp(num,card[i].number)==0)
                {
                    flag=1;
                    j=i;
                    break;
                }
            }
            if(flag==1)
                break;
            printf("当前数据库中不存在此号码，请重新输入：");
        }
        printf("当前号码为：%s  ",card[j].number);
        printf("（可用余额）：%.2f\n",card[j].balance);//显示可用余额以免超额操作

         //日期输入及错误处理
        if(count==0){
            printf("当前操作时间为(输入格式：2013 09 10)：");
            while(control==0){
                scanf("%d %d %d",&card[j].bs.time.year,&card[j].bs.time.month,&card[j].bs.time.day);
                if((card[j].bs.time.year>0)&&(card[j].bs.time.month<12&&card[j].bs.time.month>0)&&(card[j].bs.time.day>0&&card[j].bs.time.day<31))
                {
                    control=1;
                    break;
                }
                if(control==1)
                    break;
                printf("日期数据不合法，请重新输入：");
            }
        }

        //业务逻辑部分
        printf("========================业务介绍===================================\n");
        printf("0,退出业务                   1,存话费                2,进行市级通话\n");
        printf("\n");
        printf("3,进行长途通话                4,发送短信\n");
        printf("===================================================================\n");
        printf("选择业务类型[0—4]：");

        //业务处理
        scanf("%d",&card[j].bs.type);
            switch(card[j].bs.type){
                case 1:
                    printf("需存入话费值：");
                    scanf("%f",&money);
                    type="存话费";
                    break;
                case 2:
                    printf("通话时长(整数/分钟)：");
                    scanf("%d",&card[j].bs.holdingTime);
                    money=-0.2*card[j].bs.holdingTime;
                    type="市级通话";
                    break;
                case 3:
                    printf("通话时长：(整数/分钟)：");
                    scanf("%d",&card[j].bs.holdingTime);
                    money=-0.6*card[j].bs.holdingTime;
                    type="长途通话";
                    break;
                case 4:
                    printf("发送短信条数：");
                    scanf("%d",&card[j].bs.holdingTime);
                    money=-0.1*card[j].bs.holdingTime;
                    type="发送短信";
                    break;
            }
        card[j].balance=card[j].balance+money;//余额计算


    //开始显示：
        printf("========================查询结果===================================\n");
        printf("电话号码：%s\n",card[j].number);
        printf("业主姓名：%s\n",card[j].name);
        printf("业务类型：%s\n",type);
        printf("业务金额：%.1f\n",money);
        printf("当前余额：%.1f\n",card[j].balance);

    //余额为负处理
        if(card[j].balance<=0)
        {
            printf("      !余额不足，请及时充值，谢谢！\n");
        }

    //文件写入、可采用动态记录和数据库
        FILE *fp;
        if((fp=fopen("d:\\Business.txt","wb"))==NULL)//写入D盘
        {
            printf("文件不能打开！\n");
            exit(0);
        }
        fprintf(fp,"号码：%s, 业主姓名：%s, 日期：%d,%d,%d, 业务类型： %s,余额：%0.1f",card[j].number,card[j].name,card[j].bs.time.year,card[j].bs.time.month,card[j].bs.time.day,type,card[j].balance);
        fclose(fp);

    //决定是否继续业务操作
        printf("是否继续业务操作：1[继续]/0[退出]：");
        scanf("%d",&choice);
        count++;
        }
    return 0;
}


