#include <iostream>
using namespace std;

long long t;
long long xp, yp, xq, yq, xr, yr;
long long delta;

int main()
{
    cin>>t;
    for (long long i = 0; i < t; i++)
    {
        // CITIRE
        cin>>xp>>yp>>xq>>yq>>xr>>yr;
        
        // CALCUL DETERMINANT
        delta = xq*yr + xr*yp + xp*yq - xq*yp - xr*yq - xp*yr;

        // LEFT, RIGHT, TOUCH
        if (delta == 0) cout<<"TOUCH"<<endl;
        else if (delta < 0) cout<<"RIGHT"<<endl;
            else cout<<"LEFT"<<endl;
    }
    return 0;
}