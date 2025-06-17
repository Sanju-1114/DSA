// ABSTRACTION
// Hiding all unnecessary details & showing only the important parts.

// Way of implementing Abstration
    // access modifiers/specifiers
            // 1. private
            // 2. protected
            // 3. public
    // using *Abstract Classes*    
            // 1. Abstract Classes are used to provide a base class from which other classes can be derived.
            // 2. They cannot be instantiated (instance -> object) and are meant to be inherited.
            // 3. Abstract classes are typically used to define an interface for derived classes.         

#include<iostream>
#include<string>
using namespace std;

class Shape{   // Abstract class
    virtual void draw() = 0;   // pure virtual function
};

class Circle : public Shape {
public:
    void draw(){
        cout << "drawing a circle..." << endl;
    }
};
int main(){
    Circle c1;
    c1.draw();


    return 0;
}
