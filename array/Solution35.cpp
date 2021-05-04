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
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1, ans = n;
        while (left <= right) {
            int mid = ((right - left) >> 1) + left;
            if (target <= nums[mid]) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};

int main(void) {
    return 0;
}