#include "push_swap.h"
#include <stdio.h>

void print_stack(t_stack *stack) {
    while (stack != NULL) {
        printf("%d -> ", stack->data);
        stack = stack->next;
    }
    printf("NULL\n");
}

int main(int argc, char **argv) {
    t_stack *a = check_init(argc, argv); // Initialize the stack

    if (a == NULL) {
        return 1; // Exit with an error code
    }

    // Print the contents of the stack
    printf("Stack A:\n");

    print_stack(a);
    sort_three(&a);

    // Free the stack after use
    free_stack(&a);

    return 0; // Successful execution
}
