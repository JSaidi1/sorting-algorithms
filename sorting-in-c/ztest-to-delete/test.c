#include <stdio.h>
#include <stdlib.h>

float* createArray(int n) {
    float* arr = malloc(n * sizeof(float));  // allocate memory
    if (arr == NULL) {
        perror("Failed to allocate memory");
        exit(1);
    }

    for (int i = 0; i < n; i++)
        arr[i] = i * 1.1f;

    return arr;  // return pointer to first element
}

int main() {
    printf("================");
    printf("Test:");
    printf("================\n");
    int size = 5;
    float* myArray = createArray(size);

    for (int i = 0; i < size; i++)
        printf("%.2f ", myArray[i]);
    printf("\n");

    free(myArray);  // remember to free the memory
    return 0;
}
