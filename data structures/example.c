#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node_t{
     int info;
     struct node_t *next;
};

typedef struct node_t node, *list;

void readlist(list *p){
    list l,q,head=NULL;
    int c,counter=0;
    c=getchar();
    while (c!='\n'){ 
       l=(list) malloc(sizeof(node));
       if (l==NULL){
            printf("Out of memory");
            exit(1);
       }
       counter++;
       l->info=c;
       l->next=NULL;
       if (counter==1) {q=l;head=q;}
       else{
            q->next=l;
            q=q->next;
       }
        c=getchar();
    }
    *p=head;
 }
 
int listcompare(list a,list b){
   if (a==NULL && b==NULL) return 0;
   if (a==NULL) return 1;
   if (b==NULL) return -1;
   while ((a->info==b->info || abs((a->info)-(b->info))==32) && a->next!=NULL && b->next!=NULL){
      a=a->next;
      b=b->next;
   }
   if (a->next==NULL && b->next==NULL) return 0;
   if (a->next==NULL) return 1;
   if (b->next==NULL) return -1;
   if (a->info<b->info && (a->info)-32<b->info) return 1;
   else return -1;
}

int main(){
   list a=NULL,b=NULL;
   int compare;
   readlist(&a);
   readlist(&b);
   compare=listcompare(a,b);
   if (compare>0) printf("The first is smaller\n");
   else if (compare<0) printf("The second one is smaller\n");
   else printf("They are equal\n");
   free(a);
   free(b);
   return 0;
}