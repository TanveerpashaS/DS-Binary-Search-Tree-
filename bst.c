#include<stdio.h>
#include<stdlib.h>
typedef struct  NODE Node;
struct NODE
{
    int value;
    Node*left;
    Node*right;
}; Node*root=NULL;
Node*insert(Node*root,int value)
{
    if(root==NULL)
    {
        Node*node=malloc(sizeof(Node));
        node->value=value;
        node->left=node->right=NULL;
        return node;
    }
    if(value==root->value)
    {
        printf("duplicate element not allowed");
    }
    if(value<root->value)
    {
        root->left=insert(root->left,value);
    }
    if(value>root->value)
    {
        root->right=insert(root->right,value);
    }
    return root;
}
Node*search(Node*root,int value)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(value==root->value)
    {
        return root;
    }
    if(value<root->value)
    {
        return search(root->left,value);
    }
    if(value>root->value)
    {
        return search(root->right,value);
    }

}
void inorder(Node*root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d",root->value);
        inorder(root->right);
    }
}
void preorder(Node*root)
{
    if(root!=NULL)
    {
        printf("%d",root->value);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(Node*root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->value);   
    }
}
void traverse()
{
    preorder(root);
    printf(" = PREORDER\n");
    inorder(root);
    printf(" = INORDER\n");
    postorder(root);
    printf(" = POSTORDER\n");
}
void find()
{
    int value;
    Node*node;
    printf("enter value to find");
    scanf("%d",&value);
    node=search(root,value);
    node==NULL?printf("NOT FOUND"):printf("FOUND : %d\n",node->value);

}
void create()
{
    int n,value;
    printf("enter how many nodes");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("enter value of node %d",i+1);
        scanf("%d",&value);
        root=insert(root,value);
    }
}
void main()
{
    int choice;
    struct MENU
    {
        char*name;void(*func)();
    } menu[]={
        {"exit",exit},
        {"CREATE\n",create},
        {"TRAVERSE\n",traverse},
        {"SEARCH\n",find}
    };
    int size=sizeof(menu)/sizeof(menu[0]);
    for(;;)
    {
        printf("-----BST MENU-------- \n");
        for(int i=1;i<size;i++)
        {
            printf("%d.%s",i,menu[i].name);
        }
        printf("\n");
        printf("enter your choice:");
        scanf("%d",&choice);
        menu[choice].func();
    }
    
}