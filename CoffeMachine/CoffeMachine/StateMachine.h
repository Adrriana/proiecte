
#include <vector>
#include <iostream>
#include <map>

using namespace std;

struct Table_Entry
{
	int stare_curenta;
	int input;
	int urmatoarea_stare;
};


class StateMachine
{
protected:

	int stare_curenta_id = 0;
	Table_Entry  *stare_tabel[5];


public:


	virtual void transition(int input) = 0;

	StateMachine();
	~StateMachine();


};

