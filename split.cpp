/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE

  if(in == NULL){
    return;
  }
  Node* temp = in;
  in = in->next;
  if(temp->value%2!=0){
    temp->next = odds;
    odds = temp;
    split(in,odds,evens);
  }else{
    temp->next = evens;
    evens = temp;
    split(in,odds,evens);
  }
}

/* If you needed a helper function, write it here */
