


#ifndef GAMEBASIS_H_INCLUDED
#define GAMEBASIS_H_INCLUDED
bool validMove(int table[8][8],int i1,int i2,int j1,int j2)
{
    punct moveTo,moveFrom;
    moveFrom.i=i1;
    moveFrom.j=j1;
    moveTo.i=i2;
    moveTo.j=j2;
    if( table[moveTo.i][moveTo.j]==0 )
    {
        if(table[moveFrom.i][moveFrom.j]==9)
        {
            if((moveTo.i == moveFrom.i + 1 && moveTo.j == moveFrom.j + 1) ||
                    (moveTo.i == moveFrom.i + 1 && moveTo.j == moveFrom.j - 1) ||
                    (moveTo.i == moveFrom.i - 1 && moveTo.j == moveFrom.j + 1) ||
                    (moveTo.i == moveFrom.i - 1 && moveTo.j == moveFrom.j - 1) )
                return true;
            return false;
        }
        else
        {
            if((moveTo.i == moveFrom.i - 1 && moveTo.j == moveFrom.j + 1) ||
                    (moveTo.i == moveFrom.i - 1 && moveTo.j == moveFrom.j - 1))
                return true;
            return false;

        }

    }
    return false;


}
bool foxwin(int table[8][8])
{
    int i,j;
    for(i=vulpe.i+1; i<=7; i++)
        for(j=0; j<=7; j++)
            if(table[i][j]!=0)
                return false;
    return true;


}
bool dogwin(int table[8][8])
{
    int i,j;
    for(i=0; i<=7; i++)
        for(j=0; j<=7; j++)
            if((table[i][j]==9)&&
                    ((table[i-1][j-1]!=0)||(i-1)<0||(j-1)<0)&&
                    ((table[i-1][j+1]!=0)||(i-1)<0||(j+1)>7)&&
                    ((table[i+1][j-1]!=0)||(i+1)>7||(j-1)<0)&&
                    ((table[i+1][j+1]!=0)||(i+1)>7||(j+1)>7))
                return true;
    return false;
}
void generateMatrix(int table[8][8])
{
    int i,j;
    for(i=0; i<=7; i++)
        for(j=0; j<=7; j++)
        {
            table[i][j] = 0;
        }

    table[7][0] = 1;
    table[7][2] = 2;
    table[7][4] = 3;
    table[7][6] = 4;
    table[0][3] = 9;//vulpe
}
void printMatrix(int table[8][8])
{
    for(int i=0; i<=7; i++)
    {
        for(int j=0; j<=7; j++)
            cout<<table[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"strategia="<<strategy<<"\n";
    cout<<"linia="<<currentLine<<"\n";
}
void mouse(int &x,int &y)
{
    if(ismouseclick(WM_LBUTTONDOWN))
    {
        clearmouseclick(WM_LBUTTONDOWN);
        x=mousex();
        y=mousey();
        if (!(x>=stanga && x<=stanga+width && y>=sus&&y<=sus+height))
            ERRORMOUSE=1;
        ///pentru MENU si RESTART
        if(y>=560&&y<=590)
        {
            ERRORMOUSE=2;
            x1=x;
            y1=y;
        }
        ///pentru UNDO
        else if(y>=60&&y<=120&&x>=700&&x<=760)
            {
                ERRORMOUSE=3;
                x1=x;
                y1=y;
            }
        else
        {
            ERRORMOUSE=0;
            int aux=x;
            x=(y-sus)/latura;
            y=(aux-stanga)/latura;

        }
    }
}
#endif // GAMEBASIS_H_INCLUDED
