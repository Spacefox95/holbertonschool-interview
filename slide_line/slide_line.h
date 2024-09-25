#define SLIDE_LINE

/* DEFINE MACROS FOR DIRECTION */

#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

/* LIBRAIRIES */

#include <stdlib.h>
#include <stdio.h>

/* PROTOTYPES */

int slide_line(int *line, size_t size, int direction);
void slide(int *line, size_t size);
void merge(int *line, size_t size);
void reverse_array(int *line, size_t size);
