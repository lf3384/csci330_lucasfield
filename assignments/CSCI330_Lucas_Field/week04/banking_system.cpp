#include <cstdio>
#include <cstring>
#include <ctime>

class BankAccount;
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

class BankAccount {
 private:
  static int totalAccounts;
  char accountHolder[100];
  int accountNumber;
  double balance;
  FILE* logFile;
  bool is_locked;

 public:
  BankAccount() {
    accountNumber = ++totalAccounts;
    strcpy(accountHolder, "Unknown");
    balance = 0.0;
    is_locked = false;

    char logFileName[120];
    sprintf(logFileName, "Account_%d.log", accountNumber);
    logFile = fopen(logFileName, "w");

    if (logFile) {
      fprintf(logFile, "Account #%d created with default constructor\n",
              accountNumber);
      fflush(logFile);
    }

    printf("[Constructor] Default BankAccount #%d created\n", accountNumber);
  }

  BankAccount(const char* name, double initialDeposit) {
    accountNumber = ++totalAccounts;
    strcpy(accountHolder, name);
    balance = initialDeposit;
    is_locked = false;

    char logFileName[120];
    sprintf(logFileName, "Account_%d.log", accountNumber);
    logFile = fopen(logFileName, "w");

    if (logFile) {
      fprintf(logFile,
              "Account #%d created for %s with initial deposit $%.2f\n",
              accountNumber, name, initialDeposit);
      fflush(logFile);
    }

    printf("[Constructor] BankAccount for %s created with $%.2f\n", name,
           initialDeposit);
  }

  BankAccount(const BankAccount& other) {
    accountNumber = ++totalAccounts;
    strcpy(accountHolder, other.accountHolder);
    strcat(accountHolder, " (Copy)");
    balance = other.balance;
    is_locked = false;

    char logFileName[120];
    sprintf(logFileName, "Account_%d.log", accountNumber);
    logFile = fopen(logFileName, "w");

    if (logFile) {
      fprintf(logFile, "Account #%d created as copy of account #%d\n",
              accountNumber, other.accountNumber);
      fflush(logFile);
    }

    printf("[Copy Constructor] Copying account #%d\n", other.accountNumber);
  }

  ~BankAccount() {
    if (logFile) {
      fprintf(logFile, "Account #%d being destroyed. Final balance: $%.2f\n",
              accountNumber, balance);
      fclose(logFile);
    }

    printf("[Destructor] BankAccount #%d destroyed\n", accountNumber);
  }

  BankAccount& operator=(const BankAccount& other) {
    if (this != &other) {
      if (logFile) {
        fprintf(logFile, "Account #%d being reassigned\n", accountNumber);
        fclose(logFile);
      }

      strcpy(accountHolder, other.accountHolder);
      balance = other.balance;

      char logFileName[120];
      sprintf(logFileName, "Account_%d.log", accountNumber);
      logFile = fopen(logFileName, "a");

      if (logFile) {
        fprintf(logFile, "Account reassigned with data from account #%d\n",
                other.accountNumber);
        fflush(logFile);
      }
    }

    printf("[Assignment] Assigning account #%d to account #%d\n",
           other.accountNumber, this->accountNumber);
    return *this;
  }

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

  double get_balance() const { return balance; }
  void set_balance(double new_balance) { balance = new_balance; }
  void set_locked(bool locked) { is_locked = locked; }
  bool get_is_locked() const { return is_locked; }
  int get_account_number() const { return accountNumber; }

  static int getTotalAccounts() { return totalAccounts; }
};

int BankAccount::totalAccounts = 0;

AccountLock::AccountLock(BankAccount& acc)
    : account(&acc), was_locked(acc.get_is_locked()) {
  account->set_locked(true);
  printf("[AccountLock] Account #%d locked\n", account->get_account_number());
}

AccountLock::~AccountLock() {
  account->set_locked(was_locked);
  printf("[AccountLock] Account #%d unlocked\n", account->get_account_number());
}

BalanceBackup::BalanceBackup(BankAccount& acc)
    : account(acc), original_balance(acc.get_balance()), committed(false) {
  printf("[BalanceBackup] Backup created: $%.2f\n", original_balance);
}

BalanceBackup::~BalanceBackup() {
  if (!committed) {
    account.set_balance(original_balance);
    printf("[BalanceBackup] Balance restored to $%.2f\n", original_balance);
  } else {
    printf("[BalanceBackup] Backup released (transaction succeeded)\n");
  }
}

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

int main() {
  printf("Initial total accounts: %d\n\n", BankAccount::getTotalAccounts());
  BankAccount account1;
  BankAccount account2("John Doe", 1500.00);

  account2.deposit(200.00);
  account2.withdraw(50.00);
  account2.display();

  {
    TransactionLogger logger("transactions.log");
    logger.log("System started");
    logger.log("Account created");
  }

  BankAccount alice("Alice", 1000.00);
  BankAccount bob("Bob", 500.00);
  simple_transfer(alice, bob, 200.00);

  demonstrate_scope_and_lifetime();
  demonstrate_array_lifecycle();
  demonstrate_copy_operations();

  printf("Total accounts created: %d\n", BankAccount::getTotalAccounts());
  return 0;
}