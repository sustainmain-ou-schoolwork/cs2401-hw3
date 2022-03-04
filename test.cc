#include <iostream>
#include "planner.h"
#include "assignment.h"

using namespace std;


int main(int argc, char const *argv[]) {
	Planner p;

	cout << p.due_next() << endl;

	p.~Planner();
	
	cout << p.due_next() << endl;

	Assignment a, b, c;
	cin >> a;
	cin >> b;

	p.add(a);
	p.add(b);
	p.add(c);
	p.display(cout);

    return EXIT_SUCCESS;
}