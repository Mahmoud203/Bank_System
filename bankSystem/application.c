#include <stdio.h>
#include <stdlib.h>
#include "std_types.h"
#include "func.h"
#include <string.h>
#include <time.h>

int main() {
		struct BankAccount* head = NULL;
		srand(time(NULL));                   //to generate new random numbers every time you call the function
		u32 login_choice;
		while (1) {
		printf("1. Admin Window\n");
		printf("2. Client Window\n");
		printf("Enter your choice: ");
		scanf("%u", &login_choice);
		switch (login_choice) {
		case 1: {
		const u8 adminUsername[] = "mahmoud bahaa eldeen";           //admin name to login admin window
		const u8 adminPassword[] = "imt2023";                        //admin password to login admin window
		u8 username[100], password[100];
		printf("Admin Login\n");
		printf("Username: ");
		scanf(" %[^\n]", username);
		printf("Password: ");
		scanf(" %[^\n]", password);

		if (strcmp(username, adminUsername) == 0 && strcmp(password, adminPassword) == 0) {        //check if the name and pass are correct
		u32 choice;
	admin_main_menu: while (1) {
				printf("\nAdmin Main Menu:\n");
				printf("1. Create New Account\n");
				printf("2. Open Existing Account\n");
				printf("3. Exit\n");
				printf("Enter your choice: ");
				scanf("%u", &choice);

		switch (choice) {
	case 1: {
		// create new account
		u8 fullName[100], address[100], nationalID[20], guardianNationalID[20];
		u32 age;
		f64 balance;

		printf("Enter Full Name: ");
		scanf(" %[^\n]", fullName);
		printf("Enter Address: ");
		scanf(" %[^\n]", address);
		printf("Enter Age: ");
		scanf("%u", &age);
		printf("Enter National ID: ");
		scanf(" %[^\n]", nationalID);

		if (age < 21) {
			printf("Enter Guardian National ID: ");
			scanf(" %[^\n]", guardianNationalID);
		} else {
	strcpy(guardianNationalID, "N/A");
		}

		printf("Enter Initial Balance: ");
		scanf("%lf", &balance);

		struct BankAccount* newAccount = createNewAccount(fullName, address, age, nationalID, guardianNationalID, balance);
		if (newAccount != NULL) {
			// add the new account(node)to the linked list
			newAccount->next = head;
			head = newAccount;
			printf("Account created successfully.\n");
			printf("Account ID: %u\n", newAccount->accountID);
			printf("Password: %s\n", newAccount->password);
			printf("************************************************\n");
		}
		break;
	}
	case 2: {
		// open existing account
		u32 accountID;
		printf("Enter Bank Account ID: ");
		scanf("%u", &accountID);
		struct BankAccount* clientAccount = openExistingAccount(head, accountID);
		if (clientAccount != NULL) {
			printf("Account found!\n");
			u32 subChoice;
			while (1) {
		printf("\nChoose Your Option:\n");
		printf("1. Make Transaction\n");
		printf("2. Change Account Status\n");
		printf("3. Deposit in Account\n");
		printf("4. Get Cash\n");
		printf("5. Go Back to Main Menu\n");
		printf("Enter your choice: ");
		scanf("%u", &subChoice);

		switch (subChoice) {
			case 1: {
		// make transaction
		u32 sourceAccountID;
		f64 amount;

		printf("Enter Target Account ID: ");
		scanf("%u", &sourceAccountID);
		struct BankAccount* sourceAccount = openExistingAccount(head, sourceAccountID);         //call openExistingAccount function

		if (sourceAccount != NULL) {
			printf("Enter Amount: ");
			scanf("%lf", &amount);
			makeTransaction(sourceAccount, clientAccount, amount);             //call makeTransaction function
		}
		break;
	}
	case 2: {
		// change account status
		u32 status;
		printf("Change Account Status:\n");
		printf("1. Set Account to Active State\n");
		printf("2. Set Account to Restricted State\n");
		printf("3. Set Account to Closed\n");
		printf("Enter your choice: ");
		scanf("%u", &status);
		changeAccountStatus(clientAccount, status);               //call changeAccountStatus function
		printf("Status changed successfully!\n");
		break;
	}
	case 3: {
		// deposit in account
		f64 depositAmount;
		printf("Enter Deposit Amount: ");
		scanf("%lf", &depositAmount);
		depositCash(clientAccount, depositAmount);               //call depositCash function
		break;
	}
	case 4: {
		// get cash
		f64 cashAmount;
		printf("Enter Cash Amount: ");
		scanf("%lf", &cashAmount);
		getCash(clientAccount, cashAmount);                      //call getCash function
		break;
	}
	case 5:
		// go back to main menu
		break;   //break the switch
	default:
		printf("Invalid choice\n");
		}
		printf("************************************************\n");
		if (subChoice == 5) {
			break;     //break while loop of options
		}
	}
  }
		break;    //break the if loop
	}
			case 3:
				// exit
				break;
			default:
				printf("Invalid choice\n");
		}
		if (choice == 3) {
			printf("************************************************\n");
			break;   //break while loop of options
		}
	}
			break;    //break the if loop
		} else {
			printf("Incorrect username or password\n");
		}
		return 0;
		}

		case 2: {
		// client window
		u32 clientAccountID;
		u8 clientPassword[7];

		printf("Client Login\n");
		printf("Bank Account ID: ");
		scanf("%d", &clientAccountID);
		printf("Password: ");
		scanf("%s", clientPassword);

		struct BankAccount* clientAccount = openExistingAccount(head, clientAccountID);    //call openExistingAccount function

		if (clientAccount != NULL && strcmp(clientAccount->password, clientPassword) == 0) {    //check pass you enter if it correct
			printf("Login successful!\n");

	u32 clientChoice;
	while (1) {
		printf("\nClient Menu:\n");
		printf("1. Make Transaction\n");
		printf("2. Change Account Password\n");
		printf("3. Get Cash\n");
		printf("4. Deposit in Account\n");
		printf("5. Return to main Menu\n");
		printf("Enter your choice: ");
		scanf("%u", &clientChoice);

		switch (clientChoice) {
			case 1: {
		// make transaction
		u32 sourceAccountID;
		f64 amount;

		printf("Enter Target Account ID: ");
		scanf("%u", &sourceAccountID);
		struct BankAccount* sourceAccount = openExistingAccount(head, sourceAccountID);

		if (sourceAccount != NULL) {
			printf("Enter Amount: ");
			scanf("%lf", &amount);
			makeTransaction(sourceAccount, clientAccount, amount);
		}
		break;
	}
	case 2: {
		// change password
		u8 newPassword[7];
		printf("Enter New Password: ");
		scanf("%s", newPassword);
		changeAccountPassword(clientAccount, newPassword);
		break;
	}
	case 3: {
		// get cash
		f64 cashAmount;
		printf("Enter Cash Amount: ");
		scanf("%lf", &cashAmount);
		getCash(clientAccount, cashAmount);
		break;
	}
	case 4: {
		// deposit in account
		f64 depositAmount;
		printf("Enter Deposit Amount: ");
		scanf("%lf", &depositAmount);
		depositCash(clientAccount, depositAmount);
		break;
	}
	case 5: {
		goto admin_main_menu;
		break;
	}
		}
	}
	} else {
		printf("Incorrect accountID or password\n");
	}
	break;
	}
	}
	}
	}

