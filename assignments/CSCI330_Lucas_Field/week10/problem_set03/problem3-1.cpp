#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct TreeNode : std::enable_shared_from_this<TreeNode> {
  std::string data;
  std::weak_ptr<TreeNode> parent;
  std::vector<std::shared_ptr<TreeNode>> children;

  TreeNode(const std::string& value) : data(value) {
    std::cout << "TreeNode '" << data << "' created" << std::endl;
  }

  ~TreeNode() {
    std::cout << "TreeNode '" << data << "' destroyed" << std::endl;
  }

  void add_child(std::shared_ptr<TreeNode> child) {
    child->parent = shared_from_this();
    children.push_back(child);
  }

  void show_family() const {
    auto parent_ptr = parent.lock();
    if (parent_ptr) {
      std::cout << data << "'s parent: " << parent_ptr->data << std::endl;
    } else {
      std::cout << data << " is root" << std::endl;
    }

    std::cout << data << "'s children: ";
    for (const auto& child : children) {
      std::cout << child->data << " ";
    }
    std::cout << std::endl;
  }

  std::shared_ptr<TreeNode> get_parent() { return parent.lock(); }
};

int main() {
  std::cout << "=== Creating tree structure ===\n";
  {
    auto root = std::make_shared<TreeNode>("Root");
    auto child1 = std::make_shared<TreeNode>("Child1");
    auto child2 = std::make_shared<TreeNode>("Child2");
    auto grandchild = std::make_shared<TreeNode>("Grandchild");

    root->add_child(child1);
    root->add_child(child2);
    child1->add_child(grandchild);

    root->show_family();
    child1->show_family();
    grandchild->show_family();

    std::cout << "\n=== Testing parent access ===\n";
    if (auto parent = grandchild->get_parent()) {
      std::cout << "Grandchild's parent is: " << parent->data << std::endl;
    }
  }
  std::cout << "=== All nodes should be destroyed here ===\n";

  return 0;
}