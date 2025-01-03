#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *llink;
    struct node *rlink;
};
typedef struct node *NODE;
NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("Memory Full\n");
        exit(0);
    }
    return x;
}
void preorder(NODE root)
{
    if(root==NULL)
        return;
    printf("%d\t",root->info);
    preorder(root->llink);
    preorder(root->rlink);
}
void postorder(NODE root)
{
    if(root==NULL)
        return;
    postorder(root->llink);
    postorder(root->rlink);
    printf("%d\t",root->info);
}
void inorder(NODE root)
{
    if(root==NULL)
        return;
    inorder(root->llink);
    printf("%d\t",root->info);
    inorder(root->rlink);
}
void display(NODE root,int i)
{
    int j;
    if(root==NULL)
        return;
    display(root->rlink,i+1);
    for(j=0;j<i;j++)
        printf("\t");
    printf("%d\n",root->info);
    display(root->llink,i+1);
}
NODE insert(NODE root,int item)
{
    NODE temp,cur,prev;
    temp=getnode();
    temp->info=item;
    temp->llink=temp->rlink=NULL;
    if(root==NULL)
        return temp;
    prev=NULL;
    cur=root;
    while(cur!=NULL)
    {
        prev=cur;
        if(item<cur->info)
            cur=cur->llink;
        else
            cur=cur->rlink;
    }
    if(item<prev->info)
        prev->llink=temp;
    else
        prev->rlink=temp;
    return root;
}
NODE search(NODE root,int item)
{
    NODE cur;
    if(root==NULL)
    return NULL;
    cur=root;
    while(cur!=NULL)
    {
        if(item==cur->info)
            return cur;
        if(item<cur->info)
            cur=cur->llink;
        else
            cur=cur->rlink;
    }
    return NULL;
}
void main()
{
    NODE root,cur;
    int item,ch;
    root=NULL;
    for(;;)
    {
        printf("\n1.Insert\n2.preorder\n3.postorder\n4.inorder\n5.search\n6.display\n7.Exit\n");
        printf("Enter the choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the item to be inserted\n");
                    scanf("%d",&item);
                    root=insert(root,item);
                    break;
            case 2:if(root==NULL)
                    {
                        printf("Tree is empty\n");
                        break;
                    }
                    printf("The preorder Traversal is\n");
                    preorder(root);
                    break;
            case 3:if(root==NULL)
                    {
                        printf("Tree is empty\n");
                        break;
                    }
                    printf("The postorder Traversal is\n");
                    postorder(root);
                    break;
            case 4:if(root==NULL)
                    {
                        printf("Tree is empty\n");
                        break;
                    }
                    printf("The inorder Traversal is\n");
                    inorder(root);
                    break;
            case 5:if(root==NULL)
                    {
                        printf("Tree is empty\n");
                        break;
                    }
                    printf("Enter the item to be searched\n");
                    scanf("%d",&item);
                    cur=search(root,item);
                    if(cur==NULL)
                        printf("Item not found\n");
                    else
                        printf("Item found\n");
                    break;
            case 6:if(root==NULL)
                    {
                        printf("Tree is empty\n");
                        break;
                    }
                    printf("The tree is\n");
                    display(root,1);
                    break;
            default:exit(0);
        }
    }
}