#ifndef GOOGLEBOTCSV_H
#define GOOGLEBOTCSV_H
#include <stddef.h> 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "googlebot_lists.h"

/*data structure for storing site information, gathered from the csv file*/
typedef struct SITE;

/*reads site information from standard input*/
NODE* GB_GetSiteStdin(void);

/*inserts site information in structure pointed to by a given list position*/
int GB_InsertSite(LIST* l, int pos);

/*removes a site from list according to its code*/
int GB_RemoveSite(LIST* l, int code);


#endif
