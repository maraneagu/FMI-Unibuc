#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

ifstream f("queue.in");
ofstream g("queue.out");

int main(){
    int N;

    std::vector<int> STACK_1,STACK_2;

    int i;
    f>>N;
    for(i=1;i<=N;i++){
        char INPUT[21];

        f>>INPUT;
        g<<i<<": ";

        if(INPUT[1]=='u')
        {
            int P=10,NUMBER=0;
            while(isdigit(INPUT[P]))
            {
                NUMBER*=10;
                NUMBER+=INPUT[P]-'0';
                P++;
            }
            STACK_1.push_back(NUMBER);

            g<<"read("<<NUMBER<<") push(1,"<<NUMBER<<")";
        }
        else
        {
            int WR;
            if(STACK_2.empty()&&!STACK_1.empty())
            {
                while(STACK_1.size()>1){
                    WR=STACK_1.back();

                    g<<"pop(1) push(2,"<<WR<<") ";

                    STACK_2.push_back(WR);
                    STACK_1.pop_back();
                }
                WR=STACK_1.back();
                g<<"pop(1)"<<" write("<<WR<<") ";
                STACK_1.pop_back();
            }
            else
            {
                WR=STACK_2.back();
                g<<"pop(2) write("<<WR<<") ";
                STACK_2.pop_back();
            }
        }

        g<<"\n";
    }

    f.close();
    g.close();
    return 0;
}
