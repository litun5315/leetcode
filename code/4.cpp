#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>

using namespace std;

double solution4(vector<int>& num1, vector<int>& num2);

int main(void) {
    vector<int> a = {1, 2};
    vector<int> b = {3, 4};
    cout << solution4(a, b);
    return 0;
}

double solution4(vector<int>& num1, vector<int>& num2)  {
    int m = num1.size();
    int n = num2.size();
    if (m > n) {
        return solution4(num2, num1);
    }
    // 左边的size
    int sizeLeft = m + (n - m + 1) / 2;
    
    int left = 0;
    int right = m;
    while (left < right) {
        int center1 = left + (right - left + 1) / 2;
        int center2 = sizeLeft - center1;
        
        // cout << center1 << "\t" << center2 << endl;
        if (num1[center1 - 1] > num2[center2]) {
            right = center1 - 1;
        } else {
            left = center1;
        }
    }
    // here, 分割线到了合适的位置
    int maxNum1Left = (left == 0) ? (INT_MIN) : (num1[left - 1]);
    int minNum1Right = (left == m) ? (INT_MAX) : (num1[left]);
    int maxNum2Left = ((sizeLeft - left) == 0) ? (INT_MIN) : (num2[(sizeLeft - left) - 1]);
    int minNum2Right = ((sizeLeft - left) == n) ? (INT_MAX) : (num2[sizeLeft - left]);

    if ((m + n)  % 2) {
        return max(maxNum1Left, maxNum2Left);
    } else {
        return (double) (max(maxNum1Left, maxNum2Left) + min(minNum1Right, minNum2Right)) / 2;
    }

}