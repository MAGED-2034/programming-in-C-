/*
 * Written by: MAGED ALWARD
  *
 * Relation: assigment_8 from "Programming Techniques". 
 * Uinversity: STU 
 * The identation is 2 
 * Editor: VIM 
 * To successfull compilation and running:
		-compile it with c++ version 17 and above.
 *
 * ---------------Working with STL c++ -------------------
 */

#include<iostream> 
#include<list> 
#include<vector>
#include<numeric>
#include<algorithm>
#include<initializer_list>

/**** ----- includes for helper functions ---- */
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<typeinfo> // for test Functions

using namespace std;




/**__________________ HELPER FUNCTIONS  DIFINATIONS________________*/

template<typename T>
void printBasicStl1D(const T& lst);


template<typename T>
void printBasicStl2D(const T& lst);

template<typename T>
void printMap(const T& mp);


template<typename T>    
void printStk(T lst);



template<typename T>    
void printQue(T lst);



/*--------------------functions difinations ---------------*/


/*--function takes a list and return average of  the list*/

double average(const initializer_list<int> & data);



/*
 - Function takes list and int value and return index type const iterator of vlue if found
*/
list<int>::const_iterator findValue(const list<int>& data, int value) noexcept;



/*
 - Function return iterator for the first element in range of 200-400 if found  else return cend.
*/	
	bool isInRange200to400(int i) {return(i>=200&i<=400);	}
	list<int>::const_iterator findInRange200to400(const list<int>& data) noexcept;



/*
	 - Function take list of integers and replace any number between 200-400 wiht number 5. 
*/
	void replace200to400by5(list<int> & data) noexcept;


/*
 - Function take list and increment its elements by one and return the list.
*/
	int increment(int element) noexcept { return element + 1; }
	void incrementAll(list<int> & data) noexcept;


/*
	Functions take list and increment any element met the condition implemented by function
	 	incrementPointsIfItHelps.
*/
int incrementPointsIfItHelps(int points) noexcept {
    switch (points) {
        case 91 :
            return 92;
        case 82:
            return 83;
        case 73:
            return 74;
        case 64:
            return 65;
        case 55:
            return 56;
        default:
            return points;
    }
}

void helpAfterExam1(list<int> & points) noexcept;


/*
 - 	Functions take list and increment any element met the condition implemented by function incrementPointsIfItHelps 
 - function use Base_range for loop.
*/
void helpAfterExam2(list<int> & points) noexcept;



/*
	 -Function  return the sum of 2 list type int.
	 It use std::transform and std:plus<int> in the implementation.
*/
list<int> add(const list<int> & data1, const list<int> & data2) noexcept;




/*
 -Function will take vector<int> and sort it from greater to smallest.
*/
void sort1(vector<int> & data) noexcept;


/*** 
 	-Function will take vector<int> and sort it from greater to smallest.
	-The function use reverse iterator in the implementation.
****/
void sort2(vector<int> & data) noexcept;











/*----       -----------TESTING       MAIN FUNCTION ------------------      -----*/
int main() {	


	/*** Test: ----  average()   ----*****/
	initializer_list<int> m{2, 3 ,2};
	cout <<average(m) <<endl;
			

	/*******Test: --- findValue() ---*/
	const list<int>lstTestFV{11, 2, 33, 44, 5, 6, 11, 33, 29};
	const list<int>lstTestFV_1{};
	list<int>::const_iterator testCnIter;
	list<int>::const_iterator testCnIter_1;
	testCnIter = findValue(lstTestFV, 19);
	testCnIter_1 = findValue(lstTestFV_1, 33);
	
	cout <<"*-"<<*(--testCnIter)<<endl;
	cout <<"*-"<<*(--testCnIter_1)<<endl;
	for(auto i = testCnIter; i != lstTestFV.end(); i++) {
		cout <<*i <<endl; 
	}
		for(auto i = testCnIter_1; i != lstTestFV_1.end(); i++) {
			cout <<"*-" <<*i <<endl;
		}

	/*** Test: --- findInRange200to400() ---*/
	list<int> testlstFIR_1{55, 66, 66,44, 220, 355};
	list<int> testlstFIR_2{-200, 444, 554, 333};
	const list<int> testlstFIR_3{1,1,2,3,41, 2, 7};
	cout <<"*-"<<*(--findInRange200to400(testlstFIR_1))<<endl;
	cout <<"*-"<<*(--findInRange200to400(testlstFIR_2))<<endl;
	cout <<"*-"<<*(--findInRange200to400(testlstFIR_3))<<endl;
	cout << *(findInRange200to400(testlstFIR_1))<<endl;
	cout << *(findInRange200to400(testlstFIR_2))<<endl;
	cout <<*(findInRange200to400(testlstFIR_3))<<endl;

	

	/**** Test: ---- replace200to400by5()---**/
	list<int>lstRplc_1 {22, 555, -55, -55, 400, 222, 333, 433};
	list<int>lstRplc_2{};

	printBasicStl1D(lstRplc_1);
	cout <<endl;
	printBasicStl1D(lstRplc_2);
	cout <<endl;
	replace200to400by5(lstRplc_1);
	replace200to400by5(lstRplc_2);
	printBasicStl1D(lstRplc_1);
	cout <<endl;
	printBasicStl1D(lstRplc_2);
	cout <<endl;



	/**** Test: ----   incrementAll() ----------*/
	list<int> lstIncAll_1{1, 2, 3, -1, -2};
	printBasicStl1D(lstIncAll_1);
	cout <<endl;
	incrementAll(lstIncAll_1);
	printBasicStl1D(lstIncAll_1);
	cout <<endl;

	list<int> lstIncAll_2{};
	printBasicStl1D(lstIncAll_2);
	cout <<endl;
	incrementAll(lstIncAll_2);
	printBasicStl1D(lstIncAll_2);
	cout <<endl;


	/**** Test: ------- helpAfterExam1() ----*****/
	list<int> grades_1{ 100, 90, 91, 92, 93, 53, 54, 55, 56, 57, 91, 92 };
	printBasicStl1D(grades_1);
	cout <<endl;
	helpAfterExam1(grades_1);
	printBasicStl1D(grades_1);
	cout <<endl;


	list<int> grades_2{};
	printBasicStl1D(grades_2);
	cout <<endl;
	helpAfterExam1(grades_2);
	cout <<endl;



	/**** Test: ----- connectWithSpace() ---------***/
	list<int> grades_3{ 100, 90, 91, 92, 93, 53, 54, 55, 56, 57, 91, 92 };
	printBasicStl1D(grades_3);
	cout <<endl;
	helpAfterExam2(grades_3);
	printBasicStl1D(grades_3);
	cout <<endl;




	/*** Test: ---- add() ---****/
	list<int> data_1= {2, 1, 1, 4, 5};
	list<int> data_2 = {1, 0, 4, 6, 2};
	list<int> sumRslt = add(data_1, data_2);
	printBasicStl1D(sumRslt);
	cout << endl;

	list<int> data_3{};
	list<int> data_4{};
	list<int> rsltSumOfemptylists = add(data_3, data_4);
	printBasicStl1D(rsltSumOfemptylists);
	cout <<endl;


	/*** Test: --- sort1() --- ***/
	vector<int> v_1 {22, 33, 0, -150, 55, 11 , 1};
	printBasicStl1D(v_1);
	cout <<endl;
	sort1(v_1);
	printBasicStl1D(v_1);
	cout <<endl;
	/*** Test: --- 	sort2()---***/
	vector<int> v_2 {22, 33, 0, -150, 505, 11 , 1};
	printBasicStl1D(v_2);
	cout <<endl;
	sort2(v_2);
	printBasicStl1D(v_2);
	cout <<endl;

	
	return 0;
}










/********* ---------------- IMPLEMENTATION ----------*****/

void sort2(vector<int> & data) noexcept {
		stable_sort(data.rbegin(), data.rend(), std::less<int>());
}



void sort1(vector<int> & data) noexcept {
	stable_sort(data.begin(), data.end(), std::greater<int>());
}




list<int> add(const list<int> & data1, const list<int> & data2) noexcept {
	list<int> sumOfTwoList(data2.size(), 0);
	transform(data1.begin(), data1.end(), data2.begin(), sumOfTwoList.begin(), plus<int>());
	return sumOfTwoList;
}




void helpAfterExam2(list<int> & points) noexcept {
	for(auto &&i : points ) {
		 i =  incrementPointsIfItHelps(i);
	}		
}



void helpAfterExam1(list<int> & points) noexcept {
		transform(points.begin(), points.end(), points.begin(), incrementPointsIfItHelps);
}



void incrementAll(list<int> & data) noexcept {
	transform(data.begin(), data.end(), data.begin(), increment);
}



void replace200to400by5(list<int> & data) noexcept {
	replace_if(data.begin(), data.end(), isInRange200to400, 5);
}




list<int>::const_iterator findInRange200to400(const list<int>& data) noexcept {
	list<int>::const_iterator cnIter;
		cnIter = find_if(data.cbegin(), data.cend(), isInRange200to400);
		return cnIter;	
}



list<int>::const_iterator findValue(const list<int>& data, int value) noexcept {
	list<int>::const_iterator cnItr;
	cnItr = find(data.cbegin(), data.cend(), value);
	return cnItr;
}



double average (const initializer_list<int> & data) {
	double sum = 0.0;
	double rslt = 0.0;
	double len = 0.0;
	len = data.size();
	try {
		if (0==data.size()) {
			throw std::invalid_argument("inicializacny zoznam je prazdny");
		}
		sum = accumulate(data.begin(), data.end(), 0);
	}
	catch(const std::invalid_argument& e) {}
	rslt = sum / len;
	return rslt;
}












 
/**__________________ HELPER FUNCTIONS Implementation ________________*/
 
template<typename T>
void printBasicStl1D(const T& lst) {
  cout <<"\033[38;2;0;0;0m\033[48;2;242;230;16m{";
  for(auto i = lst.begin(); i != lst.end(); i++) {
    if(typeid(*i).name() == typeid(string).name())
    {    
      cout <<"\"" << *i <<"\", ";    
    }    
    else if(typeid(*i).name() == typeid(char).name()) {    
      cout <<"'" << *i <<"', ";    
    }    
    else {    
      cout << *i << ", ";    
    }    
  }    
  if(lst.empty()){    
    cout <<"}\033[0;0;0;0;0m\033[48;0;0;0;0m";    
  } else {    
    cout <<"\b\b}\033[0;0;0;0;0m\033[48;0;0;0;0m";    
  }    
}    
    
    
    
template<typename T>    
void printBasicStl2D(const T& lst) {    
  cout <<"{\n";    
  for(auto i = lst.begin(); i != lst.end(); i++) {   
     cout <<" ";    
    printBasicStl1D(*i);    
    cout<<",";    
    
  }    
  if(lst.empty()) {    
    cout <<"\n}" <<endl;    
  } else {    
    cout << "\b \n}\n";    
  }    
}    
    
    
template<typename T>    
void printMap(const T& mp) {    
    
  cout <<"{\n";    
  for(auto i = mp.begin(); i != mp.end(); i++) {    
    cout <<"\033[38;2;0;0;0m\033[48;2;242;150;16m";    
    if(typeid(i->first).name() == typeid(string).name()){    
        cout <<"\t\"" << i->first <<"\"->";    
    }    
    else if(typeid(i->first).name() == typeid(char).name()){    
        cout <<"\t'" << i->first <<"'->";
    }
    else {
        cout <<"\t" <<i->first <<"->";
    }
    if(typeid(i->second).name() == typeid(string).name()){
        cout <<"\"" << i->second <<"\",";
    }
    else if(typeid(i->second).name() == typeid(char).name()){
        cout <<"'" << i->second <<"\',";
    }else {
         cout <<i->second <<",";
    }
        cout <<"\033[0;0;0;0;0m\033[48;0;0;0;0m\n" ;    
  }
    cout <<"\n}\n";
}







template<typename T>    
void printStk(T lst) {    
  cout <<"{\n";
  
   while(!lst.empty()) {
    if(typeid(lst.top()).name() == typeid(string).name())    
    {
      cout <<"\033[38;2;0;0;0m\033[48;2;42;130;116m";    
      cout <<"\t|\"" << lst.top() <<"\"|"; 
      cout <<"\033[0;0;0;0;0m\033[48;0;0;0;0m\n";           
      lst.pop();
    }   
    else if(typeid(lst.top()).name() == typeid(char).name()) {    
      cout <<"\033[38;2;0;0;0m\033[48;2;42;130;116m";     
      cout <<"\t|'" <<lst.top() <<"'|";
      cout <<"\033[0;0;0;0;0m\033[48;0;0;0;0m\n";           
      lst.pop();
    }    
    else {    
      cout <<"\033[38;2;0;0;0m\033[48;2;42;130;116m";    
      cout <<"\t|" <<lst.top() <<"|";    
      cout <<"\033[0;0;0;0;0m\033[48;0;0;0;0m\n";           
      lst.pop();
    }    
  }    
      
    cout <<"\t---\n}\n";    

        
}    




template<typename T>    
void printQue(T lst) {         
  cout <<"{\n";    
    
   while(!lst.empty()) {
    if(typeid(lst.front()).name() == typeid(string).name())    
    {    
      cout <<"\033[38;2;0;0;0m\033[48;2;42;130;116m";    
      cout <<"\t|\"" << lst.front() <<"\"|";    
      cout <<"\033[0;0;0;0;0m\033[48;0;0;0;0m\n";           
      lst.pop();
    }    
    else if(typeid(lst.front()).name() == typeid(char).name()) {
      cout <<"\033[38;2;0;0;0m\033[48;2;42;130;116m";    
      cout <<"\t|'" <<lst.front() <<"'|\n";
      cout <<"\033[0;0;0;0;0m\033[48;0;0;0;0m\n";           
      lst.pop();
    }    
    else {    
      cout <<"\033[38;2;0;0;0m\033[48;2;42;130;116m";    
      cout <<"\t|" <<lst.front() <<"|";
      cout <<"\033[0;0;0;0;0m\033[48;0;0;0;0m\n";           
      lst.pop();
    }    
  }    
      
    cout <<"\n}\n";    
        
}    
 

