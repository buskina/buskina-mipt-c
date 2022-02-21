#include <iostream>
#include <math.h>

bool simplechecker(uint64_t n)
{
    bool issimple;
    issimple = true;
    for (uint64_t i=2; i*i<=n; i++)
    {
        if (n%i==0 && issimple == true)
            issimple = false;
    }
    if (n==1)
        issimple = false;
    return issimple;

}
bool palychecker(uint64_t n)
{
    bool ispaly;
    uint64_t dignum, digest;
    dignum = 0;
    digest = n;
    for (uint64_t i = 1; i<=n; i=i*10)
    {
        dignum++;
        digest = i;
    }
    ispaly = true;
    for (uint64_t i = 1; i<=dignum/2; i++)
    {
        if (n/digest != n%10 && ispaly == true)
            ispaly = false;
        n = (n%digest)/10;
        digest = digest/100;
    }

    return ispaly;

}
int main()
{
    uint64_t n;
    bool issimple, ispaly;
    std::cin>>n;
    issimple = simplechecker(n);
    ispaly = palychecker(n);
    if (issimple)
        std::cout<<"This number is simple"<<std::endl;
    else
        std::cout<<"This number isn't simple"<<std::endl;
    if (ispaly)
        std::cout<<"This number is palyndrom"<<std::endl;
    else
        std::cout<<"This number isn't palyndrom"<<std::endl;

    return 0;
}
