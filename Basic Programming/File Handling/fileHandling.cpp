#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct storage
{
    char words[10][50];
}DArray;

void addMoreData();
void ShowAllData();
void FindData();
DArray split(char sent[], char separator);


main()
{
    char option;
    while(1)
    {
        puts("Main Menu");
        puts("1.  Add Data");
        puts("2.  Show Data");
        puts("3.  Find Data");
        puts("4.  Exit\n");
        scanf("%c",&option);
        if(option == '1')
            addMoreData();
        else if(option == '2')
            ShowAllData();
        else if(option == '3')
            FindData();
        else if(option == '4')
            break;
    }
}

DArray split(char sent[],char separator)
{
    DArray result;
    char temp[100][20];
    int x,y=0,z=0;
        for(x=0; sent[x]!='\0'; x++,z++)
        {
            if(sent[x]==separator)
            {
                temp[y][z]='\0';
                x++;
                y++;
                z=0;
            }
            temp[y][z]=sent[x];
        }
        temp[y][z]='\0';

    for(x=0; x<=y;x++)
    {
        strcpy(result.words[x],temp[x]);
    }
    return result;
}

void addMoreData()
{
     char csv[100];
     char firstname[50];
     char lastname[50];
     char age[10];

     FILE *fptr;
     if ((fptr = fopen("program.txt","w")) == NULL)
     {
        printf("Error! opening file");
        exit(1);
     }
     printf("First Name please: ");
     fflush(stdin);
     gets(firstname);
     printf("Last Name please: ");
     fflush(stdin);
     gets(lastname);
     printf("Age please: ");
     fflush(stdin);
     gets(age);

     strcpy(csv,"");
     strcat(csv, firstname);
     strcat(csv,",");
     strcat(csv, lastname);
     strcat(csv, ",");
     strcat(csv, age);
     strcat(csv, "\n");

     fputs(csv, fptr);
     fclose(fptr);
}



void ShowAllData()
{
     char csv[100];

     FILE *fptr;
     if ((fptr = fopen("program.txt","r")) == NULL)
     {
        printf("Error! opening file");
        exit(1);
     }

     fseek(fptr, 0, SEEK_SET);
     while(fgets(csv, 200, fptr))
     {
        printf("%s",csv);
     }
     fclose(fptr);
}

void FindData()
{
    DArray temp;


    char csv[100];
    char firstname[50];

    int flag=0;

    printf("Enter the name you would like to find\n");
    fflush(stdin);
    gets(firstname);

    FILE *fptr;
     if ((fptr = fopen("program.txt","r+")) == NULL)
     {
        printf("Error! opening file");
        exit(1);
     }

    while(fgets(csv, 200, fptr))
    {
        temp = split(csv, ',');
        if(strcmp(temp.words[0], firstname)==0)
        {
            flag = 1;
            printf("The entry where the name is found is: %s", csv);
            break;
        }
    }
    if(flag==0)
    {
        printf("%s is not a part of the database\n\n", firstname);
    }
}
