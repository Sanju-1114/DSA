// INHERITANCE
// When properties and member functions of base class are passed on to the derived class

//Mode of Inheritance
/*
+---------------------+---------------------+---------------------+---------------------+
|                     | Derived Class       |  Derived Class      |   Derived Class     |
+---------------------+---------------------+---------------------+---------------------+
| Base Class (Parent) |  Private Mode       |    Protected Mode   |    Public mode      |
+---------------------+---------------------+---------------------+---------------------+
| Private             |    Not Inherited    |   Not Inherited     |    Not Inherited    |
| Protected           |      Private        |     Protected       |      Protected      |
| Public              |      Private        |     Protected       |        Public       |
+---------------------+---------------------+---------------------+---------------------+
*/

#include <iostream>
#include <string>
#include<string>
using namespace std;

class Person {
public:
    string name;
    int age;
    
    Person (string name , int age){
        this->name = name;
        this->age = age;
    }
  

};

// class Student : private Person {
class Student : public Person {
public:
    int rollNo;

    Student(string name, int age , int rollNo) : Person(name,age ){
        this->rollNo = rollNo;
    }

    void getInfo(){
        cout << "Name : " << name <<endl;
        cout << "Age : " << age <<endl;
        cout << "RollNo : " << rollNo <<endl;
    }
};

int main(){
   Student s1("Sanju" , 19 , 51);
   s1.getInfo();

   cout << s1.name ;

    return 0;
}


// Remove word wrap to see this properly
/*
================================================================================================================================================================================
|     Type of Inheritance     |              Description               |                   Syntax Example                     |              Output / Structure               |
|-----------------------------|----------------------------------------|------------------------------------------------------|-----------------------------------------------|
| Single Inheritance          | One base class and one derived class   | class A {};                                          | A → B                                          |
|                             |                                        | class B : public A {};                               |                                               |
|-----------------------------|----------------------------------------|------------------------------------------------------|-----------------------------------------------|
| Multiple Inheritance        | One derived class inherits from        | class A {}; class B {};                              | A + B → C                                      |
|                             | multiple base classes                  | class C : public A, public B {};                     |                                               |
|-----------------------------|----------------------------------------|------------------------------------------------------|-----------------------------------------------|
| Multilevel Inheritance      | Inheritance in multiple levels         | class A {};                                          | A → B → C                                      |
|                             | (derived from derived)                 | class B : public A {};                               |                                               |
|                             |                                        | class C : public B {};                               |                                               |
|-----------------------------|----------------------------------------|------------------------------------------------------|-----------------------------------------------|
| Hierarchical Inheritance    | Multiple classes inherit from one base | class A {};                                          | A → B, A → C                                   |
|                             | class                                  | class B : public A {}; class C : public A {};        |                                               |
|-----------------------------|----------------------------------------|------------------------------------------------------|-----------------------------------------------|
| Hybrid Inheritance          | Combination of multiple inheritance    | class A {}; class B : public A {};                   | Mix (e.g., Multiple + Multilevel)             |
|                             | types in one program                   | class C {}; class D : public B, public C {};         |                                               |
================================================================================================================================================================================
*/
