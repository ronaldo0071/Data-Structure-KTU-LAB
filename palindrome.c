#include<stdio.h>  
#include<stdlib.h> 
#include<string.h>

struct Node { 
    int data; 
    struct Node* next;
    struct Node* prev; 
};
void getNode(struct Node** start, char new_data) {
   struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = new_data;
   newNode->next = (*start);
   newNode->prev = NULL;
   if ((*start) != NULL)
      (*start)->prev = newNode ;
      (*start) = newNode;
}
int isPalindrome(struct Node *start) {
   if (start == NULL)
      return 1;
   struct Node *end = start;
   while (end->next != NULL)
      end = end->next;
   while (start != end && end != start->prev) {
      if (start->data != end->data)
         return 0;
      start = start->next;
      end = end->prev;
   }
return 1;
}
int main() {
  struct Node* head = NULL;
   char s[100];
   printf("Enter the string::\n");
   gets(s);
   for(int i = 0; i< strlen(s); i++){
      getNode(&head, s[i]);
   }
   if (isPalindrome(head))
      printf("String is a Palindrome");
   else
      printf("String is NOT a Palindrome");
}