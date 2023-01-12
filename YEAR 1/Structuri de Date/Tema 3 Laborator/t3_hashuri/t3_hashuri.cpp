#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream f("hashuri.in");
ofstream g("hashuri.out");

vector<int>HASH[666000];

int main(){
    int k=666000;
    int N,OPERATIE,ELEMENT,CLASA;
    int i,j;

    f>>N;
    for(i=0;i<N;i++){
        f>>OPERATIE>>ELEMENT;
        CLASA=ELEMENT%k;

        bool FOUND=false;
        for(j=0;j<HASH[CLASA].size();j++)
            if(HASH[CLASA][j]==ELEMENT){
                FOUND=true;
                break;
            }

        if(OPERATIE==1)
        {
            if(!FOUND)
                HASH[CLASA].push_back(ELEMENT);
        }
        else if(OPERATIE==2)
        {
            if(FOUND){
                swap(HASH[CLASA][j],HASH[CLASA].back());
                HASH[CLASA].pop_back();
            }
        }
        else if(FOUND)g<<1<<'\n';
            else g<<0<<'\n';

    }
    f.close();
    g.close();
    return 0;
}
