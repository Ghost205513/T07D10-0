#include <stdio.h>
#include <stdlib.h>

void menu_mod1();
void menu_mod2();
void menu_mod3();
void menu_mod4();
int input(int **buffer, int rows, int columns);
void output_matrix(int **buffer, int rows, int columns);
void output_array(int *buffer, int length);
int *max_rows(int **buffer, int rows, int columns);
int *min_columns(int **buffer, int rows, int columns);

int main() {
    int mod;

    if (scanf("%d", &mod) == 0) {
        printf("n/a");

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
                printf("n/a");
        }
    }
}

void menu_mod1() {
    int rows, columns;

    if (scanf("%d", &rows) == 0 || rows <= 0 || rows > 100) {
        printf("n/a");
    } else if (scanf("%d", &columns) == 0 || columns <= 0 || rows > 100) {
        printf("n/a");
    } else {
        int *static_matrix[100];
        int single_array[10000];

        for (int i = 0; i < rows; i++)
            static_matrix[i] = &single_array[i * columns];

        if (input(static_matrix, rows, columns) == 1) {
            printf("n/a");
        } else {
            int *max_, *min_;

            output_matrix(static_matrix, rows, columns);
            printf("\n");
            max_ = max_rows(static_matrix, rows, columns);
            output_array(max_, rows);
            printf("\n");
            min_ = min_columns(static_matrix, rows, columns);
            output_array(min_, columns);

            free(max_);
            free(min_);
        }
    }
}

void menu_mod2() {
    int rows, columns;

    if (scanf("%d", &rows) == 0 || rows <= 0) {
        printf("n/a");
    } else if (scanf("%d", &columns) == 0 || columns <= 0) {
        printf("n/a");
    } else {
        int **single_array_matrix;
        int *pointer2row;

        single_array_matrix = malloc(rows * columns * sizeof(int) + rows * sizeof(int *));
        pointer2row = (int *) (single_array_matrix + rows);

        for (int i = 0; i < rows; i++)
            single_array_matrix[i] = pointer2row + columns * i;

        if (input(single_array_matrix, rows, columns) == 1) {
            printf("n/a");
        } else {
            int *max_, *min_;

            output_matrix(single_array_matrix, rows, columns);
            printf("\n");
            max_ = max_rows(single_array_matrix, rows, columns);
            output_array(max_, rows);
            printf("\n");
            min_ = min_columns(single_array_matrix, rows, columns);
            output_array(min_, columns);

            free(max_);
            free(min_);
        }

        free(single_array_matrix);
    }
}

void menu_mod3() {
    int rows, columns;

    if (scanf("%d", &rows) == 0 || rows <= 0) {
        printf("n/a");
    } else if (scanf("%d", &columns) == 0 || columns <= 0) {
        printf("n/a");
    } else {
        int **pointers_matrix;

        pointers_matrix = malloc(rows * sizeof(int *));

        for (int i = 0; i < rows; i++)
            pointers_matrix[i] = malloc(columns * sizeof(int));

        if (input(pointers_matrix, rows, columns) == 1) {
            printf("n/a");
        } else {
            int *max_, *min_;

            output_matrix(pointers_matrix, rows, columns);
            printf("\n");
            max_ = max_rows(pointers_matrix, rows, columns);
            output_array(max_, rows);
            printf("\n");
            min_ = min_columns(pointers_matrix, rows, columns);
            output_array(min_, columns);

            free(max_);
            free(min_);
        }

        for (int i = 0; i < rows; i++)
            free(pointers_matrix[i]);

        free(pointers_matrix);
    }
}

void menu_mod4() {
    int rows, columns;

    if (scanf("%d", &rows) == 0 || rows <= 0) {
        printf("n/a");
    } else if (scanf("%d", &columns) == 0 || columns <= 0) {
        printf("n/a");
    } else {
        int **pointers2single_array_matrix;
        int *single_array_of_pointers;

        pointers2single_array_matrix = malloc(rows * sizeof(int *));
        single_array_of_pointers = malloc(rows * columns * sizeof(int));

        for (int i = 0; i < rows; i++)
            pointers2single_array_matrix[i] = single_array_of_pointers + columns * i;

        if (input(pointers2single_array_matrix, rows, columns) == 1) {
            printf("n/a");
        } else {
            int *max_, *min_;

            output_matrix(pointers2single_array_matrix, rows, columns);
            printf("\n");
            max_ = max_rows(pointers2single_array_matrix, rows, columns);
            output_array(max_, rows);
            printf("\n");
            min_ = min_columns(pointers2single_array_matrix, rows, columns);
            output_array(min_, columns);

            free(max_);
            free(min_);
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

void output_matrix(int **buffer, int rows, int columns) {
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

void output_array(int *buffer, int length) {
    printf("%d", *buffer);

    for (int i = 1; i < length; i++)
        printf(" %d", buffer[i]);
}

int *max_rows(int **buffer, int rows, int columns) {
    int *result;
    int max_in_row;

    result = malloc(rows * sizeof(int));

    for (int i = 0; i < rows; i++) {
        max_in_row = buffer[i][0];

        for (int j = 1; j < columns; j++) {
            if (buffer[i][j] > max_in_row)
                max_in_row = buffer[i][j];
        }

        result[i] = max_in_row;
    }

    return result;
}

int *min_columns(int **buffer, int rows, int columns) {
    int *result;
    int max_in_column;

    result = malloc(columns * sizeof(int));

    for (int j = 0; j < columns; j++) {
        max_in_column = buffer[0][j];

        for (int i = 1; i < rows; i++) {
            if (buffer[i][j] < max_in_column)
                max_in_column = buffer[i][j];
        }

        result[j] = max_in_column;
    }

    return result;
}
