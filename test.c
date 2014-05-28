#include <stdio.h>
#include <stdlib.h>
#include "linklib.h"

void printlist(struct node **root){
	struct node *ptr=*root;
	while(ptr){
		int *temp=(int*)ptr->data;
		printf("%d ",*temp);
		ptr=ptr->next;
	}
	
}

int main(){
	int i=0;
	struct node *root=NULL;

	
	for(i=0;i<5;++i){
		int *ptr=&i;
		struct node *node=create_node((void*)ptr,sizeof(int));

		if(node==NULL){
			printf("Error\n");
			exit(1);
		}
		insert_sorted(&root,node,sizeof(int));
	}
	
	printf("trying to print list\n");
	printlist(&root);		

	/*
	i=3;
	struct node* node=find(&root,&i,sizeof(int));

	printf("\nFinding an element\n");
	if(node!=NULL){
		int*temp=(int *)node->data;
		printf("%d ",*temp);
	}*/
	
	i=1;
	int a=0;
	printf("\nThe result of memcmp is %d",memcmp(&i,&a,4));
	struct node *node=create_node(&i,sizeof(int));
	insert_sorted(&root,node,sizeof(int));
	printlist(&root);
	free_list(&root);
	printlist(&root);

}


