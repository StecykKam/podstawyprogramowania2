#include <bitset>
#include <functional>
#include <iostream>
#include <exception>

struct Base
{
    virtual ~Base()
    {
    }
};

struct Derived : Base
{
    virtual void name()
    {
        std::cout << "name()" << std::endl;
    }
};


class float_divisionexcpt : public std::exception
{      

    std::string msg;
    int line_of_error;
    std::string name_of_function;

public:
    
    float_divisionexcpt(std::string message = "Float_division error ",int line = 0,std::string function_name ="None "):msg(message),line_of_error(line),name_of_function(function_name){}
    
    virtual const char* what() const noexcept{
    return "float division exception";
    }
    std::string get_message()const noexcept{return msg;}
    int get_line_of_error()const noexcept{return line_of_error;}
    std::string get_name_of_function()const noexcept{return name_of_function;}

};

class null_ptr_error : public float_divisionexcpt
{   
public:
    virtual const char* what()const noexcept{
    return "float division exception: null_ptr_error";
    }

    null_ptr_error(int line = 0,std::string function_name ="None ",std::string message = "Null_ptr error "):float_divisionexcpt(message,line,function_name){}
};

class denominator_is_zero : public float_divisionexcpt
{
public:
    virtual const char* what()const noexcept{
    return "float division exception: denominator_is_zero";
    }

    denominator_is_zero(int line = 0,std::string function_name ="None ",std::string message = "Denominator_is_zero error "):float_divisionexcpt(message,line,function_name){}

};


float division(int *num, int den)
{      
    std::string function_name = "float division(int* num,int den)";
    if(num == NULL) throw null_ptr_error(__LINE__,function_name);
    else if(den == 0) throw denominator_is_zero(__LINE__,function_name);
    return *num/den;
}



int main()
{
    // 0. Solve the quiz
    // https://www.geeksforgeeks.org/c-plus-plus-gq/exception-handling-gq/

    // 1. Handle standard exceptions
    try{int *myarray = new int[10000000000000L];}
    catch(const std::bad_alloc &e)
    {
        std::cerr << "Bad_alloc caught: " << e.what() << std::endl;
    }

    // 2. Handle standard exceptions
    
    
    try{
        Base     b;
        Derived &f = dynamic_cast<Derived &>(b);
       }
    catch(const std::bad_cast &e){
        std::cerr << "Bad_cast error caught: " << e.what() << std::endl;
        }



    // 3. Handle standard exceptions
    try{
    std::function<int(int, int)> add = std::plus<int>();
    std::function<int(int, int)> add2;

    std::cout << add(10, 20) << '\n';
    std::cout << add2(10, 20) << '\n';}
    
    catch(const std::bad_function_call &e)
    {
        std::cerr << "Bad function call error caught: " << e.what() << std::endl;
    }

    // 4. Handle standard exceptions
    try{
        Base *base = 0;
        typeid(*base);
    }
    catch(const std::bad_typeid &e)
    {
        std::cerr << "Bad_typeid error caught: " << e.what() << std::endl;
    }
    // 5. Handle standard exceptions
    
    try{
    std::bitset<128> x(1);
    std::cout << x.to_ulong() << std::endl;
    x.flip();
    std::cout << x.to_ulong() << std::endl;}
    catch(const std::overflow_error &e)
    {
        std::cerr << "Overflow error caught: " << e.what() << std::endl;
    }

    std::cout << "\n" << "I can do things without termination " << std::endl;


   

    // 6. Write a function: float division(int *num, int den)
    // write your own expection class(es) to handle two kinds of exceptions
    // throw when num is null or x == 0
    // provide and extra info about the exception (message, line, function name,
    // info) e.g throw myexception("msg", __FILE__, 
    // catch exceptions

     try
    {   
        int a =6;
        int* wsk1 = &a;
        std::cout << "REsult of float division: " << division(wsk1,a) << std::endl;

        int b = 6;
        int* wsk_null = NULL;
       
        std::cout << "REsult of float division: " << division(wsk_null,b) << std::endl;

       

    }
    catch(float_divisionexcpt &e)
    {
        std::cerr << "\n" << e.what() << ", Line of error: " << e.get_line_of_error() << " " << ", Function causing error: " << e.get_name_of_function() << std::endl;
    }


    try
    {   
        int a =6;
        int* wsk1 = &a;
       
        std::cout << "REsult of float division: " << division(wsk1,0) << std::endl;

    }
    catch(float_divisionexcpt &e)
    {
        std::cerr << "\n" << e.what() << ", Line of error: " << e.get_line_of_error() << " " << ", Function causing error: " << e.get_name_of_function() << std::endl;
    }


}
