#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Design 1: Student class
class Student {
 private:
  string name;
  double gpa;

 public:
  Student(const string& name, double gpa) : name(name), gpa(gpa) {}

  // Question: Are these good operator overloads?
  Student operator+(const Student& other) const {
    // "Adding" students by averaging their GPAs?
    return Student(name + " & " + other.name, (gpa + other.gpa) / 2);
  }

  bool operator<(const Student& other) const {
    // Comparing by GPA for sorting
    return gpa < other.gpa;
  }

  Student& operator<<(const string& course) {
    // "Enrolling" student in course?
    cout << name << " enrolled in " << course << endl;
    return *this;
  }

  string get_name() const { return name; }
  double get_gpa() const { return gpa; }
};

// Design 2: BankAccount class
class BankAccount {
 private:
  string account_number;
  double balance;

 public:
  BankAccount(const string& account_number, double initial_balance = 0.0)
      : account_number(account_number), balance(initial_balance) {}

  // Question: Are these good operator overloads?
  BankAccount operator+(double amount) const {
    // Adding money to account
    return BankAccount(account_number, balance + amount);
  }

  BankAccount operator-(const BankAccount& other) const {
    // Transferring money between accounts?
    return BankAccount(account_number, balance - other.balance);
  }

  bool operator>(const BankAccount& other) const {
    // Comparing account balances
    return balance > other.balance;
  }

  double get_balance() const { return balance; }
  string get_account_number() const { return account_number; }
};

// TODO: For each questionable operator overload above, suggest a better
// alternative Write your analysis and improvements here:

/*
Your analysis:

Design 1 (Student class):
- operator+(): [Good/Bad?] Why?
-BAD, adding students is not intuitive, "alice + bob" doesn't mean anything.

- operator<(): [Good/Bad?] Why?
BAD, also because it is confusing, what is alice > bob even comparing?
- operator<<(): [Good/Bad?] Why?
BAD, the "<<" causes confusions with "cout <<" statements.
- Better alternatives:
Instead of " Student combined = alice + bob;", do this: "Student combined =
Student :: combine(alice, bob)"

Instead of "return gpa < other.gpa", two main alternatives. First one being a
simpler way to compare, using "if(alice.hasLowerGPA(bob)){...}", this is much
more direct and clear. Second option, if you wanted to compare other items,
create different comparisons, like gpa, their name alphabetically.

Instead of "<<" which is confusing, replace with something like
"bob.enrollIn("math");"

Design 2 (BankAccount class):
- operator+(): [Good/Bad?] Why?
BAD, original account won't change values. It creates a new account with the new
value, the orginal value you are trying to change remains the same.
- operator-(): [Good/Bad?] Why?
BAD, this does the same sort of thing as previous operator, where it does do the
math part of it, but the values don't behave as expected. A new value will be
created with the updated value, the original value won't be changed.
- operator>(): [Good/Bad?] Why?
BAD, this is an ambiguous comparison. if you see in int main account1 >
account2, that will be confusing.
- Better alternatives:

Instead of operator+(), use account1.deposit(250); account1 += 250;

Instead of operator-(), use account2.withdraw(200); account2 -= 250;

Instead of operator<(), use account1.hasMoreMoney(account2);
*/

int main() {
  // Test the designs and think about whether they feel natural
  Student alice("Alice", 3.8);
  Student bob("Bob", 3.2);

  // Does this make sense?
  Student combined = alice + bob;
  cout << "Combined student: " << combined.get_name()
       << " with GPA: " << combined.get_gpa() << endl;
  // Doesn't make sense, "alice + bob" makes no sense, it appears as you are
  // concating the strings "alice" and "bob"

  // Does this make sense?
  alice << "Mathematics" << "Physics";
  // No, this doesn't make sense, it looks like a cout statement, which can
  // cause a lot of confusion.

  BankAccount account1("12345", 1000.0);
  BankAccount account2("67890", 500.0);

  // Does this make sense?
  BankAccount after_deposit = account1 + 200.0;
  cout << "After deposit: $" << after_deposit.get_balance() << endl;
  // It looks like it makes more sense than the others, but still not best
  // practice. Not clear what 200.0 is specifically adding to in account1. Also
  // won't get expected results.

  // Does this make sense?
  BankAccount after_transfer = account1 - account2;
  cout << "After transfer: $" << after_transfer.get_balance() << endl;
  // No, this doesn't make sense, it looks like you are subtracting account2
  // from account1. Also just not clear on what account1-account2 is even doing.

  return 0;
}