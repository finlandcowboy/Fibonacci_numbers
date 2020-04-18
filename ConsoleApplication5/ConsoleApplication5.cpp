#include "pch.h"
#include <iostream>
#include <cassert>
#include <unordered_map>
#include <vector>
#include <ctime>


class Fibonacci final {
public:
	static int get(int n) {
		assert(n >= 0);
		if (n == 0 || n == 1) {
			return n;
		}

		static std::unordered_map<int, int> cache;
		auto &result = cache[n];

		if (result == 0) {
			return get(n - 2) + get(n - 1);
		}
		return result;
	}
};

class Fibonacci2 final {
public:
	static int get(int n) {
		assert(n >= 0);
		static std::unordered_map<int, int> cache;
		cache[0] = 0;
		cache[1] = 1;
		for (int i = 2; i <= n; i++) {
			
			cache[i] = cache[i - 2] + cache[i - 1];
		}
		return cache[n];
	}
};

class Fibonacci3 final {
public:
	
	static int get(int n) {
		assert(n >= 0);
		static std::vector<int> cache;
		cache.resize(n + 1);
		cache[1] = 1;
		for (int i = 2; i <= n; i++) {

			cache[i] = cache[i - 2] + cache[i - 1];
		}
		return cache[n];
	}
};

class Fibonacci4 final {
public:
	static int get(int n) {
		assert(n >= 0);
		if (n <= 1) {
			return n;
		}
		int previous = 0;
		int current = 1;
		for (int i = 2; i <= n; i++) {
			int new_current = previous + current;
			previous = current;
			current = new_current;
		}
		return current;
	}
};

int main(int argc, char** argv) {

	int n;
	std::cin >> n;
	std::cout << Fibonacci4::get(n) << std::endl;
	unsigned int start = clock();
	std::cout << start / 1000;
	return 0;
}