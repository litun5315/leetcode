#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// Fail: no repeated results
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> res;
//         int iNRes = 0;
//         for (int i = 0; i < nums.size() - 3; i++) {
//             for (int j = i + 1; j < nums.size() - 2; j++) {
//                 for (int k = j + 1; k < nums.size() - 1; k ++) {
//                     if (!(nums[i] + nums[j] + nums[k])) {
//                         vector<int> subRes;
//                         subRes.push_back(nums[i]);
//                         subRes.push_back(nums[j]);
//                         subRes.push_back(nums[k]);
//                         iNRes++;
//                         res.push_back(subRes);
//                     }
//                 }
//             }
//         }

//         return res;
//     }
// };
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int iSizeNums = nums.size();
        int iE;
        sort(nums.begin(), nums.end());
        // -4, -1, -1, 0, 1, 2
        for (int iF = 0; iF < iSizeNums - 2; iF++) {
            if (iF != 0 && nums[iF] == nums[iF-1]) {
                continue;
            }
            iE = iSizeNums - 1;
            for (int iM = iF + 1; iM < iSizeNums - 1; iM++) {
                if (iM != iF + 1 && nums[iM] == nums[iM - 1]) {
                    continue;
                }
                while (iM < iE && nums[iF] + nums[iM] + nums[iE] > 0) {
                    iE--;
                }
                if (iM == iE) {
                    break;
                }
                if (nums[iF] + nums[iM] + nums[iE] == 0) {
                    res.push_back({nums[iF], nums[iM], nums[iE]});
                }
            }
        }

        return res;
    }
};


void printVector(vector<vector<int>>& v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << '\t';
        }
        cout << endl;
    }
}

int main(void) {
    // vector<int> data = {-1,0,1,2,-1,-4};

    vector<int> data = {-1,0,1,2,-1,-4};
    
    vector<vector<int>> testData = Solution().threeSum(data);
    printVector(testData);

    return 0;
}