#include <stdio.h>
#include <stdlib.h>

int equalStacks(int h1_count, int* h1, int h2_count, int* h2, int h3_count, int* h3) {
    long long sum1 = 0, sum2 = 0, sum3 = 0;
    int i = 0, j = 0, k = 0;

    for (int l = 0; l < h1_count; l++) {
        sum1 += h1[l];
    }
    for (int l = 0; l < h2_count; l++) {
        sum2 += h2[l];
    }
    for (int l = 0; l < h3_count; l++) {
        sum3 += h3[l];
    }

    while (sum1 != sum2 || sum2 != sum3) {
        if (i >= h1_count || j >= h2_count || k >= h3_count) {
            return 0;
        }

        if (sum1 >= sum2 && sum1 >= sum3) {
            sum1 -= h1[i++];
        } else if (sum2 >= sum1 && sum2 >= sum3) {
            sum2 -= h2[j++];
        } else if (sum3 >= sum1 && sum3 >= sum2) {
            sum3 -= h3[k++];
        }
    }
    
    return sum1;
}

int main() {
    int n1, n2, n3;
    scanf("%d %d %d", &n1, &n2, &n3);

    int* h1 = (int*)malloc(n1 * sizeof(int));
    for (int i = 0; i < n1; i++) {
        scanf("%d", &h1[i]);
    }

    int* h2 = (int*)malloc(n2 * sizeof(int));
    for (int i = 0; i < n2; i++) {
        scanf("%d", &h2[i]);
    }

    int* h3 = (int*)malloc(n3 * sizeof(int));
    for (int i = 0; i < n3; i++) {
        scanf("%d", &h3[i]);
    }

    int result = equalStacks(n1, h1, n2, h2, n3, h3);
    printf("%d\n", result);

    free(h1);
    free(h2);
    free(h3);

    return 0;
}
