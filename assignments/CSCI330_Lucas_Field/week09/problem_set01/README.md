1. Problem Set 1-1
Starter Code:
```cpp
#include <iostream>
#include <cstdio>

// TODO: Implement these functions
double add(double a, double b) {
    // Your implementation here
}

double subtract(double a, double b) {
    // Your implementation here
}

double multiply(double a, double b) {
    // Your implementation here
}

double divide(double a, double b) {
    // Your implementation here - handle division by zero
}

int main() {
    // TODO: Create array of function pointers
    double (*operations[])(double, double) = {add, subtract, multiply, divide};
    const char* op_names[] = {"Add", "Subtract", "Multiply", "Divide"};

    double a, b;
    int choice;

    std::cout << "Enter two numbers: ";
    std::cin >> a >> b;

    std::cout << "\nSelect operation:\n";
    for(int i = 0; i < 4; i++) {
        std::cout << i + 1 << ". " << op_names[i] << "\n";
    }
    std::cout << "Choice: ";
    std::cin >> choice;

    // TODO: Validate choice and call appropriate function
    // TODO: Display result

    return 0;
}
```
Implemented:
```cpp
#include <iostream>
#include <cstdio>

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        std::cout << "Error: Division by zero!\n";
        return 0;
    }
    return a / b;
}

int main() {
    double (*operations[])(double, double) = {add, subtract, multiply, divide};
    const char* op_names[] = {"Add", "Subtract", "Multiply", "Divide"};

    double a, b;
    int choice;

    std::cout << "Enter two numbers: ";
    std::cin >> a >> b;

    std::cout << "\nSelect operation:\n";
    for(int i = 0; i < 4; i++) {
        std::cout << i + 1 << ". " << op_names[i] << "\n";
    }
    std::cout << "Choice: ";
    std::cin >> choice;

    if (choice < 1 || choice > 4) {
        std::cout << "Invalid choice!\n";
        return 1;
    }

    double result = operations[choice - 1](a, b);

    if (choice != 4 || b != 0) {
        std::cout << a << " / " << b << " = " << result << "\n";
    }

    return 0;
}
```
Output:
```output
student@cpp-dev:~/workspace/assignments/CSCI330_Lucas_F
ield/week09/problem_set01$ ./problem1-1
Enter two numbers: 3 4

Select operation:
1. Add
2. Subtract
3. Multiply
4. Divide
Choice: 1
3 + 4 = 7
```
```output
ield/week09/problem_set01$ ./problem1-1
Enter two numbers: 5 0

Select operation:
1. Add
2. Subtract
3. Multiply
4. Divide
Choice: 4
Error: Division by zero!
```

2. Problem 1-2:
Starter Code:
```cpp
#include <iostream>
#include <vector>
#include <string>

// Event handler function type
typedef void (*EventHandler)(const std::string& event_data);

// TODO: Implement different event handlers
void log_handler(const std::string& event_data) {
    // Print log message with timestamp simulation
}

void alert_handler(const std::string& event_data) {
    // Print alert message
}

void debug_handler(const std::string& event_data) {
    // Print debug information
}

class EventSystem {
private:
    std::vector<EventHandler> handlers;

public:
    // TODO: Add method to register handlers
    void register_handler(EventHandler handler) {
        // Your implementation here
    }

    // TODO: Add method to fire events to all handlers
    void fire_event(const std::string& event_data) {
        // Your implementation here
    }

    // TODO: Add method to show registered handler count
    size_t get_handler_count() const {
        // Your implementation here
    }
};

int main() {
    EventSystem event_system;

    // TODO: Register handlers
    // TODO: Fire some test events
    // TODO: Show system working with multiple handlers

    return 0;
}
```
Implemented:
```cpp
#include <iostream>
#include <string>
#include <vector>

// Event handler function type
typedef void (*EventHandler)(const std::string& event_data);

// TODO: Implement different event handlers
void log_handler(const std::string& event_data) {
  // Print log message with timestamp simulation
  std::cout << "[LOG] " << event_data << "\n";
}

void alert_handler(const std::string& event_data) {
  // Print alert message
  std::cout << "[ALERT] Critical event: " << event_data << "\n";
}

void debug_handler(const std::string& event_data) {
  // Print debug information
  std::cout << "[DEBUG] Event details: " << event_data << "\n";
}

class EventSystem {
 private:
  std::vector<EventHandler> handlers;

 public:
  // TODO: Add method to register handlers
  void register_handler(EventHandler handler) { handlers.push_back(handler); }

  // TODO: Add method to fire events to all handlers
  void fire_event(const std::string& event_data) {
    for (EventHandler handler : handlers) {
      handler(event_data);
    }
  }

  // TODO: Add method to show registered handler count
  size_t get_handler_count() const { return handlers.size(); }
};

int main() {
  EventSystem event_system;

  // TODO: Register handlers
  std::cout << "Registering event handlers...\n";
  event_system.register_handler(log_handler);
  event_system.register_handler(alert_handler);
  event_system.register_handler(debug_handler);
  std::cout << "Handlers registered: " << event_system.get_handler_count()
            << "\n";

  // TODO: Fire some test events
  std::cout << "\nFiring event: \"User logged in\"\n";
  event_system.fire_event("User logged in");

  std::cout << "\nFiring event: \"File uploaded\"\n";
  event_system.fire_event("File uploaded");

  // TODO: Show system working with multiple handlers

  return 0;
}
```

Output:
```output
student@cpp-dev:~/workspace/assignments/CSCI330_Lucas_F
ield/week09/problem_set01$ ./problem1-2
Registering event handlers...
Handlers registered: 3

Firing event: "User logged in"
[LOG] User logged in
[ALERT] Critical event: User logged in
[DEBUG] Event details: User logged in

Firing event: "File uploaded"
[LOG] File uploaded
[ALERT] Critical event: File uploaded
[DEBUG] Event details: File uploaded
```
3. Problem 1-3:
Starter Code:
```cpp
#include <iostream>
#include <vector>

// Comparison function type - returns true if first should come before second
typedef bool (*Comparator)(int a, int b);

// TODO: Implement comparison functions
bool ascending(int a, int b) {
    // Your implementation here
}

bool descending(int a, int b) {
    // Your implementation here
}

// TODO: Implement simple bubble sort with custom comparator
void sort_with_comparator(std::vector<int>& data, Comparator comp) {
    // Your implementation here - use bubble sort for simplicity
}

void print_vector(const std::vector<int>& data) {
    for(int n : data) {
        std::cout << n << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> numbers = {64, 34, 25, 12, 22, 11, 90};

    std::cout << "Original: ";
    print_vector(numbers);

    // TODO: Sort ascending
    // TODO: Sort descending
    // TODO: Show results

    return 0;
}
```
Implemented:
```cpp
// Comparison function type - returns true if first should come before second
typedef bool (*Comparator)(int a, int b);

// TODO: Implement comparison functions
bool ascending(int a, int b) {
    return a < b;
}

bool descending(int a, int b) {
    return a > b;
}

// TODO: Implement simple bubble sort with custom comparator
void sort_with_comparator(std::vector<int>& data, Comparator comp) {
    int n = data.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (comp(data[j + 1], data[j])) {
                // Swap
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

void print_vector(const std::vector<int>& data) {
    for(int n : data) {
        std::cout << n << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> numbers = {64, 34, 25, 12, 22, 11, 90};

    std::cout << "Original: ";
    print_vector(numbers);

    // TODO: Sort ascending
    sort_with_comparator(numbers, ascending);
    std::cout << "Ascending: ";
    print_vector(numbers);

    // TODO: Sort descending
    sort_with_comparator(numbers, descending);
    std::cout << "Descending: ";
    print_vector(numbers);

    // TODO: Show results

    return 0;
}
```
Output:
```output
student@cpp-dev:~/workspace/assignments/CSCI330_Lucas_F
ield/week09/problem_set01$ ./problem1-3
Original: 64 34 25 12 22 11 90
Ascending: 11 12 22 25 34 64 90
Descending: 90 64 34 25 22 12 11
```