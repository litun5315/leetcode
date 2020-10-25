/* Author: Teng Li
 * Email: i@terrytengli.com
 * Date: 2020-10-25
 */

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sortedSquares0(vector<int>& A) 
{
    vector<int> res(A.size());
    for (int i = 0; i < A.size(); i++)
    {
        res[i] = A[i] * A[i];
    }
    sort(A.begin(), A.end());
}

vector<int> sortedSquares(vector<int>& A)
{
    vector<int> res(A.size());
    int i, j, cur;
    i = 0;
    j = A.size() - 1;
    cur = j;
    for (; i <= j;)
    {
        if (A[i] * A[i] > A[j] * A[j])
        {
            res[cur] = A[i] * A[i];
            i++;
        }
        else
        {
            res[cur] = A[j] * A[j];
            j--;
        }
        cur--;
    }
    return res;
}

int main(void) 
{
    return 0;
}