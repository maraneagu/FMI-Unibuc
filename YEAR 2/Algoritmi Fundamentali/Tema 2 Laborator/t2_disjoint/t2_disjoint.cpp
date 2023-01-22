#include <iostream>
#include <fstream>
using namespace std;

#define MAX 100001
int radacina[MAX],rang[MAX];
int radacina_x,radacina_y;
int N,M;
int operatie,x,y;

ifstream f("disjoint.in");
ofstream g("disjoint.out");

int c_radacina(int x)
{
    if(radacina[x] == 0)return x;
    return c_radacina(radacina[x]);
}

void operatie_1(int x,int y)
{
    radacina_x = c_radacina(x);
    radacina_y = c_radacina(y);

    // UNIM ARBORELE CU RANG MAI MIC CU CEL CU RANG MAI MARE
    // ACTUALIZAM RADACINA ARBORELUI MAI MIC
    // ACTUALIZAM RANGUL ARBORELUI MAI MARE
    if(rang[x] < rang[y])
    {
        radacina[radacina_x] = radacina_y;
        rang[radacina_y] += rang[radacina_x];
    }
    else
    {
        radacina[radacina_y] = radacina_x;
        rang[radacina_x] += rang[radacina_y];
    }
}

bool operatie_2(int x,int y)
{
    return(c_radacina(x) == c_radacina(y));
}

int main()
{
    // CITIRE
    f>>N>>M;

    // FORMAM MULTIMILE INITIALE
    // FIECARE NOD ARE RANGUL 1, FIIND RADACINA
    for(int i = 1; i <= N; i++)
        rang[i] = 1;

    for(int i = 0; i < M; i++)
    {
        f>>operatie>>x>>y;

        switch(operatie)
        {
            case 1: {operatie_1(x,y); break;}
            case 2: if(operatie_2(x,y))g<<"DA\n";
                else g<<"NU\n";
        }
    }
    return 0;
}
