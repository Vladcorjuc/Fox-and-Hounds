#ifndef GAME3_H_INCLUDED
#define GAME3_H_INCLUDED
#include "meniuFunctions.h"
#include "gamebasis.h"
#include "highscore.h"
void End(int caz);
void checkStrategy(int table[8][8]);
void defaultStrategy(int table[8][8]);
void firstStrategy(int table[8][8],int line);
void secondStrategy(int table[8][8],int line);
void thirdStrategy(int table[8][8],int line);
void fourthStrategy(int table[8][8],int line);
void fifthStrategy(int table[8][8]);
void Score()
{
    score=0;
    strcpy(moves[0],"0 moves");
    strcpy(moves[1],"1 moves");
    strcpy(moves[2],"2 moves");
    strcpy(moves[3],"3 moves");
    strcpy(moves[4],"4 moves");
    strcpy(moves[5],"5 moves");
    strcpy(moves[6],"6 moves");
    strcpy(moves[7],"7 moves");
    strcpy(moves[8],"8 moves");
    strcpy(moves[9],"9 moves");
    strcpy(moves[10],"10 moves");
    strcpy(moves[11],"11 moves");
    strcpy(moves[12],"12 moves");
    strcpy(moves[13],"13 moves");
    strcpy(moves[14],"14 moves");
    strcpy(moves[15],"15 moves");
    strcpy(moves[16],"16 moves");
    strcpy(moves[17],"17 moves");
    strcpy(moves[18],"18 moves");
    strcpy(moves[19],"19 moves");
    strcpy(moves[20],"20 moves");
    strcpy(moves[21],"21 moves");
    strcpy(moves[22],"22 moves");
    strcpy(moves[23],"23 moves");
    strcpy(moves[24],"24 moves");
    strcpy(moves[25],"25 moves");
    strcpy(moves[26],"26 moves");
    strcpy(moves[27],"27 moves");
    strcpy(moves[28],"28 moves");
    strcpy(moves[29],"29 moves");
    strcpy(moves[30],"30 moves");

}
void End(int caz)
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

        newScore(score,1);
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
                game=3;
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
void checkStrategy(int table[8][8])
{
    int i;
    for(i=0; i<=7; i++)
    {
        if(table[i][1]==9&&table[i+1][0]!=0&&table[i+1][2]!=0&&table[i+1][4]!=0&&table[i+1][6]!=0)
        {
            strategy=1;
            currentLine=i;
            firstStrategy(table,i);

        }
        else if(table[i][3]==9&&table[i][1]!=0&&table[i+1][2]!=0&&table[i+1][4]!=0&&table[i+1][6]!=0)
        {
            strategy=2;
            currentLine=i;
            secondStrategy(table,i);


        }
        else if(table[i][4]==9&&table[i][6]!=0&&table[i+1][1]!=0&&table[i+1][3]!=0&&table[i+1][5]!=0)
        {
            strategy=2;
            currentLine=i;
            secondStrategy(table,i);


        }
        else if(table[i][5]==9&&table[i][1]!=0&&table[i][3]!=0&&table[i+1][4]!=0&&table[i+1][6]!=0)
        {
            strategy=3;
            currentLine=i;
            thirdStrategy(table,i);

        }
        else if (table[i][2]==9&&table[i][6]!=0&&table[i][4]!=0&&table[i+1][1]!=0&&table[i+1][3]!=0)
        {
            strategy=3;
            currentLine=i;
            thirdStrategy(table,i);

        }
        else if((table[i][0]==9&&table[i+1][1]!=0&&table[i][2]!=0)||(table[i][7]==9&&table[i+1][6]!=0&&table[i][5]!=0))
        {
            strategy=4;
            currentLine=i;
            fourthStrategy(table,i);
        }

        else if(table[0][1]!=0&&table[0][3]!=0)
        {
            strategy=5;
            currentLine=i;
            fifthStrategy(table);

        }
    }
    defaultStrategy(table);

}
void defaultStrategy(int table[8][8])
{
    if(turn==2)
    {
        for (int line=7; line>=0; line--)
            for(int i=0; i<8; i++)
            {
                if(table[line][i]!=0&&table[line][i]!=9)
                {
                    if(line%2==1)
                    {
                        if(table[line-1][i-1]!=9&&table[line-1][i+1]!=9)
                        {
                            if(validMove(table,line,line-1,i,i+1)==1)
                            {
                                moveDog(table,line,line-1,i,i+1);
                                return;

                            }
                            else if(validMove(table,line,line-1,i,i-1)==1)
                            {
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
                                    moveDog(table,line,line-1,k,k-1);
                                    return;

                                }

                            }

                        }
                    }

                }

            }

    }
}
void firstStrategy(int table[8][8],int line)
{
    moveDog(table,line+1,line,6,5);

}
void secondStrategy(int table[8][8],int line )
{
    if(line%2==0)
        moveDog(table,line+1,line,6,5);
    else
        moveDog(table,line+1,line,1,2);

}
void thirdStrategy(int table[8][8],int line)
{
    if(line%2==0)
        moveDog(table,line,line-1,1,2);
    else
        moveDog(table,line,line-1,6,5);
}
void fourthStrategy(int table[8][8],int line)
{
    if(line%2==1)
        moveDog(table,line,line-1,2,1);
    else
        moveDog(table,line,line-1,5,6);

}
void fifthStrategy(int table[8][8])
{
    for (int line=7; line>=0; line--)
        for(int i=0; i<8; i++)
        {
            if(table[line][i]!=0&&table[line][i]!=9)
            {
                if(line-1>=0&&i-1>=0)
                {
                    if(table[line-1][i-1]==0)
                    {
                        moveDog(table,line,line-1,i,i-1);
                        return;
                    }

                }
                if(line-1>=0&&i+1<=7)
                {
                    if(table[line-1][i+1]==0)
                    {
                        moveDog(table,line,line-1,i,i+1);
                        return;

                    }

                }
            }
        }
}
void start(int table[8][8])
{
    int wrongCursor=0;
    if(foxwin(table)==true)
    {

        drawPion(table);
        lag();
        End(1);
        cout<<"Vulpea a castigat";

    }
    else if(dogwin(table)==true)
    {
        lag();
        End(2);
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
                    score++;
                    deletePiece(vulpe.i,vulpe.j);
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
                    cout<<"ERROR"<<"\n";
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
                    wrongCursor=1;
                }
            }
        }
        else
        {
            checkStrategy(table);
        }
        if(wrongCursor==0)
        {
            system("cls");
            drawPion(table);
            printMatrix(table);
        }
        if(wrongCursor!=2)
            start(table);
    }

}
void Foxvspc()
{
    waveOutSetVolume(0,0xFFF);
    PlaySound(TEXT("song.wav"), NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);
    clearmouseclick(WM_LBUTTONDOWN);
    mode=1;
    vulpe.i=0;
    vulpe.j=3;
    turn=1;
    Score();
    setbkcolor(LIGHTGRAY);
    clearviewport();
    generateMatrix(table);
    drawMatrix();
    drawPion(table);
    printMatrix(table);
    if(mode==1)
        start(table);
}


#endif // GAME3_H_INCLUDED
