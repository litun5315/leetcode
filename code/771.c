#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // test example 1
    // char *J = "aA";
    // char *S = "aAAbbbb";
    // test example 2
    // char *J = "z";
    // char *S = "ZZ";
    // int nCnt;

    nCnt = numJewelsInStones(J, S);

    printf("%d", nCnt);

    return 0;
}

int numJewelsInStones(char * J, char * S)
{
    int cnt;
    char *pJ, *pS;

    cnt = 0;

    for (pJ = J; *pJ != '\0'; pJ++)
    {
        for (pS = S; *pS != '\0'; pS++)
        {
            if (*pS == *pJ)
            {
                cnt++;
            }
        }
    }

    return cnt;
}