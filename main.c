#include <stdio.h>
#include <stdlib.h>

int select_comp = 0, shell_comp = 0, select_swap = 0, shell_swap = 0, ans_int = 0;

void swap(double *a, double *b)
{
    double c = *a;
    *a = *b;
    *b = c;
    return;
}

void selection_sort(double *array, int size)
{
    int min_index;
    for (int i = 0; i < size - 1; i++)
    {
        min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            select_comp++;
            if (array[j] < array[min_index])
                min_index = j;
        }
        if (i != min_index)
            select_swap++;
        swap(&array[i], &array[min_index]);
    }
    return;
}

void shell_sort(double *array, int size)
{
    int j;
	for (int shift = size / 2; shift > 0; shift >>= 1)
		for (int i = shift; i < size; i++)
        {
			for (j = i - shift; shell_comp++, j >= 0 && array[j] > array[j + shift]; j -= shift)
			{
                swap(&array[j], &array[j + shift]);
                shell_swap++;
			}
        }
    return;
}

void generate_random_array(int size, double *array)
{
    printf("Randomly generated array:\n\n");
    for (int i = 0; i < size; i++)
    {
        array[i] = 1;
        for (int j = 0; j < 3; j++)
            array[i] *= (double)(rand()) / (rand() + 1);
        array[i] *= rand() * 2 - RAND_MAX;
        if (ans_int)
            printf("%lf\n", array[i]);
    }
    printf("\n");
    return;
}

void generate_ordered_array(int size, double *array)
{
    printf("Sorted by non-decreasing array:\n\n");
    for (int i = 0; i < size; i++)
    {
        array[i] = i - size / 2;
        if (ans_int)
            printf("%lf\n", array[i]);
    }
    printf("\n");
    return;
}

void generate_reversed_array(int size, double *array)
{
    printf("Sorted by non-increasing array:\n\n");
    for (int i = 0; i < size; i++)
    {
        array[i] = -(i - size / 2);
        if (ans_int)
            printf("%lf\n", array[i]);
    }
    printf("\n");
    return;
}

void print_array(int size, double *array)
{
    for (int i = 0; i < size; i++)
        printf("%lf\n", array[i]);
    printf("\n");
    return;
}

int main()
{
    int N;
    char answer = 'N';
    printf("Enter size of array: ");
    scanf("%d", &N);
    printf("Do you want to print all arrays? (Y/N) ");
    scanf("\n%c", &answer);
    printf("\n");
    if (answer == 'Y')
        ans_int = 1;
    double *array = (double*) malloc(N * sizeof(double));
    printf("\n*SELECTION SORT*\n\n");
    generate_ordered_array(N, array);
    selection_sort(array, N);
    printf("Compare number: %d \nSwap number: %d\n\n", select_comp, select_swap);
    select_comp = select_swap = 0;
    if (ans_int)
    {
        printf("Sorted by selection sort array:\n\n");
        print_array(N, array);
    }
    generate_reversed_array(N, array);
    selection_sort(array, N);
    printf("Compare number: %d \nSwap number: %d\n\n", select_comp, select_swap);
    select_comp = select_swap = 0;
    if (ans_int)
    {
        printf("Sorted by selection sort array:\n\n");
        print_array(N, array);
    }
    for (int i = 0; i < 2; i++)
    {
        generate_random_array(N, array);
        selection_sort(array, N);
        printf("Compare number: %d \nSwap number: %d\n\n", select_comp, select_swap);
        select_comp = select_swap = 0;
        if (ans_int)
        {
            printf("Sorted by selection sort array:\n\n");
            print_array(N, array);
        }
    }
    printf("*SHELL SORT*\n\n");
    generate_ordered_array(N, array);
    shell_sort(array, N);
    printf("Compare number: %d \nSwap number: %d\n\n", shell_comp, shell_swap);
    shell_comp = shell_swap = 0;
    if (ans_int)
    {
        printf("Sorted by shell sort array:\n\n");
        print_array(N, array);
    }
    generate_reversed_array(N, array);
    shell_sort(array, N);
    printf("Compare number: %d \nSwap number: %d\n\n", shell_comp, shell_swap);
    shell_comp = shell_swap = 0;
    if (ans_int)
    {
        printf("Sorted by shell sort array:\n\n");
        print_array(N, array);
    }
    for (int i = 0; i < 2; i++)
    {
        generate_random_array(N, array);
        shell_sort(array, N);
        printf("Compare number: %d \nSwap number: %d\n\n", shell_comp, shell_swap);
        shell_comp = shell_swap = 0;
        if (ans_int)
        {
            printf("Sorted by shell sort array:\n\n");
            print_array(N, array);
        }
    }
    free(array);
    return 0;
}
