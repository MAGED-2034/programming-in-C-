/*
 * Written by: MAGED ALWARD
  *
 * Relation: assigment_3 from "Programming Techniques". 
 * Uinversity: STU 
 * The identation is 2 
 * Editor: VIM 
 * To successfull compilation and running:
		-compile it with c++ version 17 and above.
 *
 * ---------------Basic Data structures in c++ -------------------
 */



#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;



/**__________________ Data types_______________*/
struct Node {
	int data;
	Node* next;
};
struct List
{
	Node* first;
};



/**__________________ HELPER FUNCTIONS  DIFINATIONS________________*/
//Coloring the output in the terminal based on ASCII codes
enum TextColors
{
        BLACK = 30,
        RED = 31,
        GREEN = 32,
        YELLOW = 33,
        BLUE = 34,
        RED_PURBLE_BINK = 35,
        CYAN = 36,
        WHITE = 37,
        DEFUALT = 0
};


enum BackGroundColor
{
        bG_BLACK = 40,
        bG_RED = 41,
        bG_GREEN = 42,
        bG_YELLOW = 43,
        bG_BLUE = 44,
        bG_RED_PURBLE_BINK =  45,
        bG_CYAN = 46,
        bG_WHITE = 47,
        bG_DEFUALT = 0
};

//change the color of text output.
void setColor(TextColors color);

//Set background color
void setBackGroundColor(BackGroundColor color);

//reset to the default
void resetColor();

//Function to create random array with random values between[0, 1000).
void createArray(int *arr, const size_t size);

//PrintArr, takes 4 arguments: array pointer, size, BackGroundColor, TextColors.
void printArr(const int *arr, const size_t sz, BackGroundColor bg=bG_WHITE, TextColors fg=BLACK, int line=10);

//Swap by pointer function
void swap(int* a, int* b);


//Revere an ordered array of integers.
void reverse(int * arr, int len);

//print with array of strings whid nullptr at the end.
void printArrayOFstrings(const char* arr[]);

/** Function create random size linked list  with random vlaues between 0, rand()%200*/
void createRandomList(List *list);

//print linked lists 
void printList(List *list);

//Helper function to implement the mergeNeighbours function in recursive fasion.
//Takes 2 pointers one for input array and another for output arrray.
//Takes 4 other parameters for left, right ,  middle, index

void implementMerge(int *out, const int* in, const size_t lf, const size_t mid, const size_t rt, const size_t index, const size_t const_mid); 



/*--------------------functions difinations ---------------*/

void insertionSort(int *data, const size_t length);

void insertionSort(const char *data[]);

void insertionSort(List * list);

void mergeNeighbours(int *outpur, const int *input, const size_t low, const size_t middle, const size_t hight);





void mergeSort(int * data, const size_t length);
/*----       -----------TESTING:    MAIN FUNCTION ----------      -----*/


int main() {	
	
	int a[100];
	createArray(a, 100);
	printArr(a, 100);		
	insertionSort(a, 100);	
	printArr(a, 100, bG_BLACK, YELLOW);
	reverse(a, 100);
	printArr(a, 100, bG_WHITE, BLUE);
	

	int empty[0];
	insertionSort(empty, 100); 

	const char *mena[] = {"maged", "ahmed" , "Ahmed", "magen", "ahmer", nullptr};
	const char *empty_1[] = {NULL};
	const char *empty_2[] = {nullptr};
	const char *empty_3[] = {0};

	printArrayOFstrings(mena); 
	insertionSort(mena);
	printArrayOFstrings(mena);
	
	printArrayOFstrings(empty_1);
	insertionSort(empty_1);
	printArrayOFstrings(empty_1);
	
	printArrayOFstrings(empty_2);
	insertionSort(empty_2);
	printArrayOFstrings(empty_2);
	
	printArrayOFstrings(empty_3);
	insertionSort(empty_3);
	printArrayOFstrings(empty_3);
	
	const char* mena_1[] = {"Juraj", "Peter", "Andrej", nullptr};
	printArrayOFstrings(mena_1); 
	insertionSort(mena_1);
    printArrayOFstrings(mena_1); 

	const char* mena_2[] = {"Juraj", "Anabela", "Peter", "Andrej", nullptr};
	printArrayOFstrings(mena_2);
	insertionSort(mena_2);
	printArrayOFstrings(mena_2);

	const char* mena_4[] = {"Andrej", nullptr};
	printArrayOFstrings(mena_4); 
	insertionSort(mena_4);
	printArrayOFstrings(mena_4); 	


	const char* mena_3[] = {"Andrej", "Juraj", "Andrej", nullptr};
	printArrayOFstrings(mena_3); 
	insertionSort(mena_3);
	printArrayOFstrings(mena_3); 	



	struct Node nd_1;
	struct Node nd_2;
	struct Node nd_3;
	struct Node nd_4;
	struct Node nd_5;
	nd_1={1, &nd_2};
	nd_2={2, &nd_3};
	nd_3={2, &nd_4};
	nd_4={1, &nd_5};
	nd_5={26, NULL};	
	struct List ls;
	ls.first = &nd_1;
	printList(&ls);
	insertionSort(&ls);
	printList(&ls);	

	Node nd;
	List emptyList = {NULL};
	emptyList.first = &nd;
	
	emptyList.first->next = NULL ;
	insertionSort(&emptyList);
	printList(&emptyList);
	List list_1;
	createRandomList(&list_1);
	
	printList(&list_1);
	insertionSort(&list_1);
	printList(&list_1);
	free(list_1.first);

	const int input[]={10, 10, 9, 9,  7,  5,  2,  2,  8,  4,  2,  1, 1, 1, 0, 0};
    int output[]={20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20};
	int*ptr =output;
	printArr(input, 16, bG_YELLOW, BLACK, 20);
	printArr(ptr, 16, bG_BLACK, YELLOW, 20);
	mergeNeighbours(output, input, 0, 8, 16);
	printArr(ptr, 16, bG_RED, WHITE, 20);
	
	
	
	mergeSort(output,   16);
	printArr(output, 16, bG_YELLOW, BLACK, 20);
	
	int m[300];
	createArray(m, 300);
	printArr(m, 300);
	insertionSort(m, 300);
	printArr(m , 300);
	
	return 0;
}








/********* -------------------------- IMPLEMENTATION -------------*****/
void insertionSort(int * data, const size_t length) {

	int len = length - 1;
	int k = length - 1;
	while(len > 0) {
		int k = len;
		while(k < (length)) {
			int m = *(data + k  - 1);		
			if( *(data + k -1)< *(data + k)) {
				*(data+ k - 1) =  *(data + k);
				*(data+ k) = m;
			}
			k++;
		}
		len--;
	}
}

void insertionSort(const char *data[]) {
	size_t sz = 0;
	//find the length;
	while(*(data +  sz)) {
		sz++;
	}
	
	if(!sz) { return; }
	int i = 0;
 	while(i <(sz - 1)) {
		int  k = i;
		while(k >=0) {
			const char* m = *(data + k + 1);
			if(strcmp(*(data + 1 + k) , *(data + k )) > 0) {
			 *(data + k + 1) = *(data + k);
			 *(data + k)  = m;
			}
			k--;			
		}
		i++;
 }

}



void insertionSort(List *list) {
	if((list->first) == NULL){
		return ;
	}
/*	if(((list->first)->next) == NULL){
		return;	
	}*/
	int sz = 0;
	while(((list->first )+ sz)->next) { sz++; }
	int i = 0;
	while(i <  sz) {
		int k = i;
		while(k >=0) {
		  int m = ((list->first)+k + 1)->data;
			if((((list->first)+k + 1)->data) > (((list->first) + k)->data)) {
				(((list->first)+k + 1)->data) = (((list->first) + k)->data);
				(((list->first)+k)->data) = m;
			}
			k--;
		}
		i++;
	}
}





void mergeNeighbours(int *output, const int* input, const size_t low, const size_t middle, const size_t high) {
	
	size_t begin = low;
	const size_t mid =  middle;
	implementMerge(output, input, low, middle, high, begin, mid);

}








/**__________________ HELPERS FUNCTIONS Implementation ________________*/

//fonction for coloring the outputs.
void setColor(TextColors color) {
		
        std::cout << "\033[1;" << std::to_string(color) << "m";
};

// function to set background color
void setBackGroundColor(BackGroundColor color)
{
        std::cout << "\033[1;" << std::to_string(color) << "m";
};

// reset to the default
void resetColor()
{
        setBackGroundColor(bG_DEFUALT);
        setColor(DEFUALT);
};



//function to create random array with random values between[0, 1000).
//
void createArray(int *arr, const size_t size) {
	size_t sz = size-1;
	while(sz) {
		srand(sz * 1000);
		*(arr+sz) = rand()%1000;
		sz--;
	}
	srand(sz * 1000);
	*(arr+sz) = rand()%1000;

 }





//printArr, takes 4 arguments: array pointer, size, BackGroundColor,
//TextColors.

void printArr(const int *arr, const size_t sz, BackGroundColor bg, TextColors fg, int line){
	size_t i = 0;
	while(i < sz) {
		if(!(i%line)) {
			cout <<endl;
		}
		setColor(fg); 
		setBackGroundColor(bg);
		cout << *(arr + i) <<" ";
		resetColor();
		i++; 
	}
	cout <<endl;
}




char typeOfSorting(int *arr, const size_t sz) {
	if(sz <= 0) {
		return '\0';
	} 
	if(*(arr + sz - 1) > *(arr + sz - 2)) {return 'A'; } 
	else if(*(arr + sz - 1) < *(arr + sz - 2)) { return 'D'; }
	else {
		return typeOfSorting(arr, sz -1);
	}
}





void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}




void reverse(int * arr, int len) {
	int temp[len];
	for(int i = len -1; i >= 0; i--) {
		temp[len - i - 1] =  *(arr + i);
	}
	for(int i = 0; i < len; i++) {
		*(arr + i) = temp[i];
	}
}



void printArrayOFstrings(const char* arr[]) {
	int sz = 0;
	
	cout <<"{";
 	
	while(*(arr + sz) ) {
		sz++;
	}
	
	sz= 0;  
	while(*(arr + sz)) {
		setBackGroundColor(bG_YELLOW);
		setColor(BLACK);
		cout <<"\"" <<*(arr+ sz) << "\", ";
		resetColor();
		sz++;
	}

	sz==0?cout <<"}\n":cout <<"\b\b}\n";
}


/** Function create random size linked list between rand()%200
*/
void createRandomList(List *list) {
	srand(time(NULL));
	int sz= rand()%200;
	list->first = (Node*)malloc(sz * sizeof(Node));
	int i = 0;
	while(i < (sz-1)) {
		srand(i*i*i +2000);
		(list->first+ i)->data = rand()%1000;
		(list->first + i)->next =(list->first +  i+ 1);
		i++;
	}
	(list->first+i)->data=5555;
	(list->first+i)->next=NULL;
}



void printList(List *list) {	
	
	if(list->first->next == NULL) {
		return;
	}
	

	int sz = 0;
	while(((list->first )+ sz)->next) { sz++; }
	
	sz++;
	int i = 0;
	while(i <  (sz)) {
		setColor(BLACK);
		setBackGroundColor(bG_WHITE);
		cout << ((list->first) + i) -> data << "->";
		resetColor();
		i++;
	}
	 cout <<"NULL" <<endl;
}



void implementMerge(int *out, const int* in, size_t lf, size_t mid, const size_t rt, const size_t index, const size_t const_mid) {	
	
	if(index >= rt) {
		return;
	}
	size_t i = index;
	if((*(in + lf) >= *(in + mid)) &&lf<const_mid) {
		*(out + index) = *(in + lf);
		lf++;
	} else if(mid<rt) {
		*(out + index) = *(in + mid);
		mid++;

	} else if(mid>=rt) {
		*(out + index) = *(in + lf);
		lf++;
	} else if(lf>=const_mid) {
		*(out + index) = *(in +mid);
		mid++;
	}
	i++;
	implementMerge(out, in, lf, mid, rt, i++, const_mid);

}



void mergeSort(int * data , const size_t length){
    
    
    int* tempArray = new int[length];
    
    for(int index = 1; index < length; index *= 2) {
        
        
        for(int leftStart = 0; leftStart < length; leftStart += (index * 2)) {
            
            const size_t rightStart = std::min<unsigned long>(leftStart + index, length);
            const size_t rightEnd =  std::min<unsigned long>(rightStart + index, length);
            mergeNeighbours(tempArray, data, leftStart, rightStart, rightEnd);
        }
        
        size_t n = 0;
        while(n < length) {
            *(data + n) = *(tempArray  +  n);
            n++;
        }
        
    }
    
    delete (tempArray);
    
    
}



