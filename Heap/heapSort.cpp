#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void heapify(int i, vector<int> &arr, int n) {   // O(log n)
    int left = 2*i + 1;
    int right = 2*i + 2;
    int maxI = i;

    if(left < n && arr[left] > arr[maxI]) {   // for descending order change this > to <
        maxI = left;
    }

    if(right < n && arr[right] > arr[maxI]) {  // for descending order change this > to <
        maxI = right;
    }

    if(maxI != i) {
        swap(arr[i], arr[maxI]);
        heapify(maxI, arr, n);
    }
}

void heapSort(vector<int> &arr) {  // O(n*logn)
    int n = arr.size();

    //step 1 : Build maxHeap
    for(int i=n/2; i>=0; i--) {   // O(n*logn)
        heapify(i, arr, n);
    }

    //step 2: Taking ele to correct pos
    for(int i=n-1; i>=0; i--) {   // O(n*logn)
        swap(arr[0], arr[i]);
        heapify(0, arr ,i);
    }
}

int main() {
    //[1, 4, 2, 5, 3]
    vector<int> arr = {1, 4, 2, 5, 3};

    heapSort(arr);

    for(int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}