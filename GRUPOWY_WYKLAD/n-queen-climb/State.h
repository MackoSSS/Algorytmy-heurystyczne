#ifndef STATE_H
#define STATE_H

#include "Queen.h"
#include <vector>

class State
{
public:
	State();
	State(int);
	virtual ~State();
	std::vector<Queen> get_queens();
	void add_queen(Queen);
	std::vector<State> get_successors();
	State best_successor();
	int number_of_attacks();
	int get_n();
	void print();
protected:
private:
	std::vector<Queen> queens;
	int n;
};

#endif