/*
 * Written by: MAGED ALWARD
  *
 * Relation: assigment_5 from "Programming Techniques". 
 * Uinversity: STU 
 * The identation is 2 
 * Editor: VIM 
 * To successfull compilation and running:
		-compile it with c++ version 17 and above.
 *
 * ---------------Heap; heap-interface in c++ ---------------
 */



#include<iostream>
#include<cstdlib>
using namespace std;




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

int sum(int a, int b);

size_t getMedian(int a, int b , int c);
size_t getParent(int i);
size_t getLeftChild(int i);
size_t getRightChild(int i);
size_t getMinIndex(int * data, const size_t i, const size_t j, const  size_t k, const size_t len);


/*--------------------functions difinations ---------------*/
void siftUp(int data[], const size_t addIndex);
void buildHeapSiftUp(int data[], const size_t length);
void siftDown(int data[], const size_t topIndex, const size_t length);
void buildHeapSiftDown(int data[], const size_t length);
void heapSort(int data[], const size_t length);


/*----------TESTING:    MAIN FUNCTION -----------*/
int main() {
	
	
	cout <<"---------------1-----------------\n";
	int a[] = {2, 4, 10, 7, 1, 2, 5, 0, 3, -1, 11, 12, 1};
	printArr(a, 13);
	siftUp(a, 4);
	printArr(a, 13);
	
	int b[] = {3, 4, 10, 5, 5, 11, 15, 7, 8, 9, 10, 14,  8, 1, 2};
	printArr(b, 15);
	siftUp(b, 12);
	printArr(b, 15);

	int c[] = {3, 4, 10, 5};
	printArr(c, 4);
	siftUp(c, 0);
	printArr(c, 4);


	
	cout <<"--------------2-----------------\n";

	int d[]= {7, 2, 1, 2, 8, 5, 3, 4, 2, 2, 6};
	printArr(d, 11);
	buildHeapSiftUp(d, 11);
	printArr(d, 11);



	
	cout <<"---------------3-----------------\n";
	int aa[]= {55, 20, 10, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140};
	printArr(aa, 15);
	siftDown(aa, 0, 15);
	printArr(aa, 15);

	int bb[] = {100, 8, 2, 1, 0, 5, 6, 7, 4, 2, 3, 11, 12, 13, 14, 15, 16, 17};
	printArr(bb, 18);
	siftDown(bb, 1, 18);
	printArr(bb, 18);

	

	
	cout <<"---------------4-----------------\n";
	int cc[]={7, 2, 1, 2, 8, 5, 3, 4, 2, 2, 6};
	printArr(cc, 11);
	buildHeapSiftDown(cc, 11);
	printArr(cc, 11);


	
	cout <<"---------------5-----------------\n";
	int data[] = {7, 2, 1, 2, 8, 5, 3, 4, 2, 2, 6};
	printArr(data, 11);
	heapSort(data, 11);
	printArr(data, 11);


	int test[100];
	createArray(test, 100);
	printArr(test, 100);
	heapSort(test, 100);
	printArr(test, 100);




}








//-----------------------Implementation-------------------
//----------------One-----------------------
void siftUp(int data[], const size_t addIndex)
{
  size_t parent = getParent(addIndex);
  if(parent < 0) { return; }
  
  if(*(data + parent) > *(data + addIndex)){
    swap((data + parent), (data + addIndex));
    siftUp(data, parent);
  }
}

//-------------Tow----------------------------
void buildHeapSiftUp(int data[], const size_t length)
{
  for(int i= 0; i < length; i++){
    siftUp(data, i);
  }
}

/*
size_t getMinIndex(int * data, const size_t i, const size_t j, const  size_t k, const size_t len){
  if(j<= len &&*(data  + j) < *(data + i)){ return j; }
  if(k <= len && *(data + k) < *(data  + i)){ return k; }
   return i; 

}*/

//---------------------Three--------------------
void siftDown(int data[], const size_t topIndex, const size_t length)
{
  size_t nodeToPerc = topIndex;
  while(2*nodeToPerc+1 < length){
    unsigned child1 = 2*nodeToPerc+1;
    unsigned child2 = child1 + 1;
    unsigned minchild = child1;
    if(child2< length&&*(data + child2) < *(data +child1)){
      minchild = child2;
    }
    
    
    if(*(data + minchild) < data[nodeToPerc]){
      swap((data + nodeToPerc), (data + minchild));
      nodeToPerc = minchild;
    } else {
      nodeToPerc = length;
    }
  }
}

//----------------------Four----------------------------
void buildHeapSiftDown(int data[], const size_t length)
{
  int i = ((length - 1 )/2); 
  while(i >=0) {
    siftDown(data, i, length);
    --i;
    
  }
}


//---------------Five-------------------------
void heapSort(int data[], const size_t length)
{
    buildHeapSiftUp(data, length);
    int i = length; 
    while(i>0){
      swap(data, (data+ i-1));
      i--;
      buildHeapSiftDown(data, i);  
    }
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
		srand(sz * time(NULL) * 1000);
		*(arr+sz) = rand()%1000;
		sz--;
	}
	srand(sz * 1000 *time(NULL));
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




int sum(int a, int b) { return (a + b);} 




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
	if(arr == NULL || arr==NULL) {return;}
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


size_t getMedian(int a, int b , int c) {
	if(a==b || b==c || a==c) { return 0;}
	
	if(a > b) {
		if(b > c) {return 2;}
		else if(a>c) { return 3; }
		else { return 1;}
	}
	else{
		if(a > c) { return 1;}
		else if(c > b) { return 2;}
		else { return 3;}
	}

}





size_t getMinIndex(int * data, const size_t i, const size_t j, const size_t k, const size_t len){
  if(j<= len &&*(data  + j) < *(data + i)){ return j; }
  if(k <= len && *(data + k) < *(data  + i)){ return k; }
   return i; 

}

size_t getParent(int i){ return ((i - 1)/2); }

size_t getLeftChild(int i) { return ((2 * i)+ 1); }

size_t getRightChild(int i) { return ((2 * i) + 2); }

