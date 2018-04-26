#include <stdio.h>

int solid_choice();
float parallelepiped_calc();
float sphere_calc();
float pyramid_calc();
float cylinder_calc();
void parallelepiped_print(float);
void sphere_print(float);
void pyramid_print(float);
void cylinder_print(float);

const float pi=3.14159;

int main()
{
    int choice;
    printf("\n\n--- This program calculates the volume of several geometric solids. ---\n\n");
    do
    {
        choice=solid_choice();
        if (choice!=0)
        {
            switch (choice)
            {
                case 1: parallelepiped_print(parallelepiped_calc()); break;
                case 2: sphere_print(sphere_calc()); break;
                case 3: pyramid_print(pyramid_calc()); break;
                case 4: cylinder_print(cylinder_calc()); break;
                default: printf("\nError! You entered a wrong number key!");
            }
            printf("\n\nGive '0' to exit or any other number key to continue: ");
            scanf("%d",&choice);
        }
    }
    while (choice!=0);
    printf("\nMade by Panaro32.\n");
    return 0;
}

int solid_choice()
{
    int choice;
    printf("\nPlease choose a geometric solid according to this formula:\n");
    printf(" - Give '1' to choose parallelepiped\n");
    printf(" - Give '2' to choose sphere\n");
    printf(" - Give '3' to choose pyramid\n");
    printf(" - Give '4' to choose cylinder\n");
    printf(" - Give '0' to exit\n");
    printf("Give the number, then press <enter>: ");
    scanf("%d",&choice);
    return choice;
}

float parallelepiped_calc()
{
    float a,b,h,volume;
    printf("\nGive base's side (m): ");
    scanf("%f",&a);
    printf("Give base's height (m): ");
    scanf("%f",&b);
    printf("Give height (m): ");
    scanf("%f",&h);
    volume=a*b*h;
    return volume;
}

float sphere_calc()
{
    float r,volume;
    printf("\nGive radius (m): ");
    scanf("%f",&r);
    volume=(4*pi*r*r*r)/3;
    return volume;
}

float pyramid_calc()
{
    float a,b,h,volume;
    printf("\nGive base's side (m): ");
    scanf("%f",&a);
    printf("Give base's height (m): ");
    scanf("%f",&b);
    printf("Give height (m): ");
    scanf("%f",&h);
    volume=(a*b*h)/3;
    return volume;
}

float cylinder_calc()
{
    float r,h,volume;
    printf("\nGive radius (m): ");
    scanf("%f",&r);
    printf("Give height (m): ");
    scanf("%f",&h);
    volume=pi*r*r*h;
    return volume;
}

void parallelepiped_print(float result)
{
    printf("\nThe volume of this parallelepiped is %.3fm3.",result);
}

void sphere_print(float result)
{
    printf("\nThe volume of this sphere is %.3fm3.",result);
}

void pyramid_print(float result)
{
    printf("\nThe volume of this pyramid is %.3fm3.",result);
}

void cylinder_print(float result)
{
    printf("\nThe volume of this cylinder is %.3fm3.",result);
}