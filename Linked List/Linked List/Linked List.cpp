
#include <iostream>
#include <string>
using namespace std;
//List- U
//ELEMENT-Z

template <typename U> // make the class template, don't use the data type

class List
{

public:

    List();
    ~List();

    //methods
    void reliaf();//delete first node
    void clear();//delete all nodes (work on reliaf)
    void push_back(U data);//add a node to the and of the list
    int getsize() { return size; }//how many nodes in the list
    U& operator[](const int index);//data from node with specific index (choose the node)
    void push_front(U data);//add a node to the beggining of the list
    void insert(U value, int index);//add a node to the specific index (choose the node)
    void deleteMDL(int index);//delete a node with specific index (choose the node)
    void deletelast();//delete the last node

private:

    template <typename Z>//ELEMENT (node) don't use the data type
    class ELEMENT
    {
    public:
        //make a node
        ELEMENT* pNext;
        Z data;

        ELEMENT(Z data = Z(), ELEMENT* pNext = nullptr)//for getting information
        {
            this->data = data;
            this->pNext = pNext;
        }
    };
    int size;//how many elements in the list
    ELEMENT <U>* hlava;//allocate space in heap for each element
};





template <typename Z>
List<Z> ::List()
{
    size = 0;
    hlava = nullptr;//this is the first (0) node
}

template <typename Z>
List<Z>::~List()//destruktor
{
    cout << "use clear (after main)" << endl;
    clear();//after exiting from "main" will delete all nodes
}

template <typename Z>
void List <Z>::reliaf()//delete the first (0) node
{
    ELEMENT <Z>* adrs = hlava;// the first node is "hlava"

    hlava = hlava->pNext;
    delete adrs;
    size--;//now one element less
}




template <typename Z>
void List <Z> ::push_back(Z data)//add a node to the and of the list
{
    if (hlava == nullptr) //if we don't have the first (0) node
    {
        hlava = new ELEMENT<Z>(data); //if we don't have the first node- create it- and sent data to new first node
    }
    else// if we already have the first (0) node
    {
        ELEMENT<Z>* current = this->hlava;

        while (current->pNext != nullptr)//check all nodes
        {
            current = current->pNext;//until find the node which point on NULL. (the last node in the list should point on NULL)
        }
        current->pNext = new ELEMENT <Z>(data);//make new element
    }

    size++;//now we have +1 node
}

template <typename Z>
void List<Z>::clear()
{
    while (size)// cycle will work until size will not get 0
    {
        reliaf();//use the Relief cycle
    }

}


template <typename Z>
Z& List<Z> :: operator[] (const int index)
{
    int counter = 0;
    ELEMENT <Z>* current = this->hlava;

    while (current != nullptr)//start with first node
    {
        if (counter == index)
        {
            return current->data;
        }
        current = current->pNext; //ask for adress of the next node
        counter++;

    }

}


template <typename Z>
void List<Z>::push_front(Z data)
{
    hlava = new ELEMENT <Z>(data, hlava);//creates a new node and indicates that it is the first
    size++;// +1 node
}

template <typename Z>
void List<Z>::insert(Z data, int index)
{
    if (index == 0)//if we are trying to put a node to the index 0, will use push_fornt
    {
        push_front(data);
    }

    else//if not to the first place
    {

        ELEMENT<Z>* previous = this->hlava;//find the previous node

        for (int x = 0; x < index - 1; x++)
        {
            previous = previous->pNext;
        }

        ELEMENT<Z>* newELEMENT = new ELEMENT<Z>(data, previous->pNext);//creates a new node and give all data to it
        previous->pNext = newELEMENT;//give adress (index) to the new node
        size++;

    }

}

       
        template <typename Z>
        void List<Z>::deleteMDL(int index)
        {
            if (index == 0)//if it is the first (0) node - use "reliaf"
            {
                reliaf();
            }

            else//if it is not the first node
            {
                ELEMENT<Z>* previous = this->hlava;//find the previous node
                for (int x = 0; x < index - 1; x++)
                {
                    previous = previous->pNext;
                }

                ELEMENT<Z>* Delete = previous->pNext;//Delete- use to save adress form previous node
                previous->pNext = Delete->pNext;
                delete Delete;//rid the variable
                size--;// now -1 node
            }
        }


        template <typename Z>
        void List<Z>::deletelast()
        {

            deleteMDL(size - 1);//delete the last element with the last index. (index= size-1)


        }



        int main()
        {

            List <int> lst;


            cout << "use push_back" << endl;

            lst.push_back(57);//add 5 nodes to the end
            lst.push_back(56);
            lst.push_back(54);
            lst.push_back(52);
            lst.push_back(55);

            for (int x = 0; x < lst.getsize();x++) {
                cout << lst[x] << endl;
            }
            cout << "nodes in list: " << lst.getsize() << endl << endl;


            cout << "use push_front" << endl;
            lst.push_front(2);//add 1 node to the beginning



            for (int x = 0; x < lst.getsize();x++) {
                cout << lst[x] << endl;
            }
            cout << "nodes in list: " << lst.getsize() << endl << endl;


            cout << "use insert" << endl;

            lst.insert(666, 5);//add 1 node to the 5. index


            for (int x = 0; x < lst.getsize();x++) {
                cout << lst[x] << endl;
            }
            cout << "nodes in list: " << lst.getsize() << endl << endl;


            cout << "use reliaf" << endl;
            lst.reliaf();//delete the first node


            for (int x = 0; x < lst.getsize();x++) {
                cout << lst[x] << endl;
            }
            cout << "nodes in list: " << lst.getsize() << endl << endl;


            cout << "use deletelast" << endl;

            lst.deletelast();//delete the last node


            for (int x = 0; x < lst.getsize();x++) {
                cout << lst[x] << endl;
            }
            cout << "nodes in list: " << lst.getsize() << endl << endl;


            cout << "use deleteMDL" << endl;

            lst.deleteMDL(2);//delete the node with 2. index

            for (int x = 0; x < lst.getsize();x++) {
                cout << lst[x] << endl;
            }
            cout << "nodes in list: " << lst.getsize() << endl << endl;


            cout << "use clear" << endl;
            lst.clear();//delete all nodes

            cout << "nodes in list: " << lst.getsize() << endl << endl;




            return 0;
        }
