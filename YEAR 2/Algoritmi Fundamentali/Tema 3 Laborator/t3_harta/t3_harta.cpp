#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

ifstream fin("harta.in");
ofstream fout("harta.out");

int N, SURSA, DESTINATIE;

// MATRICE DE ADIACENTA
int m_a[301][301];
// VECTOR CARE DETERMINA DACA UN NOD A FOST SAU NU VIZITAT
vector<bool> vizitat;
// VECTOR DE TATI
vector<int> v_p;

int BFS()
{
    v_p.clear();
    v_p.resize(DESTINATIE + 1, 0);
    vizitat.clear();
    vizitat.resize(DESTINATIE + 1, false);

    v_p[SURSA] = -1;
    vizitat[SURSA] = true;

    // COADA PENTRU PARCURGEREA GRAFULUI
    queue<int> q;
    q.push(SURSA);

    while (!q.empty())
    {
        int n_curent = q.front();
        q.pop();

        // DACA AM AJUNS IN NODUL DESTINATIE, NE OPRIM
        if (n_curent == DESTINATIE) return 1;

        for (int i = 1; i <= DESTINATIE; i++)
            
            // DACA NODUL NU A FOST VIZITAT & EXISTA O LEGATURA INTRE NODURI
            if (!vizitat[i] && m_a[n_curent][i] > 0)
            {
                // ACTUALIZAM TATAL NODULUI VECIN
                v_p[i] = n_curent;

                // VIZITAM NODUL VECIN & IL PUNEM IN COADA PENTRU CONTINUAREA PARCURGERII
                vizitat[i] = true;
                q.push(i);
            }
    }
    // DACA NU AM AJUNS IN NODUL DESTINATIE, FLUXUL ESTE MAXIM
    return 0;
}

int FORDFULKERSON()
{
    long m_flux = 0;
    
    // CAT TIMP AJUNGEM DIN NODUL SURSA IN NODUL DESTINATIE A.K.A
    // CAT TIMP FLUXUL NU ESTE MAXIM
    while (BFS())
    {
        // PENTRU FIECARE NOD, PARCURGEM DRUMUL GASIT
        for (int i = 1; i <= N; i++)
        {
            if (vizitat[i + N] && m_a[i + N][DESTINATIE] > 0)
            {
                v_p[DESTINATIE] = i + N;
                
                // VALOAREA MINIMA A GRADELOR NODURILOR DE PE DRUMUL GASIT
                int flux = INT_MAX;
                for (int nod = DESTINATIE; nod != SURSA; nod = v_p[nod])
                    flux = min(flux, m_a[v_p[nod]][nod]);
                
                // ACTUALIZAM VALORILE GRADELOR NODURILOR DE PE DRUMUL GASIT
                for (int nod = DESTINATIE; nod != SURSA; nod = v_p[nod])
                {
                    m_a[v_p[nod]][nod] -= flux;
                    m_a[nod][v_p[nod]] += flux;
                }

                m_flux += flux;
            }
        }
    }
    return m_flux;
}

int main()
{
    fin>>N;

    // SE ADAUGA UN NOD SURSA & UN NOD DESTINATIE, MUCHIILE LOR AVAND COSTUL EGAL CU GRADUL DE INTRARE, RESPECTIV IESIRE
    SURSA = 0, DESTINATIE = 2 * N + 1;
    // NUMARUL DE NODURI SE DUBLEAZA & SE PUN IN DOUA MULTIMI DISTINCTE

    // CITIRE
    for (int i = 1; i <= N; i++)
    {
        int x,y;
        fin>>y>>x;

        m_a[SURSA][i] = y;
        m_a[i + N][DESTINATIE] = x;

        // CELE DOUA MULTIMI SE LEAGA INTRE ELE PRIN MUCHII DE COST 1, CU CONDITIA CA NODURILE SA FIE DISTINCTE INTRE ELE
        for (int j = 1; j <= N; j++)
            if (i != j)
                m_a[i][j + N] = 1;
    }

    // AFISARE
    fout<<FORDFULKERSON()<<'\n';
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (m_a[i][j + N] == 0 && i != j)
                fout<<i<<' '<<j<<'\n';
    return 0;
}