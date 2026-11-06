#ifndef PROJECTS_H
#define PROJECTS_H

#include "records.h"

void addProject(Project projects[], int *projectCount);
void displayProjects(Project projects[], int projectCount);
void displayProjectsByEndYear(Project projects[], int projectCount, int year);

#endif