#include <iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextGreaterElement(vector<int> &arr){
    stack<int> s;
    vector<int> ans(arr.size() , 0);

    for(int i = arr.size()-1 ; i>=0 ; i--){
        while(s.size() > 0 && s.top() <= arr[i]){   // removing invalid elements (which never be ans)
            s.pop();
        }
        if(s.empty()){
            ans[i] = -1;
        }else{
            ans[i] = s.top();
        }

        s.push(arr[i]);
    }

    return ans;
}

int main(){
   vector<int> arr = {6, 8, 0, 1, 3};

    for(int val : nextGreaterElement(arr)){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}