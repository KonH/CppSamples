#include <iostream>
#include <string>
#include <variant>

#include "samples.h"

using namespace std;

typedef variant<int, string> func_return;

func_return var_func(int x) {
	if (x >= 0) {
		return x;
	}
	return "wrong argument";
}

void check_func(int x) {
	auto result = var_func(x);
	if (holds_alternative<int>(result)) {
		cout << "Result: " << get<int>(result) << endl;
	}
	if (holds_alternative<string>(result)) {
		cout << "Error: " << get<string>(result) << endl;
	}
}

void variant_sample() {
	check_func(1);
	check_func(-1);
}
