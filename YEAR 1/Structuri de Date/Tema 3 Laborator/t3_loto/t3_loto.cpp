#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;

ifstream f("loto.in");
ofstream g("loto.out");

int N,S,i,j,k;
int NR_POSIBILE[101];

unordered_map<int, tuple<int,int,int>> COMBINATIE;

int main()
{
    f>>N>>S;
    for(i=0;i<N;++i)
        f>>NR_POSIBILE[i];

    for(i=0;i<N;++i)
        for(j=i;j<N;++j)
            for(k=j;k<N;++k)
                COMBINATIE[NR_POSIBILE[i]+NR_POSIBILE[j]+NR_POSIBILE[k]] = make_tuple(NR_POSIBILE[i],NR_POSIBILE[j],NR_POSIBILE[k]);

    for(i=0;i<N;++i)
        for(j=i;j<N;++j)
            for(k=j;k<N;++k)
                if(COMBINATIE.find(S-NR_POSIBILE[i]-NR_POSIBILE[j]-NR_POSIBILE[k])!=COMBINATIE.end())
                {
                    tuple<int,int,int> T_AUX=COMBINATIE[S-NR_POSIBILE[i]-NR_POSIBILE[j]-NR_POSIBILE[k]];
                    g<<NR_POSIBILE[i]<<' '<<NR_POSIBILE[j]<<' '<<NR_POSIBILE[k]<<' '<<get<0>(T_AUX)<<' '<<get<1>(T_AUX)<<' '<<get<2>(T_AUX);
                    return 0;
                }
    g<<-1;
    return 0;
}
