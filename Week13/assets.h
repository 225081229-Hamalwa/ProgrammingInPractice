#ifndef ASSETS_H
#define ASSETS_H

#include "records.h"

void addAsset(Asset assets[], int *assetCount);

void displayAssets(Asset assets[], int assetCount);
void displayAssetsAboveValue(Asset assets[], int assetCount, double minimumValue);

#endif