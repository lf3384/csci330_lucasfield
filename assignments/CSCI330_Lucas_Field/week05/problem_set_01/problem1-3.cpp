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
