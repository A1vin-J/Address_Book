#include <stdio.h>
#include "contact.h"
/* Structure declaration */

int main()
{
    /* Variable and structre defintion */
    int option;
    AddressBook addressbook;
    addressbook.contact_count = 0;
    
    init_intitalization(&addressbook);
    
    while (1)
    {
        printf("\n\033[1;36mAddress book menu\033[0m\n"); /* Give a prompt message for a user */
        printf("1.Add contact\n2.Search contact\n3.Edit contact\n4.Delete contact\n5.List contact\n6.Save contacts\n7.Save and Exit\n8.Exit without saving\n");
        printf("\nEnter the option : ");
        scanf("%d%*c", &option);

        switch (option) /* Based on choosed option */
        {
        case 1:
        {
            create_contact(&addressbook);
            break;
        }

        case 2:
        {
            search_contacts(&addressbook);
            break;
        }
        case 3:
        {
            edit_contact(&addressbook);
            break;
        }

        case 4:
        {
            delete_contact(&addressbook);
            break;
        }
        case 5:
        {
            printf("List Contacts:\n");
            list_contacts(&addressbook);
            break;
        }

        case 6:
            printf("\033[1;32mContacts have been saved successfully!\033[0mn");
            save_contacts(&addressbook);
            break;

        case 7:
            printf("Saving and Exiting...\n");
            save_contacts(&addressbook);
            return 0;

        case 8:
            printf("Exiting without saving...\n");
            return 0;

        default:
            printf("\nInvalid option! \n");
            scanf("%*c");
            break;
        }
    }
    return 0;
}
