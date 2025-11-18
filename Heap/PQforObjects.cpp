#include <iostream>
#include <vector>
#include<queue>
using namespace std;


class Student {  // "<" overload
public:
    string name;
    int marks;

    Student(string name, int marks) {
        this->name = name;
        this->marks = marks;
    }

    bool operator < (const Student &obj) const {
        return this->marks < obj.marks;
    }

};

int main() {
    priority_queue<Student> pq;

    pq.push(Student("Sanju", 500));
    pq.push(Student("Vikash", 480));
    pq.push(Student("Vinay", 520));
    pq.push(Student("Ayush", 400));

    while(!pq.empty()) {
        cout << "Name = " << pq.top().name << " Marks = " << pq.top().marks << endl;
        pq.pop();
    }

    return 0;
}