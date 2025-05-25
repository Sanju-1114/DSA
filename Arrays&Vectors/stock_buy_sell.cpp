#include<iostream>
#include<vector>
using namespace std;


int maxProfit(vector<int>& prices) {
     int maxPft=0;
     int bestBuy=prices[0]; 

     for(int i=0;i<prices.size();i++){
        if(prices[i]>bestBuy){
            maxPft = max(maxPft,prices[i]-bestBuy);                //calculate max profit
        }
        bestBuy = min(bestBuy,prices[i]);                         //calculate best day to buy
     }  
     return maxPft;
}


int main(){
   vector<int>prices={7,1,5,3,6,4};
   
   cout<<"Max profit = "<< maxProfit(prices);               // function call and return max profit
   
    return 0;
}
