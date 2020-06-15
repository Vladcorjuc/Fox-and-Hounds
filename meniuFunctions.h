#ifndef MENIUFUNCTIONS_H_INCLUDED
#define MENIUFUNCTIONS_H_INCLUDED

#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <winbgim.h>
#include <stdlib.h>
#include<cstring>
#include "startGame.h"
#include "draw.h"
#include "highscore.h"
using namespace std;

#define Fundal LIGHTGRAY

float x,y;
int game,language;
void Highscore();
void HowToPlay();
void Play();
void Meniu()
{
    waveOutSetVolume(0, 0xFFFFF);
    PlaySound(TEXT("Clickbutton.wav"), NULL, SND_FILENAME | SND_ASYNC);
    setbkcolor(Fundal);
    clearviewport();
    setcolor(RED);
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    settextstyle(BOLD_FONT, HORIZ_DIR, 6);
    if(language==1)
        outtextxy(400, 70, "Menu");
    else
        outtextxy(400, 70, "Meniu");
    if(language==1)
    {
        CreareButonText(0, 210, 800, 280, DARKGRAY, DARKGRAY, WHITE, "PLAY", 6);
        CreareButonText(0, 310, 800, 380, DARKGRAY, DARKGRAY, WHITE, "HOW TO PLAY", 6);
        CreareButonText(0, 410, 800, 445, DARKGRAY, DARKGRAY, WHITE, "Highscore", 3);
        CreareButonText(0, 560, 800, 590, DARKGRAY, DARKGRAY, WHITE, "EXIT", 3);
    }
    else
    {
        CreareButonText(0, 210, 800, 280, DARKGRAY, DARKGRAY, WHITE, "JOACA", 6);
        CreareButonText(0, 310, 800, 380, DARKGRAY, DARKGRAY, WHITE, "INSTRUCTIUNI", 6);
        CreareButonText(0, 410, 800, 445, DARKGRAY, DARKGRAY, WHITE, "Highscore", 3);
        CreareButonText(0, 560, 800, 590, DARKGRAY, DARKGRAY, WHITE, "IESIRE", 3);

    }
    if(language==1)
    {
        readimagefile("images/romanian.jpg", 730 , 10, 780, 60);
        readimagefile("images/english.selected.jpg", 728 ,60,782,110);

    }
    else
    {

        readimagefile("images/romanian.selected.jpg", 730 , 10, 780, 60);
        readimagefile("images/english.jpg", 728 ,60,782,110);
    }

BEGIN1:
    do
    {
        clearmouseclick(WM_LBUTTONDOWN);
        x = mousex();
        y = mousey();
    }
    while (!ismouseclick(WM_LBUTTONDOWN));
    if (y > 210 && y < 280)
    {
        waveOutSetVolume(0, 0xFFFFF);
        PlaySound(TEXT("Clickbutton.wav"), NULL, SND_FILENAME | SND_ASYNC);
        if(language==1)
            CreareButonText(0, 210, 800, 280, WHITE, WHITE, DARKGRAY, "PLAY", 6);
        else
            CreareButonText(0, 210, 800, 280, WHITE, WHITE, DARKGRAY, "JOACA", 6);
        lag();
        Play();
    }
    else if (y > 310 && y < 380)
    {
        waveOutSetVolume(0, 0xFFFFF);
        PlaySound(TEXT("Clickbutton.wav"), NULL, SND_FILENAME | SND_ASYNC);
        if(language==1)
            CreareButonText(0, 310, 800, 380, WHITE, WHITE, DARKGRAY, "        HOW TO PLAY        ", 6);
        else
            CreareButonText(0, 310, 800, 380, WHITE, WHITE, DARKGRAY, "INSTRUCTIUNI", 6);
        lag();
        HowToPlay();
    }
    else if (y > 410 && y < 445)
    {
        waveOutSetVolume(0, 0xFFFFF);
        PlaySound(TEXT("Clickbutton.wav"), NULL, SND_FILENAME | SND_ASYNC);
        CreareButonText(10, 410, 800, 445, WHITE, WHITE, DARKGRAY, "Highscore", 3);
        lag();
        Highscore();
    }
    else if (y > 560 && y < 590)
    {
        waveOutSetVolume(0, 0xFFFFF);
        PlaySound(TEXT("Clickexit.wav"), NULL, SND_FILENAME | SND_ASYNC);
        if(language==1)
            CreareButonText(0, 560, 800, 590, WHITE, WHITE, DARKGRAY, "EXIT", 3);
        else
            CreareButonText(0, 560, 800, 590, WHITE, WHITE, DARKGRAY, "IESIRE", 3);
        game = -1;
    }
    else if (x>730 && x<780 && y>10 && y<60)
    {
        readimagefile("images/romanian.selected.jpg", 730 , 10, 780, 60);
        lag();
        language=2;
        Meniu();
    }
    else if (x>728 && x<782 && y>60 && y<110)
    {
        readimagefile("images/english.selected.jpg", 728 ,60,782,110);
        lag();
        language=1;
        Meniu();
    }

    else goto BEGIN1;

}
void FoxType();
void DogType()
{
    setbkcolor(Fundal);
    clearviewport();
    setcolor(RED);
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    settextstyle(BOLD_FONT,HORIZ_DIR,6);
    if(language==1)
        outtextxy(400,70,"Type of Dog");
    else
        outtextxy(400,70,"Tipul de caine");
    readimagefile("images/dog1.jpg",350,100,450,200);
    readimagefile("images/dog2.jpg",350,225,450,325);
    readimagefile("images/dog3.jpg",350,350,450,450);
    if(language==1)
        CreareButonText (0, 560, 800, 590, DARKGRAY, DARKGRAY, WHITE, "back",3);
    else
        CreareButonText (0, 560, 800, 590, DARKGRAY, DARKGRAY, WHITE, "inapoi",3);

BEGIN2:
    do
    {
        clearmouseclick(WM_LBUTTONDOWN);
        x=mousex();
        y=mousey();
    }
    while(!ismouseclick(WM_LBUTTONDOWN));
    if (y>560 && y<590)
    {
        waveOutSetVolume(0,0xFFFFF);
        PlaySound(TEXT("Clickexit.wav"), NULL, SND_FILENAME|SND_ASYNC);
        if(language==1)
            CreareButonText (0, 560, 800, 590, WHITE, WHITE, DARKGRAY, "back",3);
        else
            CreareButonText (0, 560, 800, 590, WHITE, WHITE, DARKGRAY, "inapoi",3);
        lag();
        FoxType();
    }
    else if (x>350 && x<450)
    {
        waveOutSetVolume(0,0xFFFFF);
        PlaySound(TEXT("Clickpiece.wav"), NULL, SND_FILENAME|SND_ASYNC);


        if (y>100 && y<200)
        {
            readimagefile("images/dog1.selected.jpg",350,100,450,200);
            lag();
            hounds=1;
        }
        else if (y>225 && y<325)
        {
            readimagefile("images/dog2.selected.jpg",350,225,450,325);
            lag();
            hounds=2;
        }
        else if (y>350 && y<450)
        {
            readimagefile("images/dog3.selected.jpg",350,350,450,450);
            lag();
            hounds=3;
        }
    }
    else goto BEGIN2;
}
void FoxType()
{
    setbkcolor(Fundal);
    clearviewport();
    setcolor(RED);
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    settextstyle(BOLD_FONT,HORIZ_DIR,6);
    if(language==1)
        outtextxy(400,70,"Type of fox");
    else
        outtextxy(400,70,"Tipul de vulpe");

    readimagefile("images/fox1.jpg",350,100,450,200);
    readimagefile("images/fox2.jpg",350,225,450,325);
    readimagefile("images/fox3.jpg",350,350,450,450);
    if(language==1)
        CreareButonText (0, 560, 800, 590, DARKGRAY, DARKGRAY, WHITE, "back",3);
    else
        CreareButonText (0, 560, 800, 590, DARKGRAY, DARKGRAY, WHITE, "inapoi",3);
BEGIN3:
    do
    {
        clearmouseclick(WM_LBUTTONDOWN);
        x=mousex();
        y=mousey();
    }
    while(!ismouseclick(WM_LBUTTONDOWN));
    if (y>560 && y<590)
    {
        waveOutSetVolume(0,0xFFFFF);
        PlaySound(TEXT("Clickexit.wav"), NULL, SND_FILENAME|SND_ASYNC);
        if(language==1)
            CreareButonText (0, 560, 800, 590, WHITE, WHITE, DARKGRAY, "back",3);
        else
            CreareButonText (0, 560, 800, 590, WHITE, WHITE, DARKGRAY, "inapoi",3);
        lag();
        Play();
    }
    else if (x>350 && x<450 && y>100 && y<200 )
    {
        waveOutSetVolume(0,0xFFFFF);
        PlaySound(TEXT("Clickpiece.wav"), NULL, SND_FILENAME|SND_ASYNC);
        readimagefile("images/fox1.selected.jpg",350,100,450,200);
        lag();
        fox=1;
        DogType();
    }
    else if (x>350 && x<450 && y>225 && y<325)
    {
        waveOutSetVolume(0,0xFFFFF);
        PlaySound(TEXT("Clickpiece.wav"), NULL, SND_FILENAME|SND_ASYNC);
        readimagefile("images/fox2.selected.jpg",350,225,450,325);
        lag();
        fox=2;
        DogType();
    }
    else if (x>350 && x<450 && y>350 && y<450)
    {
        waveOutSetVolume(0,0xFFFFF);
        PlaySound(TEXT("Clickpiece.wav"), NULL, SND_FILENAME|SND_ASYNC);
        readimagefile("images/fox3.selected.jpg",350,350,450,450);
        lag();
        fox=3;
        DogType();
    }
    else goto BEGIN3;
}


void Play()
{
    setbkcolor(Fundal);
    clearviewport();
    setcolor(RED);
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    settextstyle(BOLD_FONT,HORIZ_DIR,6);
    if(language==1)
        outtextxy(400,70,"Type of game");
    else
        outtextxy(400,70,"Modul de joc");
    CreareButonText (0, 145, 800, 215, DARKGRAY, DARKGRAY, WHITE, "player vs player",4);
    if(language==1)
    {
        CreareButonText (0, 245, 800, 315, DARKGRAY, DARKGRAY, WHITE, "fox vs player",4);
        CreareButonText (0, 345, 800, 415, DARKGRAY, DARKGRAY, WHITE, "player vs dogs",4);
        CreareButonText (0, 560, 800, 590, DARKGRAY, DARKGRAY, WHITE, "back",3);
    }
    else
    {
        CreareButonText (0, 245, 800, 315, DARKGRAY, DARKGRAY, WHITE, "vulpe vs player",4);
        CreareButonText (0, 345, 800, 415, DARKGRAY, DARKGRAY, WHITE, "player vs caine",4);
        CreareButonText (0, 560, 800, 590, DARKGRAY, DARKGRAY, WHITE, "inapoi",3);
    }

BEGIN4:
    do
    {
        clearmouseclick(WM_LBUTTONDOWN);
        x=mousex();
        y=mousey();
        for(long i=0; i<=1000000; i++);
    }
    while(!ismouseclick(WM_LBUTTONDOWN));
    if (y>145 && y<215)
    {
        waveOutSetVolume(0,0xFFFFF);
        PlaySound(TEXT("Clickbutton.wav"), NULL, SND_FILENAME|SND_ASYNC);
        game=1;
        CreareButonText (0, 145, 800, 215, WHITE, WHITE, DARKGRAY, "player vs player",4);
        lag();
        FoxType();
    }
    else if (y>245 && y<315 )
    {
        waveOutSetVolume(0,0xFFFFF);
        PlaySound(TEXT("Clickbutton.wav"), NULL, SND_FILENAME|SND_ASYNC);
        game=2;
        if(language==1)
            CreareButonText (0, 245, 800, 315, WHITE, WHITE, DARKGRAY, "fox vs player",4);
        else
            CreareButonText (0, 245, 800, 315, WHITE, WHITE, DARKGRAY, "vulpe vs player",4);
        lag();
        FoxType();
    }
    else if (y>345 && y<415)
    {
        waveOutSetVolume(0,0xFFFFF);
        PlaySound(TEXT("Clickbutton.wav"), NULL, SND_FILENAME|SND_ASYNC);
        if(language==1)
            CreareButonText (0, 345, 800, 415, WHITE, WHITE, DARKGRAY, "player vs dogs",4);
        else
            CreareButonText (0, 345, 800, 415, WHITE, WHITE, DARKGRAY, "player vs caine",4);
        lag();
        game=3;
        FoxType();
    }
    else if (y>560 && y<590)
    {
        waveOutSetVolume(0,0xFFFFF);
        PlaySound(TEXT("Clickexit.wav"), NULL, SND_FILENAME|SND_ASYNC);
        if(language==1)
            CreareButonText (0, 560, 800, 590, WHITE, WHITE, DARKGRAY, "back",3);
        else
            CreareButonText (0, 560, 800, 590, WHITE, WHITE, DARKGRAY, "inapoi",3);

        lag();
        Meniu();
    }
    else goto BEGIN4;
}

void HowToPlay()
{
    setbkcolor(Fundal);
    clearviewport();
    setcolor(RED);
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    settextstyle(BOLD_FONT,HORIZ_DIR,6);
    if(language==1)
    {
        outtextxy(400,70,"How to play");
        settextjustify(LEFT_TEXT,LEFT_TEXT);
        settextstyle(BOLD_FONT,HORIZ_DIR,3);
        outtextxy(40,130,"The objective of the fox is to cross from one side of");
        outtextxy(30,150,"the board to the other, arriving at any one of the");
        outtextxy(30,170,"hounds' original squares; the hounds' objective is to");
        outtextxy(30,190,"prevent it from doing so.");
        outtextxy(40,210,"The hounds move like a draughts man, diagonally");
        outtextxy(30,230,"forward one square. The fox moves like a draughts");
        outtextxy(30,250,"king, diagonally forward or backward one square.");
        outtextxy(30,270,"However there is no jumping,promotion, or removal");
        outtextxy(30,290,"of pieces. The play alternates with the fox moving");
        outtextxy(30,310,"first. The player controlling the hounds may move");
        outtextxy(30,330,"only one of them each turn.");
        outtextxy(40,350,"The fox is trapped when it can no longer move to a");
        outtextxy(30,370,"vacant square. It is possible for two hounds to trap");
        outtextxy(30,390,"the fox against an edge of the board (other than their");
        outtextxy(30,410,"original home-row) or even one corner where a single");
        outtextxy(30,430,"hound may do the trapping. Should a hound reach the ");
        outtextxy(30,450,"fox's original home row it will be unable to move");
        outtextxy(30,470,"further.");
        CreareButonText (0, 520, 800, 550, DARKGRAY, DARKGRAY, WHITE, "easy training",3);
        CreareButonText (0, 560, 800, 590, DARKGRAY, DARKGRAY, WHITE, "back",3);
    }
    else
    {
        outtextxy(400,70,"Instructiuni");
        settextjustify(LEFT_TEXT,LEFT_TEXT);
        settextstyle(BOLD_FONT,HORIZ_DIR,3);
        outtextxy(30,130,"Obiectivul vulpii este acela de a traversa de");
        outtextxy(30,150,"la un capat la altul tabla de joc pe cand");
        outtextxy(30,170,"obiectivul cainilor este cel de a preveni asta.");
        outtextxy(30,190,"Cainii pot muta pe diagonala dar doar inainte si");
        outtextxy(30,210,"doar o casuta, iar vulpea poate muta pe diagonala");
        outtextxy(30,230,"inainte si inapoi doar o casuta.");
        outtextxy(30,250,"Vulpea este capturata cand nu mai poate muta.");
        outtextxy(30,270,"O variatie a jocului presupune victoria vulpii");
        outtextxy(30,290,"atunci cand aceasta se afla pe acelasi rand cu cel");
        outtextxy(30,310,"mai de jos caine(cel mai apropiat de pozitia de start).");
        outtextxy(30,330,"only one of them each turn.");
        outtextxy(30,330,"Jocul continua pana cand castiga ori vulpea ori cainii.");
        CreareButonText (0, 520, 800, 550, DARKGRAY, DARKGRAY, WHITE, "antrenament",3);
        CreareButonText (0, 560, 800, 590, DARKGRAY, DARKGRAY, WHITE, "inapoi",3);
    }
BEGIN5:
    do
    {
        clearmouseclick(WM_LBUTTONDOWN);
        x=mousex();
        y=mousey();
    }
    while(!ismouseclick(WM_LBUTTONDOWN));
    if(y>560 && y<590)
    {
        waveOutSetVolume(0,0xFFFFF);
        PlaySound(TEXT("Clickexit.wav"), NULL, SND_FILENAME|SND_ASYNC);
        if(language==1)
            CreareButonText (0, 560, 800, 590, WHITE, WHITE, DARKGRAY, "back",3);
        else
            CreareButonText (0, 560, 800, 590, WHITE, WHITE, DARKGRAY, "inapoi",3);
        lag();
        Meniu();
    }
    else if (y>520 && y<550)
    {
        waveOutSetVolume(0,0xFFFFF);
        PlaySound(TEXT("Clickbutton.wav"), NULL, SND_FILENAME|SND_ASYNC);

        game=4;
        if(language==1)
            CreareButonText (0, 520, 800, 550, WHITE, WHITE, DARKGRAY, "easy training",3);
        else
            CreareButonText (0, 520, 800, 550, WHITE, WHITE, DARKGRAY, "antrenament",3);
        lag();
        FoxType();
    }
    else goto BEGIN5;
}
void Highscore()
{
    setbkcolor(Fundal);
    clearviewport();
    setcolor(RED);
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    settextstyle(BOLD_FONT, HORIZ_DIR, 6);
    outtextxy(400, 70, "Highscore");
    CreareButonText (0, 245, 800, 315, DARKGRAY, DARKGRAY, WHITE, "fox vs player",4);
    CreareButonText (0, 335, 800, 405, DARKGRAY, DARKGRAY, WHITE, "player vs dogs",4);
    CreareButonText(0, 560, 800, 590, DARKGRAY, DARKGRAY, WHITE, "back", 3);

    int x,y;
START:
    do
    {
        clearmouseclick(WM_LBUTTONDOWN);
        x = mousex();
        y = mousey();
    }
    while (!ismouseclick(WM_LBUTTONDOWN));

    if (y > 560 && y < 590)
    {
        CreareButonText(0, 560, 800, 590, WHITE, WHITE, DARKGRAY, "back", 3);
        waveOutSetVolume(0, 0xFFFFF);
        PlaySound(TEXT("Clickexit.wav"), NULL, SND_FILENAME | SND_ASYNC);
        lag();
        Meniu();
    }
    else if (y>245 && y<315)
    {
        CreareButonText (0, 245, 800, 315, WHITE, WHITE, DARKGRAY, "fox vs player",4);
        waveOutSetVolume(0, 0xFFFFF);
        PlaySound(TEXT("Clickbutton.wav"), NULL, SND_FILENAME | SND_ASYNC);
        lag();
        setbkcolor(Fundal);
        clearviewport();
        setcolor(RED);
        settextjustify(CENTER_TEXT, CENTER_TEXT);
        settextstyle(BOLD_FONT, HORIZ_DIR, 5);
        outtextxy(400, 70, "Highscore - Vulpe vs player");
        CreareButonText(0, 560, 800, 590, DARKGRAY, DARKGRAY, WHITE, "back", 3);

        int up=110,down=135;
        char hh[20];
        generareHscore(2);
        for (int i=1; i<=10; i++)
        {
            CreareButonText(0, up ,800, down, RED, RED, WHITE, "" ,1);
            siruriCaractere();
            strcpy(hh, indice[i]);
            strcat(hh, movess[finalScore2[i]]);
            setcolor(WHITE);
            settextjustify (CENTER_TEXT, CENTER_TEXT);
            settextstyle (BOLD_FONT, HORIZ_DIR, 1);
            outtextxy( 400, int (up+down)/2+6, hh );
            up=down+15;
            down=up+25;
        }
        int x,y;
STARTback1:
        do
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x = mousex();
            y = mousey();
        }
        while (!ismouseclick(WM_LBUTTONDOWN));
        if (y>560 && y<590)
        {
            CreareButonText(0, 560, 800, 590, WHITE, WHITE, DARKGRAY, "back", 3);
            waveOutSetVolume(0, 0xFFFFF);
            PlaySound(TEXT("Clickexit.wav"), NULL, SND_FILENAME | SND_ASYNC);
            lag();
            Highscore();
        }
        else goto STARTback1;
    }
    else if (y>335 && y<405)
    {
        CreareButonText (0, 335, 800, 405, WHITE, WHITE, DARKGRAY, "player vs dogs",4);
        waveOutSetVolume(0, 0xFFFFF);
        PlaySound(TEXT("Clickbutton.wav"), NULL, SND_FILENAME | SND_ASYNC);
        lag();
        setbkcolor(Fundal);
        clearviewport();
        setcolor(RED);
        settextjustify(CENTER_TEXT, CENTER_TEXT);
        settextstyle(BOLD_FONT, HORIZ_DIR, 5);
        outtextxy(400, 70, "Highscore - player vs dogs");
        CreareButonText(0, 560, 800, 590, DARKGRAY, DARKGRAY, WHITE, "back", 3);

        int up=110,down=135;
        char hh[20];
        generareHscore(1);
        for (int i=1; i<=10; i++)
        {
            CreareButonText(0, up ,800, down, RED, RED, WHITE, "" ,1);
            siruriCaractere();
            strcpy(hh, indice[i]);
            strcat(hh, movess[finalScore1[i]]);
            setcolor(WHITE);
            settextjustify (CENTER_TEXT, CENTER_TEXT);
            settextstyle (BOLD_FONT, HORIZ_DIR, 1);
            outtextxy( 400, int (up+down)/2+6, hh );
            up=down+15;
            down=up+25;
        }
        int x,y;
STARTback2:
        do
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x = mousex();
            y = mousey();
        }
        while (!ismouseclick(WM_LBUTTONDOWN));
        if (y>560 && y<590)
        {
            CreareButonText(0, 560, 800, 590, WHITE, WHITE, DARKGRAY, "back", 3);
            waveOutSetVolume(0, 0xFFFFF);
            PlaySound(TEXT("Clickexit.wav"), NULL, SND_FILENAME | SND_ASYNC);
            lag();
            Highscore();
        }
        else goto STARTback2;
    }
    else goto START;
}

void FrontPage()
{
    setbkcolor(Fundal);
    clearviewport();
    setcolor(RED);
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    settextstyle(BOLD_FONT,HORIZ_DIR,8);
    outtextxy(400,300,"FOX AND HOUNDS");
    setcolor(DARKGRAY);
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    settextstyle(BOLD_FONT,HORIZ_DIR,1);
    outtextxy(400,565,"Proiect realizat de");
    outtextxy(400,580,"Balan Teodora si Corjuc Vlad");
    outtextxy(400,595,"grupa B2");
}

#endif // MENIUFUNCTIONS_H_INCLUDED
