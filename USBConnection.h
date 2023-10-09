#ifndef USBCONNECTION_H
#define USBCONNECTION_H

class USBConnection {
 private:
  int ID;
  USBConnection(int id) : ID(id) {}

 public:
  static std::stack<int> ids;

  static USBConnection* CreateUsbConnection() {
    if (!ids.empty()) {
      int id = ids.top();
      ids.pop();
      return new USBConnection(id);
    }
    return nullptr;
  }

  ~USBConnection() { ids.push(ID); }

  int get_id() { return ID; }
};

std::stack<int> USBConnection::ids({3, 2, 1});

#endif