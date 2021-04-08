/* Author: Teng Li
 * Email: i@terrytengli.com
 * Date: 2020-10-24
 */

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<int >&a, int dist, int m)
{
    int cnt = 0;
    int tar = a[0] + dist;
    for (int i = 0; i < a.size() - 1; i++)
    {
        if (a[i] < tar && a[i + 1] >= tar)
        {
            cnt++;
            tar = a[i + 1] + dist;
        }
    }
    return cnt >= m - 1;
}

int maxDistance(vector<int>& position, int m) 
{
    sort(position.begin(), position.end());
    if (m == 2)
    {
        return position[position.size() - 1] - position[0];
    }
    else
    {
        int r = (position[position.size() - 1] - position[0]) / (m - 1);
        int l = INT8_MAX;
        for(int i = 0; i < position.size() - 1; i++)
        {
            if (l > position[i + 1] - position[i])
            {
                l = position[i + 1] - position[i];
            }
        }
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (check(position, mid, m))
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return l - 1;
    }
}

int main(void)
{
    return 0;
}