#ifndef _BITPERBIT_H
#define _BITPERBIT_H_
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap_ints(int a, int b);

unsigned int int_module(int n);

void force_terminator(char* str);

void fdump1(FILE* stream);

void fdumpline(FILE* stream);

char* readline(FILE* stream);

int higher(int a, int b);

int lower(int a, int b);

int lcm(int a, int b);

int gcd(int a, int b);

unsigned int factorial(int n);

unsigned int fibonacci(int n);

int cleanfile(FILE* fp, const char* mode);

int int_arit_ref(const char op, int* n, int a);

#endif
