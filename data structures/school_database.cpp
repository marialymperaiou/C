#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
        {
            float ex1,ex2,mid,final,mark;
        }
        marks_struct;

typedef struct
        {
            char *name,*surname;
            int idnum;
            marks_struct *marks;
        }
        student_struct;

typedef struct class_node_tag
        {
            student_struct *student;
            struct class_node_tag *next;
        }
        class_node;

typedef class_node* class_node_ptr;

int task_selection();
class_node_ptr file_scan(class_node_ptr);
class_node_ptr student_insert(class_node_ptr,marks_struct,char [],char []);
float mark_calc(float,float,float,float);
class_node_ptr student_delete(class_node_ptr);
float average_mark_calc(class_node_ptr);
void print_class(class_node_ptr);

int main()
{
    class_node_ptr class_list=NULL;
    int choice;
    printf("\n\n--- This program constructs and modifies a class database. ---\n\n");
    do
    {
        choice=task_selection();
        if (choice!=0)
        {
            switch (choice)
            {
                case 1  : class_list=file_scan(class_list); break;
                case 2  : class_list=student_delete(class_list); break;
                case 3  : print_class(class_list); break;
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
    printf(" - Give '1' to insert students to the class database from file.\n");
    printf(" - Give '2' to delete a student from the class database.\n");
    printf(" - Give '3' to print the class database with the final marks.\n");
    printf(" - Give '0' to exit program.\n");
    printf("Type in the number, then press <enter>: ");
    scanf("%d",&choice);
    return choice;
}

class_node_ptr file_scan(class_node_ptr class_list)
{
    FILE *fptr;
    marks_struct s;
    char file[20],s1[20],s2[20];
    int x,i=0;
    printf("\nPlease insert the file name, then press <enter>: ");
    scanf("%s",file);
    fptr=fopen(file,"r");
    fscanf(fptr,"%d\n",&x);
    printf("\nReading file...\n");
    while (fscanf(fptr,"%s %s\n%f\n%f\n%f\n%f\n",s1,s2,&(s.ex1),&(s.ex2),&(s.mid),&(s.final))!=EOF && (i<=x))
    {
        i++;
        s.mark=(float)i;
        class_list=student_insert(class_list,s,s1,s2);
    }
    printf("\nNo more entries to read in file.\n");
    fclose(fptr);
    return class_list;
}

class_node_ptr student_insert(class_node_ptr class_list,marks_struct s,char s1[20],char s2[20])
{
    class_node_ptr p,q;
    printf("\nInserting student %s %s with id number %d...\n",s2,s1,(int)s.mark);
    q=(class_node_ptr)malloc(sizeof(class_node));
    if (q==NULL)
    {
        printf("\nNo more memory! The entry can not be saved!\n");
        return class_list;
    }
    q->next=NULL;
    q->student=(student_struct*)malloc(sizeof(student_struct));
    q->student->name=(char*)malloc((strlen(s1)+1)*sizeof(char));
    strcpy(q->student->name,s1);
    q->student->surname=(char*)malloc((strlen(s2)+1)*sizeof(char));
    strcpy(q->student->surname,s2);
    q->student->idnum=(int)s.mark;
    q->student->marks=(marks_struct*)malloc(sizeof(marks_struct));
    q->student->marks->ex1=s.ex1;
    q->student->marks->ex2=s.ex2;
    q->student->marks->mid=s.mid;
    q->student->marks->final=s.final;
    q->student->marks->mark=mark_calc(s.ex1,s.ex2,s.mid,s.final);
    if (class_list==NULL) class_list=q;
    else
    {
        p=class_list;
        if (strcmp(q->student->surname,p->student->surname)<0)
        {
            q->next=class_list;
            class_list=q;
        }
        else if (strcmp(q->student->surname,p->student->surname)==0)
        {
            if (strcmp(q->student->name,p->student->name)<0)
            {
                q->next=class_list;
                class_list=q;
            }
            else
            {
                while ((p->next!=NULL) && (strcmp(q->student->surname,p->next->student->surname)==0) && (strcmp(q->student->name,p->next->student->name)>0)) p=p->next;
                q->next=p->next;
                p->next=q;
            }
        }
        else
        {
            while ((p->next!=NULL) && (strcmp(q->student->surname,p->next->student->surname)>0)) p=p->next;
            while ((p->next!=NULL) && (strcmp(q->student->surname,p->next->student->surname)==0) && (strcmp(q->student->name,p->next->student->name)>0)) p=p->next;
            q->next=p->next;
            p->next=q;
        }
    }
    printf("Student inserted.\n");
    return class_list;
}

float mark_calc(float g1,float g2,float g3,float g4)
{
    float mark;
    mark=0.1*g1+0.15*g2+0.25*g3+0.5*g4;
    return mark;
}

class_node_ptr student_delete(class_node_ptr class_list)
{
    class_node_ptr p,q;
    int id;
    printf("\nPlease insert the id number of the student you want to delete: ");
    scanf("%d",&id);
    p=class_list;
    if (p!=NULL && p->student->idnum==id)
    {
        printf("\nDeleting student %s %s with id number %d...\n",p->student->surname,p->student->name,p->student->idnum);
        class_list=p->next;
        free(p->student->marks);
        free(p->student->name);
        free(p->student->surname);
        free(p->student);
        free(p);
        printf("Student deleted.\n");
    }
    else
    {
        while (p!=NULL && p->next!=NULL && p->next->student->idnum!=id) p=p->next;
        if (p==NULL || p->next==NULL) printf("\nNo such entry found.\n");
        else
        {
            printf("\nDeleting student %s %s with id number %d...\n",p->next->student->surname,p->next->student->name,p->next->student->idnum);
            q=p->next;
            p->next=p->next->next;
            free(q->student->marks);
            free(q->student->name);
            free(q->student->surname);
            free(q->student);
            free(q);
            printf("Student deleted.\n");
        }
    }
    return class_list;
}

float average_mark_calc(class_node_ptr class_list)
{
    class_node_ptr p;
    int i=0;
    float sum=0,mark;
    p=class_list;
    while (p!=NULL)
    {
        i++;
        sum+=p->student->marks->mark;
        p=p->next;
    }
    if (i==0)
    {
        printf("No entries found.\n");
        mark=-1;
    }
    else mark=sum/i;
    return mark;
}

void print_class(class_node_ptr class_list)
{
    class_node_ptr p;
    p=class_list;
    printf("\nCLASS RESULTS\n");
    printf("--------------------------------------------------\n");
    if (p==NULL) printf("No entries found.\n");
    while (p!=NULL)
    {
        printf("%2d%15s%15s%10.2f\n",p->student->idnum,p->student->surname,p->student->name,p->student->marks->mark);
        p=p->next;
    }
    printf("\nCLASS AVERAGE FINAL MARK\n");
    printf("--------------------------------------------------\n");
    printf("%.2f\n",average_mark_calc(class_list));
    return;
}