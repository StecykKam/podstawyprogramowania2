#include <iostream>

using namespace std;

class TwoDimensionMatrix
{

    const static int size=2;
    int matrixtable[size][size];
    int** wskpom;

    public:

    TwoDimensionMatrix();
    TwoDimensionMatrix(const int matrix[size][size]);
    ~TwoDimensionMatrix();
    
    int get(int row, int column){return matrixtable[row][column];}
    static int getsize() {return size*size;} // liczba elementow
    void displayelements();
    void completewithonelement(int n);
    
    

    TwoDimensionMatrix& operator=(const TwoDimensionMatrix& matrix);

    TwoDimensionMatrix& operator*=(int number);
                    
    TwoDimensionMatrix operator&&(const TwoDimensionMatrix& matrix)const;

    int* operator[](size_t i){return matrixtable[i];}
    const int* operator[](size_t i)const{ return matrixtable[i];}                
   
    operator size_t()const {return size*size;}

    friend TwoDimensionMatrix operator+(const TwoDimensionMatrix& matrix1,const TwoDimensionMatrix& matrix2);
    friend ostream& operator<< (ostream&,TwoDimensionMatrix const&);
};

TwoDimensionMatrix operator+(const TwoDimensionMatrix& matrix1,const TwoDimensionMatrix& matrix2);
ostream& operator<< (ostream&,TwoDimensionMatrix const&);