#include<stdio.h>
#include<stdlib.h>

typedef struct node { 
    int data; 
    struct node *lchild; 
    struct node *rchild; 
  
    } treenode; 

 treenode* initializenode(int data){

   treenode* newnode = NULL;

   newnode = (treenode*)malloc(sizeof(treenode));

   if(NULL == newnode)
      return NULL;

    newnode->data = data;
    newnode->lchild =NULL;
    newnode->rchild =NULL;
    
     
    return newnode;
 }


int Searchindex(int inorder[], int instart, int inend , int key){
    for (int index = instart; index <= inend; index++) {
        if (key == inorder[index]) {
            return index;
        }
    }
    printf("Enter a valid key\n");
    return -1;
}

treenode* getTreeInPre(int inorder[], int preorder[], int instart, int inend){
    static int preindex = 0;
    if (instart > inend)
        return NULL;

    treenode* node = initializenode(preorder[preindex++]);
    if (instart == inend)
        return node;

    int splitindex = Searchindex(inorder, instart, inend, node->data);
    if (splitindex == -1)
        return NULL;

    node->lchild = getTreeInPre(inorder, preorder, instart, splitindex - 1);
    node->rchild = getTreeInPre(inorder, preorder, splitindex + 1, inend);

    return node;
}


treenode* getTreeInPost(int inorder[], int postorder[], int instart, int inend){
    static int postindex;
    if (instart > inend)
        return NULL;

    if (postindex == -1)
        postindex = inend;

    treenode* node = initializenode(postorder[postindex--]);

    if (instart == inend)
        return node;

    int splitindex = Searchindex(inorder, instart, inend, node->data);
    if (splitindex == -1)
        return NULL;

  
        node->rchild = getTreeInPost(inorder, postorder, splitindex + 1, inend);
        node->lchild = getTreeInPost(inorder, postorder, instart, splitindex - 1);

    return node;
}


int  inorder(treenode* t) {
    if( t == NULL ){
        return 0;
    }   
    inorder(t->lchild);
    printf("%d ", t->data);
    inorder(t->rchild);
    return 1;
}


int preorder(treenode* t) {
    if( t == NULL ) {
        return 0;
    }   
    printf("%d ", t->data);
    preorder(t->lchild);
    preorder(t->rchild);
    return 1;
}


int postorder(treenode* t) {
    if( t == NULL ) {
        return 0;
    }   
    postorder(t->lchild);
    postorder(t->rchild);
    printf("%d ", t->data);
    return 1;
}



int main(){

    int choice;
    int *in;
    int *pre;
    int *post;
    int numberofnode;
    treenode* tree = NULL;

    do {
        printf("\n--- Binary Tree Menu ---\n");
        printf("1. Build tree from Inorder and Preorder\n");
        printf("2. Build tree from Inorder and Postorder\n");
        printf("3. Display Inorder Traversal\n");
        printf("4. Display Preorder Traversal\n");
        printf("5. Display Postorder Traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:

               printf("inter number of node in tree ..\n");
               scanf("%d",&numberofnode);
               in = (int*)malloc(numberofnode*sizeof(int));
               pre= (int*)malloc(numberofnode*sizeof(int));

              printf("inter inorder confugurationn of tree \n ");
              for (int i = 0; i < numberofnode; i++)
              {
                  scanf("%d",&in[i]);
              }
              printf("inter preorder confugurationn of tree \n ");
              for (int i = 0; i < numberofnode; i++)
              {
                  scanf("%d",&pre[i]);
              }
              
                tree = getTreeInPre(in, pre, 0, (numberofnode-1));
                printf("Tree built using Inorder and Preorder.\n");
                break;
            case 2:

            
               printf("inter number of node in tree ..\n");
               scanf("%d",&numberofnode);
               in = (int*)malloc(numberofnode*sizeof(int));
               post= (int*)malloc(numberofnode*sizeof(int));

              printf("inter inorder confugurationn of tree \n ");
              for (int i = 0; i < numberofnode; i++)
              {
                  scanf("%d",&in[i]);
              }
              printf("inter postorder confugurationn of tree \n ");
              for (int i = 0; i < numberofnode; i++)
              {
                  scanf("%d",&post[i]);
              }
              
                tree = getTreeInPost(in, post, 0, (numberofnode-1));
                printf("Tree built using Inorder and Postorder.\n");
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorder(tree);
                printf("\n");
                break;
            case 4:
                printf("Preorder Traversal: ");
                preorder(tree);
                printf("\n");
                break;
            case 5:
                printf("Postorder Traversal: ");
                postorder(tree);
                printf("\n");
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 6);


}