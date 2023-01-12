#include <iostream>
#include <fstream>
#include <set>
using namespace std;

ifstream f("heapuri.in");
ofstream g("heapuri.out");

int main(){
    int N,OPERATION,POSITION;
    multiset<int>HEAP;

    int AUX[200001],LENGTH_AUX=0;
    int i;

    f>>N;

    for(i=0;i<N;i++){
        f>>OPERATION;

        if(OPERATION==1){
            f>>AUX[++LENGTH_AUX];
            HEAP.insert(AUX[LENGTH_AUX]);
        }
        else if(OPERATION==2){
            f>>POSITION;
            HEAP.erase(HEAP.find(AUX[POSITION]));
        }
        else g<<*HEAP.begin()<<'\n';
    }

    f.close();
    g.close();
    return 0;
}
