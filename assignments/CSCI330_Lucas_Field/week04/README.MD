1. Problem 1-1: Banking System
Initial code:
Making the BankAccount class.
```cpp
class BankAccount {
private:
        static int next_account_number;
        static int total_created;
        static int total_destroyed;

protected:
        int account_number;
        char account_name[50];
        double balance;

public:
```
First test run, compile error
```output
banking_system.cpp:24:2: error: expected ';' after class definition
   24 | }
      |  ^
```
Seond test run, static error
```output
/usr/bin/ld: /tmp/ccJbr552.o: warning: relocation against `_ZN11BankAccount19next_account_numberE' in read-only section `.text._ZN11BankAccountC2Ev[_ZN11BankAccountC5Ev]'
/usr/bin/ld: /tmp/ccJbr552.o: in function `BankAccount::BankAccount()':
banking_system.cpp:(.text._ZN11BankAccountC2Ev[_ZN11BankAccountC5Ev]+0x12): undefined reference to `BankAccount::next_account_number'
/usr/bin/ld: banking_system.cpp:(.text._ZN11BankAccountC2Ev[_ZN11BankAccountC5Ev]+0x1b): undefined reference to `BankAccount::next_account_number'
/usr/bin/ld: banking_system.cpp:(.text._ZN11BankAccountC2Ev[_ZN11BankAccountC5Ev]+0x21): undefined reference to `BankAccount::next_account_number'
/usr/bin/ld: warning: creating DT_TEXTREL in a PIE
collect2: error: ld returned 1 exit status
```
Forgot to declare static outside of the class.
Fixed Code.
New output
```output
Created Account #1001
```
Seems to be working

Implementing Account with balance.
```cpp
        BankAccount(double amount) {
                account_number = ++next_account_number;
                strcpy(account_name, "Unknown");
                balance = amount;
                total_created++;
                printf("Created Account #%d, Balance: %.1f\n", account_number, balance);
        }
//Calling it:
BankAccount account2(1500.0);
```
New Output:
```output
Created Account #1001
Created Account #1002, Balance: 1500.0
Implemented Full Account info:
```cpp
        BankAccount(const char* name, double amount) {
                account_number = ++next_account_number;
                strcpy(account_name, name);
                balance = amount;
                total_created++;
                printf("Created Account #%d, Account Holder Name: %s, Balance: %.1f\n", account_number, name, balance);
        }
    //Calling it:
    BankAccount account3("Aaron Smith", 500.0);
```
New Output
```output
Created Account #1001
Created Account #1002, Balance: 1500.0
Created Account #1003, Account Holder Name: Aaron, Balance: 500.0
```
Copy Constructor Implemented.
```cpp
        BankAccount(const BankAccount& other) {
                account_number = next_account_number++;
                strcpy(account_name, other.account_name);
                balance = other.balance;
                total_created++;
                printf("Created Copy of Account #%d, Account Holder Name: %s, Balance: %.1f\n", account_number, other.account_name, other.balance);
        }
```

Implement Logging in each of these constructors, plus a destrcutor.
UPDATED FULL CODE:
```cpp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>

class BankAccount {
private:
    static int total_created;
    int account_number;
    char account_name[100];
    double balance;
    FILE* logFile;

public:
    BankAccount() : account_number(++total_created), balance(0.0), logFile(nullptr) {
        strcpy(account_name, "Unknown");

        char logFilename[120];
        sprintf(logFilename, "account_%d.log", account_number);
        logFile = fopen(logFilename, "w");

        if (logFile) {
            fprintf(logFile, "Account #%d created with default constructor\n", account_number);
            fflush(logFile);
        } else {
            printf("Warning: Could not create log file for account #%d\n", account_number);
        }

        printf("[Constructor] Default BankAccount #%d created\n", account_number);
    }

    BankAccount(double amount) : account_number(++total_created), balance(amount), logFile(nullptr) {
        strcpy(account_name, "Unknown");
        printf("[Constructor] Created Account #%d, Balance: %.1f\n", account_number, balance);
    }

    BankAccount(const char* name, double amount) : account_number(++total_created), balance(amount), logFile(nullptr) {
        strcpy(account_name, name);

        char logFilename[120];
        sprintf(logFilename, "account_%d.log", account_number);
        logFile = fopen(logFilename, "w");

        if (logFile) {
            fprintf(logFile, "Account #%d created for %s with initial deposit $%.2f\n",
                    account_number, name, amount);
            fflush(logFile);
        }

        printf("[Constructor] BankAccount for %s created with $%.2f\n", name, amount);
    }

    BankAccount(const BankAccount& other) : account_number(++total_created), balance(other.balance), logFile(nullptr) {
        strcpy(account_name, other.account_name);
        strcat(account_name, " (Copy)");

        char logFilename[120];
        sprintf(logFilename, "account_%d.log", account_number);
        logFile = fopen(logFilename, "w");

        if (logFile) {
            fprintf(logFile, "Account #%d created as copy of account #%d\n",
                    account_number, other.account_number);
            fflush(logFile);
        }

        printf("[Copy Constructor] Copying account #%d\n", other.account_number);
    }

    BankAccount& operator=(const BankAccount& other) {
        if (this != &other) {
            if (logFile) {
                fprintf(logFile, "Account #%d being reassigned\n", account_number);
                fclose(logFile);
                logFile = nullptr;
            }

            strcpy(account_name, other.account_name);
            balance = other.balance;

            char logFilename[120];
            sprintf(logFilename, "account_%d.log", account_number);
            logFile = fopen(logFilename, "a");

            if (logFile) {
                fprintf(logFile, "Account reassigned with data from account #%d\n", other.account_number);
                fflush(logFile);
            }

            printf("[Assignment] Assigning account #%d to account #%d\n",
                   other.account_number, this->account_number);
        }
        return *this;
    }

    ~BankAccount() {
        printf("Destroying account #%d, logFile = %p\n", account_number, (void*)logFile);

        if (logFile != nullptr) {
            int result = fprintf(logFile, "Account #%d being destroyed. Final balance: $%.2f\n",
                                account_number, balance);
            if (result < 0) {
                printf("Error writing to log file during destruction\n");
            }
            fflush(logFile);
            fclose(logFile);
            logFile = nullptr;
        }

        printf("[Destructor] BankAccount #%d destroyed\n", account_number);
    }
};

int BankAccount::total_created = 0;

int main() {
    printf("Creating accounts...\n");

    BankAccount account1;
    BankAccount account2(1500.0);
    BankAccount account3("Aaron", 500.0);
    BankAccount account4 = account3;

    printf("\nTesting assignment...\n");
    account1 = account2;

    printf("\nAccounts created, now destroying...\n");
    return 0;
}
```
Implementing other classes, AccountLock, AccountBackup.
(Referenced Claude + Homework Hints)
```cpp
class AccountLock {
 private:
  BankAccount* account;
  bool was_locked;

 public:
  AccountLock(BankAccount& acc);
  ~AccountLock();
};

class BalanceBackup {
 private:
  BankAccount& account;
  double original_balance;
  bool committed;

 public:
  BalanceBackup(BankAccount& acc);
  ~BalanceBackup();
  void commit() { committed = true; }
};
```
Implementing more functionality,to withdraw, deposit, display.
```cpp
void deposit(double amount) {
    if (is_locked) {
      printf("[Error] Account #%d is locked\n", accountNumber);
      return;
    }

    if (amount > 0) {
      balance += amount;

      if (logFile) {
        fprintf(logFile, "DEPOSIT: $%.2f, New balance: $%.2f\n", amount,
                balance);
        fflush(logFile);
      }

      printf("Deposited $%.2f to account #%d. New balance: $%.2f\n", amount,
             accountNumber, balance);
    }
  }

  bool withdraw(double amount) {
    if (is_locked) {
      printf("[Error] Account #%d is locked\n", accountNumber);
      return false;
    }

    if (amount > 0 && amount <= balance) {
      balance -= amount;

      if (logFile) {
        fprintf(logFile, "WITHDRAW: $%.2f, New balance: $%.2f\n", amount,
                balance);
        fflush(logFile);
      }

      printf("Withdrew $%.2f from account #%d. New balance: $%.2f\n", amount,
             accountNumber, balance);
      return true;
    } else {
      printf("Insufficient funds in account #%d\n", accountNumber);
      return false;
    }
  }

  void display() const {
    printf("Account #%d - %s: $%.2f", accountNumber, accountHolder, balance);
    if (is_locked) printf(" [LOCKED]");
    printf("\n");
  }
  ```
  TransactionLogger class, I referenced Homework Hints + Claude to implement and help me better understand.
  ```cpp
  class TransactionLogger {
 private:
  FILE* file;
  char filename[100];

 public:
  TransactionLogger(const char* logname) {
    strcpy(filename, logname);
    file = fopen(filename, "a");

    if (file) {
      time_t now = time(0);
      fprintf(file, "\n Logger started at %s", ctime(&now));
      fflush(file);
    }

    printf("[Logger] Transaction logger '%s' started\n", filename);
  }

  ~TransactionLogger() {
    if (file) {
      time_t now = time(0);
      fprintf(file, " Logger closed at %s\n", ctime(&now));
      fclose(file);
    }

    printf("[Logger] Transaction logger '%s' closed\n", filename);
  }

  void log(const char* transaction) {
    if (file) {
      time_t now = time(0);
      char* timestr = ctime(&now);
      timestr[strlen(timestr) - 1] = '\0';
      fprintf(file, "[%s] %s\n", timestr, transaction);
      fflush(file);

      printf("[LOG] %s\n", transaction);
    }
  }

  TransactionLogger(const TransactionLogger&) = delete;
  TransactionLogger& operator=(const TransactionLogger&) = delete;
};

bool simple_transfer(BankAccount& from, BankAccount& to, double amount) {
  printf("[Transaction Log] Transfer initiated: #%d -> #%d, $%.2f\n",
         from.get_account_number(), to.get_account_number(), amount);

  TransactionLogger logger("bank_transactions.log");
  AccountLock from_lock(from);
  BalanceBackup from_backup(from);

  char log_msg[200];
  sprintf(log_msg, "Transfer: Account #%d to #%d, Amount: $%.2f",
          from.get_account_number(), to.get_account_number(), amount);
  logger.log(log_msg);

  if (from.withdraw(amount)) {
    to.deposit(amount);
    from_backup.commit();
    printf("[Success] Transfer completed successfully\n");
    return true;
  } else {
    printf("[Failed] Transfer failed - balance will be restored\n");
    return false;
  }
}

void demonstrate_scope_and_lifetime() {
  {
    printf("Entering inner scope...\n");
    BankAccount tempAccount("Temporary User", 100.00);
    tempAccount.display();
    tempAccount.deposit(50.00);
    printf("Leaving inner scope...\n");
  }

  printf("Back in outer scope\n");
}

void demonstrate_array_lifecycle() {
  printf("Creating array of 3 accounts...\n");
  BankAccount accounts[3];
  BankAccount temp1("Account 1", 1000.00);
  BankAccount temp2("Account 2", 2000.00);
  BankAccount temp3("Account 3", 3000.00);

  accounts[0] = temp1;
  accounts[1] = temp2;
  accounts[2] = temp3;

  printf("Array going out of scope...\n");
}

void demonstrate_copy_operations() {
  BankAccount original("Alice", 1000.00);
  original.deposit(500.00);
  BankAccount copy = original;

  BankAccount another("Bob", 500.00);
  another = original;

  printf("Original: ");
  original.display();
  printf("Copy: ");
  copy.display();
  printf("Another: ");
  another.display();
}
```
The TransactionLogger class is a resource management class for the Log File that handles the file automatically. Instead of relying on the programmer to manually type fclose for everytime we open and close the log file opens and closes automatically.