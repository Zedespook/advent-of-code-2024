#include <chrono>
#include <iostream>
#include <vector>

using namespace std;

long long mix(long long secret, long long value) { return secret ^ value; }

long long prune(long long secret) { return secret % 16777216; }

long long nextSecret(long long secret) {
  secret = mix(secret, secret * 64);
  secret = prune(secret);
  secret = mix(secret, secret / 32);
  secret = prune(secret);
  secret = mix(secret, secret * 2048);
  secret = prune(secret);
  return secret;
}

int getPrice(long long secret) { return secret % 10; }

int main() {
  vector<long long> initialSecrets;
  long long secret;
  while (cin >> secret) {
    initialSecrets.push_back(secret);
  }

  vector<vector<int>> allChanges(initialSecrets.size());
  vector<vector<int>> allPrices(initialSecrets.size());
  for (size_t b = 0; b < initialSecrets.size(); ++b) {
    long long currentSecret = initialSecrets[b];
    allPrices[b].push_back(getPrice(currentSecret));
    for (int i = 0; i < 2000; ++i) {
      currentSecret = nextSecret(currentSecret);
      allPrices[b].push_back(getPrice(currentSecret));
      allChanges[b].push_back(allPrices[b].back() -
                              allPrices[b][allPrices[b].size() - 2]);
    }
  }

  long long maxBananas = 0;
  long long totalIterations = 19LL * 19 * 19 * 19;
  long long currentIteration = 0;
  auto startTime = chrono::high_resolution_clock::now();

  for (int d1 = -9; d1 <= 9; ++d1) {
    for (int d2 = -9; d2 <= 9; ++d2) {
      for (int d3 = -9; d3 <= 9; ++d3) {
        for (int d4 = -9; d4 <= 9; ++d4) {
          long long totalBananas = 0;
          for (size_t b = 0; b < initialSecrets.size(); ++b) {
            int salePrice = 0;
            for (size_t i = 0; i < allChanges[b].size() - 3; ++i) {
              if (allChanges[b][i] == d1 && allChanges[b][i + 1] == d2 &&
                  allChanges[b][i + 2] == d3 && allChanges[b][i + 3] == d4) {
                salePrice = allPrices[b][i + 4];
                break;
              }
            }
            totalBananas += salePrice;
          }
          maxBananas = max(maxBananas, totalBananas);

          currentIteration++;
          if (currentIteration % 1000 == 0) {
            auto currentTime = chrono::high_resolution_clock::now();
            auto elapsed = chrono::duration_cast<chrono::milliseconds>(
                               currentTime - startTime)
                               .count();
            double progress = (double)currentIteration / totalIterations;
            double estimatedTotalTime = (double)elapsed / progress;
            double estimatedTimeRemaining = estimatedTotalTime - elapsed;
            cout << "Progress: " << (progress * 100)
                 << "%, Estimated time remaining: "
                 << (estimatedTimeRemaining / 1000) << " seconds\r";
            cout.flush();
          }
        }
      }
    }
  }

  cout << "                                                                    "
          "            \r";
  cout << "Max Bananas: " << maxBananas << endl;

  return 0;
}