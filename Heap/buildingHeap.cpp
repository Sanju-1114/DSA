#include <iostream>
#include <vector>
using namespace std;

class Heap {
    vector<int> vec; //CBT  (max heap)
public:
    void push(int val) {
        //step1 - push in heap (vector of heap)
        vec.push_back(val);                      // O(1)
        
        //step2 - fix heap
        int x = vec.size()-1; // child idx
        int parI = (x-1)/2; // parent idx

        while (parI >=0 && vec[x] > vec[parI]){   // O(logn)
            swap(vec[x], vec[parI]);
            x = parI;
            parI = (x-1)/2;
        }
    }   
    
    void heapify(int i) {   // i = parent Index (parI)
        if(i > vec.size()) {
            return;
        }

        int l = 2*i + 1;
        int r = 2*i + 2;

        int maxIdx = i;
        if(l < vec.size() && vec[l] > vec[maxIdx]) {
            maxIdx = l;
        }

        if(r < vec.size() && vec[r] > vec[maxIdx]) {
            maxIdx = r;
        }

        swap(vec[i], vec[maxIdx]);

        if(maxIdx != i) { // swapping with child node
            heapify(maxIdx);
        }
    }

    void pop() {
        // swap(root, last)  O(1)
        swap(vec[0], vec[vec.size()-1]);

        // delete the last Idx  O(1)
        vec.pop_back();

        // fix the heap  O(logn)   --->using heapify function
        heapify(0);

    }

    int top() {
        return vec[0]; // highest priority element
    }

    bool empty() {
        return vec.size() == 0;
    }
};

int main() {
    Heap heap;

    heap.push(9);
    heap.push(4);
    heap.push(8);
    heap.push(1);
    heap.push(2);
    heap.push(5);

    while(!heap.empty()) {
        cout << heap.top() << endl;
        heap.pop();
    }

    return 0;
}