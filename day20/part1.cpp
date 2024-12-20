#include <bits/stdc++.h>
using namespace std;

struct Position {
    int x, y;
    bool operator==(const Position& other) const {
        return x == other.x && y == other.y;
    }
};

int main() {
    vector<string> grid;
    string line;
    while (getline(cin, line)) {
        if (!line.empty()) {
            grid.push_back(line);
        }
    }

    int height = grid.size();
    int width = grid[0].size();

    Position startPos{0, 0}, endPos{0, 0};
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (grid[y][x] == 'S') {
                startPos = {x, y};
            } else if (grid[y][x] == 'E') {
                endPos = {x, y};
            }
        }
    }

    vector<Position> pathPositions;
    set<pair<int, int>> visited;
    queue<Position> q;
    q.push(startPos);

    while (!q.empty()) {
        Position current = q.front();
        q.pop();
        pathPositions.push_back(current);

        if (current == endPos) {
            break;
        }

        visited.insert({current.x, current.y});

        vector<pair<int, int>> neighbors;
        const int dx[] = {-1, 1, 0, 0};
        const int dy[] = {0, 0, -1, 1};
        
        for (int i = 0; i < 4; i++) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];
            if (newX >= 0 && newX < width && newY >= 0 && newY < height &&
                grid[newY][newX] != '#' && !visited.count({newX, newY})) {
                neighbors.push_back({newX, newY});
            }
        }

        if (!neighbors.empty()) {
            q.push({neighbors[0].first, neighbors[0].second});
        }
    }

    int skips = 0;
    map<int, int> savedArr;

    for (size_t firstPos = 0; firstPos < pathPositions.size() - 1; firstPos++) {
        for (size_t secondPos = firstPos + 1; secondPos < pathPositions.size(); secondPos++) {
            int savedBySkipping = secondPos - firstPos;

            if (pathPositions[firstPos].x == pathPositions[secondPos].x ||
                pathPositions[firstPos].y == pathPositions[secondPos].y) {
                int xDiff = abs(pathPositions[firstPos].x - pathPositions[secondPos].x);
                int yDiff = abs(pathPositions[firstPos].y - pathPositions[secondPos].y);

                if (xDiff + yDiff <= 2) {
                    int saved = savedBySkipping - (xDiff + yDiff);
                    savedArr[saved]++;
                    if (saved >= 100) {
                        skips++;
                    }
                }
            }
        }
    }

    cout << skips << endl;
    return 0;
}