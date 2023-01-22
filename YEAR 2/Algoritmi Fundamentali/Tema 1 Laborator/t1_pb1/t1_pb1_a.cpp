#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {
        // matricea de adiacenta a grafului
        vector<vector<int>> m(n + 1);

        // culoarea pe care o poate lua un nod
        // 1 sau -1, dar initial toate vor fi 0
        vector<int> c(n + 1, 0);

        // vector care determina daca un nod a fost vizitat
        // initial toate vor fi nevizitate
        vector<bool> v(n + 1, false);

        // parcurgem perechile citite, care vor deveni muchiile grafului
        // + le marcam in matricea de adiacenta
        for (auto &d: dislikes) {
            m[d[0]].push_back(d[1]);
            m[d[1]].push_back(d[0]);
        }

        // VERIFICARE GRAF BIPARTIT

        queue<int> q;
        // parcurgem nodurile grafului
        for (int i = 1; i <= n; ++i){

            // daca un nod nu a fost vizitat, ii atribuim o culoare
            // + il punem in coada, pentru a-i parcurge componenta conexa
            if (!v[i]){
                c[i] = 1;
                q.push(i);

                // cat timp mai sunt noduri in coada
                while (!q.empty()){

                    // luam capul cozii
                    int a = q.front();
                    q.pop();

                    // daca a fost vizitat, trecem la urmatorul nod din coada
                    if (v[a]) continue;
                    // daca nu a fost vizitat, il marcam vizitat
                    v[a] = true;

                    // ii parcurgem vecinii
                    // + le atribuim culoarea opusa
                    for (auto b: m[a]){

                        // daca un vecin are atribuita aceeasi culoare
                        // => GRAFUL NU ESTE BIPARTIT
                        if (c[b] == c[a])
                            return false;

                        // le atribuim vecinilor culoare opusa
                        // + ii punem in coada
                        c[b] = -c[a];
                        q.push(b);
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
    int n,a,b;
    vector<vector<int>> d;

    // citire
    ifstream f("p1.in");
    f>>n;
    while(f>>a>>b){
        vector<int> p;
        p.push_back(a);
        p.push_back(b);

        d.push_back(p);
    }
    f.close();

    // afisare rezultat
    Solution s;
    cout<<s.possibleBipartition(n,d);
    return 0;
}
