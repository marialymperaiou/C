#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct tree_node_tag
        {
            int info;
            struct tree_node_tag *left,*right;
        }
        tree_node;

typedef tree_node* tree_node_ptr;

int task_selection();
void swap(int*,int*);
tree_node_ptr create();
tree_node_ptr create_fun(int*,int,int);
void insert(tree_node_ptr*);
int insert_fun(tree_node_ptr*,int,int);
void extract(tree_node_ptr*,int*);
int extract_fun(tree_node_ptr*,int*,int);
int* random(int*,int,int);
int min(int*,int,int);
void simul();
void print(tree_node_ptr);
void print_fun(tree_node_ptr);

int main()
{
    printf("\n\n--- This program controls a priority queue based on a binary tree structure. ---\n\n");
    tree_node_ptr tree=NULL;
    int choice,x;
    do
    {
        choice=task_selection();
        if (choice!=0)
        {
            switch (choice)
            {
                case 1  : tree=create(); break;
                case 2  : insert(&tree); break;
                case 3  : extract(&tree,&x); break;
                case 4  : simul(); break;
                case 5  : print(tree); break;
                default : printf("\nYou entered a wrong number key!\n");
            }
            printf("\n\nPlease give '0' to exit or any other number key to continue: ");
            scanf("%d",&choice);
        }
    }
    while (choice!=0);
    printf("\nMade by Panaro32.\n");
    return 0;
}

int task_selection()
{
    int choice;
    printf("\nPlease choose a number according to the task you want to do: \n");
    printf(" - Give '1' to create a priority queue from a random array.\n");
    printf(" - Give '2' to insert an element to the priority queue.\n");
    printf(" - Give '3' to extract the minimum element from the priority queue.\n");
    printf(" - Give '4' to check out an average cost for the priority queue.\n");
    printf(" - Give '5' to print the priority queue's elements.\n");
    printf(" - Give '0' to exit program.\n");
    printf("Type in the number, then press <enter>: ");
    scanf("%d",&choice);
    return choice;
}

void swap(int *x,int *y)
{
    int k;
    k=*x;
    *x=*y;
    *y=k;
    return;
}

tree_node_ptr create()
{
    int *a=NULL;
    tree_node_ptr p;
    int n,k;
    printf("\nGive the length of the random array: ");
    scanf("%d",&n);
    printf("Give the range of the random values: ");
    scanf("%d",&k);
    a=random(a,n,k);
    p=create_fun(a,0,n-1);
    return p;
}

tree_node_ptr create_fun(int *a,int f,int l)
{
    int x,i;
    tree_node_ptr p;
    if (f>l) p=NULL;
    else
    {
        x=min(a,f,l);
        i=f;
        while (a[i]!=x) i++;
        p=(tree_node_ptr)malloc(sizeof(tree_node));
        p->info=x;
        p->left=create_fun(a,f,i-1);
        p->right=create_fun(a,i+1,l);
    }
    return p;
}

void insert(tree_node_ptr *tree)
{
    int x,s;
    printf("\nGive the element you want to insert: ");
    scanf("%d",&x);
    s=insert_fun(tree,x,0);
    printf("\nNumber of swaps: %d\n",s);
    return;
}

int insert_fun(tree_node_ptr *tree,int x,int s)
{
    if (*tree==NULL)
    {
        s++;
        (*tree)=(tree_node_ptr)malloc(sizeof(tree_node));
        (*tree)->info=x;
        (*tree)->left=NULL;
        (*tree)->right=NULL;
    }
    else
    {
        s++;
        if (x<=(*tree)->info)
        {
            if ((*tree)->left==NULL || ((*tree)->left!=NULL && (*tree)->right!=NULL && (*tree)->left->info>=(*tree)->right->info))
            {
                swap(&x,&((*tree)->info));
                s+=insert_fun(&((*tree)->left),x,0);
            }
            else
            {
                swap(&x,&((*tree)->info));
                s+=insert_fun(&((*tree)->right),x,0);
            }
        }
        else
        {
            if ((*tree)->left==NULL || ((*tree)->left!=NULL && (*tree)->right!=NULL && (*tree)->left->info>=(*tree)->right->info))
                s+=insert_fun(&((*tree)->left),x,0);
            else s+=insert_fun(&((*tree)->right),x,0);
        }
    }
    return s;
}

void extract(tree_node_ptr *tree,int *x)
{
    int s;
    s=extract_fun(tree,x,0);
    printf("\nMinimum element: %d",*x);
    printf("\nNumber of swaps: %d",s);
    return;
}

int extract_fun(tree_node_ptr *tree,int *x,int s)
{
    if (*tree==NULL) *x=-1;
    else
    {
        if ((*tree)->left==NULL && (*tree)->right==NULL)
        {
            s++;
            *x=(*tree)->info;
            free(*tree);
            (*tree)=NULL;
        }
        else
        {
            s++;
            if ((*tree)->right==NULL || ((*tree)->left!=NULL && (*tree)->right!=NULL && (*tree)->left->info<=(*tree)->right->info))
            {
                swap(&((*tree)->left->info),&((*tree)->info));
                s+=extract_fun(&((*tree)->left),x,0);
            }
            else
            {
                swap(&((*tree)->right->info),&((*tree)->info));
                s+=extract_fun(&((*tree)->right),x,0);
            }
        }
    }
    return s;
}

int* random(int *a,int n,int k)
{
    int i;
    srand(time(NULL));
    a=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++) a[i]=rand()%(k+1);
    return a;
}

int min(int *a,int f,int l)
{
    int x,i;
    if (a==NULL) x=-1;
    else
    {
        x=a[f];
        for(i=f+1;i<=l;i++)
            if (a[i]<x) x=a[i];
    }
    return x;
}

void simul()
{
    srand(time(NULL));
    tree_node_ptr t;
    int min,m,k,p,i,x,ins=0,ext=0,si=0,se=0;
    t=create();
    printf("Give the number of tasks: ");
    scanf("%d",&m);
    printf("Give the range of values for random insertions: ");
    scanf("%d",&k);
    printf("Give the possibility %% for the extract task: ");
    scanf("%d",&p);
    printf("\n\n-------------------------------------------------------\n");
    printf(" * Tasks: %d\n",m);
    printf(" * Range: %d\n",k);
    printf(" * Insert: %d%%\n",100-p);
    printf(" * Extract: %d%%\n",p);
    printf("-------------------------------------------------------\n");
    printf("\nRunning simul function...\n");
    for(i=0;i<m;i++)
    {
        x=rand()%101;
        if (x>p)
        {
            ins++;
            si+=insert_fun(&t,rand()%(k+1),0);
        }
        else
        {
            ext++;
            se+=extract_fun(&t,&min,0);
        }
    }
    printf("\n\nRESULTS\n");
    printf("------------------------------------------------------------\n");
    printf(" * Inserts: %d\n",ins);
    printf(" * Extracts: %d\n",ext);
    printf(" * Swaps per insert: %.2f\n",(float)si/ins);
    printf(" * Swaps per extract: %.2f\n",(float)se/ext);
    printf(" * Swaps per task: %.2f\n",(float)(si+se)/(ins+ext));
    printf("------------------------------------------------------------\n");
    printf("\n");
    return;
}

void print(tree_node_ptr tree)
{
    printf("\nNumbers in priority queue: \n");
    print_fun(tree);
    printf("\n");
    return;
}

void print_fun(tree_node_ptr tree)
{
    if (tree!=NULL)
    {
        printf("%d ",tree->info);
        print_fun(tree->left);
        print_fun(tree->right);
    }
    return;
}