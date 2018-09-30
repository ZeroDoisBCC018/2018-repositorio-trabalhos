#ifndef _NOLEAK_H_
#define _NOLEAK_H_

void start_pointer_storage(void);

void add_pointer_to_storage(void* p);

void free_storage(void);

#endif
