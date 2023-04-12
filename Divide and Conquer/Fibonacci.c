#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        int a = fibonacci(n-1);
        int b = fibonacci(n-2);
        return a + b;
    }
}

int main() {
    int n = 10; // Example input value
    int result = fibonacci(n);
    printf("Fibonacci(%d) = %d\n", n, result);
    return 0;
}