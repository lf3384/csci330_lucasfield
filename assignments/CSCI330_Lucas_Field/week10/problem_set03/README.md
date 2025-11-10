1. Problem 3-1
Starter Code
```cpp
#include <memory>
#include <vector>
#include <iostream>
#include <string>

// PROBLEMATIC VERSION - Creates circular references!
struct TreeNode {
    std::string data;
    std::shared_ptr<TreeNode> parent;  // Problem: creates cycle!
    std::vector<std::shared_ptr<TreeNode>> children;

    TreeNode(const std::string& value) : data(value) {
        std::cout << "TreeNode '" << data << "' created" << std::endl;
    }

    ~TreeNode() {
        std::cout << "TreeNode '" << data << "' destroyed" << std::endl;
    }

    void add_child(std::shared_ptr<TreeNode> child) {
        child->parent = shared_from_this();  // Creates circular reference!
        children.push_back(child);
    }

    void show_family() const {
        if (parent) {
            std::cout << data << "'s parent: " << parent->data << std::endl;
        } else {
            std::cout << data << " is root" << std::endl;
        }

        std::cout << data << "'s children: ";
        for (const auto& child : children) {
            std::cout << child->data << " ";
        }
        std::cout << std::endl;
    }
};
```
Fixes:
Added inheritance
```cpp
struct TreeNode : std::enable_shared_from_this<TreeNode>
```
Change from shared_ptr to weak_ptr
```cpp
std::weak_ptr<TreeNode> parent;
```
Change show_family() to lock the weak_ptr
```cpp
auto parent_ptr = parent.lock();
if (parent_ptr) {
    std::cout << data << "'s parent: " << parent_ptr->data << std::endl;
}
```
Output
```output
student@cpp-dev:~/workspace/assignments/CSCI330_Lucas_Field
/week10/problem_set03$ ./problem3-1
=== Creating tree structure ===
TreeNode 'Root' created
TreeNode 'Child1' created
TreeNode 'Child2' created
TreeNode 'Grandchild' created
Root is root
Root's children: Child1 Child2
Child1's parent: Root
Child1's children: Grandchild
Grandchild's parent: Child1
Grandchild's children:

=== Testing parent access ===
Grandchild's parent is: Child1
TreeNode 'Root' destroyed
TreeNode 'Child1' destroyed
TreeNode 'Grandchild' destroyed
TreeNode 'Child2' destroyed
=== All nodes should be destroyed here ===
```
2. Problem 3-2
Starter Code
```cpp
#include <memory>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>
#include <algorithm>

class MediaFile {
private:
    std::string filename;
    size_t file_size;

public:
    MediaFile(const std::string& name, size_t size)
        : filename(name), file_size(size) {
        std::cout << "Loaded media file: " << filename
                  << " (" << file_size << " bytes)" << std::endl;
    }

    ~MediaFile() {
        std::cout << "Unloaded media file: " << filename << std::endl;
    }

    const std::string& get_filename() const { return filename; }
    size_t get_size() const { return file_size; }

    void play() const {
        std::cout << "Playing: " << filename << std::endl;
    }
};

class Playlist {
private:
    std::string name;
    std::vector<std::shared_ptr<MediaFile>> files;

public:
    Playlist(const std::string& playlist_name) : name(playlist_name) {
        std::cout << "Created playlist: " << name << std::endl;
    }

    ~Playlist() {
        std::cout << "Destroyed playlist: " << name << std::endl;
    }

    void add_file(std::shared_ptr<MediaFile> file) {
        files.push_back(file);
        std::cout << "Added " << file->get_filename() << " to " << name << std::endl;
    }

    void play_all() const {
        std::cout << "Playing playlist: " << name << std::endl;
        for (const auto& file : files) {
            file->play();
        }
    }

    const std::string& get_name() const { return name; }
    size_t get_file_count() const { return files.size(); }
};

class MediaLibrary {
private:
    // TODO: Use unordered_map with string keys and shared_ptr<MediaFile> values
    std::unordered_map<std::string, std::shared_ptr<MediaFile>> media_files;

    // TODO: Use vector of unique_ptr<Playlist>
    std::vector<std::unique_ptr<Playlist>> playlists;

public:
    // TODO: Implement load_media_file
    std::shared_ptr<MediaFile> load_media_file(const std::string& filename, size_t size) {
        // If file already exists, return existing shared_ptr
        // Otherwise, create new MediaFile and store in map
    }

    // TODO: Implement create_playlist
    std::unique_ptr<Playlist> create_playlist(const std::string& name) {
        // Create new playlist and return unique_ptr
        // Note: Don't store in library - let caller manage
    }

    // TODO: Implement add_playlist_to_library
    void add_playlist_to_library(std::unique_ptr<Playlist> playlist) {
        // Move the playlist into the library's storage
    }

    // TODO: Implement get_media_file
    std::shared_ptr<MediaFile> get_media_file(const std::string& filename) {
        // Return shared_ptr to existing file, or nullptr if not found
    }

    // TODO: Implement show_library_status
    void show_library_status() const {
        std::cout << "\n=== Media Library Status ===" << std::endl;
        std::cout << "Media files: " << media_files.size() << std::endl;
        for (const auto& pair : media_files) {
            std::cout << "  " << pair.first << " (refs: "
                      << pair.second.use_count() << ")" << std::endl;
        }

        std::cout << "Playlists: " << playlists.size() << std::endl;
        for (const auto& playlist : playlists) {
            std::cout << "  " << playlist->get_name()
                      << " (" << playlist->get_file_count() << " files)" << std::endl;
        }
    }
};

class NowPlayingTracker {
private:
    // TODO: Use weak_ptr to avoid keeping media files alive unnecessarily
    std::weak_ptr<MediaFile> current_track;

public:
    // TODO: Implement set_current_track
    void set_current_track(std::shared_ptr<MediaFile> track) {
        // Store weak reference to current track
    }

    // TODO: Implement show_current_track
    void show_current_track() const {
        // Use lock() to safely access current track
        // Handle case where track might have been destroyed
    }
};
```
Implemented:
load_media_file():
```cpp
std::shared_ptr<MediaFile> load_media_file(const std::string& filename, size_t size) {
    auto it = media_files.find(filename);
    if (it != media_files.end()) {
        std::cout << "File already loaded: " << filename << std::endl;
        return it->second;
    }

    auto new_file = std::make_shared<MediaFile>(filename, size);
    media_files[filename] = new_file;
    return new_file;
}
```
create_playlist():
```cpp
std::unique_ptr<Playlist> create_playlist(const std::string& name) {
    return std::make_unique<Playlist>(name);
}
```
add_playlist_to_library():
```cpp
void add_playlist_to_library(std::unique_ptr<Playlist> playlist) {
    playlists.push_back(std::move(playlist));
}
```
get_media_file():
```cpp
std::shared_ptr<MediaFile> get_media_file(const std::string& filename) {
    auto it = media_files.find(filename);
    if (it != media_files.end()) {
        return it->second;
    }
    return nullptr;
}
```
set_current_track():
```cpp
void set_current_track(std::shared_ptr<MediaFile> track) {
    current_track = track;
    std::cout << "Now playing tracker set to: " << track->get_filename() << std::endl;
}
```
show_current_track():
```cpp
void show_current_track() const {
    auto track = current_track.lock();
    if (track) {
        std::cout << "Currently playing: " << track->get_filename() << std::endl;
    } else {
        std::cout << "No track currently playing (or track was destroyed)" << std::endl;
    }
}
```
Output
```output
student@cpp-dev:~/workspace/assignments/CSCI330_Lucas_Field
/week10/problem_set03$ ./problem3-2
=== Loading media files ===
Loaded media file: song1.mp3 (4000000 bytes)
Loaded media file: song2.mp3 (3500000 bytes)
Loaded media file: song3.mp3 (4200000 bytes)

=== Creating playlists ===
Created playlist: Rock Hits
Created playlist: Chill Vibes
Added song1.mp3 to Rock Hits
Added song3.mp3 to Rock Hits
Added song2.mp3 to Chill Vibes
Added song1.mp3 to Chill Vibes

=== Media Library Status ===
Media files: 3
  song3.mp3 (refs: 3)
  song2.mp3 (refs: 3)
  song1.mp3 (refs: 4)
Playlists: 2
  Rock Hits (2 files)
  Chill Vibes (2 files)

=== Testing now playing tracker ===
Now playing tracker set to: song2.mp3
Currently playing: song2.mp3

=== Removing local references ===

=== Media Library Status ===
Media files: 3
  song3.mp3 (refs: 2)
  song2.mp3 (refs: 2)
  song1.mp3 (refs: 3)
Playlists: 2
  Rock Hits (2 files)
  Chill Vibes (2 files)
Currently playing: song2.mp3
Destroyed playlist: Rock Hits
Destroyed playlist: Chill Vibes
Unloaded media file: song3.mp3
Unloaded media file: song2.mp3
```