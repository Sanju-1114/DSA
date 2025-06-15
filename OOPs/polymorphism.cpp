// POLYMORPHISM
// Polymorphism is the ability of objects to take on *different forms* or behave in different ways 
// *depending on the context* in which they are used.

// TYPES
// Compile Time Polymorphism
    // example -> function overloading
// Run Time Polymorphism
    // example 1 -> function overriding
                 // Parent and Child both contain the same function with different implementation.
                 // The parent class function is said to be overridden.
    // example 2 -> Virtual functions
                 // A virtual function is a member function that you expect to be redefined in derived
                 // classes.
                 // PROPERTIES OF VIRTUAL FUNCTIONS
                    // 1. Virtual functions are dynameic in nature.
                    // 2. Defined by the keyword "virtual" inside a base class and are always declared
                    //    with a base class and overridden in a child class.
                    // 3. A Virtual function is called during Runtime.            

#include <iostream>
#include <string>
#include<string>
using namespace std;

class Student {
public:
    string name;
    // int age;
    // int rollNo;

    Student(){
        cout << "non-parameterized \n";
    }
    Student(string name){
        cout << "parameterized \n";
    }

    void getInfo(){
        cout << "Name : " << name <<endl;
    }
};

int main(){
   Student s1;
//    Student s1("Sanju");
   s1.name = "Sanju";
   s1.getInfo();


    return 0;
}
