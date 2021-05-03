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
    int search(vector<int>& nums, int target) {
        int iNumsSize = nums.size();
        if (iNumsSize == 1 && nums[0] == target) {
            return 0;
        } else if (iNumsSize == 1 && nums[0] != target) {
            return -1;
        }
        int cur = 0;
        if (nums[cur] == target) {
            return cur;
        } else if (nums[cur] < target) {
            // nums[cur] < target, front || not exist
            while (cur < iNumsSize - 1 && nums[cur] < nums[cur + 1]) {
                if (nums[cur] == target) {
                    return cur;
                } else if (nums[cur] < target) {
                    cur++;
                } else {
                    return -1;
                }
            }
            if (nums[cur] == target) {
                return cur;
            }
        } else {
            // back || not exist
            while (cur < iNumsSize - 1 && nums[cur] < nums[cur + 1]) {
                cur++;
            }
            cur++; // nums[0]
            if (cur == iNumsSize) {
                return -1;
            }
            while (cur < iNumsSize - 1 && nums[cur] < nums[cur + 1]) {
                if (nums[cur] == target) {
                    return cur;
                } else if (nums[cur] < target) {
                    cur++;
                } else {
                    return -1;
                }
            }
            if (nums[cur] == target) {
                return cur;
            }
        }
        return -1;
    }
};

int main(void) {
    vector<int> data = {1, 3};
    cout << Solution().search(data, 2);
    return 0;
}