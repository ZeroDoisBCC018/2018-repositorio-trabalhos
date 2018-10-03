#ifndef _BITPERBIT_H
#define _BITPERBIT_H_
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap_ints(int a, int b);

unsigned int int_module(int n);

//force \0 terminator in the last character of a string
void force_terminator(char* str);

//dump one byte (read as a character) only
void fdump1(FILE* stream);

void fdumpline(FILE* stream);

char* readline(FILE* stream);

int higher(int a, int b);

int lower(int a, int b);

//least common multiple
int lcm(int a, int b);

//greatest common divisor
int gcd(int a, int b);

unsigned int factorial(int n);

unsigned int fibonacci(int n);

//mode = the file access mode after cleaning
int cleanfile(FILE* fp, const char* mode);

/* do an arithmetic operation by receiving the integer reference
 * can be used in functions when the client can't return the value
 * op = the arithmetic operation simbol. note: this function reads
 * its parameters in polish notation. */
int int_arit_ref(const char op, int* n, int a);

#endif
