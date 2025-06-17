#include <iostream>
#include <string>
using namespace std;

// class Student{
// public:
//     string name;
//     double cgpa;

//     Student(string name, double cgpa){
//         this->name = name;
//         this->cgpa = cgpa;
//     }

//     Student(Student &obj){
//         this->name = obj.name;
//         this->cgpa = obj.cgpa;
//     }

//     void getInfo(){
//         cout << "Name : " << name << endl;
//         cout << "Cgpa : " << cgpa << endl;
//     }
// };


// // SHALLOW COPY
// class Student{
// public:
//     string name;
//     double *cgpaPtr;

//     Student(string name, double cgpa){
//         this->name = name;
//         cgpaPtr = new double;
//         *cgpaPtr = cgpa;
//     }

//     Student(Student &obj){
//         this->name = obj.name;
//         this->cgpaPtr = obj.cgpaPtr;
//     }

//     void getInfo(){
//         cout << "Name : " << name << endl;
//         cout << "Cgpa : " << *cgpaPtr << endl;
//     }
// };

// DEEP COPY
class Student{
public:
    string name;
    double *cgpaPtr;

    Student(string name, double cgpa){
        this->name = name;
        cgpaPtr = new double;
        *cgpaPtr = cgpa;
    }

    Student(Student &obj){                 // change only in this constructor b/w shallow and deep copy
        this->name = obj.name;
        cgpaPtr = new double; 
        *cgpaPtr = *obj.cgpaPtr;
    }

    void getInfo(){
        cout << "Name : " << name << endl;
        cout << "Cgpa : " << *cgpaPtr << endl;
    }
};


int main(){
    Student s1("Sanju", 9.5);
    Student s2(s1);

    s1.getInfo();
    *(s2.cgpaPtr) = 9.8;
    s1.getInfo();

    return 0;
}
