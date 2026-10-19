# include <stdio.h>
# include <stdlib.h>

void powerset(int goal, int *ar, int *subset, int size, int i, int sum, int len)
{
    if (sum == goal)
    {
        int j = 0;
        while(j < size)
        {
            printf("%d, ", subset[j]);
            j++;
        }
        printf("\n");
        return;
    }
    if (sum > goal)
        return;
    if (i == len)
        return;
    powerset(goal, ar, subset, size, i + 1, sum, len);
    subset[size] = ar[i];
    size++;
    sum += ar[i];
    powerset(goal, ar, subset, size, i + 1, sum, len);
}

int main(int argc, char **argv)
{
    int i = 1;
    int j = 0;
    int *ar = calloc(argc - 1, sizeof(int));
    while ( i < argc)
    {
        ar[j] = atoi(&argv[i][0]);
        i++;
        j++;
    }
    int size = 0;
    int *subset = malloc(sizeof(int) * (argc - 1));
    powerset(ar[0], &ar[1], subset, size, 0, 0, argc - 2);
    free(subset);
    free(ar);
}