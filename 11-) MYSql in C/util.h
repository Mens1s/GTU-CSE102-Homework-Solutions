#ifndef _UTIL_H_
#define _UTIL_H_

typedef struct table { 
    char **field;
    char **type;
    int *isNull; // 1 => NULL
    int *isKey; // 1 is True

    char **data;
    char *tableName;
    int fieldNum;
} table;

typedef struct tables {
    struct tables *next;
    table * t;
} tables;

typedef struct database {
    tables * tList; /* to be implemented as a */
    int n;          /* num of table entries */
    char * name;    /* table name */
} database;

database * create_database(char *name);
void writeToDataBase(database * db);
void changeDatabase(database * db);
void show_table(database *d);
void desc_table(database *d, char *t);
void insert_table(database *d, char *t, int colNum); 
void insert_table_fromTXT(database *d, char *t, int colNum, FILE * dbfile); 
void remove_table(database *d, char *name);
void insert_key(database *d, char *tablename, char *key );
void insert_table_for_driver(database *d, char *t, int colNum, char  fieldName[][10], char fieldType[][10], char dataField[][10]);
int wordCounter(char *s);
void red ();
void green ();
void cyan ();
void yellow ();
void reset ();
void clean_stdin();

#endif /* _UTIL_H_ */
