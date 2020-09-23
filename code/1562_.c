# include <stdio.h>
#include <stdlib.h>

int findLatestStep(int* arr, int arrSize, int m){
    // 初始化endpoints
    int **endpoints = malloc(sizeof(int *) * arrSize);
    for (int i = 0; i < arrSize; i++)
    {
        endpoints[i] = malloc(sizeof(int) * 2);
    }
    for (int i =0; i < arrSize; i++) {
        endpoints[i][0] = -1;
        endpoints[i][1] = -1;
//        printf("%d\t%d\n", endpoints[i][0], endpoints[i][1]);
    }
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == 1)
        { // 左边界，考虑一边即可
            if (endpoints[arr[i]][0] == -1)
            {
                endpoints[arr[i] - 1][0] = arr[i];
                endpoints[arr[i] - 1][1] = arr[i];
            }
            else
            {
                endpoints[arr[i] -1][0] = arr[i];
                endpoints[arr[i] - 1][1] = endpoints[arr[i]][1];
            }

        }
        else if (arr[i] == arrSize)
        { // 右边界
            if (endpoints[arr[i] - 2][0] == -1)
            {
                endpoints[arr[i] - 1][0] = arr[i];
                endpoints[arr[i] - 1][1] = arr[i];
            }
            else
            {
                endpoints[arr[i] - 1][0] = endpoints[arr[i] - 2][0];
                endpoints[arr[i] - 1][1] = arr[i];
            }
        }
        else
        { // 非边界
            if (endpoints[arr[i] - 2][0] == -1 && endpoints[arr[i]][0] == -1)
            { // 左右皆0
                endpoints[arr[i] - 1][0] = arr[i];
                endpoints[arr[i] - 1][1] = arr[i];
            }
            else if (endpoints[arr[i] - 2][0] == -1 && endpoints[arr[i]][0] != -1)
            { // 左为0，右不为0
                endpoints[arr[i] - 1][0] = arr[i];
                endpoints[arr[i] - 1][1] = endpoints[arr[i]][1];
            }
            else if (endpoints[arr[i] - 2][0] != -1 && endpoints[arr[i]][0] == -1)
            { // 左不为0，右为0
                endpoints[arr[i] - 1][0] = endpoints[arr[i] - 2][0];
                endpoints[arr[i] - 1][1] = arr[i];
            }
            else
            { // 左右皆不为0
                endpoints[arr[i] - 1][0] = endpoints[arr[i] - 2][0];
                endpoints[arr[i] - 1][1] = endpoints[arr[i]][1];
            }
        }
        // test
        for (int j = 0; j < arrSize; j++) {
            printf("第%d个：(%d, %d)\t", j+1, endpoints[j][0], endpoints[j][1]);
        }
        printf("\n");
    }
    int flag = -1;
    // flag = -1 -- 初始化
    // flag = 0 -- 开始存在
    // flag = i -- 关闭后的结果
    return flag;
}

int main(void) {
    int arr[] = {3, 5, 1, 2, 4};
    findLatestStep(arr, 5, 1);
    return 0;
}