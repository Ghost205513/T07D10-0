#include <stdio.h>
#include <stdlib.h>

int input(int **buffer, int rows, int columns);
void output(int **buffer, int rows, int columns);
int **sum(int **a, int **b, int rows, int columns);
int **multiply(int **a, int rows_a, int columns_a, int **b, int columns_b);
int **transpose(int **a, int rows, int columns);
int **matrix_init(int *rows, int *columns);
void free_m(int **a, int rows);


int main() {
    int mod, rows_a, columns_a, rows_b, columns_b;
    int **a, **b, **res;

            if (scanf("%d", &mod) == 0) {
                printf("n/a");
            } else {
                switch (mod) {
                    case 1:
                        a = matrix_init(&rows_a, &columns_a);

                        if (a != NULL) {
                            b = matrix_init(&rows_b, &columns_b);

                            if (b != NULL) {
                                if (columns_a == columns_b && rows_a == rows_b) {
                                    res = sum(a, b, rows_a, columns_a);
                                    output(res, rows_a, columns_a);
                                    free_m(res, rows_a);
                                } else {
                                    printf("n/a");
                                }
                                free_m(b, rows_b);
                            }
                            free_m(a, rows_a);
                        }
                        break;
                    case 2:
                        a = matrix_init(&rows_a, &columns_a);

                        if (a != NULL) {
                            b = matrix_init(&rows_b, &columns_b);

                            if (b != NULL) {
                                if (columns_a == rows_b) {
                                    res = multiply(a, rows_a, columns_a, b, columns_b);
                                    output(res, rows_a, columns_b);
                                    free_m(res, rows_a);
                                } else {
                                    printf("n/a");
                                }
                                free_m(b, rows_b);
                            }
                            free_m(a, rows_a);
                        }
                        break;
                    case 3:
                        a = matrix_init(&rows_a, &columns_a);

                        if (a != NULL) {
                            if (columns_a == rows_a) {
                                res = transpose(a, rows_a, columns_a);
                                output(res, columns_a, rows_a);
                                free_m(res, columns_a);
                            } else {
                                printf("n/a");
                            }
                            free_m(a, rows_a);
                        }
                        break;
                    default:
                        printf("n/a");
                }
    }
}

int input(int **buffer, int rows, int columns) {
    int flag, trash;

    flag = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            int temp;

            if (scanf("%d", &temp) == 0) {
                flag = 1;
                break;
            } else {
                buffer[i][j] = temp;
            }
        }
    }

    trash = getchar();

    while (trash == ' ' || trash == '\t')
        trash = getchar();

    if (trash != '\n')
        flag = 1;

    return flag;
}

void output(int **buffer, int rows, int columns) {
    for (int i = 0; i < rows - 1; i++) {
        printf("%d", buffer[i][0]);

        for (int j = 1; j < columns; j++)
            printf(" %d", buffer[i][j]);

        printf("\n");
    }

    printf("%d", buffer[rows - 1][0]);

    for (int j = 1; j < columns; j++)
        printf(" %d", buffer[rows - 1][j]);
}

int **sum(int **a, int **b, int rows, int columns) {
    int **ans = calloc(rows, sizeof(int *));

    for (int i = 0; i < rows; i++) {
        ans[i] = calloc(columns, sizeof(int));

        for (int j = 0; j < columns; j++)
            ans[i][j] = b[i][j] + a[i][j];
    }

    return ans;
}

int **multiply(int **a, int rows_a, int columns_a, int **b, int columns_b) {
    int **ans = calloc(rows_a, sizeof(int *));

        for (int i = 0; i < rows_a; i++) {
            ans[i] = calloc(columns_b, sizeof(int));

            for (int j = 0; j < columns_b; j++) {
                ans[i][j] = 0;

                for (int k = 0; k < columns_a; k++)
                    ans[i][j] += a[i][j + k] * b[i + k][j];
            }
        }

    return ans;
}

int **transpose(int **a, int rows, int columns) {
    int **ans = calloc(columns, sizeof(int *));

    for (int i = 0; i < columns; i++)
        ans[i] = calloc(rows, sizeof(int));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
            ans[j][i] = a[i][j];
    }

    return ans;
}

int ** matrix_init(int *rows, int *columns) {
    int **pointers_matrix = NULL;

    if (scanf("%d", rows) == 0 || *rows <= 0) {
        printf("n/a");
    } else if (scanf("%d", columns) == 0 || *columns <= 0) {
        printf("n/a");
    } else {
        pointers_matrix = malloc(*rows * sizeof(int *));

        for (int i = 0; i < *rows; i++)
            pointers_matrix[i] = malloc(*columns * sizeof(int));

        if (input(pointers_matrix, *rows, *columns) == 1) {
            printf("n/a");

            free_m(pointers_matrix, *rows);
            pointers_matrix = NULL;
        }
    }

    return pointers_matrix;
}

void free_m(int **a, int rows) {
    for (int i = 0; i < rows; i++)
            free(a[i]);

    free(a);
}
