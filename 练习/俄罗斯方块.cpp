#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
 
/*---------------------�ṹ������-----------------------*/
 
/*��ɵ�Ԫ�ṹ��*/
typedef struct cell
{
    int color;
    int state;
    int style;
    int event;
} unit;
 
/*λ�ýṹ��*/
typedef struct location
{
    int i;
    int j;
} place;
 
/*----------------------ȫ�ֱ���------------------------*/
 
int longth=24,high=23,x0=0,y0=0,xs=0,ys=0,color=240,jmax=0,imax=0,pmax=0,xn=0,yn=0,scoremax=0,score=0,speed=600;
unit now,*p=NULL;
place w[5];
unit ready,nowone;
 
/*----------------------��������------------------------*/
 
void textcolor(int color);                                       /*������ɫ*/
void gotoxy(int x, int y);                                       /*�ƶ����*/
void ycgb(void);                                                 /*���ع��*/
void xsgb(void);                                                 /*��ʾ���*/
void qk(void);                                                   /*�޻�����պ���*/
void window(int color, int xw, int yw, int longth, int hight);   /*���溯��*/
int rand(int r_min,int r_max);                                   /*���������*/
void clean(unit* u0,int color);                                  /*��Ԫ����*/
unit* c(int i,int j);                                            /*��άתһά��ַ*/
int ts(int i,int j);                                             /*���鵽��Ļ����ת��*/
int eliminate(void);                                             /*�жϲ���ȥһ��*/
void nowscreen(void);                                            /*��ʾ��ǰ����*/
void newobject(void);                                            /*������������*/
void clc(void);                                                  /*��ԭԭѡ��Ԫ�ص�ֵ������Ļ�����*/
void fz(void);                                                   /*���µ�ѡ��Ԫ�ظ�ֵ������Ļ����ʾ*/
int change(void);                                                /*�Ե�ǰ�����е���״���б任*/
void mainchange(void);                                           /*�жϲ�����*/
int goleft(void);                                                /*�����ƶ�*/
int goright(void);                                               /*�����ƶ�*/
void stop(void);                                                 /*ֹͣ��������*/
int fall(void);                                                  /*����*/
void cleanall(void);                                             /*ȫ������*/
int judge(void);                                                 /*��Ϸ�ж�*/
int appear(void);                                                /*��ֵ��ǰ����λ�ò���ʾ*/
void check(void);                                                /*����������*/
void begain(void);                                               /*��ʼ����*/
 
/*----------------------��������------------------------*/
 
/*������ɫ*/
void textcolor(int color)
{
    SetConsoleTextAttribute(hOutput, color);
}
 
/*�ƶ����*/
void gotoxy(int x, int y)
{
    COORD coordScreen = {0, 0};
    coordScreen.X = x;
    coordScreen.Y = y;
    SetConsoleCursorPosition(hOutput, coordScreen);
}
 
/*���ع��*/
void ycgb(void)
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    GetConsoleCursorInfo(hOut, &cci);
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hOut, &cci);
}
 
/*��ʾ���*/
void xsgb(void)
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    GetConsoleCursorInfo(hOut, &cci);
    cci.bVisible = 1;
    SetConsoleCursorInfo(hOut, &cci);
}
 
/*�޻�����պ���*/
void qk(void)
{
    while (_kbhit())
    {
        getch();
    }
    return ;
}
 
/*���������*/
int rand(int r_min,int r_max)
{
    int r=(int)((r_max+1-r_min)* rand() / (RAND_MAX*1.0));
    return r+r_min;
 
}
 
/*��άתһά��ַ*/
unit* c(int i,int j)
{
    return p+i*jmax+j;
}
 
/*���鵽��Ļ����ת��*/
int ts(int i,int j)
{
    if(i<=3)
        return 0;
    xs=j*2+x0+2;
    ys=i-4+y0+1;
    return 1;
}
 
/*�жϲ���ȥһ��*/
int eliminate(void)
{
    int i=0,j=0,k=0,scorebefore=score;
    for(i=imax-1; i>=0; i--)
    {
        for(j=0; j<jmax; j++)
        {
            if(c(i,j)->state!=-1)
                break;
        }
        if(j==jmax)
        {
            ++score;
            for(k=i; k>0; --k)
            {
                for(j=0; j<jmax; j++)
                    *c(k,j)=*c(k-1,j);
            }
            for(j=0; j<jmax; j++)
                clean(c(0,j),color);
            ++i;
        }
    }
    if(score>scoremax)
        scoremax=score;
    return scorebefore-score;
}
 
/*��ԭԭѡ��Ԫ�ص�ֵ������Ļ�����*/
void clc(void)
{
    int k=0;
    textcolor(color);
    for(k=1; k<5; k++)                   //��ԭԭѡ��Ԫ�ص�ֵ
    {
        clean(c(w[k].i,w[k].j),color);
        if(w[k].i>=4)
        {
            ts(w[k].i,w[k].j);
            gotoxy(xs,ys);
            printf("  ");
        }
    }
    return ;
}
 
/*���µ�ѡ��Ԫ�ظ�ֵ������Ļ����ʾ*/
void fz(void)
{
    int k=0;
    textcolor(nowone.color);
    for(k=1; k<5; k++)
    {
        *c(w[k].i,w[k].j)=nowone;
        if(w[k].i>=4)
        {
            ts(w[k].i,w[k].j);
            gotoxy(xs,ys);
            printf("��");
        }
    }
    return ;
}
 
/*�Ե�ǰ�����е���״���б任����������
�����жϵı�׼ 1.���κ����ҷ�Ԫ���Ƿ�������Խ��  2.�ĸ����齫Ҫ���ڵ�λ���Ƿ����
w[0].j<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i,w[0].j)->state>=0
���ڸ�ֵ:�ĸ�ȫ����ֵ
ע�ⲻҪ�ڴ˻���֮�����ް��յĻ����Ż�������Ӱ���������ܡ�
                w[1].i=w[0].i;
                w[1].j=w[0].j;
                w[2].i=w[0].i;
                w[2].j=w[0].j;
                w[3].i=w[0].i;
                w[3].j=w[0].j;
                w[4].i=w[0].i;
                w[4].j=w[0].j;
 */
int change(void)
{
    int style=0,k=0;
    if(nowone.state==1)
    {
        if(w[0].j+1<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0)
        {
            nowone.style=style=1;
            clc();
            w[1].i=w[0].i;          //ѡ���µ�Ԫ��
            w[1].j=w[0].j;
            w[2].i=w[0].i;
            w[2].j=w[0].j+1;
            w[3].i=w[0].i-1;
            w[3].j=w[0].j;
            w[4].i=w[0].i-1;
            w[4].j=w[0].j+1;
            fz();
            return 1;
        }
    }
    else if(nowone.state==2)
    {
        if(nowone.style==1)
            style=2;
        else if(nowone.style==2)
            style=1;
        if(style==1)        //����1:��
        {
            if(w[0].j<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-2,w[0].j)->state>=0&&c(w[0].i-3,w[0].j)->state>=0) //�ж��Ϸ��Ƿ�ռ��㹻
            {
                nowone.style=style;     //������ʽ
                clc();                  //��ԭԭѡ��Ԫ�ص�ֵ������Ļ�����
                for(k=1; k<=4; k++)      //ѡ���µ�Ԫ��
                {
                    w[k].i=w[0].i-k+1;
                    w[k].j=w[0].j;
                }
                fz();                //���µ�ѡ��Ԫ�ظ�ֵ������Ļ����ʾ
                return 1;
            }
        }
        else if(style==2)   //����2:����
        {
            if(w[0].j+3<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i,w[0].j+2)->state>=0&&c(w[0].i,w[0].j+3)->state>=0)  //�ж��ҷ��ռ��Ƿ��㹻
            {
                nowone.style=style;     //������ʽ
                clc();                  //��ԭԭѡ��Ԫ�ص�ֵ������Ļ�����
                for(k=1; k<=4; k++)     //ѡ���µ�Ԫ��
                {
                    w[k].i=w[0].i;
                    w[k].j=w[0].j+k-1;
                }
                fz();                  //���µ�ѡ��Ԫ�ظ�ֵ������Ļ����ʾ
                return 1;
            }
        }
    }
    else if(nowone.state==3)
    {
        if(nowone.style==1)
            style=2;
        else if(nowone.style==2)
            style=1;
        if(style==1)                   //z��1:��
        {
            if(w[0].j+2<jmax&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i,w[0].j+2)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0)
            {
                nowone.style=style;     //������ʽ
                clc();                  //��ԭԭѡ��Ԫ�ص�ֵ������Ļ�����
                w[1].i=w[0].i;          //ѡ���µ�Ԫ��
                w[1].j=w[0].j+1;
                w[2].i=w[0].i;
                w[2].j=w[0].j+2;
                w[3].i=w[0].i-1;
                w[3].j=w[0].j;
                w[4].i=w[0].i-1;
                w[4].j=w[0].j+1;
                fz();                  //���µ�ѡ��Ԫ�ظ�ֵ������Ļ����ʾ
                return 1;
            }
 
        }
        else if(style==2)            //z��2:��
        {
            if(w[0].j+1<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0&&c(w[0].i-2,w[0].j+1)->state>=0)
            {
                nowone.style=style;     //������ʽ
                clc();                  //��ԭԭѡ��Ԫ�ص�ֵ������Ļ�����
                w[1].i=w[0].i;          //ѡ���µ�Ԫ��
                w[1].j=w[0].j;
                w[2].i=w[0].i-1;
                w[2].j=w[0].j;
                w[3].i=w[0].i-1;
                w[3].j=w[0].j+1;
                w[4].i=w[0].i-2;
                w[4].j=w[0].j+1;
                fz();                  //���µ�ѡ��Ԫ�ظ�ֵ������Ļ����ʾ
                return 1;
            }
 
        }
    }
    else if(nowone.state==4)
    {
        if(nowone.style==1)
            style=2;
        else if(nowone.style==2)
            style=1;
        if(style==1)                   //s��1:��
        {
            if(w[0].j+2<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0&&c(w[0].i-1,w[0].j+2)->state>=0)
            {
                nowone.style=style;     //������ʽ
                clc();                  //��ԭԭѡ��Ԫ�ص�ֵ������Ļ�����
                w[1].i=w[0].i;          //ѡ���µ�Ԫ��
                w[1].j=w[0].j;
                w[2].i=w[0].i;
                w[2].j=w[0].j+1;
                w[3].i=w[0].i-1;
                w[3].j=w[0].j+1;
                w[4].i=w[0].i-1;
                w[4].j=w[0].j+2;
                fz();                  //���µ�ѡ��Ԫ�ظ�ֵ������Ļ����ʾ
                return 1;
            }
        }
        else if(style==2)            //s��2:��
        {
            if(w[0].j+1<jmax&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0&&c(w[0].i-2,w[0].j)->state>=0)
            {
                nowone.style=style;     //������ʽ
                clc();                  //��ԭԭѡ��Ԫ�ص�ֵ������Ļ�����
                w[1].i=w[0].i;          //ѡ���µ�Ԫ��
                w[1].j=w[0].j+1;
                w[2].i=w[0].i-1;
                w[2].j=w[0].j;
                w[3].i=w[0].i-1;
                w[3].j=w[0].j+1;
                w[4].i=w[0].i-2;
                w[4].j=w[0].j;
                fz();                  //���µ�ѡ��Ԫ�ظ�ֵ������Ļ����ʾ
                return 1;
            }
        }
    }
    else
    {
        style=nowone.style;
        ++style;
        if(style>4)
            style=1;
        if(nowone.state==5)        //͹��
        {
            if(style==1)      //͹��1����
            {
 
                if(w[0].j+2<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i,w[0].j+2)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0)
                {
                    nowone.style=style;     //������ʽ
                    clc();                  //��ԭԭѡ��Ԫ�ص�ֵ������Ļ�����
                    w[1].i=w[0].i;          //ѡ���µ�Ԫ��
                    w[1].j=w[0].j;
                    w[2].i=w[0].i;
                    w[2].j=w[0].j+1;
                    w[3].i=w[0].i;
                    w[3].j=w[0].j+2;
                    w[4].i=w[0].i-1;
                    w[4].j=w[0].j+1;
                    fz();                  //���µ�ѡ��Ԫ�ظ�ֵ������Ļ����ʾ
                    return 1;
                }
 
            }
            else if(style==2)      ////͹��2����
            {
 
                if(w[0].j+1<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0&&c(w[0].i-2,w[0].j)->state>=0)
                {
                    nowone.style=style;     //������ʽ
                    clc();                  //��ԭԭѡ��Ԫ�ص�ֵ������Ļ�����
                    w[1].i=w[0].i;          //ѡ���µ�Ԫ��
                    w[1].j=w[0].j;
                    w[2].i=w[0].i-1;
                    w[2].j=w[0].j;
                    w[3].i=w[0].i-1;
                    w[3].j=w[0].j+1;
                    w[4].i=w[0].i-2;
                    w[4].j=w[0].j;
                    fz();                  //���µ�ѡ��Ԫ�ظ�ֵ������Ļ����ʾ
                    return 1;
                }
 
            }
            else if(style==3)    //͹��3����
            {
                if(w[0].j+2<jmax&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0&&c(w[0].i-1,w[0].j+2)->state>=0)
                {
                    nowone.style=style;     //������ʽ
                    clc();                  //��ԭԭѡ��Ԫ�ص�ֵ������Ļ�����
                    w[1].i=w[0].i;          //ѡ���µ�Ԫ��
                    w[1].j=w[0].j+1;
                    w[2].i=w[0].i-1;
                    w[2].j=w[0].j;
                    w[3].i=w[0].i-1;
                    w[3].j=w[0].j+1;
                    w[4].i=w[0].i-1;
                    w[4].j=w[0].j+2;
                    fz();                  //���µ�ѡ��Ԫ�ظ�ֵ������Ļ����ʾ
                    return 1;
                }
            }
            else if(style==4)   //͹��4����
            {
                if(w[0].j+1<jmax&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0&&c(w[0].i-2,w[0].j+1)->state>=0)
                {
                    nowone.style=style;     //������ʽ
                    clc();                  //��ԭԭѡ��Ԫ�ص�ֵ������Ļ�����
                    w[1].i=w[0].i;          //ѡ���µ�Ԫ��
                    w[1].j=w[0].j+1;
                    w[2].i=w[0].i-1;
                    w[2].j=w[0].j;
                    w[3].i=w[0].i-1;
                    w[3].j=w[0].j+1;
                    w[4].i=w[0].i-2;
                    w[4].j=w[0].j+1;
                    fz();                  //���µ�ѡ��Ԫ�ظ�ֵ������Ļ����ʾ
                    return 1;
                }
            }
        }
        else if(nowone.state==6)    //��L��
        {
            if(style==1)       //��L��1����
            {
                if(w[0].j+1<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0&&c(w[0].i-2,w[0].j+1)->state>=0)
                {
                    nowone.style=style;     //������ʽ
                    clc();                  //��ԭԭѡ��Ԫ�ص�ֵ������Ļ�����
                    w[1].i=w[0].i;          //ѡ���µ�Ԫ��
                    w[1].j=w[0].j;
                    w[2].i=w[0].i;
                    w[2].j=w[0].j+1;
                    w[3].i=w[0].i-1;
                    w[3].j=w[0].j+1;
                    w[4].i=w[0].i-2;
                    w[4].j=w[0].j+1;
                    fz();                  //���µ�ѡ��Ԫ�ظ�ֵ������Ļ����ʾ
                    return 1;
                }
            }
            else if(style==2)    //��L��2������
            {
                if(w[0].j+2<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i,w[0].j+2)->state>=0&&c(w[0].i-1,w[0].j)->state>=0)
                {
                    nowone.style=style;     //������ʽ
                    clc();                  //��ԭԭѡ��Ԫ�ص�ֵ������Ļ�����
                    w[1].i=w[0].i;          //ѡ���µ�Ԫ��
                    w[1].j=w[0].j;
                    w[2].i=w[0].i;
                    w[2].j=w[0].j+1;
                    w[3].i=w[0].i;
                    w[3].j=w[0].j+2;
                    w[4].i=w[0].i-1;
                    w[4].j=w[0].j;
                    fz();                  //���µ�ѡ��Ԫ�ظ�ֵ������Ļ����ʾ
                    return 1;
                }
            }
            else if(style==3)    //��L��3������
            {
                if(w[0].j+1<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-2,w[0].j)->state>=0&&c(w[0].i-2,w[0].j+1)->state>=0)
                {
                    nowone.style=style;     //������ʽ
                    clc();                  //��ԭԭѡ��Ԫ�ص�ֵ������Ļ�����
                    w[1].i=w[0].i;          //ѡ���µ�Ԫ��
                    w[1].j=w[0].j;
                    w[2].i=w[0].i-1;
                    w[2].j=w[0].j;
                    w[3].i=w[0].i-2;
                    w[3].j=w[0].j;
                    w[4].i=w[0].i-2;
                    w[4].j=w[0].j+1;
                    fz();                  //���µ�ѡ��Ԫ�ظ�ֵ������Ļ����ʾ
                    return 1;
                }
 
            }
            else if(style==4)   //��L��4������
            {
                if(w[0].j+2<jmax&&c(w[0].i,w[0].j+2)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0&&c(w[0].i-1,w[0].j+2)->state>=0)
                {
                    nowone.style=style;     //������ʽ
                    clc();                  //��ԭԭѡ��Ԫ�ص�ֵ������Ļ�����
                    w[1].i=w[0].i;          //ѡ���µ�Ԫ��
                    w[1].j=w[0].j+2;
                    w[2].i=w[0].i-1;
                    w[2].j=w[0].j;
                    w[3].i=w[0].i-1;
                    w[3].j=w[0].j+1;
                    w[4].i=w[0].i-1;
                    w[4].j=w[0].j+2;
                    fz();                  //���µ�ѡ��Ԫ�ظ�ֵ������Ļ����ʾ
                    return 1;
                }
 
            }
        }
        else if(nowone.state==7)   //��L��
        {
            if(style==1)     //��L��1������
            {
                if(w[0].j+1<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-2,w[0].j)->state>=0)
                {
                    nowone.style=style;     //������ʽ
                    clc();                  //��ԭԭѡ��Ԫ�ص�ֵ������Ļ�����
                    w[1].i=w[0].i;          //ѡ���µ�Ԫ��
                    w[1].j=w[0].j;
                    w[2].i=w[0].i;
                    w[2].j=w[0].j+1;
                    w[3].i=w[0].i-1;
                    w[3].j=w[0].j;
                    w[4].i=w[0].i-2;
                    w[4].j=w[0].j;
                    fz();                  //���µ�ѡ��Ԫ�ظ�ֵ������Ļ����ʾ
                    return 1;
                }
 
            }
            else if(style==2)     //��L��2������
            {
                if(w[0].j+2<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0&&c(w[0].i-1,w[0].j+2)->state>=0)
                {
                    nowone.style=style;     //������ʽ
                    clc();                  //��ԭԭѡ��Ԫ�ص�ֵ������Ļ�����
                    w[1].i=w[0].i;          //ѡ���µ�Ԫ��
                    w[1].j=w[0].j;
                    w[2].i=w[0].i-1;
                    w[2].j=w[0].j;
                    w[3].i=w[0].i-1;
                    w[3].j=w[0].j+1;
                    w[4].i=w[0].i-1;
                    w[4].j=w[0].j+2;
                    fz();                  //���µ�ѡ��Ԫ�ظ�ֵ������Ļ����ʾ
                    return 1;
                }
 
            }
            else if(style==3)   //��L��3������
            {
                if(w[0].j+1<jmax&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0&&c(w[0].i-2,w[0].j)->state>=0&&c(w[0].i-2,w[0].j+1)->state>=0)
                {
                    nowone.style=style;     //������ʽ
                    clc();                  //��ԭԭѡ��Ԫ�ص�ֵ������Ļ�����
                    w[1].i=w[0].i;          //ѡ���µ�Ԫ��
                    w[1].j=w[0].j+1;
                    w[2].i=w[0].i-1;
                    w[2].j=w[0].j+1;
                    w[3].i=w[0].i-2;
                    w[3].j=w[0].j;
                    w[4].i=w[0].i-2;
                    w[4].j=w[0].j+1;
                    fz();                  //���µ�ѡ��Ԫ�ظ�ֵ������Ļ����ʾ
                    return 1;
                }
 
            }
            else if(style==4)    //��L��4������
            {
                if(w[0].j+2<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i,w[0].j+2)->state>=0&&c(w[0].i-1,w[0].j+2)->state>=0)
                {
                    nowone.style=style;     //������ʽ
                    clc();                  //��ԭԭѡ��Ԫ�ص�ֵ������Ļ�����
                    w[1].i=w[0].i;          //ѡ���µ�Ԫ��
                    w[1].j=w[0].j;
                    w[2].i=w[0].i;
                    w[2].j=w[0].j+1;
                    w[3].i=w[0].i;
                    w[3].j=w[0].j+2;
                    w[4].i=w[0].i-1;
                    w[4].j=w[0].j+2;
                    fz();                  //���µ�ѡ��Ԫ�ظ�ֵ������Ļ����ʾ
                    return 1;
                }
 
            }
        }
    }
    return 0;
}
 
/*��ֵ��ǰ����λ�ò���ʾ*/
int appear(void)
{
    int k=0,style=nowone.style;
    if(nowone.state==1&&nowone.style==1)
    {
        if(w[0].j+1<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0)
        {
            clc();
            w[1].i=w[0].i;          //ѡ���µ�Ԫ��
            w[1].j=w[0].j;
            w[2].i=w[0].i;
            w[2].j=w[0].j+1;
            w[3].i=w[0].i-1;
            w[3].j=w[0].j;
            w[4].i=w[0].i-1;
            w[4].j=w[0].j+1;
            fz();
            return 1;
        }
    }
    else if(nowone.state==2)
    {
        if(style==1)        //����1:��
        {
            if(w[0].j<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-2,w[0].j)->state>=0&&c(w[0].i-3,w[0].j)->state>=0) //�ж��Ϸ��Ƿ�ռ��㹻
            {
                clc();                  //��ԭԭѡ��Ԫ�ص�ֵ������Ļ�����
                for(k=1; k<=4; k++)      //ѡ���µ�Ԫ��
                {
                    w[k].i=w[0].i-k+1;
                    w[k].j=w[0].j;
                }
                fz();                //���µ�ѡ��Ԫ�ظ�ֵ������Ļ����ʾ
                return 1;
            }
        }
        else if(style==2)   //����2:����
        {
            if(w[0].j+3<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i,w[0].j+2)->state>=0&&c(w[0].i,w[0].j+3)->state>=0)  //�ж��ҷ��ռ��Ƿ��㹻
            {
                clc();                  //��ԭԭѡ��Ԫ�ص�ֵ������Ļ�����
                for(k=1; k<=4; k++)     //ѡ���µ�Ԫ��
                {
                    w[k].i=w[0].i;
                    w[k].j=w[0].j+k-1;
                }
                fz();                  //���µ�ѡ��Ԫ�ظ�ֵ������Ļ����ʾ
                return 1;
            }
        }
    }
    else if(nowone.state==3)
    {
        if(style==1)                   //z��1:��
        {
            if(w[0].j+2<jmax&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i,w[0].j+2)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0)
            {
                clc();                  //��ԭԭѡ��Ԫ�ص�ֵ������Ļ�����
                w[1].i=w[0].i;          //ѡ���µ�Ԫ��
                w[1].j=w[0].j+1;
                w[2].i=w[0].i;
                w[2].j=w[0].j+2;
                w[3].i=w[0].i-1;
                w[3].j=w[0].j;
                w[4].i=w[0].i-1;
                w[4].j=w[0].j+1;
                fz();                  //���µ�ѡ��Ԫ�ظ�ֵ������Ļ����ʾ
                return 1;
            }
 
        }
        else if(style==2)            //z��2:��
        {
            if(w[0].j+1<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0&&c(w[0].i-2,w[0].j+1)->state>=0)
            {
                clc();                  //��ԭԭѡ��Ԫ�ص�ֵ������Ļ�����
                w[1].i=w[0].i;          //ѡ���µ�Ԫ��
                w[1].j=w[0].j;
                w[2].i=w[0].i-1;
                w[2].j=w[0].j;
                w[3].i=w[0].i-1;
                w[3].j=w[0].j+1;
                w[4].i=w[0].i-2;
                w[4].j=w[0].j+1;
                fz();                  //���µ�ѡ��Ԫ�ظ�ֵ������Ļ����ʾ
                return 1;
            }
 
        }
    }
    else if(nowone.state==4)
    {
        if(style==1)                   //s��1:��
        {
            if(w[0].j+2<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0&&c(w[0].i-1,w[0].j+2)->state>=0)
            {
                clc();                  //��ԭԭѡ��Ԫ�ص�ֵ������Ļ�����
                w[1].i=w[0].i;          //ѡ���µ�Ԫ��
                w[1].j=w[0].j;
                w[2].i=w[0].i;
                w[2].j=w[0].j+1;
                w[3].i=w[0].i-1;
                w[3].j=w[0].j+1;
                w[4].i=w[0].i-1;
                w[4].j=w[0].j+2;
                fz();                  //���µ�ѡ��Ԫ�ظ�ֵ������Ļ����ʾ
                return 1;
            }
        }
        else if(style==2)            //s��2:��
        {
            if(w[0].j+1<jmax&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0&&c(w[0].i-2,w[0].j)->state>=0)
            {
                clc();                  //��ԭԭѡ��Ԫ�ص�ֵ������Ļ�����
                w[1].i=w[0].i;          //ѡ���µ�Ԫ��
                w[1].j=w[0].j+1;
                w[2].i=w[0].i-1;
                w[2].j=w[0].j;
                w[3].i=w[0].i-1;
                w[3].j=w[0].j+1;
                w[4].i=w[0].i-2;
                w[4].j=w[0].j;
                fz();                  //���µ�ѡ��Ԫ�ظ�ֵ������Ļ����ʾ
                return 1;
            }
        }
    }
    else
    {
        style=nowone.style;
        if(nowone.state==5)
        {
            if(style==1)
            {
                if(w[0].j+2<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i,w[0].j+2)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0)
                {
                    clc();                  //��ԭԭѡ��Ԫ�ص�ֵ������Ļ�����
                    w[1].i=w[0].i;          //ѡ���µ�Ԫ��
                    w[1].j=w[0].j;
                    w[2].i=w[0].i;
                    w[2].j=w[0].j+1;
                    w[3].i=w[0].i;
                    w[3].j=w[0].j+2;
                    w[4].i=w[0].i-1;
                    w[4].j=w[0].j+1;
                    fz();                  //���µ�ѡ��Ԫ�ظ�ֵ������Ļ����ʾ
                    return 1;
                }
 
            }
            else if(style==2)
            {
 
                if(w[0].j+1<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0&&c(w[0].i-2,w[0].j)->state>=0)
                {
                    clc();                  //��ԭԭѡ��Ԫ�ص�ֵ������Ļ�����
                    w[1].i=w[0].i;          //ѡ���µ�Ԫ��
                    w[1].j=w[0].j;
                    w[2].i=w[0].i-1;
                    w[2].j=w[0].j;
                    w[3].i=w[0].i-1;
                    w[3].j=w[0].j+1;
                    w[4].i=w[0].i-2;
                    w[4].j=w[0].j;
                    fz();                  //���µ�ѡ��Ԫ�ظ�ֵ������Ļ����ʾ
                    return 1;
                }
 
            }
            else if(style==3)
            {
                if(w[0].j+2<jmax&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0&&c(w[0].i-1,w[0].j+2)->state>=0)
                {
                    clc();                  //��ԭԭѡ��Ԫ�ص�ֵ������Ļ�����
                    w[1].i=w[0].i;          //ѡ���µ�Ԫ��
                    w[1].j=w[0].j+1;
                    w[2].i=w[0].i-1;
                    w[2].j=w[0].j;
                    w[3].i=w[0].i-1;
                    w[3].j=w[0].j+1;
                    w[4].i=w[0].i-1;
                    w[4].j=w[0].j+2;
                    fz();                  //���µ�ѡ��Ԫ�ظ�ֵ������Ļ����ʾ
                    return 1;
                }
            }
            else if(style==4)
            {
                if(w[0].j+1<jmax&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0&&c(w[0].i-2,w[0].j+1)->state>=0)
                {
                    clc();                  //��ԭԭѡ��Ԫ�ص�ֵ������Ļ�����
                    w[1].i=w[0].i;          //ѡ���µ�Ԫ��
                    w[1].j=w[0].j+1;
                    w[2].i=w[0].i-1;
                    w[2].j=w[0].j;
                    w[3].i=w[0].i-1;
                    w[3].j=w[0].j+1;
                    w[4].i=w[0].i-2;
                    w[4].j=w[0].j+1;
                    fz();                  //���µ�ѡ��Ԫ�ظ�ֵ������Ļ����ʾ
                    return 1;
                }
            }
        }
        else if(nowone.state==6)
        {
            if(style==1)
            {
                if(w[0].j+1<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0&&c(w[0].i-2,w[0].j+1)->state>=0)
                {
                    clc();                  //��ԭԭѡ��Ԫ�ص�ֵ������Ļ�����
                    w[1].i=w[0].i;          //ѡ���µ�Ԫ��
                    w[1].j=w[0].j;
                    w[2].i=w[0].i;
                    w[2].j=w[0].j+1;
                    w[3].i=w[0].i-1;
                    w[3].j=w[0].j+1;
                    w[4].i=w[0].i-2;
                    w[4].j=w[0].j+1;
                    fz();                  //���µ�ѡ��Ԫ�ظ�ֵ������Ļ����ʾ
                    return 1;
                }
            }
            else if(style==2)
            {
                if(w[0].j+2<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i,w[0].j+2)->state>=0&&c(w[0].i-1,w[0].j)->state>=0)
                {
                    clc();                  //��ԭԭѡ��Ԫ�ص�ֵ������Ļ�����
                    w[1].i=w[0].i;          //ѡ���µ�Ԫ��
                    w[1].j=w[0].j;
                    w[2].i=w[0].i;
                    w[2].j=w[0].j+1;
                    w[3].i=w[0].i;
                    w[3].j=w[0].j+2;
                    w[4].i=w[0].i-1;
                    w[4].j=w[0].j;
                    fz();                  //���µ�ѡ��Ԫ�ظ�ֵ������Ļ����ʾ
                    return 1;
                }
            }
            else if(style==3)
            {
                if(w[0].j+1<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-2,w[0].j)->state>=0&&c(w[0].i-2,w[0].j+1)->state>=0)
                {
                    clc();                  //��ԭԭѡ��Ԫ�ص�ֵ������Ļ�����
                    w[1].i=w[0].i;          //ѡ���µ�Ԫ��
                    w[1].j=w[0].j;
                    w[2].i=w[0].i-1;
                    w[2].j=w[0].j;
                    w[3].i=w[0].i-2;
                    w[3].j=w[0].j;
                    w[4].i=w[0].i-2;
                    w[4].j=w[0].j+1;
                    fz();                  //���µ�ѡ��Ԫ�ظ�ֵ������Ļ����ʾ
                    return 1;
                }
 
            }
            else if(style==4)
            {
                if(w[0].j+2<jmax&&c(w[0].i,w[0].j+2)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0&&c(w[0].i-1,w[0].j+2)->state>=0)
                {
                    clc();                  //��ԭԭѡ��Ԫ�ص�ֵ������Ļ�����
                    w[1].i=w[0].i;          //ѡ���µ�Ԫ��
                    w[1].j=w[0].j+2;
                    w[2].i=w[0].i-1;
                    w[2].j=w[0].j;
                    w[3].i=w[0].i-1;
                    w[3].j=w[0].j+1;
                    w[4].i=w[0].i-1;
                    w[4].j=w[0].j+2;
                    fz();                  //���µ�ѡ��Ԫ�ظ�ֵ������Ļ����ʾ
                    return 1;
                }
 
            }
        }
        else if(nowone.state==7)
        {
            if(style==1)
            {
                if(w[0].j+1<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-2,w[0].j)->state>=0)
                {
                    clc();                  //��ԭԭѡ��Ԫ�ص�ֵ������Ļ�����
                    w[1].i=w[0].i;          //ѡ���µ�Ԫ��
                    w[1].j=w[0].j;
                    w[2].i=w[0].i;
                    w[2].j=w[0].j+1;
                    w[3].i=w[0].i-1;
                    w[3].j=w[0].j;
                    w[4].i=w[0].i-2;
                    w[4].j=w[0].j;
                    fz();                  //���µ�ѡ��Ԫ�ظ�ֵ������Ļ����ʾ
                    return 1;
                }
 
            }
            else if(style==2)
            {
                if(w[0].j+2<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0&&c(w[0].i-1,w[0].j+2)->state>=0)
                {
                    clc();                  //��ԭԭѡ��Ԫ�ص�ֵ������Ļ�����
                    w[1].i=w[0].i;          //ѡ���µ�Ԫ��
                    w[1].j=w[0].j;
                    w[2].i=w[0].i-1;
                    w[2].j=w[0].j;
                    w[3].i=w[0].i-1;
                    w[3].j=w[0].j+1;
                    w[4].i=w[0].i-1;
                    w[4].j=w[0].j+2;
                    fz();                  //���µ�ѡ��Ԫ�ظ�ֵ������Ļ����ʾ
                    return 1;
                }
 
            }
            else if(style==3)
            {
                if(w[0].j+1<jmax&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0&&c(w[0].i-2,w[0].j)->state>=0&&c(w[0].i-2,w[0].j+1)->state>=0)
                {
                    clc();                  //��ԭԭѡ��Ԫ�ص�ֵ������Ļ�����
                    w[1].i=w[0].i;          //ѡ���µ�Ԫ��
                    w[1].j=w[0].j+1;
                    w[2].i=w[0].i-1;
                    w[2].j=w[0].j+1;
                    w[3].i=w[0].i-2;
                    w[3].j=w[0].j;
                    w[4].i=w[0].i-2;
                    w[4].j=w[0].j+1;
                    fz();                  //���µ�ѡ��Ԫ�ظ�ֵ������Ļ����ʾ
                    return 1;
                }
 
            }
            else if(style==4)
            {
                if(w[0].j+2<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i,w[0].j+2)->state>=0&&c(w[0].i-1,w[0].j+2)->state>=0)
                {
                    clc();                  //��ԭԭѡ��Ԫ�ص�ֵ������Ļ�����
                    w[1].i=w[0].i;          //ѡ���µ�Ԫ��
                    w[1].j=w[0].j;
                    w[2].i=w[0].i;
                    w[2].j=w[0].j+1;
                    w[3].i=w[0].i;
                    w[3].j=w[0].j+2;
                    w[4].i=w[0].i-1;
                    w[4].j=w[0].j+2;
                    fz();                  //���µ�ѡ��Ԫ�ظ�ֵ������Ļ����ʾ
                    return 1;
                }
 
            }
        }
    }
    return 0;
}
 
/*��Ϸ����*/
void maingame()
{
    int i=0,j=0,str=0;
    long time=clock();
    cleanall();
    appear();
    while(1)
    {
 
        if(clock()-time>speed)  //clock()%speed==0
        {
            time=clock();
            //check();
            if(fall())
            {
                eliminate();
                //getchar();
                nowscreen(); //ˢ����Ļ
                if(judge()==-1)
                {
                    gotoxy(0,23);
                    textcolor(color);
                    printf("You Lost!");
                    return ;
                }
                nowone=ready;
                newobject();
                if(appear()==0)
                {
                    gotoxy(0,23);
                    textcolor(color);
                    printf("You Lost!");
                    return ;
                }
            }
            // �ȼ��ж� ��ʾԤ��ͼ��
        }
        else
        {
            if(_kbhit())
            {
                str=getch();
                if(str==224)
                {
                    str=getch();
                    if(str==72)       //�������: ����
                    {
                        mainchange();
                    }
                    else if(str==80)  //�������:��������
                    {
                        if(fall())
                        {
                            eliminate();
                            nowscreen();
                            if(judge()==-1)
                            {
                                gotoxy(0,23);
                                textcolor(color);
                                printf("You Lost!");
                                return ;
                            }
                            nowone=ready;
                            newobject();
                            if(appear()==0)
                            {
                                gotoxy(0,23);
                                textcolor(color);
                                printf("You Lost!");
                                return ;
                            }
                        }
                    }
                    else if(str==75)  //�������:�����ƶ�
                    {
                        goleft();
                    }
                    else if(str==77)  //�������:�����ƶ�
                    {
                        goright();
                    }
                }
                else if(str=='\r')    //�س���ͣ
                {
                    getch();
                }
                else if(str==' ')     //ֱ������
                {
                    while(!fall());
                    eliminate();
                    nowscreen();
                    if(judge()==-1)
                    {
                        gotoxy(0,23);
                        textcolor(color);
                        printf("You Lost!");
                        return ;
                    }
                    nowone=ready;
                    newobject();
                    if(appear()==0)
                    {
                        gotoxy(0,23);
                        textcolor(color);
                        printf("You Lost!");
                        return ;
                    }
                }
                else if(str==27)      //ESC:�˳�
                {
                    return ;
                }
                else if(str=='c'||str=='C')       //C���������:�鿴�����Լ���ʱ�ؼ�������ֵ
                {
                    check();
                }
                else if(str=='s'||str=='S')      //S���������:�鿴��ʱ����Ӧ��ʾ�Ľ��
                {
                    nowscreen();
                    getch();
                }
                else if(str=='r'||str=='R')       //R��
                {
                    cleanall();
                    appear();
                    str=0;
                }
            }
            //check();
        }
    }
    return ;
}
 
/*������������*/
void newobject(void)
{
    unit newone;
    newone.color=rand(240,254);
    newone.event=0;                  //���ڿ���ӹ��ܵ���
    newone.state=rand(1,7);
    if(newone.state==1)
    {
        newone.style=1;
    }
    else if(newone.state==2||newone.state==3||newone.state==4)
    {
        newone.style=rand(1,2);
    }
    else if(newone.state==5||newone.state==6||newone.state==7)
    {
        newone.style=rand(1,4);
    }
    /*
    w.i=3;
    w.j=(jmax-1)/2;
    */
    ready=newone;
    return ;
}
 
/*�жϲ�����*/
void mainchange(void)
{
    int style=0,l=0,k=0,jbefore=0;
    jbefore=w[0].j;
    if(nowone.state==1)
    {
        change();
    }
    else if(nowone.state==2)
    {
        if(nowone.style==1&&w[0].j>=jmax-3&&w[0].j<=jmax-1)
        {
            w[0].j=jmax-4;
            if(!change())
            {
                w[0].j=jbefore;
            }
        }
        else
        {
            change();
        }
    }
    else if(nowone.state>=3&&nowone.state<=7)
    {
        if(w[0].j==jmax-2)
        {
            --w[0].j;
            if(!change())
            {
                ++w[0].j;
            }
        }
        else
        {
            change();
        }
    }
    return ;
}
 
/*�����ƶ�*/
int goleft(void)
{
    int i=0;
    if(w[0].j>0&&c(w[1].i,w[1].j-1)->state>=0&&c(w[2].i,w[2].j-1)->state>=0&&c(w[3].i,w[3].j-1)->state>=0&&c(w[4].i,w[4].j-1)->state>=0)
    {
        clc();
        for(i=0; i<5; i++)
            --w[i].j;
        fz();
        return 1;
    }
    return 0;
}
 
/*�����ƶ�*/
int goright(void)
{
    int i=0;
    if(w[0].j+1>=jmax)
        return 0;
    for(i=1; i<5; i++)
    {
        if(w[i].j+1>=jmax||c(w[i].i,w[i].j+1)->state<0)
            return 0;
    }
    clc();
    for(i=0; i<5; i++)
        ++w[i].j;
    fz();
    return 1;
}
 
/*ֹͣ��������*/
void stop(void)
{
    int i=0;
    for(i=1; i<=4; i++)
    {
        c(w[i].i,w[i].j)->state=-1;
    }
    w[0].i=4;
    w[0].j=(jmax-1)/2;
    for(i=1; i<5; i++)
        w[i]=w[0];
    return ;
}
 
/*����*/
int fall(void)
{
    int i=0;
    if(w[0].i+1>=imax)
    {
        stop();
        return 1;
    }
    for(i=1; i<5; i++)
    {
        if(w[i].i+1>=imax||c(w[i].i+1,w[i].j)->state<0)
            break;
    }
    if(i<5)
    {
        stop();
        return 1;
    }
    else
    {
        clc();
        for(i=0; i<5; i++)
        {
            ++w[i].i;
        }
        fz();
        return 0;
    }
}
 
/*��Ϸ�ж�*/
int judge(void)
{
    int i=0,j=0;
    for(i=0; i<4; i++)
        for(j=0; j<jmax; j++)
            if(c(i,j)->state==-1)
                return -1;
    return 0;
}
 
/*----------------------ͼ�κ���------------------------*/
 
/*���溯��. Ϊ����ʾЧ�������longth��ʹ��ż��,�߶Ȳ�Ӧ����23. ʹ�÷���: window(240, 10, 0, 30,23); window(240, 40, 0, 16,10);   window(240, 40, 10, 16,13); */
void window(int color, int xw, int yw, int longth, int high)
{
    int i = 0, j = 0;
    ycgb();
    textcolor(191);
    //textcolor(color);
    /*
    gotoxy(xw, yw);
    printf("��");
    for (i = 0; i < (longth - 4) / 2; i++)
    {
        printf("��");
    }
    printf("��");
    */
    for (j = 0; j < high - 2; j++)
    {
        textcolor(191);
        gotoxy(xw, yw + j + 1);
        printf("��");
        textcolor(color);
        for (i = 0; i < longth - 4; i++)
        {
            printf(" ");
        }
        textcolor(191);
        printf("��");
    }
    textcolor(251);
 
    gotoxy(xw, yw + j + 1);
    printf("��");
    for (i = 0; i < (longth - 4) / 2; i++)
    {
        printf("��");
    }
    printf("��");
    gotoxy(0, 0);
    return ;
}
 
/*��Ԫ����*/
void clean(unit* u0,int color)
{
    u0->color=color;
    u0->event=0;
    u0->state=0;
    u0->style=0;
}
 
/*ȫ������*/
void cleanall(void)
{
    int i=0,j=0;
    score=0;
    textcolor(240);
    system("cls");
    window(color, x0, y0, longth, high);
    for(i=0; i<imax; i++)
        for(j=0; j<jmax; j++)
        {
            clean(c(i,j),color);
        }
    w[0].i=4;
    w[0].j=(jmax-1)/2;
    for(i=1; i<5; i++)
    {
        w[i]=w[0];
    }
    newobject();
    nowone=ready;
    newobject();
    return ;
}
 
/*��ʾ��ǰ����*/
void nowscreen(void)
{
    int i=0,j=0;
    for(i=4; i<imax; i++)
    {
        for(j=0; j<jmax; j++)
        {
            ts(i,j);
            gotoxy(xs,ys);
            if(c(i,j)->state!=0)
            {
                textcolor(c(i,j)->color);
                //if(c(i,j)->color==color)
                //printf("��");
                printf("��");
                //getchar();
            }
            else
            {
                textcolor(color);
                printf("  ");
            }
        }
    }
    //gotoxy(22,8);
    //printf(" state=%d color=%d style=%d event=%d",c(23,5)->state,c(23,5)->color,c(23,5)->style,c(23,5)->event);
    return ;
}
 
/*����������*/
void check(void)
{
    int i,j;
    gotoxy((jmax+2)*2+2,0);
    textcolor(240);
    for(i=0; i<imax; i++)
    {
        gotoxy((jmax+2)*2+2,i);
        printf("[%2d]   ",i);
        for(j=0; j<jmax; j++)
            printf(" %2d ",c(i,j)->state);
    }
    gotoxy((jmax+2)*2+2+6+1,i);
    for(j=0; j<jmax; j++)
        printf(" [%d]",j);
 
    gotoxy(0,i+1+1);
    for(i=0; i<5; i++)
        printf(" w[%d]=[%d %d]     ",i,w[i].i,w[i].j);
    printf("\n\n nowone:   state=%2d   stytle=%d   color=%3d   event=%d    ",nowone.state,nowone.style,nowone.color,nowone.event);
    printf("\n\n ready:    state=%2d   stytle=%d   color=%3d   event=%d    ",ready.state,ready.style,ready.color,ready.event);
    printf("\n\n w0[%d][%d]: state=%2d   stytle=%d   color=%3d   event=%d    ",w[0].i,w[0].j,c(w[0].i,w[0].j)->state,c(w[0].i,w[0].j)->style,c(w[0].i,w[0].j)->color,c(w[0].i,w[0].j)->event);
    printf("\n\n o[%d][%d]:  state=%2d   stytle=%d   color=%3d   event=%d    ",4,(jmax-1)/2,c(4,(jmax-1)/2)->state,c(4,(jmax-1)/2)->style,c(4,(jmax-1)/2)->color,c(4,(jmax-1)/2)->event);
    getch();
    return ;
}
 
/*��ʼ����*/
void begain(void)
{
    int i=0,j=0,str=0,ch=0;
    textcolor(248);
    system("cls");
    gotoxy(0,3);
    for(i=0; i<40; i++)
    {
        Sleep(5);
        printf("��");
    }
    for(i=0; i<23; i++)
    {
        gotoxy(20,i);
        Sleep(i);
        if(i!=3)
            printf("��");
        else
            printf("��");
    }
    gotoxy(60,2);
    printf("����˹����");
    gotoxy(66,10);
    printf("start");
    gotoxy(66,13);
    printf("loading");
    gotoxy(66,16);
    printf("about");
    gotoxy(66,19);
    printf("exit");
    getch();
    ch=1;
    gotoxy(66,10);
    printf("Start");
    gotoxy(66,11);
    for(i=0; i<4; i++)
    {
        printf("��");
        Sleep(30);
    }
    while(1)
    {
        str=getch();
        if(str==224)
        {
            str=getch();
            if(str==72)
            {
                --ch;
                if(ch<=0)
                    ch=4;
            }
            else if(str==80)
            {
                ++ch;
                if(ch>4)
                    ch=1;
            }
            gotoxy(66,10);
            printf("start");
            gotoxy(60,11);
            printf("                ");
            gotoxy(66,13);
            printf("loading");
            gotoxy(60,14);
            printf("                ");
            gotoxy(66,16);
            printf("about");
            gotoxy(60,17);
            printf("                ");
            gotoxy(66,19);
            printf("exit");
            gotoxy(60,20);
            printf("                ");
            if(ch==1)
            {
                gotoxy(66,10);
                printf("Start");
                gotoxy(66,11);
                for(i=0; i<4; i++)
                {
                    printf("��");
                    Sleep(30);
                }
            }
            else if(ch==2)
            {
                gotoxy(66,13);
                printf("Loading");
                gotoxy(66,14);
                for(i=0; i<4; i++)
                {
                    printf("��");
                    Sleep(30);
                }
 
            }
            else if(ch==3)
            {
                gotoxy(66,16);
                printf("About");
                gotoxy(66,17);
                for(i=0; i<4; i++)
                {
                    printf("��");
                    Sleep(30);
                }
            }
            else if(ch==4)
            {
                gotoxy(66,19);
                printf("Exit");
                gotoxy(66,20);
                for(i=0; i<4; i++)
                {
                    printf("��");
                    Sleep(30);
                }
            }
 
        }
        else if(str=='\r')
        {
            gotoxy(60,2);
            printf("              ");
            gotoxy(66,10);
            printf("                ");
            gotoxy(60,11);
            printf("                ");
            gotoxy(66,13);
            printf("                ");
            gotoxy(60,14);
            printf("                ");
            gotoxy(66,16);
            printf("                ");
            gotoxy(60,17);
            printf("                ");
            gotoxy(66,19);
            printf("                ");
            gotoxy(60,20);
            printf("                ");
            for(i=0; i<23; i++)
            {
                gotoxy(20,i);
                Sleep(2);
                if(i!=3)
                    printf("  ");
                else
                    printf("��");
            }
            gotoxy(0,3);
            for(i=0; i<40; i++)
            {
                Sleep(1);
                printf("    ");
            }
            textcolor(240);
            system("cls");
            gotoxy(0,0);
            if(ch==1)
            {
                maingame();
            }
            else if(ch==4)
            {
                return ;
            }
        }
    }
 
    return ;
}
/*-----------------------������-------------------------*/
int main(void)
{
    int i=0,j=0;
    char str;
    scoremax=0;
    jmax=(longth-4)/2;
    imax=high-2+4;
    pmax=jmax*imax;
    srand((int)time(0));
    ycgb();
    p=(unit*)malloc(jmax*imax*sizeof(unit));
    begain();
 
    //maingame();
    gotoxy(0,23);
    free(p);
    return 0;
}
 
/*
------------------------���ֲ��Բο�-----------------------
��ʾ���ֻ���ͼ��
printf("�����ש���\n��  ��  ��\n�ǩ��贈��\n��  ��  ��\n�����ߩ���\n���� ����\n���� ����\n");
�Ʊ��
�����ש���
��  ��  ��
�����ߩ���
�����
����
������״
1 ����       1
2 ����       2
3 Z����      2
4 Z����      2
5 ͹��       4
6 L����      4
7 L����      4
    for(i=0; i<imax; i++)
    {
        for(j=0; j<jmax; j++)
        {
            c(i,j)->color=rand(240,254);
            c(i,j)->state=1;
            if(ts(i,j))
            {
                gotoxy(xs,ys);
                textcolor(c(i,j)->color);
                //printf("��");
                printf("��");
            }
        }
        Sleep(50);
    }
    eliminate();
    nowscreen();
*/



