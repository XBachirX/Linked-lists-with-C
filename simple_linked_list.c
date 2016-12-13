#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simple_linked_list.h"

node* create_node(head* h, int n_value, char* n_name){
	//Dynamic allocation of the node
	node* nd = (node *)malloc(sizeof(node));
	nd->name = (char *)malloc(sizeof(n_name) + 1);
	strcpy(nd->name, n_name);
	nd->value = n_value;
	nd->next = NULL;

	//Inserting the node at the end of the list
	node* tmp = h->first;
	if(!tmp){ //if the list is empty
		h->first = nd;
	}else{
		while(tmp->next){
			tmp = tmp->next;
		}
		tmp->next = nd;
	}
	return nd;
}

void print_list(head* h){
	node* tmp = h->first;
	int i = 0;
	while(tmp){
		printf("Node[%d]\tname: %s\t value: %d\n", ++i, tmp->name, tmp->value);
		tmp = tmp->next;
	}
}

int length_list(head* h){
	int i = 0;
	node* tmp = h->first;
	while(tmp){
		i++;
		tmp = tmp->next;
	}
	return i;
}

int isExists(head* h, char* n_name){
	int i = 0;
	node* tmp = h->first;
	while(tmp && !i){
		if(!strcmp(tmp->name, n_name)){
			i = 1;
		}
		tmp = tmp->next;
	}
	return i;
}

void clear_list(head* h){
	node* tmp = NULL;
	while(h->first){
		tmp = h->first;
		h->first = tmp->next;
		free(tmp->name);
		free(tmp);
	}
}

int main(){
	head* hd = (head *)malloc(sizeof(head));
	hd->first = NULL;

	create_node(hd, 1, "Ali");
	create_node(hd, 2, "Aaron");
	create_node(hd, 3, "Abby");
	create_node(hd, 4, "Abel");
	create_node(hd, 5, "Abril");

	print_list(hd);

	printf("length: %d\n", length_list(hd));

	if(isExists(hd, "Ali")){
		printf("the name exists in the list\n");
	}else{
		printf("the name do not exist in the list\n");
	}

	if(isExists(hd, "Cabrel")){
		printf("the name exists in the list\n");
	}else{
		printf("the name do not exist in the list\n");
	}

	clear_list(hd);

	printf("length: %d\n", length_list(hd));

	return 0;
}
