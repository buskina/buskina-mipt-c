#include <iostream>
#include <math.h>
#include <random>
#include <chrono>
#include <fstream>

void onemove(int mas[])
{   int next;
    std::mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> dist (0, 3);
    next = dist(rng);
    if (next==1)
    {
        mas[0]--;
    }
    if (next==2)
    {
        mas[0]++;
    }
    if (next==3)
    {
        mas[1]--;
    }
    if (next==0)
    {
        mas[1]++;
    }
}

int experiment(int n) {
    int counter;
    /* int i,j;
    int field[2*n+1][2*n+1];
    for (i=0; i<2*n+1; i++)
    {
        for (j=0; j<2*n+1; j++)
            field[i][j]=0;
    }*/
    int mas[2];
    counter = 0;
    mas[0] = n;
    mas[1] = n;
    while (mas[0]!=0 && mas[1]!=0 && mas[0]!=2*n && mas[1]!=2*n)
    {
        /*field[mas[0]][mas[1]]=0;*/
        onemove(mas);
        /*field[mas[0]][mas[1]]=1;*/
        counter++;
        /*for (i=0; i<2*n+1; i++)
    {
        for (j=0; j<2*n; j++)
            std::cout<<field[i][j];
        std::cout<<field[i][2*n]<<std::endl;
    }
        std::cout<<" "<<std::endl;
    */}
    return counter;
}

int main()
{
    int n, repet_num, i, j, result;
    result = 0;
    std::cin>>n;
    std::ofstream out;
    out.open("res.txt");
    for (j=1; j<=n; j++) {
    repet_num = 200;
    for (i=0; i<repet_num; i++) {result = result + experiment(j);}
    out<<j<<" "<<result/repet_num<<std::endl;}
    out.close();
    return 0;
}

