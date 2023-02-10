/* * Written by : MAGED AL-WARD; * DATE: 02/10/2022
* A solution to assignment 1 from the subject programming techinque
*
*/


#include <iostream>
#include <climits>
#include <string>


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









struct Position
{
	int x;
	int y;
};


// Datum
struct Date {
    int year;  // rok
    int month; // mesiac
    int day;   // den
};

// Uspesnost vykonania funkcie
enum class Result {
    SUCCESS, // funkcia vykonana uspesne
    FAILURE  // chyba pri vykonavani funkcie
};


// pass by reference
void print(const Position &position)
{
	std::cout << "x: ";
	std::cout << position.x;
	std::cout << ", y:";
	std::cout << position.y;
	std::cout << " ";
	std::cout << std::endl;
};


//pass by pointer
void print(const Position *position)
{
        std::cout << "x: ";
        std::cout << (*position).x;
        std::cout << ", y:";
        std::cout << position->y;
        std::cout << " ";
        std::cout << std::endl;
};


//reading from standard inputs
void readFromStandardInput(Position *position)
{
	std::cin >> (*position).x >> (*position).y;
}



//find the maximum
int maximum(const int *data, std::size_t length, Result *result) {
    int len = (int) length;
    int max = *data;
    while(len != 0) {
        
        if(*data > max)
        {
            max = *data;
        }
        len--;
        data++;
        
        
    }
    
    return max;
}





//find number of digits needed to write a  number.
int numDigits(int value) {
	std::string st = std::to_string(value);
	int numDigit = st.size();
	return numDigit;
};


bool isInLeapYear(const Date *date)
{
   if(!((*date).year % 4) && (!((*date).year % 100))) 
   {
	   if (!((*date).year % 400))
	   {
		   return true;
	   } 
	   else
	   {
		return false;
	   }
   }
   else if (!((*date).year % 4) && ((*date).year % 100))
   {
	   return true;
   }
   else
   {
	   return false;
   }
	
    
}



bool isValid(const Date *date) {
	if ((*date).month > 12 || (*date).month < 1)
	{
		return false;
	}
	else if (!(isInLeapYear(date))&& (*date).month == 2 && (*date).day > 28)
	{
		return false;
	} 
	else if (((*date).month == 4 || (*date).month == 6 || (*date).month == 9 || (*date).month == 11 ) && (*date).day > 30)
	{
		return false;
	}
	else if ((*date).day > 31 || (*date).day < 1) 
	{
		return false;
	}
	else
	{
		return true;
	}
};


Date* create(int day, int month, int year) {
	Date* date = new Date();
	date->day = day;
	date->month = month;
	date->year = year;
	return date;
};


void destroy(Date **date) 
{
	delete(*date);
	*date = nullptr;
	
};


int main()
{
	Position pos;
	pos.x = 120;
	pos.y = 50;

	//Test print(&position); pass by reference.
	setColor(BLACK);
	setBackGroundColor(bG_YELLOW);
	print(pos);
	resetColor();

	
	
	//Testing print(*position); pass by pointer(address);	
	Position *posPointer = &pos;

        setColor(RED_PURBLE_BINK);
        setBackGroundColor(bG_WHITE);
	print(posPointer);
	resetColor();


	//Testing readFromStandardInput();
	Position anotherPos;
	Position *posPoi = &anotherPos;
	readFromStandardInput(posPoi);
	setColor(WHITE);
	setBackGroundColor(bG_BLACK);
	print(posPoi);
	resetColor();
	

	Result result = Result::SUCCESS;
	Result* rsltPoi = &result;
	int arr[5] = {-2, 0,  -1,  -5};
	int* data = &arr[0];
	int x  = maximum(data, 4, rsltPoi);

	std::cout << "return: " << x;

	switch (result)
	{
		case Result::SUCCESS:
			std::cout << "\tResult: SUCCESS";
			break;
		case Result::FAILURE:
			std::cout << "\tResult: FAILURE";
	}
	
	std::cout << std::endl;
	
	//testing numDigits function
	int i = -25266;	
	setColor(YELLOW);
	std::cout << "Number of chars are needed: ";
	std::cout << numDigits(i) << std::endl;
	


	Date d = {100,  13, 111};
        setColor(GREEN);
        //setBackGroundColor(bG_CYAN);
	
	//testing if the year is leap
	if (isInLeapYear(&d))
	{
		std::cout << "Year is leap" << std::endl;
	}
	else
	{
		std::cout << "Year is not leap" << std::endl;
	}


	setColor(RED);
	setBackGroundColor(bG_BLACK);
	//testing isValid function
     if (isValid(&d))
     {
             std::cout << "Date is Valid" << std::endl;
     }
     else
     {
             std::cout << "Date is not valid" << std::endl;
     }


	//testing create() function
	Date* date = create(25, 30 , 2050);
	setColor(WHITE);
	setBackGroundColor(bG_BLUE);
	std::cout << "Date: " << std::to_string(date->day) << "/" << std::to_string(date->month) << "/";
	std::cout << std::to_string(date->year) << std::endl;
	resetColor(); 
	
        setColor(WHITE);
 	setBackGroundColor(bG_BLACK);
	destroy(&date);
        std::cout << "Date after calling destroy(): ";
	std::cout << date;
	std::cout << "\n";
        resetColor();

	
	//testing destroy function
	std::cout  << "I will try to destroy  nullptr\n";
	Date* nulDatePointer = nullptr; 
	std::cout <<"nulDatePointer before calling destroy() is:  ";
	std::cout << nulDatePointer << std::endl;
	destroy(&nulDatePointer);
	std::cout << "nulDatePointer After using destroy() is: ";
	std::cout << nulDatePointer << std::endl;
};

