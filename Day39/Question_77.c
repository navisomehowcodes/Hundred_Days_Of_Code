/*
Question 77
Check if the elements on the diagonal of a matrix are distinct.
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
    Matrix m;
    if (!read_matrix(&m)) {
        return 1;
    }
    int length = m.rows < m.cols ? m.rows : m.cols;
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < i; ++j) {
            if (m.cell[i][i] == m.cell[j][j]) {
                puts("False");
                return 0;
            }
        }
    }
    puts("True");
    return 0;
}
