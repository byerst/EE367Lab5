/* Header for table data type  */
#define MAXSIZE 100

typedef struct {
	int valid;
	char destAddr;
	int outLink;
} TableData;

typedef struct {
	TableData data[MAXSIZE];
	int size;
} Table;

void initTable(Table * table);
void insert(Table * table, int valid, char destaddr, int out);
int findEntryByDest(Table * table, char destAddr);
/* Finds the entry by its network addr and returns its index*/
void displayTable(Table * table);
void updateEntry(Table * table, TableData * new_entry, char destAddr);
/* Updates whether or not the table */
