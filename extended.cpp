#include<bits/stdc++.h>
using namespace std;
//Based on extended euclid algo gcd(a,b)=a*x+b*y
int d, x, y;
void extended(int a, int b) {
    if(b==0) 
    {
        d = a;
        x = 1;
        y = 0;
    }
    else
    {
        extended(b,a%b);
        int temp=x;
        x=y;
        y=temp-(a/b)*y;
    }
}
int main()
{
     extended(8,4);
     cout<<"GCD of 8 and 4 is "<<d<<endl;
}