#include <stdio.h>
#include <string.h>
struct student
{
    char regno[20];
    char name[30];
    int m1, m2, m3;
    int total;
    float percentage;
    char result[10];
};
int main()
{
    struct student s[50];
    int count = 0, choice, i, found;
    char key[20];
    FILE *fp;
    do
    {
         printf("\n1.Add record\n");
         printf("2. Display all records\n");
         printf("3. search by register number\n");
         printf("4. write records to file\n");
         printf("5. read records from file\n");
         printf("6. Exit\n");
         printf("Enter your choice:");
         scanf("%d", &choice);
         switch (choice)
         {
            case 1:
                if (count ==50)
                {
                    printf("Records limit reached.\n");
                    break;
                }
                printf("Enter register number:");
                scanf("%s", s[count].regno);
                printf("Enter student name(one word:)");
                scanf("%s", s[count].name);
                printf("enter marks in three subjects:");
                scanf("%d %d %d", &s[count].m1, &s[count].m2, &s[count].m3);

                if (s[count].m1 < 0 || s[count].m1 > 100 ||
                    s[count].m2 < 0 || s[count].m2 > 100 ||
                    s[count].m3 < 0 || s[count].m3 > 100)
                {
                    printf("Invalid marks.\n");
                    break;
                }
                s[count].total= s[count].m1 + s[count].m2 + s[count].m3;
                s[count].percentage= s[count].total/3.0f;
                if (s[count].m1 >= 35 && s[count].m2 >= 35 && s[count].m3 >= 35)
                    strcpy(s[count].result,"fail");
                count++;
                printf("record added succesfully.\n");
                break;
            case 2:
                if (count == 0)
                {
                    printf("no records available.\n");
                    break;
                }
                for (i = 0; i < count; i++)
                {
                    printf("\nregister number: %s\n", s[i].regno);
                    printf("name: %s\n", s[i].name);
                    printf("marks: %d %d %d\n", s[i].m1, s[i].m2, s[i].m3);
                    printf("Total: %d\n", s[i].total);
                    printf("percentage: %f\n", s[i].percentage);
                    printf("result: %s\n", s[i].result);
                }
                break;
            case 3:
                printf("Enter register number to search:");
                scanf("%s", key);
                found = 0;
                for (i = 0; i < count; i++)
                {
                    if (strcmp(s[i].regno, key) == 0)
                    {
                        printf("Name: %s\n", s[i].name);
                        printf("Total: %d\n",s[i].total);
                        printf("Percentage: %f\n", s[i].percentage);
                        printf("Result: %s\n", s[i].result);
                        found = 1;
                    }
                }
                if (found == 0)
                   printf("Record not found.\n");
                break;
            case 4:
                fp = fopen("students.txt", "w");
                if (fp == NULL)
              {
                  printf("unable to open file.\n");
                break;
              }
              for(i=0; i < count; i++)
              {
                  fprintf(fp,"%s %s %d %d %d %d %f %s\n",
                     s[i].regno,s[i].name,s[i],s[i].m2,s[i].m3,
                     s[i].total,s[i].percentage,s[i].result);
              }
              fclose(fp);
              printf("records written to students.txt.\n");
              break;
            case 5:
                fp=fopen("students.txt", "r");
                if (fp==NULL)
                {
                    printf("unable to open students.txt.\n");
                    break;
                }
                count=0;
                while (count < 50 &&
                      fscanf(fp,"%s %s %d %d %d %d %f %s",
                             s[count].regno, s[count].name,
                             &s[count].m1, &s[count].m2, &s[count].m3,
                             &s[count].total, &s[count].percentage,
                             s[count].result) == 8)
                             {
                                count++;
                             }
                             fclose(fp);
                             printf("%d record(s) read from students txt.\n", count);
                             break;
            case 6:
                printf("program ended.\n");
                break;
            deafult:
                printf("Include choice.\n");
        }
    }
    while (choice != 6);
    return 0;
}  