#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Graph {
private:
    int N, M;
    vector<vector<int>> matrice;

public:
    // constructor parametrizat
    Graph(int _N, int _M, vector<vector<int>> _matrice) : N(_N), M(_M), matrice(std::move(_matrice)){}

    bool c_DFS(vector<int> permutare){

        // vector care determina daca un nod a fost vizitat
        // initial toate vor fi nevizitate
        vector<int> v(N+1, 0);

        // stiva care determina nodul curent al parcurgerii DFS
        stack<int> s;

        int i = 0;

        // punem primul element al permutarii in stiva
        // + il vizitam
        s.push(permutare[i++]);
        v[s.top()] = 1;

        // cat timp mai sunt noduri in stiva
        // & nu am parcurs toate nodurile din permutare
        while (!s.empty() && i < permutare.size()){

            // nodul curent
            int n = s.top();

            // nodul din permutare pe care il cautam
            int p = permutare[i];

            bool f = false;

            // ii parcurgem vecinii nodului curent
            for (int& vecin : matrice[n])

                // daca un vecin este nodul cautat si este nevizitat
                // + il vizitam, il punem pe stiva si il marcam "found"
                if (v[vecin] == 0 && vecin == p){
                    v[p] = 1;
                    s.push(p);
                    i++;
                    f = true;
                }

            // daca nodul cautat nu a fost gasit
            if (f == false){

                // ii parcurgem vecinii nodului curent
                // + daca nu ne intoarcem si putem continua parcurgerea intr-un nod nevizitat
                // => nu se poate face DFS cu permutarea data
                for (int& vecin: matrice[n])
                    if (v[vecin] == 0)
                        return false;

                // altfel, scoatem nodul curent de pe stiva, pentru a ne intoarce
                s.pop();
            }
        }

        // daca am parcurs toate nodurile din permutare, DFS complet
        return i == permutare.size();
    }
};

int main() {
    int N, M, a, b;
    vector<int> permutare;

    // citire
    ifstream f("p2.in");
    f>>N>>M;

    // matricea de adiacenta a grafului
    vector<vector<int>> matrice(N + 1);

    for(int i = 0; i < N; i++){
        f>>a;
        permutare.push_back(a);
    }

    for(int i = 1; i <= M; i++){
        f>>a>>b;
        matrice[a].push_back(b);
        matrice[b].push_back(a);
    }

    f.close();

    // creare graf
    Graph graf = *new Graph(N, M, matrice);

    // afisare rezultat
    cout<<graf.c_DFS(permutare);
    return 0;
}
