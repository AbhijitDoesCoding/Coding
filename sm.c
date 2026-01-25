#include <stdio.h>
#include <stdlib.h>

typedef struct sm {
    int row;
    int column;
    int data;
} sm;

void inputMatrix(int matrix[][100], int m, int n) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Element [%d][%d]: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void outputMatrix(int matrix[][100], int m, int n) {
    printf("\nMatrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int nonzero(int matrix[][100], int m, int n) {
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != 0) {
                count++;
            }
        }
    }
    return count;
}

void isSparseMatrix(int nz, int m, int n) {
    if (nz < (m * n) / 2) {
        printf("\nThe given matrix is a sparse matrix.\n");
    } else {
        printf("\nThe given matrix is not a sparse matrix.\n");
    }
}

void sparseMatrixConv(sm sparseMatrix[], int matrix[][100], int m, int n, int nz) {
    sparseMatrix[0].row = m;
    sparseMatrix[0].column = n;
    sparseMatrix[0].data = nz;
    int k = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != 0) {
                sparseMatrix[k].row = i;
                sparseMatrix[k].column = j;
                sparseMatrix[k].data = matrix[i][j];
                k++;
            }
        }
    }
}

void simpletranspose(sm sparseMatrix[]);
void fasttranspose(sm sparseMatrix[]);
void displaysm(sm sparseMatrix[]);

int main() {
    int m, n;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);
    
    int matrix[100][100];
    inputMatrix(matrix, m, n);
    outputMatrix(matrix, m, n);

    int nz = nonzero(matrix, m, n);
    isSparseMatrix(nz, m, n);

    sm sparseMatrix[nz+1];
    sparseMatrixConv(sparseMatrix, matrix, m, n, nz);
    
    displaysm(sparseMatrix);
    int choice;
    printf("\n1. Simple Transpose\n2. Fast Transpose\n");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            simpletranspose(sparseMatrix);
            displaysm(sparseMatrix);
            break;
        case 2:
            fasttranspose(sparseMatrix);
            displaysm(sparseMatrix);
            break;
        default:
            printf("\nInvalid choice\n");
    }

    return 0;
}

void simpletranspose(sm sparseMatrix[]){
    int m = sparseMatrix[0].row;
    int n = sparseMatrix[0].column;
    int nz = sparseMatrix[0].data;
    
    sm tempmatrix[nz + 1];
    tempmatrix[0].data = nz;
    tempmatrix[0].row = n;
    tempmatrix[0].column = m;
    int k = 1;
    for(int i = 0; i < n; i++){
        for(int j = 1; j < nz+1; j++){
            if(sparseMatrix[j].column == i){
                tempmatrix[k].data = sparseMatrix[j].data;
                tempmatrix[k].row = sparseMatrix[j].column;
                tempmatrix[k].column = sparseMatrix[j].row;
                k++;
            }
        }
    }
    for (int i = 0; i <= nz; i++) {
        sparseMatrix[i] = tempmatrix[i];
    }
}

void fasttranspose(sm sparseMatrix[]){
    int m = sparseMatrix[0].row;
    int n = sparseMatrix[0].column;
    int nz = sparseMatrix[0].data;
    sm tempmatrix[nz + 1];
    tempmatrix[0].data = nz;
    tempmatrix[0].row = n;
    tempmatrix[0].column = m;
    
    int freqcount[m];
    for(int i = 0; i < m; i++){
        freqcount[i] = 0;
    }
    
    for(int i = 1; i < nz+1; i++){
        freqcount[sparseMatrix[i].column]++;
    }
    
    int startingpos[m];
    for(int i = 0; i < m; i++){
        startingpos[i] = 0;
    }
    
    int j = 1, k = 0;
    
    startingpos[0] = 1;
    
    for(int i = 0 ; i < m; i++){
        startingpos[j] = startingpos[j - 1] + freqcount[i];
        j++;
    }

    for(int i = 1; i < nz+1; i++){
        int temp = startingpos[sparseMatrix[i].column];
        tempmatrix[temp].data = sparseMatrix[i].data;
        tempmatrix[temp].row = sparseMatrix[i].column;
        tempmatrix[temp].column = sparseMatrix[i].row;
        startingpos[sparseMatrix[i].column]++;
    }
    
    for (int i = 0; i <= nz; i++) {
        sparseMatrix[i] = tempmatrix[i];
    }
}

void displaysm(sm sparseMatrix[]){
    int nz = sparseMatrix[0].data;
    printf("\nRow\tColumn\tElement\n");
    printf("%d\t%d\t%d\n", sparseMatrix[0].row, sparseMatrix[0].column, nz);
    for (int i = 1; i <= nz; i++) {
        printf("%d\t%d\t%d\n", sparseMatrix[i].row, sparseMatrix[i].column, sparseMatrix[i].data);
    }
}
