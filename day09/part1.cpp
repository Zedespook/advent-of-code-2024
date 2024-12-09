#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;

  vector<int> blocks;
  int fileId = 0;

  for (int i = 0; i < s.length(); i++) {
    int len = s[i] - '0';
    if (i % 2 == 0) {
      for (int j = 0; j < len; j++) {
        blocks.push_back(fileId);
      }
      fileId++;
    } else {
      for (int j = 0; j < len; j++) {
        blocks.push_back(-1);
      }
    }
  }

  while (true) {
    int right = blocks.size() - 1;
    while (right >= 0 && blocks[right] == -1) {
      right--;
    }
    if (right < 0)
      break;

    int left = 0;
    while (left < blocks.size() && blocks[left] != -1) {
      left++;
    }
    if (left >= right)
      break;

    blocks[left] = blocks[right];
    blocks[right] = -1;
  }

  long long checksum = 0;
  for (int i = 0; i < blocks.size(); i++) {
    if (blocks[i] != -1) {
      checksum += (long long)i * blocks[i];
    }
  }

  cout << checksum << '\n';
  return 0;
}