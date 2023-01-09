/*
    All functions have to be written in a file called "libmemo.c" and need
    to be compiled as an independent object file (.o) that will be
    linked with the main program object file "memo.o" to create the
    final program "memo".
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#include "memo.h"

void listHelp(void)
{
   // print out help messege on terminal
   printf("\n-h Show this help.\n");

   printf("\n-i Init a new empty database. For example:\n   memo -i \"memo.csv\"\n"   
            "   Creates a new empty database with the name memo.csv\n");

   printf("\n-a Append at the end of the database the following message.\n"
            "   memo -a \"This message will be included at the end of the database memo.csv\"\n"
            "   memo -a yourname.csv \"This message will be included in the specified database (yourname.csv)\"\n");

   printf("\n-s (in development) Search and find specific entries in the database.\n"
            "   memo -s \"09-11-2022\" will show all entries at a this given date.\n"
            "   memo -s \"programming\" will show all entries containing the word \"programming\".\n");

   printf("\n-d (in development) Delete an entry in the database.\n   memo -d 123 will delete entry number 123.\n\n");
}

int initDatabase(char *dbName)
{
   // open file in write/read mode
   FILE *fpt;
   fpt = fopen(dbName, "w+");

   // print out a header in file
   fprintf(fpt, "%s\n", "id,dateTime,message");
   fclose(fpt);

   // print to the console what db was created
   printf("Database \"%s\" created.\n", dbName);

   return 0;
}

int appendMess(char *dbName, char *message)
{  
   // get date and time
   time_t currTime;
   struct tm *currTime_info;
   char myTime[21];
   
   time(&currTime);
   currTime_info = localtime(&currTime);

   // format the time represented in the structure tm according to the formatting rules defined in the 3rd argument and store it into myTime
   strftime(myTime, sizeof(myTime), "%Y-%m-%d %H:%M:%S", currTime_info);

   // declare variables and char array/pointer
   char newLine[MAX_LINE];
   char *tokenPtr;
   int id;

   // open file in appendmode
   FILE *fpt;
   fpt = fopen(dbName, "a+"); 

   // if file does not exit print error message
   if (!fpt) 
   {  
     printf("Error: file does not exist!\n");
     exit(1);
   }

   // read a string from file pointed to by fpt and store it in the char array newLine of MAX_LINE size 
   // check for delimiter "," in newLine (returns the first token) and store it in tokenPtr
   // loop through all contet of the file until the end-of-file is reached (!feof(fpt))
   do
   {
      fgets(newLine, MAX_LINE, fpt);
      tokenPtr = strtok(newLine, ",");
   } while ( feof(fpt) != true );

   // convert tokenPtr to intiger and store it in id and increment id with 1 for every new append
   id = atoi(tokenPtr); 
   id += 1;

   //print out a new line in file seperated by commas
   fprintf(fpt,"%d,%s,%s\n", id, myTime, message);
   fclose(fpt);

   // print out on the console what memo (note) was created and in which database
   printf("memo \"%d\" created in %s.\n", id, dbName);

   return 0;
}
