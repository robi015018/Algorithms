#include <stdio.h>

struct Activity 
{
    int start;
    int finish;
};

void swap(struct Activity *a, struct Activity *b) 
{
    struct Activity temp = *a;
    *a = *b;
    *b = temp;
}
void sortActivities(struct Activity activities[], int n) 
{
    for (int i = 0; i < n-1; i++) 
    {
        for (int j = 0; j < n-i-1; j++) 
        {
            if (activities[j].finish > activities[j+1].finish) 
            {
                swap(&activities[j], &activities[j+1]);
            }
        }
    }
}

void activitySelection(struct Activity activities[], int n) 
{
    sortActivities(activities, n);

    printf("Selected activities (start, finish):\n");

    int i = 0;
    printf("(%d, %d)\n", activities[i].start, activities[i].finish);

    for (int j = 1; j < n; j++) 
    {
        if (activities[j].start >= activities[i].finish) 
        {
            printf("(%d, %d)\n", activities[j].start, activities[j].finish);
            i = j;
        }
    }
}

int main() 
{
    struct Activity activities[] = 
    {
        {1, 3}, {2, 4}, {0, 6}, {5, 7}, {8, 9}, {5, 9}
    };
    int n = sizeof(activities) / sizeof(activities[0]);

    activitySelection(activities, n);
    return 0;
}