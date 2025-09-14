#include <stdio.h>
#include "contact.h"
/* Structure declaration */

int main()
{
    /* Variable and structre defintion */
    int option;
    AddressBook addressbook;
    addressbook.contact_count = 0;

    // init_intitalization(&addressbook);

    while (1)
    {
        printf("\nAddress book menu\n"); /* Give a prompt message for a user */
        printf("1.Add contact\n2.search contact\n3.Edit contact\n4.Delete contact\n5.List contact\n6.Save contact\n7.Exit\n");
        printf("Enter the option : ");
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
            printf("Saving contacts\n");
            save_contacts(&addressbook);
            break;

        case 7:
            printf("INFO : Save and Exit...\n");
            return 0;

        default:
            printf("\nInvalid option! \n");
            scanf("%*c");
            break;
        }
    }
    return 0;
}
