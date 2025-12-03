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

const std::string kGreen = "\033[32m";
const std::string kRed = "\033[31m";
const std::string kReset = "\033[0m";

void Assert(bool condition, const std::string& message) {
  if (condition) {
    std::cout << kGreen << "[PASSED]" << kReset << " " << message << "\n";
  } else {
    std::cout << kRed << "[FAILED]" << kReset << " " << message << "\n";
    std::exit(1);
  }
}

int main() {
  const int kRounds = 10;
  const int kBudget = 100;
  const std::string kFilename = "test_results.txt";

  std::cout << "================================================\n";
  std::cout << "RUNNING AUTOMATED SANITY CHECK\n";
  std::cout << "================================================\n";

  std::remove(kFilename.c_str());

  std::cout << "Calling GenerateBids(" << kRounds << ", " << kBudget << ")..." << "\n";
  GenerateBids(kRounds, kBudget, kFilename);

  std::ifstream infile(kFilename);
  bool file_exists = infile.good();

  if (file_exists) {
      std::cout << kGreen << "[PASSED]" << kReset << " Output file '" << kFilename << "' was created.\n";
  } else {
      std::cout << kRed << "[FAILED]" << kReset << " Output file '" << kFilename << "' was NOT created.\n";
      std::cout << "         Did you forget to use the 'output_filename' parameter?\n";
      std::exit(1);
  }

  int bid_val;
  std::vector<int> bids;
  while (infile >> bid_val) {
    bids.push_back(bid_val);
  }
  infile.close();

  std::cout << "\n--- Your Generated Bids ---\n";
  std::cout << "[ ";
  for (size_t i = 0; i < bids.size(); ++i) {
      std::cout << bids[i] << (i < bids.size() - 1 ? ", " : " ");
  }
  std::cout << "]\n";

  std::cout << "\n--- Verifying Logic ---\n";

  std::cout << "Rounds: Generated " << bids.size() << " bids (Expected " << kRounds << ").\n";
  Assert(bids.size() == kRounds, "Round count is correct.");

  long total_spent = 0;
  bool non_negative = true;
  for (int bid : bids) {
    if (bid < 0) non_negative = false;
    total_spent += bid;
  }

  if (!non_negative) {
      std::cout << kRed << "[FAILED]" << kReset << " Found negative bids! You cannot bid less than 0.\n";
      std::exit(1);
  } else {
      std::cout << kGreen << "[PASSED]" << kReset << " All bids are non-negative.\n";
  }

  std::cout << "Budget: Spent " << total_spent << " points (Budget " << kBudget << ").\n";
  if (total_spent <= kBudget) {
      std::cout << kGreen << "[PASSED]" << kReset << " Total spent is within budget.\n";
  } else {
      std::cout << kRed << "[FAILED]" << kReset << " You overspent by " << (total_spent - kBudget) << " points!\n";
      std::exit(1);
  }

  std::cout << "\n" << kGreen << "SUCCESS: Your code looks valid. Ready to submit." << kReset << "\n";

  std::remove(kFilename.c_str());
  return 0;
}