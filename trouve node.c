#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node {
	int val ;
	node * fg ;
	node *fd;
}; 
node * add (node*root , int val ){
	if (root == NULL){
		node *n = (node *)malloc(sizeof(node));
		n->fg= NULL;
		n->fd= NULL;
		n->val= val;
		return n;
	}
	if (val <root->val){
	
	root ->fg = add (root->fg ,val);
	return root ;
}
	if (val >root->val){
	
	root->fd = add (root->fd ,val);
	return root ;
	
}
return root ;//val == root ->val
}

void prefixe (node *root ){
	if (root != NULL){
		printf ("%d__",root->val);
		prefixe(root->fg);
		prefixe(root->fd);
	}
}
void infixe(node *root ){
	if(root != NULL){
		infixe(root->fg);
		printf("%d__",root->val);
		infixe (root ->fd);
		
	}
}
 void postfixe(node *root ){
 	if (root != NULL){
 		postfixe (root->fg);
 		postfixe(root->fd);
 		printf("%d__",root->val);
 		
	 }
 }
  node * trouve(node*root, int val){
 	if(root == NULL )
 	return NULL;
 	if(val == root->val)
 	return root;
 		if (val < root->val)
 				return trouve(root->fg,  val);
 		else
 			return trouve(root->fd  ,val);
 }

 main()
 {
 	
 	node * root = NULL;
 	root = add(root,3);
 	root = add(root,0);
 	root = add(root,5);
 	root = add(root,9);
 	root = add(root,1);
 	root = add(root,4);
 	root = add(root,2);
 	root = trouve(root,4);
 	prefixe(root );
 	printf("\n");
 	infixe(root );
 	printf("\n");
 	postfixe(root );
 	printf("\n");
 }

