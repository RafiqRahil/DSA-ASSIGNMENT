#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ContactInfo {
    int identifier;
    char phoneNumber[11];
    char emailAddress[20];
    char fullName[20];
    char organization[30];
};

struct ContactInfo contactList[1000];
int totalContacts, index_val;
int flag = 0;
int creationFlag = 0;

void AddContacts() {
    printf("Enter number of contacts to add: ");
    scanf("%d", &totalContacts);
    for (index_val = 0; index_val < totalContacts; index_val++) {
        contactList[index_val].identifier = index_val + 1;
        printf("Enter phone number of contact %d: ", index_val + 1);
        scanf("\n");
        gets(contactList[index_val].phoneNumber);
        printf("Enter Name of contact %d: ", index_val + 1);
        scanf("\n");
        gets(contactList[index_val].fullName);
        printf("Enter email of contact %d: ", index_val + 1);
        scanf("\n");
        gets(contactList[index_val].emailAddress);
        printf("Enter organization name of contact %d: ", index_val + 1);
        scanf("\n");
        gets(contactList[index_val].organization);
    }
    creationFlag = 1;
}

void ShowContacts() {
    if (creationFlag == 1) {
        printf("\n%5s %20s %25s %25s %20s", "ID", "Phone Number", "Name", "Email", "Organization");
        for (index_val = 0; index_val < totalContacts + flag; index_val++) {
            printf("\n%5d %20s %25s %25s %20s", contactList[index_val].identifier, contactList[index_val].phoneNumber, contactList[index_val].fullName, contactList[index_val].emailAddress, contactList[index_val].organization);
        }
        printf("\n");
    } else if (creationFlag == 0) {
        printf("Contact list is empty!!!\n");
    }
}

void AddContact() {
    contactList[index_val].identifier = totalContacts + flag + 1;
    printf("Enter phone number: ");
    scanf("\n");
    gets(contactList[totalContacts + flag].phoneNumber);
    printf("Enter name: ");
    scanf("\n");
    gets(contactList[totalContacts + flag].fullName);
    printf("Enter Email: ");
    scanf("\n");
    gets(contactList[totalContacts + flag].emailAddress);
    printf("Enter Organization: ");
    scanf("\n");
    gets(contactList[totalContacts + flag].organization);
    flag++;
}

void RemoveContact() {
    int deleteFlag = 0;
    if (totalContacts == 0) {
        printf("Contact list is empty\n");
    } else {
        int position, i;
        char nameValue[30];
        printf("Enter the name of contact to delete: ");
        scanf("\n");
        gets(nameValue);
        for (i = 0; i < totalContacts; i++) {
            if ((strcmp(contactList[i].fullName, nameValue)) == 0) {
                position = i + 1;
                for (i = position - 1; i < totalContacts; i++) {
                    contactList[i] = contactList[i + 1];
                }
                totalContacts--;
                deleteFlag = 1;
                break;
            } else {
                deleteFlag = 0;
            }
        }
        if (deleteFlag == 1) {
            printf("Contact Deleted!!!\n");
        } else if (deleteFlag == 0) {
            printf("Contact not found!!!\n");
        }
    }
}

void FindContact() {
    if (totalContacts == 0) {
        printf("Contact list is empty!!!\n");
    } else {
        int searchFlag = 0;
        char nameValue[30];
        printf("Enter the name to be searched: ");
        scanf("\n");
        gets(nameValue);
        for (index_val = 0; index_val < totalContacts; index_val++) {
            if ((strcmp(contactList[index_val].fullName, nameValue)) == 0) {
                printf("Contact Record found: \n");
                printf("\n%5s %20s %25s %25s %20s", "ID", "Phone Number", "Name", "Email", "Organization");
                printf("\n%5d %20s %25s %25s %20s", contactList[index_val].identifier, contactList[index_val].phoneNumber, contactList[index_val].fullName, contactList[index_val].emailAddress, contactList[index_val].organization);
                searchFlag = 1;
                printf("\n");
                break;
            }
        }
        if (searchFlag == 0) {
            printf("Contact Not Found!!!\n");
        }
    }
}

void ModifyContact() {
    int searchFlag = 0;
    if (totalContacts == 0) {
        printf("Contact list is empty!!!\n");
    } else {
        int x;
        char nameValue[30];
        printf("Enter the name of contact to edit: ");
        scanf("\n");
        gets(nameValue);
        for (int i = 0; i < totalContacts; i++) {
            if ((strcmp(contactList[i].fullName, nameValue)) == 0) {
                x = i;
                searchFlag = 1;
            }
        }
        if (searchFlag == 1) {
            int choice;
            printf("Enter \n 1 to edit phone number\n 2 to edit name\n 3 to edit email\n 4 to edit organization\n");
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    printf("Enter phone number: ");
                    scanf("\n");
                    gets(contactList[x].phoneNumber);
                    break;
                case 2:
                    printf("Enter Name: ");
                    scanf("\n");
                    gets(contactList[x].fullName);
                    break;
                case 3:
                    printf("Enter email: ");
                    scanf("\n");
                    gets(contactList[x].emailAddress);
                    break;
                case 4:
                    printf("Enter organization name: ");
                    scanf("\n");
                    gets(contactList[x].organization);
                    break;
                default:
                    printf("Wrong Input!!!");
                    break;
            }
        } else if (searchFlag == 0) {
            printf("Contact Not Found!!!\n");
        }
    }
}

int main() {
    int userChoice;
    while (1) {
        system("cls");
        printf("1. Add new contacts to create list.\n");
        printf("2. Add new contact after list being created.\n");
        printf("3. List all Contacts.\n");
        printf("4. Delete a Contact\n");
        printf("5. Search Contacts.\n");
        printf("6. Edit a Contact\n");
        printf("7. Exit.\n");

        printf("\nEnter Choice: ");
        scanf("%d", &userChoice);

        switch (userChoice) {
            case 1:
                AddContacts();
                break;
            case 2:
                AddContact();
            case 3:
                ShowContacts();
                break;
            case 4:
                RemoveContact();
                break;
            case 5:
                FindContact();
                break;
            case 6:
                ModifyContact();
                break;
            case 7:
                exit(0);
                return 0;
            default:
                printf("Invalid Choice...\n");
        }
        system("pause"); // press any key to continue
    }

    return 0;
}