#include <iostream>
#include "matrix.h" // uzupelnij plik tasks.json  |  "${file}", "${fileDirname}/klasy.cpp",
 
using namespace std;

TwoDimensionMatrix::TwoDimensionMatrix() // bez arg konstruktor
{
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<size;j++)
            {
                matrixtable[i][j]=0; // zerowanie tab
            }
    }

    }

TwoDimensionMatrix::TwoDimensionMatrix(const int matrix[size][size])
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            this->matrixtable[i][j]=matrix[i][j]; // kopiowanie z tab
        }

    }
}

TwoDimensionMatrix:: ~TwoDimensionMatrix()
{   
   
}


void TwoDimensionMatrix::displayelements()
{   

     cout<<"\n";

    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            cout<<matrixtable[i][j]<<" ";
        }
        cout<<"\n";
    }

    

}


TwoDimensionMatrix operator+(const TwoDimensionMatrix& matrix1,const TwoDimensionMatrix& matrix2)
{
    
    TwoDimensionMatrix result;
    for(int i=0;i<result.size;i++)
    {
        for(int j=0;j<result.size;j++)
        {
            result.matrixtable[i][j] = matrix1.matrixtable[i][j] + matrix2.matrixtable[i][j]; // jest przyjazn
        }
    }
    return result;
}


TwoDimensionMatrix& TwoDimensionMatrix::operator*=(const int number)
{

    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            this->matrixtable[i][j]=this->matrixtable[i][j] * number;
        }
    }
    return *this;
}

void TwoDimensionMatrix::completewithonelement(const int n)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            matrixtable[i][j]=n;
        }
    }

}


TwoDimensionMatrix& TwoDimensionMatrix::operator=(const TwoDimensionMatrix& matrix)
{

    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            matrixtable[i][j]=matrix[i][j];
        }
    }

    return *this;

}


TwoDimensionMatrix TwoDimensionMatrix::operator&&(const TwoDimensionMatrix& matrix)const
{
    TwoDimensionMatrix result;
    
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(this->matrixtable[i][j] == matrix.matrixtable[i][j])
            {
                result.matrixtable[i][j]=1; // ta sama wartosc na i j
            }
            else
            {
                result.matrixtable[i][j]=0;

            }
        }

    }

    return result;

}


ostream& operator<< (ostream &wyjscie, TwoDimensionMatrix const& matrix)
{
   wyjscie << matrix.matrixtable[0][0] <<" "<< matrix.matrixtable[0][1]<<"\n"<<matrix.matrixtable[1][0]<<" "<<matrix.matrixtable[1][1]<<endl;
   return wyjscie;
}


