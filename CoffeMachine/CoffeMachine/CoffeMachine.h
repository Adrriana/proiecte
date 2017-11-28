
#include "StateMachine.h"
#include <iostream>

using namespace std;

class CoffeMachine :public StateMachine
{
protected:

	int stare_curenta_id = 0;
	Table_Entry stare_tabel[5];

public:


	CoffeMachine();
	~CoffeMachine();



	void transition(int input);

};

