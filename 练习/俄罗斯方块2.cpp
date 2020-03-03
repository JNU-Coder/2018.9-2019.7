#ifndef _HEAD_H_
#define _HEAD_H_

#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS 1

//�������صĲ���
#define WALL_SQUARE_WIDTH 10 //Χǽ����Ŀ��
#define xWALL_SQUARE_NUM 30 //x�᷽��ķ������Ŀ
#define yWALL_SQUARE_WIDTH 46 //y�᷽��ķ������Ŀ
#define GAME_WALL_WIDTH  (WALL_SQUARE_WIDTH*xWALL_SQUARE_NUM) //��Ϸ����Ŀ�� 300 
#define GAME_WALL_HTGH (WALL_SQUARE_WIDTH*yWALL_SQUARE_WIDTH) //��Ϸ����ĸ߶� 460

#define WINDOW_WIDTH 480 // ��Ϸ�ܴ��ڿ�� 480 
#define WINDOW_HIGH 460  // ��Ϸ�ܴ��ڸ߶� 460

//�������˹�������ز���
#define ROCK_SQUARE_WIDTH (2*WALL_SQUARE_WIDTH) //����˹����Ĵ�С��Χǽ������ 20
#define xROCK_SQUARE_NUM  ((GAME_WALL_WIDTH -20)/ROCK_SQUARE_WIDTH) // ��Ϸ��x��ŵķ�����Ŀ��14 
#define yROCK_SQUARE_NUM  ((GAME_WALL_HTGH -20)/ROCK_SQUARE_WIDTH)  // ��Ϸ��y��ŵķ�����Ŀ��22


//�����ƶ��������ز���
#define DIRECT_UP    3  
#define DIRECT_DOWN  2      
#define DIRECT_LEFT  -1  
#define DIRECT_RIGHT 1 


/*���ݽṹ-���Ա�(�ṹ������)*/
typedef struct ROCK
{
    //������ʾ�������״(ÿһ���ֽ���8λ����ÿ4λ��ʾ�����е�һ��)  
    unsigned short rockShapeBits;
    int          nextRockIndex;  //��һ�����飬�������е��±�  
} RockType;

//������ͼ�δ����е�λ��(����λ4*4�������Ͻ�����)  
typedef struct LOCATE
{
    int left;
    int top;
} RockLocation_t;

//ȫ�ֱ���-��Ϸ���״̬����(����ʾ��ǰ������Щλ���з���)  
//0��ʾû�У�1��ʾ��(��������к����У��γ�һ��Χǽ�������жϷ����Ƿ��ܹ��ƶ�)  
int game_board[yROCK_SQUARE_NUM + 2][xROCK_SQUARE_NUM + 2] = { 0 };
int game_socres = 0; //ȫ�ַ���

// �Ѷ���˹�����19����ŵ�������
int rockTypeNum = 19;
RockType RockArray[19] = { (0, 0) };

//Ԥ�����ķ����λ��
RockLocation_t preRockLocation = {GAME_WALL_WIDTH+70,70};
//ÿ�����ɳ�ʼ�������λ��
RockLocation_t initRockLocation = { (WALL_SQUARE_WIDTH + 100), WALL_SQUARE_WIDTH };
//������ʾ��λ��


//�����ļ��еĺ���
// ���������Լ���������Draw.h��
void DrawGameWindow();
void DisplayRock(int rockIdx, RockLocation_t*  LocatePtr, bool displayed);
//��ʼ��InitԴ�ļ�
void InitGame();

//game.h
void PlayGame();
bool IsGameOver();


#endif
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
Draw.h
#include"Head.h"


//������Ϸ����
void DrawGameWindow()
{
    //�Ȼ���Χǽ
    setcolor(BLUE);
    setlinestyle(PS_SOLID,NULL,0);
    setfillcolor(BLUE);
    //��������Χǽ
    for (int x = WALL_SQUARE_WIDTH; x <= GAME_WALL_WIDTH; x += WALL_SQUARE_WIDTH)
    {
        fillrectangle(x - WALL_SQUARE_WIDTH, 0, x, WALL_SQUARE_WIDTH); //��
        fillrectangle(x - WALL_SQUARE_WIDTH, GAME_WALL_HTGH - WALL_SQUARE_WIDTH, x, GAME_WALL_HTGH);//��
    }
    //��������Χǽ
    for (int y = WALL_SQUARE_WIDTH; y <= GAME_WALL_HTGH; y += WALL_SQUARE_WIDTH)
    {
        fillrectangle(0, y, WALL_SQUARE_WIDTH, y + WALL_SQUARE_WIDTH);//��
        fillrectangle(GAME_WALL_WIDTH - WALL_SQUARE_WIDTH, y, GAME_WALL_WIDTH, y + WALL_SQUARE_WIDTH);//��
    }

    //�����ұ�ͳ�Ʒ�������ض���

    //�����ָ���
    setcolor(WHITE);
    setlinestyle(PS_DASH,2);
    line(GAME_WALL_WIDTH + 20, 0, GAME_WALL_WIDTH + 20, GAME_WALL_HTGH);

    //��������
    LOGFONT font;
    gettextstyle(&font);
    settextstyle(18, 0, _T("����"));
    font.lfQuality = ANTIALIASED_QUALITY;//�������Ч��Ϊ����� 
    //1��ʾԤ����״
    outtextxy(GAME_WALL_WIDTH + 80, 30, _T("Ԥ��"));

    outtextxy(GAME_WALL_WIDTH + 80, 170, _T("����"));

    outtextxy(GAME_WALL_WIDTH + 65, 250, _T("����˵��"));
    outtextxy(GAME_WALL_WIDTH + 40, 290, _T("w a s d���Ʒ���"));
    outtextxy(GAME_WALL_WIDTH + 40, 335, _T("�ո� ��ͣ"));

    //��ʾ����
    setcolor(RED);
    outtextxy(GAME_WALL_WIDTH + 90, 200, '0');
}

//����Ϸ����ʾ���ΪrockIdx�ķ���
void DisplayRock(int rockIdx,  RockLocation_t*  LocatePtr, bool displayed)
{
    int color;//����������ɫ
    int lineColor = WHITE;//�ߵ���ɫ
    int boardFalg = 0;
    int xRock = 0;
    int yRock = 0;
    unsigned short rockCode = RockArray[rockIdx].rockShapeBits;
    //���displayedΪtrue�Ļ������������ɫ����Ϊwhite��game_board��Ӧ��λ������Ϊ1��
    //���displayedΪfalse�Ļ������������ɫ����Ϊblack��game_board��Ӧ��λ������Ϊ0��
    displayed ? (color = RED, boardFalg = 1) : (color = BLACK,lineColor = BLACK, boardFalg = 0);

    setcolor(lineColor);
    setfillcolor(color);

    setlinestyle(PS_SOLID);//����Ϊʵ�ߣ�
    xRock = LocatePtr->left;
    yRock = LocatePtr->top;

    int count = 0;//ÿ4�����У���¼����ƫ����
    unsigned short mask = 1;
    for (int i = 1; i <= 16; ++i)
    {

        mask = 1 << (16 - i);
        if ((rockCode & mask) != 0) //�����Ϊ0�Ļ����ͻ���С����
        {       
            fillrectangle(xRock , yRock, xRock + ROCK_SQUARE_WIDTH, yRock + ROCK_SQUARE_WIDTH);
        }
        if (i % 4 == 0) //����
        {
            yRock = yRock + ROCK_SQUARE_WIDTH;  
            xRock = xRock = LocatePtr->left;
        }
        else
        {
            xRock += ROCK_SQUARE_WIDTH;
        }
    }
}

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
Init.h
#include"Head.h"

static void ShapeStrToBit(unsigned char *rockShapeStr, unsigned short& rockShapeBit);
static void ReadRcok();

void InitGame()
{
    //��ȫ����Ϸ��Ϸ���ʼ�����߽��ʼ��Ϊ1
    for (int i = 0; i < xROCK_SQUARE_NUM + 2; i++)
    {
        game_board[0][i] = 1;  //�ϱ߽�
        game_board[yROCK_SQUARE_NUM + 1][i] = 1; //�±߽�
    }
    for (int i = 0; i < yROCK_SQUARE_NUM + 2; i++)
    {
        game_board[i][0] = 1 ; //��߽�
        game_board[i][xROCK_SQUARE_NUM + 1] = 1; //�ұ߽�
    }
    //��ȡ����˹���� 
    ReadRcok();

}

//���ļ��ж�ȡ�������״�洢��rockArray��
void ReadRcok()
{
    FILE* fp = fopen("RockShape.ini","r");
    if (NULL == fp)
    {
        printf("���ļ�ʧ��\n");
        return;
    }
    unsigned char readBuf[1024]; //fp��ȡ���ַ���readbuf��
    unsigned short rockShapeBit = 0;//��ŷ�����״��ռ16����λ
    unsigned char rockShapeStr[16];//��ŷ����ַ���
    int ShapeStrIdx = 0;
    int rockNum = 0;//ͳ�Ʒ���ĸ����Լ���ŷ�������RockArray���±�
    int rocknext = 0;//������������һ����״
    int rockShapeStart = 0;//ͬһ���͵���״
    while (true)
    {
        size_t readSize = fread(readBuf, 1, 1024, fp);
        if (readSize == 0)
            break;
        //����readbuf
        for (size_t idx = 0; idx < readSize; ++idx)
        {
            //���ַ���ŵ�rockShapeStr��
            while (ShapeStrIdx < 16 && idx < readSize)
            {
                if (readBuf[idx] == '@' || readBuf[idx] == '#')
                {
                    rockShapeStr[ShapeStrIdx] = (unsigned char)readBuf[idx];
                    ++ShapeStrIdx;
                }
                ++idx; //����idx == readSize�� 
                if (readBuf[idx] == '*')//�޸���һ�η����nextֵ
                {
                    idx += 5;
                    RockArray[--rockNum].nextRockIndex = rockShapeStart;
                    rockNum++;
                    rockShapeStart = rockNum;
                    rocknext = rockShapeStart ;
                }
            }
            //����û������
            if (ShapeStrIdx < 16)
            {
                break;
            }
            else //����shapestr
            {
                ShapeStrIdx = 0;//��0
                //��rockShapeStr תΪrockShapeBit
                ShapeStrToBit(rockShapeStr, rockShapeBit);
                rocknext++;
                RockArray[rockNum].rockShapeBits = rockShapeBit;
                RockArray[rockNum].nextRockIndex = rocknext;
                rockNum++;
            }
        }
    }
    fclose(fp);
}
//�����ļ��ж�ȡ���ַ���(����Ĭ��Ϊ16)ת���� unsigned short
void ShapeStrToBit(unsigned char *rockShapeStr, unsigned short& rockShapeBit)
{
    rockShapeBit = 0;
    for (size_t idx = 0; idx < 16; ++idx)
    {
        if (rockShapeStr[idx] == '@') //1
        {
            rockShapeBit |= (1 << (16 - idx - 1));
        }
        // #Ϊ0 ����Ҫ����
    }
}
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
game.h
#include"Head.h"
#define _CRT_SECURE_NO_WARNINGS 1

bool MoveAble(int rockIndex, RockLocation_t* currentLocatePtr, int f_direction);
void SetGameBoardFlag(int rockIdx, RockLocation_t* curRockLocation);
void UserHitKeyBoard(char userHit, int* RockIndex, RockLocation_t* curRockLocation);
void FullLine();
void UpdateSocres(int scores);
void DelCurLine(int rowIdx);
bool IsGameOver();


void PlayGame()
{
    char userHit = 0;//�û��û�����
    int curRockIndex = 0;//��ǰ�����rockArray�±�
    int nextRockIndex = 0;//�´�
    RockLocation_t curRockLocation;
    curRockLocation.left = initRockLocation.left;
    curRockLocation.top = initRockLocation.top;
    DWORD oldtime = 0;
    srand((unsigned int)time(NULL));
    curRockIndex = rand() % rockTypeNum;
    nextRockIndex = rand() % rockTypeNum;
    //����Ԥ������ʼ������
    //�ڳ�ʼλ�ú�Ԥ������ʾ������״
    DisplayRock(curRockIndex, &initRockLocation, 1);
    DisplayRock(nextRockIndex, &preRockLocation, 1);
    bool moveAbled = false;
    while (true)
    {
        //�жϵ�ǰ�����Ƿ����(�ж��ܷ�������)��������,�ж��Ƿ�����,���ж��Ƿ������Ϸ�� �ı�game_board ,�����´γ�ʼ���ķ��飬�Լ������µ�Ԥ������
        //
        moveAbled = MoveAble(curRockIndex, &curRockLocation, DIRECT_DOWN);
        if (!moveAbled) //�ж��Ƿ���أ��������Ʊ�ʾ���
        {
            //�޸�game_board��ֵ
            SetGameBoardFlag(curRockIndex, &curRockLocation);
            FullLine(); 
            if (IsGameOver())
            {
                MessageBox(NULL, _T("��Ϸ����"), _T("GAME OVER"), MB_OK);
                exit(0);
            }       
            //Ϊ�´�����ģ�鿪ʼ׼��
            DisplayRock(nextRockIndex, &preRockLocation, false);//�����ɵķ���
            curRockIndex = nextRockIndex;
            nextRockIndex = rand() % rockTypeNum; //�����µ�Ԥ������
            DisplayRock(curRockIndex, &initRockLocation, 1);
            DisplayRock(nextRockIndex, &preRockLocation, 1);
            FlushBatchDraw();
            //�޸�curRockLocation��ֵ
            curRockLocation.left = initRockLocation.left;
            curRockLocation.top = initRockLocation.top; 
        }

        if (kbhit()) //����û������� �ʹ�����
        {
            userHit = getch();
            UserHitKeyBoard(userHit, &curRockIndex, &curRockLocation);
        }

        //û�� ���Զ�����һ����λ :������else����Ϊ���ܰ���������������
        DWORD newtime = GetTickCount();
        if (newtime - oldtime >= (unsigned int)(300) && moveAbled == TRUE)
        {
            oldtime = newtime;
            DisplayRock(curRockIndex, &curRockLocation, false);
            curRockLocation.top += ROCK_SQUARE_WIDTH; //����һ��  
        }
        //AutomaticDownMove(curRockIndex, &curRockLocation);
        //�����·���
        DisplayRock(curRockIndex, &curRockLocation, 1);
        FlushBatchDraw();
        Sleep(20);
    }
}


//��Ӧ��������ʱ��
void UserHitKeyBoard(char userHit, int* RockIndex, RockLocation_t* curRockLocation)
{
    switch (userHit)
    {
    case 'W':
    case 'w'://��
        if (MoveAble(RockArray[*RockIndex].nextRockIndex, curRockLocation, DIRECT_UP))
        {
            DisplayRock(*RockIndex, curRockLocation, false);
            *RockIndex = RockArray[*RockIndex].nextRockIndex;
        }
        break;
    case 'S':
    case 's'://��
        if (MoveAble(*RockIndex, curRockLocation, DIRECT_DOWN))
        {
            DisplayRock(*RockIndex, curRockLocation, false);
            curRockLocation->top += 2 * (ROCK_SQUARE_WIDTH);
            if (!MoveAble(*RockIndex, curRockLocation, DIRECT_DOWN))
            {
                curRockLocation->top -= ROCK_SQUARE_WIDTH;
            }
        }
        break;
    case 'A':
    case 'a': //��
        if (MoveAble(*RockIndex, curRockLocation, DIRECT_LEFT))
        {
            DisplayRock(*RockIndex, curRockLocation, false);
            curRockLocation->left -= ROCK_SQUARE_WIDTH;
        }
        break;
    case 'D':
    case 'd': //��
        if (MoveAble(*RockIndex, curRockLocation, DIRECT_RIGHT))
        {
            DisplayRock(*RockIndex, curRockLocation, FALSE);
            curRockLocation->left += ROCK_SQUARE_WIDTH;
        }
        break;
    case ' ': //��ͣ
        while (1)
        {
            userHit = getch();
            if (userHit == ' ')
                break;
        }
        break;
    default:
        break;
    }
}

//�ж��Ƿ����У�����������Ȼ�����÷�
void FullLine()
{
    bool linefull = true;
    int idx = yROCK_SQUARE_NUM;//�����һ�����ϲ��� 22
    int count = 0;
    while (count != xROCK_SQUARE_NUM ) //�������� 14
    {
        linefull = true;
        count = 0;
        for (int i = 1; i <= xROCK_SQUARE_NUM; ++i)
        {
            if (game_board[idx][i] == 0)
            {
                linefull = false;
                count++;
            }
        }
        if (linefull) //���У�������ǰ�У����·���
        {
            DelCurLine(idx);
            game_socres += 3;
            UpdateSocres(game_socres);
            idx++;//��Ϊ����Ҫ��1
        }
        idx--;
    }

}
void UpdateSocres(int scores)
{
    setcolor(RED);
    TCHAR s[10];
    _stprintf(s, _T("%d"), scores);
    outtextxy(GAME_WALL_WIDTH + 90, 200, s);
}
//������ǰ��
void DelCurLine(int rowIdx)
{
    //������ǰ��
    setcolor(BLACK);
    setfillcolor(BLACK);
    for (int i = 1; i < xROCK_SQUARE_NUM; ++i)
    {
        fillrectangle(WALL_SQUARE_WIDTH + (i - 1)*ROCK_SQUARE_WIDTH, (rowIdx - 1)*ROCK_SQUARE_WIDTH + WALL_SQUARE_WIDTH,
                  WALL_SQUARE_WIDTH + i*ROCK_SQUARE_WIDTH, rowIdx*ROCK_SQUARE_WIDTH + WALL_SQUARE_WIDTH);
    }
    //�������������
    int cnt = 0;
    while (cnt != xROCK_SQUARE_NUM) //ֱ�������ǿ��е�Ϊֹ  
    {
        cnt = 0;
        for (int i = 1; i <= xROCK_SQUARE_NUM; i++)
        {
            game_board[rowIdx][i] = game_board[rowIdx - 1][i];

            //���������һ��  
            setcolor(BLACK);
            setfillcolor(BLACK);
            fillrectangle(WALL_SQUARE_WIDTH + ROCK_SQUARE_WIDTH*i - ROCK_SQUARE_WIDTH ,
                WALL_SQUARE_WIDTH + ROCK_SQUARE_WIDTH*(rowIdx - 1) - ROCK_SQUARE_WIDTH ,
                WALL_SQUARE_WIDTH + ROCK_SQUARE_WIDTH*i,
                WALL_SQUARE_WIDTH + ROCK_SQUARE_WIDTH*(rowIdx - 1));

            //��ʾ�����һ��  
            if (game_board[rowIdx][i] == 1)
            {
                setcolor(WHITE);
                setfillcolor(RED);
                fillrectangle(WALL_SQUARE_WIDTH + ROCK_SQUARE_WIDTH*i - ROCK_SQUARE_WIDTH ,
                    WALL_SQUARE_WIDTH + ROCK_SQUARE_WIDTH*rowIdx - ROCK_SQUARE_WIDTH ,
                    WALL_SQUARE_WIDTH + ROCK_SQUARE_WIDTH*i,
                    WALL_SQUARE_WIDTH + ROCK_SQUARE_WIDTH*rowIdx);
            }

            if (game_board[rowIdx][i] == 0)
                cnt++;            //ͳ��һ���ǲ��� ���ǿո�  
        }//for  
        rowIdx--;
    }
}

//�Ƿ�����ƶ�����
bool MoveAble(int rockIndex, RockLocation_t* currentLocatePtr, int f_direction)
{
    int mask;
    int rockX;
    int rockY;

    rockX = currentLocatePtr->left;
    rockY = currentLocatePtr->top;

    mask = (unsigned short)1 << 15;
    for (int i = 1; i <= 16; i++)
    {
        //����������Ϊ1�� ��Ϊ�����ϵĵ�  
        if ((RockArray[rockIndex].rockShapeBits & mask) != 0)
        {
            //�ж��ܷ��ƶ�(��ɨ�輴���ƶ���λ�� �Ƿ������õ�Χǽ���ص�)  
            //��������(����������)  
            if (f_direction == DIRECT_UP)
            {
                //��Ϊ������´��������һ���������״��������ֱ���жϴ˷����λ���Ƿ��Ѿ���ռ 
                //�ж���һ������
                if (game_board[(rockY - WALL_SQUARE_WIDTH) / ROCK_SQUARE_WIDTH + 1]
                    [(rockX - WALL_SQUARE_WIDTH) / ROCK_SQUARE_WIDTH + 1] == 1)
                    return false;
            }
            //��������·����ƶ�  
            else if (f_direction == DIRECT_DOWN)
            {
                if (game_board[(rockY - WALL_SQUARE_WIDTH) / ROCK_SQUARE_WIDTH + 2]
                    [(rockX - WALL_SQUARE_WIDTH) / ROCK_SQUARE_WIDTH + 1] == 1)
                    return false;
            }
            else //��������ҷ����ƶ�  
            {   //f_direction��DIRECT_LEFTΪ-1��DIRECT_RIGHTΪ1����ֱ�Ӽ�f_direction�����жϡ�  
                if (game_board[(rockY - WALL_SQUARE_WIDTH) / ROCK_SQUARE_WIDTH + 1]
                    [(rockX - WALL_SQUARE_WIDTH) / ROCK_SQUARE_WIDTH + 1 + f_direction] == 1)
                    return false;
            }
        }

        //ÿ4�� ���� ת����һ�м���  
        i % 4 == 0 ? (rockY += ROCK_SQUARE_WIDTH, rockX = currentLocatePtr->left)
            : rockX += ROCK_SQUARE_WIDTH;

        mask >>= 1;
    }

    return true;

}
//����Ϸgame_board���ñ�Ǳ�ʾ�Ѿ�ռ��
void SetGameBoardFlag(int rockIdx, RockLocation_t* curRockLocation)
{
    int mask;
    int rockX;
    int rockY;

    rockX = curRockLocation->left;
    rockY = curRockLocation->top;

    mask = (unsigned int)1 << 15;
    for (int i = 1; i <= 16; i++)
    {
        //����������Ϊ1�� ��Ϊ�����ϵĵ�  
        if ((RockArray[rockIdx].rockShapeBits & mask) != 0)
        {
            game_board[(rockY - WALL_SQUARE_WIDTH) / ROCK_SQUARE_WIDTH + 1]
                [(rockX - WALL_SQUARE_WIDTH) / ROCK_SQUARE_WIDTH + 1] = 1;
        }

        //ÿ4�� ���� ת����һ�м�����  
        i % 4 == 0 ? (rockY += ROCK_SQUARE_WIDTH, rockX = curRockLocation->left)
            : rockX += ROCK_SQUARE_WIDTH;

        mask >>= 1;
    }
}
//�ж���Ϸ�Ƿ����
bool IsGameOver()
{
    bool topLineHaveRock = false;//�����Ƿ��з���
    bool bottomLineHaveRock = false;

    for (int i = 1; i < xROCK_SQUARE_NUM; ++i)
    {
        if (game_board[1][i] == 1)
            topLineHaveRock = true;
        if (game_board[yROCK_SQUARE_NUM][i] == 1)
            bottomLineHaveRock = true;
    }
    if (bottomLineHaveRock && topLineHaveRock)
        return true;
    else 
        return false;
}
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
100
101
102
103
104
105
106
107
108
109
110
111
112
113
114
115
116
117
118
119
120
121
122
123
124
125
126
127
128
129
130
131
132
133
134
135
136
137
138
139
140
141
142
143
144
145
146
147
148
149
150
151
152
153
154
155
156
157
158
159
160
161
162
163
164
165
166
167
168
169
170
171
172
173
174
175
176
177
178
179
180
181
182
183
184
185
186
187
188
189
190
191
192
193
194
195
196
197
198
199
200
201
202
203
204
205
206
207
208
209
210
211
212
213
214
215
216
217
218
219
220
221
222
223
224
225
226
227
228
229
230
231
232
233
234
235
236
237
238
239
240
241
242
243
244
245
246
247
248
249
250
251
252
253
254
255
256
257
258
259
260
261
262
263
264
265
266
267
268
269
270
271
272
273
274
275
276
277
278
279
280
281
282
283
284
285
286
287
288
289
290
291
292
293
294
295
296
297
298
299
300
301
302
303
304
305
306
307
308
309
310
311
main.cpp
#include"Head.h"
#include"Draw.h"
#include"Init.h"
#include"game.h"

int main()
{
    initgraph(WINDOW_WIDTH,WINDOW_HIGH);

    DrawGameWindow();
    //ʹ�� API �����޸Ĵ�������  
    HWND hWnd = GetHWnd();
    SetWindowText(hWnd, _T("����˹����"));
    InitGame();
    PlayGame();
    getchar();
    closegraph();
    system("pause");
    return  0;
}
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
�����ļ���RockShape.ini
@###
@###
@@##
####

@@@#
@###
####
####

@@##
#@##
#@##
####

##@#
@@@#
####
####

****
#@##
#@##
@@##
####

@###
@@@#
####
####

@@##
@###
@###
####

@@@#
##@#
####
####

****
#@##
@@@#
####
####

@###
@@##
@###
####

@@@#
#@##
####
####

#@##
@@##
#@##
####

****
#@##
@@##
@###
####

@@##
#@@#
####
####

****
@###
@@##
#@##
####

#@@#
@@##
####
####

****
@###
@###
@###
@###

@@@@
####
####
####

****
@@##
@@##
####
####

****
--------------------- 
���ߣ��ɳ��Ĳ���1018�� 
��Դ��CSDN 
ԭ�ģ�https://blog.csdn.net/wenqiang1208/article/details/71245082 
��Ȩ����������Ϊ����ԭ�����£�ת���븽�ϲ������ӣ�
