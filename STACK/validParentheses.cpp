// LeetCode 20

#include <iostream>
#include<stack>
using namespace std;

// //Without stack
// bool isValid(string s) {
//     int count1 = 0, count2 = 0, count3 = 0;
//     for(int i=0 ; i<s.length() ; i++){
//         if(s[i] == '(') count1++;
//         if(s[i] == ')') count1--;
//         if(s[i] == '{') count2++;
//         if(s[i] == '}') count2--;
//         if(s[i] == '[') count3++;
//         if(s[i] == ']') count3--;                
//     }

//     if(count1 == 0 && count2 == 0 && count3 == 0) return true;

//     return false;
// }


//Using stack
bool isValid(string s) {
    stack <char> st;
    for(int i=0 ; i < s.size() ; i++){
        if(s[i] == '(' || s[i] =='{' || s[i] =='['){  //  opening
            st.push(s[i]);
        }else{
            if(st.size() == 0){
                return false;
            }

            if((st.top() == '(' &&  s[i] == ')') ||
                (st.top() == '{' &&  s[i] == '}')||
                (st.top() == '[' &&  s[i] == ']')){
                    st.pop();
            }
            else{               // no match
                return false;
            }
        }

    }
        return st.size() == 0 ;    
}

int main() {

    int ans = isValid("()[]{}");
    cout << ans;

    return 0;
}