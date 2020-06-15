#ifndef GAME1_H_INCLUDED
#define GAME1_H_INCLUDED

#include "meniuFunctions.h"
#include "gamebasis.h"
punct ales,selectedhound;
void PlayervsPlayer();
void End1(int caz);
void start1(int table[8][8]);
void End1(int caz)
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
    CreareButonText(0,405,800,445,DARKGRAY, DARKGRAY, WHITE, "Highscores",4);
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
                game=1;
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
void start1(int table[8][8])
{
    int wrongCursor=0;
    if(foxwin(table)==true)
    {
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
            selectedPiece(vulpe.i,vulpe.j);
            ERRORMOUSE=1;
            while(ERRORMOUSE==1)
                mouse(spre.i,spre.j);

            if(ERRORMOUSE==0)
            {
                if(validMove(table,vulpe.i,spre.i,vulpe.j,spre.j)==1)
                {
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
            start1(table);
    }


}
void PlayervsPlayer()
{
    score=-1;
    waveOutSetVolume(0,0xFFF);
    PlaySound(TEXT("song.wav"), NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);
    clearmouseclick(WM_LBUTTONDOWN);
    mode=1;
    vulpe.i=0;
    vulpe.j=3;
    turn=1;
    setbkcolor(LIGHTGRAY);
    clearviewport();
    generateMatrix(table);
    drawMatrix();
    drawPion(table);
    printMatrix(table);
    if(mode==1)
        start1(table);
}

#endif // GAME1_H_INCLUDED
