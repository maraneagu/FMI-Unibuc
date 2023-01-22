#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

ifstream f("catun.in");
ofstream g("catun.out");

int main(){
    int N,M,K;

    f>>N>>M>>K;

    // LISTA DE ADIACENTA
    vector<vector<pair<int,int>>> lista(N+1);

    // PENTRU FIECARE ASEZARE - COST MINIM & FORTAREATA CEA MAI APROPIATA
    vector<pair<int,int>> c_f(N+1, {INT32_MAX, 0});

    // COADA CU PRIORITATI PENTRU PARCURGEREA DRUMURILOR
    priority_queue<pair<int,int>> p_queue;

    // CITIRE
    int fortareata;
    for(int i = 0; i < K; i++)
    {
        f>>fortareata;

        // PENTRU FIECARE FORTAREATA, COSTUL MINIM VA FI 0,
        // IAR FORTAREATA CEA MAI APROPIATA VA FI CHIAR EA
        c_f[fortareata] = {0, fortareata};
        p_queue.push({0, fortareata});

    }

    int x,y,z;
    for(int i = 0; i < M; i++)
    {
        f>>x>>y>>z;
        lista[x].push_back({z, y});
        lista[y].push_back({z, x});

    }

    // PORNIND DE LA FIECARE FORTAREATA, II PARCURGEM CATUNELE
    // & DETERMINAM DRUMUL MINIM SPRE O FORTAREATA
    while(!p_queue.empty())
    {
        int nod = p_queue.top().second;
        p_queue.pop();

        for(auto vecin: lista[nod])
        {
            // COSTUL SPRE O FORTAREATA ESTE MAI MIC DECAT CEL CURENT
            // => ACTUALIZAM COSTUL SI CONTINUAM PARCURGEREA
            if(c_f[nod].first + vecin.first < c_f[vecin.second].first)
            {
                c_f[vecin.second] = {c_f[nod].first + vecin.first, c_f[nod].second};
                p_queue.push({-c_f[vecin.second].first, vecin.second});
            }
            // COSTUL SPRE O FORTAREATA ESTE EGAL CU CEL CURENT
            // => ALEGEM FORTAREATA CU IDENTIFICARE MINIMA
            else if(c_f[nod].first + vecin.first == c_f[vecin.second].first)
                c_f[vecin.second].second = min(c_f[nod].second, c_f[vecin.second].second);

        }
    }

    // AFISARE
    for(int i = 1; i <= N; i++)
        if(c_f[i].second == i)g<<0<<' ';
        else g<<c_f[i].second<<' ';
    return 0;
}
