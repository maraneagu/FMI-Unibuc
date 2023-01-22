#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

ifstream f("cuvinte.in");

// VECTOR CE RETINE CUVINTELE CITITE
vector<string> cuvant(10001);

// PRIORITY QUEUE PENTRU ORDONAREA PERECHILOR DE CUVINTE CRESCTOR DUPA DISTANTA LEVENSHTEIN
priority_queue<pair<int,pair<int,int>>> p_queue;

// VECTOR DE TATI, PENTRU FORMAREA CELOR K GRUPE
vector<int> tata;

int d_levenshtein(string cuvant_1,string cuvant_2)
{
    int lungime_1 = cuvant_1.size();
    int lungime_2 = cuvant_2.size();

    vector<vector<int>> d(lungime_1+1, vector<int>(lungime_2+1));

    for(int i = 1; i <= lungime_1; i++)
        d[i][0] = i;
    for(int i = 1; i <= lungime_2; i++)
        d[0][i] = i;

    for(int i = 1; i <= lungime_1; i++)
        for(int j = 1; j <= lungime_2; j++)
            d[i][j] = std::min({d[i-1][j] + 1,
                                d[i][j-1] + 1,
                                d[i-1][j-1] + (cuvant_1[i-1] == cuvant_2[j-1] ? 0 : 1)});

    return d[lungime_1][lungime_2];
}

int radacina(int nod)
{
    if(tata[nod] == 0)return nod;
    return radacina(tata[nod]);
}

int main()
{
    // CITIRE
    int K;
    cout<<"K= "; cin>>K;

    int N=0;
    while(f>>cuvant[N++]);
    cuvant.resize(N+1);

    // DISTANTA LEVENSHTEIN DINTRE ORICARE DOUA CUVINTE
    for(int i = 0; i < N; i++)
        for(int j = i+1; j < N; j++)
        {
            int l_distanta = d_levenshtein(cuvant[i],cuvant[j]);

            // ADAUGARE PERECHI IN PRIORITY QUEUE, CE LE VA ORDONA DESCRESCATOR DUPA DISTANTA
            p_queue.push({-l_distanta, {i, j}});
        }

    tata.resize(N+1, 0);
    pair<int,pair<int,int>> element;

    int element_1, element_2, radacina_1, radacina_2;
    int contor = 0;

    while(!p_queue.empty())
    {
        element = p_queue.top();
        p_queue.pop();

        element_1 = element.second.first;
        element_2 = element.second.second;
        radacina_1 = radacina(element_1);
        radacina_2 = radacina(element_2);

        // DACA DOUA CUVINTE NU SUNT IN ACEEASI GRUPA, REUNIUNE
        if(radacina_1 != radacina_2)
        {
            tata[radacina_1] = radacina_2;
            contor++;
        }

        // CAND S-AU FORMAT CELE K GRUPE, NE OPRIM
        if(contor == N-K)break;
    }

    // AFISARE

    // a) GRUPE
    for(int i = 0; i < N; i++)
        if(tata[i] == 0)
        {
            cout<<cuvant[i]<<' ';

            for(int j = 0; j < N; j++)
                if(radacina(j) == i && i != j)
                    cout<<cuvant[j]<<' ';

            cout<<endl;
        }

    // b) GRADUL DE SEPARARE

    // DISTANTA DINTRE PRIMELE DOUA CUVINTE, CARE NU SE AFLA IN ACEEASI GRUPA
    while(!p_queue.empty())
    {
        element = p_queue.top();
        p_queue.pop();

        element_1 = element.second.first;
        element_2 = element.second.second;
        radacina_1 = radacina(element_1);
        radacina_2 = radacina(element_2);

        if(radacina_1 != radacina_2)
        {
            cout<<-element.first;
            break;
        }
    }
    return 0;
}
