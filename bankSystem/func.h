#ifndef _FUNC_H
#define _FUNC_H

// Define structures for bank account and transaction
struct Transaction {
    u32 accountID;
    f64 amount;
    struct Transaction* next;
};

struct BankAccount {
    u32 accountID;
    u8 password[7]; // Store the randomly generated password
    u8 fullName[100];
    u8 address[100];
    u32 age;
    u8 nationalID[20];
    u8 guardianNationalID[20];
    f64 balance;
    u32 isActive; // 1 for active, 0 for inactive
    struct Transaction* transactions;
    struct BankAccount* next;
};

u32 generateRandomAccountID();
void generateRandomPassword(u8* password, u32 length);
struct BankAccount* createNewAccount(u8* fullName, u8* address, u32 age, u8* nationalID, u8* guardianNationalID, f64 balance);
struct BankAccount* openExistingAccount(struct BankAccount* head, u32 accountID);
void makeTransaction(struct BankAccount* sourceAccount, struct BankAccount* targetAccount, f64 amount);
void changeAccountStatus(struct BankAccount* account, u32 status);
void getCash(struct BankAccount* account, f64 amount);
void depositCash(struct BankAccount* account, f64 amount);
void changeAccountPassword(struct BankAccount* account, u8* newPassword);

#endif