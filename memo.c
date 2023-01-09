#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "memo.h"

int main(int argc, char *argv[])
{
   if (argc == 1 || argc > 4)
   {  
      listHelp();
      return 0;
   }
   else if (strcmp(argv[1], "-h") == 0 && argc == 2)
   {  
      listHelp();
      return 0;
   }
   else if (strcmp(argv[1], "-i") == 0)
   {
      if ( argc == 2)
         initDatabase("memo.csv");
      else if ( argc == 3) 
         initDatabase(argv[2]);
      else
         printf("Check no. of arguments!\n");   
      return 0;
   }
   else if (strcmp(argv[1], "-a") == 0)
   {
      if ( argc == 3)
         appendMess("memo.csv", argv[2]);
      else if ( argc == 4)
         appendMess(argv[2], argv[3]);
      else
         printf("Check no. of arguments!\n");
		return 0;
   }
   
   listHelp();
   return 1;
}
