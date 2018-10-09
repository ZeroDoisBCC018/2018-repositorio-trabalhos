#ifndef _BITPERBIT_H
#define _BITPERBIT_H_
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* this function uses call by reference
 * so the arguments are each variable's address */
void swap_ints(int* a, int* b);

int int_module(int n);

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

/* do an arithmetic operation by receiving the integer reference (&var)
 * can be used in functions when the client can't return the value
 *  (char) op = the arithmetic operation simbol. note: this function reads
 * its parameters in polish notation. */
int int_arit_ref(const char op, int* n, int a);

int power_ref(int* n, int e);

double totalclock(clock_t start_t, clock_t end_t);

/* the first one is called inside the second one
 * you just need to call the second one */
void int_merge(int v[], int s, int m, int e); 
void int_mergesort(int vector[], int start, int end);

//n = vector size
void heapsort(int a[], int n);

#endif
