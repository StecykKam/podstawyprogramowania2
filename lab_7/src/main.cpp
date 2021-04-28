#include <iostream>
#include <math.h>
#include <list>

using namespace std;


//////// product part

class Object
{

public:

    virtual void draw()const = 0;
    Object(int x = 1,int y = 1){wspolx = x; wspoly = y;}

protected:

    int wspolx;
    int wspoly;

};



class Square : public Object {

private:
  
  // Wspolrzedne
   // int wspolx;
   // int wspoly;
    int side;

public:
  
  Square(double _side_ = 10,int x = 1,int y =1) 
  :side(_side_),Object(x,y)
  {
    //std::cout << "Object Square created" << std::endl;
  }
  ~Square() {
    
    std::cout << "Object Square destroyed" << std::endl;
  }
  Square(const Square &sqr1) {  // kopiowanie
  side = sqr1.side; 
  Object::wspolx=sqr1.wspolx;
  Object::wspoly=sqr1.wspoly;
  }
  double getCircumference() const { return 4 * side; }
  double getArea() const { return side * side; }
  
  virtual void draw()const override
  {
      cout << "I am " << "Square and my area is " << getArea() << ", my Circumference: " << getCircumference() << endl;


  }


};





//////////////////////////circle
class Circle : public Object {
private:
  double radius;
  //int wspolx;
  //int wspoly;
  // Wspolrzedne
public:
  Circle(double _radius_ = 5,int x = 2,int y = 2) 
  :radius(_radius_),Object(x,y)
  {
    //std::cout << "Object Circle created" << std::endl;
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

  virtual void draw()const override
  { 

    cout << "I am " << "Circle and my area is " << getArea() << ", my Circumference: " << getCircumference() << endl;

  }


};



class StraightLine : public Object
{

private:

    int wspolx2,wspoly2;

public:

    StraightLine(int x1 = 1,int y1 = 0,int x2 = 2,int y2 = 1):Object(x1,y1){wspolx2 = x2;wspoly2 = y2;}
    
    double get_length()const
    {
        double tmpexp = (wspolx2 - wspolx)*(wspolx2 - wspolx) + (wspoly2 - wspoly)*(wspoly2 - wspoly);
        return sqrt(tmpexp);
    }

    virtual void draw()const override
    {
        cout << "I am " << "StraightLine and my length is " << get_length() << endl;
    }


};

class CurvedLine : public Object
{
    double length;

public:

    CurvedLine(double dl_line = 8.0){length = dl_line; }


    virtual void draw()const override
    {

        cout << "I am " << "CurvedLine and my length is " << length << endl;

    }

};



/// creators

class Drawing
{

private:

    int wielkosc;
    
public:

    list<Object*> objects;
    Drawing(int rozmiar = 500):wielkosc(rozmiar){}
    void add_to_list(Object* object_tmp){objects.push_back(object_tmp);}
    void print_all_elements_of_list()const
    {   
        cout << "\nMy work: " << endl;
        for(Object* e:objects)
        {
            e->draw();
            
        }
        cout << "\n" << endl;
    }

    ~Drawing()
    {
        for(Object* e:objects)
        {
            delete e;
        }
        objects.clear();
    }

};




class Painter
{

public:

    Drawing Created_objects;
    virtual ~Painter(){}
    virtual Object* createObject()const = 0;
    
    void draw();
    void printMyWork()const
    {
        Created_objects.print_all_elements_of_list();
    }

};

void Painter::draw()
{
    Object* tmp_obj = this->createObject();
    tmp_obj->draw();
    Created_objects.add_to_list(tmp_obj);
}



class CirclePainter : public Painter
{

public:

    virtual Object* createObject()const override
    {

        return new Circle();

    }

};


class SquarePainter : public Painter
{

    virtual Object* createObject()const override
    {
        return new Square();
    }

};


class StraightLinePainter : public Painter
{

    virtual Object* createObject()const override
    {
        return new StraightLine();
    }

};


class CurvedLinePainter : public Painter
{

    virtual Object* createObject()const override
    {
        return new CurvedLine();
    }

};



int main(int argc, char *argv[])
{
    std::cout << "Hello world." << std::endl;
    
    
    Painter* sq_painter = new SquarePainter();

    sq_painter->draw();
    sq_painter->draw();
    sq_painter->printMyWork();
    
    
    

    Painter* circle_painter = new CirclePainter();
    circle_painter->draw();
    circle_painter->draw();
    circle_painter->printMyWork();

    Painter* line_str = new StraightLinePainter();
    line_str->draw();
    line_str->draw();
    line_str->printMyWork();

    Painter* line_curved = new CurvedLinePainter();
    line_curved->draw();
    line_curved->draw();
    line_curved->printMyWork();

    delete sq_painter;
    delete line_str;
    delete line_curved;
    delete circle_painter;


    return 0;
}


