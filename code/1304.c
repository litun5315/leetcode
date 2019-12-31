/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumZero(int n, int* returnSize){
    *returnSize = n;
    int *a = malloc(sizeof(int) * n);
    int max = n / 2;
    int cnt = max;
    for (int i = 0; i < cnt; i++) {
        a[i * 2] = max;
        a[i * 2 + 1] = 0 - max;
        max --;
    }
    if (n % 2 == 1) a[n - 1] = 0;
    return a;
}