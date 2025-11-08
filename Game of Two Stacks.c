#include <stdio.h>
#include <stdlib.h>

int twoStacks(int x, int a_count, int* a, int b_count, int* b) {
    long long sum = 0;
    int count = 0;
    int i = 0;
    int j = 0;
    
    while (i < a_count && sum + a[i] <= x) {
        sum += a[i];
        i++;
    }
    
    count = i;
    
    while (j < b_count) {
        sum += b[j];
        j++;
        
        while (sum > x && i > 0) {
            i--;
            sum -= a[i];
        }
        
        if (sum <= x) {
            if (i + j > count) {
                count = i + j;
            }
        } else {
            break;
        }
    }
    
    return count;
}

int main() {
    int g;
    scanf("%d", &g);
    while (g--) {
        int n, m, x;
        scanf("%d %d %d", &n, &m, &x);
        
        int* a = (int*)malloc(sizeof(int) * n);
        for (int a_i = 0; a_i < n; a_i++) {
            scanf("%d", &a[a_i]);
        }
        
        int* b = (int*)malloc(sizeof(int) * m);
        for (int b_i = 0; b_i < m; b_i++) {
            scanf("%d", &b[b_i]);
        }
        
        int result = twoStacks(x, n, a, m, b);
        printf("%d\n", result);
        
        free(a);
        free(b);
    }
    return 0;
}
