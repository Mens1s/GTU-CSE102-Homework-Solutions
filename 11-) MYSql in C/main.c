#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

int main(){

    database * db;

    int flag = 0;
    int dbCheck = 0;
    char command[100] = {0};
    int count = 0;

    yellow();
    printf("<=================================================>\n");
    cyan();
    printf("<====    Welcome LAST HOMEWORK of CSE-102     ====>\n");
    printf("<====  If you need any help type -h or --help ====>\n");
    printf("<====    Ahmet Yigit 200104004066 as MENS1S   ====>\n");
    printf("<==== You can visit more code @ github/mens1s ====>\n");
    yellow();
    printf("<=================================================>\n");
    reset();

    while(flag == 0){

        strcpy(command,"");

        printf("\033[1;32mmens1s@Mens1s_SQL\033[0m$ ");
        scanf("%[^\n]%*c", command);

        count = wordCounter(command);

        if(strncmp(command,"CREATE DATABASE",15) == 0 && count == 3){
            char dbName[100] = {0};


            sscanf(command,"%s %s %s",dbName,dbName,dbName);
            
            db = create_database(dbName);
            db->tList = (tables *) malloc( sizeof(tables) );
            db->tList->t = (table * ) malloc( sizeof(table) );

            yellow();
            printf("\tYour '%s' named database created succesfully!\n",db->name);
            reset();

            dbCheck = 1;
        }
        else if(strcmp(command,"EXIT") == 0 ){
            flag = 1;
            yellow();
            printf("\tThanks for using us!\n");
            reset();
        }
        else if(strncmp(command,"-h",15) == 0 && count == 1 || strncmp(command,"--help",15) == 0 && count == 1){
            cyan();
            printf("Commands : \n");
            printf("\t\033[0;32mCREATE DATABASE <databaseName>                        =>\033[1;33m This function create new database\n\n");
            printf("\t\033[0;32mSHOW TABLES                                           =>\033[1;33m This function show all tables and fields in the database\n\n");
            printf("\t\033[0;32mDESCRIBE <tableName>                                  =>\033[1;33m This function shows all field of <name> table\n\n");
            printf("\t\033[0;32mCREATE TABLE <tableName> <fieldCount>                 =>\033[1;33m This function create new table\n\n");
            printf("\t\033[0;32mDROP TABLE <tableName>                                =>\033[1;33m This function removes table\n\n");
            printf("\t\033[0;32mALTER TABLE <tableName> ADD PRIMARY KEY(<fieldName>)  =>\033[1;33m This function adds primary key speciality to field\n\n");
            printf("\t\033[0;32mCHANGE PREVIOUS DATABASE                              =>\033[1;33m This function changes database to old one\n\n");
            printf("\t\033[0;32mWRITE CHANGES DATABASE                                =>\033[1;33m This function writes changes to database and erase last entries\n\n");
            printf("\t\033[0;32mEXIT                                                  =>\033[1;33m Exit and finish the program\n\n");

        } 
        else if(strcmp(command,"CHANGE PREVIOUS DATABASE") == 0){
            dbCheck = 1;
            db = create_database("null");
            db->tList = (tables *) malloc( sizeof(tables) );
            db->tList->t = (table * ) malloc( sizeof(table) );
            changeDatabase(db);
        }
        else if(dbCheck == 0){
            red();
            printf("\n\tPlease create database firstly after do magic!\n");
            reset();
        }
        else if(strcmp(command,"WRITE CHANGES DATABASE") == 0){
            writeToDataBase(db);
        }    
        else{
            if( strncmp(command,"SHOW TABLES",12) == 0 && count == 2 ) {
                show_table(db);
            }

            else if(strncmp(command,"DESCRIBE",8) == 0 && count == 2){
                char tbName[100] = {0};
                sscanf(command,"%s %s",tbName,tbName);
                desc_table(db,tbName);
            }

            else if(strncmp(command,"CREATE TABLE",8) == 0 && count == 4){
                char tbName[100] = {0};
                int fieldCount;
                sscanf(command,"%s %s %s %d",tbName,tbName,tbName,&fieldCount);

                insert_table(db,tbName,fieldCount);
                clean_stdin();
            }

            else if(strncmp(command,"DROP TABLE",10) == 0 && count == 3){
                char tbName[100] = {0};
                sscanf(command,"%s %s %s",tbName,tbName,tbName);
                remove_table(db,tbName);
                
                green();
                printf("\tYour remove table operation has done succesfully.\n");
                reset();
            }

            else if(strncmp(command,"ALTER TABLE",11) == 0 && count == 6){
                char tbName[100] = {0}, keyField[100] = {0};

                sscanf(command,"%s %s %s %s %s %s",tbName,tbName,tbName,keyField,keyField,keyField);

                char realKeyField[100] = {0};

                for(int a = 4 ; a < strlen(keyField) - 1; a++)
                    realKeyField[a-4] = keyField[a];

                insert_key(db,tbName,realKeyField);

                green();
                printf("\tYour insert key operation has done succesfully.\n");
                reset();
            }

            else{
                red();
                printf("\n\tWrong command if you need help you can type -h or github page!\n");
                reset();
            }
        }
    }
}

