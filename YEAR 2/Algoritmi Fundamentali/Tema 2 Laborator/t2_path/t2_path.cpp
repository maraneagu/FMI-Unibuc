#include <iostream>
#include <vector>
#include <queue>
using namespace std;

ifstream f("path.in");
ofstream g("path.out");

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        // LISTA DE ADIACENTA A GRAFULUI
        vector<vector<pair<int,double>>> lista(n+1);

        for(int i = 0; i < edges.size(); i++)
        {
            lista[edges[i][0]].push_back({edges[i][1], succProb[i]});
            lista[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        priority_queue<pair<double,int>> p_queue;
        // VOM PORNI DE LA VALOAREA start CU PROBABILITATEA MAXIMA 1 => 1.00
        p_queue.push({1.00, start});

        // VECTOR DE PROBABILITATI CURENTE
        vector<double> probabilitate(n+1, 0.00);
        probabilitate[start] = 1.00;

        while(!p_queue.empty())
        {
            int nod = p_queue.top().second;
            p_queue.pop();

            // PARCURGEM VECINII NODULUI CURENT
            // DACA PROBABILITATEA ESTE MAI MARE, O ACTUALIZAM
            for(int vecin: lista[nod])
                if(probabilitate[vecin.first] < probabilitate[nod] * vecin.second)
                {
                    probabilitate[vecin.first] = probabilitate[nod] * vecin.second;
                    p_queue.push({probabilitate[vecin.first], vecin.first});
                }
        }

        return probabilitate[end];
    }
};

int main()
{
    return 0;
}
