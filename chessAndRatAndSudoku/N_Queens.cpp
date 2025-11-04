// LeetCode problem 51
#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
using namespace std;                // TC : O(n!)                          

bool isSafe(vector<string> &board , int row , int col , int n){   // check safe to place or not
    
    // Check horizontally
    for (int j = 0; j < n; j++){
        if(board[row][j] == 'Q'){ 
             return false;
        }
    }

    // Check Vertically
    for (int i = 0; i < n; i++){
        if(board[i][col] == 'Q'){    
             return false;
        }
    }

    // Check left side Diagonal
    for(int i=row , j = col ; i>=0 && j>=0 ; i-- ,j--){
        if(board[i][j] == 'Q'){    
            return false;
       }
    }

    // Check right side Diagonal
    for(int i=row , j = col ; i>=0 && j<n ; i-- ,j++){
        if(board[i][j] == 'Q'){    
            return false;
       }
    }

    return true;
}

void nQueens(vector<string> &board , int row ,int n ,vector<vector<string>> &ans){
    if(row == n){
         ans.push_back({board});
         return;
    } 


    for (int j = 0; j < n; j++){
        if(isSafe(board , row , j , n)){      
            board[row][j] = 'Q';                   // Set Queen
            nQueens(board , row+1 , n , ans);      // for next Queen
            board[row][j] = '.';              //Backtracking     // Again empty it for next step 
        }
    }
    
}

vector<vector<string>> solveNQueens(int n){
    vector<string> board(n , string(n,'.'));  // board initially
    vector<vector<string>> ans;              // To store possible answers

    nQueens(board , 0 , n , ans);           // Call to place all queens and return ans
    return ans;                             // return ans to main function
}

int main(){
    int n = 4;

    for(vector<string> val : solveNQueens(n)){
        for(string str : val){
            cout << str << endl;
        }
        cout << endl;
    }
    
    return 0;
}