#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

ofstream fout("accounts_merge.out");

vector<vector<string>> a = {{"John","johnsmith@mail.com","john_newyork@mail.com"},
                            {"John","johnsmith@mail.com","john00@mail.com"},
                            {"Mary","mary@mail.com"},
                            {"John","johnnybravo@mail.com"}};

class Solution 
{
public:
    // VECTOR DE TATI
    vector<int> v_p;

    // FUNCTIE CE DETERMINA TATAL UNEI ELEMENT: PERECHEA DIN CARE PROVINE O ADRESA DE EMAIL
    int e_parinte(int x)
    {
        if (v_p[x] == x) return x;
        return v_p[x] = e_parinte(v_p[x]);
    }

    // FUNCTIE CE REUNESTE DOUA PERECHI: AU ACELASI TATA
    void e_reuniune(int x, int y)
    {
        v_p[e_parinte(x)] = v_p[e_parinte(y)];
    }

    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        // MAP PENTRU FORMAREA PERECHILOR NUME - ADRESA DE EMAIL: 
        // NUME/ADRESA DE EMAIL - ID-UL PERECHII DIN CARE PROVINE
        unordered_map<string, int> map;

        v_p.resize(accounts.size() + 1);
        // FIECAREI PERECHI I SE ATRIBUIE UN TATA INITIAL: i
        for (int i = 0; i < accounts.size(); i++)
            v_p[i] = i;

        // PENTRU FIECARE ADRESA DE EMAIL
        for (int i = 0; i < accounts.size(); i++)
            for (int j = 1; j < accounts[i].size(); j++)
            {
                // DACA NU I S-A ATRIBUIT UN ID, I SE ATRIBUIE CEL CURENT: i
                if (map.find(accounts[i][j]) == map.end())
                    map[accounts[i][j]] = i;
                
                // ALTFEL, O ADRESA DE EMAIL APARE DE DOUA ORI: MULTIMILE DE EMAIL-URI SE REUNESC
                // SE REUNESTE MULTIMEA CURENTA CU CEA DIN CARE PROVINE ADRESA DE EMAIL
                else e_reuniune(i, map[accounts[i][j]]);
            }
        
        vector<string> n[accounts.size()];
        vector<vector<string>> n_e;

        for (auto p: map)
            n[e_parinte(p.second)].push_back(p.first);

        for (int i = 0; i < accounts.size(); i++)
        {
            // DACA O PERECHE NU MAI ARE ADRESE DE EMAIL, SE TRECE PESTE ACEASTA
            if(n[i].size() == 0)
                continue;
            
            // SORTAM ADRESELE DE EMAIL
            sort(n[i].begin(), n[i].end());

            // FORMAM PERECHEA NUME - ADRESE DE EMAIL
            vector<string> pereche;
            // ADAUGAM NUMELE
            pereche.push_back(accounts[i][0]);
            // ADAUGAM ADRESELE DE EMAIL
            for (auto e: n[i])
                pereche.push_back(e);
            
            // ADAUGAM PERECHEA LA RASPUNSUL FINAL
            n_e.push_back(pereche);
        }
        return n_e;
    }
};

int main()
{
    Solution s;
    a = s.accountsMerge(a);

    for (auto p: a)
    {
        fout<<p[0]<<": ";

        for (int i = 1; i < p.size(); i++)
            fout<<p[i]<<' ';
        
        fout<<endl;
    }
    return 0;
}
