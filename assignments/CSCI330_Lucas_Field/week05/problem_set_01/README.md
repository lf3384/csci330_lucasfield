1. Problem Set 1-1
Starter code:
```cpp
#include <iostream>

struct Animal {
    virtual ~Animal() = default;
    virtual void make_sound() const {
        std::cout << "Some generic animal sound\n";
    }
};

struct Dog : Animal {
    // Your override here
};

int main() {
    Animal* animal = new Dog();
    animal->make_sound();  // Should print "Woof!"
    delete animal;
    return 0;
}
```
This is what I inserted:
```cpp
struct Dog : Animal {
  void make_sound() const { std::cout << "Woof!\n"; }
};
```
Output:
```output
student@cpp-dev:~/workspace/assignments/CSCI330_Lucas_
Field/week05/problem_set_01$ ./problem1-1
Woof!
```
2. Problem Set 1-2
Starting Code:
```cpp
#include <iostream>

struct Animal {
  virtual ~Animal() = default;
  virtual void make_sound() const {
    std::cout << "Some generic animal sound\n";
  }
};

struct Dog : Animal {
  void make_sound() const { std::cout << "Woof!\n"; }
};

int main() {
  Animal* animal = new Dog();
  animal->make_sound();  // Should print "Woof!"
  delete animal;
  return 0;
}
```
Insert override keyword:
```cpp

struct Dog : Animal {
  void make_sound() const override { std::cout << "Woof!\n"; }
};
```
Purposely create a typo:
```cpp
struct Dog : Animal {
  void make_snound() const override { std::cout << "Woof!\n"; }
};
```
Compiler Error:
```output
problem1-2.cpp:11:8: error: 'void Dog::make_snound() const' marked 'override', but does not override
   11 |   void make_snound() const override { std::cout << "Woof!\n"; }
```
As we can see, the override keyword is working, just did not compile due to typo.

Fix typo, check output:
```output
student@cpp-dev:~/workspace/assignments/CSCI330_Lucas_
Field/week05/problem_set_01$ ./problem1-2
Woof!
```

3. Problem 1-3
Create an array of Animals that points to different animals:
Starter Code:
```cpp
Animal* zoo[3] = {
    new Dog(),
    new Animal(),
    // Add a Cat class that meows
};
```
Inserted Cat class:
```cpp
#include <iostream>

struct Animal {
  virtual ~Animal() = default;
  virtual void make_sound() const {
    std::cout << "Some generic animal sound\n";
  }
};

struct Dog : Animal {
  Dog() {}

  void make_sound() const override { std::cout << "Woof!\n"; }

  ~Dog() { std::cout << "Dog Destructor Called!\n"; }
};

struct Cat : Animal {
  Cat() {}

  void make_sound() const override { std::cout << "Meow!\n"; }

  ~Cat() { std::cout << "Cat Destructor Called!\n"; }
};

int main() {
  Animal* zoo[3] = {new Dog(), new Cat(), new Animal()};
  for (int i; i > 3; i++) {
    zoo[i]->make_sound();
  }

  for (int i; i > 3; i++) {
    delete zoo[i];
  }
  return 0;
}
```
No compile errors, but also no output.

Simple mistake, used wromng comparison operator in for loop.
New output:
```cpp
student@cpp-dev:~/workspace/assignments/CSCI330_Lucas_Field/week05/problem_
set_01$ ./problem1-3
Woof!
Meow!
Some generic animal sound
Dog Destructor Called!
Cat Destructor Called!
```
FINAL CODE:
```cpp
#include <iostream>

struct Animal {
  virtual ~Animal() = default;
  virtual void make_sound() const {
    std::cout << "Some generic animal sound\n";
  }
};

struct Dog : Animal {
  Dog() {}

  void make_sound() const override { std::cout << "Woof!\n"; }

  ~Dog() { std::cout << "Dog Destructor Called!\n"; }
};

struct Cat : Animal {
  Cat() {}

  void make_sound() const override { std::cout << "Meow!\n"; }

  ~Cat() { std::cout << "Cat Destructor Called!\n"; }
};

int main() {
  Animal* zoo[3] = {new Dog(), new Cat(), new Animal()};
  std::cout << "Animal Sounds\n";
  for (int i; i < 3; i++) {
    zoo[i]->make_sound();
  }

  for (int i; i < 3; i++) {
    delete zoo[i];
  }
  return 0;
}
```


