#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <string>
#include <map>
#include <algorithm>
#include <iterator>

using namespace std;

class list_element
{   
    friend class double_way_list;
    list_element* previous;
    list_element* next;
    string value;

public:

    list_element(list_element* prev = nullptr,list_element* nxt = nullptr, string val = " "):previous(prev),next(nxt),value(val){}

};

////////////////////////////////////////////////

class double_way_list
{
    list_element* head;
    list_element* tail;
    static int elements;

public:

    double_way_list():head(nullptr),tail(nullptr){}
    ~double_way_list();
    void push_back(string val);
    int get_size()const{return elements;}
    operator vector<string>();
    operator list<string>();
    operator set<string>();
    operator string();
    operator map<string,string>();


    class iterator
    {
        list_element* cursor;
        
    public:

        iterator(const double_way_list& li):cursor(li.head){}
        iterator(list_element* ptr){cursor = ptr;}

        iterator& operator++()
        {
            if(cursor){cursor = cursor->next;}
            return *this;  
        }

        bool operator!=(const iterator& it){return this->cursor!=it.cursor;}
        
        string& operator*(){return cursor->value;}

         using difference_type = std::ptrdiff_t;
         using value_type = iterator;
         using pointer = iterator*;
         using reference = iterator&;
         using iterator_category = std::output_iterator_tag;


    };

    iterator begin(){return iterator(this->head);}
    iterator end(){return iterator(this->tail->next);}


};

int double_way_list::elements = 0;

////////////////////////////////////////////////   implementation part


 double_way_list::~double_way_list()
 {
     for(head;head;)
     {
         list_element* to_del = head;
         head = head->next;
         delete to_del;
     }

    head = tail = nullptr;
    this->elements = 0;

 }



void double_way_list::push_back(string val)
{
    list_element* le = new list_element(tail,nullptr,val);
    if(le->previous == nullptr){head = tail = le;}
    else
    {
        tail->next = le;
        tail = le;
    }

    this->elements++;

}



double_way_list::operator vector<string>()
{
    vector<string> con;
    con.reserve(this->elements);  // optimization
    for(auto it = this->begin();it != this->end();++it){con.push_back(*it);}


    return con;

}

double_way_list::operator list<string>()
{
    list<string> con;
    
    for(const auto& el : *this)
    {
        con.push_back(el);
    }
    
    return con;
}

double_way_list::operator set<string>()
{
    set<string> con;

    for(const auto& el : *this)
    {
        con.insert(el);
    }

    return con;

}

double_way_list::operator string()
{
    string all_content;
    
    for(const auto& e : *this )
    {
        all_content += e;
    }

    return all_content;
}

double_way_list::operator map<string,string>()
{
    map<string,string> con;

    for(const auto& el : *this)
    {
        con.emplace(el,el);

    }
    
    return con;

}








int main(int argc, char *argv[])
{
    std::cout << "---->Test1<-------------" << std::endl;

    double_way_list list1;
    list1.push_back("one");
    list1.push_back("two");
    list1.push_back("three");

    for(int i=0;i<12;++i)
    {
        list1.push_back(to_string(i));
    }

    cout << "Size: " << " ";
    cout << list1.get_size() << endl;

    for(auto& e : list1){cout << e << " ";}
    cout << "\n";


    double_way_list::iterator iter(list1);
    cout << "Iterator on first element: " << *iter << endl;
    ++iter;
    ++iter;
    cout << "After double ++: ";
    cout << *iter << endl;
    cout << "\n";

    
    cout << "\n----->TEST2<------" << endl;

    vector<string> to_vec;
    to_vec = static_cast<vector<string>>(list1);
    cout << "Result of convertion our list to std::vector: " << endl;
    for(const auto& el : to_vec){cout << el << " ";}
    cout << "\n\n";

    cout << "Result of convertion our list to std::set: " << endl;
    set<string> to_set;
    to_set = static_cast<set<string>>(list1);

    for(const auto& el : to_set)
    {
        cout << el << " ";
    }
    cout << "\n\n";



    cout << "\n------>Test3<---------"<<endl;


    cout << "Result of copying our list to std::vector by std::copy: " << endl;
    vector<string> to_cp;
    to_cp.reserve(list1.get_size());  // we have to reserve memory to then copy
    std::copy(list1.begin(),list1.end(),back_inserter(to_cp));
    
    for(const auto& e : to_cp)
    {
        cout << e << " ";
    }

    cout << "\n";
    cout << "\nResult of copying our list to std::list by std::copy " << endl;
    list<string> list_cpy;
    list_cpy.resize(list1.get_size());
    std::copy(list1.begin(),list1.end(),list_cpy.begin());

    for(const auto& el : list_cpy)
    {
        cout << el << " ";
    }

    cout << endl;

    cout << "\n------>Test4<---------" << endl;

    const string value_to_find = "20";
    const string value_to_find2 = "two";
    
    if(std::count(list1.begin(),list1.end(),value_to_find)){cout << "The element: " << value_to_find << " was found in our list" << endl;}
    else{cout << "The element: " << value_to_find << " was not found in our list" << endl;}

    if(std::count(list1.begin(),list1.end(),value_to_find2)){cout << "The element: " << value_to_find2 << " was found in our list" << endl;}
    else{cout << "The element: " << value_to_find2 << " was not found in our list" << endl;}

    
    cout <<  "\n------>Test5<---------" << endl;

    string value_to_count = "three";

    cout << "\nNumber of element: " << value_to_count << " in our list = ";    
    cout << std::count(list1.begin(),list1.end(),value_to_count) << endl;


    list1.push_back("three");
    list1.push_back("three");
    list1.push_back("three");

    cout << "\nNumber of element after adding: " << value_to_count << " in our list = ";    
    cout << std::count(list1.begin(),list1.end(),value_to_count) << endl;


    return 0;
}