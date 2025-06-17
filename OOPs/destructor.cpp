#include <iostream>
#include <string>
using namespace std;

class Student{
public:
    string name;
    double *cgpaPtr;

    Student(string name, double cgpa){
        this->name = name;
        cgpaPtr = new double;
        *cgpaPtr = cgpa;
    }

    Student(Student &obj){ 
        this->name = obj.name;
        cgpaPtr = new double;
        *cgpaPtr = *obj.cgpaPtr;
    }

    //destructor
    ~Student(){
        cout << "Hi, I am Destructor";
        delete cgpaPtr;
    }

    void getInfo(){
        cout << "Name : " << name << endl;
        cout << "Cgpa : " << *cgpaPtr << endl;
    }
};

int main(){

    Student s1("Sanju", 9.5);
    s1.getInfo();
    
 


    return 0;
}
