// STATIC KEYWORD
    // Static Variables
        // 1. Variables declared as static in a function are created and initialised once for the lifetime
        //    of the program. (in a Function)
        // 2. Static Variables in a class are created & initialised once. They are shared by all the
        //    obj1ects of the class. (in Class)
    // Static obj1ects



#include <iostream>
#include <string>
#include<string>
using namespace std;

// void fun(){
//     int x=0;
//     cout << "x : "<< x << endl; // normal it always print x=0
//     x++;
    
//     static int x=0;
//     cout << "x : "<< x << endl;  // it incresed by 1 every time
//     x++;
// }

// class A {
// public:
//     int x;

//     void incX(){  // it creates different x at different memory locations for every object
//         x++;
//     }  
// };


class ABC {
public:
    ABC(){
        cout << "Constructor \n";
    }
    ~ABC(){
        cout << "destructor \n";
    }
};


int main(){
    //  fun();
    //  fun();
    //  fun();

    // A obj1;
    // A obj2;
    // obj1.x = 100;
    // obj2.x = 200;
    // cout << obj1.x << endl;
    // cout << obj2.x << endl;
    
    // if (true){
    //     ABC obj;   // ends before main fxn
    // }
    // cout << "End of main fxn \n";
    
    if (true){
        static ABC obj;  // stay till the end of the program -> ends after main fxn
    }
    cout << "End of main fxn \n";
    


    return 0;
}
