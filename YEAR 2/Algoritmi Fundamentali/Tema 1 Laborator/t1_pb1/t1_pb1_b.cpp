#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

int n;
// culoarea pe care o poate lua un nod
// 1 sau -1, dar initial toate vor fi 0
vector<int> c(n + 1, 0);

class Solution {
public:
    bool pBipartition(int n, vector<vector<int>> &dislikes)
    {
        // matricea de adiacenta a grafului
        vector<vector<int>> m(n + 1);

        // vector care determina daca un nod a fost vizitat
        // initial toate vor fi nevizitate
        vector<bool> v(n + 1, false);

        // parcurgem perechile citite, vor deveni muchiile grafului
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

    vector<vector<int>> possibleBipartition(int n, vector<vector<int>>& dislikes)
    {
        if(pBipartition(n,dislikes)){
            vector<vector<int>> r;
            int i;

            vector<int> g1;
            vector<int> g2;

            for(i = 1; i <= n; i++)
                if(c[i]==1)g1.push_back(i);
                else g2.push_back(i);

            r.push_back(g1);
            r.push_back(g2);

            return r;
        }
    }
};

int main()
{
    int a,b;
    vector<vector<int>> d;

    // citim n si perechile de noduri
    ifstream f("p1.in");
    f>>n;
    while(f>>a>>b){
        vector<int> p;
        p.push_back(a);
        p.push_back(b);

        d.push_back(p);
    }
    f.close();

    // afisam rezultatul
    Solution s;

    vector<vector<int>> rez;
    rez=s.possibleBipartition(n,d);

    for(int i = 0; i <= 1; i++){
        cout<<"Grupa "<<i+1<<": ";
        for(int j = 0; j < rez[i].size(); j++)
            cout<<rez[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
