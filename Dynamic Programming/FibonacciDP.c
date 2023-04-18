// Fibonacci DP in C

#include<stdio.h>

int fib(int n) {
    int fibArray[n+1];
    fibArray[0] = 0;
    fibArray[1] = 1;
    for(int i = 2; i <= n; i++) {
        fibArray[i] = fibArray[i-1] + fibArray[i-2];
    }
    return fibArray[n];
}

int main() {
    int n = 10;
    printf("%d\n", fib(n));
    return 0;
}
/*The time complexity of this implementation is O(n), as we only need to loop through the array once.

a recursive implementation of the Fibonacci sequence has a time complexity of O(2^n), as each call to the function results in two more calls. This can become very inefficient as n increases.

Here's an example recursive implementation for comparison:*/

int fib(int n) {
    if (n <= 1)
        return n;
    return fib(n-1) + fib(n-2);
}