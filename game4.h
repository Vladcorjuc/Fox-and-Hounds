#ifndef GAME4_H_INCLUDED
#define GAME4_H_INCLUDED
#include "meniuFunctions.h"
#include "gamebasis.h"
punct Stack[1000];
int stackIndex=0;
void EndTraining(int caz)
{
    int style, midx, midy,x,y;
    int size = 1;
    setbkcolor(LIGHTGRAY);
    clearviewport();
    setcolor(RED);
    moveto(50,50);

    midx = getmaxx() / 2;
    midy = getmaxy() / 2;

    settextstyle(GOTHIC_FONT, HORIZ_DIR, 6);
    settextjustify(1,1);
    if(caz==1)
    {
        CreareButonText(0,50,800,100,RED, RED, WHITE, "THE FOX WON",5);
        if (fox==1)
            readimagefile("images/fox1.selected.jpg",305,105,495,295);
        else if (fox==2)
            readimagefile("images/fox2.selected.jpg",305,105,495,295);
        else
            readimagefile("images/fox3.selected.jpg",305,105,495,295);
    }
    else
    {
        CreareButonText(0,50,800,100,RED, RED, WHITE, "THE DOGS WON",5);
        if (hounds==1)
            readimagefile("images/dog1.selected.jpg",305,105,495,295);
        else if (hounds==2)
            readimagefile("images/dog2.selected.jpg",305,105,495,295);
        else
            readimagefile("images/dog3.selected.jpg",305,105,495,295);
    }
    CreareButonText(0,330,800,380,DARKGRAY, DARKGRAY, WHITE, "PLAY AGAIN",5);
    CreareButonText (0, 560, 800, 590, DARKGRAY, DARKGRAY, WHITE, "Meniu",3);
    mode=0;
    while(mode==0)
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            x=mousex();
            y=mousey();
            if(y>=330&&y<=380)
            {
                CreareButonText(0,330,800,380,WHITE,WHITE, DARKGRAY, "PLAY AGAIN",5);
                lag();

                mode=1;
                game=4;
            }
            if(y>=560&&y<=590)
            {
                CreareButonText (15, 560, 800, 590, WHITE, WHITE, DARKGRAY, "Meniu",3);
                lag();
                mode=2;
                Meniu();
            }
        }
    }

}

void Undo()
{
    if(stackIndex>0)
    {
        table[Stack[stackIndex-1].i][Stack[stackIndex-1].j]=table[Stack[stackIndex].i][Stack[stackIndex].j];
        table[Stack[stackIndex].i][Stack[stackIndex].j]=0;
        table[Stack[stackIndex-2].i][Stack[stackIndex-2].j]=9;
        deletePiece(Stack[stackIndex].i,Stack[stackIndex].j);
        deletePiece(vulpe.i,vulpe.j);
        table[vulpe.i][vulpe.j]=0;
        vulpe.i=Stack[stackIndex-2].i;
        vulpe.j=Stack[stackIndex-2].j;
        deselectpiece(vulpe.i);
        stackIndex=stackIndex-3;

    }

}
void Easystrategy(int table[8][8])
{

    for(int line=7; line>=0; line--)
        for(int i=0; i<=7; i++)
        {

            if(table[line][i]!=0&&table[line][i]!=9)
            {
                if(line%2==1)
                {
                    if(table[line-1][i-1]!=9&&table[line-1][i+1]!=9)
                    {
                        if(validMove(table,line,line-1,i,i+1)==1)
                        {
                            stackIndex++;
                            Stack[stackIndex].i=line;
                            Stack[stackIndex].j=i;
                            stackIndex++;
                            Stack[stackIndex].i=line-1;
                            Stack[stackIndex].j=i+1;


                            moveDog(table,line,line-1,i,i+1);
                            return;

                        }
                        else if(validMove(table,line,line-1,i,i-1)==1)
                        {
                            stackIndex++;
                            Stack[stackIndex].i=line;
                            Stack[stackIndex].j=i;
                            stackIndex++;
                            Stack[stackIndex].i=line-1;
                            Stack[stackIndex].j=i-1;
                            moveDog(table,line,line-1,i,i-1);
                            return;

                        }
                    }

                }
                else
                {
                    for(int k=7; k>=0; k--)
                    {
                        if(table[line][k]>=1&&table[line][k]<=4&&table[line-1][k-1]!=9&&table[line-1][k+1]!=9&&line!=0)
                        {
                            if(validMove(table,line,line-1,k,k-1)==1)
                            {
                                stackIndex++;
                                Stack[stackIndex].i=line;
                                Stack[stackIndex].j=k;
                                stackIndex++;
                                Stack[stackIndex].i=line-1;
                                Stack[stackIndex].j=k-1;
                                moveDog(table,line,line-1,k,k-1);
                                return;

                            }

                        }

                    }
                }
            }


        }
}
void startTraining(int table[8][8])
{
    int wrongCursor=0;
    if(foxwin(table)==true)
    {

        drawPion(table);
        lag();
        EndTraining(1);
        cout<<"Vulpea a castigat";

    }
    else if(dogwin(table)==true)
    {
        lag();
        EndTraining(2);
        cout<<"Cainii au castigat";

    }
    else
    {
        if(turn==1)
        {
            ERRORMOUSE=1;
            selectedPiece(vulpe.i,vulpe.j);
            while(ERRORMOUSE==1)
                mouse(spre.i,spre.j);
            if(ERRORMOUSE==0)
            {
                if(validMove(table,vulpe.i,spre.i,vulpe.j,spre.j)==1)
                {
                    deletePiece(vulpe.i,vulpe.j);
                    stackIndex++;
                    Stack[stackIndex].i=vulpe.i;
                    Stack[stackIndex].j=vulpe.j;
                    table[spre.i][spre.j]=9;
                    table[vulpe.i][vulpe.j]=0;
                    vulpe.i=spre.i;
                    vulpe.j=spre.j;
                    currentLine=vulpe.i;
                    deselectpiece(vulpe.i);
                    turn=2;

                }
                else
                {
                    system("cls");
                    cout<<x1<<" "<<y1;
                    wrongCursor=1;
                }
            }

            else if(ERRORMOUSE==2)
            {
                if (x1>0 && x1<395)
                {
                    CreareButonText (15, 560, 395, 590, WHITE, WHITE, DARKGRAY, "Meniu",3);
                    lag();
                    wrongCursor=2;
                    Meniu();
                }
                else if (x1>405 && x1<800)
                {
                    CreareButonText (405, 560, 780, 590, WHITE, WHITE, DARKGRAY, "Restart",3);
                    lag();
                    wrongCursor=2;
                }
                else
                {
                    cout<<"ERROR"<<"\n";
                    system("cls");
                    cout<<x1<<" "<<y1;
                    wrongCursor=1;
                }


            }
            else if(ERRORMOUSE==3)
            {
                cout<<111111;
                    Undo();

            }
        }
        else
        {
            Easystrategy(table);
        }
        if(wrongCursor==0)
        {
            system("cls");
            drawPion(table);
            printMatrix(table);

        }
        if(wrongCursor!=2)
            startTraining(table);
    }

}
void Training()
{
    score=-1;
    waveOutSetVolume(0,0xFFF);
    PlaySound(TEXT("song.wav"), NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);
    clearmouseclick(WM_LBUTTONDOWN);
    readimagefile("images/arrow.jpg",30,260,110,340);
    mode=1;
    vulpe.i=0;
    vulpe.j=3;
    turn=1;
    setbkcolor(LIGHTGRAY);
    clearviewport();
    readimagefile("images/undo.jpg",700,60,760,120);
    generateMatrix(table);
    drawMatrix();
    drawPion(table);
    printMatrix(table);
    stackIndex=0;
    if(mode==1)
        startTraining(table);

}

#endif // GAME4_H_INCLUDED
