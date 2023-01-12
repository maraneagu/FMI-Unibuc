#include <iostream>
#include <fstream>
using namespace std;

ifstream f("curatenie.in");
ofstream g("curatenie.out");

int contor=1,position[500001],rsd[500001];

struct nod{int left,right;}tree[500001];

void binary_tree(int e,int left,int right)
{
    if(position[e]>left)
    {
        tree[e].left = rsd[++contor];
        binary_tree(rsd[contor],left,position[e]-1);
    }
    if(position[e]<right)
    {
        tree[e].right = rsd[++contor];
        binary_tree(rsd[contor],position[e]+1,right);
    }
}

int main()
{
    int N,element;
    int i;

    f>>N;
    for(i=1;i<=N;++i)
    {
        f>>element;
        position[element]=i;
    }
    for(i=1;i<=N;++i)
    {
        f>>rsd[i];
    }

    binary_tree(rsd[1],1,N);

    for(i=1;i<=N;i++)
    {
        g<<tree[i].left<<' '<<tree[i].right;
        g<<"\n";
    }
    return 0;
}
