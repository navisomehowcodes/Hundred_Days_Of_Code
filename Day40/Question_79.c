/*
Question 79
Perform diagonal traversal of a matrix.
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
    /* Each diagonal has a constant row + column. Alternate its direction. */
    for (int diagonal = 0; diagonal < m.rows + m.cols - 1; ++diagonal) {
        int top = diagonal < m.cols ? 0 : diagonal - m.cols + 1;
        int bottom = diagonal < m.rows ? diagonal : m.rows - 1;
        for (int offset = 0; offset <= bottom - top; ++offset) {
            int row = diagonal % 2 == 0 ? bottom - offset : top + offset;
            printf("%s%d", diagonal == 0 ? "" : " ", m.cell[row][diagonal - row]);
        }
    }
    putchar('\n');
    return 0;
}
