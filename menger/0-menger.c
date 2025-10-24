#include "menger.h"
#include <stdio.h>

/**
 * menger - Create a fractal cube
 * @level: number of side square
 */

void menger(int level) {
    if (level < 0)
        return;

    int size = 1;
    for (int i = 0; i < level; i++) {
        size *= 3;
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int x = i, y = j;
            int print = 1;
            while (x > 0 || y > 0) {
                if (x % 3 == 1 && y % 3 == 1) {
                    print = 0;
                    break;
                }
                x /= 3;
                y /= 3;
            }
            putchar(print ? '#' : ' ');
        }
        putchar('\n');
    }
}
