#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <list>
#include <memory>
#include <typeinfo>
#include <stdlib.h>
using namespace std;

class Figure {
  string type;
  class Point2D {
  public:
    int x_ob;
    int y_ob;
    Point2D() {
      x_ob = 0;
      y_ob = 0;
    }
    double getPtX() { return x_ob; };
    double getPtY() { return y_ob; };
    Point2D(int _x, int _y) {
      x_ob = _x;
      y_ob = _y;
    }
    void setPtXY(int x, int y) {
      x_ob = x;
      y_ob = y;
    }
  };
  Point2D coord;

public:
  Figure() {
    coord.x_ob = 0;
    coord.y_ob = 0;
  }
  virtual ~Figure() = default;
  void setXY(int _x, int _y) { coord.setPtXY(_x, _y); }
  void setType(const char *n) { type = n; }
  void getType() { cout << type; }
  string getType_str(){return type;}
  void getCo() { cout << "(" << coord.x_ob << " , " << coord.y_ob << ")"; }
  virtual double getArea()const { return 0; };
  virtual double getCircumference() { return 0; };
  Figure(const Figure &f) {
    this->setXY(f.getX(), f.getY());
    this->type = f.type;
  }
  virtual Figure *clone() const { return new Figure(*this); } 
  double getX() const { return this->coord.x_ob; }
  double getY() const { return this->coord.y_ob; }
};







class Square : public Figure {
private:
  string type = "Square";
  double side = 5;

public:
  static double count;

  Square(const Square &sq) : Figure(sq) {
    this->side = sq.side;
    count++;
  }

  Square(double _side_, int x, int y) {
    count++;
    side = _side_;
    std::cout << "Object Square created" << std::endl;
    this->setType("Square");
    this->setXY(x, y);
  }
  Square() {
    count++;
    this->setType("Square");
  };
  ~Square() {
    count--;
    std::cout << "Object Square destroyed" << std::endl;
  }
  double getCircumference() override { return 4 * side; }
  double getArea()const override { return side * side; }
  double getSide() { return side; }
  void set(double n) { side = n; }
  
  void changePosS(int a, int b) { this->setXY(a, b); }

  virtual Figure *clone() const { return new Square(*this); }   // 

};

double Square::count = 0;







class Circle : public Figure {
private:
  double radius = 10;

public:
  Circle(const Circle &cir) : Figure(cir) { this->radius = cir.radius; }
  Circle(double _radius_, int x, int y) {
    radius = _radius_;
    std::cout << "Object Circle created" << std::endl;
    this->setXY(x, y);
    this->setType("Circle");
  }
  Circle() {
    this->setType("Circle");
    this->setXY(0, 0);
  };
  ~Circle() { std::cout << "Object Circle destroyed" << std::endl; }
  double getCircumference() override { return 2 * M_PI * radius; }
  double getArea()const override { return M_PI * radius * radius; }
  static void print_pi() { std::cout << "Pi is " << M_PI << std::endl; }
  void set(double n) { radius = n; }
  double getRadius() { return radius; }
  void changePosC(int a, int b) { this->setXY(a, b); }

  virtual Figure *clone() const { return new Circle(*this); }     //

};








class Drawing {
private:
  
  int r_x, r_y;
  list<Figure *> figureList;

public:
  Drawing() {
    r_x = 20;
    r_y = 20;
  };
  Drawing(int _rx, int _ry) {
    r_x = _rx;
    r_y = _ry;
    cout << "Drawing has been created." << endl;
  }
  Drawing(const Drawing &f){};
  ~Drawing() {
    
    if(figureList.size() != 0)
    {
      for(auto e:figureList)
      {
        delete e;
      }
    }

    figureList.clear();
    cout << endl << "Clear the lsit." << endl;
  }
  Drawing *deepcopy(const Drawing *copy) { return new Drawing(*copy); }
  void setSize(int rx, int ry) {
    r_x = rx;
    r_y = ry;
  }
  void addFigure(Figure *ab) { figureList.push_back(ab); };
  void printList() {
    cout << endl << "List of elements: " << endl;
    for (auto const &v : figureList) {
      cout << "Figure type: ";
      v->getType();
      cout << " ";
      cout << endl << "Co-ordinates: ";
      v->getCo();
      cout << endl;
      cout << "Area: " << v->getArea()
           << " Circumference: " << v->getCircumference() << endl
           << endl;
    }
    cout << endl;
  }
  void eraser(int idx) {
    list<Figure *>::iterator itr = figureList.begin();
    advance(itr, idx);
    figureList.erase(itr);
  }

  int get_dim_x()const{return r_x;}
  int get_dim_y()const{return r_y;}

  list<Figure*>& getList(){return figureList;}

  friend ostream& operator<<(ostream& os, const Drawing& object);
  friend istream& operator>>(istream& is, Drawing& object);
  
  


  Figure& operator[](int n)
  {
    cout<<"Wyluskanie"<<endl;
    int counter = 0;
    for(auto e:figureList)
    {
      if(counter == n)
      {
        return *e;
      }
      ++counter;
    }
    
    exit(1);

  }

  Figure& operator()(int n)
  {

    int counter = 0;
    for(auto e:figureList)
    {
      if(counter == n)
      {
        return *e;
      }
      ++counter;
    }

    
    exit(1);  // domyslnie
    

  }


  Drawing& operator+=(Drawing& object)    // dokonuje zmiany na naszym obieckie
  {
    //int size_of_figures = object.figureList.size();
    for(auto e:object.figureList)
    {
      Figure* tmp = e->clone();
      this->figureList.push_back(tmp);
      
    }

    return *this; 

  }



  friend Drawing operator+(const Drawing& object1,const Drawing& object2);

  
  Drawing& operator=(const Drawing& object_to_assign)
  {
    if(&object_to_assign != this) // zabezpieczenie na a=a
    {
    figureList.clear();
    this->r_x = object_to_assign.r_x;
    this->r_y = object_to_assign.r_y;

    for(auto e:object_to_assign.figureList)
    {
      Figure* new_element = e->clone();
      this->figureList.push_back(new_element);

    }
    }
    return *this;

  }

};



///////////////////////////////////////////////////////////



ostream& operator<<(ostream& os,Figure& object)
{
  os << "Figure type: ";
  os<<object.getType_str();
  os << " ";
  os  << endl << "Co-ordinates: ";
  os<<"(" << object.getX()<<","<<object.getY()<<")"<<endl;
  os << "Area: " << object.getArea()<<endl;
  os << "Circumference: " << object.getCircumference();
  os << endl;
  os<<"\n";
  return os;
}


ostream& operator<<(ostream& os,const Drawing& object)
{ 
  os<<"\n";
  os << "List of elements:" << endl;
  
  for(auto const &e:object.figureList)
  {
    os << *e;                  //przeciazenie class Figure
  }
  
  os << "Size of Drawing:" << object.r_x << " x " << object.r_y << endl;
  os << endl;

  return os;

}


istream& operator>>(istream& is, Drawing& object)
{
  cout << "Insert changed dimensions.." << endl;
  is >> object.r_x >> object.r_y;
  return is;

}

bool operator==(const Drawing& object1 ,const Drawing& object2)
{ 
  int dimx_obj1 = object1.get_dim_x();
  int dimx_obj2 = object2.get_dim_x();
  int dimy_obj1 = object1.get_dim_y();
  int dimy_obj2 = object2.get_dim_y();

  if((dimx_obj1 == dimx_obj2) && (dimy_obj1 == dimy_obj2))
  {
    return true;
  }
  
  return false;

}


Drawing operator+(const Drawing& object1,const Drawing& object2) // nie dokonuje zmian na naszym obiekcie
  {
    Drawing new_one;
    for(auto e:object1.figureList)
    { 
      Figure* tmp = e->clone();
      new_one.figureList.push_back(tmp);
    }
    for(auto e:object2.figureList)
    {
      Figure* tmp = e->clone();
      new_one.figureList.push_back(tmp);
    }
    return new_one;
  }

bool operator<(const Figure& object1,const Figure& object2)
{
  if(object2.getArea() >= object1.getArea())
  {
    return true;
  }

  return false;

}


bool PComp(const Figure *const &a, const Figure *const &b) { return *a < *b;} // przeciazenie <


int main(int argc, char *argv[]) {
  Drawing *drawing = new Drawing(100, 100);
  Drawing *drawing2 = new Drawing(200, 200);

  Circle *c1 = new Circle(5, 10, 15);
  Square *s1 = new Square(5, 10, 15);
  drawing->addFigure(c1);
  drawing->addFigure(s1);

  drawing2->addFigure(c1);
  drawing2->addFigure(s1);

  Square *sq1 = new Square(*s1);
  Circle *cir2 = new Circle(*c1);
  drawing->addFigure(cir2);
  drawing->addFigure(sq1);

  Drawing tmpdrawing(100,100);
  
  // 1 // print all available info
  std::cout << *drawing << std::endl;

  // 2 // change the drawing dimensions
  
  std::cin >> *drawing;
  
  // 3 // comparison
  
  if (*drawing == *drawing2) {
  std::cout << "Drawing are equal" << std::endl;
  }

  // 4 // sort the figures based on area (compare pointer by the dereference)
  // uncoment also PComp function
  
  drawing->getList().sort(PComp);

  cout<<*drawing;

  // 5 // return the n'th element in the figure list
  
  std::cout << (*drawing)[0] << std::endl;

  // 6 // return the n'th element in the figure list
  
  std::cout << (*drawing)(0);

  // 7 // add figures from drawing2 to drawing
  
  *drawing += *drawing2; //
  //cout<<*drawing;
  *drawing = *drawing + *drawing2;
  //cout<<*drawing;

  // 8 //add copy assigment operator
  
  *drawing = *drawing2;
  
  //cout<<*drawing;

  // 9 // fix the memory leak

  // 10 // clean the code

  // jest destruktor zwalniajacy pamiec w liscie
  
  delete drawing;
  delete drawing2;
 // delete c1;
  //delete s1;
  //delete sq1;
 // delete cir2;

  return 0;
}