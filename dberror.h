#ifndef DBERROR_H
#define DBERROR_H

#include "stdio.h"

/* module wide constants */
#define PAGE_SIZE 4096

/* return code definitions */
typedef int RC;

#define RC_OK 0
#define RC_FILE_NOT_FOUND 1
#define RC_FILE_HANDLE_NOT_INIT 2
#define RC_WRITE_FAILED 3
#define RC_READ_NON_EXISTING_PAGE 4

//buffer pool errors, assign2
#define RC_BP_NOT_EXIST 5
#define RC_BP_PAGE_NUM_ILLEGAL 6
#define RC_BP_NOT_INIT 7
#define RC_BP_WRITE_BACK_FAILED 8
#define RC_BP_PAGE_NOT_EXIST 9
#define RC_OPEN_FAILED 10
#define RC_BP_NO_AVAILABLE_FRAME 11
#define RC_BP_STRATEGY_ILLEGAL 12
#define RC_BP_FRAME_NOT_FOUND 13

//record manager errors, assign3
#define RC_RM_PINPAGE_FAILED 14
#define RC_RM_MARKDIRTY_FAILED 15
#define RC_RM_UNPIN_FAILED 16
#define RC_RM_CREATE_PAGE_FAILED 17
#define RC_RM_INIT_BUFFER_POOL_FAILED 18
#define RC_RM_INIT_TABLE_FAILED 19
#define RC_RM_SHUTDOWN_BUFFER_POOL_FAILED 20
#define RC_RM_FORCE_PAGE_FAILED 21
#define RC_RM_TABLE_NOT_EXIST 22
#define RC_RM_DESTROY_PAGE_FAILED 23
#define RC_RM_PAGE_NOT_EXIST 24
#define RC_RM_SLOT_NOT_EXIST 25
#define RC_RM_SCHEMA_NOT_EXIST 26
#define RC_RM_SCHEMA_INIT_FAIL 27
#define RC_RM_TABLE_NOT_OPEN 28





#define RC_RM_COMPARE_VALUE_OF_DIFFERENT_DATATYPE 200
#define RC_RM_EXPR_RESULT_IS_NOT_BOOLEAN 201
#define RC_RM_BOOLEAN_EXPR_ARG_IS_NOT_BOOLEAN 202
#define RC_RM_NO_MORE_TUPLES 203
#define RC_RM_NO_PRINT_FOR_DATATYPE 204
#define RC_RM_UNKOWN_DATATYPE 205

#define RC_IM_KEY_NOT_FOUND 300
#define RC_IM_KEY_ALREADY_EXISTS 301
#define RC_IM_N_TO_LAGE 302
#define RC_IM_NO_MORE_ENTRIES 303

/* holder for error messages */
extern char *RC_message;

/* print a message to standard out describing the error */
extern void printError (RC error);
extern char *errorMessage (RC error);

#define THROW(rc,message) \
  do {			  \
    RC_message=message;	  \
    return rc;		  \
  } while (0)		  \

// check the return code and exit if it is an error
#define CHECK(code)							\
  do {									\
    int rc_internal = (code);						\
    if (rc_internal != RC_OK)						\
      {									\
	char *message = errorMessage(rc_internal);			\
	printf("[%s-L%i-%s] ERROR: Operation returned error: %s\n",__FILE__, __LINE__, __TIME__, message); \
	free(message);							\
	exit(1);							\
      }									\
  } while(0);


#endif