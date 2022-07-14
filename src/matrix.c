#include <stdio.h>
#include <stdlib.h>

int input(int **buffer, int rows, int columns);
void output(int **buffer, int rows, int columns);
void menu_mod1();
void menu_mod2();
void menu_mod3();
void menu_mod4();

int main() {
    int mod;

    if (scanf("%d", &mod) == 0) {
        printf("n/a\n");

    } else {
        switch (mod) {
            case 1:
                menu_mod1();
                break;
            case 2:
                menu_mod2();
                break;
            case 3:
                menu_mod3();
                break;
            case 4:
                menu_mod4();
                break;
            default:
                printf("n/a\n");
        }
    }
}

void menu_mod1() {
    int rows, columns;

    if (scanf("%d", &rows) == 0 || rows <= 0 || rows > 100) {
        printf("n/a\n");
    } else if (scanf("%d", &columns) == 0 || columns <= 0 || rows > 100) {
        printf("n/a\n");
    } else {
        int *static_matrix[100];
        int single_array[10000];

        for (int i = 0; i < rows; i++)
            static_matrix[i] = &single_array[i * columns];

        if (input(static_matrix, rows, columns) == 1) {
            printf("n/a\n");
        } else {
            output(static_matrix, rows, columns);
        }
    }
}

void menu_mod2() {
    int rows, columns;

    if (scanf("%d", &rows) == 0 || rows <= 0) {
        printf("n/a\n");
    } else if (scanf("%d", &columns) == 0 || columns <= 0) {
        printf("n/a\n");
    } else {
        int **single_array_matrix;
        int *pointer2row;

        single_array_matrix = malloc(rows * columns * sizeof(int) + rows * sizeof(int *));
        pointer2row = (int *) (single_array_matrix + rows);

        for (int i = 0; i < rows; i++)
            single_array_matrix[i] = pointer2row + columns * i;

        if (input(single_array_matrix, rows, columns) == 1) {
            printf("n/a\n");
        } else {
            output(single_array_matrix, rows, columns);
        }

        free(single_array_matrix);
    }
}

void menu_mod3() {
    int rows, columns;

    if (scanf("%d", &rows) == 0 || rows <= 0) {
        printf("n/a\n");
    } else if (scanf("%d", &columns) == 0 || columns <= 0) {
        printf("n/a\n");
    } else {
        int **pointers_matrix;

        pointers_matrix = malloc(rows * sizeof(int *));

        for (int i = 0; i < rows; i++)
            pointers_matrix[i] = malloc(columns * sizeof(int));

        if (input(pointers_matrix, rows, columns) == 1) {
            printf("n/a\n");
        } else {
            output(pointers_matrix, rows, columns);
        }

        for (int i = 0; i < rows; i++)
            free(pointers_matrix[i]);

        free(pointers_matrix);
    }
}

void menu_mod4() {
    int rows, columns;

    if (scanf("%d", &rows) == 0 || rows <= 0) {
        printf("n/a\n");
    } else if (scanf("%d", &columns) == 0 || columns <= 0) {
        printf("n/a\n");
    } else {
        int **pointers2single_array_matrix;
        int *single_array_of_pointers;

        pointers2single_array_matrix = malloc(rows * sizeof(int *));
        single_array_of_pointers = malloc(rows * columns * sizeof(int));

        for (int i = 0; i < rows; i++)
            pointers2single_array_matrix[i] = single_array_of_pointers + columns * i;

        if (input(pointers2single_array_matrix, rows, columns) == 1) {
            printf("n/a\n");
        } else {
            output(pointers2single_array_matrix, rows, columns);
        }

        free(single_array_of_pointers);
        free(pointers2single_array_matrix);
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
