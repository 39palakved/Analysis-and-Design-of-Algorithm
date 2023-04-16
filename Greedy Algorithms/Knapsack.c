#include <stdio.h>

void knapsack(int n, float weight[], float value[], float capacity) {
    float x[20], total_value = 0;
    int i, j, u;
    u = capacity;

    for (i = 0; i < n; i++) {
        x[i] = 0.0;
    }

    for (i = 0; i < n; i++) {
        if (weight[i] > u) {
            break;
        } else {
            x[i] = 1.0;
            total_value += value[i];
            u -= weight[i];
        }
    }

    if (i < n) {
        x[i] = u / weight[i];
        total_value += x[i] * value[i];
    }

    printf("The selected elements are: ");
    for (i = 0; i < n; i++) {
        if (x[i] == 1.0) {
            printf("%d ", i + 1);
        } else if (x[i] > 0.0 && x[i] < 1.0) {
            printf("%d(%.2f) ", i + 1, x[i]);
        }
    }

    printf("\nTotal value: %.2f\n", total_value);
}

int main() {
    float weight[20], value[20], capacity;
    int n, i, j;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the weights and values of each item:\n");
    for (i = 0; i < n; i++) {
        scanf("%f %f", &weight[i], &value[i]);
    }
    printf("Enter the capacity of the knapsack: ");
    scanf("%f", &capacity);
    knapsack(n, weight, value, capacity);
    return 0;
}