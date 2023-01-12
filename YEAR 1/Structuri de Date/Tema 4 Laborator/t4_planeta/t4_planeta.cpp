#include <iostream>
#include <fstream>

using namespace std;

ifstream f("planeta.in");
ofstream g("planeta.out");

long long catalan[31];

void Catalan(int n)
{
    catalan[0]=1;
    catalan[1]=1;
    for(int i=2;i<=n;i++)
        for(int j=1;j<=i;j++)
            catalan[i]=catalan[i]+catalan[j-1]*catalan[i-j];
   return;
}

void permutare(int stanga,int dreapta,long long k)
{
    int i;
    if(stanga>dreapta)return;

    for(i=stanga;i<=dreapta && catalan[i-stanga]*catalan[dreapta-i]<=k;i++)
         k-=catalan[i-stanga]*catalan[dreapta-i];

    g<<i<<' ';

    if(i>stanga)
        permutare(stanga,i-1,k/catalan[dreapta-i]);
    if(i<dreapta)
        permutare(i+1,dreapta,k%catalan[dreapta-i]);
    return;
}

int main()
{
    int N;
    long long K;
    f>>N>>K;

    Catalan(N);
    permutare(1,N,K-1);

}
