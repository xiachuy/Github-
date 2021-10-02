#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

 struct TreeNode {
    int val;
    struct TreeNode *left;
     struct TreeNode *right;
 };
 
typedef struct tree
{
  TreeNode  * root;
} Tree;


typedef struct Node
{
    int val;
    struct TreeNode *treepoint;
    struct Node * next;
}Node,*PNode;

typedef struct stack
{
    struct Node *sp;
}Stack,*Pstack;

void init_stack(Pstack p)
{
    p->sp=NULL;

}
void push(Pstack p,TreeNode *root)
{
    PNode newnode=(PNode)malloc(sizeof(Node));
    newnode->val=root->val;
    newnode->treepoint=root;
    newnode->next=p->sp;
    p->sp=newnode;
}

TreeNode * pop(Pstack p)
{
    if(p->sp==NULL)
        return NULL;
    TreeNode * res=p->sp->treepoint;
    PNode temp=p->sp;
    p->sp=p->sp->next;
    free(temp);
    return res;    
}
bool is_empty(Pstack p)
{
    if(p->sp==NULL)
        return true;
    else
        return false;
}


void inorderTraversal(struct TreeNode* root){
    int i=0;
    Stack S;
    init_stack(&S);
    while(root||!(is_empty(&S)))
    {
        if(root)
        {
            push(&S,root);
            root=root->left;
        }
        else
        {
            root=pop(&S);
            printf("%d\n",root->val);
            root=root->right;
        }
    }
}

void insert_node(Tree * tree,int value)
{
    TreeNode* node=(TreeNode*)malloc(sizeof(TreeNode));
    node->val=value;
    node->left=NULL;
    node->right=NULL;
    if(tree->root==NULL)
    {
        tree->root=node;
    }
    else
    {
        TreeNode* temp=tree->root;
        while(temp!=NULL)
        {
            if(value<temp->val)//插入值比当前值小的话，进入左子树
            {
                if(temp->left==NULL)//左子树为空，就将当前结点的左子树指向node
                {
                    temp->left=node;
                    return;
                }
                else
                {
                    temp=temp->left;
                }
            }
            else
            {
                if(temp->right==NULL)
                {
                    temp->right=node;
                    return;
                }
                else
                {
                    temp=temp->right;
                }
            }
        }
    }
    
}
void preoder(TreeNode * node)
{
    if(node!=NULL)
    {
        printf("%d\n",node->val);
        preoder(node->left);
        preoder(node->right);
    }
}
void inorder(TreeNode * node)
{
    if(node!=NULL)
    {
        inorder(node->left);
        printf("%d\n",node->val);
        inorder(node->right);
    }
}
void postorder(TreeNode * node)
{
    if(node!=NULL)
    {
        postorder(node->left);
        postorder(node->right);
        printf("%d\n",node->val);
    }
}

int main(void) { 
    int j=0;
    Stack S;
    init_stack(&S);
    int arr[7]={16,0,8,2,5,1,7};
    Tree tree;
    tree.root=NULL;
    for(int i=0;i<7;i++)
    {
        insert_node(&tree,arr[i]);
    }
    
    for(int j=0;j<7;j++)
    {
        int k=0;
    //    k=pop(&S);
      //  printf("%d ",k);
    }
	if(is_empty(&S))
	    printf("none");
	 else
	    printf("exit");
	    inorder(tree.root);
	printf("inorderTraversal :");
    inorderTraversal(tree.root);
	return 0;

}