#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

ifstream fin("scurt.in");
ofstream fout("scurt.out");

string text_1, text_2, s_c;

class Solution {
    string LCS(string text_1, string text_2, int lungime_1, int lungime_2)
    {
        int m_p_d[lungime_1 + 1][lungime_2 + 1];
        
        string s_c = "";
                
        for (int i = 0; i < lungime_1 + 1; i++)
            for (int j = 0; j < lungime_2 + 1; j++)
                if(i == 0 || j == 0)
                    m_p_d[i][j] = 0;
        
        for (int i = 1; i < lungime_1 + 1; i++)
            for (int j = 1; j < lungime_2 + 1; j++)
                if (text_1[i-1] == text_2[j-1])
                    m_p_d[i][j] = 1 + m_p_d[i-1][j-1];
                else
                    m_p_d[i][j] = max(m_p_d[i-1][j], m_p_d[i][j-1]);
        
        int i = lungime_1, j = lungime_2;
        
        while (i > 0 && j > 0)
        {
            if (text_1[i-1] == text_2[j-1])
            {
                s_c.push_back(text_1[i-1]); 
                --i; --j;
            }
            else if(m_p_d[i][j-1] > m_p_d[i-1][j])
            {
                s_c.push_back(text_2[j-1]);  
                --j;                       
            }
            else
            {
                s_c.push_back(text_1[i-1]); 
                --i;                
            }
        }
        
        while (i > 0)
        {
            s_c.push_back(text_1[i-1]);
            --i;
        }
        
        while (j > 0)
        {
            s_c.push_back(text_2[j-1]);
            --j;
        }
        
        reverse(s_c.begin(), s_c.end());
        return s_c;
    }
    
public:
    string shortestCommonSupersequence(string text_1, string text_2) {
        
        int lungime_1 = text_1.length();
        int lungime_2 = text_2.length();
        
        return LCS(text_1, text_2, lungime_1, lungime_2);
    }
};

int main()
{
    // CITIRE
    fin>>text_1>>text_2;

    Solution s;
    s_c = s.shortestCommonSupersequence(text_1, text_2);

    // AFISARE
    fout<<s_c;
    return 0;
}