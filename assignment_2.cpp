/*
Meno a priezvisko: MAGED AL-WARD


POKYNY:
(1)  Implementujte funkcie tak, aby splnali popis pri ich deklaraciach.
(2)  Cela implementacia musi byt v tomto jednom subore.
(3)  Odovzdajte len tento zdrojovy subor (s vypracovanymi rieseniami).
(4)  Program musi byt kompilovatelny.
(5)  Globalne a staticke premenne su zakazane.
(6)  V ziadnom pripade nemente deklaracie funkcii, ktore mate za ulohu naprogramovat
     (nemente nazvy, navratove hodnoty, ani typ a pocet parametrov v zadanych funkciach).
     Nemente implementacie zadanych datovych typov, ani implementacie hotovych pomocnych funkcii
     (ak nie je v zadani ulohy uvedene inak).
(7)  V pripade potreby mozete kod doplnit o dalsie pomocne funkcie alebo datove typy.
(8)  Vase riesenie otestujte (vo funkcii 'main' a pomocou doplnenych pomocnych funkcii alebo datovych typov).
     Testovaci kod ale nebude hodnoteny.
(9)  Funkcia 'main' musi byt v zdrojovom kode posledna.
*/


#include <iostream>
#include<cstdlib>
using namespace std;

//-------------------------------------------------------------------------------------------------
// DATOVE TYPY
//-------------------------------------------------------------------------------------------------

// Reprezentacia uzla zretazeneho zoznamu
struct Node {
    int data; // hodnota uzla
    Node *next; // adresa nasledujuceho uzla zoznamu
};

// Reprezentacia zretazeneho zoznamu
struct List {
    Node *first; // adresa prveho uzla zoznamu
};

// Pomocna struktura pre ulohu 2
struct ListData {
    int *data; // pole hodnot uzlov
    size_t len; // dlzka pola 'data'
};


//-----------------------Helper function definition --------------------------------------


void printList(List * list);
void freeList(List* list);

//-------------------Assignment Functions definition -----------------

void appendNode(List *list, const int val);
List *createList(const ListData *listData);
void insertNode(List * sortedList, const int val);
List *joinLists(List *list1, List *list2);
void removeLastNode(List *list);
bool isPalindrome(const List *list) ;
int sumNodes(const List *list, const size_t n);
bool contains(const List *list1, const List *list2);
List *deepCopyList(const List *list);
Node *findLastNodeOccurrence(const List *list, const int val);




//----------Test: main function ----------------------
int main() {

    List list={};
    appendNode(&list, 333);
    appendNode(&list, 332);
    appendNode(&list, 33);
    appendNode(&list, 3632);



    int a[] = {22, 33, 44, 55};
    ListData lstDt={};
    lstDt.data = a;
    lstDt.len = 3;
    List lst2 = *(createList(&lstDt));
    printList(&lst2);

    const int i=61;
    insertNode(&lst2, i);
    insertNode(&lst2, 5);
    insertNode(&lst2, 3);
    insertNode(&lst2, 20);
    printList(&lst2);


  List* m = joinLists(&lst2, &list);
  printList(m);
  removeLastNode(m);
  removeLastNode(m);
  removeLastNode(m);
  removeLastNode(m);
  printList(m);

  removeLastNode(&lst2);
  removeLastNode(&lst2);
  removeLastNode(&lst2);
  removeLastNode(&lst2);
  removeLastNode(&lst2);
  printList(&lst2);

  List list2 = {};
  appendNode(&list2, 1);
  appendNode(&list2, 1);
  printList(&list2);
  if(isPalindrome(&list2)){ cout << "true" << endl; }
 else {cout << "false" << endl; }
  appendNode(&list2, 2);
  printList(&list2);
  if(isPalindrome(&list2)){ cout << "true" << endl; }
   else {cout << "false" << endl; }
  appendNode(&list2, 3);
    printList(&list2);
  if(isPalindrome(&list2)){ cout << "true" << endl; }
   else {cout << "false" << endl;}
  appendNode(&list2, 2);
  appendNode(&list2, 1);
  appendNode(&list2, 1);
  printList(&list2);
  if(isPalindrome(&list2)){ cout << "true" << endl; }
  else {cout << "false" << endl; }


  cout << "sum: " << sumNodes(&list2, 7) <<endl;



  List lst_1={};
  appendNode(&lst_1, 2);
  appendNode(&lst_1, 2);
  appendNode(&lst_1, 2);
  appendNode(&lst_1, 2);
  appendNode(&lst_1, 1);
  printList(&lst_1);

  List lst_2={};
  appendNode(&lst_2, 2);
  appendNode(&lst_2, 3);
  printList(&lst_2);
  if(contains(&lst_1, &lst_2)) {
    cout <<"true" <<endl;
  } else {
    cout <<"false\n";
  }
  
  
  
	List * listPtr =(deepCopyList(&lst_1));
	List ls = {};
	ls.first = listPtr->first;
	appendNode(&lst_1, 2255);
 
  freeList(&lst_1);
  appendNode(&ls, 99);
  printList(&ls);
  
  
  Node * match = findLastNodeOccurrence(&ls, 2); 
	cout << match->next->data << endl;
  return 0;
}






//--------------------Function implemention--------------------


//------------------one-------------

void appendNode(List *list, const int val) {
   
  Node * nd = (Node*)malloc(sizeof(Node));
  nd->data = val;
  nd->next = nullptr;
  if(list->first==nullptr){
    list->first = nd;
    return;
  } 
  Node* ptr = list->first;
  while(true){
    if(ptr->next == NULL){
      ptr->next =nd;
      break;
    }
    ptr = ptr->next;
  }

}

//------------------Two-----------------
List *createList(const ListData *listData) {
  if(listData->len == 0){
    return nullptr;
  }
  size_t i = 0;
  List ls = {};
  List *lst=&ls;
  while(i < listData->len){
    appendNode(lst,  *(listData->data + i));
    i++;
  }
  return lst; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}



//--------------Three-------------------
void insertNode(List * sortedList, const int val) {
  Node * nd = (Node*)malloc(sizeof(Node));
  nd->data = val;
   
  nd->next = NULL;
   int i = 0;
   if(sortedList->first==nullptr||sortedList->first->data >= val){
     nd->next = sortedList->first;
     sortedList->first = nd;

     return;
   }
   
    Node* tempPtr = sortedList->first;

   while(true) {
     if(tempPtr->next == NULL){
       if(tempPtr->data >val){
        nd->next= tempPtr;
        tempPtr=nd;
        return;
       } else{
         tempPtr->next=nd;
         return;
       }
     }
    if(tempPtr->data >= val){
      nd->next=tempPtr;
      tempPtr= nd;
      return;
    }
    tempPtr = tempPtr->next;
   }
  tempPtr->next = nd; 
}



//---------------------Four-------------------
List *joinLists(List *list1, List *list2){
  if(list1 ==  nullptr||list2==nullptr){return nullptr;}
  if(list1->first == nullptr||list2->first ==nullptr) { return nullptr; }
  Node* temp = list1->first;
  while(temp->next!= nullptr){
    temp = temp->next;
  }
  temp->next=list2->first;
  return list1; 
}


//-----------------------Five---------------
void removeLastNode(List *list) {
  if(list ==  nullptr){return;}
  if(list->first == nullptr) { return; }
  Node* nd = list->first;
  Node* nw;
  while(nd->next->next != NULL) {
    nd = nd->next;
  }
  free(nd->next);
  nd->next = NULL;
}



//------------Six-----------------
bool isPalindrome(const List *list) {
  if(list ==  nullptr){return true;}
  if(list->first == nullptr) { return true; }

  Node* nd_1 = list->first;
  Node* nd_2 = list->first;

  int len = 0;
  int j = 0;
  int k = 0;
  int i = 0;

  //get the length;
  while (nd_1!= nullptr){
    nd_1 = nd_1->next;
    len++;
  }
  
  Node *nd[len];
  while (nd_2!= nullptr){
    nd[j] = &(*nd_2);
    nd_2 = nd_2->next;
    j++;
  }
 
  
  j = 0;
  k=len-1;
  int mid = len/2;
  while(i<len){
    if(j >= mid){
      break;
    }
    if(nd[j]->data== nd[k]->data) {
      nd[k] = nullptr;
      nd[j] = nullptr;
      j++;
      k--;
    }
    i++;
  }
  if(len%2 == 0){ k++; }
  if(j!=k){ return false;}
  return true; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}



//--------------Seven----------------------
int sumNodes(const List *list, const size_t n) {
  if(list ==  nullptr){return 0;}
  if(list->first == nullptr) { return 0; }
  
  
  size_t i = 0;
  int sum = 0;
  Node* nd = list->first;
  while(i < n){
    sum = sum + nd->data;
    nd=nd->next;
    i++;
  }
  
  return sum;
  
}



//--------------------------Eight------------------
bool contains(const List *list1, const List *list2) {
 if(list1 ==  nullptr||list2==nullptr){return 1;}
  if(list1->first == nullptr||list2->first ==nullptr) { return 1; }
  int len_1 = 0;
  int len_2 = 0;
  Node* nd_21  = list2->first;
  
  
  bool i = 0;
  while(nd_21){
   Node* nd_11  = list1->first;
   i= 0;
   while(nd_11){
     if(nd_21->data == nd_11->data){
       i=true;
     }
     nd_11 =nd_11->next;
   }
    nd_21 = nd_21->next;
  }

    return i; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}


//------------Nine----------------------
List *deepCopyList(const List *list) {
		List *ptr = (List*)malloc(sizeof(List));

		ptr->first =nullptr;
    if(list == nullptr){
      return ptr;
    }
    int len = 0;
    Node *nd_1 = list->first;
    Node *nd_2 = list->first;
    while(nd_1){
     	appendNode(ptr, nd_1->data);
      nd_1 = nd_1->next;
    }
    
    return ptr; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//--------------Tenth--------------------
Node *findLastNodeOccurrence(const List *list, const int val) {
  if(list ==  nullptr){return nullptr;}
  if(list->first == nullptr) { return nullptr; }
  int index = 0;
  int existuje =0;
  Node* nd_1 = list->first;
  Node* adder = (Node *) malloc(sizeof(Node)); 
  while(nd_1){
    if(nd_1->data == val){
      existuje  = 1;
      adder = nd_1;
    }   
    nd_1 = nd_1->next;
  }  
  if(existuje == 0){
    return nullptr;
  }
  return adder; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}



//--------------------Helper functions implementaion-----------
void printList(List * list){
  Node * n = list->first;
  
  while(true){
      if(n->next == NULL) {
        cout << n->data << "->NULL";
        break;
      }
      
      if(n == NULL ){
        break;
      }
      cout << n->data <<"->";
      n = n->next;
  }
  
  
  cout <<endl;
}


void freeList(List* list){

  Node* nd = list->first;
  Node* nw;
  while(nd != NULL) {
    nw = nd->next;
    free(nd);
    nd = nw;
  }
  list->first = NULL;
}



