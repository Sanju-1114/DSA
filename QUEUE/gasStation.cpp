// leetCode 134
#include <iostream>
#include <vector>
using namespace std;

// int canCompleteCircuit(vector<int>& gas , vector<int>& cost){
//     int totGas = 0 , totCost = 0;
//     for(int val : gas){
//         totGas += val;
//     }

//     for(int val : cost){
//         totCost += val;
//     }

//     if(totGas < totCost){
//         return -1;
//     }

//     // unique solution always exists
//     int start = 0 , currGas = 0;

//     for(int i=0 ; i<gas.size(); i++){
//         currGas += (gas[i] - cost[i]);
        
//         if(currGas < 0){
//             start = i+1;
//             currGas = 0;
//         }
//     }

//     return start;

// }

int canCompleteCircuit(vector<int>& gas , vector<int>& cost){  //O(n)
    int totGas = 0 , totCost = 0;

    // unique solution always exists
    int start = 0 , currGas = 0;

    for(int i=0 ; i<gas.size(); i++){
        totGas += gas[i];
        totCost += cost[i];

        currGas += (gas[i] - cost[i]);
        
        if(currGas < 0){
            start = i+1;
            currGas = 0;
        }
    }

    return totGas < totCost ? -1 : start;

}

int main() {
    vector<int> gas = {1, 2, 4, 5, 9};
    vector<int> cost = {3, 4, 1, 10, 1};

    cout << "Starting index to start tour :  " << canCompleteCircuit(gas , cost) << endl;

    return 0;
}