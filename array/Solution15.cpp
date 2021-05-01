#include <iostream>
#include <vector>

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
        int iNRes = 0;
        for (int i = 0; i < nums.size() - 3; i++) {
            for (int j = i + 1; j < nums.size() - 2; j++) {
                for (int k = j + 1; k < nums.size() - 1; k ++) {
                    if (!(nums[i] + nums[j] + nums[k])) {
                        vector<int> subRes;
                        subRes.push_back(nums[i]);
                        subRes.push_back(nums[j]);
                        subRes.push_back(nums[k]);
                        iNRes++;
                        res.push_back(subRes);
                    }
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
    vector<int> data = {-1,0,1,2,-1,-4};
    
    // vector<vector<int>> testData = Solution().threeSum(data);
    // printVector(testData);
    vector<int> data1 = {0, 1, 12};
    vector<int> data2 = {12, 1, 0};
    cout << (data1 == data2);

    return 0;
}