/* Author: Teng Li
 * Email: i@terrytengli.com
 * Date: 2020-10-23
 */

// getWinner is my initial solution, and which is out of time
// getWinner2 is my refined solution, which is passed on leetcode.com

#include <stdio.h>
#include <vector>

using namespace std;

void travelVect(vector<int >& arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int getWinner(vector<int >& arr, int k)
{
    int win_num = 0;
    int temp;
    // printf("win_num = %d, k = %d", win_num, k);
    while(win_num != k || win_num < arr.size())
    {
        if (arr[0] > arr[1])
        {
            win_num++;
            arr.push_back(arr[1]);
            arr.erase(arr.begin() + 1);
            // travelVect(arr); // test
        }
        else
        {
            win_num = 1;
            arr.push_back(arr[0]);
            arr.erase(arr.begin());
            // travelVect(arr); // test
        } 
    }
    return arr[0];
}

int getWinner2(vector<int>& arr, int k)
{
    int win_nums = 0;
    int ans = arr[0];
    int i = 1;
    while (i < arr.size() && win_nums < k)
    {
        if (ans > arr[i])
        {
            win_nums++;
            i++;
        }
        else
        {
            ans = arr[i];
            win_nums = 1;
            i++;
        }
    }
    return ans;
}

int main(void)
{
    // int arr_tmp[] = {2,1,3,5,4,6,7}; // 7
    int arr_tmp[] = {3, 2, 1}; // 3
    // int arr_tmp[] = {1, 11, 22, 33, 44, 55, 66, 77, 88, 99}; // 10
    vector<int> arr(arr_tmp, arr_tmp + 3);
    printf("start:\n");
    travelVect(arr); // test
    int k = 10;
    int res = getWinner2(arr, k);
    printf("result = %d\n", res);
    return 0;
}