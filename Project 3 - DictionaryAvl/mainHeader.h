#pragma once
#include <iostream>
#include <ostream>
#include <stack>
#include "node.h"

using namespace std;

template <class K, class V>
class Dictionary {
    private:
        Node <K,V>* root;
        unsigned size;

        Node <K, V>* insert (Node <K, V>* cr, K ke, V val);
            //metoda de adaugare
        Node <K, V>* remove (Node <K, V>* cr, V val);
            //metoda de stergere
        Node <K, V>* rightRotate (Node <K, V>* cr);
            //rotatie spre dreapta
        Node <K, V>* leftRotate  (Node <K, V>* cr); 
            //rotatie spre stanga
        Node <K, V>* minValFromTree (Node <K, V>* cr);
            //obtinere valoare minima din Dictionar        
        Node <K, V>* deleteNode (Node <K, V>* cr, K ke);
            //stergere nod
        void preOrderForKey (Node <K, V>* cr, V &val, K ke);
            //functie pentru srchKey
        void deleteDictionary (Node <K, V>* cr);
            //functie pentru deleteAllElements
    public:

        Dictionary ();
            //constructor fara parametri
        Dictionary (const Dictionary&); 
            //constructor de copiere
        ~Dictionary ();
            //destructor
        unsigned getSize();
            //obtine nrElemente din Dictionar
        void inOrder (Node <K, V>* cr);
            //parcurgere inOrdine
        void preOrder (Node <K, V>* cr);
            //parcurgere preOrdine
        void add (K, V);    
            //adaugare element
        void show();        
            //vedere valori din Dictionar
        void deleteAfKey (K);   
            //stergere dupa cheie
        void deleteAllElements (); 
            //stergere Dictionar
        bool srchKey(K ke, V &aux); 
            //cautare dupa cheie
        bool isEmpty();     
            //verificare Dictionar gol
        

        V operator [] (const K index) ;
            //operatorul de indexare
        Dictionary <K, V> &operator = (Dictionary<K, V> dctnary);
            //operatorul de atribuire
};

template <class K, class V>
Dictionary <K, V>::Dictionary (){
    root = nullptr;
    size = 0;
}

template <class K, class V>
Dictionary <K, V>::Dictionary (const Dictionary &ob){
    this->root = nullptr;
    this->size = 0;

    std::stack <Node <K, V>* > stiva; 
    stiva.push(ob.root);
    while(!stiva.empty()){
        Node <K, V>* cr = stiva.top();
        stiva.pop();

        if(cr->left != nullptr)
            stiva.push(cr->left);
    
        if(cr->right != nullptr)
            stiva.push(cr->right);

        add(cr->key, cr->value);
    }
}

template <class K, class V>
Dictionary <K, V>::~Dictionary(){
    deleteAllElements();
}

template <class K, class V>
Node <K, V>* Dictionary<K, V>::insert(Node <K, V>* cr, K ke, V val){
    //nu avem niciun element
    if(cr == nullptr){
        cr  = new Node <K, V> (ke, val);
        return cr;
    }
    if(cr->key == ke){
        this->size -= 1;
        cr->value = val;
        return cr;
    }

    if(ke > cr->key){
        cr->right = insert(cr->right, ke, val);
    }
    else{
        cr->left = insert(cr->left, ke, val);
    }

    cr->renewHeight();

    int balance = cr->getBalance(cr);
    
    // Left Left Case  
    if (balance > 1 && ke < cr->left->key)  
        return rightRotate(cr);  
  
    // Right Right Case  
    if (balance < -1 && ke > cr->right->key)  
        return leftRotate(cr);  
  
    // Left Right Case  
    if (balance > 1 && ke > cr->left->key){  
        cr->left = leftRotate(cr->left);  
        return rightRotate(cr); 
    }  
  
    // Right Left Case  
    if (balance < -1 && ke < cr->right->key){  
        cr->right = rightRotate(cr->right);  
        return leftRotate(cr);
    }  

    return cr;  
}

template <class K, class V>
void Dictionary <K, V>::add(K ke, V val){
    this->size += 1;
    this->root = insert(this->root, ke,  val);
}

template <class K, class V>
unsigned Dictionary <K, V>::getSize(){
    return this->size;
}

template <class K, class V>
void Dictionary <K, V>::inOrder (Node <K, V>* cr){
    if(cr == nullptr)
        return;
    inOrder(cr->left);
    cout << "Nodul: " << cr->value;
    cout << "  -- Cheia: " << cr->key;
    cout << "  -- Inaltimea: " << cr->height << endl;
    inOrder(cr->right);
}

template <class K, class V>
void Dictionary <K, V>::show(){
    if(root != nullptr && size > 0)
        inOrder(root);
}

template <class K, class V>
void Dictionary <K, V>::preOrder(Node<K, V>* cr){
    if(cr == nullptr)
        return;
    cout << "Nodul: " << cr->value;
    cout << "  -- Cheia: " << cr->key;
    cout << "  -- Inaltimea: " << cr->height << endl;
    preOrder(cr->left);
    preOrder(cr->right);
}

template <class K, class V>
void Dictionary <K, V>::preOrderForKey(Node <K, V>* cr, V &val, K ke){
    if(cr == nullptr)
        return;

    if(cr->key == ke){
        val = cr->value;
        return;
    }
    
    if(cr->key > ke)
        preOrderForKey(cr->left, val, ke);
    if(cr->key < ke)
        preOrderForKey(cr->right, val, ke);
}

template <class K, class V>
bool Dictionary <K, V>::srchKey(K ke, V &aux){
    preOrderForKey(root, aux, ke);
    if(aux != V())
        return true;
    return false;
}

template <class K, class V>
Node <K, V>* Dictionary<K, V>::rightRotate(Node <K, V>* cr){
    Node <K, V>* leftChild  = cr->left;
    Node <K, V>* rightChild = leftChild->right;

    //rotatie
    leftChild->right = cr;
    cr->left = rightChild;

    //renewHeight
    cr->renewHeight();
    leftChild->renewHeight();

    return leftChild;
}

template <class K, class V>
Node <K, V>* Dictionary<K, V>::leftRotate(Node <K, V>* cr){
    Node <K, V>* rightChild = cr->right;
    Node <K, V>* leftChild  = rightChild->left;

    //rotatie
    rightChild->left = cr;
    cr->right = leftChild;

    //renewHeights
    cr->renewHeight();
    rightChild->renewHeight();

    return rightChild;
}

template <class K, class V>
Node <K, V>* Dictionary<K, V>::minValFromTree (Node <K, V>* cr){
    Node <K, V>* aux = cr;
    
    while(aux->left != nullptr)
        aux = aux->left;
    return aux;
}

template <class K, class V>
void Dictionary<K, V>::deleteAfKey(K ke){
    this->size -= 1;
    deleteNode(root, ke);
}

template <class K, class V>
Node <K, V>* Dictionary <K, V>::deleteNode(Node <K, V>* root, K ke){
    if(root == nullptr)
        return root;

    //ne ducem in stanga
    if(ke < root->key)
        root->left = deleteNode(root->left, ke);
    else
        if(ke > root->key) //altfel, ne ducem in dreapta
            root->right = deleteNode(root->right, ke);
        else{
            //nodul are un copil sau niciunul
            if(root->left == nullptr || root->right == nullptr){
                Node <K, V>* temp = root->left ? root->left : root->right;

                //nu are copil
                if(temp == nullptr){
                    temp = root;
                    root = nullptr;
                }
                else //are un copil
                    *root = *temp;
                    delete temp;
            }
            else{   //nodul are 2 copii
                Node <K, V>* temp = minValFromTree(root->right);
                root->key   = temp->key;
                root->right = deleteNode(root->right, temp->key);
            }
        }

        //daca arborele avea doar 1 nod
        if(root == nullptr)
            return root;

        root->renewHeight();

        int balance = root->getBalance(root);

        //left left
        if(balance > 1 && root->left->getBalance(root->left) >= 0)
            return rightRotate(root);
        
        //left right
        if(balance > 1 && root->left->getBalance(root->left) < 0){
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        //right right
        if(balance < -1 && root->right->getBalance(root->right) <= 0)
            return leftRotate(root);

        //right left
        if(balance < -1 && root->right->getBalance(root->right) > 0){
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

    return root;
}

template <class K, class V>
void Dictionary <K, V>::deleteAllElements(){
    deleteDictionary(root);
    size = 0;
    root = nullptr;
}

template <class K, class V>
void Dictionary <K, V>::deleteDictionary(Node <K, V>* node){
    if(node == nullptr)
        return;
    
    deleteDictionary(node->left);
    deleteDictionary(node->right);
    
    delete node;
}

template <class K, class V>
std::ostream & operator << (std::ostream &out, Dictionary <K, V> &dtnary){
    out <<  "In Dictionar sunt " << dtnary.getSize() << " elemente" << std::endl;
    if(dtnary.getSize()){
        dtnary.show();
    }
    return out;
}

template <class K, class V>
V Dictionary<K, V>::operator[] (const K index) {
    V aux = V();
    //TODO    
    preOrderForKey(root, aux, index);
    return aux;
}

template <class K, class V>
Dictionary<K, V>& Dictionary<K, V>::operator= (Dictionary <K, V> dctnary){
    std::swap(this->root, dctnary.root);    
    std::swap(this->size, dctnary.size);
        //dctnary este copie a arborelui original
        //si se formeaza un nou arbore pe baza
        //dictionarului existent

    return *this;
} 

template <class K, class V>
bool Dictionary <K, V>::isEmpty(){
    if(getSize())
        return false;
    return true;
}