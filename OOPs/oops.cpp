// Four pillars of OOPs
    // 1. Encapsulation
    // 2. Abstraction
    // 3. Inheritance
    // 4. Polymorphism

#include <iostream>
#include<string>
using namespace std;

class Teacher{
public:  
    // properties / attributes
    string name;
    string dept;
    string subject;
    double salary;

    //methods / member functions      [functions inside the class]
    void changeDept(string newDept){
        dept = newDept;
    }

};

int main(){
    Teacher t1;
    t1.name = "Sanju";
    t1.dept = "CSE";
    t1.subject = "C++";
    t1.salary = 25000000.34;

    cout << t1.name << endl;
   


    return 0;
}
