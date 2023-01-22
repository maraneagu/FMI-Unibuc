#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int N_NODURI = graph.size();
        
        int m_biti = (1<<N_NODURI) - 1;

        queue<pair<int,int>> q;
        vector<vector<bool>> vizitat(N_NODURI, vector<bool> (1<<N_NODURI, false));
        
        for (int i = 0; i < N_NODURI; i++) 
        {
            q.push({i, 1<<i});
            vizitat[i][1<<i] = true;
        }

        int c_hamiltonian = 0;

        while (!q.empty()) 
        {
            for (int k = q.size(); k > 0; k--) 
            {
                auto [nod, masca] = q.front();
                q.pop();

                if (masca == m_biti) 
                    return c_hamiltonian;
                
                for (auto n: graph[nod]) 
                {
                    if (!vizitat[n][masca | (1 << n)]) 
                    {
                        q.push({n, masca | (1 << n)});
                        vizitat[n][masca | (1 << n)] = true;
                    }
                }
            }
            c_hamiltonian++;
        }
        return c_hamiltonian; 
    }
};