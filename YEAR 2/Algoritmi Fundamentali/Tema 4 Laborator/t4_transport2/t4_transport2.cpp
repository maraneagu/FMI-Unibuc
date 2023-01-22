#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

ifstream fin("transport2.in");
ofstream fout("transport2.out");

int N, M;

// STRUCTURA PENTRU REPREZENTAREA MUCHIILOR GRAFULUI
struct muchie
{
    int nod, capacitate;
};

// MATRICE DE ADIACENTA
vector<vector<muchie>> m_a;
// VECTOR CARE VERIFICA DACA UN NOD A FOST SAU NU VIZITAT
vector<bool> vizitat;

bool BFS(int c_maxima)
{
    vizitat.clear();
    vizitat.resize(N + 1, false);

    // COADA PENTRU PARCURGEREA GRAFULUI
    queue<int> q;
    
    // PORNIM PARCURGEREA DE LA NODUL 1
    q.push(1);
    vizitat[1] = true;

    while (!q.empty())
    {
        int n_curent = q.front();
        q.pop();

        // DACA AM AJUNS LA NODUL DESTINATIE, NE OPRIM
        if (n_curent == N) return true;

        // PARCURGEM VECINII NODULUI CURENT
        for (auto n_vecin : m_a[n_curent])
            
            // DACA NODUL VECIN NU A FOST VIZITAT & CAPACITATEA MAXIMA NU DEPASESTE CAPACITATEA NODULUI VECIN
            if (vizitat[n_vecin.nod] == false && n_vecin.capacitate >= c_maxima)
            {
                // IL ADAUGAM IN COADA, PENTRU A CONTINUA PARCURGEREA & IL VIZITAM
                q.push(n_vecin.nod);
                vizitat[n_vecin.nod] = true;
            }
    }
    return false;
}

int main()
{
    fin>>N>>M;

    m_a.resize(N + 1);
    vizitat.resize(N + 1);

    // CITIRE
    for (int i = 0; i < M; i++)
    {
        int x, y, c;
        muchie m;

        fin>>x>>y>>c;

        m.nod = y;
        m.capacitate = c;
        m_a[x].push_back(m);

        m.nod = x;
        m_a[y].push_back(m);
    }

    // CAUTARE BINARA PENTRU DETERMINAREA CAPACITATII MAXIME
    int stanga = 1, dreapta = 100001, mijloc;
    int g_maxima;

    while (stanga <= dreapta)
    {
        mijloc = (stanga + dreapta) / 2;

        // DACA AM AJUNS LA DESTINATIE, ACTUALIZEZ GREUTATEA MAXIMA
        if (BFS(mijloc) == true)
        {
            g_maxima = mijloc;
            stanga = mijloc + 1;
        }
        else
        {
            dreapta = mijloc - 1;
        }
    }

    // AFISARE
    fout<<g_maxima;
    return 0;
}