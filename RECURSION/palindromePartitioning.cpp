// LeetCode problem 131
#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
#include<set>
using namespace std;

bool isPalin(string part){
    // for(int i=0 , j=part.size() ; i<=j ; i++ , j--){
    //     if(part[i] != part[j]){
    //         return false;
    //     }
    // }
    // return true;

    // OR

    string partReverse = part;
    reverse(partReverse.begin() , partReverse.end());
    return part == partReverse;
}




void getAllParts(string s , vector<string> &partitions,vector<vector<string>> &ans  ){
    if(s.size() == 0){
        ans.push_back(partitions);
        return;
    }

    for (int i = 0; i < s.size(); i++){
        string part = s.substr(0, (i+1));

        if(isPalin(part)){
            partitions.push_back(part);
            getAllParts(s.substr(i+1 , s.size()), partitions , ans);
            partitions.pop_back();
        }
    }
    
    
}

vector<vector<string>> partion(string s){
    vector<vector<string>> ans;
    vector<string> partitions;

    getAllParts(s , partitions , ans);

    return ans;
}

int main(){
    string s = "aab";

    for(vector<string> part : partion(s)){
        for(string eachPart : part){
            cout << eachPart << " ";
        }
        cout << endl;
    }

    return 0;
}