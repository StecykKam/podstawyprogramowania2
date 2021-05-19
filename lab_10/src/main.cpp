#include <array>
#include <iostream>
using namespace std;
#define N 10
#include <stdexcept>

class VectoredList
{

    class Bucket
    {
    
    public:

        Bucket* previous;
        Bucket* next;

        int size_of_bucket;
        int capacity_of_block = N;
        std::array<std::string,N> values;

        static Bucket* getBucket(std::string val)
        {
            Bucket* new_bucket = new Bucket;
            new_bucket->values[0] = val;
            new_bucket->size_of_bucket++;
            new_bucket -> previous = new_bucket->next = NULL;
            return new_bucket;
        }

    };




public:

    Bucket* head;
    Bucket* tail;
    int size;
    int capacity;

    
   

/*
    VectoredList_iterator begin()
    {
        iterator.list_element = head;
        return iterator;
    } 

    VectoredList_iterator end()
    {
        iterator.list_element = tail;
        return iterator;
    }
    
    */

    VectoredList()
    {
        head = tail = 0;
        size = 0;
        capacity = N;
    }

    ~VectoredList()
    {
        while(head!=0)
        {
            Bucket* todel = head;
            head = head ->next;
            delete todel;
        }
    }

    void push_back(std::string value);

    std::string& operator[](int index)
    {
        if(index < 0){
            throw std::runtime_error( "You are out of range of array!!!" );
        }
        else
        {   
        
            Bucket* tmp = head;
            int block = index / 10;

            if(block >= size){throw std::runtime_error( "You are out of range of array!!!" );}

            int location = index % 10;

            for(int i=0;i<block;i++)
            {
                tmp = tmp -> next;
            }

            return tmp->values[location];

        }
        
    
    
    
    }


   /* class iterator
    {
    
    public:

        Bucket* list_element;
        string* value;
        int index;
        iterator():list_element(0){}
        iterator(Bucket* new_bucket):list_element(new_bucket){}

        bool operator!=(const iterator& itr)const
        {
            return  this->list_element != itr.list_element;
        }
        
        iterator& operator++()
        {
            this->list_element = list_element->next;
            return *this;

        }

    }; */


   

    //iterator begin(){return iterator(head);}
   // iterator end(){return iterator(tail);}


    class iterator
    {
    
    public:
        
        string* tmp_element;
        int index = 0;
        iterator(Bucket& tmp_bucket)
        {
            tmp_element = &tmp_bucket.values[0];
        }

        iterator& operator++()
        {
            
        }

        string& operator*()
        {
            
        }

        bool operator!=(iterator& to_compare)
        {
            return this->tmp_element == to_compare.tmp_element;
        }

    };

    iterator begin(){return iterator(*head);}
    iterator end(){return iterator(*tail);}


};

void VectoredList::push_back(std::string value)
{

   if(head == 0) // nic nie ma
   {
       Bucket* new_node = Bucket::getBucket(value);
       size++;
       head = new_node;
       tail = new_node;
       head->previous = 0;
       tail->next = 0;
       //return true;
   }


    else if(head != 0 && tail != 0 && tail->size_of_bucket < tail->capacity_of_block)
    {
        tail->values[tail->size_of_bucket++] = value; // zwiekszenie indxu po isntrukcji
        //return true;
    }

    else if(head != 0 && tail != 0 && tail->size_of_bucket >= tail->capacity_of_block)
    {
       Bucket* new_node = Bucket::getBucket(value); // new_node next juz wsakzuje na 0
       size++;
       new_node->previous = tail;
       tail->next = new_node; 
       tail = new_node; 
       //return true;

    }
    
    
   // return false;

}


int main()
{
    cout << endl << "---------- 1,2 ----------" << endl;
     VectoredList v;
     for (int i = 0; i < 101; ++i)
        {
            v.push_back("s" + to_string(i));
        }

//
    for(int i=0;i<N;i++)
    {
        cout << v.head->values[i] << endl;
    }
    cout << "\n";
    for(int i=0;i<N;i++)
    {
        cout << v.head->next->values[i] << endl;
    }

    cout << "index" << endl;
    cout << v[62] << endl;


    for(int i = 100 ; i>=0 ;i--)
    {
        cout << v[i] << " ";
    }

    
    try{
    cout << v[120] << endl;
    }
    catch(...){cout << "\nException - out of range" << endl;}


    


//
    
    // for (VectoredList::VectoredListIterator ita(v, 101); ita.good(); --ita)
    // {
    //     cout << ita.get() << " ";
    //     if (ita.cursor % 10 == 0)
    //         cout << endl;
    // }

    cout << endl << "---------- 3 ----------" << endl;;
    // for (const auto &element : v)
    //     cout << element << "AAA" << endl;

    cout << endl << "---------- 4 ----------" << endl;
    // VectoredList::VectoredListIterator it3(v, 3);
    // VectoredList::VectoredListIterator it33(v, 33);
    // VectoredList::VectoredListIterator it45(v, 45);

    // v.erase(it3);
    // v.pop_back();
    // v.pop_back();
    // v.erase(it33, it45);
    // for (int i = 0; i < v.VectoredListSize(); ++i)
    // {
    //     cout << v[i] << " ";
    //     if (i % 10 == 0)
    //         cout << endl;
    // }

    cout << endl << "---------- 5 ----------" << endl;
    // VectoredList v2 = v;
    // for (int i = 0; i < v2.VectoredListSize(); ++i)
    // {
    //     cout << v2[i] << " ";
    //     if (i % 10 == 0)
    //         cout << endl;
    // }
}
