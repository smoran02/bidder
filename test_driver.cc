#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

#define main student_main
#include "bidder.cc"
#undef main

void Assert(bool condition, const std::string& message) {
  if (condition) {
    std::cout << "[PASSED] " << message << std::endl;
  } else {
    std::cout << "[FAILED] " << message << std::endl;
    std::exit(1);
  }
}

int main() {
  const int kRounds = 20;
  const int kBudget = 1000;
  const std::string kFilename = "test_results.txt";

  std::cout << "Running Automated Sanity Check..." << std::endl;

  std::remove(kFilename.c_str());

  GenerateBids(kRounds, kBudget, kFilename);

  std::ifstream infile(kFilename);
  Assert(infile.good(), "Output file created.");

  int bid_val;
  std::vector<int> bids;
  while (infile >> bid_val) {
    bids.push_back(bid_val);
  }
  infile.close();

  Assert(bids.size() == kRounds, "Correct number of rounds.");

  long total_spent = 0;
  bool non_negative = true;
  for (int bid : bids) {
    if (bid < 0) non_negative = false;
    total_spent += bid;
  }

  Assert(non_negative, "Bids are non-negative.");
  Assert(total_spent <= kBudget, "Total spent is within budget.");

  std::cout << "\nSUCCESS: Ready to submit.\n";
  std::remove(kFilename.c_str());

  return 0;
}
