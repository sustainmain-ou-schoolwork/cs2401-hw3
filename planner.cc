#include "planner.h"

Planner::Planner() {

}

Planner::~Planner() {

}

Planner::Planner(const Planner& other) {

}

void Planner::operator = (const Planner& other) {

}


void Planner::add(const node& item) {

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

}

void Planner::find_all(DateTime due_date) const {

}


void Planner::load(std::istream& ins) {

}

void Planner::save(std::ostream& outs) const {

}