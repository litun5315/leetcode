/* Author: Teng Li
 * Email: i@terrytengli.com
 * Date: 2020-10-22
 */

#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

void travelVector(vector<int> &V);
void travelVector2(vector<int> &V);
void fun1();
void fun2();
void fun3();
void fun4();

int main()
{
    fun4();
}

void travelVector(vector<int> &V)
{
    for (int i = 0; i < V.size(); i++)
    {
        printf("%d ", V[i]);
    }
    printf("\n");
}

void travelVector2(vector<int> &V)
{
    vector<int>::iterator it;
    for (it = V.begin(); it != V.end(); it++)
    {
        printf(" %d", *it);
    }
    printf("\n");
}

void fun1()
{
    vector<int> v1;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    for (int i  = 0; i < v1.size(); i++)
    {
        printf("%d ", v1[i]);
    }
    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        v1.pop_back();
    }
    for (int i  = 0; i < v1.size(); i++)
    {
        printf("%d ", v1[i]);
    }
}

void fun2()
{
    vector<int> v1;

    v1.push_back(12);
    v1.push_back(0);
    v1.push_back(2);
    v1.push_back(1);
    v1.push_back(130);

    sort(v1.begin(), v1.end());

    travelVector(v1);
}

void fun3()
{
    vector<int> v1;

    v1.push_back(12);
    v1.push_back(0);
    v1.push_back(2);
    v1.push_back(1);
    v1.push_back(130);

    reverse(v1.begin(), v1.end());

    travelVector2(v1);
}

void fun4()
{
    vector<vector<int> > v1(5, vector<int>(6));

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            v1[i][j] = 6 * i + j;
        }
    }

    // for (int i = 0; i < 5; i++)
    // {
    //     for (int j = 0; j < 6; j++)
    //     {
    //         printf("%d ", v1[i][j]);
    //     }
    //     printf("\n");
    // }
    vector<vector<int> >::iterator i;
    vector<int>::iterator j;
    for (i = v1.begin(); i != v1.end(); i++)
    {
        for(j = i->begin(); j != i->end(); j++)
        {
            printf("%d ", *j);
        }
        printf("\n");
    }
}