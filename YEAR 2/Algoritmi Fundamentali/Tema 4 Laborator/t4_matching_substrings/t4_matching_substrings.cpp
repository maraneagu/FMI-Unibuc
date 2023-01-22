#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

int N, K;
string PREFIX, SUFIX, SUBSIR, REZULTAT;
string SURSA;

// LISTA DE ADIACENTA
unordered_map<string, vector<string>> l_a;
// VECTOR CE RETINE GRADELE INTERNE ALE UNUI SUBSIR
unordered_map<string, int> g_intern;
// VECTOR CE RETINE GRADELE EXTERNE ALE UNUI SUBSIR
unordered_map<string, int> g_extern;

void DFS(string s)
{
   // PARCURGEM LISTA DE ADIACENTA A SUBSIRULUI DE LA COADA LA CAP
   while (!l_a[s].empty())
   {
        // LUAM ULTIMUL SUBSIR VECIN
        string s_vecin = l_a[s].back();
        l_a[s].pop_back();

        // CONTINUAM PARCURGEREA SUBSIRURILOR
        DFS(s_vecin);

        // ADAUGAM ULTIMUL CARACTER AL SUBSIRULUI VECIN LA SIRUL REZULTAT
        REZULTAT += s_vecin.back();
   } 
}

int main()
{
    // CITIRE
    cin>>N>>K;

    // DACA SUBSIRURILE AU LUNGIME 1, SIRUL DE LUNGIME N - K + 1 ESTE FORMAT & IL AFISAM
    if (K == 1)
    {
        for (int i = 0; i < N; i++)
        {
            cin>>SUBSIR;
            cout<<SUBSIR;
        }
        return 0;
    }

    for (int i = 0; i < N; i++)
    {
        cin>>SUBSIR;

        // DETERMINAM PREFIXUL: PRIMELE K - 1 LITERE
        PREFIX = SUBSIR.substr(0, K - 1);
        // DETERMINAM SUFIXUL: ULTIMELE K - 1 LITERE
        SUFIX = SUBSIR.substr(1);

        l_a[PREFIX].push_back(SUFIX);

        // ACTUALIZAM GRADUL INTERN AL SUFIXULUI
        g_intern[SUFIX]++;
        // ACTUALIZAM GRADUL EXTERN AL PREFIXULUI
        g_extern[PREFIX]++;
    }

    // DETERMINAM SUBSIRUL SURSA - PUNCTUL DE PLECARE
    SURSA = l_a.begin() -> first;

    int contor = 0;
    for (auto g_e : g_extern)
    {
        // CAUTAM SUBSIRUL CARE ARE GRADUL EXTERN MAI MARE DECAT GRADUL INTERN
        if (g_e.second > g_intern[g_e.first])
        {
            SURSA = g_e.first;
            contor++;
        }

        // DACA AM GASIT MAI MULTE PUNCTE DE PLECARE, NE OPRIM
        if (contor > 1)
        {
            cout<<"-1";
            return 0;
        }
    }

    DFS(SURSA);

    // DUPA DFS, SIRULUI REZULTAT ESTE INVERSAT, ASTFEL INVERSEZ SUBSIRUL SURSA PENTRU A-L PUTEA ADAUGA
    reverse(SURSA.begin(), SURSA.end());
    REZULTAT += SURSA;

    // INVERSAM SIRUL REZULTAT
    reverse(REZULTAT.begin(), REZULTAT.end());

    // DACA DIMENSIUNEA SIRULUI REZULTAT NU ESTE N + K - 1, NE OPRIM
    if (REZULTAT.size() != N + K - 1)
    {
        cout<<"-1";
        return 0;
    }

    // AFISARE
    cout<<REZULTAT;
    return 0;
}