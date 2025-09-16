#include <stdio.h>
#include <string.h>
#include "contact.h"

int count=0,arr[10]={0};

/* Function definitions */
// void init_intitalization(AddressBook *addressbook)
// {
// }
int create_contact(AddressBook *addressbook)  //adding contact function
{
    printf("\n");
    char yn;
    char name[32];
    strcpy(addressbook->contact_details[addressbook->contact_count].Name,name_validation(name));

    char number[11];
    strcpy(addressbook->contact_details[addressbook->contact_count].Mobile_number,mobile_no_validation(1,number,addressbook));

    char mail_id[35];
    strcpy(addressbook->contact_details[addressbook->contact_count].Mail_ID,mail_id_validation(1,mail_id,addressbook));

    addressbook->contact_count++;

    printf("\033[1;32mContact Added Successfully!\033[0m\n");

    printf("Do you want to continue? (y/n) :");
    scanf("%c%*c",&yn);

    if(yn == 'y') create_contact(addressbook);

    return 0;
}
void list_contacts(AddressBook *addressbook)  //list function
{
    printf("\n");
    print_line();
    printf("\033[1;33m%-5s %-35s %-20s %-35s\033[0m\n","S.No","Name","Mobile Number","Mail Id");
    print_line();

    int s=1;
    for(int i=0;i<addressbook->contact_count;i++)  //loop to print all the contacts
    {
        print_contact_details(addressbook,i,s++);
    }

    print_line();
}

int search_contacts(AddressBook *addressbook)  // search function
{
    int option,val;

    while(1)
    {
        printf("\n");
        printf("Search Contact menu : \n1. Name \n2. Mobile number\n3. Mail ID\n4. Exit\nEnter the option : "); /* Providing menu */

        scanf("%d%*c",&option);

        switch(option)
        {
            case 1:
            val = search_by_name(0,addressbook);

            if(val >= 0)
            {
                print_line();
                printf("\033[1;33m%-5s %-35s %-20s %-35s\033[0m\n","S.No","Name","Mobile Number","Mail Id");
                print_line();

                print_contact_details(addressbook,val,1);
                
                print_line();
                printf("\n");
            }
            break;

            case 2:
            val = search_by_mobile_no(addressbook);

            if(val >= 0)
            {
                print_line();
                printf("\033[1;33m%-5s %-35s %-20s %-35s\033[0m\n","S.No","Name","Mobile Number","Mail Id");
                print_line();

                print_contact_details(addressbook,val,1);
                
                print_line();
                printf("\n");
            }
            break;

            case 3:
            val = search_by_mail(addressbook);

            if(val >= 0)
            {
                print_line();
                printf("\033[1;33m%-5s %-35s %-20s %-35s\033[0m\n","S.No","Name","Mobile Number","Mail Id");
                print_line();

                print_contact_details(addressbook,val,1);
                
                print_line();
                printf("\n");
            }
            break;

            case 4:
            return 0;

            default:
            printf("\033[1;31mInvalid Option!\033[0m\n");
            scanf("%*c");
            break;

        }
    }
}
int edit_contact(AddressBook *addressbook)  //edit function
{
    int option,val;
    char yn,name[32],number[11],mail_id[35];

    while(1)  //search option for edit
    {
        printf("\n");
        printf("Search Contact menu : \n1. Name \n2. Mobile number\n3. Mail ID\n4. Exit\nEnter the option : ");  //providing menu to select how to search the contact to edit 

        scanf("%d%*c",&option);

        switch(option)
        {
            case 1:
            {
                val = search_by_name(1,addressbook);
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

            default:
            printf("\033[1;31mInvalid Option!\033[0m\n");
            scanf("%*c");
            continue;
        }

        if(val<0) continue;
        
        printf("Edit Contact menu : \n1. Name \n2. Mobile number\n3. Mail ID\n4. All details\n Enter the option : "); // providing menu to select the member to be edited

        scanf("%d%*c",&option);

        switch(option)
        {
            case 1:
            
            if(val >= 0)
            {
                printf("\n"); 
                
                print_line();
                printf("\033[1;33m%-5s %-35s %-20s %-35s\033[0m\n","S.No","Name","Mobile Number","Mail Id");
                print_line();

                print_contact_details(addressbook,val,1);

                print_line(); 
                printf("\n");

                printf("Edit this contact's Name? (y/n): ");
                scanf("%c%*c",&yn);

                if(yn == 'y')
                {
                    strcpy(addressbook->contact_details[val].Name,name_validation(name));
                    printf("\n");
                    printf("\033[1;32mContact's Name has been changed successfully!\033[0m");
                    printf("\n");
                }
            }
            break;

            case 2:
            
            if(val >= 0)
            {
                printf("\n");

                print_line();
                printf("\033[1;33m%-5s %-35s %-20s %-35s\033[0m\n","S.No","Name","Mobile Number","Mail Id");
                print_line();

                print_contact_details(addressbook,val,1);

                print_line(); 
                printf("\n");

                printf("Edit this contact's Mobile number? (y/n): ");
                scanf("%c%*c",&yn);

                if(yn == 'y')
                {
                    strcpy(addressbook->contact_details[val].Mobile_number,mobile_no_validation(1,number,addressbook));
                    printf("\n");
                    printf("\033[1;32mContact's Mobile number has been changed successfully!\033[0m");
                    printf("\n");
                }
            }
            break;

            case 3:
            
            if(val >= 0)
            {
                printf("\n");

                print_line();
                printf("\033[1;33m%-5s %-35s %-20s %-35s\033[0m\n","S.No","Name","Mobile Number","Mail Id");
                print_line();

                print_contact_details(addressbook,val,1);
                
                print_line();
                printf("\n");

                printf("Edit this contact's Mail Id (y/n): ");
                scanf("%c%*c",&yn);

                if(yn == 'y')
                {
                    strcpy(addressbook->contact_details[val].Mail_ID,mail_id_validation(1,mail_id,addressbook));
                    printf("\n");
                    printf("\033[1;32mContact's Mail Id has been changed successfully!\033[0m");
                    printf("\n");
                }
            }
            break;

            case 4:
            if(val >= 0)
            {
                printf("\n");

                print_line();
                printf("\033[1;33m%-5s %-35s %-20s %-35s\033[0m\n","S.No","Name","Mobile Number","Mail Id");
                print_line();

                print_contact_details(addressbook,val,1);
                
                print_line();
                printf("\n");

                printf("Edit all the details of this contact? (y/n): ");
                scanf("%c%*c",&yn);

                if(yn == 'y')
                {
                    strcpy(addressbook->contact_details[val].Name,name_validation(name));

                    strcpy(addressbook->contact_details[val].Mobile_number,mobile_no_validation(1,number,addressbook));

                    strcpy(addressbook->contact_details[val].Mail_ID,mail_id_validation(1,mail_id,addressbook));
                    
                    printf("\n");
                    printf("\033[1;32mAll the details of the contact has been changed successfully!\033[0m");
                    printf("\n");
                }
            }

            default:
            printf("\033[1;31mInvalid Option!\033[0m\n");
            scanf("%*c");
            continue;
        }
    }
}

int delete_contact(AddressBook *addressbook)  //delete function
{
    int option,val;
    char yn;

    while(1)
    {
        printf("\n");

        printf("Delete Contact menu : \n1.Name \n2.Mobile number\n3.Mail ID\n4.Exit\nEnter the option : "); /* Providing menu */

        scanf("%d%*c",&option);

        switch(option)
        {
            case 1:
            val = search_by_name(1,addressbook);
            if(val >= 0)
            {
                printf("\n");

                print_line();
                printf("\033[1;33m%-5s %-35s %-20s %-35s\033[0m\n","S.No","Name","Mobile Number","Mail Id");
                print_line();

                print_contact_details(addressbook,val,1);

                print_line();
                printf("\n");

                printf("Delete this contact? (y/n): ");
                scanf("%c%*c",&yn);

                if(yn == 'y') delete_shift(addressbook,val);
                printf("\n");
                printf("\033[1;32mContact deleted successfully!\033[0m\n");
                printf("\n");
            }
            break;

            case 2:
            val = search_by_mobile_no(addressbook);
            if(val >= 0)
            {
                printf("\n");

                print_line();
                printf("\033[1;33m%-5s %-35s %-20s %-35s\033[0m\n","S.No","Name","Mobile Number","Mail Id");
                print_line();

                print_contact_details(addressbook,val,1);

                print_line();
                printf("\n");

                printf("Delete this contact? (y/n): ");
                scanf("%c%*c",&yn);

                if(yn == 'y') delete_shift(addressbook,val);
                printf("\n");
                printf("\033[1;32mContact deleted successfully!\033[0m\n");
                printf("\n");
            }
            break;

            case 3:
            val = search_by_mail(addressbook);
            if(val >= 0)
            {
                printf("\n");

                print_line();
                printf("\033[1;33m%-5s %-35s %-20s %-35s\033[0m\n","S.No","Name","Mobile Number","Mail Id");
                print_line();

                print_contact_details(addressbook,val,1);

                print_line();
                printf("\n");

                printf("Delete this contact? (y/n):");
                scanf("%c%*c",&yn);

                if(yn == 'y') delete_shift(addressbook,val);
                printf("\033[1;32mContact deleted successfully!\033[0m\n");
            }
            break;

            case 4:
            return 0;

            default:
            printf("\033[1;31mInvalid Option!\033[0m\n");
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

int search_by_name(int check, AddressBook *addressbook)  //search by name function
{
    char input[32], yn;

    while(1)
    {
        count = 0;
        strcpy(input,name_validation(input));

        for(int i=0;i<addressbook->contact_count;i++)
        {
            if(strcmp(input,addressbook->contact_details[i].Name) == 0)
            {
                arr[count] = i;
                count++;
            }
        }

        if(count == 1) return *arr;
        else if(count == 0)
        {
            printf("\n");
            printf("\033[1;31mName not found!\033[0m\nTry again ? (y/n):");
            scanf("%c%*c",&yn);

            if(yn == 'y') continue;
        }
        else
        {
            print_line();
            printf("\033[1;33m%-5s %-35s %-20s %-35s\033[0m\n","S.No","Name","Mobile Number","Mail Id");
            print_line();

            int s=1;
            for(int i=0;i<count;i++)
            {
                print_contact_details(addressbook, arr[i], s++);
            }
            print_line();

            if(check)
            {
                printf("Select the contact: ");
                int s_no;
                scanf("%d%*c",&s_no);
                printf("\n");

                return arr[s_no-1];
            }
        }
        return -1;
    }
}

int search_by_mobile_no(AddressBook *addressbook)  //search by mobile number function
{
    char input[11], yn;

    while(1)
    {
        strcpy(input,mobile_no_validation(0,input,addressbook));


        for(int i=0;i<addressbook->contact_count;i++)
        {
            if(strcmp(input,addressbook->contact_details[i].Mobile_number) == 0) return i;
        }

        printf("\033[1;31mMobile Number not found!\033[0m\n Try again ? (y/n):");
        scanf("%c%*c",&yn);

        if(yn == 'y') continue;
        else return -1;
    }
}

int search_by_mail(AddressBook *addressbook)  //search by mail id function
{
    char input[35], yn;

    while(1)
    {
        strcpy(input,mail_id_validation(0,input,addressbook));

        for(int i=0;i<addressbook->contact_count;i++)
        {
            if(strcmp(input,addressbook->contact_details[i].Mail_ID) == 0) return i;
        }

        printf("\033[1;31mMail Id not found!\033[0m\n Try again ? (y/n): ");
        scanf("%c%*c",&yn);

        if(yn == 'y') continue;
        else return -1;
    }
}

void print_contact_details(AddressBook *addressbook, int i,int serial)  // function to print conntact details
{
    printf("\033[0;33m%-5d %-35s %-20s %-35s\033[0m\n",serial,
            addressbook->contact_details[i].Name,
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