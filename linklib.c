#include "linklib.h"


/* This function will insert a node into the list
Since we are inserting in a sorted order we need to specify a size
for the memcmp function which will compare the data */

void insert_sorted(struct node **root,struct node *node,int size){

	struct node *ptr=*root;
	//struct node *prev_ptr=NULL;
	if(ptr==NULL || memcmp(node->data,ptr->data,size)<0){
		node->next=*root;
		*root=node;
		return;
	}
	else{
		while(ptr->next!=NULL && memcmp(node->data,ptr->data,size)>0){
			ptr=ptr->next;
				
		}
		node->next=ptr->next;
		ptr->next=node;
	}
	
	return;
}


struct node *create_node(void* data,int data_size){

	struct node *node=malloc(sizeof(struct node));
	if(node==NULL){
		printf("Cannot create a node\n");
		return NULL;
	}

	node->data=malloc(sizeof(data_size));
	if(node->data==NULL){
		printf("Cannot allocate memory for data of the node\n");
		return NULL;
	}	
	memcpy(node->data,data,data_size);
	return node;
}


/*Will return the first node containing the data
in case of duplicates */
struct node *find(struct node **root,void *data,int data_size){
	struct node *ptr=*root;

	while(ptr->next!=NULL){
		if(memcmp(ptr->data,data,data_size)==0){
			return ptr;
		}	
		ptr=ptr->next;
	}

	return NULL;
}


void free_list(struct node **root){

	while(*root){
		struct node *temp=*root;
		*root=temp->next;
		free(temp->data);
		free(temp);
	}

}

