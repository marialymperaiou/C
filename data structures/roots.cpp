#include <stdio.h>

typedef struct
        {
            float a,b,c;
        }
        bar1;
typedef struct
        {
            float d,x1,x2;
        }
        bar2;

bar1 quadratic_choice();
bar2 root_calc(bar1);
void root_print(bar1,bar2);

int main()
{
    int choice;
    bar1 terms;
    bar2 roots;
    printf("\n\n--- This program calculates the roots of quadratic equations. ---\n\n");
    do
    {
        terms=quadratic_choice();
        roots=root_calc(terms);
        root_print(terms,roots);
        printf("\n\nGive '0' to exit or any other number key to continue: ");
        scanf("%d",&choice);
    }
    while (choice!=0);
    printf("\nMade by Panaro32.\n");
    return 0;
}

bar1 quadratic_choice()
{
    bar1 terms;
    printf("\nThe general form of a quadratic equation is ax^2+bx+c=0.\n");
    printf(" - 'a','b' and 'c' are constans, 'x' is a variable.\n\n");
    printf("Give a real number for 'a', then press <enter>: ");
    scanf("%f",&terms.a);
    printf("Give a real number for 'b', then press <enter>: ");
    scanf("%f",&terms.b);
    printf("Give a real number for 'c', then press <enter>: ");
    scanf("%f",&terms.c);
    printf("\nSo your quadratic equation is: (%.2f)x^2+(%.2f)x+(%.2f)=0.\n",terms.a,terms.b,terms.c);
    return terms;
}

bar2 root_calc(bar1 terms)
{
    bar2 roots;
    if (terms.a!=0)
    {
        roots.d=terms.b*terms.b-4*terms.a*terms.c;
        if (roots.d>=0)
        {
            roots.x1=(-terms.b-sqrt(roots.d))/(2*terms.a);
            roots.x2=(-terms.b+sqrt(roots.d))/(2*terms.a);
        }
        else
        {
            roots.x1=(-terms.b)/(2*terms.a);
            roots.x2=fabs(sqrt(-roots.d)/(2*terms.a));
        }
    }
    else
    {
        if (terms.b!=0) roots.x1=-terms.c/terms.b;
        else ;
    }
    return roots;
}

void root_print(bar1 terms,bar2 roots)
{
    if (terms.a!=0)
    {
        if (roots.d>0) printf("\nThe equation has two simple real roots: %.2f and %.2f",roots.x1,roots.x2);
        else if (roots.d<0) printf("\nThe equation has two simple complex roots: %.2f-%.2fi and %.2f+%.2fi",roots.x1,roots.x2,roots.x1,roots.x2);
             else printf("\nThe equation has one double real root: %.2f",roots.x1);
    }
    else
    {
        if (terms.b!=0) printf("\nThe equation has one simple real root: %.2f",roots.x1);
        else if (terms.c!=0) printf("\nThe equation has no roots.");
             else printf("\nThe equation has infinite roots.");
    }
}