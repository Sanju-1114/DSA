#include <iostream>
#include <vector>
#include<queue>
using namespace std;

struct ComparePair {
    bool operator () (pair<string, int> &p1, pair<string, int> &p2) {
        return p1.second < p2.second;
    }
};

int main() {
     priority_queue<pair<string, int>, vector<pair<string, int>>, ComparePair > pq;  // default - maxHeap --> based on "first"

    pq.push(make_pair("Sanju", 500));
    pq.push(make_pair("Vikash", 480));
    pq.push(make_pair("Vinay", 520));
    pq.push(make_pair("Ayush", 400));

    while(!pq.empty()) {
        cout << "Name = " << pq.top().first << " Marks = " << pq.top().second << endl;
        pq.pop();
    }

    return 0;
}