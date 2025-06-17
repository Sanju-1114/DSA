// CONSTRUCTOR
// Special method invoked automatically at the time of object creation.Used for initilisation.
    // Same name as class
    // Constructor doesn't have return type
    // Only called once (automatically) , at object creation
    // Memory allocation happens when constructor is called


#include <iostream>
#include <string>
using namespace std;
    
class Teacher{
private :
    double salary;  
    
public:


//    // 1.... Non-parameterized constructor
//    Teacher(){
//        // cout << "I am a Constructor" << endl;
//        dept = "CSE";   // default set department
//    }

    // // 2.... parameterized constructor
    // Teacher(string n , string d , string s , double sal){
    //     name = n;
    //     dept = d;
    //     subject = s;
    //     salary = sal;
    // }


// THIS keyword                                   parameterized
    // this->prop is same as *(this).prop
    Teacher(string name , string dept , string subject , double salary){
        this->name = name;
        this->dept = dept;
        this->subject = subject;
        this->salary = salary;
    }

    // 3.... copy constructor
    Teacher(Teacher &orgObj){
        cout << "I am custom copy constructor" << endl;
        this->name = orgObj.name;
        this->dept = orgObj.dept;
        this->subject = orgObj.subject;
        this->salary = orgObj.salary;
    }
 
    
    string name;
    string dept;
    string subject;
    
    void changeDept(string newDept){
        dept = newDept;
    }
    
    void getInfo(){
        cout << name << endl;
        cout << dept << endl;
        cout << subject << endl;
        cout << salary << endl;
    }

};

int main(){
    Teacher t1("Sanju" , "CSE" , "C++" , 250000);
    Teacher t2(t1);  // Custom copy constructor - invoke
    t2.getInfo(); 
   


    return 0;
}
    