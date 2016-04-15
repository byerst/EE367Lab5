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
	for(i=0; i<=table->size-1; i++)
	{	printf("Entry #%d\t", table->size);
		printf("Valid: %d\t", table->data[i].valid);
		printf("Destination: %c\t", table->data[i].destAddr);
		printf("Output link: %d\t", table->data[i].outLink);
	}
}

void updateEntry(Table * table, TableData * new_entry, char destAddr)
{	
	int target = findEntryByDest(table, destAddr);
	if (target != -1) { 
	table->data[target].valid = new_entry->valid;
	table->data[target].destAddr = new_entry->destAddr;
	table->data[target].outLink = new_entry->outLink;
	}
	
}

void addEntry(Table * table, TableData * new_entry)
{
	table->data[table->size] = *new_entry;
	table->size++;
}

int getOutlink(Table * table, char destAddr)
{
	int target = findEntryByDest(table, destAddr);
	if (target != -1) {
		return table->data[target].outLink;
	}
}

void updateTable(Table * table, int Valid, char dest, int outlink)
{
	int target = findEntryByDest(table, dest);
	//printf("Target: %d\n", target);
	TableData new_entry;
	new_entry.valid = Valid;
	new_entry.destAddr = dest;
	new_entry.outLink = outlink;
	
	if (target == -1) { //if target not found, add entry
		addEntry(table, &new_entry);
	}
	else updateEntry(table, &new_entry, dest);
}  
