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

#include "allocator.h"
#include "simple_singly_linked_list.h"

typedef struct IntListNodeData* IntListNode;

struct IntListNodeData
{
   int data;
   IntListNode next;
};

struct IntListData
{
   IntListNode head;
};

static IntListNode list_obtain_node(int data) {
   IntListNode node = (IntListNode)alloc_mem(sizeof(struct IntListNodeData));

   node->data = data;
   node->next = 0;
   return node;
}

static void list_release_node(IntListNode node)
{
   if(node->next != 0) {
      list_release_node(node->next);
   }
   free_mem(node);
}

void list_dump(char *prefix, IntList list) {
   return;
}

    IntList list_obtain()
{

   IntList intList = alloc_mem(sizeof(struct IntListData));

   if (intList != 0)
   {
      intList->head = 0;
   }
   return intList;
}

void list_release(IntList *p_list)
{
   if (p_list != 0 && *p_list != 0)
   {
      IntList list = *p_list;
      IntListNode current = list->head;

      if (current != 0) {
         list_release_node(current);
      }
      free_mem(list);
      *p_list = 0;
   }
}

bool list_is_valid(IntList list)
{
   return list != 0;
}

bool list_is_empty(IntList list)
{
   if (!list_is_valid(list))
   {
      return true;
   }

   return list->head == 0;
}

int list_get_size(IntList list)
{
   if (!list_is_valid(list))
   {
      return 0;
   }

   if (list_is_empty(list))
   {
      return 0;
   }

   int size = 0;
   IntListNode current = list->head;
   while (current != 0)
   {
      size++;
      current = current->next;
   }

   return size;
}

bool list_contains(IntList list, int value)
{
   if (!list_is_valid(list) || list_is_empty(list))
   {
      return false;
   }

   IntListNode current = list->head;
   while (current != 0)
   {
      if (current->data == value) {
         return true;
      }

      current = current->next;
   }

   return false;
}

int list_get_at(IntList list, unsigned int index)
{
   if (!list_is_valid(list) || list_is_empty(list)) {
      return 0;
   }

   unsigned int i = 0;
   IntListNode current = list->head;
   while (current != 0)
   {
      if (i == index) {
         return current->data;
      }
      current = current->next;
      i++;
   }

   return 0;
}

void list_insert(IntList list, int value)
{
   if (list_is_valid(list)){
      IntListNode newNode = list_obtain_node(value);

      if (list_is_empty(list)){
         list->head = newNode;
         return;
      }

      IntListNode current = list->head;
      while (current->next != 0){
         current = current->next;
      }

      current->next = newNode;
   }
}

void list_insert_at(IntList list, unsigned int index, int value)
{
   if (!list_is_valid(list)){
      return;
   }

   IntListNode newNode = list_obtain_node(value);

   if (list_is_empty(list)) {
      list->head = newNode;
      return;
   }

   if (index == 0){
      newNode->next = list->head;
      list->head = newNode;
      return;
   }

   unsigned int i = 0;
   IntListNode current = list->head;
   IntListNode previous = 0;

   while (current != 0 && i < index){
      previous = current;
      current = current->next;
      i++;
   }

   previous->next = newNode;
   newNode->next = current;
}

void list_append(IntList list, IntList list_to_append)
{
   if (!list_is_valid(list_to_append) || list_is_empty(list_to_append)){
         return;
      }

   if (list_is_empty(list)) {
      list->head = list_to_append->head;
   }
   else{
      IntListNode current = list->head;
      while (current->next != 0){
         current = current->next;
      }

      current->next = list_to_append->head;
   }

   list_to_append->head = 0;
}

void list_remove(IntList list, int value)
{
   if (!list_is_valid(list) || list_is_empty(list)){
      return;
   }

   if (list->head->data == value){
      IntListNode old_head = list->head;
      list->head = list->head->next;
      list_release_node(old_head);
      return;
   }

   IntListNode current = list->head;
   while (current->next != 0){
      if (current->next->data == value){
         IntListNode to_remove = current->next;
         current->next = to_remove->next;
         list_release_node(to_remove);
         return;
      }
      current = current->next;
   }
}

void list_remove_all(IntList list, int value)
{
   if (!list_is_valid(list) || list_is_empty(list)){
      return;
   }

   while (list->head != 0 && list->head->data == value){
      IntListNode old_head = list->head;
      list->head = list->head->next;
      list_release_node(old_head);
   }

   if (list_is_empty(list)){
      return;
   }

   IntListNode current = list->head;
   while (current->next != 0){
      if (current->next->data == value){
         IntListNode to_remove = current->next;
         current->next = to_remove->next;
         list_release_node(to_remove);
      }else{
         current = current->next;
      }
   }
}

int list_remove_at(IntList list, unsigned int index)
{
   if (!list_is_valid(list) || list_is_empty(list)){
      return 0;
   }

   if (index == 0){
      int value = list->head->data;
      IntListNode old_head = list->head;
      list->head = list->head->next;
      list_release_node(old_head);
      return value;
   }

   unsigned int i = 0;
   IntListNode current = list->head;
   IntListNode previous = 0;

   while (current != 0 && i < index){
      previous = current;
      current = current->next;
      i++;
   }

   if (current == 0){
      return 0;
   }

   int value = current->data;
   previous->next = current->next;
   list_release_node(current);
   return value;
}

void list_clear(IntList list)
{
   if (!list_is_valid(list) || list_is_empty(list)){
      return;
   }

   IntListNode current = list->head;
   while (current != 0){
      IntListNode next = current->next;
      list_release_node(current);
      current = next;
   }

   list->head = 0;
}
