#include "Gym_Header.h"

void productRegister()
{
    if(products==NULL){
        products=(struct GymProduct*) malloc(sizeof(struct GymProduct));
    }
    else{
        products=(struct GymProduct*) realloc(products,(numberofProduct+1)*sizeof(struct GymProduct));
    }
    printf("Enter Product ID\n");
    scanf("%s",products[numberofProduct].productId);  
    printf("Enter Product Name\n");
    scanf(" %s",products[numberofProduct].productName);
    printf("Enter Weight\n");
    scanf("%f",&products[numberofProduct].productWeight);
    printf("Enter product Price\n");
    scanf("%f",&products[numberofProduct].productPrice);
    products[numberofProduct].Srno = numberofProduct+1;
    products[numberofProduct].defectProduct = false;
    products[numberofProduct].productAvailable = true;
    numberofProduct++;
}

void productDisplay()
{
    if(numberofProduct>0)
    {
        printf("\nSrno\tProduct ID\tProduct Name\tWeight\t Defect\t Availablity\tProduct Price\n");
        printf("----------------------------------------------------------------------------------------\n");
        for(productIndex = 0;productIndex < numberofProduct;productIndex++)
        {
            printf("%2d\t%5s\t\t%5s\t%.2f\t%5d\t%5d\t\t %.2f\n",products[productIndex].Srno,
                   products[productIndex].productId,products[productIndex].productName,
                   products[productIndex].productWeight,products[productIndex].defectProduct,
                   products[productIndex].productAvailable,products[productIndex].productPrice);
        }
        printf("----------------------------------------------------------------------------------------\n");
    }
    else{
        printf("products Are Empty\n");
    }
}

void productUpdate()
{
    char newProductId[50];
    printf("Enter Product ID\n");
    scanf("%s",newProductId);
    for(productIndex=0;productIndex < numberofProduct;productIndex++)
    {
        if(strcmp(newProductId,products[productIndex].productId)==0)
        {
            while(choice!=2)
            {
                printf("1.Product Name\n2.Product Weight\n3.Product Price\n4.Exit\n"
                       "Enter What you update\n");
                scanf("%d",&choice);
                switch(choice)
                {
                case 1:
                    printf("Enter New Name\n");
                    scanf("%s",&products[productIndex].productName);
                    break;
                case 2:
                    printf("Enter Weight\n");
                    scanf("%f",&products[productIndex].productWeight);
                    break;
                case 3:
                    printf("Enter product Price\n");
                    scanf("%f",&products[productIndex].productPrice);
                    break;
                case 4:
                    printf("Exit from Update\n");
                    return;
                default:
                    printf("Enter Correct Choice\n");
                    break;
                }
            }
        }
    }
    printf("Product Id not Available\n");
    return;
}

void defectProduct()
{
    printf("Enter Product ID\n");
    scanf("%s",products[numberofProduct].productId);
    for(productIndex = 0;productIndex < numberofProduct;productIndex++)
    {
        if(strcmp(products[numberofProduct].productId,products[productIndex].productId) == 0)
        {
            products[productIndex].defectProduct = true;
            return;
        }
        else{
            printf("Product Not available\n");
        }
    }
}
void productAvilability()
{
    printf("Enter Product ID\n");
    scanf("%s",products[numberofProduct].productId);
    for(productIndex = 0;productIndex < numberofProduct;productIndex++)
    {
        if(strcmp(products[numberofProduct].productId,products[productIndex].productId) == 0)
        {
            printf("1.Product Available\n2.Product Not Available\n");
            scanf("%d",&choice);
            switch(choice)
            {
            case 1:
                products[productIndex].productAvailable=true;
                break;
            case 2:
                products[productIndex].productAvailable=false;
                break;
            default:
                printf("Enter correct choice\n");
                break;
            }
        }
        else{
            printf("Product Not available\n");
        }
    }
}

void removeProduct()
{
    char newProductId[50];
    printf("Enter Product Id\n");
    scanf("%s",newProductId);
    for(int productIndex=0;productIndex < numberofProduct;productIndex++)
    {
        if(strcmp(newProductId,products[productIndex].productId)==0)
        {
            for(int shiftIndex=productIndex;shiftIndex < numberofProduct;shiftIndex++)
            {
                products[shiftIndex]=products[shiftIndex+1];
                products[shiftIndex].Srno--;
            }
            numberofProduct--;            
            printf("Product DELETED Succssfully\n");
            return;
        }
    }
    printf("Enter CORRECT product ID\n");
}

void productCount()
{
    int totalProducts=0;
    float totalAmount=0.0;
    for(productIndex=0;productIndex<numberofProduct;productIndex++)
    {
        totalProducts++;
        totalAmount+=products[productIndex].productPrice;
    }
    printf("-----------------------\n");
    printf("Total Products\t%3d\n\nTotal Expenses\t %.2f\n",totalProducts,totalAmount);
    printf("-----------------------\n");
}

void productList()
{
    if(numberofProduct > 0)
    {
        int i=1;
        printf("\t\t*Product List*\n");
        for(productIndex=0;productIndex < numberofProduct;productIndex++)
        {
            bool duplicate=false;
            for(int listArray=0;listArray < productIndex;listArray++)
            {
                if(strcmp(products[productIndex].productName,products[listArray].productName)==0)
                {
                    duplicate=true;
                }
            }
            if(!duplicate)
            {
                printf("%d.%s\n",i,products[productIndex].productName);
                i++;
            }
        }
    }
    else{
        printf("products Are Empty\n");
    }
}


void fileWrite()
{
    ptr=fopen("GymData.txt","w");
    if(ptr == NULL)
    {
        printf("File openin Error\n");
        return;
    }
    else{
        printf("Data ADDED to File Successfully\n");
    }
    for(productIndex = 0;productIndex < numberofProduct;productIndex++)
    {
        fprintf(ptr,"%d\t%s\t%s\t%.2f\t%d\t%d\t%.2f\n",
                products[productIndex].Srno,products[productIndex].productId,
                products[productIndex].productName,products[productIndex].productWeight,
                products[productIndex].defectProduct,products[productIndex].productAvailable,
                products[productIndex].productPrice);
    }
    fclose(ptr);
}

void fileRead()
{
    ptr=fopen("GymData.txt","a+");
    if(ptr == NULL)
    {
        printf("File openin Error\n");
        return;
    }
    else{
        printf("File Open Sucessfully\n");
    }
    if(products==NULL)
    {
        products=(struct GymProduct*) malloc(sizeof(struct GymProduct));
    }
    while(fscanf(ptr,"%d %s %s %f %d %d %f",
                  &products[numberofProduct].Srno,products[numberofProduct].productId,
                  products[numberofProduct].productName,&products[numberofProduct].productWeight,
                  &products[numberofProduct].defectProduct,&products[numberofProduct].productAvailable,
                  &products[numberofProduct].productPrice)!=EOF)
    {
        numberofProduct++;
        products=(struct GymProduct*) realloc(products,(numberofProduct+1)*sizeof(struct GymProduct));
    }
    fclose(ptr);
}
