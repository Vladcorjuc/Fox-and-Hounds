#include <iostream>
#include <winbgim.h>
#include<stdlib.h>
#include "game3.h"
#include "game1.h"
#include "game4.h"
#include "game2.h"
#include <windows.h>
using namespace std;
int main()
{
    initwindow(800,600,"FOX AND HOUNDS");
    FrontPage();
    getch();
    language=1;
    Meniu();
    while(game>0)
    {
    if(game==3)
    Foxvspc();
    if(game==1)
    PlayervsPlayer();
    if(game==4)
    Training();
    if(game==2)
    pcvshounds();
    }
    closegraph();

    return 0;
}
