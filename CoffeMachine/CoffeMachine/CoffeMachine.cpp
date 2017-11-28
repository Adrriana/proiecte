
#include "CoffeMachine.h"
#define TABLE_LENGTH  5


CoffeMachine::CoffeMachine()
{
	stare_tabel[0] = { 0,   5,   1 };
	stare_tabel[1] = { 0,  10,   2 };
	stare_tabel[2] = { 1,   5,   2 };
	stare_tabel[3] = { 1,  10,   3 };
	stare_tabel[4] = { 2,   5,   3 };


}


CoffeMachine::~CoffeMachine()
{
}



void CoffeMachine::transition(int input)
{


	bool strea_gasita = true;
	for (int i = 0; i < TABLE_LENGTH; i++) {
		if (stare_curenta_id == stare_tabel[i].stare_curenta && input == stare_tabel[i].input && strea_gasita)
		{
			std::cout << "State found, transitioning from state: " << " " << stare_curenta_id << " " << "to: " << " " << stare_tabel[i].urmatoarea_stare << "\n";
			stare_curenta_id = stare_tabel[i].urmatoarea_stare;
			strea_gasita = false;
			break;

		}
		if (strea_gasita == false)
			cout << "Not found";
	}




}


