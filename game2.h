#ifndef GAME2_H_INCLUDED
#define GAME2_H_INCLUDED
#include "gamebasis.h"
#include "draw.h"

void pcvshounds();
int strategia,ok=0;
int pas=1;

void foxstrategy(int table[8][8])
{
   if (table[7][0]==0)
       strategia=1;
       else
        strategia=2;
}

void EndFox(int caz)
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

        newScore(score,2);
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
                game=2;
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

void strategia1()
{
    if (vulpe.j-1>=0&&vulpe.i<=6&&validMove(table,vulpe.i,vulpe.i+1,vulpe.j,vulpe.j-1)==1)
    {
        table[vulpe.i][vulpe.j]=0;
        deletePiece(vulpe.i,vulpe.j);
        vulpe.i+=1;
        vulpe.j=vulpe.j-1;
        table[vulpe.i][vulpe.j]=9;
    }
    else if (vulpe.j+1<=7&&vulpe.i+1<=7&&validMove(table,vulpe.i,vulpe.i+1,vulpe.j,vulpe.j+1)==1)
    {
        table[vulpe.i][vulpe.j]=0;
        deletePiece(vulpe.i,vulpe.j);
        vulpe.i+=1;
        vulpe.j+=1;
        table[vulpe.i][vulpe.j]=9;
    }
    else if (vulpe.i-1>=0&&vulpe.j-1>=0&&validMove(table,vulpe.i,vulpe.i-1,vulpe.j,vulpe.j-1)==1)
    {
        table[vulpe.i][vulpe.j]=0;
        deletePiece(vulpe.i,vulpe.j);
        vulpe.i+=-1;
        vulpe.j+=-1;
        table[vulpe.i][vulpe.j]=9;
    }
    else if (vulpe.i-1>=0&&vulpe.j+1<=7&&validMove(table,vulpe.i,vulpe.i-1,vulpe.j,vulpe.j+1)==1)
    {
        table[vulpe.i][vulpe.j]=0;
        deletePiece(vulpe.i,vulpe.j);
        vulpe.i+=-1;
        vulpe.j+=1;
        table[vulpe.i][vulpe.j]=9;
    }
}
void strategia2()
{
    if (vulpe.j+1<=7&&vulpe.i+1<=7&&validMove(table,vulpe.i,vulpe.i+1,vulpe.j,vulpe.j+1)==1&&pas==1)
    {
        table[vulpe.i][vulpe.j]=0;
        deletePiece(vulpe.i,vulpe.j);
        vulpe.i+=1;
        vulpe.j+=1;
        table[vulpe.i][vulpe.j]=9;
    }
    else if (vulpe.j-1>=0&&vulpe.i<=6&&validMove(table,vulpe.i,vulpe.i+1,vulpe.j,vulpe.j-1)==1)
    {
        table[vulpe.i][vulpe.j]=0;
        deletePiece(vulpe.i,vulpe.j);
        vulpe.i+=1;
        vulpe.j=vulpe.j-1;
        table[vulpe.i][vulpe.j]=9;
        pas=2;
    }
        else if (vulpe.i-1>=0&&vulpe.j-1>=0&&validMove(table,vulpe.i,vulpe.i-1,vulpe.j,vulpe.j-1)==1)
    {
        table[vulpe.i][vulpe.j]=0;
        deletePiece(vulpe.i,vulpe.j);
        vulpe.i+=-1;
        vulpe.j+=-1;
        table[vulpe.i][vulpe.j]=9;
    pas=1;
    }
    else if (vulpe.i-1>=0&&vulpe.j+1<=7&&validMove(table,vulpe.i,vulpe.i-1,vulpe.j,vulpe.j+1)==1)
    {
        table[vulpe.i][vulpe.j]=0;
        deletePiece(vulpe.i,vulpe.j);
        vulpe.i+=-1;
        vulpe.j+=1;
        table[vulpe.i][vulpe.j]=9;
        pas=1;
    }

}

void startFox()
{
    int wrongCursor=0;
    if(foxwin(table)==true)
    {
        drawPion(table);
        lag();
        EndFox(1);
        cout<<"Vulpea a castigat";
    }
    else if(dogwin(table)==true)
    {
        lag();
        EndFox(2);
        cout<<"Cainii au castigat";
    }
    else
    {

    if (turn==1)
    {
       if (ok==0)
       {
           ok=1;
           foxstrategy(table);
       }
       if (strategia==1)
        strategia1();
        else
            strategia2();
        wrongCursor=0;
        turn=2;

    }
    else
    {
        score++;
            ERRORMOUSE=1;
            while(ERRORMOUSE==1)
                mouse(ales.i,ales.j);
            if(ERRORMOUSE==0)
            {

                if(table[ales.i][ales.j]!=9&&table[ales.i][ales.j]!=0)
                {
    HOUNDSBEGIN:
                    selectedhound.i=ales.i;
                    selectedhound.j=ales.j;
                    selectedPiece(selectedhound.i,selectedhound.j);
                    ales.i=0;
                    ales.j=0;
                    while(ERRORMOUSE==1||validMove(table,selectedhound.i,ales.i,selectedhound.j,ales.j)==false)
                        {

                            mouse(ales.i,ales.j);
                            if(table[ales.i][ales.j]!=0&&table[ales.i][ales.j]!=9)
                            {
                                drawHound(selectedhound.j,selectedhound.i);
                                if(selectedhound.i>0)
                                deselectpiece(selectedhound.i-1);
                                goto HOUNDSBEGIN;

                            }

                        }

                    moveDog(table,selectedhound.i,ales.i,selectedhound.j,ales.j);
                    deselectpiece(ales.i);



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
     if(wrongCursor==0)
        {
            system("cls");
            drawPion(table);
            printMatrix(table);

        }
        if(wrongCursor!=2)
            startFox();
    }

}
void pcvshounds()
{
    score=0;
    waveOutSetVolume(0,0xFFF);
    PlaySound(TEXT("song.wav"), NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);
    clearmouseclick(WM_LBUTTONDOWN);
    vulpe.i=0;
    vulpe.j=3;
    turn=2;
    mode=1;
    pas=1;
    Score();
    setbkcolor(LIGHTGRAY);
    clearviewport();
    generateMatrix(table);
    drawMatrix();
    drawPion(table);
    printMatrix(table);
    if(mode==1)
    startFox();
}



#endif // GAME2_H_INCLUDED
