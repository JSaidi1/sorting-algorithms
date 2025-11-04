#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *choose_sorting_method()
{
    char sorting_method_nmber[11];

    printf("\nSorting method:\n");
    printf("1) Selection Sort\n");
    printf("2) Bubble Sort\n");
    printf("==>Set the number of the choosen sort (set 0 to exit): ");

    scanf("%10s", sorting_method_nmber);

    if (strcmp(sorting_method_nmber, "0") == 0)
    {
        printf("You have chosen 'Exit the program', Bye, see you!\n");
        return "Exit the program";
    }
    else if (strcmp(sorting_method_nmber, "1") == 0)
    {
        printf("You have chosen 'Selection Sort':\n");
        return "Selection Sort";
    }
    else if (strcmp(sorting_method_nmber, "2") == 0)
    {
        printf("You have chosen 'Bubble Sort':\n");
        return "Bubble Sort";
    }
    else
    {
        printf("Error: invalid selection '%s'. Please set a valid number form the list above!'\n", sorting_method_nmber);
        return "Error: invalid selection";
    }
}

float *generate_random_array_to_sort()
{
    int size;
    float min, max;

    // Ask for array size and range
    printf("Enter array size: ");
    scanf("%d", &size);

    printf("Enter minimum value: ");
    scanf("%f", &min);

    printf("Enter maximum value: ");
    scanf("%f", &max);

    if (size <= 0 || min > max)
    {
        printf("Invalid input.\n");
        return NULL;
    }

    // float arr[size];
    float *arr = (float *)malloc(size * sizeof(float));
    if (!arr)
        return NULL; // memory allocation failed

    // Seed the random number generator
    srand((unsigned)time(NULL));

    // Generate random float array
    for (int i = 0; i < size; i++)
    {
        float scale = rand() / (float)RAND_MAX; // 0.0 to 1.0
        arr[i] = min + scale * (max - min);
    }

    // Print the array
    printf("\nGenerated float array:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%.3f ", arr[i]);
    }
    printf("\n");

    /////////////
    //int n = sizeof(arr) / sizeof(arr[0]);
    printf("size = %d", size);
    for (int i = 0; i < size; i++)
    {
        printf("the array[%d] = %.3f", i, arr[i]);
    }
    //exit(0);
    /////////////

    return arr;
}

// void print_array(float arr[], int n)
void print_array(float *array)
{
    int n = sizeof(array) / sizeof(array[0]);
    printf("{");
    for (int i = 0; i < n; i++)
    {
        printf("%g", array[i]); // %g removes unnecessary zeros
        if (i < n - 1)
            printf(", ");
    }
    printf("}\n");
}
