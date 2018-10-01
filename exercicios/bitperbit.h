#ifndef _BITPERBIT_H
#define _BITPERBIT_H_
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap_ints(int a, int b);

int int_module(int a);

void force_terminator(char* str, int n);

void dump_one_byte(FILE* f);

char* read_line(FILE* fp);

#endif
