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
void displayTable(Table * table);
