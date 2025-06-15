// ENCAPSULATION
// Encapsulation is wrapping up of data and member functions in a single unit called class.


#include <iostream>
    #include<string>
    using namespace std;
    
    class Teacher{
    private :
        double salary;    
    public:  
        // properties / attributes
        string name;
        string dept;
        string subject;
        
    
        //methods / member functions      [functions inside the class]
        void changeDept(string newDept){
            dept = newDept;
        }

        // setter
        void setSalary(double s){
            salary = s;
        }

        // getter
        double getSalary(){
            return salary;
        }
    
    };
    
    int main(){
        Teacher t1;
        t1.name = "Sanju";
        t1.dept = "CSE";
        t1.subject = "C++";
        
    
        cout << t1.name << endl;
       
    
    
        return 0;
    }
    