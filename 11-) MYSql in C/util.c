#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

void red () {
  printf("\033[1;31m");
}

void green () {
  printf("\033[0;32m");
}

void cyan () {
  printf("\033[0;36m");
}

void yellow () {
  printf("\033[1;33m");
}

void reset () {
  printf("\033[0m");
}
/*
        With this function I clean buffer for next scanf work perfectly.
*/
void clean_stdin(){  
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}
/*
    Function wordCounter

    Aim: 
        counts word number in a string and return it

    Arguments:
        s => string
    Return:
        number of word
*/
int wordCounter(char *s){
    int count = 0;
    for (int i = 0;s[i+1] != '\0';i++)
    {
        if (s[i] == ' ')
            count++;    
    }
    return count + 1;
}

/*
    Function insert_table_fromTXT

    Aim: 
        create and realloce databases with datas which are coming from txt file

    Arguments:
        d => database 
        t => table name
        colNum => field number
        dbFile => dataFile
*/
void insert_table_fromTXT(database *d, char *t, int colNum, FILE * dbfile){
    tables * head  = d->tList;
    

    /* go to last entry*/
    for(int a = 0; a < d->n; a++)
        d->tList = d->tList->next;
    
    /* create dynamic data for table*/
    if(d->n != 0){
        d->tList = (tables *) malloc( sizeof(tables) );
        d->tList->t = (table * ) malloc( sizeof(table) );
    }

    d->tList->t->field =  ( char** ) malloc( colNum * sizeof(char*) );
    d->tList->t->type =  ( char** ) malloc( colNum * sizeof(char*) );
    d->tList->t->data =  ( char** ) malloc( colNum * sizeof(char*) );

    for(int a = 0; a < colNum; a++){
        d->tList->t->field[a] = (char *) malloc( 100 * sizeof(char) );
        d->tList->t->type[a] = (char *) malloc( 100 * sizeof(char) );
        d->tList->t->data[a] =  ( char *) malloc( 100 * sizeof(char) );

    }

    d->tList->t->tableName = (char *) malloc( strlen(t) * sizeof(char) );

    d->tList->t->isKey  = (int *) malloc( sizeof(int) );
    d->tList->t->isNull = (int *) malloc( sizeof(int) );
    /* end of creating dynamic data for table */

    d->tList->t->fieldNum = colNum;
    strcpy( d->tList->t->tableName, t );
    
    for(int a = 0; a < colNum; a++)
        fscanf(dbfile,"%s %s %d %d %s,",d->tList->t->field[a],d->tList->t->type[a],&d->tList->t->isNull[a],&d->tList->t->isKey[a],d->tList->t->data[a]);
    head->next = d->tList;
    d->tList = head;

    d->n++;
}

/*
    Function create_database

    Aim: 
        creates database and allocate dynamic memory 

    Arguments:
        name => database name

    Return allocated database memory address
*/
database * create_database(char *name){
    database * db = (database *) malloc( sizeof(database) );
    db->n = 0;
    db->name = ( char * ) malloc( sizeof(char) * strlen(name) );
    strcpy(db->name,name);
    return db;
}

/*
    Function show_table

    Aim: 
        shows all tables in the database

    Arguments:
        database => database 
*/
void show_table(database *d){
    int a;
    tables * head = d->tList;
    red();
    if (d->n  == 0)   
        printf("There no tables!\n");
    reset();
    for(a = 0; a <  d->n ; a++){
        cyan();
        printf("Fields in %s Table\n\n",  d->tList->t->tableName);
        yellow();
        for(int b = 0 ;  b <  d->tList->t->fieldNum ; b++)
            printf("|%10s|\n", d->tList->t->field[b]);

        d->tList =  d->tList->next;
    }
    reset();
    d->tList = head;
}

/*
    Function desc_table

    Aim: 
        shows one table fields and details

    Arguments:
        database => database 
        t        => name of table will shown
*/
void desc_table(database *d, char *t){
    
    tables * head = d->tList;

    int flag = 0;

    for(int a = 0; a < d->n && flag == 0; a++){

        if( strcmp(head->t->tableName, t) == 0){
            yellow();
            printf("__________________________________________________________");
            green();
            printf("\n|%10s|%10s|%10s|%10s|%10s|\n","FIELD","TYPE","NULL","KEY","DATA");
            yellow();
            printf("__________________________________________________________\n");
            cyan();
            for(int b = 0; b < head->t->fieldNum; b++){
                printf("|%10s", head->t->field[b]);

                printf("|%10s", head->t->type[b]);

                printf("|%10d", head->t->isNull[b]);

                printf("|%10d", head->t->isKey[b]);

                printf("|%10s|\n", head->t->data[b]);

                
            }
            yellow();
            printf("__________________________________________________________\n");
            reset();
            flag = 1;
        }   
        else   
            head = head->next;
    }
    red();
    if (flag == 0)
        printf("There is no table named : %s\n", t);
    reset();
}

/*
    Function insert_table

    Aim: 
        create new table with using dynamic memory allocation

    Arguments:
        database => database 
        t        => name of table will create
*/
void insert_table(database *d, char *t, int colNum){

    tables * head  = d->tList;
    

    /* go to last entry*/
    for(int a = 0; a < d->n; a++)
        d->tList = d->tList->next;
    
    /* create dynamic data for table*/
    if(d->n != 0){
        d->tList = (tables *) malloc( sizeof(tables) );
        d->tList->t = (table * ) malloc( sizeof(table) );
    }

    d->tList->t->field =  ( char** ) malloc( colNum * sizeof(char*) );
    d->tList->t->type =  ( char** ) malloc( colNum * sizeof(char*) );
    d->tList->t->data =  ( char** ) malloc( colNum * sizeof(char*) );

    for(int a = 0; a < colNum; a++){
        d->tList->t->field[a] = (char *) malloc( 100 * sizeof(char) );
        d->tList->t->type[a] = (char *) malloc( 100 * sizeof(char) );
        d->tList->t->data[a] = (char *) malloc( 100 * sizeof(char) );
    }

    d->tList->t->tableName = (char *) malloc( strlen(t) * sizeof(char) );

    d->tList->t->isKey  = (int *) malloc( sizeof(int) );
    d->tList->t->isNull = (int *) malloc( sizeof(int) );
    /* end of create dynamic data for table*/

    /* filling with datas */
    d->tList->t->fieldNum = colNum;
    strcpy( d->tList->t->tableName, t );


    red();


    for(int a = 0; a < colNum; a++){
        yellow();
        printf("Enter %d. field name : ",a+1);
        reset();
        scanf("%s", d->tList->t->field[a]);

        d->tList->t->isKey[a] = 0;
        
        yellow();
        printf("Enter %d. field type : ",a+1);
        reset();
        scanf("%s",d->tList->t->type[a]);

        yellow();
        printf("Enter %d. field data : ",a+1);
        reset();
        scanf("%s",d->tList->t->data[a]);

        d->tList->t->isNull[a] = 1;
        printf("\n");
    }
    head->next = d->tList;
    d->tList = head;

    d->n++;
}

/*
    Function remove_table

    Aim: 
        remove specified named table from database

    Arguments:
        database => database 
        t        => name of table will remove
*/
void remove_table(database *d, char *name){
    if(d->n == 0){
        red();
        printf("\n\tPlease create tables firstly after do magic!\n");
        reset();
        return;
    }
    tables * head = d->tList;
    int flag = 0;

    if(strcmp(d->tList->t->tableName,name) == 0){
        if( d->n != 1)
            d->tList = d->tList->next;

        d->n--;
        return;
    }
    else{
        for(int a = 0; a < d->n - 1 && flag == 0; a++){
            if( strcmp(d->tList->next->t->tableName,name) == 0 ){
                d->tList = d->tList->next->next;
                flag = 1;
                d->n--;
            }
            else
                d->tList = d->tList->next;
        }
    }

    red();
    if(flag == 0)
        printf("\tThere is no table named %s\n",name);
    reset();

    d->tList = head;
}   

/*
    Function insert_key

    Aim: 
        add insert_key specified table specified table

    Arguments:
        database  => database 
        tablename => name of table will add key
        key       => name of field we arrange it
*/
void insert_key(database *d, char *tablename, char *key ){
    tables * head = d->tList;
    
    int flag = 0;

    for(int a = 0; a < d->n && flag == 0; a++){
        if( strcmp(d->tList->t->tableName, tablename) == 0 ){
            for(int b = 0; b < d->tList->t->fieldNum; b++){
                if( strcmp(d->tList->t->field[b],key) == 0)
                    d->tList->t->isKey[b] = 1;
            }
            flag = 1;
        }
        else
            d->tList = d->tList->next;
    }

    red();
    if (flag == 0)
        printf("\tThere is no %s tablename or %s Field\n",tablename,key);
    reset();
    d->tList = head;
}


/*
    Function insert_table_for_driver

    Aim: 
        create new table with using dynamic memory allocation for test driver user where do not enter anything

    Arguments:
        database  => database 
        t         => name of table will create
        colnum    => number of col
        fieldName => field name of each row
        fieldType => field type of each row
*/
void insert_table_for_driver(database *d, char *t, int colNum, char  fieldName[][10], char fieldType[][10], char dataField[][10]){

    tables * head  = d->tList;

    /* go to last entry*/
    for(int a = 0; a < d->n; a++)
        d->tList = d->tList->next;
    
    /* create dynamic data for table*/
    if(d->n != 0){
        d->tList = (tables *) malloc( sizeof(tables) );
        d->tList->t = (table * ) malloc( sizeof(table) );
    }

    d->tList->t->field =  ( char** ) malloc( colNum * sizeof(char*) );
    d->tList->t->type =  ( char** ) malloc( colNum * sizeof(char*) );
    d->tList->t->data =  ( char** ) malloc( colNum * sizeof(char*) );

    for(int a = 0; a < colNum; a++){
        d->tList->t->field[a] = (char *) malloc( 100 * sizeof(char) );
        d->tList->t->type[a] = (char *) malloc( 100 * sizeof(char) );
        d->tList->t->data[a] = (char *) malloc( 100 * sizeof(char) );
    }

    d->tList->t->tableName = (char *) malloc( strlen(t) * sizeof(char) );

    d->tList->t->isKey  = (int *) malloc( sizeof(int) );
    d->tList->t->isNull = (int *) malloc( sizeof(int) );
    /* end of create dynamic data for table*/

    /* filling with datas */
    d->tList->t->fieldNum = colNum;
    strcpy( d->tList->t->tableName, t );

    red();

    for(int a = 0; a < colNum; a++){
        strcpy( d->tList->t->field[a], fieldName[a]);
        d->tList->t->isKey[a] = 0;   
        strcpy(d->tList->t->type[a], fieldType[a]);
        strcpy(d->tList->t->data[a], dataField[a]);
        d->tList->t->isNull[a] = 1;
    }
    head->next = d->tList;
    d->tList = head;

    d->n++;
}

/*
    Function writeToDataBase

    Aim: 
        adding data to database db.txt

    Arguments:
        database  => database 
*/
void writeToDataBase(database * db){
    FILE *dbfile;
    tables * head = db->tList;

    dbfile = fopen("db.txt","w");
    if (dbfile == NULL){
        printf("\nError not opened file\n");
    }
    else{
        fprintf(dbfile,"DATABASE_NAME: %s TABLE_COUNT: %d\n",db->name,db->n);

        for(int a = 0; a < db->n ; a++){
            fprintf(dbfile,"TABLE_NAME: %s FIELD_NUM: %d\n",head->t->tableName,head->t->fieldNum);

            for(int b = 0; b < head->t->fieldNum; b++){
                fprintf(dbfile,"%s ",head->t->field[b]);
                fprintf(dbfile,"%s ",head->t->type[b]);
                fprintf(dbfile,"%d ",head->t->isNull[b]);
                fprintf(dbfile,"%d ",head->t->isKey[b]);
                fprintf(dbfile,"%s \n",head->t->data[b]);
            }
            head = head->next;
        }
        fclose(dbfile);
        yellow();
        printf("\tDatabase succesfully writed!\n");
        reset();
    }
}

/*
    Function changeDatabase

    Aim: 
        change current database with older database

    Arguments:
        database  => database 
*/
void changeDatabase(database * db){
    FILE *dbfile;
    

    int n;
    char dbName[100] = {0};
    char tbName[100] = {0};
    char data[100] = {0};
    char temp[100];

    dbfile = fopen("db.txt","r");
    if (dbfile == NULL){
        printf("\nError not opened file\n");
    }
    
    else{
        fscanf(dbfile,"%s %s %s %d",dbName,dbName,temp,&n);
        db->n = 0;
        strcpy(db->name, dbName);

        for(int a = 0; a < n ; a++){
            int colnum;
            fscanf(dbfile,"%s %s %s %d",temp,tbName,temp,&colnum);

            insert_table_fromTXT(db,tbName,colnum,dbfile);
        }        
        yellow();
        printf("\tPrevious database succesfully loaded!\n");
        reset();
        fclose(dbfile);
    }
}
