#include<iostream>
#include<vector>

using namespace std;

void function88(vector<int>& nums1, int m, vector<int>& nums2, int n);

int main(void) {
    // vector<int> nums1 = {1, 2, 3, 0, 0};
    // vector<int> nums2 = {2, 4, 7};
    // int m = 3;
    // int n = 3;
    vector<int> nums1 = {1, 0};
    vector<int> nums2 = {2};
    int m = 1;
    int n = 1;
    function88(nums1, m, nums2, n);
    cout << "flag1";
    for (int i = 0; i < m + n; i++) {
        cout << nums1[i] << "\t";
        // cout << "flag2";
    }
    cout << nums1.size();
    int tmp = 4;
    cout << tmp << ' ' << tmp-- << ' ' << --tmp <<endl;
    return 0;
}
void function88(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int cur = m + n - 1;
    m--;
    n--;
    while (n >= 0) {
        while (m >= 0 && nums1[m] > nums2[n]) {
            swap(nums1[cur--], nums1[m--]);
        }
        swap(nums1[cur--], nums2[n--]);
    }
}
// void function88(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//     int i = 0;
//     int j = 0;
//     if (n == 0) {
//        nums1.erase(nums1.begin() + m + n, nums1.begin() + nums1.size());
//        return ;
//     }
//     if (m == 0) {
//         for (int i = 0; i < n; i++) {
//             nums1.insert(nums1.begin() + i, nums2[i]);
//             nums1.erase(nums1.begin() + m + n, nums1.begin() + nums1.size());
//         }

//     }
//     while (j < n) {
//         cout << "flag --> " << nums1[i] << '\t' << nums2[j] << endl;
//         if (nums1[i] < nums2[j] && i < m) {
//             i++;
//         } else {
//             nums1.insert(nums1.begin() + i, nums2[j]);
//             j++;
//             i++;
//         }
//         cout << "i = " << i << "\t j = " << j << endl;
//     }
//     nums1.erase(nums1.begin() + m + n, nums1.begin() + nums1.size());
// }