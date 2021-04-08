#include<iostream>
#include<string>
#include<vector>

using namespace std;

string logestPalindrome(string s);

int main(void) {
    string s = "abdgabba";
    cout << logestPalindrome(s) << endl;

    return 0;
}

// 动态规划方法
string logestPalindrome(string s) {
    int lengthS = s.length();
    int maxLen = 0;
    int beginIdx = 0;
    vector<vector<bool>> flag(lengthS, vector<bool>(lengthS));
    for (int j = 0; j < lengthS; j++) {
        for (int i = 0; i <= j; i++) {
            if (s[i] != s[j]) {
                flag[i][j] = false;
            } else if (j - i < 3) {
                flag[i][j] = true;
            } else {
                flag[i][j] = flag[i + 1][j - 1];
            }
            if (flag[i][j] == true && j - i + 1 > maxLen) {
                maxLen = j - i + 1;
                beginIdx = i;
            }
        }
    }
    return s.substr(beginIdx, maxLen);
}