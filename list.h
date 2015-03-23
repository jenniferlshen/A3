//Jenny Shen 260509776
#ifndef __Assignment3__list__
#define __Assignment3__list__

#include <stdio.h>
typedef int BOOLEAN;
#define true 1;
#define false 0;

void add(int);
void prettyPrint();
BOOLEAN delete(int);
typedef struct NODE
{
    int value;
    struct NODE *next;
} NODE;

extern NODE *head;
NODE* find(int);

#endif