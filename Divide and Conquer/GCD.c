#include <stdio.h>

// Recursive function to find the GCD of two integers using divide-and-conquer
int gcd(int a, int b) {
    if (b == 0) {
        return a; // base case: gcd(a,0) = a
    }
    else {
        return gcd(b, a % b); // recursive case: gcd(a,b) = gcd(b,a%b)
    }
}

// main function to test the gcd function
int main() {
    int a, b;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    int result = gcd(a, b);
    printf("The GCD of %d and %d is %d\n", a, b, result);
    return 0;
}