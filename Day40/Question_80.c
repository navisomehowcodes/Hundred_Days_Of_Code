/*
Question 80
Multiply two matrices.
*/

#include <stdio.h>
#include <limits.h>

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
    if (a.cols != b.rows) {
        puts("Incompatible dimensions");
        return 0;
    }
    long long result[MAX_SIDE][MAX_SIDE];
    for (int row = 0; row < a.rows; ++row) {
        for (int col = 0; col < b.cols; ++col) {
            long long total = 0;
            for (int k = 0; k < a.cols; ++k) {
                long long term = (long long)a.cell[row][k] * b.cell[k][col];
                if ((term > 0 && total > LLONG_MAX - term) ||
                    (term < 0 && total < LLONG_MIN - term)) {
                    puts("Overflow");
                    return 0;
                }
                total += term;
            }
            result[row][col] = total;
        }
    }
    for (int row = 0; row < a.rows; ++row) {
        for (int col = 0; col < b.cols; ++col) {
            printf("%s%lld", col == 0 ? "" : " ", result[row][col]);
        }
        putchar('\n');
    }
    return 0;
}
