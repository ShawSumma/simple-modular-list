
#include "lists.h"

#include <stdlib.h>

int main() {
    list(int) x = list_new(int);

    for (int i = 0; i < 7; i++) {
        list_push(int, x, i);
    }

    list_index(int, x, 3) = 30;

    while (list_len(int, x) != 0) {
        printf("%i\n", list_pop(int, x));
    }

    list_delete(int, x);
}
