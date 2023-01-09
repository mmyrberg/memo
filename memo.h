/*
    All the function declarations, struct and macro
    need to be inside an header file called "memo.h".
*/
#ifndef MEMO_H
#define MEMO_H

#define MAX_LINE 1024

void listHelp(void);
int initDatabase(char *dbName);
int appendMess(char *dbName, char *message);

#endif