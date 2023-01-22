#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

ifstream fin("cuplaj.in");
ofstream fout("cuplaj.out");

int N, M, E, N_NODURI, SURSA, DESTINATIE;

// STRUCTURA PENTRU REPREZENTAREA MUCHIILOR GRAFULUI
struct muchie
{
    int n_s, n_d, capacitate, pozitie;
};
vector<muchie> s_m;

// MATRICE DE INDICI, CE RETINE PENTRU FIECARE NOD, INDICII MUCHIILOR INCIDENTE NODULUI
vector<vector<int>> m_i;
// VECTOR CARE VERIFICA DACA UN NOD A FOST SAU NU VIZITAT
vector<bool> vizitat;
// VECTOR DE TATI
vector<int> v_p;

void A_MUCHIE(int x, int y)
{
    int p = (int)s_m.size();
    muchie m;

    // ADAUGAM INDICII MUCHIEI IN MATRICEA DE INDICI
    m_i[y].push_back(p + 1);
    // CREEM MUCHIA
    m = {x, y, 1, p + 1};
    s_m.push_back(m);

    // REPETAM PROCESUL PENTRU INVERSA
    m_i[x].push_back(p);
    m = {y, x, 0, p};
    s_m.push_back(m);
}

bool BFS()
{
    v_p.clear();
    v_p.resize(N_NODURI + 1);
    vizitat.clear();
    vizitat.resize(N_NODURI + 1, false);

    vizitat[SURSA] = true;

    // COADA PENTRU PARCURGEREA GRAFULUI
    queue<int> q;
    q.push(SURSA);

    while (!q.empty())
    {
        int n_curent = q.front();
        q.pop();

        if (n_curent != DESTINATIE)
        {
            // PARCURGEM INDICII MUCHIILOR INCIDENTE NODULUI
            for (int i_muchie : m_i[n_curent])
            {
                muchie m = s_m[i_muchie];

                // DACA NODUL VECIN NU A FOST VIZITAT & CAPACITATEA NU A FOST DEPASITA
                if (!vizitat[m.n_d] && m.capacitate != 0)
                {
                    // ACTUALIZAM TATAL NODULUI VECIN
                    v_p[m.n_d] = i_muchie;
                    
                    // VIZITAM NODUL VECIN & IL PUNEM IN COADA PENTRU CONTINUAREA PARCURGERII
                    vizitat[m.n_d] = true;
                    q.push(m.n_d);
                }
            }
        }
    }
    // DACA NU AM AJUNS IN NODUL DESTINATIE, FLUXUL ESTE MAXIM
    return vizitat[DESTINATIE];
}

int FORDFULKERSON()
{
    int m_flux = 0;

    // CAT TIMP AJUNGEM DIN NODUL SURSA IN NODUL DESTINATIE A.K.A
    // CAT TIMP FLUXUL NU ESTE MAXIM
    while (BFS())
    {
        // PARCURGEM INDICII MUCHIILOR INCIDENTE NODULUI DESTINATIE A.K.A
        // PARCURGEM DRUMUL GASIT
        for (int i_muchie : m_i[DESTINATIE])
        {
            muchie m = s_m[i_muchie];

            if (vizitat[m.n_d] && s_m[m.pozitie].capacitate != 0)
            {
                v_p[DESTINATIE] = m.pozitie;
                
                // VALOAREA MINIMA A MUCHIILOR DE PE DRUMUL GASIT
                int flux = INT_MAX;
                for (int nod = DESTINATIE; nod != SURSA; nod = s_m[v_p[nod]].n_s)
                    flux = min(flux, s_m[v_p[nod]].capacitate);

                // ACTUALIZAM VALORILE MUCHIILOR DE PE DRUMUL GASIT & A INVERSELOR LOR
                for (int nod = DESTINATIE; nod != SURSA; nod = s_m[v_p[nod]].n_s)
                {
                    s_m[v_p[nod]].capacitate -= flux;
                    s_m[s_m[v_p[nod]].pozitie].capacitate += flux;
                }

                m_flux += flux;
            }
        }
    }
    return m_flux;
}

int main()
{
    // CITIRE
    fin>>N>>M>>E;

    // ACTUALIZAM NUMARUL DE NODURI
    N_NODURI = N + M + 2;
    // SE ADAUGA UN NOD SURSA SI UN NOD DESTINATIE
    SURSA = 0, DESTINATIE = N_NODURI - 1;

    m_i.resize(N_NODURI + 1);

    for (int i = 0; i < E; i++)
    {
        int x,y;
        fin>>x>>y;

        // INDEXURILE NODURILOR DIN MULTIMEA B SUNT MARITE CU N, PENTRU A EVITA SUPRAPUNEREA
        y += N;

        A_MUCHIE(x, y);
    }

    // MUCHII SURSA - MULTIMEA A
    for (int i = 1; i <= N; i++)
        A_MUCHIE(SURSA, i);

    // MUCHII MULTIMEA B - DESTINATIE
    for (int i = 1; i <= M; i++)
        A_MUCHIE(i + N, DESTINATIE);

    // AFISARE
    fout<<FORDFULKERSON()<<'\n';
    for (muchie m : s_m)
        if (m.n_s < m.n_d && m.n_s != SURSA && m.n_d != DESTINATIE && m.capacitate == 0)
            fout<<m.n_s<<' '<<m.n_d - N<<'\n';
    return 0;
}