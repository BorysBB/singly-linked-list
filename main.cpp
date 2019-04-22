#include <iostream>
using namespace std;

template<typename key, typename info>
class Sequence
{
 struct node
 {
  key id;
  info value;
  node*next;
 };
 node* head = NULL;

public:
    Sequence();         //constructor
    Sequence(const Sequence &source); //copy constructor
    ~Sequence(); //destructor
    void add_node(key Key, info val);   //add node at the end
    void del_node(key delId);   //delete node by key
    void print_sequence();
 Sequence& operator=(const Sequence & source);
    Sequence& operator+(const Sequence & n);
    void del_by_value(info del_value);
    void del_sequence(); //delete whole sequence
    void add_before(key before_id, key _id, info _value);   // add node at specified position
    int seq_length()const;
    key get_key(int start_position, int sequence_length)const;
    info get_info(int start_position, int sequence_length)const;
};
template<typename key, typename info>
    int split(const Sequence<key, info> &source, int start, Sequence<key, info> &result1, int step1, Sequence<key, info> &result2, int step2);

int main()
{
 Sequence<int, char>S1;
 S1.add_node(1, 'a');
 S1.add_node(2, 'b');
 S1.add_node(3, 'c');
 S1.add_node(4, 'd');
 S1.add_node(5, 'e');
 S1.add_node(6, 'f');
 S1.add_node(7, 'g');
 S1.add_node(8, 'h');
 S1.add_node(9, 'i');
 Sequence<int, char>S2;
 Sequence<int, char>S3;
    split(S1, 2, S2, 5, S3,3);
    cout<<"________________________"<<endl;
    cout<<"Split function result: "<<endl;
    cout<<"S2"<<endl;
    S2.print_sequence();
    cout<<"----------"<<endl;
    cout<<"S3"<<endl;
    S3.print_sequence();
    cout<<"________________________"<<endl;
    cout<<"---------COPY CONSTRUCTOR TEST-----------"<<endl;
    Sequence<int, float>S4;
    S4.add_node(1,1.1);
    S4.add_node(2, 2.2);
    cout<<"initializing with non-empty sequence"<<endl;
    Sequence<int, float>S5(S4);
    cout<<"New sequence: "<<endl;
    S5.print_sequence();
    cout<<"initializing with empty sequence"<<endl;
    Sequence<int, float>S6;
    Sequence<int, float>S7(S6);
    S7.print_sequence();
    cout<<endl;
    cout<<"________________________"<<endl;
    cout<<"---------ADD METHODS TESTS-----------"<<endl;
    cout<<"push_back method:"<<endl;
    Sequence<float, char>S8;
    S8.add_node(3.3, 'a');
    S8.add_node(4.3, 'b');
    S8.print_sequence();
    cout<<"adding element with the same key"<<endl;
    S8.add_node(3.3,'c');
    S8.print_sequence();
    cout<<"push before given node method:"<<endl;
    S8.add_before(3.3, 5.7, 'd');
    S8.print_sequence();
    cout<<"adding element with the same key"<<endl;
    S8.add_before(3.3, 4.3, 'e');
    S8.print_sequence();
    cout<<"adding element before element which doesn t exist"<<endl;
    S8.add_before(10,5.1,'e');
    S8.print_sequence();
    cout<<"________________________"<<endl;
    cout<<"---------REMOVE METHODS TESTS-----------"<<endl;
    cout<<"Del by key method:"<<endl;
    S8.del_node(5.7);
    S8.print_sequence();
    S8.add_node(11,'a');
    S8.print_sequence();
    S8.del_by_value('a');
    cout<<"after del by value"<<endl;
    S8.print_sequence();
    cout<<"removing value which is not on the list"<<endl;
    S8.del_by_value('a');
    cout<<"Sequence after removing element which is not in the list"<<endl;
    S8.print_sequence();
    S8.add_node(15,'g');
    S8.add_node(16,'b');
    S8.add_before(16,17,'z');
    cout<<"Sequence before removing all elements"<<endl;
    S8.print_sequence();
    S8.del_sequence();
    cout<<"Sequence after del_sequence function"<<endl;
    S8.print_sequence();
    cout<<"removing empty sequence"<<endl;
    S8.del_sequence();
    cout<<endl;
    cout<<"________________________"<<endl;
    cout<<"---------OPERATORS TESTS-----------"<<endl;
    cout<<"overloaded + operator"<<endl;
    Sequence<int, float>S9;
    Sequence<int, float>S10;
    cout<<endl;
    cout<<"adding empty sequences"<<endl;
    S9+S10;
    S9.print_sequence();
    cout<<endl;
    cout<<"adding empty to nonempty"<<endl;
    S9.add_node(1,1);
    S9+S10;
    S9.print_sequence();
    cout<<"adding nonempty to empty"<<endl;
    Sequence <int, float>S23;
    Sequence<int, float>S22;
    S22.add_node(1,1);
    S22.add_node(2,2);
    S22.add_node(3,3);
    S23+S22;
    S23.print_sequence();
    cout<<"Adding two nonempty sequences"<<endl;  //same key
    Sequence <char, char>S12;
    S12.add_node('a','a');
    S12.add_node('b','b');
    S12.add_node('c','c');
    Sequence <char, char>S13;
    S13.add_node('a','a');
    S13.add_node('d','d');
    S13.add_node('e','e');
    S12+S13;
    S12.print_sequence();
    cout<<"________________________"<<endl;
    cout<<"overloaded = operator"<<endl;
    cout<<endl;
    Sequence <double, double>S14;
    Sequence <double, double>S15;
    cout<<"assigning empty to empty"<<endl;
    S14=S15;
    S14.print_sequence();
    cout<<endl;
    cout<<"assigning empty to nonempty "<<endl;
    S14.add_node(1,1);
    S14.add_node(2,2);
    S14.print_sequence();
    S14=S15;
    cout<<"after assigning"<<endl;
    S14.print_sequence();

    cout<<"assigning nonempty to empty "<<endl;
    Sequence <double, double>S16;
    Sequence <double, double>S17;
    S17.add_node(1,1);
    S17.add_node(100,100);
    S17.add_node(-1,-1);
    S16=S17;
    S16.print_sequence();
    cout<<"----------------------------------"<<endl;
    cout<<"Split function tests:"<<endl;
    Sequence<int, int>S18;
    S18.add_node(1,1);
    S18.add_node(2,2);
    S18.add_node(3,3);
    S18.add_node(4,4);
    S18.add_node(5,5);
    S18.add_node(6,6);
    S18.add_node(7,7);
    S18.add_node(8,8);
    S18.add_node(9,9);
    S18.add_node(10,10);
    Sequence<int, int>S19;
    Sequence<int, int>S20;
    cout<<endl;
    cout<<"No such start position:"<<endl;
    split(S18, 15,S19, 3 , S20, 4);
    S19.print_sequence();
    S20.print_sequence();
    cout<<endl;
    cout<<"step one greater than length"<<endl;
    split(S18, 3,S19, 30 , S20, 4);
    S19.print_sequence();
    S20.print_sequence();
    cout<<endl;
    cout<<"Source sequence after function split - should be without any change"<<endl;
    S18.print_sequence();

 return 0;
}

template<typename key, typename info>
    int split(const Sequence<key, info> &source, int start, Sequence<key, info> &result1, int step1, Sequence<key, info> &result2, int step2)
    {
        int length=0;
        int limit=0;
        int position=start;
        key ID;
        info VALUE;
        key _ID;
        info _VALUE;
        int _1step_counter = 0;
        int _2step_counter = 0;
        limit=source.seq_length();
        if(limit<=0)
        {
            cout<<"Source sequence is empty"<<endl;
            return 0;
        }
        while(position < limit)
        {
        _1step_counter = 0;
        _2step_counter = 0;
            while(_1step_counter < step1 && position<limit )
            {
            ID=source.get_key(position, limit);
            VALUE=source.get_info(position, limit);
            result1.add_node(ID, VALUE);
            length++;
            _1step_counter++;
            position++;
            }
            if(position == limit)
            {
                break;
            }

            while(_2step_counter < step2 && position<limit)
            {
            _ID=source.get_key(position, limit);
            _VALUE=source.get_info(position, limit);
            result2.add_node(_ID, _VALUE);
            length++;
            _2step_counter++;
            position++;
            }
            if(position == limit)
            {
                break;
            }
        }

        cout<<"Total length of two sequences: "<<length<<endl;
        return length;

    }
template<typename key, typename info>
    key Sequence<key, info>::get_key(int start_position, int sequence_length)const
    {
        node* curr=head;
        int start_counter = 0;
        while(curr!=NULL && start_counter < start_position && start_counter < sequence_length)
        {
            start_counter++;
            curr=curr->next;
        }
        if(start_counter==start_position)
        {
            return curr->id;
        }
    }
template<typename key, typename info>
    info Sequence<key, info>::get_info(int start_position, int sequence_length)const
    {
        node* curr=head;
        int start_counter = 0;
        while(curr!=NULL && start_counter < start_position && start_counter < sequence_length)
        {
            start_counter++;
            curr=curr->next;
        }
        if(start_counter==start_position)
        {
            return curr->value;
        }
    }


template<typename key, typename info>
 Sequence<key,info>::Sequence()  //constructor
 {
  node* head = NULL;
  node* curr = NULL;
  node* temp = NULL;
 }
template<typename key, typename info>
    Sequence<key, info>::Sequence(const Sequence &source)   //copy constructor
 {
     if(source.head!=NULL)
        {
     head=new node;
        node *curr_one=head;
        node *curr_source=source.head;
            while(curr_source!=NULL)
            {
                curr_one->id=curr_source->id;
                curr_one->value=curr_source->value;
                if(curr_source->next!=NULL)
                {
                    curr_one->next=new node;
                    curr_one=curr_one->next;
                    curr_source=curr_source->next;
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            cout<<"object is empty"<<endl;
        }
 }

template<typename key, typename info>
  Sequence<key, info>::~Sequence()
 {
     head=NULL;
     node* next=NULL;

 }
template<typename key, typename info>
 void Sequence<key,info>::add_node(key Key, info val) //adding element to sequence
 {
  int sum = 0;
  node* curr = head;
  while (curr != NULL)
  {
   if (curr->id == Key)
   {
    sum++;
    break;
   }
   curr = curr->next;
  }
  if (sum != 0)
  {
   cout << "Can NOT add this element. It is already existing" << endl;
  }
  else
  {
   node* n = new node;
   n->next = NULL;
   n->id = Key;
   n->value = val;
   if (head != NULL)
   {
    curr = head;
    while (curr->next != NULL)
    {
     curr = curr->next;
    }
    curr->next = n;
   }
   else
   {
    head = n;
   }
  }
 }

template<typename key, typename info>
    void Sequence<key, info>::del_node(key delId)       //removing element fro sequence
 {
  node* delPtr = NULL;
  node* temp = head;
  node* curr = head;
  while (curr != NULL)
  {
   node* delPtr = NULL;
   if (curr->id == delId)
   {
    if (curr == head)
    {
     delPtr = curr;
     head = head->next;
     curr = head;
     temp = head;
     delete delPtr;
     break;    //jako ze mamy unikalne id przestaje szukac dalej po usunieciu
    }
    else if (curr->next == NULL)
    {
     delPtr = curr;
     temp->next = NULL;
     curr = NULL;
     delete delPtr;
     break;
    }
    else
    {
     node *delPtr = curr;
     curr = curr->next;
     temp->next = curr;
     curr = temp;
     delete delPtr;
     break; //jako ze mamy unikalne id przestaje szukac dalej po usunieciu
    }
   }
   if (curr == head && curr->id == delId)
   {
    curr = head;
    temp = head;
   }
   else
   {
    temp = curr;
    curr = curr->next;
   }
  }
 }
template<typename key, typename info>
    void Sequence<key,info>:: print_sequence()       //Showing all elements of a sequence
 {
  cout << "Sequence:" << endl;
  node* curr = head;
  while (curr!= NULL)
  {
      cout<<"element: "<<endl;
   cout << "Id: " << curr->id << endl;
   cout << "Value: " << curr->value << endl;
   cout << "" << endl;
   curr = curr->next;
  }
 }

template<typename key, typename info>
    Sequence<key, info> & Sequence<key,info>:: operator=(const Sequence<key,info> & source)  //overloaded = operator
 {
    node* s_curr=source.head;
    node* curr=NULL;
    if(this==&source)
    {
        cout<<"self-copy"<<endl;
        return *this;
    }
    del_sequence();
    while(s_curr!=NULL)
    {
        add_node(s_curr->id, s_curr->value);
        s_curr=s_curr->next;
    }
    return *this;
 }
template<typename key, typename info>
 Sequence<key,info> &Sequence<key,info>::operator+(const Sequence & n)
    {
        node*curr=head;
        node*temp=head;
        node *n_curr=n.head;
        node *n_temp=n.head;
        if(head==NULL&&n.head!=NULL)
        {
            node *n_curr=n.head;
            head=new node;
            head->id=n_curr->id;
            head->value=n_curr->value;
            head->next=NULL;
            n_curr=n_curr->next;
            curr=head;
            while(n_curr!=NULL)
            {
                add_node(n_curr->id, n_curr->value);

                n_curr=n_curr->next;
            }
//            head=new node;
//            curr=head;
//
//            while(n_curr!=NULL)
//            {
//                curr->id=n_curr->id;
//                curr->value=n_curr->value;
//                if(n_curr->next!=NULL)
//                {
//                curr->next=new node;
//                }
//                curr=curr->next;
//                n_curr=n_curr->next;
//            }
            return *this;
        }
        else if(n.head==NULL && head==NULL)
        {
            return *this;
        }

        else
        {
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        while(n_curr!=NULL)
        {
            int counter=0;
            temp=head;
            while(temp!=NULL)
            {
                if(temp->id==n_curr->id)
                {
                    counter++;
                }
                temp=temp->next;
            }
            if(counter==0)
            {
                curr->next=new node;
                curr=curr->next;
                curr->next=NULL;
                curr->id=n_curr->id;
                curr->value=n_curr->value;
            }
            n_curr=n_curr->next;
        }
        return *this;
        }
    }

template<typename key, typename info>
void Sequence<key,info>:: del_by_value(info del_value)
{
    if(head==NULL)
    {
        cout<<"Sequence is empty"<<endl;
        return;
    }
    node* curr=head;
    node* temp=head;
    node* delPtr=NULL;
    while(curr!=NULL)
    {
        if(curr->value==del_value && curr==head && curr->next!=NULL)
        {
            while(curr->value==del_value && curr==head && curr->next!=NULL)
            {
            delPtr=head;
            head=head->next;
            temp=head;
            curr=head;
            delete delPtr;
            }
        }
        if(curr==NULL)
        {
            break;
        }
        else if(curr->value==del_value && curr!=head && curr->next!=NULL)
        {
            while(curr->value==del_value && curr!=head && curr->next!=NULL)
            {
            delPtr=curr;
            curr=curr->next;
            temp->next=curr;
            delete delPtr;
            }
        }
        if(curr==NULL)
        {
            return;
        }
        else if(curr->value==del_value && curr==head && curr->next==NULL)
        {
            delPtr=head;
            head=NULL;
            curr=NULL;
            temp=NULL;
            delete delPtr;
            break;
            return;
        }
        if(curr==NULL)
        {
            return;
        }
        else if(curr->value==del_value && curr!=head && curr->next==NULL)
        {
            delPtr=curr;
            temp->next=NULL;
            curr=NULL;
            delete delPtr;
        }
        if(curr==NULL)
        {
            break;
        }
        temp=curr;
        curr=curr->next;
    }

}

template<typename key, typename info>
void Sequence<key,info>::del_sequence()
{
    if(head==NULL)
    {
        return;
    }
    node* delPtr=NULL;
    while(head->next!=NULL)
    {
        delPtr=head;
        head=head->next;
        delete delPtr;
    }
    delPtr=head;
    head=NULL;
    delete delPtr;
}
template<typename key, typename info>
void Sequence<key,info>::add_before(key before_id, key _id, info _value)
{
    if (head==NULL)
    {
        cout<<"Sequence is empty cannot add before given key"<<endl;
        return;
    }
    int counter=0;
    node* curr=head;
    node* temp=NULL;
    while(curr!=NULL)
    {
        if(curr->id==_id)
        {
            counter++;
        }
        curr=curr->next;
    }
    if(counter != 0)
    {
        cout<<"Element with given key already exists"<<endl;
        return;
    }
    curr=head;
    while(curr!=NULL)
    {
        if(curr->id==before_id && curr==head)
        {
        head=new node;
        head->next=curr;
        head->id=_id;
        head->value=_value;
        }
        else if(curr->id==before_id && curr!=head)
        {
            node* n = new node;
            temp->next=n;
            n->next=curr;
            n->id=_id;
            n->value=_value;
        }
        temp=curr;
        curr=curr->next;
    }
}

template<typename key, typename info>
int Sequence<key,info>::seq_length()const
{
    node* curr=head;
    int counter=0;
    while(curr!=NULL)
    {
        counter++;
        curr=curr->next;
    }
    return counter;
}
