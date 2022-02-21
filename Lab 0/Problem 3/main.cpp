#include <iostream>
#include <math.h>

int main()
{
    uint64_t n, i;
    int64_t a;
    char b;
    bool iscorrect;
    std::cin>>n;
    iscorrect = true;
    a = 0;
    for (i=0; i<n; i++)
    {
        std::cin>>b;
        if(b=='(')
            a++;
        else
            a--;
        if (a<0 && iscorrect == true)
            iscorrect = false;
    }
    if (a==0 && iscorrect == true)
        std::cout<<"Correct";
    else
        std::cout<<"Incorrect";

    return 0;
}
