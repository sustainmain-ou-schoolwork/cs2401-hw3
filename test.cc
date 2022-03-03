#include <iostream>
#include "planner.h"

using namespace std;


int main(int argc, char const *argv[]) {
	Planner p;

	cout << p.due_next() << endl;

	p.~Planner();
	
	cout << p.due_next() << endl;


    return EXIT_SUCCESS;
}