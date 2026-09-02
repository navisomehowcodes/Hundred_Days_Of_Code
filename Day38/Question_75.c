/*
Question 75
Add two matrices.
*/

#include <stdio.h>

enum { MAX_SIDE = 100 };

typedef struct {
    int rows, cols;
    int cell[MAX_SIDE][MAX_SIDE];
} Matrix;

static int read_matrix(Matrix *m)
{
    if (scanf("%d%d", &m->rows, &m->cols) != 2 ||
        m->rows < 1 || m->rows > MAX_SIDE || m->cols < 1 || m->cols > MAX_SIDE) {
        return 0;
    }
    for (int row = 0; row < m->rows; ++row) {
        for (int col = 0; col < m->cols; ++col) {
            if (scanf("%d", &m->cell[row][col]) != 1) {
                return 0;
            }
        }
    }
    return 1;
}

int main(void)
{
    Matrix a, b;
    if (!read_matrix(&a) || !read_matrix(&b)) {
        return 1;
    }
    if (a.rows != b.rows || a.cols != b.cols) {
        puts("Incompatible dimensions");
        return 0;
    }
    for (int row = 0; row < a.rows; ++row) {
        for (int col = 0; col < a.cols; ++col) {
            long long sum = (long long)a.cell[row][col] + b.cell[row][col];
            printf("%s%lld", col == 0 ? "" : " ", sum);
        }
        putchar('\n');
    }
    return 0;
}
