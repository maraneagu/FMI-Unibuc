#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;

// matricea de adiacenta a grafului
vector<vector<int>> m;

// matricea transpusa a grafului
vector<vector<int>> m_t;

// vector care determina nivelul unui nod
vector<int> n;

int nr_cc;
// vector unde este stocat rezultatul
vector<vector<int>> cc;

// stiva pentru evidenta nodurilor parcurse la DFS
vector<int> s;

void DFS(int x){
    for(auto e: m[x])
        if(n[e] == 0){
            n[e] = 1;
            DFS(e);
        }

    s.push_back(x);
}

void DFS_T(int x){
    cc[nr_cc].push_back(x);

    n[x] = 2;

    for(auto e: m_t[x])
        if(n[e] == 1)
            DFS_T(e);
}

int main(){

    int N,M,a,b;

    // citire
    ifstream f("ctc.in");

    f>>N>>M;

    m.resize(N + 1);
    m_t.resize(N + 1);
    n.resize(N + 1, 0);
    cc.resize(N + 1);

    for(int i = 0; i < M; i++){
        f>>a>>b;

        m[a].push_back(b);
        m_t[b].push_back(a);
    }

    f.close();

    for(int i = 1; i <= N; i++){
        if(n[i] == 0){
            n[i] = 1;
            DFS(i);
        }
    }

    while(!s.empty()){
        a = s.back();
        s.pop_back();

        if(n[a] == 1){
            nr_cc++;
            DFS_T(a);
        }
    }

    ofstream g("ctc.out");

    g<<nr_cc<<endl;

    for(int i = 1; i <= nr_cc; i++){
        for(int j = 0; j < cc[i].size(); j++)
            g<<cc[i][j]<<' ';
        g<<endl;
    }

    g.close();
    return 0;
}
