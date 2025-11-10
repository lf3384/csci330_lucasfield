#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Document {
 private:
  std::string title;
  std::string content;

 public:
  Document(const std::string& t, const std::string& c) : title(t), content(c) {
    std::cout << "Document '" << title << "' created" << std::endl;
  }

  ~Document() {
    std::cout << "Document '" << title << "' destroyed" << std::endl;
  }

  const std::string& get_title() const { return title; }
  const std::string& get_content() const { return content; }
  void set_content(const std::string& new_content) { content = new_content; }
};

class Editor {
 private:
  std::string name;
  std::shared_ptr<Document> doc;

 public:
  Editor(const std::string& editor_name, std::shared_ptr<Document> d)
      : name(editor_name), doc(d) {
    std::cout << "Editor '" << name << "' opened" << std::endl;
  }

  ~Editor() { std::cout << "Editor '" << name << "' closed" << std::endl; }

  void edit(const std::string& new_content) {
    if (doc) {
      doc->set_content(new_content);
      std::cout << "Editor '" << name << "' edited document to: \""
                << new_content << "\"" << std::endl;
    }
  }

  void show_info() const {
    if (doc) {
      std::cout << "Editor '" << name << "' - Document: '" << doc->get_title()
                << "', Content: \"" << doc->get_content()
                << "\", Ref count: " << doc.use_count() << std::endl;
    }
  }
};

class Viewer {
 private:
  std::string name;
  std::shared_ptr<Document> doc;

 public:
  Viewer(const std::string& viewer_name, std::shared_ptr<Document> d)
      : name(viewer_name), doc(d) {
    std::cout << "Viewer '" << name << "' opened" << std::endl;
  }

  ~Viewer() { std::cout << "Viewer '" << name << "' closed" << std::endl; }

  void view() const {
    if (doc) {
      std::cout << "Viewer '" << name << "' viewing: \"" << doc->get_content()
                << "\"" << std::endl;
    }
  }

  void show_ref_count() const {
    if (doc) {
      std::cout << "Viewer '" << name << "' - Ref count: " << doc.use_count()
                << std::endl;
    }
  }
};

int main() {
  auto document = std::make_shared<Document>("Report.txt", "Initial content");

  std::cout << "\nCreating editors and viewers...\n";
  {
    Editor editor1("Alice", document);
    Editor editor2("Bob", document);
    Viewer viewer1("Charlie", document);

    editor1.show_info();

    editor1.edit("Alice's changes");
    viewer1.view();

    {
      Viewer viewer2("Dave", document);
      viewer2.show_ref_count();
      std::cout << "Dave's viewer destroyed\n";

      editor2.show_info();
    }
    std::cout << "All editors and viewers destroyed\n";

    std::cout << "Document ref count: " << document.use_count() << std::endl;

    return 0;
  }
}  // Document should be destroyed here