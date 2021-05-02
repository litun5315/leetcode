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
    int removeElement(vector<int>& nums, int val) {
        int iNumsSize = nums.size();
        if (!iNumsSize) {
            return 0;
        }
        int slow = 0;
        int fast = 0;
        while (fast < iNumsSize) {
            if (nums[fast] != val) {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }

        return slow;
    }
};

int main(void) {
    vector<int> data = {3,2,2,3};
    int val = 3;

    printVector(data);

    int res = Solution().removeElement(data, val);

    printVector(data);

    cout << res;

    return 0;
}