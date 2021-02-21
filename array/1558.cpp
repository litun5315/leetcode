#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int res = 0, iLeft, iRight, iLeftOdd, iLeftEven, iRightOdd, iRightEven;
        for (int i = 0; i < arr.size(); i++) {
            iLeft = i + 1;
            iRight = arr.size() - i;
            iLeftEven = (iLeft + 1) / 2;
            iLeftOdd = iLeft / 2;
            iRightEven = (iRight + 1) / 2;
            iRightOdd = iRight / 2;
            res += arr[i] * (iLeftOdd * iRightOdd + iLeftEven * iRightEven);
        }
        return res;
    }
};

class Solution1 {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {

        int res = 0;
        for(int i = 0; i < arr.size(); i ++){
            int left = i + 1, right = arr.size() - i,
                left_even = (left + 1) / 2, right_even = (right + 1) / 2,
                left_odd = left / 2, right_odd = right / 2;
            res += (left_even * right_even + left_odd * right_odd) * arr[i];
        }
        return res;
    }
};


int main(void) {
    vector<int> arr = {1, 4, 2, 5, 3};
    Solution solution = Solution();
    // Solution1 solution = Solution1();
    cout << solution.sumOddLengthSubarrays(arr) << endl;
    return 0;
}

