#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    int** seq = (int**)malloc(n * sizeof(int*));
    int* sz = (int*)calloc(n, sizeof(int));

    int lastans = 0;

    for (int i = 0; i < n; i++) {
        seq[i] = NULL;
    }

    for (int i = 0; i < q; i++) {
        int op, x, y;
        scanf("%d %d %d", &op, &x, &y);

        int idx = (x ^ lastans) % n;

        if (op == 1) {
            sz[idx]++;
            seq[idx] = (int*)realloc(seq[idx], sz[idx] * sizeof(int));
            seq[idx][sz[idx] - 1] = y;
        } else {
            int t = seq[idx][y % sz[idx]];
            printf("%d\n", t);
            lastans = t;
        }
    }

    for (int i = 0; i < n; i++) {
        free(seq[i]);
    }
    free(seq);
    free(sz);

    return 0;
}
