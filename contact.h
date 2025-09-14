#ifndef CONTACT_H
#define CONTACT_H

// UDTs
typedef struct Contact_data
{
    char Name[32];
    char Mobile_number[11];
    char Mail_ID[35];
} Contacts;

typedef struct AddressBook_Data
{
    Contacts contact_details[100];
    int contact_count;
} AddressBook;

// Function declarations 

// Functionalities [main.c]
void init_intitalization(AddressBook *);
int create_contact(AddressBook *);
void list_contacts(AddressBook *);
int search_contacts(AddressBook *);
int edit_contact(AddressBook *);
int delete_contact(AddressBook *);
int save_contacts(AddressBook *);

// Sub-Functions [contact.c]
void print_contact_details(AddressBook *, int );
int search_by_name(AddressBook *);
int search_by_mobile_no(AddressBook *);
int search_by_mail(AddressBook *);
void delete_shift(AddressBook *, int);
void print_line(void);

#endif // CONTACT_H
       // CONTACT_H