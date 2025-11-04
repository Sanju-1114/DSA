// LeetCode problem 
#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
using namespace std;

void helper(vector<vector<int>> &maze , int row , int col ,string path ,vector<string> &ans){
    int n = maze.size();
    if (row < 0 || col < 0 || row >= n || col >= n || maze[row][col] == 0 || maze[row][col] == -1){
            return;
    }

    if(row == n-1 && col == n-1){
        ans.push_back(path);
        return;
    }
    
    maze[row][col] = -1; // visited

    helper(maze , row+1 , col , path+"D" , ans);   //DOWN
    helper(maze , row-1 , col , path+"U" , ans);    //UP
    helper(maze , row , col-1 , path+"L" , ans);  //LEFT
    helper(maze , row , col+1 , path+"R" , ans);   //RIGHT

    maze[row][col] = 1;  // unvisited
}

vector<string> findPath(vector<vector<int>> &maze){
    int n = maze.size();

    vector<string> ans; 
    string path = "";
    
    helper(maze , 0 , 0 , path ,ans);

    return ans;
}

int main(){

    vector<vector<int>> maze = {
                               {1,0,0,0},
                               {1,1,0,1},
                               {1,1,0,0},
                               {0,1,1,1}
                            };
     
    vector<string> ans = findPath(maze);

    for(string path : ans){
        cout << path << endl;
    }
   

    return 0;
}