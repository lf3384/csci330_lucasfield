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