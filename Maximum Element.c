#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long *data;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (long long*)malloc(stack->capacity * sizeof(long long));
    return stack;
}

void push(Stack* stack, long long item) {
    stack->data[++stack->top] = item;
}

long long pop(Stack* stack) {
    return stack->data[stack->top--];
}

long long peek(Stack* stack) {
    return stack->data[stack->top];
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int main() {
    int n, type;
    long long x;
    scanf("%d", &n);

    Stack* mainStack = createStack(n);
    Stack* maxStack = createStack(n);

    while (n--) {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%lld", &x);
            push(mainStack, x);
            if (isEmpty(maxStack) || x >= peek(maxStack)) {
                push(maxStack, x);
            }
        } else if (type == 2) {
            if (!isEmpty(mainStack)) {
                if (peek(mainStack) == peek(maxStack)) {
                    pop(maxStack);
                }
                pop(mainStack);
            }
        } else {
            if (!isEmpty(maxStack)) {
                printf("%lld\n", peek(maxStack));
            }
        }
    }
    
    free(mainStack->data);
    free(mainStack);
    free(maxStack->data);
    free(maxStack);

    return 0;
}

