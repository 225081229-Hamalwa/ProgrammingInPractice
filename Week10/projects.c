#include <stdio.h>
#include "projects.h"

Project projects[MAX_RECORDS];
int projectCount = 0;

void addProject(void)
{
    if (projectCount >= MAX_RECORDS)
    {
        printf("Project storage is full!\n");
        return;
    }

    Project newProject;

    printf("\nEnter Project ID: ");
    scanf("%d", &newProject.projectID);

    printf("Enter Project Name: ");
    scanf(" %49[^\n]", newProject.projectName);

    printf("Enter Department: ");
    scanf(" %49[^\n]", newProject.department);

    printf("Enter Project End Year: ");
    scanf("%d", &newProject.endYear);

    projects[projectCount] = newProject;
    projectCount++;

    printf("Project added successfully!\n");
}

void displayProjects(void)
{
    if (projectCount == 0)
    {
        printf("\nNo projects available.\n");
        return;
    }

    printf("\n--- MUNICIPAL PROJECTS ---\n");

    for (int i = 0; i < projectCount; i++)
    {
        printf("\nProject ID: %d\n", projects[i].projectID);
        printf("Project Name: %s\n", projects[i].projectName);
        printf("Department: %s\n", projects[i].department);
        printf("End Year: %d\n", projects[i].endYear);
    }
}

void saveProjectsText(void)
{
    FILE *file = fopen("data/projects.txt", "w");

    if (file == NULL)
    {
        printf("Error: Could not open projects file for saving.\n");
        return;
    }

    for (int i = 0; i < projectCount; i++)
    {
        fprintf(file, "%d|%s|%s|%d\n",
                projects[i].projectID,
                projects[i].projectName,
                projects[i].department,
                projects[i].endYear);
    }

    fclose(file);

    printf("Project data saved successfully!\n");
}

void loadProjectsText(void)
{
    FILE *file = fopen("data/projects.txt", "r");

    if (file == NULL)
    {
        printf("No project data file found.\n");
        return;
    }

    projectCount = 0;

    while (projectCount < MAX_RECORDS &&
           fscanf(file, "%d|%49[^|]|%49[^|]|%d\n",
                  &projects[projectCount].projectID,
                  projects[projectCount].projectName,
                  projects[projectCount].department,
                  &projects[projectCount].endYear) == 4)
    {
        projectCount++;
    }

    fclose(file);

    printf("%d project record(s) loaded successfully!\n", projectCount);
}