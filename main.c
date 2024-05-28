#include "Gym_Header.h"
#include "Gym.cpp"

int main()
{
    printf("\t\tGym Application\n\n");
    fileRead();
    while(choice != 8)
    {
        printf("\n1.Product List\n2.Product Register\n3.Product Display\n4.Add Defect Product\n"
               "5.Product Update\n6.Update Product Avilabilty\n7.Product Delete\n"
               "8.Total Products With Expenses\n9.Exit\n\nEnter Your Choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            productList();
            break;
        case 2:
            productRegister();
            break;
        case 3:
            productDisplay();
            break;
        case 4:
            defectProduct();
            break;
        case 5:
            productUpdate();
            break;
        case 6:
            productAvilability();
            break;
        case 7:
            removeProduct();
            break;
        case 8:
            productCount();
            break;
        case 9:
            printf("Exit\n");
            fileWrite();
            free(products);
            return;
        default:
            printf("Enter Correct Choice\n");
            break;
        }
    }
    return 0;
}

