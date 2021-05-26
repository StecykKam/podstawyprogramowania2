#include <array>
#include <iostream>
using namespace std;
#define N 10
#include <stdexcept>
#include <vector>
#include <string.h>

class VectoredList
{

    class Bucket
    {
    
    public:

        Bucket* previous;
        Bucket* next;

        int size_of_bucket;   // current size
        int capacity_of_block = N;      //general capacity
        std::array<std::string,N> values;

        static Bucket* getBucket(std::string val)
        {
            Bucket* new_bucket = new Bucket;
            new_bucket->values[0] = val;
            new_bucket->size_of_bucket++;
            new_bucket -> previous = new_bucket->next = NULL;
            return new_bucket;
        }

        Bucket(Bucket* other){
            next=0; // nie chcemy wskazywac na to samo, tylko chcemy nowy bucket nie skorelowany z tym przekazywanym
            previous=0;
            
            for(int i=0;i<N;++i){values[i]=" ";}
            
            size_of_bucket=other->size_of_bucket;
            capacity_of_block=other->capacity_of_block;
            for(int i=0;i<size_of_bucket;i++)
                values[i]=other->values[i];
        }

        Bucket* get_Bucket_copy(Bucket* other)
        {   
            //Bucket* wsk_tmp = &other;
            Bucket* new_bucket = new Bucket(other);
            return new_bucket;

        }
        Bucket()=default;


    };




public:

    Bucket* head;
    Bucket* tail;
    int size;  // current number of blocks
    int capacity; // general capacity (all elements, whcich we can allocate or allocated)


//////////////

    VectoredList(VectoredList &&v);
    void assign(vector<string> v);
    VectoredList operator+(const VectoredList& rhs)const;
    VectoredList &operator=(VectoredList &&v);
    
/////////////

   

    int VectoredListSize()const
    {
        return size;
    }

    int VectoredListCapacity()const{return capacity;}

    void push_back(std::string &&value);

    int how_many_elements_allocated()const
    {
        int sum = 0;
        Bucket* tmp_head = head;
        while(tmp_head)
        {
            sum += tmp_head->size_of_bucket;
            tmp_head = tmp_head->next;
        }
        return sum;
    }

    void free_me()
    {

        Bucket* tmp_to_del;
        for(head;head!=0;)
        {   
            head-> size_of_bucket = 0; // we free elements
            tmp_to_del = head;
            head=head->next;
            delete tmp_to_del;
        }
        head=tail=0;
        capacity = 0;
        size = 0;

    }


    VectoredList& operator=(VectoredList& other){              //jest blad
        

        //cout << head->values[0] << "Wartosc w heaedzie assgnment" << endl;

        while(head!=0)
        {
            Bucket* todel = head;
            head = head ->next;
            delete todel;
        }
        
        size=other.size;
        capacity=other.capacity;
        head = new Bucket(other.head);
        Bucket only_to_cpy;
     
       head = only_to_cpy.get_Bucket_copy(other.head);
        int blocks=size/10;
    
        Bucket* head_tmp = head;
        Bucket* wsk = other.head;
        /*head->next = only_to_cpy.get_Bucket_copy(wsk->next);

        head->next->next = only_to_cpy.get_Bucket_copy(wsk->next->next);

        head->next->next->next = only_to_cpy.get_Bucket_copy(wsk->next->next->next);*/
        
       for(int i=0;i<blocks-1;i++)
        {   
            
            head_tmp->next = only_to_cpy.get_Bucket_copy(wsk->next);
            
            head_tmp = head_tmp->next;
            wsk = wsk->next;

        }


        return *this;
    }
   

    VectoredList()
    {
        head = tail = 0;
        size = 0;
        capacity = 0; // change
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

    void push_back(const std::string& value);

    std::string& operator[](int index)const
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


    class VectoredListIterator
    {
    
    public:
        
        string tmp_element;
        Bucket* list_element;
        Bucket* cursor;
        int size_of_container;
        int index = 0;
      
        VectoredListIterator(VectoredList& v,int position):list_element(v.head)
        {   
            v.head->previous = 0;
            index = position;
            size_of_container = v.size;
            Bucket* ptr_element = list_element;
            int block = index / 10;

            if(block >= v.size){throw std::runtime_error( "You are out of range of array!!!" );}

            int location = index % 10;

            for(int i=0;i<block;i++)
            {
                ptr_element = ptr_element -> next;
            }
             cursor = ptr_element;
             tmp_element = ptr_element->values[location];

        }

        VectoredListIterator(Bucket* tmp_bucket,int pos)
        {
            list_element = tmp_bucket;
            cursor = tmp_bucket;
            index = pos;
            

        }

        int good(){
            
            if((index < 0) && (cursor->previous == 0) ){return 0;}
            else if((index >= size_of_container*N)){return 0;}
            //&& (cursor->next == 0)
            else{return 1;}
            
        } // wsk przed headem
        string& get(){return tmp_element;}

        VectoredListIterator& operator++()
        {
            if(index<size_of_container*N){index++;} // zabezpieczenie
            Bucket* ptr_element = list_element;
            int block = index / 10;

          
            int location = index % 10;

            for(int i=0;i<block;i++)
            {
                ptr_element = ptr_element -> next;
            }
             cursor = ptr_element;
             if(index<N*size_of_container){tmp_element = ptr_element->values[location];}
             return *this;
        }

        string& operator*()
        {
            return cursor->values[index%10]; // index jakis w tej konkretnej tablicy
            //return tmp_element;
        }

        VectoredListIterator& operator--()
        {
            index--;
            Bucket* ptr_element = list_element;
            int block = index / 10;

            
            int location = index % 10;

            for(int i=0;i<block;i++)
            {
                ptr_element = ptr_element -> next;
            }
             cursor = ptr_element;
             tmp_element = ptr_element->values[location];
             return *this;
        }

        bool operator!=(VectoredListIterator& to_compare)
        {
           // return this->cursor != to_compare.cursor;
        
            if((this->index == to_compare.index) && (this->cursor == to_compare.cursor))
            {return false;}
            else{return true;}
        
        }   

    };

  VectoredListIterator begin()const{return VectoredListIterator(this->head,0);}
  VectoredListIterator end()const{return VectoredListIterator(this->tail,size*N-1);} // przesylam index koncowy np 109
  
  void erase(VectoredListIterator& itr)
  {
      VectoredListIterator tmp(*this,itr.index+1);
      
      int position_to_delete = itr.index;
      cout << "ERASE :::: " <<endl; // mozna miec dwa iteratory
        cout << *itr << endl;
      cout << *tmp << endl;
      for(itr;tmp.good();++itr,++tmp)
      {
         // cout << *itr << " " << *tmp << endl;

          *itr = *tmp;
         
        // cout << *itr << endl;
          
      }


  }


  void erase(VectoredListIterator& itr1, VectoredListIterator&itr2) // index o jeden wiekszy bo liczymy od 0
  { 
     // int starting_position = itr2.index + 1;
     // VectoredListIterator tmp(*this,starting_position);
    //  cout << *tmp << "START " << endl;
      ++itr2; // za drugim iteratorem
      for(itr1;itr2.good();++itr2,++itr1)
      {
          *itr1 = *itr2;
      }
     


  }



};

void VectoredList::push_back(const std::string& value)
{

   if(head == 0) // nic nie ma
   {
       Bucket* new_node = Bucket::getBucket(value);
       size++;
       head = new_node;
       tail = new_node;
       head->previous = 0;
       tail->next = 0;
       capacity+=N;
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
       capacity+=N;
       //return true;

    }
    
    
   // return false;

}

/////////////////////////////////////////////////


void VectoredList::push_back(std::string &&value)
{

   if(head == 0) // nic nie ma
   {
       Bucket* new_node = Bucket::getBucket(value);
       size++;
       head = new_node;
       tail = new_node;
       head->previous = 0;
       tail->next = 0;
       capacity+=N;
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
       capacity+=N;
       //return true;

    }
    
    
   // return false;

}




VectoredList::VectoredList(VectoredList &&v)
{
    this->head = v.head; // move
    this->tail = v.tail;
    this->capacity = v.capacity;
    this->size = v.size;

                        // clear

    v.head = nullptr;
    v.tail = nullptr;
    v.capacity = 0;
    v.size = 0;
}

void VectoredList::assign(vector<string> v) // here create copy
{

   // cout << "size of vector = " << v.size() << endl;

    if(head)
    {
        this->free_me();
    }
    
    for(int i = 0;i<v.size();++i)
    {
        string&& rref = move(v[i]);
        this->push_back(rref);
        //cout << rref << " in assing" << endl;
    }
}

VectoredList VectoredList::operator+(const VectoredList& rhs)const
{
    VectoredList new_container;

    const VectoredList& ref_to_cur = *this;

    Bucket* tmp_first = head;
    Bucket* tmp_second = rhs.head;


    for(int i=0;i<ref_to_cur.VectoredListSize();++i,tmp_first = tmp_first->next)
    {   
        for(int j=0;j<tmp_first->size_of_bucket;++j)
        {
            new_container.push_back(ref_to_cur[j]);
            //cout << ref_to_cur[j] << endl;
        }
    }

    

    for(int i=0;i<rhs.VectoredListSize();++i,tmp_second = tmp_second->next)
    {
        for(int j=0;j<tmp_second->size_of_bucket;++j)
        {
            new_container.push_back(rhs[j]);
            //cout << rhs[j] << endl;
        }
    }

    
    return new_container;  // it will be moved here

}

VectoredList& VectoredList::operator=(VectoredList &&v)
{

    if(&v!=this) // security
    {   
        this->free_me();

        this->head = v.head;   // move
        this->tail = v.tail;
        this->size = v.size;
        this->capacity = v.capacity;

                                //clear

        v.head = nullptr;
        v.tail = nullptr;
        v.size = 0;
        v.capacity = 0;
        

    }
    
    
    return *this;

}






int main(int argc, char *argv[])
{   
    
    

    cout << endl << "---------- 1 ----------" << endl;
    VectoredList v;
    string       t11("TEST 1.1");
    string       t12("TEST 1.2");
    v.push_back(t11);
    v.push_back(t12);

    VectoredList v1(move(v));     // move(v) <==> lvalue -> xvalue

    for (int i = 0; i < v1.how_many_elements_allocated(); ++i)
    {
         cout << v1[i] << endl;
     
    }


    cout << endl << "---------- 2 ----------" << endl;
    VectoredList v2;
    string       t21("TEST 2.1");
    string       t22("TEST 2.2");
    v2.push_back(t21);
    v2.push_back(t22);

    v1 = move(v2);

    for (int i = 0; i < v1.how_many_elements_allocated(); ++i) //v1.VectoredListSize()
    {
        cout << v1[i] << endl;
    }

    cout << endl << "---------- 3 ----------" << endl;
    VectoredList v3, v4;
    string       t31("TEST 3.1");
    v3.push_back(t31);

    v4 = v1 + v3;


    for (int i = 0; i < v4.how_many_elements_allocated(); ++i)
    {
        cout << v4[i] << endl;
    }

    cout << endl << "---------- 4 ----------" << endl;
    vector<string> V{"TEST 4.1", "TEST 4.2"};

   
    v4.assign(V);

//
   // cout << V[0] << " " << V[1] << endl;
//
//  cout << " How many el : " << v4.how_many_elements_allocated() << "size: " << v4.size << " " << v4.capacity << endl;

    for (int i = 0; i < v4.how_many_elements_allocated(); ++i)
    {
       cout << v4[i] << endl;
   }



   
    return 0;
}
