#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

ifstream fin("lung.in");
ofstream fout("lung.out");

string text_1, text_2;

class Solution {
public:
    int longestCommonSubsequence(string text_1, string text_2) 
    {
        int lungime_1 = text_1.length();
        int lungime_2 = text_2.length();

        vector<vector<int>> m_p_d(lungime_1 + 1, vector<int>(lungime_2 + 1, 0));
        
        for (int i = 1; i <= lungime_1; i++)
        {
            for (int j = 1; j <= lungime_2; j++)
            {
                if (text_1[i-1] == text_2[j-1])
                    m_p_d[i][j] = m_p_d[i-1][j-1] + 1;
                else
                    m_p_d[i][j] = max(m_p_d[i-1][j], m_p_d[i][j-1]);
            }
        }
        return m_p_d[lungime_1][lungime_2];
    }
};

int main()
{
    // CITIRE
    fin>>text_1>>text_2;

    Solution s;
    int s_c = s.longestCommonSubsequence(text_1, text_2);

    // AFISARE
    fout<<s_c;
    return 0;
}