#include <stdio.h>

struct Item
{
    int weight;
    int profit;
    float ratio;
};

void sortItems(struct Item items[], int n)
{
    struct Item temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (items[j].ratio < items[j + 1].ratio)
            {
                temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

float fractionalKnapsack(struct Item items[], int n, int capacity)
{
    float totalProfit = 0.0;
    sortItems(items, n);
    for (int i = 0; i < n; i++)
    {
        if (items[i].weight <= capacity)
        {
            capacity -= items[i].weight;
            totalProfit += items[i].profit;
        }
        else
        {
            totalProfit += items[i].ratio * capacity;
            break;
        }
    }
    return totalProfit;
}

int main()
{
    int n, capacity;
    printf("Enter number of items: ");
    scanf("%d", &n);
    struct Item items[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter weight and profit of item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].profit);
        items[i].ratio =
            (float)items[i].profit / items[i].weight;
    }
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);
    float maxProfit =fractionalKnapsack(items, n, capacity);
    printf("Maximum Profit = %.2f\n", maxProfit);
    return 0;
}