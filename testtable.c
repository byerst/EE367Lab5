#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"

int main()
{	Table t;
	TableData td;
	td.valid = 0;
	td.destAddr = 'a';
	td.outLink = 1;
	initTable(&t);
	updateTable(&t, 0, 'a', 1);
	displayTable(&t);
}
