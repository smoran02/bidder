# In-Class Activity: The Bidding War

## Overview
Welcome to the CPSC 120A Bidding Tournament!

In this activity, you will implement a C++ class that competes against your classmates' code in a resource allocation game.

### The Game Rules
1.  **The Setup:** There are a specific number of **Rounds** and a total **Budget** of points.
2.  **The Goal:** Win as many rounds as possible.
3.  **Winning a Round:** In each round, the team that bids the highest amount wins **2 points**.
    * If there is a tie, the 2 points are split equally among the winners (e.g., if 2 teams tie, each gets 1 point).
4.  **Constraint:** The total sum of all your bids across all rounds **must not exceed your Budget**.

---

## Your Task

You must edit the file **`bidder.cc`** to implement three functions:

1.  **`GetTeamMembers()`**: Returns a vector of your team's names.
2.  **`GetStrategy()`**: Returns a one-sentence description of your strategy.
3.  **`GenerateBids()`**: The core logic. This function calculates how much to spend per round and writes the bids to a file.

**NOTE: if you use an inappropriate name or strategy, your team will be disqualified.**

### Output
Your output should be a file with your integer bid for each round on a separate line. The total number of lines in the file should be equal to the number of rounds, and the sum of your bids should not exceed the budget.

### Constraints
* You must generate exactly the number of bids requested (matches the number of rounds).
* Your bids must be non-negative integers.
* The sum of your bids must be less than or equal to the budget.

---

## How to Compile and Run

We have provided a `Makefile` to help you compile and test your code.

### 1. Manual Testing
You can write your own testing code inside the `main()` function at the bottom of `bidder.cc`. This `main` function is for **you**. We will not use it during the contest.

To run your manual tests:
```bash
make
./bidder
```
* Use this to experiment. Print out your vector, check your math, etc.

### 2. Automated Testing (The Sanity Check)
Before you submit, you must pass the automated sanity check. This verifies that your file output format is correct and you aren't cheating (spending more than your budget).

To run the sanity check:
```bash
make test
```

* **If you see `[FAILED]`**: Read the error message, fix your code, and try again.
* **If you see `SUCCESS`**: Your code is valid and ready for the tournament. Time to commit and push!

---

## Submission

1.  Make sure `make test` prints **SUCCESS**.
2.  Commit your changes:
    ```bash
    git add bidder.cc
    git commit -m "Implemented bidding logic"
    ```
3.  Push your code:
    ```bash
    git push
    ```
