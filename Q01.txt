#include<bits/stdc++.h>
using namespace std;
//practical ques1;

class Set 
{
    int *arr;
    int size;
public:
    Set()
    {
        size= 10;
        arr = new int[size];
    } 
    void input();
    void display();
    void cardinality();
    void unique();
    bool isMember();
    void powerSet();
};

void Set :: input() 
{
    cout << "enter the size of array: ";
    cin >> size;
    arr = new int[size];
    cout << "enter the elements: ";
    for(int i=0; i<size; i++) 
    {
        cin >> arr[i];
    }
}

void Set :: display() 
{
    cout << "The set is {";
    for(int i = 0; i<size; i++) 
    {
        cout << arr[i] << ",";
    }
    cout << "}" << endl;
}

void Set :: cardinality() 
{
    cout << "The cardinality of the set is: " << size << endl;
}

void Set :: unique() 
{
    int i, j, l;
    for(i=0; i<size; ++i)
    {
        for(j=i+1; j<size;)
        {
            if(arr[i] == arr[j])
            {
                for(l=0; l<size-1; ++l) 
                {
                    arr[l] = arr[l+1];
                    --size;
                }
            }
            else 
            {
                ++j;
            }
        }
    }
}

void Set :: powerSet()
{
    int count, temp;
    count = pow(2, size);
    cout << "{ {},";
    for(int i=1; i<count; i++) 
    {
        temp = i;
        cout << "{";
        for(int j=0; j<size; j++) 
        {
            if(temp & 1)
            {
                cout << arr[j] << ",";
                temp = temp >> 1;
            }
            cout << "\b}";
        }
        cout << "}";
    }
}

bool Set :: isMember() 
{
    int e;
    cout << "Enter the element to be searched: ";
    cin >> e;

    for(int i=0; i<size; i++) 
    {
        if(e == arr[i]) 
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
}

int main() 
{
    Set a;
    int ch;
    a.input();
    a.display();
    a.unique();
    a.cardinality();

    cout << "enter your choice" << endl;
    cout << "1.Power set" << endl << "2.Is Member" << endl << "3. Exit" << endl;
    cin >> ch;
    switch (ch)
    {
    case 1: a.powerSet();
            break;
    case 2: if(a.isMember())
            {
                cout << "given element belongs to the set" << endl;
            }
            else
            {
                cout << "Give element does not belong to the set" << endl;
            } 
            break;
    case 3:
        exit (0);
    
    default: 
        cout << "wrong choice!";
        break;
    }



    return 0;
}