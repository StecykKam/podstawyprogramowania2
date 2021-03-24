#include <iostream>
#include <cmath>
#include<list>

using namespace std;

//deklaracja
class Drawing;


//////////////////////////figure
class figure
{
protected:

string nazwa;
int wspolx;
int wspoly;


public:

figure(int x=0,int y=0,string nazwad="domyslna")
:wspolx(x),wspoly(y),nazwa(nazwad){}
friend class Drawing;


};


//////////////////////////////square
class Square: public figure {
private:
  
  // Wspolrzedne
int side;
public:
  static double count;
  Square(double _side_,int x,int y,string nazwa="kwadratdomyslny") // x,y w klasie bazowej
  :side(_side_),figure(x,y,nazwa)
   {
    count++;
    std::cout << "Object Square created" << std::endl;
  }
  ~Square() {
    count--;
    std::cout << "Object Square destroyed" << std::endl;
  }
  Square(const Square &sqr1) {  // kopiowanie
  side = sqr1.side; 
  wspolx=sqr1.wspolx;
  wspoly=sqr1.wspoly;
  }
  double getCircumference() const { return 4 * side; }
  double getArea() const { return side * side; }
  


};

double Square::count = 0;

//////////////////////////circle
class Circle: public figure {
private:
  double radius;
  // Wspolrzedne
public:
  Circle(double _radius_,int x,int y,string nazwa="kolodomyslne") 
  :radius(_radius_),
  figure(x,y,nazwa)
  {
    std::cout << "Object Circle created" << std::endl;
  }
  ~Circle() { std::cout << "Object Circle destroyed" << std::endl; }
  Circle(const Circle &cir1) {
     radius = cir1.radius;
     wspolx=cir1.wspolx;
     wspoly=cir1.wspoly;

      }
  double getCircumference() const { return 2 * M_PI * radius; }
  double getArea() const { return M_PI * radius * radius; }
  void print_pi() { std::cout << "Pi is " << M_PI << std::endl; }
};




/////////////////////// drawing
class Drawing {
private:
  
  int wielkosc;

public:
  
  list<figure*> figury; // kompozycja, bo zawiera
  Drawing(int rozmiar=500)
  :wielkosc(rozmiar){}

  ~Drawing(){}

  void narysujkwadrat(int bok,int x,int y,string nazwa="kwadratdomysl")
  {
      figure* ptrkwadrat=new Square(bok,x,y,nazwa);
      figury.push_back(ptrkwadrat);

  }
 
 
  void narysujkolo(int promien,int x,int y,string nazwa="kolodomysl")
  { 

      figure* ptrkolo= new Circle(promien,x,y,nazwa);
      figury.push_back(ptrkolo);

  }
  
  
  void kopiujfigure(figure* wsk)
  {
    int kopiax=wsk->wspolx;
    int kopiay=wsk->wspoly;

    figure* wskkopia=new figure();
    figury.push_back(wskkopia);

  }


  void usunfigure(int miejscewliscie)
  {   
      auto iterator=figury.begin();
      //figury *wsk=
      int i;
      for(i=0;i<miejscewliscie;i++,iterator++) // dochodzi iterator do danego miejsca
      figury.erase(iterator);
      //delete wsk;
      
  }


  void zmienpolozenie(figure* wsk,int zmianax,int zmianay) // podajemy wsk w liscie
  {
      wsk->wspolx=zmianax;
      wsk->wspoly=zmianay;

  }

  void wylistuj()
  {
    for(figure* e:figury)
    {
        cout<<e->nazwa<<" "<<e->wspolx<<" "<<e->wspoly<<endl;

    }

  }


};

int main(int argc, char *argv[]) { 
  
  Drawing malarz1;
  malarz1.narysujkwadrat(5,1,2,"1 kwadrat");
  malarz1.narysujkolo(2,5,6,"1kolo");
  malarz1.wylistuj();
  malarz1.usunfigure(1); // w noramlnej kolejnosci, nie od zera
  cout<<"Czy usunie"<<endl;
  malarz1.wylistuj();
  
  
   }
