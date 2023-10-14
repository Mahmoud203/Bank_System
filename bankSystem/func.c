#include <stdio.h>
#include <stdlib.h>
#include "std_types.h"
#include "func.h"
#include <string.h>
#include <time.h>

// function to generate a random 10-digit Bank Account ID
u32 generateRandomAccountID() {
    return rand() % 9000000000U + 1000000000U;       // 9000000000 to make it 10 digits   //+1000000000 to start from the end 
}

// function to generate a random password
void generateRandomPassword(u8* password, u32 length) {
    const u8 charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";    //array of characters and numbers
    for (u32 i = 0; i < length; i++) {
        u32 index = rand() % (u32)(sizeof(charset) - 1);    //rand function to genarate random values
        password[i] = charset[index];
    }
    password[length] = '\0';                     // to go to the end of the string
}

// function to create a new bank account
struct BankAccount* createNewAccount(u8* fullName, u8* address, u32 age, u8* nationalID, u8* guardianNationalID, f64 balance) {
    struct BankAccount* newAccount = (struct BankAccount*)malloc(sizeof(struct BankAccount));     //dynamic allocations for linked list
    if (newAccount == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    // generate random 10-digit Bank Account ID
    newAccount->accountID = generateRandomAccountID();

    // generate random 6-character password
    generateRandomPassword(newAccount->password, 6);

    strcpy(newAccount->fullName, fullName);
    strcpy(newAccount->address, address);
    newAccount->age = age;
    strcpy(newAccount->nationalID, nationalID);
    strcpy(newAccount->guardianNationalID, guardianNationalID);
    newAccount->balance = balance;
    newAccount->isActive = 1; // account is active by default
    newAccount->transactions = NULL; // initialize transactions list
    newAccount->next = NULL;

    return newAccount;
}

// function to open an existing account
struct BankAccount* openExistingAccount(struct BankAccount* head, u32 accountID) {
    // Search for the account by accountID in the linked list
    struct BankAccount* current = head;
    while (current != NULL) {
        if (current->accountID == accountID && current->isActive == 1) {
            return current;
        }
        current = current->next;
    }

    printf("Account not found or inactive\n");
    return NULL;
}

// function to make a transaction
void makeTransaction(struct BankAccount* sourceAccount, struct BankAccount* targetAccount, f64 amount) {
    if (sourceAccount == NULL || targetAccount == NULL) {
        printf("Invalid account(s) for transaction\n");
        return;
    }

    if (sourceAccount->balance >= amount) {                 //check if you have enough money
        sourceAccount->balance -= amount;                   // take the cash from your account
        targetAccount->balance += amount;                   //add them in the target account
        printf("Transaction completed successfully\n");
    } else {
        printf("Insufficient balance for the transaction\n");
    }
}

// function to change account status
void changeAccountStatus(struct BankAccount* account, u32 status) {
    if (account == NULL) {
        printf("Invalid account\n");
        return;
    }

    switch (status) {
        case 1:
            account->isActive = 1; // set account to active state
            break;
        case 2:
            account->isActive = 2; // set account to restricted state
            break;
        case 3:
            account->isActive = 0; // set account to closed
            break;
        default:
            printf("Invalid status\n");
    }
}

// function to get cash from the account
void getCash(struct BankAccount* account, f64 amount) {
    if (account == NULL) {
        printf("Invalid account\n");
        return;
    }

    if (account->balance >= amount) {            //check account balance
        account->balance -= amount;              // take amount of cash you want
        printf("Transaction successful. Remaining balance: %.2lf\n", account->balance);
    } else {
        printf("Not enough money for the transaction\n");
    }
}

// function to deposit cash into the account
void depositCash(struct BankAccount* account, f64 amount) {
    if (account == NULL) {
        printf("Invalid account\n");
        return;
    }

    if (amount > 0) {
        account->balance += amount;             //add amount of cash you want
        printf("Deposit successful. New balance: %.2lf\n", account->balance);
    } else {
        printf("Invalid deposit amount\n");
    }
}

// function to change the account password
void changeAccountPassword(struct BankAccount* account, u8* newPassword) {
    if (account == NULL) {
        printf("Invalid account\n");
        return;
    }
    strcpy(account->password, newPassword);          //copy the string from new password to password variable in the struct
    printf("Password changed successfully\n");
}




