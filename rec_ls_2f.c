//Copyright Kopinjol Baishya
//email = kopinjol@gmail.com
//website = kopinjol.github.io

#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <glob.h>
#include "sys/stat.h"

void dir_search();


int main(int argc, char *argv[]) {
  char **found;
  glob_t gstruct;
  FILE *fptr;
  regex_t regex;
  int r, r1, isd, i, j;
  struct stat buf;

  char *command = "ls -la > list.txt";
  setenv( "HOME_NOW", argv[2], 1 );
  char *command_0 = "cd $HOME_NOW";
  char *command_1 = "pwd";
  system( command );
  system( command_0 );
  system( command_1 );
  r = glob("*.*", GLOB_ERR, NULL, &gstruct);
  if( r != 0 ) {
    if ( r==GLOB_NOMATCH )
      fprintf(stderr, "No matches. \n");
    else
      fprintf(stderr, "Some kind of glob error. \n");
      exit(1);
  }
  printf("Found %zu filename matches\n", gstruct.gl_pathc);
  found = gstruct.gl_pathv;
  while( *found ) {
    printf( "%s\n", *found);
    //printf("After the found. \n");
    r1 = stat( *found, &buf );
    if( r1 == -1 ) {
      printf( "File couldnot be stated. \n" );
    }
    isd = S_ISDIR(buf.st_mode);
    if( isd != 0 ) {
      //dir_search();
      printf("isd ne zero! \n");

    }
    *found = *found + sizeof(*found);

  }

}

void dir_search(){
  
    int r, r1, isd;
    char **found;
    glob_t gstruct;
    FILE *fptr;
    regex_t regex;
    struct stat buf;


    r = glob("*.*", GLOB_ERR, NULL, &gstruct);
    if( r != 0 ) {
        if ( r==GLOB_NOMATCH )
            fprintf(stderr, "No matches. \n");
        else
            fprintf(stderr, "Some kind of glob error. \n");
            exit(1);
    }
    printf("Found %zu filename matches\n", gstruct.gl_pathc);
    found = gstruct.gl_pathv;
    while( *found ) {
        printf( "%s\n", *found );
        r1 = stat( *found, &buf );
        if( r1 == -1 ) {
            printf( "File couldnot be stated. \n" );
        }
        isd = S_ISDIR(buf.st_mode);
        if( isd != 0 ) {
            dir_search();
        }

    }

}
