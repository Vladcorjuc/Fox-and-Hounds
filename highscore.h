#ifndef highscore.h
#define highscore.h
#include "meniuFunctions.h"
#include <fstream>
#include <string.h>

int hscore[30], finalScore1[10],finalScore2[10];
char movess[30][20],indice[11][6];

using namespace std;

void newScore(int sc, int tip)
{
    cout<<sc;
    if (tip==1)
    {
        ifstream in("highscore1");
        int x;
        while (in>>x)
            hscore[x]=1;
        ofstream out("highscore1");
        int nr=0;

        hscore[sc]=1;

        for (int i=0; i<30; i++)
            if (hscore[i])
            {
                out<<i<<" ";
                if (nr<10)
                {
                    nr++;
                    finalScore1[nr]=i;
                }
            }
        in.close();
        out.close();
    }
    else if (tip==2)
    {
        ifstream in2("highscore2");
        int x;
        while (in2>>x)
            hscore[x]=1;
        ofstream out2("highscore2");
        int nr=0;

        hscore[sc]=1;

        for (int i=0; i<30; i++)
            if (hscore[i])
            {
                out2<<i<<" ";
                if (nr<10)
                {
                    nr++;
                    finalScore2[nr]=i;
                }
            }
        in2.close();
        out2.close();
    }
}

void generareHscore(int tip)
{
     if (tip==1)
     {ifstream in("highscore1");
        int x,nr=0;
        while (in>>x)
            hscore[x]=1;
      for (int i=0; i<30; i++)
            if (hscore[i] && nr<10)
                {
                    nr++;
                    finalScore1[nr]=i;
                }
            }
       else if (tip==2)
        {
        ifstream in2("highscore2");
        int x,nr=0;
        while (in2>>x)
            hscore[x]=1;
        for (int i=0; i<30; i++)
            if (hscore[i] && nr<10)
                {
                    nr++;
                    finalScore2[nr]=i;
                }
            }
}

void siruriCaractere()
{
    strcpy(movess[0],"0 moves");
    strcpy(movess[1],"1 moves");
    strcpy(movess[2],"2 moves");
    strcpy(movess[3],"3 moves");
    strcpy(movess[4],"4 moves");
    strcpy(movess[5],"5 moves");
    strcpy(movess[6],"6 moves");
    strcpy(movess[7],"7 moves");
    strcpy(movess[8],"8 moves");
    strcpy(movess[9],"9 moves");
    strcpy(movess[10],"10 moves");
    strcpy(movess[11],"11 moves");
    strcpy(movess[12],"12 moves");
    strcpy(movess[13],"13 moves");
    strcpy(movess[14],"14 moves");
    strcpy(movess[15],"15 moves");
    strcpy(movess[16],"16 moves");
    strcpy(movess[17],"17 moves");
    strcpy(movess[18],"18 moves");
    strcpy(movess[19],"19 moves");
    strcpy(movess[20],"20 moves");
    strcpy(movess[21],"21 moves");
    strcpy(movess[22],"22 moves");
    strcpy(movess[23],"23 moves");
    strcpy(movess[24],"24 moves");
    strcpy(movess[25],"25 moves");
    strcpy(movess[26],"26 moves");
    strcpy(movess[27],"27 moves");
    strcpy(movess[28],"28 moves");
    strcpy(movess[29],"29 moves");
    strcpy(movess[30],"30 moves");

    strcpy(indice[1],"1. ");
    strcpy(indice[2],"2. ");
    strcpy(indice[3],"3. ");
    strcpy(indice[4],"4. ");
    strcpy(indice[5],"5. ");
    strcpy(indice[6],"6. ");
    strcpy(indice[7],"7. ");
    strcpy(indice[8],"8. ");
    strcpy(indice[9],"9. ");
    strcpy(indice[10],"10. ");

}
#endif // highscore.h
