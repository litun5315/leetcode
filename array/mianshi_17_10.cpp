/* Author: Teng Li
 * Email: i@terrytengli.com
 * Date: 2020-10-23
 */
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int max_cnt(vector<int>& nums) 
{
    vector<int> flag(nums.size(), 0);
    sort(nums.begin(), nums.end());
    int i, j;
    i = 0;
    j = 1;
    while(j < nums.size())
    {
        if (nums[j] == nums[i])
        {
            flag[i]++;
            j++;
        }
        else
        {
            i = j;
            j++;
        }
    }
    int max_idex = 0;
    for (int i = 0; i < flag.size(); i++)
    {
        if (flag[i] > flag[max_idex])
        {
            max_idex = i;
        }
    }
    for (int i = max_idex + 1; i < flag.size(); i++)
    {
        if (flag[i] == flag[max_idex])
        {
            return -1;
        }
    }
    return nums[max_idex];
}
int majorityElement(vector<int>& nums) 
{
    vector<int> flag(nums.size(), 0);
    sort(nums.begin(), nums.end());
    int i, j;
    i = 0;
    j = 1;
    while(j < nums.size())
    {
        if (nums[j] == nums[i])
        {
            flag[i]++;
            j++;
        }
        else
        {
            i = j;
            j++;
        }
    }
    for (int i = 0; i < flag.size(); i++)
    {
        if ((flag[i] + 1) > (nums.size() / 2))
        {
            return nums[i];
        }
    }
    return -1;
}

int main(void)
{
    // int a[] = {1, 2, 5, 9, 5, 9, 5, 5, 5};
    // int a[] = {3, 2};
    // int a[] = {3, 3, 2, 2};
    int a[] = {2,2,1,1,1,2,2};
    vector<int> v(a, a+7);
    int idx;
    idx = majorityElement(v);
    printf("%d", idx);
    return 0;
}