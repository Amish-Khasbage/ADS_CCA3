#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int left;
    int right;
} Node;

void swap_and_travers(Node* tree, int k, int current_depth, int current_node) {
    if (current_node == -1) {
        return;
    }

    if (current_depth % k == 0) {
        int temp = tree[current_node].left;
        tree[current_node].left = tree[current_node].right;
        tree[current_node].right = temp;
    }

    swap_and_travers(tree, k, current_depth + 1, tree[current_node].left);
    swap_and_travers(tree, k, current_depth + 1, tree[current_node].right);
}

void inorder(Node* tree, int node) {
    if (node == -1) {
        return;
    }

    inorder(tree, tree[node].left);
    printf("%d ", tree[node].data);
    inorder(tree, tree[node].right);
}

int main() {
    int n;
    scanf("%d", &n);

    Node* tree = (Node*)malloc((n + 1) * sizeof(Node));
    for (int i = 1; i <= n; i++) {
        tree[i].data = i;
    }

    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &tree[i].left, &tree[i].right);
    }

    int t;
    scanf("%d", &t);

    while (t--) {
        int k;
        scanf("%d", &k);

        swap_and_travers(tree, k, 1, 1);
        inorder(tree, 1);
        printf("\n");
    }

    free(tree);
    return 0;
}
