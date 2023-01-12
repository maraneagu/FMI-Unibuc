#include <iostream>
#include <fstream>
#include <new>
#include <cstdlib>
using namespace std;

class Multime{
    int lungime;
    int *vector;

public:
    // CONSTRUCTOR DE INITIALIZARE
    Multime();
    Multime(int);

    // CONSTRUCTOR DE COPIERE
    Multime(const Multime&);

    // OPERATOR DE ATRIBUIRE
    Multime& operator=(const Multime);

    /*
    // DESTRUCTOR
    ~Multime();
    */
    // SET & GET (PENTRU TOATE DATELE MEMBRE)
    void Set_Lungime(int);
    int Get_Lungime();

    void Set_Vector(int,int);
    int Get_Vector(int);

    // OPERATORII PENTRU INTRARI & IESIRI
    friend istream& operator>>(istream&, Multime&);
    friend ostream& operator<<(ostream&, const Multime&);

    // TRANSFORMAREA UNUI VECTOR IN MULTIME
    friend void Transformare_In_Multime(Multime&);

    // REUNIUNEA - OPERATORUL+
    const Multime operator+(Multime);

    // INTERSECTIA - OPERATORUL*
    const Multime operator*(Multime&);

    // DIFERENTA - OPERATORUL-
    const Multime operator-(Multime&);

    // CITIREA SI AFISAREA A n MULTIMI
    friend void N_Multimi();

    // TRUE - CITIRE DIN CONSOLA, FALSE - CITIRE DIN FISIER
    Multime(bool);

    // OPERATOR-
    Multime operator-(); // VERSIUNEA PREFIXATA
    // VERSIUNEA POSTFIXATA
    Multime operator-(int);

    // OPERATOR--
    Multime operator--(); // VERSIUNEA PREFIXATA
    // VERSIUNEA POSTFIXATA
    Multime operator--(int);
};

Multime::Multime(){}

Multime::Multime(int L){
    try{
        vector = new int[L];
    }catch (bad_alloc xa){
        cout<<"Allocation Failure!"<<endl;
        exit(EXIT_FAILURE);
    }
    lungime = L;
}

Multime::Multime(const Multime& ob){
    try{
        vector = new int[ob.lungime];
    }catch (bad_alloc xa){
        cout<<"Allocation Failure!"<<endl;
        exit(EXIT_FAILURE);
    }
    lungime = ob.lungime;
    for(int i=0;i<lungime;i++)
        vector[i] = ob.vector[i];
}

Multime& Multime::operator=(const Multime ob){
    if(this != &ob){
        vector = new int[ob.lungime];
        lungime = ob.lungime;
        for(int i=0;i<lungime;i++)
            vector[i] = ob.vector[i];
    }
    return *this;
}

/*
Multime::~Multime(){
    delete[] vector;
}
*/

istream& operator>>(istream& in, Multime& ob){
    cout<<"NUMARUL DE ELEMENTE AL VECTORULUI: ";
    in>>ob.lungime;

    cout<<"ELEMENTELE VECTORULUI: ";
    ob.vector = new int[ob.lungime];
    for(int i=0;i<ob.lungime;i++)
        in>>ob.vector[i];
    cout<<endl;

    return in;
}

ostream& operator<<(ostream& out, const Multime& ob){
    cout<<"NUMARUL DE ELEMENTE ALE MULTIMII: ";
    out<<ob.lungime<<endl;

    cout<<"ELEMENTELE MULTIMII: ";
    for(int i=0;i<ob.lungime;i++)
        out<<ob.vector[i]<<' ';
    out<<endl;

    return out;
}

const Multime Multime::operator+(Multime B){
    Multime aux(*(this));

    int i,j;
    for(i=0;i<B.lungime;i++){
        bool apare=false;
        for(j=0;j<lungime;j++)
            if(vector[j]==B.vector[i]){
                apare=true;
                break;
            }
        if(apare==false){
            aux.vector[aux.lungime]=B.vector[i];
            aux.lungime++;
        }
    }
    cout<<aux;
    return aux;
}

const Multime Multime::operator*(Multime& B){
    Multime aux(0);

    int i,j;
    for(i=0;i<lungime;i++){
        bool apare=false;
        for(j=0;j<B.lungime;j++)
            if(B.vector[j]==vector[i]){
                apare=true;
                break;
            }
        if(apare==true){
            aux.vector[aux.lungime]=vector[i];
            aux.lungime++;
        }
    }
    return aux;
}

const Multime Multime::operator-(Multime& B){
    Multime aux(0);

    int i,j;
    for(i=0;i<lungime;i++){
        bool apare=false;
        for(j=0;j<B.lungime;j++)
            if(B.vector[j]==vector[i]){
                apare=true;
                break;
            }
        if(apare==false){
            aux.vector[aux.lungime]=vector[i];
            aux.lungime++;
        }
    }

    return aux;
}

void N_Multimi(){
    int N,i;

    cout<<"NUMARUL DE VECTORI CARE VOR FI INTRODUSI DE LA TASTATURA: ";
    cin>>N;
    cout<<endl;

    Multime M[N];
    for(i=0;i<N;i++)cin>>M[i];

    char litera;
    cout<<"PENTRU A TRANSFORMA CEI "<<N<<" VECTORI IN MULTIMI, TASTATI LITERA 'M'! DACA DORITI SA RAMANA VECTORI, TASTATI LITERA 'V'!"<<endl;
    cout<<"LITERA ALEASA: ";
    cin>>litera;
    if(litera=='M'||litera=='m'){
        cout<<endl<<"DUPA TRANSFORMARE, MULTIMILE SUNT: "<<endl;
        for(i=0;i<N;i++){
            Transformare_In_Multime(M[i]);
            cout<<M[i];
        }

        int tasta;
        cout<<endl<<"PENTRU A REUNI CELE "<<N<<" MULTIMI, TASTATI 1!"<<endl;
        cout<<"PENTRU A INTERSECTA CELE "<<N<<" MULTIMI, TASTATI 2!"<<endl;
        cout<<"PENTRU A FACE DIFERENTA CELOR "<<N<<" MULTIMI, TASTATI 3!"<<endl;
        cout<<"TASTA ALEASA: ";
        cin>>tasta;

        if(tasta==1){
            Multime aux(M[0]);
            for(i=1;i<N;i++)
                aux=aux+M[i];
            cout<<aux;
        }
        else if(tasta==2){
            Multime aux(M[0]);
            for(i=1;i<N;i++)
                aux=aux*M[i];
            if(aux.lungime==0)cout<<"MULTIMEA VIDA!";
            else cout<<aux;
        }
        else{
            Multime aux(M[0]);
            for(i=1;i<N;i++)
                aux=aux-M[i];
            if(aux.lungime==0)cout<<"MULTIMEA VIDA!";
            else cout<<aux;
        }
    }
}

Multime::Multime(bool citire){
    if(citire==true)
        cin>>*(this);
    else{
        ifstream f("citire_fisier.txt");
        f>>*(this);
        f.close();
    }
}

Multime Multime::operator-(){
    int i;
    for(i=0;i<lungime;i++)
        vector[i]=-vector[i];
    return *this;
}

Multime Multime::operator--(){
    lungime--;
    return *this;
}

Multime Multime::operator--(int x){
    lungime--;
    return *this;
}

class Management{
    int lungime;
    Multime *vector;

public:
    // CONSTRUCTOR DE INITALIZARE
    Management();

    // CONSTRUCTOR DE COPIERE
    Management(const Management&);

    // OPERATORUL DE ATRIBUIRE
    Management& operator=(const Management);

    // OPERATORII PENTRU INTRARI & IESIRI
    friend istream& operator>>(istream&, Management&);
    friend ostream& operator<<(ostream&, const Management&);
};

Management::Management(){};

Management::Management(const Management& ob){
    try{
        vector = new Multime[ob.lungime];
    }catch (bad_alloc xa){
        cout<<"Allocation Failure!"<<endl;
        exit(EXIT_FAILURE);
    }
    lungime = ob.lungime;
    for(int i=0;i<lungime;i++)
        vector[i] = ob.vector[i];
}

Management& Management::operator=(const Management ob){
    if(this != &ob){
        vector = new Multime[ob.lungime];
        lungime = ob.lungime;
        for(int i=0;i<lungime;i++)
            vector[i] = ob.vector[i];
    }
    return *this;
}

istream& operator>>(istream& in, Management& ob){
    cout<<"NUMARUL DE VECTORI: ";
    in>>ob.lungime;

    ob.vector = new Multime[ob.lungime];
    int i;
    for(i=0;i<ob.lungime;i++)
        in>>ob.vector[i];
    return in;
}

ostream& operator<<(ostream& out, const Management& ob){
    cout<<"NUMARUL DE MULTIMI: ";
    out<<ob.lungime<<endl;

    for(int i=0;i<ob.lungime;i++)
        out<<ob.vector[i]<<' ';
    out<<endl;

    return out;
}

int main(){
    Multime M;
    cin>>M;
    cout<<M;
    return 0;
}

void Multime::Set_Lungime(int L){lungime = L;}
int Multime::Get_Lungime(){return lungime;}

void Multime::Set_Vector(int P,int E){
    if(P>=0 && P<=lungime)
        vector[P] = E;
}
int Multime::Get_Vector(int P){return vector[P];}

void Transformare_In_Multime(Multime& ob){
    Multime aux(0);

    int i,j;
    for(i=0;i<ob.lungime;i++){
        bool apare=false;
        for(j=0;j<aux.lungime;j++)
            if(aux.vector[j]==ob.vector[i]){
                apare=true;
                break;
            }
        if(apare==false){
            aux.vector[aux.lungime]=ob.vector[i];
            aux.lungime++;
        }
    }
    ob=aux;
}
