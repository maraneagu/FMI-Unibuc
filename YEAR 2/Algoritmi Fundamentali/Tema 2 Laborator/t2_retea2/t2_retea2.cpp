#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

ifstream f("retea2.in");
ofstream g("retea2.out");

#define DOUBLE_MAX 999999.999999;
double distanta[2001];
pair<int,int> centrala[2001], bloc[2001];

double distanta_b_c(pair<int,int> b, pair<int,int> c)
{
    return sqrt(1.0*(b.first-c.first)*(b.first-c.first) + 1.0*(b.second-c.second)*(b.second-c.second));
}

int selectat[2001];
double rezultat;

int main(){
    int N,M;

    // CITIRE
    f>>N>>M;

    for(int i = 0; i < N; i++)
        f>>centrala[i].first>>centrala[i].second;

    for(int i = 0; i < M; i++){
        f>>bloc[i].first>>bloc[i].second;
        distanta[i] = DOUBLE_MAX;
    }

    f.close();

    // DISTANTA DE LA UN BLOC LA O CENTRALA
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            distanta[i] = min(distanta[i], distanta_b_c(bloc[i],centrala[j]));

    double distanta_curenta;
    int bloc_curent;
    // M PASI - PENTRU SELECTIA CELOR M BLOCURI
    for (int i = 0; i < M; i++)
    {
        distanta_curenta = DOUBLE_MAX;

        // PARCURGEM CELE M BLOCURI
        // DINTRE CELE NESELECTATE, IL VOM ALEGE PE CEL CARE ARE DISTANTA CEA MAI MICA
        // FATA DE UN BLOC SAU O CENTRALA
        for(int j = 0; j < M; j++)
            if(selectat[j] == 0 && distanta[j] < distanta_curenta)
            {
                distanta_curenta = distanta[j];
                bloc_curent = j;
            }

        // MARCAM BLOCUL SELECTAT SI ACTUALIZAM REZULTATUL
        selectat[bloc_curent] = 1;
        rezultat += distanta_curenta;

        // RECALCULAM DISTANTELE MINIME FATA DE NOUL BLOC SELECTAT
        for(int j = 0; j < M; j++)
            distanta[j] = min(distanta[j], distanta_b_c(bloc[bloc_curent], bloc[j]));
    }

    // AFISARE
    g<<fixed<<setprecision(6)<<rezultat;
    g.close();
    return 0;
}
