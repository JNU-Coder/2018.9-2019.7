#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h> 
#include<windows.h>
#define x0 26
#define y0 1
HANDLE hOutput=GetStdHandle(STD_OUTPUT_HANDLE);
/*��ʾ����*/
void p(int*a,int i,int x,int y);
/*����ˢ������*/
void shua(void);
/*ʤ��������Ժ�������*/
int test(void);
/*����ո�����*/
void kg(int*a);
/*����������������*/
void ct(int x,int y,int l,int k,int c);
/*������Ļ2048*/
void p2048(int x,int y);
/*������ɫ����ֵ����*/
int col(int*a);
/*�ƶ����*/
void gotoxy(int x,int y)
{
	COORD coordScreen={0,0};
	coordScreen.X=x;
	coordScreen.Y=y;
	SetConsoleCursorPosition(hOutput,coordScreen);
}
/*������ɫ*/
void textcolor(int color)  
{
	SetConsoleTextAttribute(hOutput,color);
} 
/*��ʾ����*/
void prin(int*a,int*score,int*scoremax)
{
	int i;
	for (i = 0; i < 16; i++)
	{
        p(a,i,x0,y0);
	}
	printf("\n\n                          score=%d   MAXscore=%d                  \n", *score, *scoremax);
}
/* ��������� */
int shu(void)
{
	int s = 0;
	s = 1 + (int)(12.0 * rand() / (RAND_MAX + 1.0));
	if (s == 12)
		return 4;
	else
		return 2;
}
 
/* ����λ�� */
int rands(void)
{
	return (int)(16.0 * rand() / (RAND_MAX + 1.0));
}
/* ������*/
int main(void)
{
	int flag = 0, c = 0, pd = 1, n = 0, i = 0, m = 0, j =
		0, sj, sj1, sj2, a[16] = { 0 }, b[16] ={0}, x = 0, score = 0, t = 0, jx = 0, scoremax = 0,ks=1,yx=0;
		char sr,an;
        //��ʼ����
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
		printf("                      2048��Ϸ˵��");
		gotoxy(13,8);
		printf(" ͨ�������ּ��ƶ����֣��ϲ���ͬ����������ȡ�ø��������");
		gotoxy(13,9);
		printf(" �õ�2048ʱ��Ϸ��ʤ������Ȼ��Ҳ����ѡ�������ս��");
		gotoxy(13,11);
		printf(" ��������:");
		gotoxy(13,13);
		printf(" ��:��  ��:��  ��:��  ��:��  ���¿�ʼ:r   �˳���Ϸ:e");
		textcolor(240);
		printf("\n\n\n\n\n                                                            I know ");
		getch();
		p2048(17,1);
	    textcolor(255);
	    gotoxy(34,18);
		}
		yx=0;
		}
		//���ع��
        HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO cci;
        GetConsoleCursorInfo(hOut,&cci);
        cci.bVisible=FALSE;
        SetConsoleCursorInfo(hOut,&cci);
        //ˢ�»���
		textcolor(240);
		gotoxy(0,0);
		for(i=0;i<=500;i++)
		{
			printf("      ");
		}
		gotoxy(0,0);
		/*����ʱ������*/
		srand((int)time(0));
		/* ���ó�ʼֵ */
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
		/*��ʾ*/
		prin(a,&score,&scoremax);
		for (;;)
		{
			/* �޻������� */
			sr = getch();
			/* scanf("%d",&n); *//* ��¼֮ǰ��λ��,�����ԱȽ��ƶ��Ƿ���Ч */
			for (j = 0; j < 16; j++)
				b[j] = a[j];
			switch (sr)
			{
				/* �����ƶ� */
			case 72:
				/* ȫ���Ƶ��ϱ� */
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
					/* �Ƶ������ĺϲ����� */
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
				/* �����ƶ� */
			case 80:
				/* ȫ���ƶ������� */
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
					/* �Ƶ������ĺϲ����� */
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
				/* �����ƶ� */
			case 75:
				/* ȫ���ƶ������� */
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
					/* �Ƶ������ĺϲ����� */
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
				/* �����ƶ� */
			case 77:
				/* ȫ���ƶ������� */
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
					/* �Ƶ������ĺϲ����� */
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
				/* ���¿�ʼ */
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
				/* �˳� */
			case 'e':
				shua();
				ct(32,19,15,3,207);
				printf(" ��Ϸ���˳�!");
				textcolor(255);
				gotoxy(0,0);
				getch();
				return 0;
				break;
				/* �������(ˢ��) */
			default:
				;
				break;
		}						
		/*windows�µ�ϵͳ��������*/
		//system ("cls");
		/* �ж���߷� */
		if (score > scoremax)
			scoremax = score;
		/* �ж��Ƿ�ʤ��(�Ƿ���2048) */
		for (j = 0; j < 16; j++)
		{
			if (a[j] == 2048 && jx == 0)
			{
				/* ʤ��ʱ�����Ϸ��� */
				/*��ʾ*/
				prin(a,&score,&scoremax);
				shua();
				ct(20,19,15,3,207);
				printf("  ��Ϸʤ��!");
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
				/* ���¿�ʼ��Ϸ */
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
				/* ������Ϸ */
				else if (t == 2)
				{
					jx = 1;
					shua();
				}
				else
				{
					shua();
					ct(32,19,15,3,207);
					printf(" ��Ϸ���˳�!");
					textcolor(255);
					gotoxy(0,0);
					getch();
					return 0;
				}
			}
		}						
		/* �����Ƿ�����µ�������λ���Լ���Ϸ�Ƿ�ʧ�� */
		/* flag,pd,x����ֵ */
		flag = 0;
		pd = 1;
		x = 0;
		/* �ж��ƶ����Ƿ��п�λ:pd=0Ϊ�п�λ,pd=1Ϊ�޿�λ */
		for (j = 0; j < 16; j++)
		{
			if (a[j] == 0)
				pd = 0;
		}
		/* �ƶ��Ƿ���Ч:x=1��Ч,x=0��Ч */
		for (j = 0; j < 16; j++)
		{
			if (a[j] != b[j])
			{
				x = 1;
				break;
			}
		}
		/* �ƶ���Чʱ���п�λʱ�������� */
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
		/* ��Ϸ�Ƿ�ʧ�ܵ��ж� */
		/* �ƶ����޿�λ */
		else if (pd != 0)
		{
			/* �ж��Ƿ��пɺϲ����� */
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
			/* �޿�λ��û�пɺϲ�����ʱ��Ϸʧ�� */
			if (flag == 0)
			{
				/* ʧ��ʱ�����Ϸ��� */
				/*��ʾ*/
				prin(a,&score,&scoremax);
				shua();
				ct(20,19,15,3,271);
				printf("  ��Ϸ����!");
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
					printf(" ��Ϸ���˳�!");
					textcolor(255);
					gotoxy(0,0);
					getch();
					return 0;
				}
			}
		}
		else;
		/* ��ʾ��� */
		prin(a,&score,&scoremax);
	}
	return 0;
}
/*��ʾ����*/
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
/*����ո�����*/
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
/*������ɫ����ֵ*/
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
/*������Ļ2048*/
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
	//����
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
/*����������*/
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
/*ʤ��������Ժ���*/
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
				//printf("\n��Ϸʤ��!t\n���¿�ʼ��Ϸ�밴1\n������Ϸ�밴2\n�˳��밴������3\n");   2 1 3
			                                                                         
/*
	2	����ѡ�� textcolor(240);
		         gotoxy(36,19);
				 printf("                           ");
		         textcolor(159);
                 gotoxy(38,19);
				 printf(" Continue                ");
	2	����ƽ�� textcolor(240);
		         gotoxy(36,19);
				 printf("                           ");
		         textcolor(159);
                 gotoxy(49,19);
				 printf("    Continue  ");
	1  ����ѡ��  textcolor(240);
		         gotoxy(36,20);
				 printf("                           ");
				 textcolor(239);
                 gotoxy(38,20);
				 printf(" Restart                 ");
	1   ����ƽ�� textcolor(240);
		         gotoxy(36,20);
				 printf("                           ");
				 textcolor(239);
                 gotoxy(49,20);
				 printf("    Restart   ");
	3   �˳�ѡ�� textcolor(240);
		         gotoxy(36,21);
				 printf("                           ");
				 textcolor(175);
                 gotoxy(38,21);
				 printf(" Exit                    ");
    3   �˳�ƽ�� textcolor(240);
		         gotoxy(36,21);
				 printf("                           ");
				 textcolor(175);
                 gotoxy(49,21);
			   	 printf("    Exit      ");
		 //      0000000000000000000000000  24		
		*/
                shua();
				ct(20,19,15,3,207);
				printf("  ��Ϸʤ��!");
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


