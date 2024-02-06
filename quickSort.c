#include <stdio.h>
#include <math.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

long long partition(int A[], long long L, long long R, long long indexPivot) {
    int pivot = A[indexPivot];
    swap(&A[indexPivot], &A[R]);
    long long storeIndex = L;
    long long i = 0;
    for (i = L; i <= R - 1; i++) {
        if (A[i] < pivot) {
            swap(&A[storeIndex], &A[i]);
            storeIndex++;
        }
    }
    swap(&A[storeIndex], &A[R]);
    return storeIndex;
}

void quickSort(int A[], long long L, long long R) {
    if (L < R) {
        long long index = (L + R) / 2;
        index = partition(A, L, R, index);
        if (L < index)
            quickSort(A, L, index - 1);
        if (index < R)
            quickSort(A, index + 1, R);
    }
}

int main() {
    long long n;
    scanf("%lld", &n);
    int a[100000];
    long long i = 0;
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    quickSort(a, 0, n - 1);
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}

