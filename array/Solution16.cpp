#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int iNumSize = nums.size();
        int iMinDiff = INT_MAX;
        int iMinDiffTemp;
        int iSumTemp;
        int iSum;
        sort(nums.begin(), nums.end());
        for (int iF = 0; iF < iNumSize - 2; iF++) {
            for (int iM = iF + 1; iM < iNumSize - 1; iM++) {
                for (int iE = iM + 1; iE < iNumSize; iE++) {
                    iSumTemp = nums[iF] + nums[iM] + nums[iE];
                    iMinDiffTemp = iSumTemp - target;
                    if (abs(iMinDiffTemp) < iMinDiff) {
                        iSum = iSumTemp;
                        iMinDiff = abs(iMinDiffTemp);
                    }
                }
            }
        }

        return iSum;
    }
};

int main(void) {
    vector<int> data = {-1,2,1,-4};

    int res = Solution().threeSumClosest(data, 1);

    cout << res;

    return 0;
}