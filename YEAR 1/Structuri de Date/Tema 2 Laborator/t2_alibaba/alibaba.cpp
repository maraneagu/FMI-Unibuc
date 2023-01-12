#include <iostream>
#include <fstream>
#include <deque>
using namespace std;

ifstream f("alibaba.in");
ofstream g("alibaba.out");

int main(){
    int N,K,CIFRA,i;
    char C_CIFRA;

    std::deque<int> DEQUE_MAX;

    f>>N>>K;
    for(i=0;i<N;i++){
        f>>C_CIFRA;
        CIFRA=C_CIFRA-'0';

        while(!DEQUE_MAX.empty()&&CIFRA>DEQUE_MAX.back()&&K>0){
            DEQUE_MAX.pop_back();
            K--;
        }
        DEQUE_MAX.push_back(CIFRA);
    }
    while(K){
        DEQUE_MAX.pop_back();
        K--;
    }
    while(!DEQUE_MAX.empty()){
        g<<DEQUE_MAX.front();
        DEQUE_MAX.pop_front();
    }

    f.close();
    g.close();
    return 0;
}
