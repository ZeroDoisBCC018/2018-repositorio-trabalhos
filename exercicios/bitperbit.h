#ifndef _BITPERBIT_H
#define _BITPERBIT_H_
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void swap_ints(int a, int b);

int int_module(int a);

void force_terminator(char* str, int n);

void fdump1(FILE* f);

char* read_line(FILE* fp);

#endif
