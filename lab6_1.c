/*Write a program to find the maximum profit nearest to but not
exceeding the given knapsack capacity using the Fractional Knapsack algorithm.*/

#include <stdio.h>
#include <stdlib.h>


struct Item {
    int item_id;
    float item_profit;
    float item_weight;
    float profit_weight_ratio;
};

void heapify(struct Item items[], int n, int i);
void swap(struct Item *a, struct Item *b);


float fractionalKnapsack(struct Item items[], int n, float capacity) {
   
    for (int i = 0; i < n; i++) {
        items[i].profit_weight_ratio = items[i].item_profit / items[i].item_weight;
    }

   
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(items, n, i);
    }

    float maxProfit = 0.0;

    while (capacity > 0 && n > 0) {
        swap(&items[0], &items[n - 1]);
        n--;

        struct Item currentItem = items[n];

        if (currentItem.item_weight <= capacity) {
            maxProfit += currentItem.item_profit;
            capacity -= currentItem.item_weight;
            printf("%d %.6f %.6f 1.000000\n", currentItem.item_id, currentItem.item_profit, currentItem.item_weight);
        } else {
            float fraction = capacity / currentItem.item_weight;
            maxProfit += fraction * currentItem.item_profit;
            capacity = 0;
            printf("%d %.6f %.6f %.6f\n", currentItem.item_id, currentItem.item_profit, currentItem.item_weight, fraction);
        }

        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(items, n, i);
        }
    }

    return maxProfit;
}


void heapify(struct Item items[], int n, int i) {
    int largest = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if (leftChild < n && items[leftChild].profit_weight_ratio > items[largest].profit_weight_ratio) {
        largest = leftChild;
    }

    if (rightChild < n && items[rightChild].profit_weight_ratio > items[largest].profit_weight_ratio) {
        largest = rightChild;
    }

    if (largest != i) {
        swap(&items[i], &items[largest]);
        heapify(items, n, largest);
    }
}


void swap(struct Item *a, struct Item *b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    for (int i = 0; i < n; i++) {
        printf("Enter the profit and weight of item no %d: ", i + 1);
        scanf("%f %f", &items[i].item_profit, &items[i].item_weight);
        items[i].item_id = i + 1;
    }

    float capacity;
    printf("Enter the capacity of knapsack: ");
    scanf("%f", &capacity);

    float maxProfit = fractionalKnapsack(items, n, capacity);

    printf("Maximum profit: %.6f\n", maxProfit);

    return 0;
}