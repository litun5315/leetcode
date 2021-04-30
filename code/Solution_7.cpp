#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int iRes = 0;
        int iLastX;
        iLastX = x % 10;
        if (!x) {
            return x;
        }
        while (!iLastX) {
            x /= 10;
            iLastX = x % 10;
        }
        while (x) {
            iRes *= 10;
            iRes += iLastX;
            if (iRes > INT_MAX/10 || (iRes == INT_MAX / 10 && iLastX > 7)) return 0;
            if (iRes < INT_MIN/10 || (iRes == INT_MIN / 10 && iLastX < -8)) return 0;
            x /= 10;
            iLastX = x % 10;
        }

        return iRes;
    }
};



int main(void)
{
    cout << Solution().reverse(-90100);
}