/*
Meno a priezvisko: MAGED AL-WARD
*/



#include <iostream>
#include<cstdlib>
using namespace std;

/**__________________ Data types_______________*/
struct Weight {
    int product; // hmotnost produktu
    int packing; // hmotnost balenia
};


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

//-----------------------Helper function definition --------------

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
void swap(Weight& a, Weight& b);

//Revere an ordered array of integers.
void reverse(int * arr, int len);

//print with array of strings whid nullptr at the end.
void printArrayOFstrings(const char* arr[]);

//overide printArray to print array type Weight.
void printArr(const Weight*  w, const size_t sz);
int sum(int a, int b);

size_t getMedian(int a, int b , int c);
size_t parti(int* data,  int low, int high);


//-------------------Assignment Functions definition -----------------
void bubbleSort(int *data, const size_t length);

void bubbleSort(Weight *data, const size_t length);

size_t getPivotIndex(const int *data, const size_t low, const size_t high);


size_t partition(int *data, const size_t pivot, const size_t low, const size_t high);


void quickSort(int *data, const size_t low, const size_t high);




//----------Test: main function ----------------------
int main() {

	cout << "-------------------1----------" <<endl;
	int g[] = {1, 3, 2};
	bubbleSort(g, 3);
	printArr(g,3);
	
	cout << "-------------------2----------" <<endl;
	Weight F[] = {{10, 1}, {20, 2}, {5,2}};
	bubbleSort(F, 3);
	printArr(F, 3);

	cout << "-------------------3----------" <<endl;
	int E[] = {10, 20, 1000, 30, 40};
	cout << getPivotIndex(E, 2, 3)  << endl;
	printArr(E, 5);
	
	int d[] = {10, 20, 2000, 30, 1000, 40, 5000, 50, 60, 70};
	cout << getPivotIndex(d, 2, 7) << endl;
	printArr(d, 10);

	cout << "-------------------4----------" <<endl;
	int c[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
	cout << partition(c, 5, 2, 7)  << endl;
	printArr(c, 9);

	int b[] = {10, 20, 30, 40, 50, 60, 70, 50, 80, 90};
	cout << partition(b, 4, 2, 8)  << endl;
	printArr(b, 10);


	cout << "-------------------5----------" <<endl;
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	quickSort(a, 2 ,7);
	printArr(a, 8);

	int aa[20];
	createArray(aa, 20);
	printArr(aa, 20);
	bubbleSort(aa, 20);
	reverse(aa, 20);
	printArr(aa, 20);
	quickSort(aa, 0, 15);
	printArr(aa, 20);

  return 0;
}






//--------------------Function implemention--------------------


//------------------one-------------
void bubbleSort(int * data, const size_t length) {
	if(data==NULL || data==nullptr || length<=0) {return;}	

	int n = length;
	int i = 0;
	while(i < n){
	 	int j = 0;
		while(j < n -1) {
			if(*(data + j) < *(data + j + 1) ) {
				swap((data+j) , (data +j +1));
			}
			j++;
		}
		n--;
	}
}

//------------------Two-----------------

void bubbleSort(Weight* data, const size_t length) {
	if(data==NULL || data==nullptr || length<=0) {return;}

	int n = length;
	int i = 0;
	while(i <= n) {
		int j = 0;
		while(j < n-1) {
			int aPck = (data + j)->packing;
			int aPro = (data + j)->product;
			int bPck = (data + j + 1)->packing;
			int bPro = (data+j+1)->product;
			if((aPro + aPro) < (bPro + bPck) ) {
				swap(*(data + j), *(data + j + 1) ); 
			}
			j++;
			
		}
		n--;
	}
}


//--------------Three-------------------
size_t getPivotIndex(const int *data, const size_t low, const size_t high)
{
	int atLow = *(data + low);
	int atMid = *(data + ((low + high) /2));
	int atHigh = *(data +(high - 1));
	switch(getMedian(atLow, atMid, atHigh) ) {
		case 1:
			return low;
		case 2: 
			return ((low+high)/2);
		case 3:
			return (high - 1);
		default:
			return ((low + high)  / 2);
	}
}



//---------------------Four-------------------



size_t partition(int *data,  const size_t pivot, const size_t low, const size_t high) {	
  size_t i = low-1;
  size_t j = low;
	int rndPiv = *(data + pivot);
	swap((data+pivot), (data+high-1));
	for(j=low; j < high-1; j++) {
    
  
    if(*(data + j)>= rndPiv){
      i++;
      swap((data + j), (data + i));
      
    }
    
  }
 	swap((data + i+1 ) , (data + high-1)); 
  return i+1;
}

//-----------------------Five---------------
void quickSort(int *data, const size_t low, const size_t high) {
	  
		if(low < high) {
			int index = getPivotIndex(data, low, high);
			size_t piv=partition(data,  index, low, high);
			quickSort(data,  low, piv -1);
			quickSort(data, piv + 1, high);
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





void printArr(const Weight*  w, const size_t sz) {
	cout << "{" ;
	size_t i = 0;
	while(i < sz) {
		setColor(YELLOW);
		setBackGroundColor(bG_BLACK); 
		cout <<"{" <<(w + i)->packing <<", " <<(w + i)->product <<"}, ";
		resetColor();
		i++;
	}

	cout <<"\b\b} \n";
}


int sum(int a, int b) { return (a + b);} 




void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swap(Weight& a, Weight& b) {
	Weight temp;
	temp.packing = a.packing;
	temp.product = a.product;
	a.product = b.product;
	a.packing = b.packing;
	b.packing = temp.packing;
	b.product = temp.product;
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

