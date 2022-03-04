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
}

Planner::Planner(const Planner& other) {

}

void Planner::operator = (const Planner& other) {

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
}

void Planner::add(const node& item) {
    node* cursor = head;
    node* previous;

    // if list is empty
    if (cursor == NULL) {
        add_end(item);
    }
    else {
        // run through the list until the cursor points at a greater value or the last node
        while (cursor -> link() != NULL && cursor -> data() <= item.data()) {
            previous = cursor;
            cursor = cursor -> link();
        }

        // if cursor is pointing at the last node
        if (cursor -> link() == NULL) {
            add_end(item);
        }
        else {
            previous -> set_link(new node(item.data(), cursor));
        }
    }
}

void Planner::remove(const std::string& name) const {

}


unsigned int Planner::due_next() const {
    // TODO
    return 0;
}

unsigned int Planner::average_wait() const {
    // TODO
    return 0;
}

unsigned int Planner::waiting() const {
    // TODO
    return 0;
}

unsigned int Planner::oldest() const {
    // TODO
    return 0;
}

unsigned int Planner::newest() const {
    // TODO
    return 0;
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