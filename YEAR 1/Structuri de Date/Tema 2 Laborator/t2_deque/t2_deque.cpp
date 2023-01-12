#include <iostream>
#include <fstream>
#include <deque>
using namespace std;

ifstream f("deque.in");
ofstream g("deque.out");

int main(){
    int N,K,SUM=0;
    f>>N>>K;
    int E[N];

    std::deque<int> DEQUE_MIN;

    int i;
    for(i=0;i<N;i++){
        f>>E[i];

        while(!DEQUE_MIN.empty() && E[i]<=E[DEQUE_MIN.back()])
            DEQUE_MIN.pop_back();
        DEQUE_MIN.push_back(i);

        if(DEQUE_MIN.front()==i-K)
            DEQUE_MIN.pop_front();

        if(i>=K-1)
            SUM+=E[DEQUE_MIN.front()];
    }

    g<<SUM;

    f.close();
    g.close();
    return 0;
}
