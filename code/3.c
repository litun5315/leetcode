#include <stdio.h>

int main(void)
{
    int len;

    // test example is as follow
    // char *s = "pwwpwd";
    // char *s = "abcabcbb";
    // char *s = "bbbbbbbbb";
    char *s = "";
    len = fun(s);
    printf("%d", len);
    return 0;
}

int fun(char *s)
{
    char *start, *end, *add, *p;
    int Maxlen, addFlag, len;

    if (s == '\0')
    {
        // printf("signal 1!\n");  // test
        return 0;
    }
    start = s;
    end = s;
    add = s + 1;
    Maxlen = 1;
    // printf("signal 2!\n");  // test
    while (add != '\0')
    {
        printf("signal 3!\n");  // test
        addFlag = 1;
        p = start;
        while (p != end)
        {
            p++;
            if (*p == *add)
            {
                addFlag = 0;
                start++;
                break;
            }
        }
        if (addFlag == 1)
        {
            add++;
            end = add;
            len = 1;
            for (p = start; p != end; p++)
            {
                len++;
            }
            if (len > Maxlen)
            {
                Maxlen = len;
            }
        }
    }
    return Maxlen;
}