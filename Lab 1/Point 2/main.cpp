#include <iostream>
#include <math.h>
#include <random>
#include <chrono>
#include <fstream>

const int dislnum = 10;
const int fsize = 30;
int field[fsize][fsize];
int disl[dislnum][3];

void filling()
{
    int i, j, x, y;
    std::mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());
    for (i = 0; i < fsize; i++)
    {
        for (j = 0; j < fsize; j++)
            field[i][j]=0;
    }
    i = 0;
    while(i < dislnum)
    {
        std::uniform_int_distribution<int> dist (0, fsize);
        x = dist(rng);
        y = dist(rng);
        if (field[x][y]!=1)
        {
            field[x][y] = 1;
            disl[i][0] = x;
            disl[i][1] = y;
            i++;
        }
    }
}

bool staticcheck(int x, int y)
{
    if (x==0 || y==0 || x==fsize-1 || y==fsize-1)
    {
        return true;
    }
    else
    {
        if (field[x-1][y]!=0 || field[x+1][y]!=0 || field[x][y-1]!=0 || field[x][y+1]!=0)
            return true;
        else
            return false;
    }

}

void fstaticcheck ()
{
    for (int i=0; i<dislnum; i++)
    {
        if (field[disl[i][0]][disl[i][1]]!=3 && staticcheck(disl[i][0], disl[i][1]))
        {
            field[disl[i][0]][disl[i][1]] = 3;
        }
    }
}

bool finishcheck ()
{
    for (int i=0; i<dislnum; i++)
    {
        if (field[disl[i][0]][disl[i][1]]==1 && !staticcheck(disl[i][0], disl[i][1]))
        {
            return false;
        }
    }
    return true;
}

void print()
{
    int i,j;
    for (i=0; i<fsize; i++)
    {
        for (j=0; j<fsize-1; j++)
            std::cout<<field[i][j];
        std::cout<<field[i][fsize-1]<<std::endl;
    }
    std::cout<<" "<<std::endl;
}

void refresh()
{
    for (int i=0; i<dislnum; i++)
    {
        if (field[disl[i][0]][disl[i][1]] == 2)
            field[disl[i][0]][disl[i][1]] = 1;
    }
}

void choosedir()
{
    for (int i=0; i<dislnum; i++)
    {
        std::mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());
        std::uniform_int_distribution<int> dist (0, 3);
        disl[i][3] = dist(rng);
    }
}

void onemove()
{
    for (int i=0; i<dislnum; i++)
    {
        if (field[disl[i][0]][disl[i][1]] ==1 && disl[i][3]==0)
        {
            field[disl[i][0]][disl[i][1]] = 0;
            disl[i][0]--;
            field[disl[i][0]][disl[i][1]] = 2;
        }
    }
    for (int i=0; i<dislnum; i++)
    {
        if (field[disl[i][0]][disl[i][1]] ==1 && disl[i][3]==1 && field[disl[i][0]+1][disl[i][1]]!=2 )
        {
            field[disl[i][0]][disl[i][1]] = 0;
            disl[i][0]++;
            field[disl[i][0]][disl[i][1]] = 2;
        }
        else
        {
            field[disl[i][0]][disl[i][1]] = 3;
            field[disl[i][0]+1][disl[i][1]] = 3;
        }
    }
    for (int i=0; i<dislnum; i++)
    {
        if (field[disl[i][0]][disl[i][1]] ==1 && disl[i][3]==2 && field[disl[i][0]][disl[i][1]-1]!=2 )
        {
            field[disl[i][0]][disl[i][1]] = 0;
            disl[i][1]--;
            field[disl[i][0]][disl[i][1]] = 2;
        }
        else
        {
            field[disl[i][0]][disl[i][1]] = 3;
            field[disl[i][0]][disl[i][1]-1] = 3;
        }
    }
    for (int i=0; i<dislnum; i++)
    {
        if (field[disl[i][0]][disl[i][1]] ==1 && disl[i][3]==3 && field[disl[i][0]][disl[i][1]+1]!=2 )
        {
            field[disl[i][0]][disl[i][1]] = 0;
            disl[i][1]++;
            field[disl[i][0]][disl[i][1]] = 2;
        }
        else
        {
            field[disl[i][0]][disl[i][1]] = 3;
            field[disl[i][0]][disl[i][1]+1] = 3;
        }
    }
}

int main()
{
    filling();

    while(!finishcheck())
    {
        fstaticcheck();
        choosedir();
        onemove();
        refresh();
        print();

    }


    /*std::ofstream out;
    out.open("res.txt");
    for (j=1; j<=n; j++)
    {
        repet_num = 200;
        for (i=0; i<repet_num; i++)
        {
            result = result + experiment(j);
        }
        out<<j<<" "<<result/repet_num<<std::endl;
    }
    out.close();*/
    return 0;
}


