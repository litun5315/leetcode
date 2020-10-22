/* Author: Teng Li
 * Email: i@terrytengli.com
 * Date: 2020-10-22
 */
#include <vector>
#include <stdio.h>

using namespace std;

void transpose(vector<vector<int> >& A) 
{
    int temp;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = i; j < A[i].size(); j++)
        {
            temp = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = temp;
        }
    }
}

void travelVector(vector<vector<int> > &V)
{
    for (int i = 0; i < V.size(); i++)
    {
        for (int j = 0; j < V[i].size(); j++)
        {
            printf("%d ", V[i][j]);
        }
        printf("\n");
    }
}

int main(void) 
{
    vector<vector<int> > v(3, vector<int>(3));

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            v[i][j] = i * 3 + j;
        }
    }
    travelVector(v);
    transpose(v);
    printf("\n");
    travelVector(v);

    return 0;
}