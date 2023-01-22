#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

ifstream f("easygraph.in");
ofstream g("easygraph.out");

// VECTOR CE RETINE VALOAREA FIECARUI NOD
vector<int> valoare;

// LISTA DE ADIACENTA A GRAFULUI
vector<vector<int>> lista;

// VECTOR CE DETERMINA DACA UN NOD A FOST SAU NU VIZITAT
vector<int> vizitat;

// COSTUL UNUI NOD IN PARCURGEREA DFS
vector<long long int> cost;

// SUMA MAXIMA A UNUI LANT DIN GRAF
long long int suma_maxima;
#define MIN -10000000000

void DFS(int nod)
{
    vizitat[nod] = 1;
    cost[nod] = valoare[nod];

    // PARCURGEM VECINII FIECARUI NOD SI ACTUALIZAM SUMA MAXIMA
    for(int vecin: lista[nod])
    {
        if(vizitat[vecin] == 0)
            DFS(vecin);

        if(cost[nod] < cost[vecin] + valoare[nod])
            cost[nod] = cost[vecin] + valoare[nod];
    }

    if(suma_maxima < cost[nod])
        suma_maxima = cost[nod];
}

int main()
{
    int T;
    f>>T;

    // CITIRE
    for(int i = 0; i < T; i++)
    {
        int N,M;
        f>>N>>M;

        // REDECLARAREA DIMENSIUNII VECTORILOR
        valoare.resize(N+1);
        lista.resize(N+1);
        vizitat.resize(N+1);
        cost.resize(N+1);

        // GOLIREA VECTORILOR
        valoare.clear();
        lista.clear();
        vizitat.clear();
        cost.clear();

        for(int j = 1; j <= N; j++)
            f>>valoare[j];

        for(int j = 0; j < M; j++)
        {
            int x,y;
            f>>x>>y;
            lista[x].push_back(y);
        }

        suma_maxima = MIN;
        // PENTRU FIECARE NOD CE NU A FOST VIZITAT, FACEM PARCURGEREA DFS
        for(int j = 1; j <= N; j++)
            if(vizitat[j] == 0)
                DFS(j);

        // AFISARE
        g<<suma_maxima<<endl;

    }
    return 0;
}
