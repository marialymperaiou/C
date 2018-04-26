#include <stdio.h>

int num(char);
int crypt_choice();
int array_scan(char []);
int number_entry(char []);
int key_entry(char []);
void encryption(int [],char [],char [],int,int);
void decryption(int [],char [],char [],int,int);
void print_array(int [],int);

int main()
{
    int choice,numbersize,keysize;
    char number[100],key[100];
    int result[100];
    printf("\n\n--- This program encrypts or decrypts numbers based on a key you enter. ---\n\n");
    do
    {
        choice=crypt_choice();
        if (choice!=0)
        {
            switch (choice)
            {
                case 1  : numbersize=number_entry(number); keysize=key_entry(key);
                          encryption(result,number,key,numbersize,keysize); print_array(result,numbersize); break;
                case 2  : numbersize=number_entry(number); keysize=key_entry(key);
                          decryption(result,number,key,numbersize,keysize); print_array(result,numbersize); break;
                default : printf("\nError! You entered a wrong number key!");
            }
            printf("\n\nGive '0' to exit or any other number key to continue: ");
            scanf("%d",&choice);
        }
    }
    while (choice!=0);
    printf("\nMade by Panaro32.\n");
    return 0;
}

int num(char x)
{
    int y;
    y=x-'0';
    return y;
}

int crypt_choice()
{
    int choice;
    printf("\nPlease give '1' to encrypt, '2' to decrypt or '0' to exit: ");
    scanf("%d",&choice);
    return choice;
}

int array_scan(char array[100])
{
    int size=0;
    char x,z;
    scanf("%c",&z);
    if (z!='\n') x=z;
    else scanf("%c",&x);
    while (x!='\n')
    {
        array[size]=x;
        size++;
        scanf("%c",&x);
    }
    return size;
}

int number_entry(char array[100])
{
    printf("\nEnter the number you want to encrypt/decrypt: ");
    return array_scan(array);
}

int key_entry(char array[100])
{
    printf("\nEnter the key for encryption/decryption: ");
    return array_scan(array);
}

void encryption(int result[100],char number[100],char key[100],int numbersize,int keysize)
{
    int i;
    for(i=0;i<numbersize;i++)
        result[i]=(num(number[i])+num(key[i % keysize])) % 10;
}

void decryption(int result[100],char number[100],char key[100],int numbersize,int keysize)
{
    int i;
    for(i=0;i<numbersize;i++)
        result[i]=(num(number[i])-num(key[i % keysize])+10) % 10;
}

void print_array(int array[100],int size)
{
    int i;
    printf("\nThe encrypted/decrypted number is: ");
    for(i=0;i<size;i++)
        printf("%d",array[i]);
    printf("\n");
}
