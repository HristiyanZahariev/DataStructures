#include <iostream>
#include <cmath>
#include <string.h>
#include <stack>

using namespace std;

string getFinalMove(size_t n) {
	std::string finalMove;
	finalMove.resize(2 * n + 1);

	for (unsigned int i = 0; i < 2 * n + 1; i++) {
		if (i < n) {
			finalMove[i] = '<';
		}
		else if (i == n) {
			finalMove[i] = '_';
		}
		else {
			finalMove[i] = '>';
		}
	}
	return finalMove;
}

string createStart(size_t n) {
	string data;
	data.resize(2 * n + 1);
	for (unsigned int i = 0; i < 2 * n + 1; i++) {
		if (i < n) {
			data[i] = '>';
		}
		else if (i == n) {
			data[i] = '_';
		}
		else {
			data[i] = '<';
		}
	}
	return data;
}

void makeMoves(stack<string>& container, string& currentPlace) {
	size_t index = currentPlace.find('_');
	string copy = currentPlace;

	if (((index + 1) <= (currentPlace.size() - 1)) && (copy[index + 1] == '<')) {
		swap(copy[index], copy[index + 1]);
		container.push(copy);
	}

	if ((index - 1 >= 0) && (copy[index - 1] == '>')) {
		swap(copy[index], copy[index - 1]);
		container.push(copy);
	}

	if (((index + 2) <= (currentPlace.size() - 1)) && (copy[index + 2] == '<')) {
		swap(copy[index], copy[index + 2]);
		container.push(copy);
		return;
	}

	if ((index - 2 >= 0) && (copy[index - 2] == '>')) {
		swap(copy[index], copy[index - 2]);
		container.push(copy);
		return;
	}
}


void solve(std::stack<std::string>& container, std::string& start) {
	if (start == getFinalMove(start.size() / 2)) {
		container = stack<string>();
		return;
	}


	makeMoves(container, start);

	while (!container.empty()) {
		string current = container.top();
		cout << current.c_str() << endl;
		container.pop();
		solve(container, current);
	}
}

int main() {
	stack<string> steck;
	string start = createStart(2);
	cout << start << endl;
	solve(steck, start);
}

