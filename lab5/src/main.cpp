#include <iostream>
#include "matrix.h"
#define rozmiarmac 2

const int TwoDimensionMatrix::size;

using namespace std;

int main(int argc, char *argv[])
{
    std::cout << "Hello world." << std::endl;
    
   
   
   
    int tablica[rozmiarmac][rozmiarmac]={{1,2},{3,4}};

    TwoDimensionMatrix matrix1(tablica);
    
    cout<<"Rozmiar: "<<matrix1.getsize();
    

    matrix1.displayelements();

    int wiersz=1;
    int kolumna=1;

    cout<<"Przeciazenie strumienia"<<endl;
    cout<<matrix1;
    

    if(wiersz >= rozmiarmac || kolumna >= rozmiarmac) {cout<<"Błąd"<<endl;}

    cout<<matrix1.get(wiersz,kolumna)<<endl;


    int tablica2[rozmiarmac][rozmiarmac]={{5,4},{3,2}};
    TwoDimensionMatrix matrix2(tablica2);
    matrix2.displayelements();
    TwoDimensionMatrix wynikdodawania;
    wynikdodawania = (matrix1+ matrix2);
    wynikdodawania.displayelements();    

    wynikdodawania*=6;
    wynikdodawania.displayelements();

    TwoDimensionMatrix wyniklogicznego;

    wyniklogicznego=matrix1 && matrix2;

    wyniklogicznego.displayelements();

    
    matrix1=matrix2;
    matrix1.displayelements();
    
    matrix1.completewithonelement(6);
    matrix1.displayelements();
    matrix2.displayelements();

    int* wsk=matrix2[1];
    //2 element
    cout<<"Wartosc wsk: "<<*(wsk+1)<<endl; //wsk dostajemy sie do pierwszego el wiersza


    return 0;
}
