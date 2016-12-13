#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	int value;
	char* name;
	struct node* next;
}node;

typedef struct head{
	node* first;
}head;


node* create_node(head* , int , char* );

void print_list(head* );

int length_list(head* );

int isExists(head* , char* );

void clear_list(head* );
