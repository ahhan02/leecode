#include <iostream>
#include <string>
using namespace std;

bool isLongPressedName(string name, string typed) {
  int i = 0, j = 0;
  while (i < name.size() && j < typed.size()) {
    if (i != name.size()-1 && name[i] == name[i+1]) {
      if (typed[j] == name[i]) {
        // cout << "1: name[i]: " << name[i] << " typed[j]: " << typed[j] << endl;
        ++j;
      }
    } else {
      if (typed[j] != name[i]) {
        break;
      }

      while (typed[j] == name[i]) {
        // cout << "2: name[i]: " << name[i] << " typed[j]: " << typed[j] << endl;
        ++j;
      }
    }

    ++i;
  }

  // cout << "i: " << i << " j: " << j << endl;

  if (i == name.size() && j == typed.size()) {
    return true;
  }

  return false;
}

int main() {
  string name, typed;
  // cin >> name >> typed;
  getline(cin, name);
  getline(cin, typed);
  cout << isLongPressedName(name, typed) << endl;
  return 0;
}
