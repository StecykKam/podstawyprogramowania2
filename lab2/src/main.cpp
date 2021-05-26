#include <math.h>
#include <iostream>



class Square
{
    private:
    float dlugoscboku;
    float polekwadratu;
    float obwod;
    static int lobiektow;

    public:
    Square(float dlboku) // konstruktor
    {
        dlugoscboku=dlboku;
        lobiektow++;
        std::cout<<"Object Square created!"<<std::endl;
    }
    ~Square()
    {
         std::cout<<"Object Square destroyed"<<std::endl;
         lobiektow--;
    }

    void polekw()
    {
        polekwadratu=dlugoscboku*dlugoscboku;
    }

    void obwodkw()
    {
        obwod=dlugoscboku*4;
    }

    void wyswietl()
    {
        std::cout<<"Pole kwadratu: "<<polekwadratu<<" Obwód: "<<obwod<<std::endl;
    }


    void wyswietlilosc()
    {
        std::cout<<"Liczba obiektow"<<lobiektow;
    }

};

int Square::lobiektow = 0;

class Circle
{
    private:
    float promien;
    float polek;
    float obwodk;


    public:
    Circle(float pr) // konstruktor
    {
        promien=pr;
        std::cout <<"Object Cirle created!"<<std::endl;
    }
    ~Circle()
    {
        std::cout <<"Object Circle destroyed"<<std::endl;
    }

    void polekola()
    {
        polek=M_PI*promien*promien; /// pir^2
    }

    void obwodkola()
    {
        obwodk=2*M_PI*promien;
    }

     void wyswietl()
    {
        std::cout<<"Pole kola: "<<polek<<" Obwód: "<<obwodk<<std::endl;
    }

    static float zwrocpi()
    {
        return M_PI;
    }


};


int main(int argc, char *argv[])
{

   // std::cout << "Hello world." << std::endl;

    Square kwadrat1(10);
    Circle kolo1(6);

    kwadrat1.polekw();
    kwadrat1.obwodkw();

    kwadrat1.wyswietl();

    kolo1.polekola();
    kolo1.obwodkola();
    kolo1.wyswietl();



    return 0;
}