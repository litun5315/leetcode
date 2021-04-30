#include <iostream>
#include <vector>

using namespace std;

// TIME OUT
// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int iMaxArea = 0;
//         for (int i = 0; i < height.size(); i++) {
//             for (int j = i + 1; j < height.size(); j++) {
//                 int iCurArea = (j - i) * min(height[i], height[j]);
//                 if (iCurArea > iMaxArea) {
//                     iMaxArea = iCurArea;
//                 }
//             }
//         }
//         return iMaxArea;
//     }
// };

class Solution {
public:
    int maxArea(vector<int>& height) {
        int iMaxArea = 0;
        int iCurArea = 0;
        int iPre = 0;
        int iBack = height.size() - 1;
        while (iPre < iBack) {
            iCurArea = (iBack - iPre) * min(height[iPre], height[iBack]);
            if (height[iPre] < height[iBack]) {
                if (iCurArea > iMaxArea) {
                    iMaxArea = iCurArea;
                }
                iPre++;
            } else {
                if (iCurArea > iMaxArea) {
                    iMaxArea = iCurArea;
                }
                iBack--;
            }
        }
        return iMaxArea;
    }
};

int main(void) {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    // vector<int> height = {1, 1};
    // vector<int> height = {4, 3, 2, 1, 4};
    cout << Solution().maxArea(height);

    return 0;
}