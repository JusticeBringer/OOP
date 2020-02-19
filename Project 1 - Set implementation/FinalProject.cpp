#include <iostream>
#include "SetProject.h"

using namespace std;

Set::Set (){    //constructor fara parametri
    size = 0;
    array = new int[0];
}

Set::Set (int *vector, unsigned nrElem){    //constructor cu parametri
    if(nrElem == 0)
        return;
    size = 0;
    array = new int[nrElem];    //atribuim dimensiunea

    while(nrElem != 0){
        if(cautare(vector[size]) == -1){
            size += 1;
            array[size - 1] = vector[size - 1]; //adaugam elementele
            cout << "Element adaugat \n";  
            }
        nrElem --;
    }

    //acum ordonam crescator
    sort();
}

Set::Set (const Set &ob){   //constructorul de copiere
    size = ob.size;
    array = new int[ob.size];

    for(int i = 0; i < size; i++)
        array[i] = ob.array[i];
}

Set::~Set (){   //deconstructorul
    delete [] array;

    if(size == 1)
        cout << "Element sters \n";
    else
        cout << "Elemente sterse \n";
    size = 0;
}

int Set::cautare (int value){   //algoritmul de
                                //cautare binara
    if(size == 0)
        return -1;

    int left = 0;
    int right = size - 1;

    while(left <= right){
        int middle = left + (right - 1) / 2;

        if(array[middle] == value)
            return middle;
        if(array[middle] < value)
            left = middle + 1;
        else
            right = middle - 1;
    }   
    return -1;
}

void Set::insert (int value){   //insertia unui element
    if(cautare(value) == -1){     
        size = size + 1;
        array[size - 1] = value;
        cout << "Element adaugat \n";    
    }
    sort( );
}

void Set::sort ( ){     //metoda de sortare 
    for(unsigned i = 0; i < size; i++)
        for(unsigned j = i + 1; j < size ; j++)
            if(array[i] > array[j])
                swap(&array[i], &array[j]);
}

void Set::afisare (){   //afisarea elementelor vectorului
    if(size == 0)
        return;
    for(int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

void Set::stergere (int value){ //stergerea unui element
    if(size == 0)
        return;
    if(cautare(value) == -1)
        return;
    for(int i = cautare(value); i < size; i++)
        array[i] = array[i+1];
    size--;
}

int Set::sumElements(){ //suma elementelor din vector
    if(size == 0)
        return 0;
    int sum = 0;
    for(int i = 0; i < size; i++)
        sum += array[i];
    return sum;
}

int Set::nrElem (){ //numarul elementelor din vector
    return size;
}

int* Set::nrPare (unsigned *sizePar){   //numarul de elemente pare
    if(size == 0)                       //trimis ca parametru si
        return 0;                       //returnarea unui vector
    int numerePare = 0;                 //de elemente pare
    for(int i = 0; i < size; i++)
        if(array[i] % 2 == 0)
            numerePare += 1;
    if(numerePare == 0)
        return 0;
    int* nrPar = new int[numerePare];
    for(int i = 0; i < size; i++)
        if(array[i] % 2 == 0){
            nrPar[(*sizePar)] = array[i];
            (*sizePar) += 1;
        }
    return nrPar;
}

int* Set::nrImpare (unsigned *sizeImpar){   //numarul de elemente impare
    if(size == 0)                           //trimis ca parametru si
        return 0;                           //returnarea unui vector
    int numereImpare = 0;                   //de elemente impare
    for(int i = 0; i < size; i++)
        if(array[i] % 2 == 0)
            numereImpare += 1;
    if(numereImpare == 0)
        return 0;
    int* nrImpar = new int[numereImpare];
    for(int i = 0; i < size; i++)
        if(array[i] % 2 != 0){
            nrImpar[(*sizeImpar)] = array[i];
            (*sizeImpar) += 1;
        }
    return nrImpar;
}

void Set::swap (int *a, int*b){ //interschimbarea
    int temp = *a;              //a doua elemente
    *a = *b; 
    *b = temp;
}

std::ostream & operator << (std::ostream &out, const Set &c)
{                       //supraincarcarea operatorului <<
    if(c.size == 0)
        return out;
    for(int i = 0; i < c.size; i++)
        out << c.array[i] << " ";
    return out;
}
 
std::istream & operator >> (std::istream &input, Set &c)
{                   //supraincarcarea operatorului >>
    cout << "Introdu numarul de elemente: ";
    int nrElem, x;
    cin >> nrElem;

    for(unsigned i = 0; i < nrElem; i ++){
        cin >> x;
        c.insert(x);
    }   
    return input;
}

Set Set::operator = (Set c){
    if(size == 0)          //supraincarcarea operatorului =
        exit(0);
    for(int i = 0; i < c.size; i++)
        insert(c.array[i]);
    return *this;
}   

int& Set::operator[] (int i){
    if(i < 0){                  //supraincarcarea operatorului []
        cout << "i este negativ";
        return array[0];
    }
    if(i > size){
        cout << "i este peste size";
        return array[0];
    }
    return array[i];
}

Set Set::operator+(const Set &ob){
    Set temp;               //supraincarcarea operatorului +
    temp.size = size + ob.size;
    
    int i;
    for(i = 0; i < this->size; i++)
        temp.array[i + 1] = this->array[i - 1];

    int sizeArray = i + 1;
    for(int j = 0; j < ob.size; j++)
        temp.array[i + j] = ob.array[j];

    for(int i = 0; i < temp.size; i ++)
        for(int j = i + 1; j < temp.size; j++)
            if(temp.array[i] == temp.array[j])
                {
                    for(int k = j; k < temp.size; k ++)
                        temp.array[k] = temp.array[k + 1];
                    temp.size --;
                }    
    return temp;
}

bool Set::operator < (const Set &ob){   //supraincarcarea operatorului <
    if(size < ob.size || size == ob.size)
       return true;
    return false;
}

bool Set::operator > (const Set &ob){   //supraincarcarea operatorului >
    if(size > ob.size || size == ob.size)
        return true;
    return false;
}

int* Set::operator * (int value){   //supraincarcarea operatorului *
    if (size == 0)
        return 0;
    for(int i = 0; i < size; i ++)
        array[i] *= value;
    return array;
} 

int main()  
{                               //mici teste pe functii
    int *arr = new int[7];
    for(int i = 0; i < 7; i++)
        arr[i] = i;
    Set build(arr, 7);
    build.afisare();

    int *arr22 = new int[7];
    for(int i = 5; i < 13; i++)
        arr22[i - 5] = i;
    Set bu(arr22, 7);
    bu.afisare();

    Set ceva;
    ceva = build + bu;
    
    int* cev = build * 2;    

    return 0;
}