#include <stdio.h>

int factorial(int n) {
    if(n == 0 || n==1) {
        return 1;
    } 
    else {
        int m = n / 2;
        int left = factorial(m);
        int right = factorial(n - m);
        return left * right;
    }
}

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    printf("%d! = %d\n", n, factorial(n));
    return 0;
}