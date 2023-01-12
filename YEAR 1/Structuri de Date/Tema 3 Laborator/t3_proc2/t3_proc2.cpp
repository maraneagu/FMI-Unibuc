#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

ifstream f("proc2.in");
ofstream g("proc2.out");

int main(){
    int N,M,i,START,TIME;

    priority_queue<int> P_LIBERE;
    priority_queue< pair<int,int> > P_OCUPATE;

    f>>N>>M;

    for(i=1;i<=N;i++)
        P_LIBERE.push(-i);

    for(i=0;i<M;i++){
        f>>START>>TIME;

        while(!P_OCUPATE.empty() && -P_OCUPATE.top().first<=START)
        {
            P_LIBERE.push(P_OCUPATE.top().second);
            P_OCUPATE.pop();
        }

        P_OCUPATE.push(make_pair(-(START+TIME),P_LIBERE.top()));

        g<<-P_LIBERE.top()<<'\n';
        P_LIBERE.pop();
    }
    return 0;
}
