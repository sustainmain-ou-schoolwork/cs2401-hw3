#include "planner.h"
#include "node.h"

Planner::Planner() {
    head = tail = NULL;
    nodecount = 0;
}

Planner::~Planner() {
    node* previous;
    while (head != NULL) {
        previous = head;
        head = head -> link();
        delete previous;
    }

    nodecount = 0;
}

Planner::Planner(const Planner& other) {
    head = tail = NULL;
    nodecount = 0;

    node* cursor = other.head;
    node tmp;

    while (cursor != NULL) {
        tmp = node(cursor -> data());
        add_end(tmp);
        cursor = cursor -> link();
    }
}

void Planner::operator = (const Planner& other) {
    if (this == &other) {
        return;
    }

    // delete all nodes
    node* previous;
    while (head != NULL) {
        previous = head;
        head = head -> link();
        delete previous;
    }
    head = tail = NULL;
    nodecount = 0;

    // copy all the nodes from other
    node* cursor = other.head;
    node tmp;
    while (cursor != NULL) {
        tmp = node(cursor -> data());
        add_end(tmp);
        cursor = cursor -> link();
    }
}


void Planner::add_end(const node& item) {
    // if list is empty
    if (head == NULL) {
        head = tail = new node(item.data());
    }
    else {
        tail -> set_link(new node(item.data()));
        tail = tail -> link();
    }

    nodecount++;
}

void Planner::add(const node& item) {
    node* cursor = head;
    node* previous = NULL;

    // if list is empty
    if (cursor == NULL) {
        add_end(item);
    }
    else {
        // run through the list until the cursor points at the last node or a node with a greater value
        while ((cursor != NULL) && (cursor -> data() <= item.data())) {
            previous = cursor;
            cursor = cursor -> link();
        }

        if (cursor == NULL) {
            // passed through the whole list
            add_end(item);
        }
        else if (previous == NULL) {
            // cursor pointing at first node
            head = new node(item.data(), cursor);
            nodecount++;
        }
        else {
            previous -> set_link(new node(item.data(), cursor));
            nodecount++;
        }
    }
}

void Planner::remove(const std::string& name) {
    node* cursor = head;
    node* previous = NULL;

    // run through the list until the cursor points at NULL or the target node
    while ((cursor != NULL) && (cursor -> data().get_name() != name)) {
        previous = cursor;
        cursor = cursor -> link();
    }

    // if the target node was found, remove it
    if (cursor != NULL) {
        // if the target node is the first node
        if (head == cursor) {
            head = head -> link();
        }
        else {
            previous -> set_link(cursor -> link());
        }

        // if the target node was the last node
        if (tail == cursor) {
            tail = previous;
        }

        delete cursor;
        nodecount--;
    }
}


unsigned int Planner::due_next() const {
    DateTime now;
    if (head == NULL) {
        return 0;
    }
    else {
        // check if the assignment is past due
        now.make_now();
        if (now < head -> data().get_due()) {
            return head -> data().minutes_til_due();
        }
        else {
            return 0;
        }
    }
}

double Planner::average_wait() const {
    node* cursor = head;
    unsigned int totalWait = 0;

    // add the wait times of each assignment
    while (cursor != NULL) {
        totalWait += cursor -> data().minutes_waiting();
        cursor = cursor -> link();
    }

    return static_cast<double>(totalWait) / static_cast<double>(nodecount);
}

unsigned int Planner::waiting() const {
    return nodecount;
}

unsigned int Planner::oldest() const {
    node* cursor = head;
    unsigned int oldest = 0;

    if (cursor == NULL) {
        return 0;
    }
    else {
        while (cursor != NULL) {
            if (cursor -> data().minutes_waiting() > oldest) {
                oldest = cursor -> data().minutes_waiting();
            }
            cursor = cursor -> link();
        }
        return oldest;
    }
}

unsigned int Planner::newest() const {
    node* cursor = head;
    unsigned int newest;

    if (cursor == NULL) {
        return 0;
    }
    else {
        newest = newest = cursor -> data().minutes_waiting();
        cursor = cursor -> link();
        
        while (cursor != NULL) {
            if (cursor -> data().minutes_waiting() < newest) {
                newest = cursor -> data().minutes_waiting();
            }
            cursor = cursor -> link();
        }
        return newest;
    }
}

Assignment Planner::find(const std::string& name) const {
    // TODO
    return Assignment();
}


void Planner::display(std::ostream& outs) const {
    node* cursor = head;

    while (cursor != NULL) {
        outs << cursor -> data() << '\n';

        cursor = cursor -> link();
    }
}

void Planner::find_all(DateTime due_date) const {

}


void Planner::load(std::istream& ins) {

}

void Planner::save(std::ostream& outs) const {

}