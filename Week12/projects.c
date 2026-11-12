#include <stdio.h>
#include "projects.h"

void addProject(Project projects[], int *projectCount)
{
    if (*projectCount >= MAX_RECORDS)
    {
        printf("\nProject array is full!\n");
        return;
    }

    printf("\n--- ADD PROJECT ---\n");

    printf("Enter Project ID: ");
    scanf("%d", &projects[*projectCount].id);

    printf("Enter Project Title: ");
    scanf(" %39[^\n]", projects[*projectCount].title);

    printf("Enter Project Budget: ");
    scanf("%lf", &projects[*projectCount].budget);

    printf("\nEnter Project Start Date\n");

    printf("Day: ");
    scanf("%d", &projects[*projectCount].startDate.day);

    printf("Month: ");
    scanf("%d", &projects[*projectCount].startDate.month);

    printf("Year: ");
    scanf("%d", &projects[*projectCount].startDate.year);

    printf("\nEnter Project End Date\n");

    printf("Day: ");
    scanf("%d", &projects[*projectCount].endDate.day);

    printf("Month: ");
    scanf("%d", &projects[*projectCount].endDate.month);

    printf("Year: ");
    scanf("%d", &projects[*projectCount].endDate.year);

    (*projectCount)++;

    printf("\nProject added successfully!\n");
}

void displayProjects(Project projects[], int projectCount)
{
    if (projectCount == 0)
    {
        printf("\nNo projects registered.\n");
        return;
    }

    printf("\n========== PROJECT RECORDS ==========\n");

    for (int i = 0; i < projectCount; i++)
    {
        printf("\nProject %d\n", i + 1);
        printf("ID: %d\n", projects[i].id);
        printf("Title: %s\n", projects[i].title);
        printf("Budget: N$ %.2lf\n", projects[i].budget);

        printf("Start Date: %02d/%02d/%04d\n",
               projects[i].startDate.day,
               projects[i].startDate.month,
               projects[i].startDate.year);

        printf("End Date: %02d/%02d/%04d\n",
               projects[i].endDate.day,
               projects[i].endDate.month,
               projects[i].endDate.year);
    }

    printf("\n=====================================\n");
}
void displayProjectsByEndYear(Project projects[], int projectCount, int year)
{
    if (projectCount == 0)
    {
        printf("\nNo projects available.\n");
        return;
    }

    int found = 0;

    printf("\n========== PROJECTS ENDING IN %d ==========\n", year);

    for (int i = 0; i < projectCount; i++)
    {
        if (projects[i].endDate.year == year)
        {
            printf("\nProject ID: %d\n", projects[i].id);
            printf("Title: %s\n", projects[i].title);
            printf("Budget: N$ %.2lf\n", projects[i].budget);

            printf("Start Date: %02d/%02d/%04d\n",
                   projects[i].startDate.day,
                   projects[i].startDate.month,
                   projects[i].startDate.year);

            printf("End Date: %02d/%02d/%04d\n",
                   projects[i].endDate.day,
                   projects[i].endDate.month,
                   projects[i].endDate.year);

            found++;
        }
    }

    if (found == 0)
    {
        printf("\nNo projects ending in %d were found.\n", year);
    }
    else
    {
        printf("\nTotal projects found: %d\n", found);
    }

    printf("===========================================\n");
}