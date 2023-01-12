#include <iostream>
#include <fstream>
using namespace std;

ifstream f("timbre.in");
ofstream g("timbre.out");

int N,M,K,COST_MINIM,i;
long long TOTAL=0;

int main()
{
    f>>N>>M>>K;

    pair<int,int> INTERVAL[11000];

    for(i=0;i<M;i++)
        f>>INTERVAL[i].first>>INTERVAL[i].second;

    while(N>0)
    {
        int j=-1;
        COST_MINIM=10000;
        for(i=0;i<M;i++)
            if(INTERVAL[i].first>=N
               && INTERVAL[i].second<COST_MINIM
               && INTERVAL[i].first>-1)
            {
                j=i;
                COST_MINIM=INTERVAL[i].second;
            }
        TOTAL=TOTAL+COST_MINIM;
        INTERVAL[j].first=-1;
        N=N-K;
    }
    g<<TOTAL;
    return 0;
}
