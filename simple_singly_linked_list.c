/*----------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class>
 * ---------------------------------------------------------
 * Exercise Number: S01
 * Title:			Simple Singly Linked List implementation
 * Author:			Rudradeep Adhikari
 * ----------------------------------------------------------
 * Description:
 * Implementation of a simple singly linked list.
 * ----------------------------------------------------------
 */

/*
  Implementation notes:

  1) The 'ListData' struct of this linked list SHALL have
     a pointer to the head node of the list as only member!

  2) List and list node allocation: 
     Use functions `mem_alloc(…)` and `mem_free(…)`
     declared in `allocator.h`. DO NOT use `malloc(…)` and `free(…)` directly
     as unit tests will fail.

  3) Use 'limits.h' to get maximum and minimum values for numeric types, if needed.

  4) Avoid code duplication wherever (reasonably) possible.
     This is valid for implementation of similar functions as well
     as for reoccurring code patterns, such as list iteration.
     Nevertheless, aim for efficiency, e.g. `remove_all` shall traverse 
     the list only once and not use `remove` as defined, because
     the later would start at the beginning of the list for each iteration.
*/

#include "simple_singly_linked_list.h"

/** The type of list nodes */


/** The implementation of list node data */

/** The implementation of list data */


/* ===================================================================== */
/* private list functions */

/* abstract away and generalize also memory allocation for list nodes */
static <node-type> list_obtain_node(<params>) {
}

static void list_release_node(<node-type>) {
}

/* optional: implement a function for printing the content of the list - may be useful for debugging */
void list_dump(char* prefix, IntList list) {
}

/* ===================================================================== */
