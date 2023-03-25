#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>

void Sort(int *vet, int *L, int *R, int sLeft, int sRight)
{
    int i = 0, j = 0, k = 0;
    while (i < sLeft && j < sRight)
    {
        if (L[i] < R[j])
            vet[k++] = L[i++];
        else
            vet[k++] = R[j++];
    }
    while (i < sLeft)
        vet[k++] = L[i++];
    while (j < sRight)
        vet[k++] = R[j++];
}

void Merge(int *vet, int size)
{
    int *L, *R;
    int mid;

    if (size < 2)
        return;

    mid = size / 2;

    L = (int *)malloc(mid * sizeof(int));
    R = (int *)malloc((size - mid) * sizeof(int));
    if (!L || !R)
        return;

    for (int i = 0; i < mid; i++)
        L[i] = vet[i];
    for (int i = mid; i < size; i++)
        R[i - mid] = vet[i];
    Merge(L, mid);
    Merge(R, size - mid);
    Sort(vet, L, R, mid, size - mid);
    free(L);
    free(R);
}

int main()
{
    srand(time(NULL));
    int size = 6;
    int *vet = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
        vet[i] = rand() % 100 + 1;

    Merge(vet, size);

    for (int i = 0; i < size; i++)
        printf("%d, ", vet[i]);

    return 0;
}