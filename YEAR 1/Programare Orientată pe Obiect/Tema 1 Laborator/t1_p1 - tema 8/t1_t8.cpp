#include <iostream>
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
    Multime& operator=(Multime&);

    // DESTRUCTOR
    ~Multime();

    // SET & GET (PENTRU TOATE DATELE MEMBRE)
    void Set_Lungime(int);
    int Get_Lungime();

    void Set_Vector(int,int);
    int Get_Vector(int);

    // OPERATORII PENTRU INTRARI & IESIRI
    friend istream& operator>>(istream&, Multime&);
    friend ostream& operator<<(ostream&, const Multime&);

    // TRANSFORMAREA UNUI VECTOR IN MULTIME
    void Transformare_In_Multime();

    // REUNIUNEA - OPERATORUL+
    Multime operator+(Multime);

    // INTERSECTIA - OPERATORUL*
    Multime operator*(Multime);

    // DIFERENTA - OPERATORUL-
    Multime operator-(Multime);

    // CITIREA SI AFISAREA A n MULTIMI
    friend void N_Multimi();
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

Multime& Multime::operator=(Multime& ob){
    if(this != &ob){
        vector = new int[ob.lungime];
        lungime = ob.lungime;
        for(int i=0;i<lungime;i++)
            vector[i] = ob.vector[i];
    }
    return *this;
}

Multime::~Multime(){
    delete[] vector;
}

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

Multime Multime::operator+(Multime B){
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
    *(this)=aux;
    return *(this);
}

Multime Multime::operator*(Multime B){
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

    *(this)=aux;
    return *(this);
}

Multime Multime::operator-(Multime B){
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

    *(this)=aux;
    return *(this);
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
            M[i].Transformare_In_Multime();
            cout<<M[i];
        }

        int tasta;
        cout<<endl<<"PENTRU A REUNI CELE "<<N<<" MULTIMI, TASTATI 1!"<<endl;
        cout<<"PENTRU A INTERSECTA CELE "<<N<<" MULTIMI, TASTATI 2!"<<endl;
        cout<<"PENTRU A FACE DIFERENTA CELOR "<<N<<" MULTIMI, TASTATI 3!"<<endl;
        cout<<"TASTA ALEASA: ";
        cin>>tasta;


        if(tasta==1){
            for(i=1;i<N;i++)
                M[0]+M[i];
            cout<<M[0];
        }
        else if(tasta==2){
            for(i=1;i<N;i++)
                M[0]*M[i];
            cout<<M[0];
        }
        else{
            for(i=1;i<N;i++)
                M[0]-M[i];
            cout<<M[0];
        }
    }
}

int main(){
    N_Multimi();
    return 0;
}

void Multime::Set_Lungime(int L){lungime = L;}
int Multime::Get_Lungime(){return lungime;}

void Multime::Set_Vector(int P,int E){
    if(P>=0 && P<=lungime)
        vector[P] = E;
}
int Multime::Get_Vector(int P){return vector[P];}

void Multime::Transformare_In_Multime(){
    Multime aux(0);

    int i,j;
    for(i=0;i<lungime;i++){
        bool apare=false;
        for(j=0;j<aux.lungime;j++)
            if(aux.vector[j]==vector[i]){
                apare=true;
                break;
            }
        if(apare==false){
            aux.vector[aux.lungime]=vector[i];
            aux.lungime++;
        }
    }
    *(this)=aux;
}

