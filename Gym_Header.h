#ifndef GYM_HEADER_H
#define GYM_HEADER_H
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void productList();
void productRegister();
void productDisplay();
void defectProduct();
void productUpdate();
void productAvilability();
void removeProduct();
void productCount();

void fileWrite();
void fileRead();

struct GymProduct
{
    int Srno;
    float productWeight,productPrice;
    char productId[10],productName[50];
    bool defectProduct,productAvailable;
};
struct GymProduct *products=NULL;
int choice=0,numberofProduct=0,productIndex=0;
FILE *ptr=NULL;

#endif // GYM_HEADER_H


