/**
* @mainpage
* @section intro Introduction
*
* The implementation of a "Simple Singly Linked List".
* 
* @section objective Assignment Objective
* In this assignment an Abstract Data Type of a "Simple Singly Linked List" shall be implemented against 
* the defined common interface of a list. This interface is declared within file 'list.h'. It is intended
* to be used by applications or other libraries and aims to abstract the 'list' functionality as far as possible.
*
* The term 'simple' in 'Simple Singly Linked List' refers to the limited members of the list data:
* the pointer to the list head node is the only member of list data.
* 
* **Configuration**
*
* There is no configuration required.
*
* @section assignment Assignment
* The 'Simple Singly Linked List' shall be implemented in file 'simple_singly_linked_list.c'. The corresponding header file
* includes the common interface 'list.h' but does not add functions by its own.
*
* The library 'allocator' is provided for memory allocation functionality that integrates with unit testing. Behind the facade,
* allocats memory dynamically similar to `malloc`. Allocated memory must be freed when it is not used anymore. The 'allocator'
* library must be used for memory alloction operations, otherwise unit tests will fail.
* 
*
* -# Implement 'simple_singly_linked_list.c' against interface indirectly declared in 'list.h':
*    Make the program and tests compile: Implement all functions in all relevant files declared in the headers 
*    EMTPY (return nothing, 0, false, ... as required).
*   - All unit tests shall run but FAIL after this step
*   - **--COMMIT--**
* -# Implement the empty functions one by one to make the unit tests pass one by one.
*   - The purpose of a function is specified as API documentation within the header files.
*   - Obey comments in source files. Run the unit tests frequently and fix failures.
*   - **--COMMIT-- after each implemented function.**
*
* Main driver is not required in this assignment.
*
* @section notes Notes
* -# make cleantest: This new make target for clearing the console, building, and running unit test is available.
* -# Sometimes changes are not properly detected by incremental builds. If something very strange 
*    happens during compilation, try to run `make clean` followed by `make` to start a clean build.
*    This approach is also recommended after everthing is done, because some compiler warning appears
*    only in clean builds. 
*/