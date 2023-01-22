#include <iostream>
#include <vector>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

ifstream fin("euler.in");
ofstream fout("euler.out");

// VECTOR CE RETINE PERECHILE DE NODURI
vector<vector<int>> perechi;
// VECTOR CE RETINE PERECHILE DE NODURI ALE CICLULUI EULERIAN
vector<vector<int>> c_eulerian;

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>> &pairs) 
    {
        int N_PERECHI = pairs.size();
        
        // MATRICE DE ADIACENTA
        unordered_map<int, stack<int>> m_a;

        // VECTOR CE DETERMINA NUMARUL DE APARITII AL UNUI NOD PE PRIMA POZITIE DIN PERECHE
        unordered_map<int, int> p_in;

        // VECRTOR CE DETERMINA NUMARUL DE APARITII AL UNUI NOD PE A DOUA POZITIE DIN PERECHE
        unordered_map<int, int> p_out;

        // VECTOR CE RETINE PERECHILE CICLULUI EULERIAN
        vector<vector<int>> c_eulerian;

        m_a.reserve(N_PERECHI + 1);
        p_in.reserve(N_PERECHI + 1);
        p_out.reserve(N_PERECHI + 1);
        
        // CONTORIZAM APARITIILE PE POZITII & FORMAM MATRICEA DE ADIACENTA
        for (int i = 0; i < N_PERECHI; i++) 
        {
            int in, out;

            in = pairs[i][0];
            out = pairs[i][1];

            p_in[in]++;
            p_out[out]++;

            m_a[in].push(out);
        }
		
        // DETERMINAM NODUL DE START
        int n_start = -1;
        for (auto& pereche : m_a) 
        {
            int p = pereche.first;
            if (p_in[p] - p_out[p] == 1) 
                n_start = p;
        }

        // DACA n_start A RAMAS -1, ATUNCI CICLUL EULERIAN POATE INCEPE DIN ORICE NOD
        if (n_start == -1) 
			n_start = m_a.begin()->first;

        C_EULERIAN(m_a, c_eulerian, n_start);
        reverse(c_eulerian.begin(), c_eulerian.end());

        return c_eulerian;
    }
private:
    void C_EULERIAN(unordered_map<int, stack<int>> &m_a, vector<vector<int>> &c_eulerian, int n_in) 
    {
        // STIVA DE NODURI ADIACENTE NODULUI CURENT
        auto& s = m_a[n_in];

        while (!s.empty()) 
        {
            int n_out = s.top();
            s.pop();

            // CONTINUAM PARCURGEREA GRAFULUI
            C_EULERIAN(m_a, c_eulerian, n_out);
			
            // ADAUGAM PERECHEA DE NODURI DUPA APEL, PENTRU A EVITA CAZURILE DE NODURI IZOLATE
            c_eulerian.push_back({n_in, n_out});
        }
    }
};

int main()
{
    // CITIRE
    int x, y;
    while (fin>>x>>y)
        perechi.push_back({x, y});

    Solution s;
    c_eulerian = s.validArrangement(perechi);

    // AFISARE
    int p = c_eulerian.size();
    for (int i = 0; i < p; i++)
        fout<<'['<<c_eulerian[i][0]<<", "<<c_eulerian[i][1]<<']'<<endl;
    return 0;
}