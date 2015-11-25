/**
@author-buaasoft QiWangming
PhoneSystem
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 10
#define N 15
//ʱ��ṹ
struct date{
    int year;
    int month;
    int day;
}date;

//ҵ��ṹ
struct business{
    struct date time;
    int type;
    int holdingTime;
}business[N];

//�绰���ṹ
struct card{
    char number[12];
    char name[12];
    float balance;
    struct business bs;
}card[M]={//�ɲ������ݿ�����ļ����ж�̬��ȡ
    {"13141454996","����",20,{{0,0,0},0,0}},{"18203263771","����",30,{{0,0,0},0,0}},//��������ʵ������
    {"13141459344","C��",10,{{0,0,0},0,0}},{"18203262475","����",0,{{0,0,0},0,0}},
    {"15141493446","����",34,{{0,0,0},0,0}},{"18963524154","����",9,{{0,0,0},0,0}},
    {"18328688871","������",10,{{0,0,0},0,0}},{"12562314720","ţС��",1,{{0,0,0},0,0}},
    {"13454993520","������",12,{{0,0,0},0,0}},{"12345678900","��С��",11,{{0,0,0},0,0}}
};

int main()
{

    printf("========================��ӭʹ�õ绰��������ϵͳ========================\n");
    char num[12];//�������뵱ǰҪ�����ĵ绰����
    int j,i,flag=0,choice=1,count=0,control=0;//���ڿ������̵ļ�����
    float money=0.0;//ҵ�񻰷ѽ��
    char *type="��ҵ�����";//���ҵ������

    printf("������绰���룺");
    while(choice!=0){
    //�������뼰����Ĵ���
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
            printf("��ǰ���ݿ��в����ڴ˺��룬���������룺");
        }
        printf("��ǰ����Ϊ��%s  ",card[j].number);
        printf("����������%.2f\n",card[j].balance);//��ʾ����������ⳬ�����

         //�������뼰������
        if(count==0){
            printf("��ǰ����ʱ��Ϊ(�����ʽ��2013 09 10)��");
            while(control==0){
                scanf("%d %d %d",&card[j].bs.time.year,&card[j].bs.time.month,&card[j].bs.time.day);
                if((card[j].bs.time.year>0)&&(card[j].bs.time.month<12&&card[j].bs.time.month>0)&&(card[j].bs.time.day>0&&card[j].bs.time.day<31))
                {
                    control=1;
                    break;
                }
                if(control==1)
                    break;
                printf("�������ݲ��Ϸ������������룺");
            }
        }

        //ҵ���߼�����
        printf("========================ҵ�����===================================\n");
        printf("0,�˳�ҵ��                   1,�滰��                2,�����м�ͨ��\n");
        printf("\n");
        printf("3,���г�;ͨ��                4,���Ͷ���\n");
        printf("===================================================================\n");
        printf("ѡ��ҵ������[0��4]��");

        //ҵ����
        scanf("%d",&card[j].bs.type);
            switch(card[j].bs.type){
                case 1:
                    printf("����뻰��ֵ��");
                    scanf("%f",&money);
                    type="�滰��";
                    break;
                case 2:
                    printf("ͨ��ʱ��(����/����)��");
                    scanf("%d",&card[j].bs.holdingTime);
                    money=-0.2*card[j].bs.holdingTime;
                    type="�м�ͨ��";
                    break;
                case 3:
                    printf("ͨ��ʱ����(����/����)��");
                    scanf("%d",&card[j].bs.holdingTime);
                    money=-0.6*card[j].bs.holdingTime;
                    type="��;ͨ��";
                    break;
                case 4:
                    printf("���Ͷ���������");
                    scanf("%d",&card[j].bs.holdingTime);
                    money=-0.1*card[j].bs.holdingTime;
                    type="���Ͷ���";
                    break;
            }
        card[j].balance=card[j].balance+money;//������


    //��ʼ��ʾ��
        printf("========================��ѯ���===================================\n");
        printf("�绰���룺%s\n",card[j].number);
        printf("ҵ��������%s\n",card[j].name);
        printf("ҵ�����ͣ�%s\n",type);
        printf("ҵ���%.1f\n",money);
        printf("��ǰ��%.1f\n",card[j].balance);

    //���Ϊ������
        if(card[j].balance<=0)
        {
            printf("      !���㣬�뼰ʱ��ֵ��лл��\n");
        }

    //�ļ�д�롢�ɲ��ö�̬��¼�����ݿ�
        FILE *fp;
        if((fp=fopen("d:\\Business.txt","wb"))==NULL)//д��D��
        {
            printf("�ļ����ܴ򿪣�\n");
            exit(0);
        }
        fprintf(fp,"���룺%s, ҵ��������%s, ���ڣ�%d,%d,%d, ҵ�����ͣ� %s,��%0.1f",card[j].number,card[j].name,card[j].bs.time.year,card[j].bs.time.month,card[j].bs.time.day,type,card[j].balance);
        fclose(fp);

    //�����Ƿ����ҵ�����
        printf("�Ƿ����ҵ�������1[����]/0[�˳�]��");
        scanf("%d",&choice);
        count++;
        }
    return 0;
}


