#include <stdio.h>

#define MAX 100

struct Consumer
{
    int id;
    char name[50];
    char address[100];
    int units;
    float bill;
};

struct Consumer consumers[MAX];
int count = 0;

/* Safely read an integer (prevents the endless loop) */
int readInt()
{
    int n;
    while (scanf("%d", &n) != 1)
    {
        printf("Invalid input! Enter a number: ");
        while (getchar() != '\n');
    }
    return n;
}

/* Calculate electricity bill */
float calculateBill(int units)
{
    return units * 2.0f;
}

/* Module 1: Consumer Management */
void addConsumer()
{
    if (count >= MAX)
    {
        printf("\nConsumer limit reached!\n");
        return;
    }

    printf("\nEnter Consumer ID: ");
    consumers[count].id = readInt();

    printf("Enter Consumer Name: ");
    scanf(" %49[^\n]", consumers[count].name);

    printf("Enter Address: ");
    scanf(" %99[^\n]", consumers[count].address);

    printf("Enter Units Consumed: ");
    consumers[count].units = readInt();

    while (consumers[count].units < 0)
    {
        printf("Units cannot be negative! Enter again: ");
        consumers[count].units = readInt();
    }

    consumers[count].bill = calculateBill(consumers[count].units);

    count++;

    printf("\nConsumer added successfully!\n");
}

void displayConsumers()
{
    int i;

    if (count == 0)
    {
        printf("\nNo consumer records found.\n");
        return;
    }

    printf("\n========== CONSUMER LIST ==========\n");

    for (i = 0; i < count; i++)
    {
        printf("\nConsumer ID : %d", consumers[i].id);
        printf("\nName        : %s", consumers[i].name);
        printf("\nAddress     : %s", consumers[i].address);
        printf("\nUnits Used  : %d", consumers[i].units);
        printf("\nBill Amount : Rs. %.2f\n", consumers[i].bill);
    }
}

void searchConsumer()
{
    int id, i, found = 0;

    printf("\nEnter Consumer ID to search: ");
    id = readInt();

    for (i = 0; i < count; i++)
    {
        if (consumers[i].id == id)
        {
            printf("\nConsumer Found!\n");
            printf("Consumer ID : %d\n", consumers[i].id);
            printf("Name        : %s\n", consumers[i].name);
            printf("Address     : %s\n", consumers[i].address);
            printf("Units Used  : %d\n", consumers[i].units);
            printf("Bill Amount : Rs. %.2f\n", consumers[i].bill);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nConsumer not found.\n");
    }
}

/* Module 2: Bill Generation */
void generateBill()
{
    int id, i, found = 0;

    printf("\nEnter Consumer ID: ");
    id = readInt();

    for (i = 0; i < count; i++)
    {
        if (consumers[i].id == id)
        {
            printf("\n");
            printf("====================================\n");
            printf("       ELECTRICITY BILL\n");
            printf("====================================\n");
            printf("Consumer ID : %d\n", consumers[i].id);
            printf("Name        : %s\n", consumers[i].name);
            printf("Address     : %s\n", consumers[i].address);
            printf("Units Used  : %d\n", consumers[i].units);
            printf("Rate        : Rs. 2 per unit\n");
            printf("------------------------------------\n");
            printf("Total Bill  : Rs. %.2f\n", consumers[i].bill);
            printf("====================================\n");

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nConsumer not found. Add the consumer first.\n");
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n===== ELECTRICITY BILLING SYSTEM =====\n");
        printf("1. Add Consumer\n");
        printf("2. Display All Consumers\n");
        printf("3. Search Consumer\n");
        printf("4. Generate Electricity Bill\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        choice = readInt();

        switch (choice)
        {
            case 1:
                addConsumer();
                break;

            case 2:
                displayConsumers();
                break;

            case 3:
                searchConsumer();
                break;

            case 4:
                generateBill();
                break;

            case 5:
                printf("\nThank you for using the system!\n");
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }

    } while (choice != 5);

    return 0;
}