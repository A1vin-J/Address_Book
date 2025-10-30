# Address Book

## 📘 Overview

The **Address Book** is a command-line contact management system written in C.

It allows users to **add, view, search, edit, and delete contacts**, while maintaining data persistence through a CSV file.
This project demonstrates structured C programming, file handling, and validation of real-world data formats such as names, phone numbers, and email IDs.

---

## ⚙️ Features

* Add new contacts with **Name**, **Phone Number**, and **Email ID**.
* **Search**, **Edit**, and **Delete** contacts easily.
* Display all saved contacts in a formatted table.
* Save and load contacts from a CSV file (`AddressBook.csv`) across program runs.
* Multiple validations for inputs (names, mobile numbers, and email).
* Prevents duplicate entries for mobile numbers and emails.
* Modular design — core logic, validations, and data structures are well-separated.
* Simple, user-friendly CLI interface.

---

## 🧩 Project Structure

```
Address_Book/
|
├── .gitignore
├── AddressBook.csv       # File storing all contact records
├── contact.c             # Functions for main functionalities (Add, Edit, Delete, Search, List)
├── contact.h             # Header file containing structures and function prototypes
├── main.c                # Entry point with main menu and program control
├── Validations.c         # Functions for validating name, email, and mobile number formats
```

---

## 🧱 Compilation

To compile the project:

```bash
gcc *.c
```

This will generate the executable file `a.out`.

---

## 🧠 Usage

### Run the Program

```bash
./a.out
```

### Sample Interaction

```
Address book menu
1.Add contact
2.Search contact
3.Edit contact
4.Delete contact
5.List contact
6.Save contacts
7.Save and Exit
8.Exit without saving

Enter the option : 5
List Contacts:

..........................................................................................
S.No  Name                                Mobile Number        Mail Id
..........................................................................................
1     alvin j                             9999222292           alvin@gmail.com
2     ajay a                              9933993399           ajay@a.com
3     hishanth s                          9944994499           hishanth@s.com
4     alvin j                             9999222299           alvinj@emertxe.com
..........................................................................................

Enter the option : 2

Search Contact menu :
1. Name
2. Mobile number
3. Mail ID
4. Exit

Enter the option : 1
Enter Name: alvin j
..........................................................................................
S.No  Name                                Mobile Number        Mail Id
..........................................................................................
1     alvin j                             9999222292           alvin@gmail.com
2     alvin j                             9999222299           alvinj@emertxe.com
..........................................................................................

Enter the option : 3
Select the contact: 1
Edit Contact menu :
1. Name
2. Mobile number
3. Mail ID
4. All details

Enter the option : 2
Edit this contact's Mobile number? (y/n): y
Enter Mobile number: 9293949596
Contact's Mobile number has been changed successfully!

Address book menu
1.Add contact
2.Search contact
3.Edit contact
4.Delete contact
5.List contact
6.Save contacts
7.Save and Exit
8.Exit without saving

Enter the option : 8
Exiting without saving...
```
---

## 🧩 Core Logic

* **`add_contact()`** – Adds a new contact after validating fields.
* **`search_contact()`** – Searches existing contacts by name, mobile number, or email.
* **`edit_contact()`** – Allows editing of any contact field.
* **`delete_contact()`** – Removes a selected contact from the list.
* **`list_contacts()`** – Displays all contacts in a formatted list.
* **`save_contact()`** – Writes updated contacts to `AddressBook.csv`.
* **`validate_name()`**, **`validate_email()`**, **`validate_mobile()`** – Validation functions for proper user input.

---

## 🧠 Concepts Used

* File I/O operations.
* Structures and arrays of structures.
* Input validation using character and string operations.
* Modular C programming.
* Command-line, menu-driven UI design

---

## 🚀 Future Improvements

* Add sorting (by name or mobile number).
* Implement search suggestions (partial matches).
* Add encryption or password-based access.
* GUI integration using GTK or Qt.

---

## 🧑‍💻 Author

**Alvin J**

[GitHub: A1vin-J](https://github.com/A1vin-J)

---

## 📄 License

This project is open-source and available under the **MIT License**.
