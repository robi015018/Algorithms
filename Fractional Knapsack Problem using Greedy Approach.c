#include <stdio.h>

struct Item 
{
    int value;
    int weight;
};

float ratio(struct Item a) 
{
    return (float)a.value / a.weight;
}
void swap(struct Item* a, struct Item* b) 
{
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}
void sortItems(struct Item items[], int n) 
{
    for (int i = 0; i < n-1; i++) 
    {
        for (int j = i+1; j < n; j++) 
        {
            if (ratio(items[i]) < ratio(items[j])) 
            {
                swap(&items[i], &items[j]);
            }
        }
    }
}
float fractionalKnapsack(int capacity, struct Item items[], int n) 
{
    sortItems(items, n);

    float total_value = 0.0;

    for (int i = 0; i < n; i++) 
    {
        if (capacity >= items[i].weight) 
        {
            // Take whole item
            capacity -= items[i].weight;
            total_value += items[i].value;
        } else 
        {
            total_value += items[i].value * ((float)capacity / items[i].weight);
            break;
        }
    }

    return total_value;
}

int main() 
{
    struct Item items[] = { {60, 10}, {100, 20}, {120, 30} };
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 50;

    float max_value = fractionalKnapsack(capacity, items, n);
    printf("Maximum value in Knapsack = %.2f\n", max_value);

    return 0;
}