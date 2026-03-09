#include <stdio.h>

void knapsack(int n, float weight[], float profit[], float capacity) {
    float x[20], tp = 0;
    int i;
    float u = capacity;

    for (i = 0; i < n; i++) {
        x[i] = 0.0;
    }

    for (i = 0; i < n; i++) {
        if (weight[i] > u) {
            break;
        } else {
            x[i] = 1.0;
            tp = tp + profit[i];
            u = u - weight[i];
        }
    }

    if (i < n) {
        x[i] = u / weight[i];
        tp = tp + (x[i] * profit[i]);
    }

    printf("\nThe result vector is :- ");
    for (int j = 0; j < n; j++) {
        printf("%f\t", x[j]);
    }

    printf("\nMaximum profit is :- %f\n", tp);
}

int main() {
    int num;
    float weight[20], profit[20], ratio[20], temp, capacity;

    printf("Enter the no. of objects :- ");
    scanf("%d", &num);

    printf("\nEnter the weights and profits of each object :-\n");
    for (int i = 0; i < num; i++) {
        scanf("%f %f", &weight[i], &profit[i]);
    }

    printf("\nEnter the knapsack capacity :- ");
    scanf("%f", &capacity);

    for (int i = 0; i < num; i++) {
        ratio[i] = profit[i] / weight[i];
    }

    // Sorting by ratio (descending)
    for (int i = 0; i < num; i++) {
        for (int j = i + 1; j < num; j++) {
            if (ratio[i] < ratio[j]) {
                temp = ratio[j]; ratio[j] = ratio[i]; ratio[i] = temp;
                temp = weight[j]; weight[j] = weight[i]; weight[i] = temp;
                temp = profit[j]; profit[j] = profit[i]; profit[i] = temp;
            }
        }
    }

    knapsack(num, weight, profit, capacity);
    return 0;
}