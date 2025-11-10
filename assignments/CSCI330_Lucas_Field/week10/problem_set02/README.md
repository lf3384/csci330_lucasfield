1. Problem 2-1;
Starter Code:
```cpp
#include <memory>
#include <iostream>
#include <string>
#include <vector>

class Document {
private:
    std::string title;
    std::string content;

public:
    Document(const std::string& t, const std::string& c)
        : title(t), content(c) {
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
    // TODO: Add shared_ptr to Document

public:
    // TODO: Implement constructor
    Editor(const std::string& editor_name, std::shared_ptr<Document> doc);

    // TODO: Implement destructor that announces editor closing
    ~Editor();

    // TODO: Implement edit method
    void edit(const std::string& new_content);

    // TODO: Implement method to show document info and reference count
    void show_info() const;
};

class Viewer {
private:
    std::string name;
    // TODO: Add shared_ptr to Document

public:
    // TODO: Implement constructor
    Viewer(const std::string& viewer_name, std::shared_ptr<Document> doc);

    // TODO: Implement destructor that announces viewer closing
    ~Viewer();

    // TODO: Implement view method
    void view() const;

    // TODO: Implement method to show reference count
    void show_ref_count() const;
};
```
Implemented:
Added ptr class
```cpp
std::shared_ptr<Document> doc;
```
Editor Constructor
```cpp
Editor(const std::string& editor_name, std::shared_ptr<Document> d)
    : name(editor_name), doc(d) {
    std::cout << "Editor '" << name << "' opened" << std::endl;
}
```
Editor Destructor
```cpp
Editor(const std::string& editor_name, std::shared_ptr<Document> d)
    : name(editor_name), doc(d) {
    std::cout << "Editor '" << name << "' opened" << std::endl;
}
```
edit() method
```cpp
void edit(const std::string& new_content) {
    if (doc) {  // Safety check: ensure we have a valid document
        doc->set_content(new_content);
        std::cout << "Editor '" << name << "' edited document to: \""
                  << new_content << "\"" << std::endl;
    }
}
```
show_info() method
```cpp
void show_info() const {
    if (doc) {
        std::cout << "Editor '" << name << "' - Document: '"
                  << doc->get_title() << "', Content: \""
                  << doc->get_content() << "\", Ref count: "
                  << doc.use_count() << std::endl;
    }
}
```
view class shared_ptr
```cpp
std::shared_ptr<Document> doc;
```
Viewer Constructor
```cpp
Viewer(const std::string& viewer_name, std::shared_ptr<Document> d)
    : name(viewer_name), doc(d) {
    std::cout << "Viewer '" << name << "' opened" << std::endl;
}
```
Viewer Destructor
```cpp
~Viewer() {
    std::cout << "Viewer '" << name << "' closed" << std::endl;
}
```
view() method
```cpp
~Viewer() {
    std::cout << "Viewer '" << name << "' closed" << std::endl;
}
```
show_ref() method
```cpp
void show_ref_count() const {
    if (doc) {
        std::cout << "Viewer '" << name << "' - Ref count: "
                  << doc.use_count() << std::endl;
    }
}
```
Output:
```output
student@cpp-dev:~/workspace/assignments/CSCI330_Lucas_Field
/week10/problem_set02$ ./problem2-1
Document 'Report.txt' created

Creating editors and viewers...
Editor 'Alice' opened
Editor 'Bob' opened
Viewer 'Charlie' opened
Editor 'Alice' - Document: 'Report.txt', Content: "Initial content", Ref count: 4
Editor 'Alice' edited document to: "Alice's changes"
Viewer 'Charlie' viewing: "Alice's changes"
Viewer 'Dave' opened
Viewer 'Dave' - Ref count: 5
Viewer 'Dave' closed
Dave's viewer destroyed
Editor 'Bob' - Document: 'Report.txt', Content: "Alice's changes", Ref count: 4
Viewer 'Charlie' closed
Editor 'Bob' closed
Editor 'Alice' closed
All editors and viewers destroyed
Document ref count: 1
Document 'Report.txt' destroyed
```

2. Problem 2-2
Starter Code:
```cpp
#include <memory>
#include <unordered_map>
#include <iostream>
#include <string>

class ExpensiveResource {
private:
    std::string id;
    int creation_cost;

public:
    ExpensiveResource(const std::string& resource_id)
        : id(resource_id), creation_cost(100) {
        std::cout << "Creating expensive resource: " << id
                  << " (cost: " << creation_cost << ")" << std::endl;
    }

    ~ExpensiveResource() {
        std::cout << "Destroying resource: " << id << std::endl;
    }

    const std::string& get_id() const { return id; }
    void use() const {
        std::cout << "Using resource: " << id << std::endl;
    }
};

class ResourceCache {
private:
    // TODO: Add map to store weak_ptr to resources
    std::unordered_map<std::string, std::weak_ptr<ExpensiveResource>> cache;

public:
    // TODO: Implement get_resource method
    std::shared_ptr<ExpensiveResource> get_resource(const std::string& id) {
        // Check if resource exists in cache and is still valid
        // If yes, return shared_ptr to existing resource
        // If no, create new resource, add to cache, and return it
    }

    // TODO: Implement method to show cache status
    void show_cache_status() const {
        std::cout << "Cache contains " << cache.size() << " entries:" << std::endl;
        for (const auto& pair : cache) {
            std::cout << "  " << pair.first << ": "
                      << (pair.second.expired() ? "expired" : "active")
                      << std::endl;
        }
    }

    // TODO: Implement method to clean up expired entries
    void cleanup_expired() {
        // Remove expired weak_ptr entries from cache
    }
};
```
Implemented:
get_resource() method
```cpp
std::shared_ptr<ExpensiveResource> get_resource(const std::string& id) {
    auto it = cache.find(id);

    if (it != cache.end()) {
        auto shared = it->second.lock();
        if (shared) {
            std::cout << "Reusing cached resource: " << id << std::endl;
            return shared;
        }
    }

    auto new_resource = std::make_shared<ExpensiveResource>(id);
    cache[id] = new_resource;
    return new_resource;
}
```
cleanup_expired() method
```cpp
void cleanup_expired() {
    std::cout << "Cleaning up expired entries..." << std::endl;
    auto it = cache.begin();
    while (it != cache.end()) {
        if (it->second.expired()) {
            std::cout << "  Removing expired entry: " << it->first << std::endl;
            it = cache.erase(it);
        } else {
            ++it;
        }
    }
}
```
Output:
```output
student@cpp-dev:~/workspace/assignments/CSCI330_Lucas_Field
/week10/problem_set02$ ./problem2-2
=== Test 1: Creating and sharing resources ===
Creating expensive resource: res1 (cost: 100)
Creating expensive resource: res2 (cost: 100)
Reusing cached resource: res1
resource1 and resource1_again are same object: 1
Using resource: res1
Using resource: res2
Using resource: res1
Cache contains 2 entries:
  res2: active
  res1: active
Destroying resource: res2
Destroying resource: res1

=== Test 2: Resources destroyed, cache cleanup ===
Cache contains 2 entries:
  res2: expired
  res1: expired
Cleaning up expired entries...
  Removing expired entry: res2
  Removing expired entry: res1
Cache contains 0 entries:

=== Test 3: Creating resources after cleanup ===
Creating expensive resource: res1 (cost: 100)
Cache contains 1 entries:
  res1: active
Destroying resource: res1
```
