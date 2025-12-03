CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

bidder: bidder.cc
	$(CXX) $(CXXFLAGS) bidder.cc -o bidder

test: test_driver.cc
	$(CXX) $(CXXFLAGS) test_driver.cc -o test_runner
	./test_runner

clean:
	rm -f bidder test_runner *.txt
