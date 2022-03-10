#include <iostream>
#include "planner.h"
#include "assignment.h"

using namespace std;


/**
 * @brief Print a message and wait for the user to press enter.
 * 
 * @param msg message to print
 */
void pause(const string& msg = "");

/**
 * @brief Clears out any newline characters at the beginning of the stream
 * 
 * @param ins the stream to be cleared of newlines
 */
void clearNewlines(istream& ins);

/**
 * @brief Run a test on a Planner.
 * 
 * @param p the Planner to run tests on
 * @param testnum the number of the test to run
 */
void test(Planner& p, int testNum);


int main(int argc, char const *argv[]) {
	if (argc > 1) {
		const int TEST_NUM = atoi(argv[1]);
		Planner p;

		cout << "===== TEST #" << TEST_NUM << " =====" << endl;
		test(p, TEST_NUM);


		return EXIT_SUCCESS;
	}
	else {
		cout << "Include the test number as the second parameter." << endl;
		return EXIT_FAILURE;
	}
}


void pause(const string& msg) {
	string x;
	cout << msg;
	getline(cin, x);
}

void clearNewlines(istream& ins) {
    while (ins.peek() == '\n' || ins.peek() == '\r') {
        ins.ignore();
    }
}

void test(Planner& p, int testNum) {
	Assignment a, b, c;
	Planner p2, p3;

	switch (testNum) {
		case 1:
			// test: print the due_next value
			cout << p.due_next() << endl;
			p.~Planner();
			cout << p.due_next() << endl;
			break;
		case 2:
			// test: add 1 assignment
			cin >> a;
			cin.ignore();  // remove extra newline

			p.add(a);
			p.display(cout);
			break;
		case 3:
			// test: add assignments out of order
			cin >> a;
			cin >> b;
			cin.ignore();  // remove extra newline

			p.add(a);
			p.add(b);
			p.add(a);
			p.add(b);
			p.add(c);
			p.add(b);
			p.display(cout);
			break;
		case 4:
			// test: remove an assignment
			cin >> a;
			cin.ignore();  // remove extra newline

			p.add(a);
			p.remove(a.get_name());
			p.display(cout);
			break;
		case 5:
			// test: use remove on an empty Planner
			p.~Planner();
			p.remove("test");
			p.display(cout);
			break;
		case 6:
			// test: deconstructor
			p.add(a);
			p.~Planner();
			p.display(cout);
			p.add(a);
			p.add(a);
			p.~Planner();
			p.display(cout);
			break;
		case 7:
			// test: check memory usage before adding Assignments, after adding Assignments, and after deleting Assignments
			pause("check memory usage and press enter when done: ");
			cout << "continuing..." << endl;

			for(int i = 0; i < 10000; i++) {
				p.add(a);
			}
			pause("check memory usage and press enter when done: ");
			cout << "continuing..." << endl;

			for(int i = 0; i < 10000; i++) {
				p.remove(a.get_name());
			}
			pause("check memory usage and press enter when done: ");
			cout << "continuing..." << endl;
			p.display(cout);
			break;
		case 8:
			// test: add 1 assignment to the planner and copy it
			cin >> a;
			cin.ignore();  // remove extra newline

			p2 = Planner(p);
			p2.display(cout);

			p.add(a);
			p3 = Planner(p);
			p3.display(cout);
			break;
		case 9:
			// test: use = operator
			cin >> a;
			cin.ignore();  // remove extra newline

			p2 = p;
			cout << "first run (should be empty)" << endl;
			p2.display(cout);
			p.add(a);

			p2 = p;
			cout << "second run (should have 1 entry)" << endl;
			p2.display(cout);
			break;
		case 10:
			// test: check memory usage before adding nodes to p, after adding nodes to p, and after setting new p using = operator
			pause("check memory usage and press enter when done: ");
			cout << "continuing..." << endl;

			for(int i = 0; i < 10000; i++) {
				p.add(a);
			}
			pause("check memory usage and press enter when done: ");
			cout << "continuing..." << endl;

			p = p2;
			pause("check memory usage and press enter when done: ");
			cout << "continuing..." << endl;
			p.display(cout);
			break;
		case 11:
			// test: add two assignments and print due_next
			cin >> a;
			cin >> b;
			p.add(a);
			p.add(b);
			cout << p.due_next() << endl;
			break;
		case 12:
			// test: add two assignments and print average_wait
			cin >> a;
			cin >> b;
			p.add(a);
			p.add(b);
			cout << p.average_wait() << endl;
			break;
	}
}