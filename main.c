#include <stdio.h>
#include <stdlib.h> /* 亂數相關函數 */
#include <time.h>   /* 時間相關函數 */
#include <assert.h>
#include <windows.h>
time_t t;

int singleLineClear();
int KeyboardSelect();


int main()
{
    int WinStatus=0;
    /*int j=0,i=0;
    while(j<10)
    {
        printf("Output: %d",j);
        singleLineClear(20);
        Sleep(1000);
        j++;
    }*/
    int Temp[12]={1,2,3,4,5,6,5,4,3,2,1,6};
    int A[3][4]={{-2,-2,-2,-2},{-2,-2,-2,-2},{-2,-2,-2,-2}};//宣告矩陣
    srand((unsigned) time(&t));



    for(int i=0;i<12;i++)
    {
        int a=randint(3);
        int b=randint(4);
        while(A[a][b]!=-2)
        {

            //Sleep(500);
            a=randint(3);
            b=randint(4);
        }
        //printf("%d_%d_%d\n",a,b,Temp[i]);
        //printf("OK\n");
        A[a][b]=Temp[i];
    }





    while(WinStatus==0)
    {
        int temp1,temp2;
        int i=0,j=0;
        int Num[2];
        for(int u=0;u<2;u++)
        {
            if(u==0)
            {
                printf("-------\nFirst Attempt\n");
            }
            else
            {
                printf("-------\nSecond Attempt\n");
            }
            //printf("\r[%d][%d]",i+1,j+1);
            int P=KeyboardSelect();
            while(P!=0)
            {
                switch(P)
                {
                    case 2: //up
                        if(i<2)
                        {
                            i++;
                        }
                        if(u==0)
                        {
                            gotoxy(0,2);
                        }
                        else
                        {
                            gotoxy(0,13);
                        }
                        printf("\n");
                        DrawGUI(i,j,A,0,0,0,0);
                        printf("\r[%d][%d]",i+1,j+1);
                        singleLineClear();
                        break;
                    case 1: //down
                        if(i>0)
                        {
                            i--;
                        }
                        if(u==0)
                        {
                            gotoxy(0,2);
                        }
                        else
                        {
                            gotoxy(0,13);
                        }
                        printf("\n");
                        DrawGUI(i,j,A,0,0,0,0);
                        printf("\r[%d][%d]",i+1,j+1);
                        singleLineClear();
                        break;
                    case 3: //left
                        if(j>0)
                        {
                            j--;
                        }
                        if(u==0)
                        {
                            gotoxy(0,2);
                        }
                        else
                        {
                            gotoxy(0,13);
                        }
                        printf("\n");
                        DrawGUI(i,j,A,0,0,0,0);
                        printf("\r[%d][%d]",i+1,j+1);
                        break;
                    case 4: //right
                        if(j<3)
                        {
                            j++;
                        }
                        if(u==0)
                        {
                            gotoxy(0,2);
                        }
                        else
                        {
                            gotoxy(0,13);
                        }
                        printf("\n");
                        DrawGUI(i,j,A,0,0,0,0);
                        printf("\r[%d][%d]",i+1,j+1);
                        singleLineClear();
                        break;
                    case 5: //Home Debugging Answer Reveal Button
                        for(int i=0;i<3;i++)
                        {
                            for(int j=0;j<4;j++)
                            {
                                printf("%d ",A[i][j]);
                            }
                            printf("\n");
                        }
                        Sleep(1000);
                        system("cls");
                        break;
                    default:
                        break;
                }
                P=KeyboardSelect();
            }
            if(A[i][j]!=-1)
            {
                Num[u]=A[i][j];
                printf("\nYou Picked [%d][%d] is %d\n",i+1,j+1,Num[u]);
                if(u==1)
                {
                    if(Num[0]==Num[1])
                    {
                        DrawGUI(i,j,A,1,1,temp1,temp2);
                        printf("\nCorrect\n");
                        for(int r=0;r<3;r++)
                        {
                            for(int s=0;s<4;s++)
                            {
                                if(A[r][s]==Num[0])
                                {
                                    A[r][s]=-1;
                                }
                            }
                        }
                        WinStatus=1;
                        for(int r=0;r<3;r++)
                        {
                            for(int s=0;s<4;s++)
                            {
                                if(A[r][s]>-1)
                                {
                                    WinStatus=0;
                                }
                            }
                        }
                        Sleep(2000);
                        system("cls");
                    }
                    else
                    {
                        DrawGUI(i,j,A,1,1,temp1,temp2);
                        printf("\nIncorrect\n");
                        Sleep(2000);
                        system("cls");
                    }
                }
                else
                {
                    printf("-----\n");
                    DrawGUI(i,j,A,1,0,0,0);
                    temp1=i;
                    temp2=j;
                }
            }
            else
            {
                printf("\nYou Picked This Before\n");
                if(u==0)
                {
                    u=-1;
                }
                else
                {
                    u=0;
                }
                Sleep(500);
                printf("\[%d][%d]",i+1,j+1);
            }



        }

    }
    printf("\nYou Win!");
}
int DrawGUI(int i,int j,int A[3][4],int isVisible,int isSecond,int First_i,int First_j)
{
    for(int r=0;r<3;r++)
    {
        for(int s=0;s<4;s++)
        {
            if(A[r][s]==-1)
            {
                printf("/");
            }
            else if(r==i&&s==j)
            {
                if(isVisible==1)
                {
                    printf("%d",A[i][j]);
                }
                else
                {
                    printf("+");
                }
            }
            else
            {
                if(isSecond==1)
                {
                    if(r==First_i&&s==First_j)
                    {
                        printf("%d",A[First_i][First_j]);
                    }
                    else
                    {
                        printf("*");
                    }
                }
                else
                {
                    printf("*");
                }

            }

        }
        printf("\n");
    }
}

int singleLineClear()  //單行輸出刷新
{
    fflush(stdout);
}
void gotoxy(int xpos, int ypos)
{
  COORD scrn;
  HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
  scrn.X = xpos; scrn.Y = ypos;
  SetConsoleCursorPosition(hOuput,scrn);
}
int randint(int n) {


  if ((n - 1) == RAND_MAX) {
    return rand();
  } else {
    /* 計算可以被整除的長度 */
    long end = RAND_MAX / n;
    assert (end > 0L);
    end *= n;

    /* 將尾端會造成偏差的幾個亂數去除，
       若產生的亂數超過 limit，則將其捨去 */
    int r;
    while ((r = rand()) >= end);

    return r % n;
  }
}
int KeyboardSelect()
{
    int ch;
    while( (ch=getch())!='\r' ) /* Press ENTERS to quit... */
    {
        switch(ch)
        {
        case 0xE0:
            switch(ch=getch())
            {
                case 72:  //UP
                    return 1;
                    break;

                case 80:  //DOWN
                    return 2;
                    break;
                case 75:  //LEFT
                    return 3;
                    break;
                case 77:  //RIGHT
                    return 4;
                    break;
                case 71:  //HOME
                    return 5;
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
        }
    }
    return 0;
}
