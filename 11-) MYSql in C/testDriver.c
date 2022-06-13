#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

void stage1();
void stage2();
void stage3();
void stage4();

int main(){
    red();
    printf("\n\n\n--------------------------------------\n");
    printf("STAGE 1 | Basic operations \n\n\n");
    stage1();
    reset();

    red();
    printf("\n\n\n--------------------------------------\n");
    printf("STAGE 2 | Mid level operations \n\n\n");
    stage2();
    reset();


    red();
    printf("\n\n\n--------------------------------------\n");
    printf("STAGE 3 | ALL OPERATIONS except READ DATA\n\n\n");
    stage3();
    reset();

    red();
    printf("\n\n\n--------------------------------------\n");
    printf("STAGE 4 | ALL OPERATIONS from Saved DATA\n\n\n");
    stage4();
    reset();
}

/*
    Function stage1

    Aim: 
        testing basics of function

        creating database, table showing and describing tables also remove
*/
void stage1(){
    database * db;

    red();
    printf("Creating database named vehicle...\n");
    db = create_database("vehicle");
    db->tList = (tables *) malloc( sizeof(tables) );
    db->tList->t = (table * ) malloc( sizeof(table) );
    green();
    printf("Succesfully created...\n\n");

    red();
    printf("Creating table named car with 3 field...\n");
    char names[3][10], types[3][10], datas[3][10];
    strcpy(datas[0],"Sedan"); strcpy(datas[1],"2021"); strcpy(datas[2],"True");
    strcpy(names[0],"MODEL"); strcpy(names[1],"MOD_YEAR"); strcpy(names[2],"isAuto");
    strcpy(types[0],"char(40)");strcpy(types[1],"int");strcpy(types[2],"bool");
    insert_table_for_driver(db, "car", 3, names , types, datas);

    red();
    printf("Showing tables...\n");
    reset();
    show_table(db);
    green();
    printf("Succesfully showed...\n\n");
    reset();

    red();
    printf("Describing bike table...\n");
    reset();
    desc_table(db,"bike");
    green();
    printf("Succesfully showed...\n\n");
    reset();

    red();
    printf("Droping car table ...\n");
    reset();
    green();
    printf("Succesfully removed...\n\n");
    reset();
    remove_table(db,"car");
    desc_table(db,"car");
    show_table(db);
}

/*
    Function stage2

    Aim: 
        testing mid level of function

        creating database, table showing and describing tables also remove 
        control of undefined valeus such as when database hold only car table we want to remove bike
*/
void stage2(){
    database * db;

    red();
    printf("Creating database named vehicle...\n");
    db = create_database("vehicle");
    db->tList = (tables *) malloc( sizeof(tables) );
    db->tList->t = (table * ) malloc( sizeof(table) );
    green();
    printf("Succesfully created...\n\n");

    red();
    printf("Creating table named car with 3 field...\n");
    char names[3][10], types[3][10], datas[3][10];
    strcpy(datas[0],"Sedan"); strcpy(datas[1],"2021"); strcpy(datas[2],"True");
    strcpy(names[0],"MODEL"); strcpy(names[1],"MOD_YEAR"); strcpy(names[2],"isAuto");
    strcpy(types[0],"char(40)");strcpy(types[1],"int");strcpy(types[2],"bool");
    insert_table_for_driver(db, "car", 3, names , types, datas);

    printf("Describing car table ...\n");
    desc_table(db,"car");
    red();
    printf("Droping car table ...\n");
    reset();
    remove_table(db,"car");
    green();
    printf("Succesfully removed...\n\n");
    reset();
    
    printf("Dropping car table again..\n\n");
    red();
    printf("Droping car table ...\n");
    reset();
    remove_table(db,"car");
    green();
    printf("Succesfully removed...\n\n");
    reset();

    printf("Creating table named bike with 2 field...\n");
    char names2[3][10], types2[3][10], datas2[3][10];

    strcpy(datas2[0],"2012"); strcpy(datas2[1],"220");
    strcpy(names2[0],"MOD_YEAR"); strcpy(names2[1],"topSpeed");
    strcpy(types2[0],"int");strcpy(types2[1],"int");
    insert_table_for_driver(db, "bike", 2, names2 , types2, datas2);
    green();
    printf("Succesfully created...\n\n");

    red();
    printf("Describing bike table...\n");
    reset();
    desc_table(db,"bike");
    green();
    printf("Succesfully showed...\n\n");
    reset();

    red();
    printf("Adding primary key bike table topSpeed field...\n");
    reset();
    insert_key(db,"bike","topSpeed");
    desc_table(db,"bike");
    green();
    printf("Succesfully added...\n\n");
    reset();

}

/*
    Function stage2

    Aim: 
        testing last level of function

        all functions tested...
*/
void stage3(){
    database * db;

    red();
    printf("Creating database named vehicle...\n");
    db = create_database("vehicle");
    db->tList = (tables *) malloc( sizeof(tables) );
    db->tList->t = (table * ) malloc( sizeof(table) );
    green();
    printf("Succesfully created...\n\n");

    red();
    printf("Creating table named car with 3 field...\n");
    char names[3][10], types[3][10], datas[3][10];
    strcpy(datas[0],"Sedan"); strcpy(datas[1],"2021"); strcpy(datas[2],"True");
    strcpy(names[0],"MODEL"); strcpy(names[1],"MOD_YEAR"); strcpy(names[2],"isAuto");
    strcpy(types[0],"char(40)");strcpy(types[1],"int");strcpy(types[2],"bool");
    insert_table_for_driver(db, "car", 3, names , types, datas);

    printf("Creating table named bike with 2 field...\n");
    char names2[3][10], types2[3][10], datas2[3][10];

    strcpy(datas2[0],"2012"); strcpy(datas2[1],"220");
    strcpy(names2[0],"MOD_YEAR"); strcpy(names2[1],"topSpeed");
    strcpy(types2[0],"int");strcpy(types2[1],"int");
    insert_table_for_driver(db, "bike", 2, names2 , types2, datas2);
    green();
    printf("Succesfully created...\n\n");

    red();
    printf("Showing tables...\n");
    reset();
    show_table(db);
    green();
    printf("Succesfully showed...\n\n");
    reset();

    red();
    printf("Describing car table...\n");
    reset();
    desc_table(db,"car");
    red();
    printf("Describing bike table...\n");
    reset();
    desc_table(db,"bike");
    green();
    printf("Succesfully showed...\n\n");
    reset();

    red();
    printf("Adding primary key car table isAuto field...\n");
    reset();
    insert_key(db,"car","isAuto");
    desc_table(db,"car");
    green();
    printf("Succesfully added...\n\n");
    reset();

    red();
    printf("Writing database to file...\n");
    reset();
    writeToDataBase(db);
    green();
    printf("Succesfully writed...\n\n");
    reset();

    red();
    printf("Droping car table ...\n");
    reset();
    remove_table(db,"car");
    green();
    printf("Succesfully removed...\n\n");
    reset();
    desc_table(db,"car");
    show_table(db);
}

/*
    Function stage4

    Aim: 
        testing last level of function with getting information from db.txt file

*/
void stage4(){
database * db;

    red();
    printf("Creating database named vehicle...\n");
    db = create_database("vehicle");
    db->tList = (tables *) malloc( sizeof(tables) );
    db->tList->t = (table * ) malloc( sizeof(table) );
    green();
    printf("Succesfully created...\n\n");
    
    red();
    printf("Changing database to old one...\n");
    reset();
    changeDatabase(db);
    green();
    printf("Succesfully changed...\n\n");
    reset();

    red();
    printf("Showing tables...\n");
    reset();
    show_table(db);
    green();
    printf("Succesfully showed...\n\n");
    reset();

    red();
    printf("Describing car table...\n");
    reset();
    desc_table(db,"car");
    red();
    printf("Describing bike table...\n");
    reset();
    desc_table(db,"bike");
    green();
    printf("Succesfully showed...\n\n");
    reset();

    red();
    printf("Adding primary key car table isAuto field...\n");
    reset();
    insert_key(db,"car","isAuto");
    desc_table(db,"car");
    green();
    printf("Succesfully added...\n\n");
    reset();

    red();
    printf("Writing database to file...\n");
    reset();
    writeToDataBase(db);
    green();
    printf("Succesfully writed...\n\n");
    reset();

    red();
    printf("Droping car table ...\n");
    reset();
    remove_table(db,"car");
    green();
    printf("Succesfully removed...\n\n");
    reset();
    desc_table(db,"car");
    show_table(db);
}