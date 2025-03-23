#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#define size 5

typedef struct {
    int row;
    int column;
    int nonzero;
} element;

void inputMatrix(int matrix[size][size]) {
    printf("Enter your matrix elements:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("Element at row %d, column %d: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

bool isSparseMatrix(int matrix[size][size], element sm[], int *count) {
    *count = 0;
    int total = size * size;
    bool sparse = false;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] > 0) {
                sm[*count].row = i + 1;
                sm[*count].column = j + 1;
                sm[*count].nonzero = matrix[i][j];
                (*count)++;
            }
        }
    }

    if (*count <= total / 2) {
        sparse = true;
    }
    return sparse;
}

void outputMatrix(int matrix[size][size]) {
    printf("\nYour matrix is:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void outputSparseMatrix(element sm[], int count) {
    printf("\nRow\tColumn\tElement\n");
    printf("%d\t%d\t%d\n", size, size, count);
    for (int i = 0; i < count; i++) {
        printf("%d\t%d\t%d\n", sm[i].row, sm[i].column, sm[i].nonzero);
    }
}

void transpose(element sm[], int *count) {
    for (int i = 0; i < *count; i++) {
        int temp = sm[i].row;
        sm[i].row = sm[i].column;
        sm[i].column = temp;
    }
}

int compareByRow(const void *a, const void *b) {
    const element *e1 = (const element *)a;
    const element *e2 = (const element *)b;
    return (e1->row - e2->row);
}

void simpletranspose(element sm[], int *count) {
    element temp[size * size];
    int q = 0;
    int freq = 0;

    for (int col = 1; col < size + 1; col++) {
        for (int p = 0; p < *count; p++) {
            freq++;
            if (sm[p].column == col) {
                temp[q].row = sm[p].column;
                temp[q].column = sm[p].row;
                temp[q].nonzero = sm[p].nonzero;
                q++;
            }
        }
    }

    printf("\nFrequency of simple transpose is: %d\n", freq);

    for (int i = 0; i < *count; i++) {
        sm[i] = temp[i];
    }
}

void fasttranspose(element sm[], int *count) {
    int freq = 0;
    int rowTerms[size + 1], startingPos[size + 1];
    element transposed[size * size];
    int numCols = size;

    for (int i = 0; i <= numCols; i++) {
        rowTerms[i] = 0;
        startingPos[i] = 0;
    }

    for (int i = 0; i < *count; i++) {
        rowTerms[sm[i].column]++;
    }

    startingPos[1] = 0;
    freq++;

    for (int i = 2; i <= numCols; i++) {
        freq++;
        startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
    }

    for (int i = 0; i < *count; i++) {
        int pos = startingPos[sm[i].column]++;
        transposed[pos].row = sm[i].column;
        transposed[pos].column = sm[i].row;
        transposed[pos].nonzero = sm[i].nonzero;
        freq++;
    }

    for (int i = 0; i < *count; i++) {
        sm[i] = transposed[i];
    }

    printf("\nFrequency of Fast Transpose is: %d", freq);
}

int main() {
    element sm[size * size];
    int matrix[size][size];
    int count = 0;
    clock_t start_time, end_time;
    double cpu_time_used;

    start_time = clock();
    inputMatrix(matrix);
    outputMatrix(matrix);

    if (isSparseMatrix(matrix, sm, &count)) {
        printf("\nThis is a sparse matrix.\n");
        outputSparseMatrix(sm, count);
    } else {
        printf("\nThis is not a sparse matrix.\n");
    }

    printf("\nNow transposing the matrix...\n");
    printf("\nChoose your method:\n1.Normal\n2.Simple\n3.Fast\n");
    int uzi;
    scanf("%d", &uzi);

    switch (uzi) {
        case 1:
            transpose(sm, &count);
            break;
        case 2:
            simpletranspose(sm, &count);
            break;
        case 3:
            fasttranspose(sm, &count);
            break;
        default:
            printf("Invalid option.\n");
            return 1;
    }

    printf("\nTransposed sparse matrix:\n");
    outputSparseMatrix(sm, count);

    end_time = clock();
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("\nExecution time: %f seconds\n", cpu_time_used);
    printf("\nThe time complexity of this program is O(n^2).\n");

    return 0;
}
