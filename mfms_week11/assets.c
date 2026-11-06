#include <stdio.h>
#include "assets.h"

void addAsset(Asset assets[], int *assetCount)
{
    if (*assetCount >= MAX_RECORDS)
    {
        printf("\nAsset array is full!\n");
        return;
    }

    printf("\n--- ADD ASSET ---\n");

    printf("Enter Asset ID: ");
    scanf("%d", &assets[*assetCount].id);

    printf("Enter Asset Description: ");
    scanf(" %39[^\n]", assets[*assetCount].description);

    printf("Enter Asset Value: ");
    scanf("%lf", &assets[*assetCount].value);

    printf("Enter Acquisition Day: ");
    scanf("%d", &assets[*assetCount].acquired.day);

    printf("Enter Acquisition Month: ");
    scanf("%d", &assets[*assetCount].acquired.month);

    printf("Enter Acquisition Year: ");
    scanf("%d", &assets[*assetCount].acquired.year);

    (*assetCount)++;

    printf("\nAsset added successfully!\n");
}

void displayAssets(Asset assets[], int assetCount)
{
    if (assetCount == 0)
    {
        printf("\nNo assets registered.\n");
        return;
    }

    printf("\n========== ASSET RECORDS ==========\n");

    for (int i = 0; i < assetCount; i++)
    {
        printf("\nAsset %d\n", i + 1);
        printf("ID: %d\n", assets[i].id);
        printf("Description: %s\n", assets[i].description);
        printf("Value: N$ %.2lf\n", assets[i].value);

        printf("Acquisition Date: %02d/%02d/%04d\n",
               assets[i].acquired.day,
               assets[i].acquired.month,
               assets[i].acquired.year);
    }

    printf("\n===================================\n");
}
void displayAssetsAboveValue(Asset assets[], int assetCount, double minimumValue)
{
    if (assetCount == 0)
    {
        printf("\nNo assets available.\n");
        return;
    }

    int found = 0;

    printf("\n========== ASSETS ABOVE VALUE ==========\n");
    printf("Minimum value: N$ %.2lf\n", minimumValue);

    for (int i = 0; i < assetCount; i++)
    {
        if (assets[i].value > minimumValue)
        {
            printf("\nAsset ID: %d\n", assets[i].id);
            printf("Description: %s\n", assets[i].description);
            printf("Value: N$ %.2lf\n", assets[i].value);

            found++;
        }
    }

    if (found == 0)
    {
        printf("\nNo assets found above N$ %.2lf.\n", minimumValue);
    }
    else
    {
        printf("\nTotal assets found: %d\n", found);
    }

    printf("========================================\n");
}