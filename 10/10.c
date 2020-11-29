/* Caleb Catt Homework Chapter 10 */

#include <stdio.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{
  FILE* input;
  struct stat stats;
  char* name = malloc(sizeof(64));
  char* directoryStart = "Folders/";

  input = fopen("names.txt","r");
  while(fgets(name,64,input)) {
    int folder;
    char* folderName;
    //Formatting to "Folder/Name"
    strtok(name, "\n"); // This is an interesting internet find - This will remove the issue I was having on the previous version of printing a new line character
    strcpy(folderName,directoryStart);
    strcat(folderName, name);

    if(stat(folderName, &stats) == 0){
      if(S_ISDIR(stats.st_mode)){
        printf("User already exists: %s\n", folderName);
      }
    }
    else {
      folder = mkdir(folderName, S_IRWXU);
      printf("Directory created for %s\n", folderName);
    }
  }
  return 0; 
}