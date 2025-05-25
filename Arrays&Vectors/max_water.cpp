#include <iostream>
#include <vector>
using namespace std;

// int maxArea(vector<int>& height) {
//         int maxWater=0;
//         for(int i=0;i<height.size();i++){
//             for(int j=i+1;j<height.size();j++){
//               int width = j-i;                                 //This is Brute force appproch methode
//               int ht = min(height[i],height[j]);
//               int area = width*ht;
//               maxWater = max(maxWater,area);
//             }
//         }
//         return maxWater;
// }

// most optimised (2 pointer approach)

int maxArea(vector<int> &height)
{
  int maxWater = 0;
  int n = height.size();
  int i = 0, j = n - 1;
  while (i < j)
  {
    int width = j - i;
    int ht = min(height[i], height[j]);
    int currWater = width * ht;
    maxWater = max(maxWater, currWater);

    height[i] < height[j] ? i++ : j--;
  }
  return maxWater;
}
int main()
{
  vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};

  cout << "Max water = " << maxArea(height) << endl;

  return 0;
}