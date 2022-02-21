#include <iostream>
#include <math.h>

uint64_t dignum(uint64_t n)
{
    uint64_t dignum;
    dignum = 0;
    for (uint64_t i = 1; i<=n; i=i*10)
    {
        dignum++;
    }
    return dignum;

}
int main()
{
    uint64_t n, dig, i;
    std::cin>>n;
    dig = dignum(n);
    uint64_t*mas = new uint64_t[dig];
    for (i=0; i<dig; i++) {*(mas+i) = n%10;
    n = n/10;}
    for (i=0; i<dig; i++) {std::cout<<*(mas+i)<<" ";}
    delete[] mas;
    return 0;
}
