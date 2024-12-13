#include <bits/stdc++.h>

struct File {
  int id;
  int size;
  int startPos;
  int endPos;
};

int main() {
  std::string s;
  std::cin >> s;

  std::vector<File> files;
  int fileId = 0;
  int pos = 0;

  for (size_t i = 0; i < s.length(); i++) {
    int len = s[i] - '0';
    if (i % 2 == 0) {
      files.push_back({fileId++, len, pos, pos + len - 1});
      pos += len;
    } else {
      pos += len;
    }
  }

  std::vector<int> blocks(pos, -1);
  for (const auto &file : files) {
    for (int i = file.startPos; i <= file.endPos; i++) {
      blocks[i] = file.id;
    }
  }

  for (int fileId = files.size() - 1; fileId >= 0; fileId--) {
    auto file =
        std::find_if(files.begin(), files.end(),
                     [fileId](const File &f) { return f.id == fileId; });
    int fileSize = file->endPos - file->startPos + 1;

    int bestPos = -1;
    int currentRunStart = -1;
    int currentRunLength = 0;

    for (int i = 0; i < file->startPos; i++) {
      if (blocks[i] == -1) {
        if (currentRunStart == -1)
          currentRunStart = i;
        currentRunLength++;
        if (currentRunLength >= fileSize) {
          bestPos = currentRunStart;
          break;
        }
      } else {
        currentRunStart = -1;
        currentRunLength = 0;
      }
    }

    if (bestPos != -1) {
      std::vector<int> fileBlocks(blocks.begin() + file->startPos,
                                  blocks.begin() + file->endPos + 1);
      for (int i = file->startPos; i <= file->endPos; i++) {
        blocks[i] = -1;
      }
      for (int i = 0; i < fileSize; i++) {
        blocks[bestPos + i] = fileBlocks[i];
      }
    }
  }

  long long checksum = 0;
  for (size_t i = 0; i < blocks.size(); i++) {
    if (blocks[i] != -1) {
      checksum += (long long)i * blocks[i];
    }
  }

  std::cout << checksum << std::endl;
  return 0;
}