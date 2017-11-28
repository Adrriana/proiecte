
#include "CoffeMachine.h"
#include "StateMachine.h"
#include <iostream>


using namespace std;

int main() {

	CoffeMachine x;
	x.transition(5);
	x.transition(5);
	x.transition(5);

	CoffeMachine y;
	y.transition(10);
	y.transition(10);
	y.transition(10);




	_getch();
}