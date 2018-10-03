#ifndef _COLLECTOR_H_
#define _COLLECTOR_H_

int collector_start(unsigned int size);

void collect(void* p);

void freeall(void);

#endif
