void sort_by_selection(float *array/*, int n , char *order*/)
{
    float current_value_to_sort, current_min, current_item;
    int n, i, j, index_of_last_min;

    n = sizeof(array) / sizeof(array[0]);

    for (i = 0; i < n; i++)
    {
        current_value_to_sort = array[i];
        current_min = current_value_to_sort;

        index_of_last_min = i;

        for (j = i + 1; j < n; j++)
        {
            current_item = array[j];

            if (current_min > current_item)
            {

                current_min = current_item;
                index_of_last_min = j;
            }
        }

        array[i] = current_min;
        array[index_of_last_min] = current_value_to_sort;
    }

}

