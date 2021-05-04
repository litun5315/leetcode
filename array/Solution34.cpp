#include <bits/stdc++.h>

using namespace std;

void printVector(vector<int>& data) {
    for (int & i : data) {
        cout << i << '\t';
    }
    cout << endl;
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int iNumsSize = nums.size();
        int iFirstMeet = -1;
        int iLastMeet = -1;
        int cur;
        if (iNumsSize < 1) {
            return {iFirstMeet, iLastMeet};
        }
        if (nums[0] > target || nums[iNumsSize - 1] < target) {
            return {iFirstMeet, iLastMeet};
        } else {
            cur = 0;
            while (cur < iNumsSize) {
                if (nums[cur] == target) {
                    iFirstMeet = cur;
                    break;
                } else if (nums[cur] < target) {
                    cur++;
                } else {
                    return {iFirstMeet, iLastMeet};
                }
            }
            cur = iNumsSize - 1;
            while (cur > -1) {
                if (nums[cur] == target) {
                    iLastMeet = cur;
                    break;
                } else if (nums[cur] > target) {
                    cur--;
                } else {
                    return {iFirstMeet, iLastMeet};
                }
            }
        }
        return {iFirstMeet, iLastMeet};
    }
};

int main(void) {
    vector<int> data = {};
    vector<int> res = Solution().searchRange(data, 10);
    printVector(res);
    return 0;
}