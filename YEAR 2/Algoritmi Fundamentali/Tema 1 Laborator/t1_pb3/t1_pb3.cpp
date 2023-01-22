#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& prerequisites) {

        // matricea de adiacenta a grafului
        vector<vector<int>> m(N + 1);

        // vector care retine gradul intern al unui nod/ numarul de cursuri ce mai trebuie parcurse
        vector<int> g_i(N + 1, 0);

        // parcurgem perechile citite, ce vor deveni muchiile grafului
        for(auto &p: prerequisites){

            // le marcam in matricea de adiacenta
            m[p[1]].push_back(p[0]);

            // le actualizam gradul intern
            g_i[p[0]]++;
        }

        // SORTARE TOPOLOGICA

        queue<int> q;
        vector<int> s_t;

        // adaugam in coada nodurile cu grad intern 0
        for(int i = 0; i < N; i++)
            if(g_i[i] == 0)
                q.push(i);

        while(!q.empty()){

            // nodul curent
            int n = q.front();

            // avand gradul intern 0 => cursul poate fi parcurs
            s_t.push_back(n);
            q.pop();

            // parcurgem nodurile externe ale celui curent
            for(auto e: m[n]){

                // daca taiand legatura cu nodul curent, gradul acestora devine 0
                // => le adaugam la coada
                if(--g_i[e] == 0)
                    q.push(e);
            }
        }

        if(s_t.size() == N)return s_t;
        return {};
    }
};

int main()
{
    int N,a,b;
    vector<vector<int>> P;

    // citire
    ifstream f("p3.in");

    f>>N;
    while(f>>a>>b){
        vector<int> p;
        p.push_back(a);
        p.push_back(b);

        P.push_back(p);
    }

    f.close();

    // afisare rezultat
    Solution s;
    vector<int> rez = s.findOrder(N,P);

    for(int i = 0; i < N; i++)
        cout<<rez[i]<<' ';
    return 0;
}
