#include <stdio.h>
#include <string.h>
#include "contact.h"

/* Function definitions */
// void init_intitalization(AddressBook *addressbook)
// {
// }
int create_contact(AddressBook *addressbook)  //adding contact function
{
    char yn;
    printf("Enter contact Name: ");
    scanf("%[^\n]%*c",addressbook->contact_details[addressbook->contact_count].Name);

    printf("Enter contact Mobile Number: ");
    scanf("%[^\n]%*c",addressbook->contact_details[addressbook->contact_count].Mobile_number);

    printf("Enter contact Mail Id: ");
    scanf("%[^\n]%*c",addressbook->contact_details[addressbook->contact_count].Mail_ID);

    addressbook->contact_count++;

    printf("Contact Added Successfully\n");

    printf("Do you want to continue (y/n) :");
    scanf("%c%*c",&yn);

    if(yn == 'y') create_contact(addressbook);

    return 0;
}
void list_contacts(AddressBook *addressbook)  //list function
{
    print_line();
    printf("%-35s %-20s %-35s\n","Name","Mobile Number","Mail Id");
    print_line();

    for(int i=0;i<addressbook->contact_count;i++)  //loop to print all the contacts
    {
        print_contact_details(addressbook,i);
    }

    print_line();
}

int search_contacts(AddressBook *addressbook)  // search function
{
    int option,val;

    while(1)
    {
        printf("Search Contact menu : \n1.Name \n2.Mobile number\n3.Mail ID\n4. Exit\nEnter the option : "); /* Providing menu */

        scanf("%d%*c",&option);

        switch(option)
        {
            case 1:
            val = search_by_name(addressbook);
            if(val >= 0)
            print_contact_details(addressbook,val);
            break;

            case 2:
            val = search_by_mobile_no(addressbook);
            if(val >= 0)
            print_contact_details(addressbook,val);
            break;

            case 3:
            val = search_by_mail(addressbook);
            if(val >= 0)
            print_contact_details(addressbook,val);
            break;

            case 4:
            return 0;

        }
    }
}
int edit_contact(AddressBook *addressbook)  //edit function
{
    int option,val;
    char yn;

    while(1)
    {
        printf("Search contact to edit by:\n1.Name \n2.Mobile number \n3.Mail Id \n4.Exit \nEnter the option : ");  //providing menu to select how to search the contact to edit 

        scanf("%d%*c",&option);

        switch(option)
        {
            case 1:
            {
                val = search_by_name(addressbook);
                break;
            }

            case 2:
            {
                val = search_by_mobile_no(addressbook);
                break;
            }

            case 3:
            {
                val = search_by_mail(addressbook);
                break;
            }

            case 4:
            return 0;
        }

        printf("Edit Contact menu : \n1.Name \n2.Mobile number\n3.Mail ID\n4.All details\nEnter the option : "); // providing menu to select the member to be edited

        scanf("%d%*c",&option);

        switch(option)
        {
            case 1:
            
            if(val >= 0)
            {
                printf("\n");
                print_contact_details(addressbook,val);
                printf("\n");

                printf("Edit this contact's Name (y/n):");
                scanf("%c%*c",&yn);

                if(yn == 'y')
                {
                    printf("Enter the new Name: ");
                    scanf("%[^\n]%*c",addressbook->contact_details[val].Name);
                    printf("Contact's Name has been changed successfully!");
                    printf("\n");
                }
            }
            break;

            case 2:
            
            if(val >= 0)
            {
                printf("\n");
                print_contact_details(addressbook,val);
                printf("\n");

                printf("Edit this contact's Mobile number (y/n):");
                scanf("%c%*c",&yn);

                if(yn == 'y')
                {
                    printf("Enter the new Mobile Number: ");
                    scanf("%[^\n]%*c",addressbook->contact_details[val].Mobile_number);
                    printf("Contact's Mobile number has been changed successfully!");
                    printf("\n");
                }
            }
            break;

            case 3:
            
            if(val >= 0)
            {
                printf("\n");
                print_contact_details(addressbook,val);
                printf("\n");

                printf("Edit this contact's Mail Id (y/n):");
                scanf("%c%*c",&yn);

                if(yn == 'y')
                {
                    printf("Enter the new Mail Id: ");
                    scanf("%[^\n]%*c",addressbook->contact_details[val].Mail_ID);
                    printf("Contact's Mail Id has been changed successfully!");
                    printf("\n");
                }
            }
            break;

            case 4:
            if(val >= 0)
            {
                printf("\n");
                print_contact_details(addressbook,val);
                printf("\n");

                printf("Edit all the details of this contact (y/n):");
                scanf("%c%*c",&yn);

                if(yn == 'y')
                {
                    printf("Enter the new Name: ");
                    scanf("%[^\n]%*c",addressbook->contact_details[val].Name);

                    printf("Enter the new Mobile Number: ");
                    scanf("%[^\n]%*c",addressbook->contact_details[val].Mobile_number);
                    
                    printf("Enter the new Mail Id: ");
                    scanf("%[^\n]%*c",addressbook->contact_details[val].Mail_ID);
                    
                    printf("All the details of the contact has been changed successfully!");
                    printf("\n");
                }
            }
        }
    }
}

int delete_contact(AddressBook *addressbook)  //delete function
{
    int option,val;
    char yn;

    while(1)
    {
        printf("Delete Contact menu : \n1.Name \n2.Mobile number\n3.Mail ID\n4.Exit\nEnter the option : "); /* Providing menu */

        scanf("%d%*c",&option);

        switch(option)
        {
            case 1:
            val = search_by_name(addressbook);
            if(val >= 0)
            {
                printf("\n");
                print_contact_details(addressbook,val);
                printf("\n");

                printf("Delete this contact? (y/n):");
                scanf("%c%*c",&yn);

                if(yn == 'y') delete_shift(addressbook,val);
                printf("Contact deleted successfully!\n\n");
            }
            break;

            case 2:
            val = search_by_mobile_no(addressbook);
            if(val >= 0)
            {
                printf("\n");
                print_contact_details(addressbook,val);
                printf("\n");

                printf("Delete this contact? (y/n):");
                scanf("%c%*c",&yn);

                if(yn == 'y') delete_shift(addressbook,val);
                printf("Contact deleted successfully!\n\n");
            }
            break;

            case 3:
            val = search_by_mail(addressbook);
            if(val >= 0)
            {
                printf("\n");
                print_contact_details(addressbook,val);
                printf("\n");

                printf("Delete this contact? (y/n):");
                scanf("%c%*c",&yn);

                if(yn == 'y') delete_shift(addressbook,val);
                printf("Contact deleted successfully!\n\n");
            }
            break;

            case 4:
            return 0;

            default:
            printf("Invalid Option!\n");
            scanf("%*c");
            break;

        }
    }
    return 0;
}
int save_contacts(AddressBook *addressbook)
{
    return 0;
}


//sub-functionalities:

int search_by_name(AddressBook *addressbook)  //search by name function
{
    char input[32], yn;

    printf("Enter Name: ");
    scanf("%[^\n]%*c",input);

    for(int i=0;i<addressbook->contact_count;i++)
    {
        if(strcmp(input,addressbook->contact_details[i].Name) == 0) return i;
    }

    printf("Name not found!\n Try again ? (y/n):");
    scanf("%c%*c",&yn);

    if(yn == 'y') search_by_name(addressbook);
    else return -1;
}

int search_by_mobile_no(AddressBook *addressbook)  //search by mobile number function
{
    char input[11], yn;

    printf("Enter Mobile Number: ");

    scanf("%[^\n]%*c",input);

    for(int i=0;i<addressbook->contact_count;i++)
    {
        if(strcmp(input,addressbook->contact_details[i].Mobile_number) == 0) return i;
    }

    printf("Mobile Number not found!\n Try again ? (y/n):");
    scanf("%c%*c",&yn);

    if(yn == 'y') search_by_mobile_no(addressbook);
    else return -1;
}

int search_by_mail(AddressBook *addressbook)  //search by mail id function
{
    char input[35], yn;

    printf("Enter Mail Id: ");

    scanf("%[^\n]%*c",input);

    for(int i=0;i<addressbook->contact_count;i++)
    {
        if(strcmp(input,addressbook->contact_details[i].Mail_ID) == 0) return i;
    }

    printf("Mail Id not found!\n Try again ? (y/n):");
    scanf("%c%*c",&yn);

    if(yn == 'y') search_by_mail(addressbook);
    else return -1;
}

void print_contact_details(AddressBook *addressbook, int i)  // function to print conntact details
{
    printf("%-35s %-20s %-35s\n",addressbook->contact_details[i].Name,
                addressbook->contact_details[i].Mobile_number,
                addressbook->contact_details[i].Mail_ID);
}

void delete_shift(AddressBook *addressbook, int i)  // shifting funtion for deleting contact
{
    for(i;i<addressbook->contact_count;i++)
    {
        strcpy(addressbook->contact_details[i].Name,addressbook->contact_details[i+1].Name);
        strcpy(addressbook->contact_details[i].Mobile_number,addressbook->contact_details[i+1].Mobile_number);
        strcpy(addressbook->contact_details[i].Mail_ID,addressbook->contact_details[i+1].Mail_ID);
    }
    addressbook->contact_count--;
}

void print_line(void)  // listing format lines
{
    for(int i=0;i<90;i++)
    {
        printf("%c",'-');
    }

    printf("\n");
}

// Validations:

