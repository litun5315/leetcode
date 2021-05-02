#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int iNumsSize = nums.size();
        if (!iNumsSize) {
            return 0;
        }
        int slow = 1;
        int fast = 1;
        while (fast < iNumsSize) {
            if (nums[fast] != nums[fast - 1]) {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }
};

void printVector(vector<int>& data) {
    for (int & i : data) {
        cout << i << '\t';
    }
    cout << endl;
}

int main(void) {
    vector<int> data = {0,0,1,1,1,2,2,3,3,4};
    printVector(data);

    int iRes = Solution().removeDuplicates(data);

    cout << iRes << endl;
    printVector(data);
    return 0;
}