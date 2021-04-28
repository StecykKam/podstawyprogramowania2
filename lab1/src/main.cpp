#include <iostream>

void dodawanie1(int a, int b, int *c);
void dodawanie2(int *a,int *b,int *c);
void dodawanie3( int &a, int &b, int *c);
void dodawanie4(int *&a, int *&b, int *c);
void dodawanietablicy1(int taba[10], int tabb[10],int tabc[10]);
void dodawanietablicy2(int *taba,int *tabb, int *tabc);
void dodawanietablicy3(int taba[], int tabb[],int tabc[]);
void dodawanietablicy4(int (&taba)[10],int (&tabb)[10],int (&tabc)[10]);

int main(int argc, char *argv[])
{
    std::cout << "Dodawanie liczb" <<std::endl;

    int *a,*b,*c,d,e,f;
    d=10;
    e=12;
    f=0;
    c=&f;

    
    a=&d;

    b=&e;

    dodawanie1(d,e,c);

    dodawanie2(a,b,c);

    dodawanie3(d,e,c);
    
    dodawanie4(a,b,c);
   
    std::cout << "Dodawanie tablic" <<std::endl;

    int taba[10]={0,1,2,3,4,5,6,7,8,9};
    int tabb[10]={11,12,13,14,15,16,17,18,19,20};
    int tabc[10];

    dodawanietablicy1(taba,tabb,tabc);
    dodawanietablicy2(taba,tabb,tabc);
    dodawanietablicy3(taba,tabb,tabc);
    dodawanietablicy4(taba,tabb,tabc);
    
    return 0;

}


void dodawanie1(int a, int b, int *c)
{   
    *c= a + b;
    
    std::cout<<"Wynik 1 dodawania = "<<*c<<std::endl; 
    std::cout << "\n";
}

void dodawanie2(int *a,int *b,int *c)
{
    *c=*a + *b;

    std::cout<<"Wynik 2 dodawania = "<<*c<<std::endl; 
     std::cout << "\n";
}

void dodawanie3( int &a, int &b, int *c)
{
    *c=a+b;
    std::cout<<"Wynik 3 dodawania = "<<*c<<std::endl; 
     std::cout << "\n";
}

void dodawanie4(int *&a, int *&b, int *c)
{

    *c=*a + *b;
    std::cout<<"Wynik 4 dodawania = "<<*c<<std::endl;
     std::cout << "\n";
}


void dodawanietablicy1(int taba[10], int tabb[10],int tabc[10])
{
    for(int i=0;i<10;i++)
    {
        tabc[i]=taba[i]+tabb[i];
        std::cout << "Dodawanie tablicy 1 = " <<tabc[i]<<std::endl;
    }
     std::cout << "\n";
}

void dodawanietablicy2(int *taba,int *tabb, int *tabc)
{
     for(int i=0;i<10;i++)
    {
        tabc[i]=taba[i]+tabb[i];
        std::cout << "Dodawanie tablicy 2 = " <<tabc[i]<<std::endl;
    }
     std::cout << "\n";
}

void dodawanietablicy3(int taba[], int tabb[],int tabc[])
{
     for(int i=0;i<10;i++)
    {
        tabc[i]=taba[i]+tabb[i];
        std::cout << "Dodawanie tablicy 3 = " <<tabc[i]<<std::endl;
    }
     std::cout << "\n";
}

void dodawanietablicy4(int (&taba)[10],int (&tabb)[10],int (&tabc)[10])
{
    for(int i=0;i<10;i++)
    {
        tabc[i]=taba[i]+tabb[i];
        std::cout << "Dodawanie tablicy 4 = " <<tabc[i]<<std::endl;
    }

}