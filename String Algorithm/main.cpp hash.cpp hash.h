// .h is a header file used to store function declaration and macros
// take input from a file ./a < input.txt
-------------------------------------------------------------------------------------.h file---------------------------------------------------------------------------
  #include<bits/stdc++.h>
#include <iostream>
#include <string>
#include <cmath>
// You are free to use additional libraries as long as it's not BANNED per instruction.

using namespace std;

//int hash_function(string text);
class node
{
  public:
    string val;
    node *next;
    node(string val){
        this->val=val;
        next=NULL;
    }
};
class Hash{
    int bucket;
    //pointer to pointer array
    node **table;
    int *slotsLength;
  public:
    Hash(int V);
    void insertItem(string x);

    int hash_function(string x);
    float mean();
    void displayhash();
    void displayLength();
    int getSlotLength(int slotNum);
    float stdDeviation();

};



-----------------------------------------------------------------------------------------.cpp file----------------------------------------------------------------
  //Working of function is done in this file
  #include<bits/stdc++.h>
#include <iostream>
#include <string>
#include "Hash.h"

using namespace std;

int Hash::hash_function(string text) {
    // Implement your own hash function here
    char ch=tolower(text[0]);
    int value=ch-'a';
    return (value%bucket);
   
}


Hash::Hash(int size){
    this->bucket=size;
    table=new node*[size];
    slotsLength=new int[size];
    for(int i=0;i<size;i++){
        *(table+i)=NULL;
    }
}
void Hash::insertItem(string key){
    int index=hash_function(key);
    node *trav=NULL;
    if(*(table+index)==NULL){
        node *newNode=new node(key);
        *(table+index)=newNode;
    }
    else{
        trav=*(table+index);
        while(trav->next!=NULL){
            trav=trav->next;
        }
        node *newNode=new node(key);
        trav->next=newNode;
    }

}
void Hash::displayhash(){
    for(int i=0;i<bucket;i++){
        cout<<i<<"-->";
        node *trav=*(table+i);
        int length=0;
        while(trav!=NULL){
            cout<<trav->val<<" ";
            trav=trav->next;
            length++;
        }
        slotsLength[i]=length;
        cout<<endl;
    }
}

int Hash::getSlotLength(int slotNum){
   return slotsLength[slotNum];
}

void Hash::displayLength(){
   
   for(int i=0;i<bucket;i++){
      cout<<"Slot "<<i<<": "<<getSlotLength(i)<<endl;
   }
}

float Hash::mean(){
  float sum=0;
  for(int i=0;i<bucket;i++){
    sum+=getSlotLength(i);
  }
  return (sum/bucket);
}

float Hash::stdDeviation(){
   float mu=mean();
   float lamda=0;
   for(int i=0;i<bucket;i++){
       lamda+=(getSlotLength(i)-mu)*(getSlotLength(i)-mu);
   }
   float variance=lamda/bucket;
   float stdev=sqrt(variance);
   
   return stdev;
}


---------------------------------------------------------------------------------main.cpp--------------------------------------------------------------------
 //Here we create instances of class and call them.
  //we must include .h file
  
  /*
Abhishek Kumar Chaurasiya
*/
#include<bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <string>
#include "Hash.h"
using namespace std;

int main() {
    // freopen("inputs/sample_input.txt", "r", stdin);
    int k = 0;
    int n = 0;
    string texts[500];
    // WARNING: Start of the tokenizer that loads the input from std::cin, DO NOT change this part!
    cin >> k;
    string line;
    getline(cin, line);

    while (getline(cin, line)) {
        texts[n] = line;
        n++;
    }
    // WARNING: End of the tokenizer, DO NOT change this part!

    // By this point, k is the # of slots, and n is the # of tokens to fit in
    // texts[] stores the input sequence of tokens/keys to be inserted into your hash table

    // The template is able to be compiled by running 
    //   make
    //   ./encoder < inputs/sample_input.txt
    // which puts out the placeholders only.

    // Your time to shine starts now
    Hash *obj=new Hash(k);
   for(int i=0;i<n;i++){
     obj->insertItem(texts[i]);
   }
  
 
 
 
    cout << "==== Printing the contents of the first 5 slots ====" << endl;
    obj->displayhash();

    cout << "==== Printing the slot lengths ====" << endl;
    obj->displayLength();

    cout << "==== Printing the standard variance =====" << endl;
    cout<<obj->stdDeviation();

    return 0;
}
