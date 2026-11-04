#include <stdio.h>
#include "assets.h"

Asset assets[MAX_RECORDS];
int assetCount = 0;

void addAsset(void)
{
    if (assetCount >= MAX_RECORDS)
    {
        printf("Asset storage is full!\n");
        return;
    }

    Asset newAsset;

    printf("\nEnter Asset ID: ");
    scanf("%d", &newAsset.assetID);

    printf("Enter Asset Name: ");
    scanf(" %49[^\n]", newAsset.assetName);

    printf("Enter Department: ");
    scanf(" %49[^\n]", newAsset.department);

    printf("Enter Asset Value: ");
    scanf("%f", &newAsset.assetValue);

    assets[assetCount] = newAsset;
    assetCount++;

    printf("Asset added successfully!\n");
}

void displayAssets(void)
{
    if (assetCount == 0)
    {
        printf("\nNo assets available.\n");
        return;
    }

    printf("\n--- ASSET LIST ---\n");

    for (int i = 0; i < assetCount; i++)
    {
        printf("\nAsset ID: %d\n", assets[i].assetID);
        printf("Asset Name: %s\n", assets[i].assetName);
        printf("Department: %s\n", assets[i].department);
        printf("Asset Value: N$ %.2f\n", assets[i].assetValue);
    }
}

void saveAssetsText(void)
{
    FILE *file = fopen("data/assets.txt", "w");

    if (file == NULL)
    {
        printf("Error: Could not open assets file for saving.\n");
        return;
    }

    for (int i = 0; i < assetCount; i++)
    {
        fprintf(file, "%d|%s|%s|%.2f\n",
                assets[i].assetID,
                assets[i].assetName,
                assets[i].department,
                assets[i].assetValue);
    }

    fclose(file);
    printf("Asset data saved successfully!\n");
}

void loadAssetsText(void)
{
    FILE *file = fopen("data/assets.txt", "r");

    if (file == NULL)
    {
        printf("No asset data file found.\n");
        return;
    }

    assetCount = 0;

    while (assetCount < MAX_RECORDS &&
           fscanf(file, "%d|%49[^|]|%49[^|]|%f\n",
                  &assets[assetCount].assetID,
                  assets[assetCount].assetName,
                  assets[assetCount].department,
                  &assets[assetCount].assetValue) == 4)
    {
        assetCount++;
    }

    fclose(file);
    printf("%d asset record(s) loaded successfully!\n", assetCount);
}