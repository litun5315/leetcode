#include <stdio.h>

int max(char *s);
int main(void)
{
    int len;

    char *s = "";
    len = max(s);
    printf("%d", len);
//    printf("%d", s == '\0');
    return 0;
}

int max(char *s)
{
    char *start, *end, *add, *p;
    int Maxlen, addFlag, len;

    if (*s == '\0')
    {
        // printf("signal 1!\n");  // test
        return 0;
    }
    start = s;
    end = s;
    add = s + 1;
    Maxlen = 1;
    // printf("signal 2!\n");  // test
    while (*add != '\0' && *start != '\0')
    {
//        printf("signal 3!\n");  // test
        addFlag = 1;
        p = start;
        while (1)
        {
            if (*p == *add)
            {
                addFlag = 0;
                if (start != end)
                {
                    start++;
                }
                if (start == end && *start == *add && start < add)
                {
                    start++;
                    end++;
                }
                if (start == end && *start == *add && start == add)
                {
                    add++;
                }
                break;
            }
            if (p == end)
            {
                break;
            }
            p++;
        }
        if (addFlag == 1)
        {
            end = add;
            len = end - start + 1;
//            printf("%d", len); //test
            if (len > Maxlen)
            {
                Maxlen = len;
            }
            add++;
        }
    }
    return Maxlen;
}