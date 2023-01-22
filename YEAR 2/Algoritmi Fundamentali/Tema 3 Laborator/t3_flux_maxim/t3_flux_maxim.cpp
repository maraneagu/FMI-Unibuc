#include <fstream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

// ALGORITM EDMONDS-KARP

ifstream fin("maxflow.in");
ofstream fout("maxflow.out");

int N, M;

// MATRICE DE ADIACENTA
vector<vector<int>> m_a;
// MATRICE DE CAPACITATE
vector<vector<int>> m_c;
// VECTOR DE TATI
vector<int> v_p;

bool BFS (int s, int d)
{
    // VECTOR CARE VERIFICA DACA UN NOD A FOST SAU NU VIZITAT
    vector<bool> vizitat(N + 1);
    v_p[s] = -1;
    vizitat[s] = true;

    // COADA PENTRU PARCURGEREA GRAFULUI
    queue<int> q;
    q.push(s);

    while (!q.empty())
    {
        int n_curent = q.front();
        q.pop();

        // PARCURGEM VECINII NODULUI
        for (int n_vecin : m_a[n_curent])
        {
            // DACA NODUL VECIN NU A FOST VIZITAT & CAPACITATEA NU A FOST DEPASITA
            if (!vizitat[n_vecin] && m_c[n_curent][n_vecin])
            {
                // ACTUALIZAM TATAL NODULUI VECIN CU NODUL CURENT
                v_p[n_vecin] = n_curent;

                // DACA AM AJUNS IN NODUL DESTINATIE, NE OPRIM
                if(n_vecin == d) return true;

                // DACA NU, VIZITAM NODUL VECIN & IL PUNEM IN COADA PENTRU CONTINUAREA PARCURGERII
                vizitat[n_vecin] = true;
                q.push(n_vecin);
            }
        }
    }
    // DACA NU AM AJUNS IN NODUL DESTINATIE, FLUXUL ESTE MAXIM
    return false;
}

int MAXFLOW (int s, int d)
{
    long m_flux = 0;

    // CAT TIMP AJUNGEM DIN NODUL SURSA IN NODUL DESTINATIE A.K.A
    // CAT TIMP FLUXUL NU ESTE MAXIM
    while (BFS(s, d))
    {
        // VALOAREA MINIMA A MUCHIILOR DE PE DRUMUL GASIT
        int flux = INT_MAX;
        for (int nod = d; nod != s; nod = v_p[nod])
            flux = min(flux, m_c[v_p[nod]][nod]);

        // ACTUALIZAM VALORILE MUCHIILOR DE PE DRUMUL GASIT & A INVERSELOR LOR
        for (int nod = d; nod != s; nod = v_p[nod])
        {
            // PENTRU MUCHIA ORIGINALA, II SCADEM CAPACITATEA
            m_c[v_p[nod]][nod] -= flux;
            // PENTRU MUCHIA INVERSATA, II MARIM CAPACITATEA
            m_c[nod][v_p[nod]] += flux;
        }

        m_flux += flux;
    }
    return m_flux;
}

int main()
{
    // CITIRE
    fin>>N>>M;

    // INITIALIZARE
    int sursa = 1, destinatie = N;
    m_a.resize(N + 1);
    m_c.resize(N + 1, vector<int>(N + 1));
    v_p.resize(N + 1);

    for(int i = 0; i < M; i++)
    {
        int x, y, capacitate;
        fin>>x>>y>>capacitate;

        m_c[x][y] = capacitate;
        m_a[x].push_back(y);
        // MUCHIE PENTRU GRAFUL REZIDUAL
        m_a[y].push_back(x);
    }

    // AFISARE
    int m_flux = MAXFLOW(sursa, destinatie);
    fout<<m_flux;
    return 0;
}