#include<bits/stdc++.h>
using namespace std;
class node
{
  public:
    int val;
    node *next;
    node(int val){
        this->val=val;
        next=NULL;
    }
};
class Hash{
    int bucket;
    //pointer to pointer array
    node **table;
  public:
    Hash(int V);
    void insertItem(int x);

    int hashfunction(int x){
        return (x%bucket);
    }
    
    void displayhash();
};

Hash::Hash(int size){
    this->bucket=size;
    table=new node*[size];
    for(int i=0;i<size;i++){
        *(table+i)=NULL;
    }
}
void Hash::insertItem(int key){
    int index=hashfunction(key);
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
        while(trav!=NULL){
            cout<<trav->val<<" ";
            trav=trav->next;
        }
        cout<<endl;
    }
}

void solve(){
  
  int k,items; cin>>k>>items;
  Hash *obj=new Hash(k);
  for(int i=0;i<items;i++){
     int e; cin>>e;
     obj->insertItem(e);
  }
  obj->displayhash();


}


int main(){
 

#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   freopen("Error.txt", "w", stderr);
#endif
   int t; cin>>t;
   while(t--){
    solve();
   }

}

///////////////////////////////////////////////////////////////////////////////////string /////////////////////////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
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

    int hash_function(string x){
        char ch=tolower(x[0]);
        int value=ch-'a';
        return (value%bucket);
    }
    float mean();
    void displayhash();
    void displayLength();
    int getSlotLength(int slotNum);
    float stdDeviation();

};

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

void solve(){
  
  int k,items; cin>>k>>items;
  Hash *obj=new Hash(k);
  for(int i=0;i<items;i++){
     string e; cin>>e;
     obj->insertItem(e);
  }
  obj->displayhash();
  obj->displayLength();
  cout<<obj->stdDeviation();

}


int main(){
 

#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   freopen("Error.txt", "w", stderr);
#endif
   int t; cin>>t;
   while(t--){
    solve();
   }

}
