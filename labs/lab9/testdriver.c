#include <stdio.h>
#include "dataStructure.h" // Assuming your list implementation is in list.h and list.c

int main() {
  list_t * list = list_create();
  if (list == NULL) {
    printf("Error: Could not create list\n");
    return 1;
  }

  if (list_append(list, 1) != LIST_OK) {
    printf("Error: Could not append element\n");
    return 1;
  }

  if (list_prepend(list, 0) != LIST_OK) {
    printf("Error: Could not prepend element\n");
    return 1;
  }

  element_t * found = list_find(list, 1);
  if (found == NULL || found->val != 1) {
    printf("Error: Could not find element\n");
    return 1;
  }

  if (list_removeFront(list) != LIST_OK) {
    printf("Error: Could not remove front element\n");
    return 1;
  }

  if (list_destroy(list) != LIST_OK) {
    printf("Error: Could not destroy list\n");
    return 1;
  }

  printf("All tests passed!\n");
  return 0;
}
