#ifndef DRAW_H_INCLUDED
#define DRAW_H_INCLUDED
int fox,hounds;
int strategy=0,currentLine=7,helper,table[8][8],turn=0,win=0,ERRORMOUSE,mode=1;
int numar=8,width=500,height=500,latura,sus,stanga,x1,y1,score;
char moves[31][20];

struct punct
{
    int i,j;
} vulpe,spre;

void drawFox(int j,int i);

void lag ()

{
    for (long int i=-100000000; i<=100000000; i++);

}

void CreareButonText (int x1, int y1, int x2, int y2, int borderc, int fillc, int textc, char text[], int sizetext)
{
    setcolor(borderc);
    setlinestyle(SOLID_LINE, 0xFFFF, THICK_WIDTH);
    setfillstyle(SOLID_FILL, fillc);
    rectangle(x1, y1, x2, y2);
    floodfill(int((x1+x2)/2), int((y1+y2)/2), borderc);
    setbkcolor(fillc);
    setcolor(textc);
    settextjustify (CENTER_TEXT, CENTER_TEXT);
    settextstyle (BOLD_FONT, HORIZ_DIR, sizetext);
    outtextxy(int((x1+x2)/2), int((y1+y2)/2+8), text);
}

void drawHound(int j,int i);
void deletePiece(int linia, int coloana)
{
    int x1,y1,x2,y2,xmijloc,ymijloc;
    latura=width/numar;
    sus=(getmaxy()-width)/2;
    x1=stanga+latura*(coloana);
    y1=sus+latura*(linia);
    x2=x1+latura;
    y2=y1+latura;
    xmijloc=(x1+x2)/2;
    ymijloc=(y1+y2)/2;
    setcolor(GREEN);
    setlinestyle(SOLID_LINE,0xFFFF,1);
    setfillstyle(SOLID_FILL,LIGHTGREEN);
    rectangle(x1,y1,x2,y2);
    floodfill(stanga+latura*(coloana)+latura/2,sus+latura*(linia)+latura/2,GREEN);
}

void deselectpiece(int linia)
{
    int j;
    for(j=0; j<=7; j++)
        if(table[linia][j]==0)
            deletePiece(linia,j);
    if(turn==1)
    {
        if(linia-2>=0)
        {
            for(j=0; j<=7; j++)
                if(table[linia-2][j]==0)
                    deletePiece(linia-2,j);
        }
        if(linia+2<=7)
        {
            for(j=0; j<=7; j++)
                if(table[linia+2][j]==0)
                    deletePiece(linia+2,j);
        }
    }
}
void selectedPiece(int linia,int coloana)
{
    int x1,y1,x2,y2,xmijloc,ymijloc;
    latura=width/numar;
    sus=(getmaxy()-width)/2;
    x1=stanga+latura*(coloana);
    y1=sus+latura*(linia);
    x2=x1+latura;
    y2=y1+latura;
    xmijloc=(x1+x2)/2;
    ymijloc=(y1+y2)/2;
    setcolor(WHITE);
    setlinestyle(SOLID_LINE,0xFFFF,1);
    rectangle(x1,y1,x2,y2);
    rectangle(x1+1,y1+1,x2-1,y2-1);
    rectangle(x1+2,y1+2,x2-2,y2-2);
    setlinestyle(DOTTED_LINE,0xFFFF,2);
    if(turn==2)
    {
        if(linia-1>=0&&coloana-1>=0)
        {
            if(table[linia-1][coloana-1]==0)
                line(x1,y1,x1-latura/2,y1-latura/2);
        }
        if(linia-1>=0&&coloana+1<=7)
        {
            if(table[linia-1][coloana+1]==0)
                line(x1+latura,y1,x1+latura+latura/2,y1-latura/2);
        }
    }
    if(turn==1)
    {
        if(linia-1>=0&&coloana-1>=0)
        {
            if(table[linia-1][coloana-1]==0)
                line(x1,y1,x1-latura/2,y1-latura/2);
        }
        if(linia-1>=0&&coloana+1<=7)
        {
            if(table[linia-1][coloana+1]==0)
                line(x1+latura,y1,x1+latura+latura/2,y1-latura/2);
        }
        if(linia+1<=7&&coloana-1>=0)
        {
            if(table[linia+1][coloana-1]==0)
                line(x1,y1+latura,x1-latura/2,y1+latura+latura/2);
        }
        if(linia+1<=7&&coloana+1<=7)
        {
            if(table[linia+1][coloana+1]==0)
                line(x2,y2,x2+latura/2,y2+latura/2);
        }
    }
}

void drawMatrix()
{
    int i,j;
    latura=width/numar;
    sus=(getmaxy()-width)/2;
    stanga=(getmaxx()-height)/2;
    setlinestyle(SOLID_LINE,0xFFFF,1);
    setcolor(GREEN);
    for(i=0; i<=7; i++)
        for(j=0; j<=7; j++)
        {
            rectangle(stanga+latura*(i),sus+latura*(j),stanga+latura*(i+1),sus+latura*(j+1));
            if((i+j)%2==0)
            {
                setfillstyle(SOLID_FILL,GREEN);
                floodfill(stanga+latura*i+latura/2,sus+latura*j+latura/2,GREEN);
            }
            else
            {
                setfillstyle(SOLID_FILL,LIGHTGREEN);
                floodfill(stanga+latura*i+latura/2,sus+latura*j+latura/2,GREEN);
            }
        }

    CreareButonText (0, 560, 395, 590, DARKGRAY,DARKGRAY, WHITE, "Meniu",3);
    CreareButonText (405, 560, 800, 590, DARKGRAY,DARKGRAY, WHITE, "Restart",3);

    CreareButonText (0, 10, 800, 40, DARKGRAY,DARKGRAY, WHITE,moves[score],3);
    if (fox==1)
        readimagefile("images/fox1.selected.jpg",30,260,110,340);
    else if (fox==2)
        readimagefile("images/fox2.selected.jpg",30,260,110,340);
    else
        readimagefile("images/fox3.selected.jpg",30,260,110,340);
    if (hounds==1)
        readimagefile("images/dog1.selected.jpg",690,260,770,340);
    else if (hounds==2)
        readimagefile("images/dog2.selected.jpg",690,260,770,340);
    else
        readimagefile("images/dog3.selected.jpg",690,260,770,340);
}

void moveDog(int table[8][8], int i1,int i2,int j1,int j2)
{

    punct moveFrom, moveTo;
    moveFrom.i = i1;
    moveFrom.j = j1;
    moveTo.i = i2;
    moveTo.j = j2;
    deletePiece(moveFrom.i,moveFrom.j);
    table[moveTo.i][moveTo.j]=table[moveFrom.i][moveFrom.j];
    table[moveFrom.i][moveFrom.j]=0;
    turn = 1;
}

void drawPion(int table[8][8])
{
    int i,j;
    for(i=0; i<=7; i++)
        for(j=0; j<=7; j++)
        {
            if(table[i][j]!=0&&table[i][j]!=9)
                drawHound(j,i);
            if(table[i][j]==9)
                drawFox(j,i);
        }
    if(turn==1)
    {
        if (hounds==1)
            readimagefile("images/dog1.jpg",690,260,770,340);
        else if (hounds==2)
            readimagefile("images/dog2.jpg",690,260,770,340);
        else
            readimagefile("images/dog3.jpg",690,260,770,340);
        if (fox==1)
            readimagefile("images/fox1.selected.jpg",30,260,110,340);
        else if (fox==2)
            readimagefile("images/fox2.selected.jpg",30,260,110,340);
        else

            readimagefile("images/fox3.selected.jpg",30,260,110,340);

    }
    else
    {
        if (hounds==1)
            readimagefile("images/dog1.selected.jpg",690,260,770,340);
        else if (hounds==2)
            readimagefile("images/dog2.selected.jpg",690,260,770,340);
        else
            readimagefile("images/dog3.selected.jpg",690,260,770,340);
        if (fox==1)
            readimagefile("images/fox1.jpg",30,260,110,340);
        else if (fox==2)
            readimagefile("images/fox2.jpg",30,260,110,340);
        else

            readimagefile("images/fox3.jpg",30,260,110,340);

    }
    CreareButonText (0, 10, 800, 40, DARKGRAY,DARKGRAY, WHITE,moves[score],3);

}

void drawHound(int j,int i)
{
    latura=width/numar;
    sus=(getmaxy()-width)/2;
    stanga=(getmaxx()-height)/2;
    if(hounds==1)
        readimagefile("images/dog1.table.jpg",stanga+latura*(j),sus+latura*(i),stanga+latura*(j+1),sus+latura*(i+1));
    else if(hounds==2)
        readimagefile("images/dog2.table.jpg",stanga+latura*(j),sus+latura*(i),stanga+latura*(j+1),sus+latura*(i+1));
    else if(hounds==3)
        readimagefile("images/dog3.table.jpg",stanga+latura*(j),sus+latura*(i),stanga+latura*(j+1),sus+latura*(i+1));

}

void drawFox(int j,int i)
{
    latura=width/numar;
    sus=(getmaxy()-width)/2;
    stanga=(getmaxx()-height)/2;
    if(fox==1)
        readimagefile("images/fox1.table.jpg",stanga+latura*(j),sus+latura*(i),stanga+latura*(j+1),sus+latura*(i+1));
    else if(fox==2)
        readimagefile("images/fox2.table.jpg",stanga+latura*(j),sus+latura*(i),stanga+latura*(j+1),sus+latura*(i+1));
    else if(fox==3)
        readimagefile("images/fox3.table.jpg",stanga+latura*(j),sus+latura*(i),stanga+latura*(j+1),sus+latura*(i+1));

}

#endif // DRAW_H_INCLUDED
