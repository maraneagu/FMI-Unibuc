#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int N, SURSA, DESTINATIE, N_NODURI;

// MATRICEA ORIGINALA
int M[2005][2005];
// MATRICEA PENTRU FLUX
int M_FLUX[2005][2005];
// VECTOR CE DETERMINA DACA UN NOD A FOST SAU NU VIZITAT
vector<bool> vizitat;
// VECTOR DE TATI
vector<int> v_p;

bool BFS()
{
    v_p.clear();
    v_p.resize(N_NODURI + 1, -1);
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

        for (int i = 1; i <= DESTINATIE; i++)

            // DACA NODUL NU A FOST VIZITAT & EXISTA O LEGATURA INTRE NODURI
            if (!vizitat[i] && M_FLUX[n_curent][i] == 1)
            {
                // ACTUALIZAM TATAL NODUL i CU NODUL CURENT
                v_p[i] = n_curent;
                
                // DACA AM AJUNS LA NODUL DESTINATIE, NE OPRIM
                if (i == DESTINATIE)
                    return true;

                // DACA NU, VIZITAM NODUL i & IL PUNEM IN COADA PENTRU CONTINUAREA PARCURGERII
                vizitat[i] = true;
                q.push(i);
            }
    }
    // DACA NU AM AJUNS IN NODUL DESTINATIE, FLUXUL ESTE MAXIM
    return false;
}

int MAXFLOW()
{
    long m_flux = 0;

    // CAT TIMP AJUNGEM DIN NODUL SURSA IN NODUL DESTINATIE A.K.A
    // CAT TIMP FLUXUL NU ESTE MAXIM
    while (BFS())
    {
        // PENTRU NODURILE CE DESEMNEAZA LINII
        for (int i = N + 1; i < DESTINATIE; i++)
            
            // DACA EXISTA UN DRUM INTRE NODUL DESTINATIE & UN ASTFEL DE NOD, IL PARCURGEM INVERS
            if (vizitat[i])
            {
                int flux = INT_MAX;

                // ACTUALIZAM TATAL NODULUI DESTINATIE CU NODUL CURENT PENTRU PARCURGEREA DRUMULUI
                v_p[DESTINATIE] = i;

                // PARCURGEM DRUMUL INVERS, ACTUALIZAND VALOAREA FLUXULUI
                for (int j = DESTINATIE; j > 0; j = v_p[j])
                    flux = min(flux, M_FLUX[v_p[j]][j]);

                // PARCURGEM DRUMUL INVERS, ACTUALIZAND VALOAREA DIN MATRICEA PENTRU FLUX
                for (int j = DESTINATIE; j > 0; j = v_p[j])
                {
                    M_FLUX[v_p[j]][j] -= flux;
                    M_FLUX[j][v_p[j]] += flux;
                }

                m_flux += flux;
            }
    }
    return m_flux;
}

int main()
{
    cin>>N;

    N_NODURI = 2 * N + 2;
    // SE ADAUGA UN NOD SURSA & UN NOD DESTINATIE
    SURSA = 0, DESTINATIE = N_NODURI - 1;

    // CITIRE
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            cin>>M[i][j];

            if (M[i][j] == 1)
                // j ESTE MARIT CU N PENTRU A EVITA SUPRAPUNEREA
                M_FLUX[i][j + N] = 1;
        }

    // FLUX DE LA NODUL SURSA LA NODURILE CE DESEMNEAZA LINII
    for (int i = 1; i <= N; i++)
        M_FLUX[SURSA][i] = 1;

    // FLUX DE LA NODURILE CE DESEMNEAZA LINII LA NODUL DESTINATIE
    for (int j = 1; j <= N; j++)
        M_FLUX[j + N][DESTINATIE] = 1;

    // AFISARE
    if (MAXFLOW() != N)
        cout<<"-1"<<endl;
    else 
    {
        int CUPLAJ[2005], LINIE[2005];

        // INITIAL, TOATE LINIILE SUNT IN ORDINEA ORIGINALA
        for (int i = 1; i <= N; i++)
            LINIE[i] = i;

        // DETERMINAM CUPLAJELE
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                if (M[i][j] == 1 && M_FLUX[i][j + N] == 0)
                    CUPLAJ[i] = j;
        
        for (int i = 1; i <= N; i++)
            
            // DACA AVEM CUPLAJ INTRE DOUA LINII, FACEM SWAP INTRE ACESTEA
            if (CUPLAJ[i] != LINIE[i])
            {
                // CAUTAM LINIA CU CARE AVEM CUPLAJ
                int j;
                for(j = 1; CUPLAJ[i] != LINIE[j]; j++);

                // AFISAM LINIILE INITIALE
                cout<<"R "<<LINIE[i]<<' '<<LINIE[j]<<endl;

                // FACEM SWAP INTRE LINIILE CUPLATE
                int swap = LINIE[j];
                LINIE[j] = LINIE[i];
                LINIE[i] = swap;
            }
    }
    return 0;
}