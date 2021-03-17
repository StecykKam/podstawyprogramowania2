#include <iostream>

#include <iostream>
#include <cmath>

using namespace std;

class Square {
private:
  double side;
  // Wspolrzedne
  float x=5,y=5;

public:
  static double count;
  Square(double _side_) {
    count++;
    side = _side_;
    std::cout << "Object Square created" << std::endl;
  }
  ~Square() {
    count--;
    std::cout << "Object Square destroyed" << std::endl;
  }
  Square(const Square &sqr1) { side = sqr1.side; }
  double getCircumference() const { return 4 * side; }
  double getArea() const { return side * side; }
  void wypiszinf(){std::cout<<"Polozenie kwadratu: "<<"("<<x<<","<<y<<")"<<std::endl;}
};

double Square::count = 0;

class Circle {
private:
  double radius;
  // Wspolrzedne
  float m=10,n=10;

public:
  Circle(double _radius_=5) {
    radius = _radius_;
    std::cout << "Object Circle created" << std::endl;
  }
  ~Circle() { std::cout << "Object Circle destroyed" << std::endl; }
  Circle(const Circle &cir1) { radius = cir1.radius; }
  double getCircumference() const { return 2 * M_PI * radius; }
  double getArea() const { return M_PI * radius * radius; }
  static double print_pi() { std::cout << "Pi is " << M_PI << std::endl; }
  //std::cout<<"Polozenie kola: "<<"("<<Circle::x<<","<<Circle::y<<")"<<std::endl;
};

class Drawing {
private:
  // Kwadrat i Kolo
  // Rozmiar plotna



    class Circle{
    private:
        int radius;
        int position_x,position_y;
    public:
        Circle(int posx=10,int posy=10,int radius=5)
        {
            position_x=posx;
            position_y=posy;
            radius=5;
        };
         void wyswko(){std::cout << position_x<<" "<<position_y << std::endl;}
    };

    Circle *kolo;

        class Square{
        int bok;
        int position_x,position_y;
        public:
        Square(int posx=5,int posy=5,int bok=5)
        {
            position_x=posx;
            position_y=posy;
            bok=5;
        }
        void wyswkw(){std::cout << position_x<<" "<<position_y << std::endl;}
    };

    Square *kwadrat;
    const int size_x=20,size_y=20;


public:
  // Konstruktory
  // Destruktor
  // Pobierz Informacje



  Drawing(){
    kwadrat=new Square;
    kolo=new Circle;

  }

   Drawing* deepcopy(const Drawing* kopiowany)
   {

       return new Drawing(*kopiowany);
   }

  ~Drawing()
  {
        delete kwadrat;
        delete kolo;
  }

  void wypiszinfo()
  {
      cout<<"Szerokość płotna: "<<size_x<<" Wysokosc: "<<endl;
      cout<<"Pozycja kola"<<" ";
      kolo->wyswko();
      cout<<"Pozycja kwadratu"<<" ";
      kwadrat->wyswkw();



  }

};

int main(int argc, char *argv[]) {
















  return 0; }
