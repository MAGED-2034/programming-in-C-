/*
 :* Written by: MAGED ALWARD
 : *
 * Relation: assigment_7 from "Programming Techniques". Uinversity: STU Note:
 * The identation is 2 Editor: VIM To successfull compilation and running:
		-compile it with c++ version 11 and above.
 *
 * ---------------Working with STL c++ -------------------
 */

#include<iostream> 
#include<string>
#include<sstream>
#include<map>
#include<queue>
#include<list> 
#include<stack>
#include<vector>
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


/*--function takes a list and reverse it and return it as queue type.*/
queue<int> reverse(const list<int> & data) noexcept;


/*
 - Function takes reference to data structure type queue and reverse it with
	 help of stack data structure.
*/
void reverse(queue<int> & data) noexcept;


/*
 - Function generates 2D vector and return it. Takes 3 values 2(row, col) and
	 value to fill the vector with it.
*/
vector<vector<int>> create2dVector(const size_t size1, const size_t size2, 
		const int value) noexcept;


/*
 - Function takes 2 values(string, int), concatnate space and number to the
	 string and return it.
*/

string connectWithSpace(const string & text, const int number) noexcept;

/*
 - Function takes stream of integer number as string and  return the sum of
	 them.
*/
int sum(istringstream & text) noexcept;



/*
 - Function takes three parameters; map type string to string and list
	 typestring.
 - Will match every element in the list with map first key of the
	 map.
 - If any element match with first key will be raplace with second key and will
	 return the list.
*/
list<string> translate(const map<string, string> & translator, const
		list<string> & sentence) noexcept;



/*
 - Function takes string and will check if every parenthesis is paired if yes
	 will return true. 
 - If the string is empty of doesn't contain any parenthesis,
	also will return true.
*/
bool areParenthesisPaired(const string & mathExpression) noexcept;


/***function to test --call-back function "execute"---***/
int maxValue(int a, int b) noexcept;
int multiply(int a, int b) noexcept;



/*
 - function excute will take function pointer as parameter and another twon
	 values and run the function on it
*/
int execute(int (*function)(int, int), int parameter1, int parameter2);


/*
 - Enum to catagorize the exceptions
*/
enum class ExceptionType {
	NO_EXCEPTION,
	INVALID_ARGUMENT,
	BAD_ALLOC,
	UNKNOWN_EXCEPTION
};



/*
 - Function will take a function pointer as  perameter.
 - It will check what type of exception was thrown by the parameter function
   and return it
*/
ExceptionType thrownException(void (*function)()) noexcept;


/*** functions will throw different exceptions ****/
void doNotThrow() noexcept;
void throwInvalidArgument();
void throwBadAlloc();
void throwOutOfRange();



/*
 - Class to emulate IndexOutofRangeException.
*/
class IndexOutOfRangeException {
	private:
    const size_t length;
    const size_t index;
	public:
    IndexOutOfRangeException(size_t length, size_t index) noexcept
            : length(length)
            , index(index) { }
 
    size_t getLength() const noexcept {
        return length;
    }
 
    size_t getIndex() const noexcept {
        return index;
    }
 
    string what() const noexcept {
        return "index out of range: " + to_string(index) + " >= " + to_string(length);
    }
};



/*
 - Function takes 2 values(length, index).
 - It will generate list of length and fill it with '0'.
 - At index value will be 1 if index is exist or Exception will be thrown
*/
list<int> createList(const list<int>::size_type length, const list<int>::size_type indx);





/*----       -----------TESTING       MAIN FUNCTION ------------------      -----*/
int main(void) {	


	/*** Test: --cireateList()--*/	
	list<int> testLst_0 = createList(0, 0);
	printBasicStl1D(testLst_0);
	testLst_0 = createList(10, 10);
	printBasicStl1D(testLst_0);
	testLst_0 = createList(11, 2);
	printBasicStl1D(testLst_0);
	testLst_0 = createList(13, 5);
	printBasicStl1D(testLst_0);
	testLst_0 = createList(10, -1);
	printBasicStl1D(testLst_0);
	testLst_0 = createList(5, 10);
	printBasicStl1D(testLst_0);


	/*******Test: --- thrownException() ---*/
	cout <<endl;
	if (thrownException(doNotThrow) == ExceptionType::NO_EXCEPTION) {
		cout <<"true" << endl;
	}
	if (thrownException(throwInvalidArgument) == ExceptionType::INVALID_ARGUMENT) {
		cout <<"true" << endl;
	}
	if(thrownException(throwBadAlloc) == ExceptionType::BAD_ALLOC) {
		cout <<"true" <<endl;
	}
	if(thrownException(throwOutOfRange) == ExceptionType::UNKNOWN_EXCEPTION) {
		cout <<"true" <<endl;
	}

	
	/*** Test: --- call-back function;execute(), lambda ---*/
	cout <<execute(&multiply, 20, 50) <<execute(&multiply, 20, 50) <<endl;
	cout <<execute(&maxValue, 20, 50) <<execute(&maxValue, 20, 50) <<endl;
	cout <<execute([](int a, int b) ->int { return a - b; }, 20, 50);


	/**** Test: ---- areParenthesisPaired() ---*/
	cout <<endl;
	const string empStr = "";
	if(areParenthesisPaired(empStr)) { cout <<"TRUE" <<endl;}
	const string trueString = "[][dds][]s[][]s[]s[[][d]s](0)(--------){{[9]}}";
	if(areParenthesisPaired(trueString)) { cout <<"TRUE" <<endl;}
	if(areParenthesisPaired("ab - (c< d > 1) + {[23 ( [ 45] ) 6] i7} 8 ")) {
		cout <<"TRUE" <<endl;
	}
	const string str1 = "(";
	if(areParenthesisPaired(str1)) { cout <<"TRUE" <<endl;}
	const string str2 = "())";
	if(areParenthesisPaired(str2)) { cout <<"TRUE" <<endl;}
  const string str3 = "( >";
	if(areParenthesisPaired(str3)) { cout <<"TRUE" <<endl;}



	/**** Test: ----   translate() ----------*/
	cout <<endl;
	const map<string, string> mp {
		{"read","citat"}, 
		{"write","pisat"},
		{"book","kniha"},
		{"I","ja"},
		{"you","ty"},
		{"he","on"},
		{"she","ona"},
		{"it","on"},
		{"a",""},
		{"an",""},
		{"the",""}
	};
	
                                                         
	list<string>testList { "I", "am", "reading", "a", "book" };
	testList = translate(mp, testList);
	printMap(mp);
	printBasicStl1D(testList);
	cout << "\n";


/**** Test: ------- sum(stream) ----*/
	string digits_0 = "10 20 30 40";
	istringstream streamDigits_0(digits_0);
	cout <<sum(streamDigits_0) <<endl;

	string digits_1("10 20 s dds30 m 40");
	istringstream streamDigits_1(digits_1);
	cout <<sum(streamDigits_1) <<endl;
	
	const char* digits_2 = "10 20 30 -40";
	istringstream streamDigits_2(digits_2);
	cout <<sum(streamDigits_2) <<endl;
	
	const string digits_3 = "10 20 ss30 -40";
	istringstream streamDigits_3(digits_3);
	cout <<sum(streamDigits_3) <<endl;
	
	string digits_4 = " ";
	istringstream streamDigits_4(digits_4);
	cout <<sum(streamDigits_4) <<endl;
	

	string digits_5 = "";
	istringstream streamDigits_5(digits_5);
	cout <<sum(streamDigits_5) <<endl;
	
	char digits_6[]= "10 20 30   -40";
	istringstream streamDigits_6(digits_6);
	cout <<sum(streamDigits_6) <<endl;


	/**** Test: ----- connectWithSpace() ---------***/
	const string a_0= "aaa";
	const int num = -20;
	cout<< connectWithSpace(a_0, num) <<endl;
		
	const char* a_1 = "aaa";
	const int num_1= 20;
	cout<< connectWithSpace(a_1, num_1) <<endl;

	const string a_2(" a b -");
	const int num_2 = -20;
	cout<< connectWithSpace(a_2, num_2) <<endl;
	
	char a_3[]= "aaa";
	int num_3 = 20;
	cout<< connectWithSpace(a_3, num_3) <<endl;
	
	const char a_4[] ="";
	int num_4 = -20;
	cout<< connectWithSpace(a_4, num_4) <<endl;


	
	/*** Test: ---- create2dVector() ---****/
	printBasicStl2D(create2dVector(2, 5, 10));
	printBasicStl2D(create2dVector(0, 0, 11));




/*** Test: --- reverse() --- ***/
	queue<int> q_1;
	for(int i = 1; i <= 10; i++) {
		q_1.push(i);
	}
	printQue(q_1);	
	reverse(q_1);
	printQue(q_1);



	/*** Test: --- 	queue reverse() ---***/
	list<int> lst_to_test_reverse_1;
	for(int i = 1; i <= 10; i++) {
		lst_to_test_reverse_1.push_front(i);
	}
	printBasicStl1D(lst_to_test_reverse_1);
	printQue(reverse(lst_to_test_reverse_1));

	list<int> lst_to_test_reverse_2;
	for(int i = 1; i<= 10;i++) {
		lst_to_test_reverse_2.push_back(i);
	}
	printBasicStl1D(lst_to_test_reverse_2);
	printQue(reverse(lst_to_test_reverse_2));



	return 0;
}






/********* ---------------- IMPLEMENTATION ----------*****/

queue<int>reverse(const list<int> & data) noexcept {
	list<int>::const_reverse_iterator cnItr;
		queue<int> qu_1;
	for(auto cnItr = data.crbegin(); cnItr != data.crend(); cnItr++) {
		qu_1.push(*cnItr);
	}	
	return qu_1;
}


void reverse(queue<int> & data) noexcept {
	stack<int> stkInt;
	while(!data.empty()) {
		stkInt.push(data.front());
		data.pop();
	}
	while(!stkInt.empty()) {
		data.push(stkInt.top()); 
		stkInt.pop();
	}
}

  
vector<vector<int>> create2dVector(const size_t size1, const size_t size2, const int value) noexcept {
  vector<int> v1D(size2, value);    
  vector<vector<int>> v2D(size1, v1D);    
  return v2D;    
}    
    

string connectWithSpace(const string & text, const int number) noexcept {
	string nwStr = text +" "+ to_string(number);
	return nwStr;
}


int sum(istringstream & text) noexcept {
	 int rslt = 0, num;

	 while(text >> num) {
		 rslt += num;
	 }
	 return rslt;
}


list<string> translate(const map<string, string> & translator, const list<string> & sentence) noexcept {
	map<string, string>::const_iterator itMap;
	list<string>::const_iterator itLst;
	list<string> rslt;
	int cntrl = 0;
	for(itLst = sentence.begin(); itLst != sentence.end(); itLst++) {
			for(itMap = translator.cbegin(); itMap != translator.cend(); itMap++) {
				if(*itLst == (itMap->first)) {
					cntrl = 1;
					rslt.push_back(itMap->second);
					break;
				}
				
			}
		if(!cntrl) { rslt.push_back("?"); }
		cntrl = 0;

	}

	return rslt;
}


bool areParenthesisPaired(const string & mathExpression) noexcept {
	
	if (mathExpression.empty()) {return true;}

	string::const_iterator itStr;
	stack<char> stkChar;

	for (itStr = mathExpression.begin(); itStr!=mathExpression.end(); itStr++)
	{
		switch(*itStr) {
			case '{':
				stkChar.push(*itStr);
				break;
			case '}':
				if(stkChar.empty()) { stkChar.push(*itStr); }
				else if (stkChar.top() == '{') { stkChar.pop(); }
				else { stkChar.push(*itStr); }
				break;
			case '(':
				stkChar.push(*itStr);
				break;
			case ')':
				if(stkChar.empty()) { stkChar.push(*itStr); }
				else if (stkChar.top() == '(') { stkChar.pop(); }
        else { stkChar.push(*itStr); }
        break;
			case '[':
      	stkChar.push(*itStr);
	      break;
			case ']':
				if(stkChar.empty()) { stkChar.push(*itStr); }
				else if (stkChar.top() == '[') { stkChar.pop(); }
				else { stkChar.push(*itStr); }
				break;
			default:
				continue;
		}
	}
		if (stkChar.empty()) { return true; }	
		else { return false; }
}



int multiply(int a,int b)noexcept{
	return a * b;
}

int maxValue(int a, int b) noexcept {
	if(a >= b) {  return a; }
	else { return b; }
}

int execute(int (*function)(int, int), int parameter1, int parameter2) {
	return function(parameter1, parameter2);
}



void doNotThrow() noexcept {
}

void throwInvalidArgument() {
    throw std::invalid_argument("popis vynimky"); 
}

void throwBadAlloc() {
    throw std::bad_alloc(); 
}

void throwOutOfRange() {
    throw std::out_of_range("popis vynimky");
}

ExceptionType thrownException(void (*function)()) noexcept {
	try {
		function();
	}
	catch(std::invalid_argument const& ex) {
		return ExceptionType::INVALID_ARGUMENT;
	}
	catch(std::bad_alloc const& ex) {
		return ExceptionType::BAD_ALLOC;
	}	catch(...) {
		return ExceptionType::UNKNOWN_EXCEPTION;
	}
	return ExceptionType::NO_EXCEPTION;
}



list<int> createList(const list<int>::size_type length, const list<int>::size_type indexOfOne) {
	list<int> lst_1;
	try {
		if (length <= indexOfOne) { throw IndexOutOfRangeException (length, indexOfOne); }
		else {
			while (lst_1.size() < length) {
				if (lst_1.size() == indexOfOne) { lst_1.push_back(1); }
				else { lst_1.push_back(0); }
			}
		}
	}
	
	catch (IndexOutOfRangeException& m){}
	return lst_1;
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
 


