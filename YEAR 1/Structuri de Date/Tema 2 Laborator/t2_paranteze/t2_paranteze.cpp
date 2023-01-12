#include <iostream>
#include <fstream>
#include <cstring>
#include <deque>
using namespace std;

ifstream f("paranteze.in");
ofstream g("paranteze.out");

int main(){
    int N,MAX=0,i;
    char PARANTEZA;

    std::deque< std::pair<int,char> >DEQUE;
    std::pair<int,char>PAIR;

    f>>N;
    for(i=0;i<N;i++){
        f>>PARANTEZA;

        if(strchr(")]}",PARANTEZA) && !DEQUE.empty()){
            if(PARANTEZA==')' && DEQUE.back().second=='(')
                DEQUE.pop_back();
            else if(PARANTEZA==']' && DEQUE.back().second=='[')
                DEQUE.pop_back();
            else if(PARANTEZA=='}' && DEQUE.back().second=='{')
                DEQUE.pop_back();
            else{
                PAIR.first=i;
                PAIR.second=PARANTEZA;
                DEQUE.push_back(PAIR);
            }
        }
        else{
           PAIR.first=i;
           PAIR.second=PARANTEZA;
           DEQUE.push_back(PAIR);
        }

        if(!DEQUE.empty()){
            if(i-DEQUE.back().first > MAX)
                MAX=i-DEQUE.back().first;
        }
    }

    g<<MAX;

    f.close();
    g.close();
    return 0;
}
