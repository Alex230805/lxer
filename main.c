#include <stdio.h>
#include <stdlib.h>
#include "lxer.h"

lxer_head lxer = {0};
Arena_header ah = {0};

#define SOURCE "test_file.txt"

typedef struct{
  char* name;
  int id;
}program;




int main(){
  program pg = {0};

  NOTY("LXER TESTING PROGRAM","testing lxer by implementing a simple parser: ", NULL);
  StringBuilder* sb = read_file(&ah, SOURCE);
  printf("Content of "SOURCE": \n\n%s\n\n", sb->string);
  lxer_start_lexing(&lxer, sb->string);
  lxer_get_lxer_content(&lxer);

  NOTY("parser","Start parsing the example", NULL);
  if(lxer_get_current_token(&lxer) == LXR_OPEN_CRL_BRK){
    if(lxer_brk_expect_sep(&lxer)){
      char* program_name = lxer_get_rh(&lxer, false);
      if(strcmp(program_name, "program_name") != 0 || strlen(program_name) < 1){
        WARNING("Unable to find the program name of the process", NULL);
        goto abort;
      }
      lxer_next_token(&lxer); 
      lxer_next_token(&lxer);
      if(lxer_get_current_token(&lxer) == LXR_DOUBLE_QUOTE){
        size_t tracker_lh = lxer.lxer_tracker;
        size_t tracker_rh = 0;
        lxer_next_token(&lxer);
        while(lxer_get_current_token(&lxer) != LXR_DOUBLE_QUOTE) lxer_next_token(&lxer);
        tracker_rh = lxer.lxer_tracker;
        char* name = lxer_get_rh_in_between(&lxer, tracker_lh, tracker_rh);
        if(strlen(name) < 1){
          WARNING("Cannot have empty string, fix it!", NULL);
          goto abort;
        }
        LXR_TOKENS current_token = lxer_get_current_token(&lxer);
        lxer_next_token(&lxer);
        if(current_token != LXR_DOUBLE_QUOTE && lxer_get_current_token(&lxer) != LXR_COMMA){
          WARNING("Invalid syntax", NULL);
          goto abort;
        }
        pg.name = name;
        lxer_next_token(&lxer);
        if(lxer_get_current_token(&lxer) == LXR_DOUBLE_DOTS){
          if(strcmp(lxer_get_rh(&lxer, true), "memory_index") != 0){
            WARNING("You must define a lable 'memory_index' to proceed", NULL);
            goto abort;
          }
          char* process_id = lxer_get_rh(&lxer, false);
          if(strlen(process_id) < 1){
            WARNING("Invalid process id", NULL);
            goto abort;
          }
          pg.id = atoi(process_id);
          lxer_next_token(&lxer);
          if(lxer_get_current_token(&lxer) != LXR_CLOSE_CRL_BRK){
            WARNING("Not a valid program name", NULL);
            goto abort;
          }
        }else{
          WARNING("Invalid syntax", NULL);
          goto abort;
        }
      }
    }else{
      WARNING("Invalid section", NULL);
      goto abort;
    }
  }
  NOTY("LXER test case", "parsed output from the internal struct composed by lxer", NULL);
  printf("Program name: %s\n", pg.name);
  printf("Program id: %d\n", pg.id);
  
abort:
  arena_free(&ah);
  arena_free(&lxer.lxer_ah);
  return 0;
}
