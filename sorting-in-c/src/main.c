#include <stdio.h>
#include <stdlib.h> //for exit
#include <string.h>

#include "../include/utils_fncts.h"
#include "../include/sort_by_selection.h"

int main()
{
    char *sorting_method;

    while (1)
    {
        sorting_method = choose_sorting_method();

        if (strcmp(sorting_method, "Exit the program") == 0)
        {
            break;
        }
        else if (strcmp(sorting_method, "Selection Sort") == 0)
        {
            // === "Selection Sort"
            // get array to sort
            // printf("%f", generate_random_array_to_sort()[0]);
            // printf("%f", generate_random_array_to_sort()[1]);
            // printf("%f", generate_random_array_to_sort()[2]);
            float array[] = generate_random_array_to_sort();
            if (!array)
            {
                printf("Error: invalid input or memory allocation failed.\n");
                return 1;
            }

            /////////////
            int size = sizeof(array) / sizeof(array[0]);
            printf("size = %d", size);
            for (int i = 0; i < size; i++)
            {
                printf("the array[%d] = %.3f", i, array[i]);
            }
            exit(0);
            /////////////

            //print_array(array);
            // apply selection function
            // sort_by_selection(array/*, char *order*/);
            sort_by_selection(array);

            //
            print_array(array);

            //

            break;
        }
        else if (strcmp(sorting_method, "Bubble Sort") == 0)
        {
            // === "Bubble Sort"

            break;
        }
        else
        {
            // Error: invalid selection
        }
    } // while(1)

    // printf("sorting_method = %s", sorting_method);

    return 0;
}