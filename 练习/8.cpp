#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h> 
#include<windows.h>
#define x0 26
#define y0 1
HANDLE hOutput=GetStdHandle(STD_OUTPUT_HANDLE);
/*显示声明*/
void p(int*a,int i,int x,int y);
/*部分刷新声明*/
void shua(void);
/*胜利画面测试函数声明*/
int test(void);
/*字体空格声明*/
void kg(int*a);
/*画长条函数的声明*/
void ct(int x,int y,int l,int k,int c);
/*标题字幕2048*/
void p2048(int x,int y);
/*单个颜色返回值声明*/
int col(int*a);
/*移动光标*/
void gotoxy(int x,int y)
{
	COORD coordScreen={0,0};
	coordScreen.X=x;
	coordScreen.Y=y;
	SetConsoleCursorPosition(hOutput,coordScreen);
}
/*字体颜色*/
void textcolor(int color)  
{
	SetConsoleTextAttribute(hOutput,color);
} 
/*显示函数*/
void prin(int*a,int*score,int*scoremax)
{
	int i;
	for (i = 0; i < 16; i++)
	{
        p(a,i,x0,y0);
	}
	printf("\n\n                          score=%d   MAXscore=%d                  \n", *score, *scoremax);
}
/* 产生随机数 */
int shu(void)
{
	int s = 0;
	s = 1 + (int)(12.0 * rand() / (RAND_MAX + 1.0));
	if (s == 12)
		return 4;
	else
		return 2;
}
 
/* 决定位置 */
int rands(void)
{
	return (int)(16.0 * rand() / (RAND_MAX + 1.0));
}
/* 主函数*/
int main(void)
{
	int flag = 0, c = 0, pd = 1, n = 0, i = 0, m = 0, j =
		0, sj, sj1, sj2, a[16] = { 0 }, b[16] ={0}, x = 0, score = 0, t = 0, jx = 0, scoremax = 0,ks=1,yx=0;
		char sr,an;
        //开始画面
		p2048(17,1);
	    textcolor(255);
	    gotoxy(35,15);
		for(;;)
		{
			an=getch();
		switch(an)
		{
		case 72:
			if(ks==1)
				ks=0;
			else
				ks=1;
		break;
		case 80:
			if(ks==1)
				ks=0;
			else
				ks=1;
		break;
		case '\r':
			yx=1;
			break;
		default:
		break;
		}
		if(ks==1)
			gotoxy(35,15);
		else
			gotoxy(34,18);
		if(ks==1&&yx==1)
			break;
		else if(ks==0&&yx==1)
		{
		textcolor(240);
		gotoxy(0,0);
		for(i=0;i<=500;i++)
		{
			printf("      ");
		}
		gotoxy(0,0);
        ct(12,5,58,10,223);
		gotoxy(13,6);
		printf("                      2048游戏说明");
		gotoxy(13,8);
		printf(" 通过按数字键移动数字，合并相同的数字来的取得更大的数。");
		gotoxy(13,9);
		printf(" 得到2048时游戏即胜利，当然您也可以选择继续挑战。");
		gotoxy(13,11);
		printf(" 按键操作:");
		gotoxy(13,13);
		printf(" 上:↑  下:↓  左:←  右:→  重新开始:r   退出游戏:e");
		textcolor(240);
		printf("\n\n\n\n\n                                                            I know ");
		getch();
		p2048(17,1);
	    textcolor(255);
	    gotoxy(34,18);
		}
		yx=0;
		}
		//隐藏光标
        HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO cci;
        GetConsoleCursorInfo(hOut,&cci);
        cci.bVisible=FALSE;
        SetConsoleCursorInfo(hOut,&cci);
        //刷新画面
		textcolor(240);
		gotoxy(0,0);
		for(i=0;i<=500;i++)
		{
			printf("      ");
		}
		gotoxy(0,0);
		/*设置时间种子*/
		srand((int)time(0));
		/* 设置初始值 */
		sj = rands();
		sj1 = rands();
		sj2 = rands();
		for (;;)
		{
			if (sj == sj1 || sj == sj2 || sj1 == sj2)
			{
				sj1 = rands();
				sj2 = rands();
			}
			else
				break;
		}
		a[sj] = shu();
		a[sj1] = shu();
		a[sj2] = shu();
		/*显示*/
		prin(a,&score,&scoremax);
		for (;;)
		{
			/* 无回显输入 */
			sr = getch();
			/* scanf("%d",&n); *//* 记录之前的位置,将用以比较移动是否有效 */
			for (j = 0; j < 16; j++)
				b[j] = a[j];
			switch (sr)
			{
				/* 向上移动 */
			case 72:
				/* 全部移到上边 */
				for (j = 0; j < 4; j++)
				{
					for (c = 0; c < 3; c++)
					{
						if (a[j] == 0)
						{
							a[j] = a[j + 4];
							a[j + 4] = 0;
						}
						if (a[j + 4] == 0)
						{
							a[j + 4] = a[j + 8];
							a[j + 8] = 0;
						}
						if (a[j + 8] == 0)
						{
							a[j + 8] = a[j + 12];
							a[j + 12] = 0;
						}
					}
					/* 移到上面后的合并操作 */
					if (a[j] == a[j + 4])
					{
						a[j] = a[j] * 2;
						score = score + a[j];
						a[j + 4] = a[j + 8];
						a[j + 8] = a[j + 12];
						a[j + 12] = 0;
						if (a[j + 4] == a[j + 8])
						{
							a[j + 4] = 2 * a[j + 4];
							score = score + a[j + 4];
							a[j + 8] = 0;
						}
					}
					else if (a[j + 4] == a[j + 8])
					{
						a[j + 4] = 2 * a[j + 4];
						score = score + a[j + 4];
						a[j + 8] = a[j + 12];
						a[j + 12] = 0;
					}
					else if (a[j + 8] == a[j + 12])
					{
						a[j + 8] = 2 * a[j + 8];
						score = score + a[j + 8];
						a[j + 12] = 0;
					}
					else;
				}
				break;
				/* 向下移动 */
			case 80:
				/* 全部移动到下面 */
				for (j = 12; j < 16; j++)
				{
					for (c = 0; c < 3; c++)
					{
						if (a[j] == 0)
						{
							a[j] = a[j - 4];
							a[j - 4] = 0;
						}
						if (a[j - 4] == 0)
						{
							a[j - 4] = a[j - 8];
							a[j - 8] = 0;
						}
						if (a[j - 8] == 0)
						{
							a[j - 8] = a[j - 12];
							a[j - 12] = 0;
						}
					}
					/* 移到下面后的合并操作 */
					if (a[j] == a[j - 4])
					{
						a[j] = a[j] * 2;
						score = score + a[j];
						a[j - 4] = a[j - 8];
						a[j - 8] = a[j - 12];
						a[j - 12] = 0;
						if (a[j - 4] == a[j - 8])
						{
							a[j - 4] = 2 * a[j - 4];
							score = score + a[j - 4];
							a[j - 8] = 0;
						}
					}
					else if (a[j - 4] == a[j - 8])
					{
						a[j - 4] = 2 * a[j - 4];
						score = score + a[j - 4];
						a[j - 8] = a[j - 12];
						a[j - 12] = 0;
					}
					else if (a[j - 8] == a[j - 12])
					{
						a[j - 8] = 2 * a[j - 8];
						score = score + a[j - 8];
						a[j - 12] = 0;
					}
					else;
				}
				break;
				/* 向左移动 */
			case 75:
				/* 全部移动到左面 */
				for (j = 0; j <= 12; j = j + 4)
				{
					for (c = 0; c < 3; c++)
					{
						if (a[j] == 0)
						{
							a[j] = a[j + 1];
							a[j + 1] = 0;
						}
						if (a[j + 1] == 0)
						{
							a[j + 1] = a[j + 2];
							a[j + 2] = 0;
						}
						if (a[j + 2] == 0)
						{
							a[j + 2] = a[j + 3];
							a[j + 3] = 0;
						}
					}
					/* 移到左面后的合并操作 */
					if (a[j] == a[j + 1])
					{
						a[j] = a[j] * 2;
						score = score + a[j];
						a[j + 1] = a[j + 2];
						a[j + 2] = a[j + 3];
						a[j + 3] = 0;
						if (a[j + 1] == a[j + 2])
						{
							a[j + 1] = 2 * a[j + 1];
							score = score + a[j + 1];
							a[j + 2] = 0;
						}
					}
					else if (a[j + 1] == a[j + 2])
					{
						a[j + 1] = 2 * a[j + 1];
						score = score + a[j + 1];
						a[j + 2] = a[j + 3];
						a[j + 3] = 0;
					}
					else if (a[j + 2] == a[j + 3])
					{
						a[j + 2] = 2 * a[j + 2];
						score = score + a[j + 2];
						a[j + 3] = 0;
					}
					else;
				}
				break;
				/* 向右移动 */
			case 77:
				/* 全部移动到右面 */
				for (j = 3; j <= 16; j = j + 4)
				{
					for (c = 0; c < 3; c++)
					{
						if (a[j] == 0)
						{
							a[j] = a[j - 1];
							a[j - 1] = 0;
						}
						if (a[j - 1] == 0)
						{
							a[j - 1] = a[j - 2];
							a[j - 2] = 0;
						}
						if (a[j - 2] == 0)
						{
							a[j - 2] = a[j - 3];
							a[j - 3] = 0;
						}
					}
					/* 移到右面后的合并操作 */
					if (a[j] == a[j - 1])
					{
						a[j] = a[j] * 2;
						score = score + a[j];
						a[j - 1] = a[j - 2];
						a[j - 2] = a[j - 3];
						a[j - 3] = 0;
						if (a[j - 1] == a[j - 2])
						{
							a[j - 1] = 2 * a[j - 1];
							score = score + a[j - 1];
							a[j - 2] = 0;
						}
					}
					else if (a[j - 1] == a[j - 2])
					{
						a[j - 1] = 2 * a[j - 1];
						score = score + a[j - 1];
						a[j - 2] = a[j - 3];
						a[j - 3] = 0;
					}
					else if (a[j - 2] == a[j - 3])
					{
						a[j - 2] = 2 * a[j - 2];
						score = score + a[j - 2];
						a[j - 3] = 0;
					}
					else;
				}
				break;
				/* 重新开始 */
			case 'r':
				for (j = 0; j < 16; j++)
					a[j] = 0;
				sj1 = rands();
				sj2 = rands();
				for (;;)
				{
					if (sj1 == sj2)
					{
						sj1 = rands();
						sj2 = rands();
					}
					else
						break;
				}
				a[sj1] = shu();
				a[sj2] = shu();
				flag = 0;
				score = 0;
				jx = 0;
				break;
				/* 退出 */
			case 'e':
				shua();
				ct(32,19,15,3,207);
				printf(" 游戏已退出!");
				textcolor(255);
				gotoxy(0,0);
				getch();
				return 0;
				break;
				/* 其他情况(刷新) */
			default:
				;
				break;
		}						
		/*windows下的系统清屏函数*/
		//system ("cls");
		/* 判断最高分 */
		if (score > scoremax)
			scoremax = score;
		/* 判断是否胜利(是否含有2048) */
		for (j = 0; j < 16; j++)
		{
			if (a[j] == 2048 && jx == 0)
			{
				/* 胜利时输出游戏结果 */
				/*显示*/
				prin(a,&score,&scoremax);
				shua();
				ct(20,19,15,3,207);
				printf("  游戏胜利!");
				textcolor(159);
                gotoxy(38,19);
				printf(" Continue                ");
				textcolor(239);
                gotoxy(49,20);
				printf("    Restart   ");
				textcolor(175);
                gotoxy(49,21);
				printf("    Exit      ");
				t=2;
                an=75;
				yx=0;
				for(;;)
				{
					an=getch();
					switch(an)
					{
					case 72:
						if(t==2)
						{
							t=3;
				 textcolor(240);
		         gotoxy(36,21);
				 printf("                           ");
				 textcolor(175);
                 gotoxy(38,21);
				 printf(" Exit                    ");
				 textcolor(240);
		         gotoxy(36,19);
				 printf("                           ");
		         textcolor(159);
                 gotoxy(47,19);
				 printf("      Continue  ");
				 textcolor(240);
		         gotoxy(36,20);
				 printf("                           ");
				 textcolor(239);
                 gotoxy(49,20);
				 printf("    Restart   ");
						}
						else if(t==1)
						{
							t=2;
							textcolor(240);
		         gotoxy(36,19);
				 printf("                           ");
		         textcolor(159);
                 gotoxy(38,19);
				 printf(" Continue                ");
				 textcolor(240);
		         gotoxy(36,20);
				 printf("                           ");
				 textcolor(239);
                 gotoxy(47,20);
				 printf("      Restart   ");
				 textcolor(240);
		         gotoxy(36,21);
				 printf("                           ");
				 textcolor(175);
                 gotoxy(49,21);
			   	 printf("    Exit      ");
						}
						else
						{
							t=1;
							textcolor(240);
		         gotoxy(36,20);
				 printf("                           ");
				 textcolor(239);
                 gotoxy(38,20);
				 printf(" Restart                 ");
				 textcolor(240);
		         gotoxy(36,21);
				 printf("                           ");
				 textcolor(175);
                 gotoxy(47,21);
			   	 printf("      Exit      ");	
				 textcolor(240);
		         gotoxy(36,19);
				 printf("                           ");
		         textcolor(159);
                 gotoxy(49,19);
				 printf("    Continue  ");
						}
						break;
					case 80:
						if(t==2)
						{
							t=1;
							 textcolor(240);
		         gotoxy(36,20);
				 printf("                           ");
				 textcolor(239);
                 gotoxy(38,20);
				 printf(" Restart                 ");
				 textcolor(240);
		         gotoxy(36,19);
				 printf("                           ");
		         textcolor(159);
                 gotoxy(47,19);
				 printf("      Continue  ");
				 textcolor(240);
		         gotoxy(36,21);
				 printf("                           ");
				 textcolor(175);
                 gotoxy(49,21);
			   	 printf("    Exit      ");
						}
						else if(t==1)
						{
							t=3;
							textcolor(240);
		         gotoxy(36,21);
				 printf("                           ");
				 textcolor(175);
                 gotoxy(38,21);
				 printf(" Exit                    ");
				 textcolor(240);
		         gotoxy(36,20);
				 printf("                           ");
				 textcolor(239);
                 gotoxy(47,20);
				 printf("      Restart   ");
				 textcolor(240);
		         gotoxy(36,19);
				 printf("                           ");
		         textcolor(159);
                 gotoxy(49,19);
				 printf("    Continue  ");
						}
						else
						{
						t=2;
						textcolor(240);
		         gotoxy(36,19);
				 printf("                           ");
		         textcolor(159);
                 gotoxy(38,19);
				 printf(" Continue                ");
				 textcolor(240);
		         gotoxy(36,21);
				 printf("                           ");
				 textcolor(175);
                 gotoxy(47,21);
			   	 printf("      Exit      ");	
				 textcolor(240);
		         gotoxy(36,20);
				 printf("                           ");
				 textcolor(239);
                 gotoxy(49,20);
				 printf("    Restart   ");
						}
						break;
					case '\r':
						yx=1;
						break;
					}
					if(yx==1)
					{
						yx=0;
						break;
					}
				}
				shua();
                textcolor(255);
				gotoxy(0,0);
				/* 重新开始游戏 */
				if (t == 1)
				{
					shua();
					pd = 1;
					x = 0;
					for (j = 0; j < 16; j++)
						a[j] = 0;
					sj1 = rands();
					sj2 = rands();
					for (;;)
					{
						if (sj1 == sj2)
						{
							sj1 = rands();
							sj2 = rands();
						}
						else
							break;
					}
					a[sj1] = shu();
					a[sj2] = shu();
					for (j = 0; j < 16; j++)
						b[j] = a[j];
					flag = 0;
					score = 0;
					break;
				}
				/* 继续游戏 */
				else if (t == 2)
				{
					jx = 1;
					shua();
				}
				else
				{
					shua();
					ct(32,19,15,3,207);
					printf(" 游戏已退出!");
					textcolor(255);
					gotoxy(0,0);
					getch();
					return 0;
				}
			}
		}						
		/* 决定是否产生新的数及其位置以及游戏是否失败 */
		/* flag,pd,x赋初值 */
		flag = 0;
		pd = 1;
		x = 0;
		/* 判断移动后是否有空位:pd=0为有空位,pd=1为无空位 */
		for (j = 0; j < 16; j++)
		{
			if (a[j] == 0)
				pd = 0;
		}
		/* 移动是否有效:x=1有效,x=0无效 */
		for (j = 0; j < 16; j++)
		{
			if (a[j] != b[j])
			{
				x = 1;
				break;
			}
		}
		/* 移动有效时且有空位时产生新数 */
		if (pd == 0 && x == 1)
		{
			for (;;)
			{
				sj = rands();
				if (a[sj] == 0)
				{
					a[sj] = shu();
					break;
				}
				else;
			}
		}
		/* 游戏是否失败的判定 */
		/* 移动后无空位 */
		else if (pd != 0)
		{
			/* 判断是否还有可合并的项 */
			for (j = 0; j < 16; j++)
			{
				if (j != 3 && j != 7 && j != 11 && j != 15 && a[j] == a[j + 1])
				{
					flag = flag + 1;
				}
				if (j != 12 && j != 13 && j != 14 && j != 15
					&& a[j] == a[j + 4])
				{
					flag = flag + 1;
				}
				if (j != 0 && j != 4 && j != 8 && j != 12 && a[j] == a[j - 1])
				{
					flag = flag + 1;
				}
				if (j != 0 && j != 1 && j != 2 && j != 3 && a[j] == a[j - 4])
				{
					flag = flag + 1;
				}
			}					
			/* 无空位且没有可合并的项时游戏失败 */
			if (flag == 0)
			{
				/* 失败时输出游戏结果 */
				/*显示*/
				prin(a,&score,&scoremax);
				shua();
				ct(20,19,15,3,271);
				printf("  游戏结束!");
				textcolor(240);
                gotoxy(38,19);
				printf("Whether continue the game ?");
				gotoxy(44,21);
				printf("@Yes      No");
                gotoxy(44,21);
				t=1;
				an=75;
				yx=0;
				for(;;)
				{
					an=getch();
					switch(an)
					{
					case 75:
						if(t==1)
						{
							t=0;
							gotoxy(53,21);
							printf("@");
							gotoxy(44,21);
							printf(" ");
						}
						else
						{
							t=1;
							gotoxy(44,21);
							printf("@");
							gotoxy(53,21);
							printf(" ");
						}
						break;
					case 77:
						if(t==1)
						{
							t=0;
							gotoxy(53,21);
							printf("@");
							gotoxy(44,21);
							printf(" ");
 
						}
						else
						{
							t=1;
							gotoxy(44,21);
							printf("@");
							gotoxy(53,21);
							printf(" ");
						}
						break;
					case '\r':
						yx=1;
						break;
					}
					if(yx==1)
					{
						yx=0;
						break;
					}
				}
				shua();
                textcolor(255);
				gotoxy(0,0);
				if (t == 1)
				{
					for (j = 0; j < 16; j++)
						a[j] = 0;
					sj=rands();
					sj1 = rands();
					sj2 = rands();
					for (;;)
					{
						if (sj1 ==sj2||sj1==sj||sj2==sj)
						{
							sj1 = rands();
							sj2 = rands();
						}
						else
							break;
					}
					a[sj]=shu();
					a[sj1] = shu();
					a[sj2] = shu();
					score = 0;
					jx = 0;
				}
				else
				{
					shua();
					ct(32,19,15,3,207);
					printf(" 游戏已退出!");
					textcolor(255);
					gotoxy(0,0);
					getch();
					return 0;
				}
			}
		}
		else;
		/* 显示结果 */
		prin(a,&score,&scoremax);
	}
	return 0;
}
/*显示函数*/
void p(int*a,int i,int x,int y)
{
    int x1=x,y1=y;
	textcolor(col(a+i));
	x1=x+(i%4)*7;
	y1=y+(i/4)*4;
	gotoxy(x1,y1);
	printf("     ");
	gotoxy(x1,y1+1);
    kg(a+i);
    gotoxy(x1,y1+2);
	printf("     ");
	textcolor(240);
}
/*字体空格声明*/
void kg(int*a)
{
	if(*a==0)
		printf("     ",*a);
	else if(*a<10)
		printf("  %d  ",*a);
	else if(*a<100)
		printf(" %d  ",*a);
	else if(*a<1000)
		printf(" %d ",*a);
	else if(*a<10000)
		printf("%d ",*a);
	else
		printf("%d",*a);
}
/*单个颜色返回值*/
int col(int*a)
{
int co=127;
if(*(a)==0)
co=127;
else if(*(a)==2)
co=143;
else if(*(a)==4)
co=191;
else if(*(a)==8)
co=175;
else if(*(a)==16)
co=239;
else if(*(a)==32)
co=223;
else if(*(a)==64)
co=207;
else if(*(a)==128)
co=95;
else if(*(a)==256)
co=159;
else if(*(a)==512)
co=63;
else if(*(a)==1024)
co=111;
else if(*(a)==2048)
co=79;
else if(*(a)==4096)
co=287;
else 
co=271;
return co;
}
/*标题字幕2048*/
void p2048(int x,int y)
{
	int i;
	textcolor(240);
	gotoxy(0,0);
	for(i=0;i<=500;i++)
		{
			printf("      ");
		}
	//2
	textcolor(207);
	gotoxy(x,y);
	printf("          ");
    gotoxy(x,y+1);
	printf("          ");
	gotoxy(x+7,y+2);
	printf("   ");
	gotoxy(x+7,y+3);
	printf("   ");
	gotoxy(x,y+4);
	printf("          ");
    gotoxy(x,y+5);
	printf("          ");
    gotoxy(x,y+6);
	printf("   ");
	gotoxy(x,y+7);
	printf("   ");
	gotoxy(x,y+8);
	printf("          ");
    gotoxy(x,y+9);
	printf("          ");
	//0
	textcolor(239);
    gotoxy(x+13,y);
	printf("          ");
    gotoxy(x+13,y+1);
	printf("          ");
	gotoxy(x+13,y+2);
	printf("   ");
    gotoxy(x+13+7,y+2);
	printf("   ");
	gotoxy(x+13,y+3);
	printf("   ");
    gotoxy(x+13+7,y+3);
	printf("   ");
	gotoxy(x+13,y+4);
	printf("   ");
    gotoxy(x+13+7,y+4);
	printf("   ");
	gotoxy(x+13,y+5);
	printf("   ");
    gotoxy(x+13+7,y+5);
	printf("   ");
	gotoxy(x+13,y+6);
	printf("   ");
    gotoxy(x+13+7,y+6);
	printf("   ");
	gotoxy(x+13,y+7);
	printf("   ");
    gotoxy(x+13+7,y+7);
	printf("   ");
	gotoxy(x+13,y+8);
	printf("          ");
    gotoxy(x+13,y+9);
	printf("          ");
	//4
	textcolor(159);
	gotoxy(x+26,y);
	printf("   ");
    gotoxy(x+26+7,y);
	printf("   ");
	gotoxy(x+26,y+1);
	printf("   ");
    gotoxy(x+26+7,y+1);
	printf("   ");
	gotoxy(x+26,y+2);
	printf("   ");
    gotoxy(x+26+7,y+2);
	printf("   ");
	gotoxy(x+26,y+3);
	printf("   ");
    gotoxy(x+26+7,y+3);
	printf("   ");
	gotoxy(x+26,y+4);
	printf("          ");
    gotoxy(x+26,y+5);
	printf("          ");
	gotoxy(x+26,y+6);
	printf("   ");
	gotoxy(x+26,y+7);
	printf("   ");
	gotoxy(x+26,y+8);
	printf("   ");
	gotoxy(x+26,y+9);
	printf("   ");
	//8
	textcolor(175);
	for(i=0;i<10;i++)
	{
	gotoxy(x+39,y+i);
	printf("          ");
	}
	textcolor(240);
	gotoxy(x+42,y+2);
	printf("    ");
	gotoxy(x+42,y+3);
	printf("    ");
	gotoxy(x+42,y+6);
	printf("    ");
	gotoxy(x+42,y+7);
	printf("    ");
	//长条
	 ct(35,15,20,1,240);
     printf(" Game Sart");
	 ct(35,18,20,1,240);
	 printf("How to play");
	 printf("\n");
	 printf("\n\n\n                                                           Made by Mr Yan");
	 gotoxy(35-25,15);
	 textcolor(255);
	 gotoxy(0,0);
}
/*画长条函数*/
void ct(int x,int y,int l,int k,int c)
{
	int i=0,j=0;
	textcolor(c);
	gotoxy(x,y);
	for(i=0;i<k;i++)
	{
	gotoxy(x,y+i);
	for(j=0;j<l;j++)
	{
	printf(" ");
	}
	}
	gotoxy(x+1,y+k/2);
}
void shua(void)
{
	gotoxy(0,18);
	textcolor(255);
	printf("                                                                   \n");
	printf("                                                                   \n");
	printf("                                                                   \n");
	printf("                                                                   \n");
	printf("                                                                   \n");
	printf("                                                                   \n");
	gotoxy(0,0);
}
/*胜利画面测试函数*/
int test(void)
{
	int i,t,yx;
	char an;
        textcolor(240);
		gotoxy(0,0);
		for(i=0;i<=500;i++)
		{
			printf("      ");
		}
		gotoxy(0,0);
        HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO cci;
        GetConsoleCursorInfo(hOut,&cci);
        cci.bVisible=FALSE;
        SetConsoleCursorInfo(hOut,&cci);
				//printf("\n游戏胜利!t\n重新开始游戏请按1\n继续游戏请按2\n退出请按其他键3\n");   2 1 3
			                                                                         
/*
	2	继续选中 textcolor(240);
		         gotoxy(36,19);
				 printf("                           ");
		         textcolor(159);
                 gotoxy(38,19);
				 printf(" Continue                ");
	2	继续平常 textcolor(240);
		         gotoxy(36,19);
				 printf("                           ");
		         textcolor(159);
                 gotoxy(49,19);
				 printf("    Continue  ");
	1  重新选中  textcolor(240);
		         gotoxy(36,20);
				 printf("                           ");
				 textcolor(239);
                 gotoxy(38,20);
				 printf(" Restart                 ");
	1   重新平常 textcolor(240);
		         gotoxy(36,20);
				 printf("                           ");
				 textcolor(239);
                 gotoxy(49,20);
				 printf("    Restart   ");
	3   退出选中 textcolor(240);
		         gotoxy(36,21);
				 printf("                           ");
				 textcolor(175);
                 gotoxy(38,21);
				 printf(" Exit                    ");
    3   退出平常 textcolor(240);
		         gotoxy(36,21);
				 printf("                           ");
				 textcolor(175);
                 gotoxy(49,21);
			   	 printf("    Exit      ");
		 //      0000000000000000000000000  24		
		*/
                shua();
				ct(20,19,15,3,207);
				printf("  游戏胜利!");
				textcolor(159);
                gotoxy(38,19);
				printf(" Continue                ");
 
				textcolor(239);
                gotoxy(49,20);
				printf("    Restart   ");
				textcolor(175);
                gotoxy(49,21);
				printf("    Exit      ");
				t=2;
                an=75;
				yx=0;
				for(;;)
				{
					an=getch();
					switch(an)
					{
					case 72:
						if(t==2)
						{
							t=3;
				 textcolor(240);
		         gotoxy(36,21);
				 printf("                           ");
				 textcolor(175);
                 gotoxy(38,21);
				 printf(" Exit                    ");
				 textcolor(240);
		         gotoxy(36,19);
				 printf("                           ");
		         textcolor(159);
                 gotoxy(47,19);
				 printf("      Continue  ");
				 textcolor(240);
		         gotoxy(36,20);
				 printf("                           ");
				 textcolor(239);
                 gotoxy(49,20);
				 printf("    Restart   ");	
						}
						else if(t==1)
						{
							t=2;
							textcolor(240);
		         gotoxy(36,19);
				 printf("                           ");
		         textcolor(159);
                 gotoxy(38,19);
				 printf(" Continue                ");
				 textcolor(240);
		         gotoxy(36,20);
				 printf("                           ");
				 textcolor(239);
                 gotoxy(47,20);
				 printf("      Restart   ");
				 textcolor(240);
		         gotoxy(36,21);
				 printf("                           ");
				 textcolor(175);
                 gotoxy(49,21);
			   	 printf("    Exit      ");
						}
						else
						{
							t=1;
							textcolor(240);
		         gotoxy(36,20);
				 printf("                           ");
				 textcolor(239);
                 gotoxy(38,20);
				 printf(" Restart                 ");
				 textcolor(240);
		         gotoxy(36,21);
				 printf("                           ");
				 textcolor(175);
                 gotoxy(47,21);
			   	 printf("      Exit      ");	
				 textcolor(240);
		         gotoxy(36,19);
				 printf("                           ");
		         textcolor(159);
                 gotoxy(49,19);
				 printf("    Continue  ");
						}
						break;
					case 80:
						if(t==2)
						{
							t=1;
							 textcolor(240);
		         gotoxy(36,20);
				 printf("                           ");
				 textcolor(239);
                 gotoxy(38,20);
				 printf(" Restart                 ");
				 textcolor(240);
		         gotoxy(36,19);
				 printf("                           ");
		         textcolor(159);
                 gotoxy(47,19);
				 printf("      Continue  ");
				 textcolor(240);
		         gotoxy(36,21);
				 printf("                           ");
				 textcolor(175);
                 gotoxy(49,21);
			   	 printf("    Exit      ");
						}
						else if(t==1)
						{
							t=3;
							textcolor(240);
		         gotoxy(36,21);
				 printf("                           ");
				 textcolor(175);
                 gotoxy(38,21);
				 printf(" Exit                    ");
				 textcolor(240);
		         gotoxy(36,20);
				 printf("                           ");
				 textcolor(239);
                 gotoxy(47,20);
				 printf("      Restart   ");
				 textcolor(240);
		         gotoxy(36,19);
				 printf("                           ");
		         textcolor(159);
                 gotoxy(49,19);
				 printf("    Continue  ");
						}
						else
						{
						t=2;
						textcolor(240);
		         gotoxy(36,19);
				 printf("                           ");
		         textcolor(159);
                 gotoxy(38,19);
				 printf(" Continue                ");
				 textcolor(240);
		         gotoxy(36,21);
				 printf("                           ");
				 textcolor(175);
                 gotoxy(47,21);
			   	 printf("      Exit      ");	
				 textcolor(240);
		         gotoxy(36,20);
				 printf("                           ");
				 textcolor(239);
                 gotoxy(49,20);
				 printf("    Restart   ");
						}
						break;
					case '\r':
						yx=1;
						break;
					}
					if(yx==1)
					{
						yx=0;
						break;
					}
				}
				shua();
                textcolor(255);
				gotoxy(0,0);
				textcolor(240);
				if(t==2)
					printf("Continue       ");
				else if(t==1)
					printf("Restart        ");
				else
					printf("Exit           ");
				return 0;
}


