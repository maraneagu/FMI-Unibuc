#include <iostream>
#include <fstream>
#include <deque>
using namespace std;

ifstream f("vila2.in");
ofstream g("vila2.out");

int main(){
    int N,K,dif,DIFMAX=-1;
    f>>N>>K;
    int V[N];

    std::deque<int> DEQUE_MIN;
    std::deque<int> DEQUE_MAX;

    int i;
    for(i=0;i<N;i++){
        f>>V[i];

        while(!DEQUE_MIN.empty() && V[i]<V[DEQUE_MIN.back()])
            DEQUE_MIN.pop_back();
        DEQUE_MIN.push_back(i);

        while(!DEQUE_MAX.empty() && V[i]>V[DEQUE_MAX.back()])
            DEQUE_MAX.pop_back();
        DEQUE_MAX.push_back(i);

        if(DEQUE_MIN.front()==i-K-1)
            DEQUE_MIN.pop_front();

        if(DEQUE_MAX.front()==i-K-1)
            DEQUE_MAX.pop_front();

        if(i>=K){
            dif=V[DEQUE_MAX.front()]-V[DEQUE_MIN.front()];
            if(dif>DIFMAX)DIFMAX=dif;
        }
    }

    g<<DIFMAX;

    f.close();
    g.close();
    return 0;
}
