#include<iostream>
#include<vector>
#include<list>

using namespace std;

int main(){
    // pair<int,int> p = {1,5};
    // pair<char,int> p = {'S',5};
    // pair<string , int> p = {"Sanju" , 5};
    // pair<int , pair<char,int>> p = {1, {'a',3}};

    // cout << p.first <<","<< p.second.first << ","<< p.second.second << endl;
     
    vector<pair<int,int>> vec ={{1,2}};
    vec.push_back({3,4});    // -> we need to send as pair
    vec.emplace_back(5,6);  // -> in-place object create  => no need to send as pair
    for(pair<int,int> val : vec){
        cout << val.first << " " << val.second << endl;
    }

    return 0;
}
