#include <iostream>
#include <new>
#include <cstdlib>
#include <string.h>
#include <cstring>
using namespace std;

class Autor{
    string nume;

public:
    Autor();
    Autor(string);
    Autor(const Autor&);
    Autor& operator=(const Autor);
    virtual ~Autor();
};

Autor::Autor(){}
Autor::Autor(string N)
{
    nume=N;
}
Autor::Autor(const Autor& A)
{
    nume=A.nume;
}
Autor& Autor::operator=(const Autor A)
{
    if(this!=&A)
        nume=A.nume;
    return *this;
}
Autor::~Autor(){}

class Biblioteca{
protected:
    char denumire[50];

public:
    Biblioteca();
    Biblioteca(char[]);
    Biblioteca(const Biblioteca&);
    Biblioteca& operator=(const Biblioteca);
    virtual ~Biblioteca();

    virtual void Citire();
    virtual void Afisare();

    friend void strcat(char*,Biblioteca);
};

Biblioteca::Biblioteca(){}
Biblioteca::Biblioteca(char D[])
{
    strcpy(denumire,D);
}
Biblioteca::Biblioteca(const Biblioteca& B)
{
    strcpy(denumire,B.denumire);
}
Biblioteca& Biblioteca::operator=(const Biblioteca B)
{
    if(this!=&B)
        strcpy(denumire,B.denumire);
    return *this;
}
Biblioteca::~Biblioteca(){}

void Biblioteca::Citire()
{
    cout<<"Introduceti denumirea bibliotecii: ";
    cin.getline(denumire,50);
}
void Biblioteca::Afisare()
{
    cout<<"Denumirea bibliotecii este: "<<denumire<<endl;
}
void strcat(char* S,Biblioteca B)
{
    strcat(S,B.denumire);
}

class Carte: public Biblioteca{
protected:
    int aparitie;
    char titlu[50];

public:
    Carte();
    Carte(char[],int,char[]);
    Carte(const Carte&);
    Carte& operator=(const Carte);
    ~Carte();

    virtual void Citire();
    void Afisare();

    friend void strcat(char*,Carte);
};

Carte::Carte():Biblioteca(){}
Carte::Carte(char D[],int A,char T[]):Biblioteca(D)
{
    aparitie=A;
    strcpy(titlu,T);
}
Carte::Carte(const Carte& C):Biblioteca(C)
{
    aparitie=C.aparitie;
    strcpy(titlu,C.titlu);
}
Carte& Carte::operator=(const Carte C)
{
    if(this!=&C){
        this->Biblioteca::operator=(C);

        aparitie=C.aparitie;
        strcpy(titlu,C.titlu);
    }
    return *this;
}
Carte::~Carte(){}

void Carte::Citire()
{
    Biblioteca::Citire();
    cout<<"Introduceti titlul cartii: ";
    cin.getline(titlu,50);
    cout<<"Introduceti anul aparitiei cartii: ";
    cin>>aparitie;
}
void Carte::Afisare()
{
    Biblioteca::Afisare();
    cout<<"Titlul cartii este: "<<titlu<<endl;
    cout<<"Anul aparitiei cartii este: "<<aparitie<<endl;
}
void strcat(char* S,Carte C)
{
    strcat(S,C.denumire);
}

class InregistrareCarte: public Biblioteca{
protected:
    int isbn;
    int nrpagini;

public:
    InregistrareCarte();
    InregistrareCarte(char[],int,int);
    InregistrareCarte(const InregistrareCarte&);
    InregistrareCarte& operator=(const InregistrareCarte);
    ~InregistrareCarte();

    void Citire();
    void Afisare();
};

InregistrareCarte::InregistrareCarte():Biblioteca(){}
InregistrareCarte::InregistrareCarte(char D[],int I,int NR):Biblioteca(D)
{
    isbn=I;
    nrpagini=NR;
}
InregistrareCarte::InregistrareCarte(const InregistrareCarte& IC):Biblioteca(IC)
{
    isbn=IC.isbn;
    nrpagini=IC.nrpagini;
}
InregistrareCarte& InregistrareCarte::operator=(const InregistrareCarte IC)
{
    if(this!=&IC){
        this->Biblioteca::operator=(IC);

        isbn=IC.isbn;
        nrpagini=IC.nrpagini;
    }
    return *this;
}
InregistrareCarte::~InregistrareCarte(){}

void InregistrareCarte::Citire()
{
    Biblioteca::Citire();
    cout<<"Introduceti isbn-ul: ";
    cin>>isbn;
    cout<<"Introduceti numarul de pagini al cartii: ";
    cin>>nrpagini;
}
void InregistrareCarte::Afisare()
{
    Biblioteca::Afisare();
    cout<<"Isbn-ul cartii este: "<<isbn<<endl;
    cout<<"Numarul de pagini al cartii este: "<<nrpagini<<endl;
}

class FisaBiblioteca: virtual public Carte,virtual public InregistrareCarte{
protected:
    int id;
    char *Aut;
    int nrAutori;

public:
    FisaBiblioteca();
    FisaBiblioteca(char[],int,char[],int,int,int,char*);
    FisaBiblioteca(const FisaBiblioteca&);
    FisaBiblioteca& operator=(const FisaBiblioteca);
    ~FisaBiblioteca();

    void Citire();
    friend void strcat(char*,FisaBiblioteca);
};

FisaBiblioteca::FisaBiblioteca():Carte(),InregistrareCarte(){}
FisaBiblioteca::FisaBiblioteca(char D[],int A,char T[],int I,int NR,int NR_A,char* AT):Carte(D,A,T),InregistrareCarte(D,I,NR)
{
    try{
        Aut=new char[NR_A];
    }
    catch(bad_alloc xa){
        exit(EXIT_FAILURE);
    }
    nrAutori=NR_A;
    Aut=AT;

}
FisaBiblioteca::FisaBiblioteca(const FisaBiblioteca& FB):Carte(FB),InregistrareCarte(FB)
{
    id=FB.id;
    try{
        Aut=new char[FB.nrAutori];
    }
    catch(bad_alloc xa){
        exit(EXIT_FAILURE);
    }
    nrAutori=FB.nrAutori;
    for(int i=0;i<nrAutori;i++)
        Aut[i]=FB.Aut[i];
}
FisaBiblioteca& FisaBiblioteca::operator=(const FisaBiblioteca FB)
{
    if(this!=&FB){
        this->Carte::operator=(FB);
        this->InregistrareCarte::operator=(FB);

        id=FB.id;
        try{
            Aut=new char[FB.nrAutori];
        }
        catch(bad_alloc xa){
            exit(EXIT_FAILURE);
        }
        nrAutori=FB.nrAutori;
        for(int i=0;i<nrAutori;i++)
            Aut[i]=FB.Aut[i];

    }
    return *this;
}
FisaBiblioteca::~FisaBiblioteca(){}

/*
void strcat(char* S,FisaBiblioteca FB)
{
    strcat(S,FB.denumire);
}
*/
void FisaBiblioteca::Citire()
{
    Carte::Citire();
    cout<<"Introduceti id-ul: ";
    cin>>id;
    cout<<"Introduceti numarul de autori: ";
    cin>>nrAutori;
    for(int i=0;i<nrAutori;i++)
        cin>>Aut[i];
}

class GestiuneCarti{
    int nr;
    Biblioteca* *b;

public:
    GestiuneCarti& operator=(const GestiuneCarti);
    void Citire();
};

GestiuneCarti& GestiuneCarti::operator=(const GestiuneCarti GC)
{
    if(this!=&GC){
        nr=GC.nr;

        b=new Biblioteca*[nr];
        for(int i=0;i<nr;i++)
            b[i]=GC.b[i];
    }
    return *this;
}
void GestiuneCarti::Citire()
{
    int op;
    b=new Biblioteca*[nr];
    for(int i=0;i<nr;i++){
        cout<<"Introduceti optiunea de citire: 1 pentru o carte si 2 pentru o fisa de biblioteca!";
        cin>>op;

        switch(op)
        {
            case 1:{b[i]=new Carte();}
            case 2:{b[i]=new FisaBiblioteca();}

        }
        b[i]->Citire();
    }
}

int main()
{
    Biblioteca b("Eminescu");
    Carte c("Humanitas",1998,"Ion");
    FisaBiblioteca fb("Carturesti",1880,"Schite si Nuvele",45879,356,1,"Caragiale");

    char s[100]="";
    strcat(s,b);
    strcat(s,c);
    //strcat(s,fb);
    cout<<s;
    return 0;
}
