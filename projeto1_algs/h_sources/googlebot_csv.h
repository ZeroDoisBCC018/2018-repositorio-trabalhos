#ifndef GOOGLEBOTCSV_H
#define GOOGLEBOTCSV_H
#define CSV FILE*;
#include <stddef.h> 
#include <stdlib.h>
#include <stdio.h>
#include "googlebot_ds.h"
#include "googlebot_lists.h"
typedef int boolean;

/*checks validity for codes of new site entries*/
int GB_CodeCheck (int code, LIST* l);

/*opens CSV file with read permission*/
CSV GB_OpenCSVread (CSV fp, char* filename);

/*opens CSV file and erases its original content, so it can be rewritten with updated data from structs*/
GB_OpenCSVWrite (CSV fp, char* filename);

/*closes opened CSV file*/
void GB_CloseCSV;

/*reads CSV file and stores its data in site structs*/
void GB_ReadCSV (CSV fp, SITE* s);

/*prints updated struct data into original CSV file*/
int GB_UpdateDataBase (CSV fp, char* filename, LIST* l)

#endif
