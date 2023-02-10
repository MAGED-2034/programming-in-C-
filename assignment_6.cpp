/*
 * Written by: MAGED ALWARD
  *
 * Relation: assigment_6 from "Programming Techniques". 
 * Uinversity: STU
 * Note: The identation is 2 
 * Editor: VIM
 * To successfull compilation and running:
    -compile it with c++ version 11 and above.
 * ------------ --------------------"String.cpp implementation--------------------
 */

#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

//--------- 1. ULOHA------.
int sucet(int a=10, int b=20) {
    return a + b;
}


//----------------- 2. ULOHA.
class String {
  public:

    //--a
    String(){
      this->data = new char[1];
    }

    //--b
    String(const char * st){
      if(st){
        this->data = new char[strlen(st) + 1];
        strcpy(this->data, st);
        (this->data)[strlen(st)] = '\0';
      }
    }

    //--c
    String(const String& str){
      this->data = new char[str.getLength() + 1];
       strcpy(this->data,str.data);
      (this->data)[str.getLength()] = '\0';
    }

    //--d
    size_t getLength() const {
      return(strlen(this->data));
    } 
    
    //--e
    char getChar(size_t index) const {
      if(strlen(this->data)){
        return((this->data)[index]);
      }
      return '\0';
    }
       
    //--f
    const char * toCString() const{
      return this->data;
    }
    
    //--g
    void set(const char *text) {
      delete(this->data);
      this->data = new char[strlen(text) + 1];
      strcpy(this->data, text);
      (this->data)[strlen(text)] = '\0';
    }

    //--h
    void append(const char *text) {
      size_t len  = strlen(text) + strlen(this->data) + 1;
      char* tempStr = new char[len];
      strcpy(tempStr, this->data);
      delete(this->data);
      this->data = new char[len];
      strcpy(this->data, tempStr);
      delete(tempStr);
      strcat(this->data, text);
    }

     //--i 
     ~String() {};

  private:
    char *data;
};

//--test function
void basicTestString() {
  const String str1;
  
  const String str2("hello world");
  String str3("hello world");
  String str4("");
  String str5(nullptr);
  String str6(str2);
  size_t length1 = str1.getLength();
  assert(length1 == 0);
  size_t length2 = str2.getLength();
  assert(length2 == 11);
  
  const char *cstr1 = str1.toCString();
  assert(cstr1[0] == '\0');
  const char *cstr2 = str2.toCString();
  assert(std::strcmp(cstr2, "hello world") == 0);
  str3.set("HELLO WORLD AGAIN");
  assert(std::strcmp(str3.toCString(), "HELLO WORLD AGAIN") == 0);



}


int main() {

  //--test 1.ULOHA 
  cout<<sucet()<<endl;

  //--test 2.ULOHA
  basicTestString();

  return 0; 
}





