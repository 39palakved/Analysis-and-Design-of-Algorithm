#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 100

int matrixChainOrder(int p[], int n)
{
    int m[MAX_SIZE][MAX_SIZE];
    int i, j, k, l, q;

    for (i = 1; i <= n; i++)
        m[i][i] = 0;

    for (l = 2; l <= n; l++) {
        for (i = 1; i <= n - l + 1; i++) {
            j = i + l - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    return m[1][n];
}

int main()
{
    int p[] = { 30, 35, 15, 5, 10, 20, 25 };
    int n = sizeof(p) / sizeof(p[0]);

    printf("Minimum number of multiplications is %d\n", matrixChainOrder(p, n - 1));

    return 0;
}