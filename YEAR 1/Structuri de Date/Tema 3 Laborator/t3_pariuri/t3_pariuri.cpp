#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;

ifstream f("pariuri.in");
ofstream g("pariuri.out");

unordered_map<int,int>SUMA;

int main(){
    int N,M,TIMP,BANI;
    int i,j;

    f>>N;
    for(i=0;i<N;i++){
        f>>M;
        for(j=0;j<M;j++){
            f>>TIMP>>BANI;
            SUMA[TIMP]=SUMA[TIMP]+BANI;
        }
    }

    g<<SUMA.size()<<endl;

    unordered_map<int,int>::iterator ITERATOR;
    for(ITERATOR=SUMA.begin();ITERATOR!=SUMA.end();ITERATOR++)
        g<<ITERATOR->first<<' '<<ITERATOR->second<<' ';

    f.close();
    g.close();
    return 0;
}
