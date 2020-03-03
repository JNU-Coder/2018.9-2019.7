#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
 
/*---------------------结构体声明-----------------------*/
 
/*组成单元结构体*/
typedef struct cell
{
    int color;
    int state;
    int style;
    int event;
} unit;
 
/*位置结构体*/
typedef struct location
{
    int i;
    int j;
} place;
 
/*----------------------全局变量------------------------*/
 
int longth=24,high=23,x0=0,y0=0,xs=0,ys=0,color=240,jmax=0,imax=0,pmax=0,xn=0,yn=0,scoremax=0,score=0,speed=600;
unit now,*p=NULL;
place w[5];
unit ready,nowone;
 
/*----------------------函数声明------------------------*/
 
void textcolor(int color);                                       /*字体颜色*/
void gotoxy(int x, int y);                                       /*移动光标*/
void ycgb(void);                                                 /*隐藏光标*/
void xsgb(void);                                                 /*显示光标*/
void qk(void);                                                   /*无回显清空函数*/
void window(int color, int xw, int yw, int longth, int hight);   /*界面函数*/
int rand(int r_min,int r_max);                                   /*返回随机数*/
void clean(unit* u0,int color);                                  /*单元清零*/
unit* c(int i,int j);                                            /*二维转一维地址*/
int ts(int i,int j);                                             /*数组到屏幕坐标转换*/
int eliminate(void);                                             /*判断并消去一行*/
void nowscreen(void);                                            /*显示当前情形*/
void newobject(void);                                            /*创建下落物体*/
void clc(void);                                                  /*还原原选定元素的值并从屏幕中清除*/
void fz(void);                                                   /*给新的选定元素赋值并在屏幕上显示*/
int change(void);                                                /*对当前数组中的形状进行变换*/
void mainchange(void);                                           /*判断并变形*/
int goleft(void);                                                /*向左移动*/
int goright(void);                                               /*向右移动*/
void stop(void);                                                 /*停止本次下落*/
int fall(void);                                                  /*下落*/
void cleanall(void);                                             /*全部清零*/
int judge(void);                                                 /*游戏判断*/
int appear(void);                                                /*赋值当前物块的位置并显示*/
void check(void);                                                /*辅助纠错函数*/
void begain(void);                                               /*开始界面*/
 
/*----------------------辅助函数------------------------*/
 
/*字体颜色*/
void textcolor(int color)
{
    SetConsoleTextAttribute(hOutput, color);
}
 
/*移动光标*/
void gotoxy(int x, int y)
{
    COORD coordScreen = {0, 0};
    coordScreen.X = x;
    coordScreen.Y = y;
    SetConsoleCursorPosition(hOutput, coordScreen);
}
 
/*隐藏光标*/
void ycgb(void)
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    GetConsoleCursorInfo(hOut, &cci);
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hOut, &cci);
}
 
/*显示光标*/
void xsgb(void)
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    GetConsoleCursorInfo(hOut, &cci);
    cci.bVisible = 1;
    SetConsoleCursorInfo(hOut, &cci);
}
 
/*无回显清空函数*/
void qk(void)
{
    while (_kbhit())
    {
        getch();
    }
    return ;
}
 
/*返回随机数*/
int rand(int r_min,int r_max)
{
    int r=(int)((r_max+1-r_min)* rand() / (RAND_MAX*1.0));
    return r+r_min;
 
}
 
/*二维转一维地址*/
unit* c(int i,int j)
{
    return p+i*jmax+j;
}
 
/*数组到屏幕坐标转换*/
int ts(int i,int j)
{
    if(i<=3)
        return 0;
    xs=j*2+x0+2;
    ys=i-4+y0+1;
    return 1;
}
 
/*判断并消去一行*/
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
 
/*还原原选定元素的值并从屏幕中清除*/
void clc(void)
{
    int k=0;
    textcolor(color);
    for(k=1; k<5; k++)                   //还原原选定元素的值
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
 
/*给新的选定元素赋值并在屏幕上显示*/
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
            printf("█");
        }
    }
    return ;
}
 
/*对当前数组中的形状进行变换，基本坐标
关于判断的标准 1.变形后最右方元素是否发生数组越界  2.四个方块将要所在的位置是否可用
w[0].j<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i,w[0].j)->state>=0
关于赋值:四个全部赋值
注意不要在此基础之上做无把握的化简优化，否则将影响其它功能。
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
            w[1].i=w[0].i;          //选定新的元素
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
        if(style==1)        //长条1:竖
        {
            if(w[0].j<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-2,w[0].j)->state>=0&&c(w[0].i-3,w[0].j)->state>=0) //判断上方是否空间足够
            {
                nowone.style=style;     //更改形式
                clc();                  //还原原选定元素的值并在屏幕上清除
                for(k=1; k<=4; k++)      //选定新的元素
                {
                    w[k].i=w[0].i-k+1;
                    w[k].j=w[0].j;
                }
                fz();                //给新的选定元素赋值并在屏幕上显示
                return 1;
            }
        }
        else if(style==2)   //长条2:横条
        {
            if(w[0].j+3<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i,w[0].j+2)->state>=0&&c(w[0].i,w[0].j+3)->state>=0)  //判断右方空间是否足够
            {
                nowone.style=style;     //更改形式
                clc();                  //还原原选定元素的值并在屏幕上清除
                for(k=1; k<=4; k++)     //选定新的元素
                {
                    w[k].i=w[0].i;
                    w[k].j=w[0].j+k-1;
                }
                fz();                  //给新的选定元素赋值并在屏幕上显示
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
        if(style==1)                   //z型1:左
        {
            if(w[0].j+2<jmax&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i,w[0].j+2)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0)
            {
                nowone.style=style;     //更改形式
                clc();                  //还原原选定元素的值并在屏幕上清除
                w[1].i=w[0].i;          //选定新的元素
                w[1].j=w[0].j+1;
                w[2].i=w[0].i;
                w[2].j=w[0].j+2;
                w[3].i=w[0].i-1;
                w[3].j=w[0].j;
                w[4].i=w[0].i-1;
                w[4].j=w[0].j+1;
                fz();                  //给新的选定元素赋值并在屏幕上显示
                return 1;
            }
 
        }
        else if(style==2)            //z型2:上
        {
            if(w[0].j+1<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0&&c(w[0].i-2,w[0].j+1)->state>=0)
            {
                nowone.style=style;     //更改形式
                clc();                  //还原原选定元素的值并在屏幕上清除
                w[1].i=w[0].i;          //选定新的元素
                w[1].j=w[0].j;
                w[2].i=w[0].i-1;
                w[2].j=w[0].j;
                w[3].i=w[0].i-1;
                w[3].j=w[0].j+1;
                w[4].i=w[0].i-2;
                w[4].j=w[0].j+1;
                fz();                  //给新的选定元素赋值并在屏幕上显示
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
        if(style==1)                   //s型1:右
        {
            if(w[0].j+2<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0&&c(w[0].i-1,w[0].j+2)->state>=0)
            {
                nowone.style=style;     //更改形式
                clc();                  //还原原选定元素的值并在屏幕上清除
                w[1].i=w[0].i;          //选定新的元素
                w[1].j=w[0].j;
                w[2].i=w[0].i;
                w[2].j=w[0].j+1;
                w[3].i=w[0].i-1;
                w[3].j=w[0].j+1;
                w[4].i=w[0].i-1;
                w[4].j=w[0].j+2;
                fz();                  //给新的选定元素赋值并在屏幕上显示
                return 1;
            }
        }
        else if(style==2)            //s型2:上
        {
            if(w[0].j+1<jmax&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0&&c(w[0].i-2,w[0].j)->state>=0)
            {
                nowone.style=style;     //更改形式
                clc();                  //还原原选定元素的值并在屏幕上清除
                w[1].i=w[0].i;          //选定新的元素
                w[1].j=w[0].j+1;
                w[2].i=w[0].i-1;
                w[2].j=w[0].j;
                w[3].i=w[0].i-1;
                w[3].j=w[0].j+1;
                w[4].i=w[0].i-2;
                w[4].j=w[0].j;
                fz();                  //给新的选定元素赋值并在屏幕上显示
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
        if(nowone.state==5)        //凸形
        {
            if(style==1)      //凸形1：上
            {
 
                if(w[0].j+2<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i,w[0].j+2)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0)
                {
                    nowone.style=style;     //更改形式
                    clc();                  //还原原选定元素的值并在屏幕上清除
                    w[1].i=w[0].i;          //选定新的元素
                    w[1].j=w[0].j;
                    w[2].i=w[0].i;
                    w[2].j=w[0].j+1;
                    w[3].i=w[0].i;
                    w[3].j=w[0].j+2;
                    w[4].i=w[0].i-1;
                    w[4].j=w[0].j+1;
                    fz();                  //给新的选定元素赋值并在屏幕上显示
                    return 1;
                }
 
            }
            else if(style==2)      ////凸形2：右
            {
 
                if(w[0].j+1<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0&&c(w[0].i-2,w[0].j)->state>=0)
                {
                    nowone.style=style;     //更改形式
                    clc();                  //还原原选定元素的值并在屏幕上清除
                    w[1].i=w[0].i;          //选定新的元素
                    w[1].j=w[0].j;
                    w[2].i=w[0].i-1;
                    w[2].j=w[0].j;
                    w[3].i=w[0].i-1;
                    w[3].j=w[0].j+1;
                    w[4].i=w[0].i-2;
                    w[4].j=w[0].j;
                    fz();                  //给新的选定元素赋值并在屏幕上显示
                    return 1;
                }
 
            }
            else if(style==3)    //凸形3：下
            {
                if(w[0].j+2<jmax&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0&&c(w[0].i-1,w[0].j+2)->state>=0)
                {
                    nowone.style=style;     //更改形式
                    clc();                  //还原原选定元素的值并在屏幕上清除
                    w[1].i=w[0].i;          //选定新的元素
                    w[1].j=w[0].j+1;
                    w[2].i=w[0].i-1;
                    w[2].j=w[0].j;
                    w[3].i=w[0].i-1;
                    w[3].j=w[0].j+1;
                    w[4].i=w[0].i-1;
                    w[4].j=w[0].j+2;
                    fz();                  //给新的选定元素赋值并在屏幕上显示
                    return 1;
                }
            }
            else if(style==4)   //凸形4：左
            {
                if(w[0].j+1<jmax&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0&&c(w[0].i-2,w[0].j+1)->state>=0)
                {
                    nowone.style=style;     //更改形式
                    clc();                  //还原原选定元素的值并在屏幕上清除
                    w[1].i=w[0].i;          //选定新的元素
                    w[1].j=w[0].j+1;
                    w[2].i=w[0].i-1;
                    w[2].j=w[0].j;
                    w[3].i=w[0].i-1;
                    w[3].j=w[0].j+1;
                    w[4].i=w[0].i-2;
                    w[4].j=w[0].j+1;
                    fz();                  //给新的选定元素赋值并在屏幕上显示
                    return 1;
                }
            }
        }
        else if(nowone.state==6)    //左L形
        {
            if(style==1)       //左L形1：左
            {
                if(w[0].j+1<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0&&c(w[0].i-2,w[0].j+1)->state>=0)
                {
                    nowone.style=style;     //更改形式
                    clc();                  //还原原选定元素的值并在屏幕上清除
                    w[1].i=w[0].i;          //选定新的元素
                    w[1].j=w[0].j;
                    w[2].i=w[0].i;
                    w[2].j=w[0].j+1;
                    w[3].i=w[0].i-1;
                    w[3].j=w[0].j+1;
                    w[4].i=w[0].i-2;
                    w[4].j=w[0].j+1;
                    fz();                  //给新的选定元素赋值并在屏幕上显示
                    return 1;
                }
            }
            else if(style==2)    //左L形2：正躺
            {
                if(w[0].j+2<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i,w[0].j+2)->state>=0&&c(w[0].i-1,w[0].j)->state>=0)
                {
                    nowone.style=style;     //更改形式
                    clc();                  //还原原选定元素的值并在屏幕上清除
                    w[1].i=w[0].i;          //选定新的元素
                    w[1].j=w[0].j;
                    w[2].i=w[0].i;
                    w[2].j=w[0].j+1;
                    w[3].i=w[0].i;
                    w[3].j=w[0].j+2;
                    w[4].i=w[0].i-1;
                    w[4].j=w[0].j;
                    fz();                  //给新的选定元素赋值并在屏幕上显示
                    return 1;
                }
            }
            else if(style==3)    //左L形3：向下
            {
                if(w[0].j+1<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-2,w[0].j)->state>=0&&c(w[0].i-2,w[0].j+1)->state>=0)
                {
                    nowone.style=style;     //更改形式
                    clc();                  //还原原选定元素的值并在屏幕上清除
                    w[1].i=w[0].i;          //选定新的元素
                    w[1].j=w[0].j;
                    w[2].i=w[0].i-1;
                    w[2].j=w[0].j;
                    w[3].i=w[0].i-2;
                    w[3].j=w[0].j;
                    w[4].i=w[0].i-2;
                    w[4].j=w[0].j+1;
                    fz();                  //给新的选定元素赋值并在屏幕上显示
                    return 1;
                }
 
            }
            else if(style==4)   //左L形4：倒躺
            {
                if(w[0].j+2<jmax&&c(w[0].i,w[0].j+2)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0&&c(w[0].i-1,w[0].j+2)->state>=0)
                {
                    nowone.style=style;     //更改形式
                    clc();                  //还原原选定元素的值并在屏幕上清除
                    w[1].i=w[0].i;          //选定新的元素
                    w[1].j=w[0].j+2;
                    w[2].i=w[0].i-1;
                    w[2].j=w[0].j;
                    w[3].i=w[0].i-1;
                    w[3].j=w[0].j+1;
                    w[4].i=w[0].i-1;
                    w[4].j=w[0].j+2;
                    fz();                  //给新的选定元素赋值并在屏幕上显示
                    return 1;
                }
 
            }
        }
        else if(nowone.state==7)   //右L形
        {
            if(style==1)     //右L形1：向上
            {
                if(w[0].j+1<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-2,w[0].j)->state>=0)
                {
                    nowone.style=style;     //更改形式
                    clc();                  //还原原选定元素的值并在屏幕上清除
                    w[1].i=w[0].i;          //选定新的元素
                    w[1].j=w[0].j;
                    w[2].i=w[0].i;
                    w[2].j=w[0].j+1;
                    w[3].i=w[0].i-1;
                    w[3].j=w[0].j;
                    w[4].i=w[0].i-2;
                    w[4].j=w[0].j;
                    fz();                  //给新的选定元素赋值并在屏幕上显示
                    return 1;
                }
 
            }
            else if(style==2)     //右L形2：倒躺
            {
                if(w[0].j+2<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0&&c(w[0].i-1,w[0].j+2)->state>=0)
                {
                    nowone.style=style;     //更改形式
                    clc();                  //还原原选定元素的值并在屏幕上清除
                    w[1].i=w[0].i;          //选定新的元素
                    w[1].j=w[0].j;
                    w[2].i=w[0].i-1;
                    w[2].j=w[0].j;
                    w[3].i=w[0].i-1;
                    w[3].j=w[0].j+1;
                    w[4].i=w[0].i-1;
                    w[4].j=w[0].j+2;
                    fz();                  //给新的选定元素赋值并在屏幕上显示
                    return 1;
                }
 
            }
            else if(style==3)   //右L形3：向下
            {
                if(w[0].j+1<jmax&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0&&c(w[0].i-2,w[0].j)->state>=0&&c(w[0].i-2,w[0].j+1)->state>=0)
                {
                    nowone.style=style;     //更改形式
                    clc();                  //还原原选定元素的值并在屏幕上清除
                    w[1].i=w[0].i;          //选定新的元素
                    w[1].j=w[0].j+1;
                    w[2].i=w[0].i-1;
                    w[2].j=w[0].j+1;
                    w[3].i=w[0].i-2;
                    w[3].j=w[0].j;
                    w[4].i=w[0].i-2;
                    w[4].j=w[0].j+1;
                    fz();                  //给新的选定元素赋值并在屏幕上显示
                    return 1;
                }
 
            }
            else if(style==4)    //右L形4：正躺
            {
                if(w[0].j+2<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i,w[0].j+2)->state>=0&&c(w[0].i-1,w[0].j+2)->state>=0)
                {
                    nowone.style=style;     //更改形式
                    clc();                  //还原原选定元素的值并在屏幕上清除
                    w[1].i=w[0].i;          //选定新的元素
                    w[1].j=w[0].j;
                    w[2].i=w[0].i;
                    w[2].j=w[0].j+1;
                    w[3].i=w[0].i;
                    w[3].j=w[0].j+2;
                    w[4].i=w[0].i-1;
                    w[4].j=w[0].j+2;
                    fz();                  //给新的选定元素赋值并在屏幕上显示
                    return 1;
                }
 
            }
        }
    }
    return 0;
}
 
/*赋值当前物块的位置并显示*/
int appear(void)
{
    int k=0,style=nowone.style;
    if(nowone.state==1&&nowone.style==1)
    {
        if(w[0].j+1<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0)
        {
            clc();
            w[1].i=w[0].i;          //选定新的元素
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
        if(style==1)        //长条1:竖
        {
            if(w[0].j<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-2,w[0].j)->state>=0&&c(w[0].i-3,w[0].j)->state>=0) //判断上方是否空间足够
            {
                clc();                  //还原原选定元素的值并在屏幕上清除
                for(k=1; k<=4; k++)      //选定新的元素
                {
                    w[k].i=w[0].i-k+1;
                    w[k].j=w[0].j;
                }
                fz();                //给新的选定元素赋值并在屏幕上显示
                return 1;
            }
        }
        else if(style==2)   //长条2:横条
        {
            if(w[0].j+3<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i,w[0].j+2)->state>=0&&c(w[0].i,w[0].j+3)->state>=0)  //判断右方空间是否足够
            {
                clc();                  //还原原选定元素的值并在屏幕上清除
                for(k=1; k<=4; k++)     //选定新的元素
                {
                    w[k].i=w[0].i;
                    w[k].j=w[0].j+k-1;
                }
                fz();                  //给新的选定元素赋值并在屏幕上显示
                return 1;
            }
        }
    }
    else if(nowone.state==3)
    {
        if(style==1)                   //z型1:左
        {
            if(w[0].j+2<jmax&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i,w[0].j+2)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0)
            {
                clc();                  //还原原选定元素的值并在屏幕上清除
                w[1].i=w[0].i;          //选定新的元素
                w[1].j=w[0].j+1;
                w[2].i=w[0].i;
                w[2].j=w[0].j+2;
                w[3].i=w[0].i-1;
                w[3].j=w[0].j;
                w[4].i=w[0].i-1;
                w[4].j=w[0].j+1;
                fz();                  //给新的选定元素赋值并在屏幕上显示
                return 1;
            }
 
        }
        else if(style==2)            //z型2:上
        {
            if(w[0].j+1<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0&&c(w[0].i-2,w[0].j+1)->state>=0)
            {
                clc();                  //还原原选定元素的值并在屏幕上清除
                w[1].i=w[0].i;          //选定新的元素
                w[1].j=w[0].j;
                w[2].i=w[0].i-1;
                w[2].j=w[0].j;
                w[3].i=w[0].i-1;
                w[3].j=w[0].j+1;
                w[4].i=w[0].i-2;
                w[4].j=w[0].j+1;
                fz();                  //给新的选定元素赋值并在屏幕上显示
                return 1;
            }
 
        }
    }
    else if(nowone.state==4)
    {
        if(style==1)                   //s型1:右
        {
            if(w[0].j+2<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0&&c(w[0].i-1,w[0].j+2)->state>=0)
            {
                clc();                  //还原原选定元素的值并在屏幕上清除
                w[1].i=w[0].i;          //选定新的元素
                w[1].j=w[0].j;
                w[2].i=w[0].i;
                w[2].j=w[0].j+1;
                w[3].i=w[0].i-1;
                w[3].j=w[0].j+1;
                w[4].i=w[0].i-1;
                w[4].j=w[0].j+2;
                fz();                  //给新的选定元素赋值并在屏幕上显示
                return 1;
            }
        }
        else if(style==2)            //s型2:上
        {
            if(w[0].j+1<jmax&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0&&c(w[0].i-2,w[0].j)->state>=0)
            {
                clc();                  //还原原选定元素的值并在屏幕上清除
                w[1].i=w[0].i;          //选定新的元素
                w[1].j=w[0].j+1;
                w[2].i=w[0].i-1;
                w[2].j=w[0].j;
                w[3].i=w[0].i-1;
                w[3].j=w[0].j+1;
                w[4].i=w[0].i-2;
                w[4].j=w[0].j;
                fz();                  //给新的选定元素赋值并在屏幕上显示
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
                    clc();                  //还原原选定元素的值并在屏幕上清除
                    w[1].i=w[0].i;          //选定新的元素
                    w[1].j=w[0].j;
                    w[2].i=w[0].i;
                    w[2].j=w[0].j+1;
                    w[3].i=w[0].i;
                    w[3].j=w[0].j+2;
                    w[4].i=w[0].i-1;
                    w[4].j=w[0].j+1;
                    fz();                  //给新的选定元素赋值并在屏幕上显示
                    return 1;
                }
 
            }
            else if(style==2)
            {
 
                if(w[0].j+1<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0&&c(w[0].i-2,w[0].j)->state>=0)
                {
                    clc();                  //还原原选定元素的值并在屏幕上清除
                    w[1].i=w[0].i;          //选定新的元素
                    w[1].j=w[0].j;
                    w[2].i=w[0].i-1;
                    w[2].j=w[0].j;
                    w[3].i=w[0].i-1;
                    w[3].j=w[0].j+1;
                    w[4].i=w[0].i-2;
                    w[4].j=w[0].j;
                    fz();                  //给新的选定元素赋值并在屏幕上显示
                    return 1;
                }
 
            }
            else if(style==3)
            {
                if(w[0].j+2<jmax&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0&&c(w[0].i-1,w[0].j+2)->state>=0)
                {
                    clc();                  //还原原选定元素的值并在屏幕上清除
                    w[1].i=w[0].i;          //选定新的元素
                    w[1].j=w[0].j+1;
                    w[2].i=w[0].i-1;
                    w[2].j=w[0].j;
                    w[3].i=w[0].i-1;
                    w[3].j=w[0].j+1;
                    w[4].i=w[0].i-1;
                    w[4].j=w[0].j+2;
                    fz();                  //给新的选定元素赋值并在屏幕上显示
                    return 1;
                }
            }
            else if(style==4)
            {
                if(w[0].j+1<jmax&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0&&c(w[0].i-2,w[0].j+1)->state>=0)
                {
                    clc();                  //还原原选定元素的值并在屏幕上清除
                    w[1].i=w[0].i;          //选定新的元素
                    w[1].j=w[0].j+1;
                    w[2].i=w[0].i-1;
                    w[2].j=w[0].j;
                    w[3].i=w[0].i-1;
                    w[3].j=w[0].j+1;
                    w[4].i=w[0].i-2;
                    w[4].j=w[0].j+1;
                    fz();                  //给新的选定元素赋值并在屏幕上显示
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
                    clc();                  //还原原选定元素的值并在屏幕上清除
                    w[1].i=w[0].i;          //选定新的元素
                    w[1].j=w[0].j;
                    w[2].i=w[0].i;
                    w[2].j=w[0].j+1;
                    w[3].i=w[0].i-1;
                    w[3].j=w[0].j+1;
                    w[4].i=w[0].i-2;
                    w[4].j=w[0].j+1;
                    fz();                  //给新的选定元素赋值并在屏幕上显示
                    return 1;
                }
            }
            else if(style==2)
            {
                if(w[0].j+2<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i,w[0].j+2)->state>=0&&c(w[0].i-1,w[0].j)->state>=0)
                {
                    clc();                  //还原原选定元素的值并在屏幕上清除
                    w[1].i=w[0].i;          //选定新的元素
                    w[1].j=w[0].j;
                    w[2].i=w[0].i;
                    w[2].j=w[0].j+1;
                    w[3].i=w[0].i;
                    w[3].j=w[0].j+2;
                    w[4].i=w[0].i-1;
                    w[4].j=w[0].j;
                    fz();                  //给新的选定元素赋值并在屏幕上显示
                    return 1;
                }
            }
            else if(style==3)
            {
                if(w[0].j+1<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-2,w[0].j)->state>=0&&c(w[0].i-2,w[0].j+1)->state>=0)
                {
                    clc();                  //还原原选定元素的值并在屏幕上清除
                    w[1].i=w[0].i;          //选定新的元素
                    w[1].j=w[0].j;
                    w[2].i=w[0].i-1;
                    w[2].j=w[0].j;
                    w[3].i=w[0].i-2;
                    w[3].j=w[0].j;
                    w[4].i=w[0].i-2;
                    w[4].j=w[0].j+1;
                    fz();                  //给新的选定元素赋值并在屏幕上显示
                    return 1;
                }
 
            }
            else if(style==4)
            {
                if(w[0].j+2<jmax&&c(w[0].i,w[0].j+2)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0&&c(w[0].i-1,w[0].j+2)->state>=0)
                {
                    clc();                  //还原原选定元素的值并在屏幕上清除
                    w[1].i=w[0].i;          //选定新的元素
                    w[1].j=w[0].j+2;
                    w[2].i=w[0].i-1;
                    w[2].j=w[0].j;
                    w[3].i=w[0].i-1;
                    w[3].j=w[0].j+1;
                    w[4].i=w[0].i-1;
                    w[4].j=w[0].j+2;
                    fz();                  //给新的选定元素赋值并在屏幕上显示
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
                    clc();                  //还原原选定元素的值并在屏幕上清除
                    w[1].i=w[0].i;          //选定新的元素
                    w[1].j=w[0].j;
                    w[2].i=w[0].i;
                    w[2].j=w[0].j+1;
                    w[3].i=w[0].i-1;
                    w[3].j=w[0].j;
                    w[4].i=w[0].i-2;
                    w[4].j=w[0].j;
                    fz();                  //给新的选定元素赋值并在屏幕上显示
                    return 1;
                }
 
            }
            else if(style==2)
            {
                if(w[0].j+2<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i-1,w[0].j)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0&&c(w[0].i-1,w[0].j+2)->state>=0)
                {
                    clc();                  //还原原选定元素的值并在屏幕上清除
                    w[1].i=w[0].i;          //选定新的元素
                    w[1].j=w[0].j;
                    w[2].i=w[0].i-1;
                    w[2].j=w[0].j;
                    w[3].i=w[0].i-1;
                    w[3].j=w[0].j+1;
                    w[4].i=w[0].i-1;
                    w[4].j=w[0].j+2;
                    fz();                  //给新的选定元素赋值并在屏幕上显示
                    return 1;
                }
 
            }
            else if(style==3)
            {
                if(w[0].j+1<jmax&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i-1,w[0].j+1)->state>=0&&c(w[0].i-2,w[0].j)->state>=0&&c(w[0].i-2,w[0].j+1)->state>=0)
                {
                    clc();                  //还原原选定元素的值并在屏幕上清除
                    w[1].i=w[0].i;          //选定新的元素
                    w[1].j=w[0].j+1;
                    w[2].i=w[0].i-1;
                    w[2].j=w[0].j+1;
                    w[3].i=w[0].i-2;
                    w[3].j=w[0].j;
                    w[4].i=w[0].i-2;
                    w[4].j=w[0].j+1;
                    fz();                  //给新的选定元素赋值并在屏幕上显示
                    return 1;
                }
 
            }
            else if(style==4)
            {
                if(w[0].j+2<jmax&&c(w[0].i,w[0].j)->state>=0&&c(w[0].i,w[0].j+1)->state>=0&&c(w[0].i,w[0].j+2)->state>=0&&c(w[0].i-1,w[0].j+2)->state>=0)
                {
                    clc();                  //还原原选定元素的值并在屏幕上清除
                    w[1].i=w[0].i;          //选定新的元素
                    w[1].j=w[0].j;
                    w[2].i=w[0].i;
                    w[2].j=w[0].j+1;
                    w[3].i=w[0].i;
                    w[3].j=w[0].j+2;
                    w[4].i=w[0].i-1;
                    w[4].j=w[0].j+2;
                    fz();                  //给新的选定元素赋值并在屏幕上显示
                    return 1;
                }
 
            }
        }
    }
    return 0;
}
 
/*游戏主体*/
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
                nowscreen(); //刷新屏幕
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
            // 等级判断 显示预判图形
        }
        else
        {
            if(_kbhit())
            {
                str=getch();
                if(str==224)
                {
                    str=getch();
                    if(str==72)       //方向键上: 变形
                    {
                        mainchange();
                    }
                    else if(str==80)  //方向键下:快速下落
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
                    else if(str==75)  //方向键左:向左移动
                    {
                        goleft();
                    }
                    else if(str==77)  //方向键右:向右移动
                    {
                        goright();
                    }
                }
                else if(str=='\r')    //回车暂停
                {
                    getch();
                }
                else if(str==' ')     //直接下落
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
                else if(str==27)      //ESC:退出
                {
                    return ;
                }
                else if(str=='c'||str=='C')       //C键纠错帮助:查看数组以及此时关键变量的值
                {
                    check();
                }
                else if(str=='s'||str=='S')      //S键纠错帮助:查看此时真正应显示的结果
                {
                    nowscreen();
                    getch();
                }
                else if(str=='r'||str=='R')       //R键
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
 
/*创建下落物体*/
void newobject(void)
{
    unit newone;
    newone.color=rand(240,254);
    newone.event=0;                  //后期可添加功能的项
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
 
/*判断并变形*/
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
 
/*向左移动*/
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
 
/*向右移动*/
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
 
/*停止本次下落*/
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
 
/*下落*/
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
 
/*游戏判断*/
int judge(void)
{
    int i=0,j=0;
    for(i=0; i<4; i++)
        for(j=0; j<jmax; j++)
            if(c(i,j)->state==-1)
                return -1;
    return 0;
}
 
/*----------------------图形函数------------------------*/
 
/*界面函数. 为了显示效果，宽度longth需使用偶数,高度不应超过23. 使用范例: window(240, 10, 0, 30,23); window(240, 40, 0, 16,10);   window(240, 40, 10, 16,13); */
void window(int color, int xw, int yw, int longth, int high)
{
    int i = 0, j = 0;
    ycgb();
    textcolor(191);
    //textcolor(color);
    /*
    gotoxy(xw, yw);
    printf("┏");
    for (i = 0; i < (longth - 4) / 2; i++)
    {
        printf("━");
    }
    printf("┓");
    */
    for (j = 0; j < high - 2; j++)
    {
        textcolor(191);
        gotoxy(xw, yw + j + 1);
        printf("┃");
        textcolor(color);
        for (i = 0; i < longth - 4; i++)
        {
            printf(" ");
        }
        textcolor(191);
        printf("┃");
    }
    textcolor(251);
 
    gotoxy(xw, yw + j + 1);
    printf("┗");
    for (i = 0; i < (longth - 4) / 2; i++)
    {
        printf("━");
    }
    printf("┛");
    gotoxy(0, 0);
    return ;
}
 
/*单元清零*/
void clean(unit* u0,int color)
{
    u0->color=color;
    u0->event=0;
    u0->state=0;
    u0->style=0;
}
 
/*全部清零*/
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
 
/*显示当前情形*/
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
                //printf("■");
                printf("█");
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
 
/*辅助纠错函数*/
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
 
/*开始界面*/
void begain(void)
{
    int i=0,j=0,str=0,ch=0;
    textcolor(248);
    system("cls");
    gotoxy(0,3);
    for(i=0; i<40; i++)
    {
        Sleep(5);
        printf("━");
    }
    for(i=0; i<23; i++)
    {
        gotoxy(20,i);
        Sleep(i);
        if(i!=3)
            printf("┃");
        else
            printf("╋");
    }
    gotoxy(60,2);
    printf("俄罗斯方块");
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
        printf("━");
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
                    printf("━");
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
                    printf("━");
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
                    printf("━");
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
                    printf("━");
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
                    printf("━");
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
/*-----------------------主函数-------------------------*/
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
------------------------各种测试参考-----------------------
显示三种基本图形
printf("┏━┳━┓\n┃  ┃  ┃\n┣━╋━┫\n┃  ┃  ┃\n┗━┻━┛\n██ ■■\n██ ■■\n");
制表符
┏━┳━┓
┃  ┃  ┃
┗━┻━┛
方块符
█■
基本形状
1 方形       1
2 长条       2
3 Z形左      2
4 Z形右      2
5 凸形       4
6 L形左      4
7 L形右      4
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
                //printf("■");
                printf("█");
            }
        }
        Sleep(50);
    }
    eliminate();
    nowscreen();
*/



