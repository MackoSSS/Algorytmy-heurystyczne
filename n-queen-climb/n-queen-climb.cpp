// n-queen-climb.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Queen.h"
#include "State.h"


using namespace std;


State Hillclimb(State current) {
	State next;
	int iteration = 1; 
	while (true) { 
		next = current.best_successor();
		if (current.number_of_attacks() <= next.number_of_attacks()) {
			return current;
		}
		current = next;
		++iteration;
	}
	return State(-1);
}

int main() {
	int dim;
	cout << "Choose the board's dimension: ";
	cin >> dim;
	State initial_state(dim);
	State solution = Hillclimb(initial_state);
	while (solution.number_of_attacks() > 0) {
		State initial_state(dim);
		solution = Hillclimb(initial_state);
	}
	cout << "\nSolution:\n" << endl;
	if (solution.get_n() == -1)
		cout << "Error" << endl;
	else {
		solution.print();
	}

	system("pause");
	return 0;
}

