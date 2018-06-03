#include "stdafx.h"
#include <iostream>
#include "State.h"
#include <stdlib.h>
#include <time.h>

State::State()
{

}

State::State(int dim)
{
	n = dim;
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		Queen q(rand() % n, i);
		this->add_queen(q);
	}
}

State::~State()
{

}

int State::get_n()
{
	return n;
}

void State::add_queen(Queen q) {
	if ((int)queens.size() < n) {
		queens.push_back(q);
	}
}


std::vector<State> State::get_successors() {
	std::vector<State> successors;
	int x_before, y_before;
	for (int i = 0; i < n; i++) {
		x_before = queens[i].get_x();
		y_before = queens[i].get_y();
		while (queens[i].walk_up(n) != STOP)
			successors.push_back(*this);
		queens[i].set_x(x_before);
		queens[i].set_y(y_before);
		while (queens[i].walk_down(n) != STOP)
			successors.push_back(*this);
		queens[i].set_x(x_before);
		queens[i].set_y(y_before);
	}
	return successors;
}

/* liczba atakow miedzy hetmanami */
int State::number_of_attacks() {
	// rzedy
	int attacks_in_rows = 0;
	int queens_by_row[10];
	for (int i = 0; i < 10; i++)
		queens_by_row[i] = 0;
	// ukos
	int attacks_in_diag = 0;
	int queens_by_diagonal[2 * 10 - 1], queens_by_diagonal_2[2 * 10 - 1];
	for (int i = 0; i < 2 * 10 - 1; i++) {
		queens_by_diagonal[i] = 0;
		queens_by_diagonal_2[i] = 0;
	}
	// liczba hetmanow
	int x, y;
	for (int i = 0; i < 10; i++) {
		x = queens[i].get_x();
		y = queens[i].get_y();
		++queens_by_row[x]; 
		++queens_by_diagonal[x + y]; 
		++queens_by_diagonal_2[n - 1 + y - x]; 
	}
	for (int i = 0; i < n; i++)
	if (queens_by_row[i] > 1)
		attacks_in_rows += queens_by_row[i] - 1;
	for (int i = 0; i < 2 * n - 1; i++) {
		if (queens_by_diagonal[i] > 1)
			attacks_in_diag += queens_by_diagonal[i] - 1;
		if (queens_by_diagonal_2[i] > 1)
			attacks_in_diag += queens_by_diagonal_2[i] - 1;
	}
	return attacks_in_diag + attacks_in_rows;
}


State State::best_successor() {
	std::vector<State> successors = get_successors();
	int number_of_successors = successors.size();
	std::vector<int> best_successors;
	int min_index; 
	int min_attacks = n*n; 
	int attacks;
	for (int i = 0; i < number_of_successors; i++) {
		attacks = successors[i].number_of_attacks();
		if (attacks < min_attacks) { 
			min_attacks = attacks;
			best_successors.clear(); 
			best_successors.push_back(i); 
		}
		else if (attacks == min_attacks) 
			best_successors.push_back(i); 
	}
	
	srand(time(NULL));
	min_index = rand() % (int)best_successors.size();
	return successors[best_successors[min_index]];
}


void State::print() {
	char board[10][10];
	
	for (int i = 0; i < 10; i++)
	for (int j = 0; j < 10; j++)
		board[i][j] = '0';
	
	for (int i = 0; i < 10; i++)
		board[queens[i].get_x()][queens[i].get_y()] = '1';

	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		std::cout << board[i][j] << (j == n - 1 ? "\n" : " ");
}