#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

ifstream fin("riremito.in");
ofstream fout("riremito.out");

int N, x, y, z, K;
int n_start;

// LISTA DE ADIACENTA
vector<pair<int,int>> l_a[100001];
// VCETOR CE DETERMINA DACA UN NOD A FOST SAU NU VIZITAT
vector<bool> vizitat;
// VECTOR CE RETINE TIMPUL MINIM DE VIZITARE AL UNUI NOD LA TOATE CELELALTE NODURI
vector<long long> T_VIZITARE;
// VECTOR CE RETINE TIMPUL MINIM DE VIZITARE AL UNUI NOD LA NODUL DE START
vector<long long> T_VIZITARE_SUBGRAF;

void DFS(long long n_curent, long long t_curent)
{
    vizitat[n_curent] = true;
    
    // PARCURGEM VECINII NODULUI CURENT
    for (auto vecin : l_a[n_curent])
    {
        int n_vecin = vecin.first;
        int t_vecin = vecin.second;

        // DACA NODUL VECIN NU A FOST VIZITAT
        if (!vizitat[n_vecin])
        {
            // CONTINUAM PARCURGEREA GRAFULUI
            DFS(n_vecin, t_curent + t_vecin);

            // SE ALEGE INTRE TIMPUL DE TELEPORTARE DIN NODUL VECIN INAPOI LA NODUL DE START SAU CONTINUAREA PARCURGERII
            long long timp = min(T_VIZITARE_SUBGRAF[n_vecin] + 2 * t_vecin, T_VIZITARE[n_vecin] + t_vecin + t_curent);
            
            // SE ACTUALIZEAZA TIMPUL MINIM PANA LA NODUL DE START
            T_VIZITARE_SUBGRAF[n_curent] += timp;

            // SE ACTUALIZEAZA TIMPUL MINIM PANA LA NODUL VECIN
            T_VIZITARE[n_curent] = min(T_VIZITARE[n_curent], T_VIZITARE[n_vecin] + t_vecin - timp);
        }
    }
    T_VIZITARE[n_curent] += T_VIZITARE_SUBGRAF[n_curent];
}

int main()
{
    fin>>N;

    // CITIRE
    for (int i = 1; i < N; i++)
    {
        fin>>x>>y>>z;
        l_a[x].push_back({y, z});
        l_a[y].push_back({x, z});
    }

    fin>>K;

    // AFISARE
    for (int i = 1; i <= K; i++)
    {
        fin>>n_start;

        vizitat.clear();
        vizitat.resize(N + 1, false);
        T_VIZITARE.clear();
        T_VIZITARE.resize(N + 1, 0);
        T_VIZITARE_SUBGRAF.clear();
        T_VIZITARE_SUBGRAF.resize(N + 1, 0);

        DFS(n_start, 0);

        fout<<T_VIZITARE[n_start]<<endl;
    }
    return 0;
}