#ifndef QUEEN_H
#define QUEEN_H

#define STOP 0
#define GO_ON 1

class Queen
{
public:
	Queen(int, int);
	virtual ~Queen();
	int get_x();
	int get_y();
	void set_x(int);
	void set_y(int);
	int walk_up(int); // one step up on the board
	int walk_down(int); // one step down on the board
protected:
private:
	int x;
	int y;
};

#endif