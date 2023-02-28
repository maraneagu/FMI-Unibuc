#include <iostream>
#include <vector>
using namespace std;

// GRAHAM'S SCAN, VARIANTA ANDREW

int N;
vector<pair<long long,long long>> L;
pair<long long,long long> aux, p, q, r;
long long delta;

int main()
{
    cin>>N;

    // RETINEM P1, P2 IN L
    cin>>p.first>>p.second>>q.first>>q.second;
    L.push_back(make_pair(p.first, p.second));
    L.push_back(make_pair(q.first, q.second)); 

    for (int i = 2; i < N; i++)
    {
        cin>>r.first>>r.second;

        // ADAUG Pi LA FINALUL LUI L
        L.push_back(make_pair(r.first, r.second));

        // CALCUL DETERMINANT
        delta = q.first*r.second + r.first*p.second + p.first*q.second - q.first*p.second - r.first*q.second - p.first*r.second;

        // L ARE MAI MULT DE DOUA PUNCTE, ULTIMELE 3 NU DETERMINA VIRAJ STANGA
        while (L.size() > 2 && delta <= 0)
        {
            // STERGERE PENULTIM ELEMENT
            r = L[L.size() - 1];
            L.pop_back();
            L.pop_back();
            L.push_back(r);

            // RECALCULARE DETERMINANT
            p = L[L.size() - 3];
            q = L[L.size() - 2];
            delta = q.first*r.second + r.first*p.second + p.first*q.second - q.first*p.second - r.first*q.second - p.first*r.second;
        }

        p = L[L.size() - 2];
        q = L[L.size() - 1];
    }

    // CALCUL DE INTOARCERE
    r = L[0];

    // CALCUL DETERMINANT
    delta = q.first*r.second + r.first*p.second + p.first*q.second - q.first*p.second - r.first*q.second - p.first*r.second;

    // L ARE MAI MULT DE DOUA PUNCTE, ULTIMELE 3 NU DETERMINA VIRAJ STANGA
    while (L.size() > 2 && delta <= 0)
    {
        // STERGERE PENULTIM ELEMENT
        L.pop_back();

        // RECALCULARE DETERMINANT
        p = L[L.size() - 2];
        q = L[L.size() - 1];
        r = L[0];
        delta = q.first*r.second + r.first*p.second + p.first*q.second - q.first*p.second - r.first*q.second - p.first*r.second;
    }
 
    cout<<L.size()<<endl;
    for (int i = 0; i < L.size(); i++)
        cout<<L[i].first<<' '<<L[i].second<<endl;
    return 0;
}