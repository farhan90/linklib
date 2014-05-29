#ifndef LINKLIB_H
#define LINKLIB_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct node{
	void *data; //A generic data pointer
	struct node *next;

};


void insert_node(struct node **root,struct node *node,int size);
void free_list(struct node **root);
struct node *create_node(void *data,int data_size);
struct node *find_node(struct node **root,void *data,int data_size);
void remove_node(struct node **root,void *data,int data_size);
#endif



