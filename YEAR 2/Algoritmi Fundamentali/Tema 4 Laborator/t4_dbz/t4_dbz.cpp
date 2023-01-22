#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

ifstream fin("dbz.in");
ofstream fout("dbz.out");

int N, M, x, y, z;

// LISTA DE ADIACENTA
vector<pair<int,int>> l_a[2000];
// VECTOR DE TATI
vector<int> v_p;
// VECTOR CE DETERMINA DURATA DE DEPLASARE SPRE UN NOD 
vector<int> d_d;

int DIJKSTRA(int n_sursa)
{
    v_p.clear();
    v_p.resize(N + 1, 0);
    d_d.clear();
    d_d.resize(N + 1, INT_MAX);

    // COADA DE PRIORITATI PENTRU PARCURGEREA GRAFULUI
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    
    q.push({0, n_sursa});
    d_d[n_sursa] = 0;

    while (!q.empty())
    {
        int d_curent = q.top().first;
        int n_curent = q.top().second;
        q.pop();

        // PARCURGEM NODURILE VECINE ALE NODULUI CURENT
        for (auto vecin : l_a[n_curent])
        {
            int n_vecin = vecin.first;
            int d_vecin = vecin.second + d_curent;

            if (d_vecin < d_d[n_vecin])
            {
                // ACTUALIZAM DURATA DE DEPLASARE SPRE NODUL VECIN
                d_d[n_vecin] = d_vecin;

                // ACTUALIZAM TATAL NODULUI VECIN
                // DACA NODUL CURENT ESTE NODUL SURSA, TATAL NODULUI VECIN ESTE EL INSUSI
                if (n_curent == n_sursa)
                    v_p[n_vecin] = n_vecin;
                
                // ALTFEL, TATAL NODULUI VECIN ESTE TATAL NODULUI CURENT
                else v_p[n_vecin] = v_p[n_curent]; 

                // ADAUGAM NODUL IN COADA PENTRU A CONTINUA PARCURGEREA
                q.push({d_vecin, n_vecin});
            }
        }
    }

    // DETERMINAM DISTANTA MINIMA CATRE NODUL SURSA
    int d_minima = INT_MAX;

    for (int i = 1; i <= N; i++)
        if (i != n_sursa)
            for (auto vecin : l_a[i])
            {
                int n_vecin = vecin.first;
                int d_vecin = vecin.second;

                // DACA UN NOD VECIN AL LUI i IL ARE CA TATA PE NODUL i, AVEM CICLU
                if (v_p[n_vecin] == v_p[i] || (n_vecin == n_sursa && v_p[i] == i))
                    continue;

                // ALTFEL, CALCULAM DURATA DE DEPLASARE A DRUMULUI
                d_minima = min(d_minima, d_d[i] + d_d[n_vecin] + d_vecin);
            }
    
    if (d_minima == INT_MAX)
        return -1;
    
    return d_minima;
}

int main()
{
    fin>>N>>M;

    v_p.resize(N + 1);
    d_d.resize(N + 1);

    // CITIRE
    for (int i = 1; i <= M; i++)
    {
        fin>>x>>y>>z;

        l_a[x].push_back({y, z});
        l_a[y].push_back({x, z});
    }

    // AFISARE
    for (int i = 1; i <= N; i++)
        fout<<DIJKSTRA(i)<<' ';
    return 0;
}