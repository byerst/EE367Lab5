/*  file: table.c
 *  functions for table
 */

#include <stdio.h>
#include <stdlib.h>
#include "table.h"

void initTable(Table * table)
{	table->size = 0;	}

void insert(Table * table, int isvalid, char destaddr, int out)
{	
	(table->size)++;
	int size = table->size;	
	table->data[size].destAddr = destaddr;
	table->data[size].outLink = out;
	table->data[size].valid = isvalid;
}

int findEntryByDest(Table * table, char destaddr)
{
	int i;
	for (i=0; i<=table->size; i++)
	{	if (destaddr == table->data[i].destAddr)
			return i;
	}
	return -1;
}
void displayTable(Table * table)
{	int i;
	for(i=0; i<=table->size; i++)
	{	printf("Entry #%d\t", table->size);
		printf("Valid: %d\t", table->data->valid);
		printf("Destination: %c\t", table->data->destAddr);
		printf("Output link: %d\t", table->data->outLink);
	}
}

void updateEntry(Table * table, TableData * new_entry, char destAddr)
{	
	int target = findEntryByDest(table, destAddr);
	table->data[target].valid = new_entry->valid;
	table->data[target].destAddr = new_entry->destAddr;
	table->data[target].outLink = new_entry->outLink;	
}

