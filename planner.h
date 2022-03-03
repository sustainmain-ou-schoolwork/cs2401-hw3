#ifndef PLANNER_H
#define PLANNER_H

#include "node.h"
#include "assignment.h"

class Planner {
    public:
        /**
         * @brief Construct a new Planner object.
         */
        Planner();

        /**
         * @brief Destroy the Planner object.
         */
        ~Planner();

        /**
         * @brief Construct a new Planner object from an existing Planner object.
         * 
         * @param other the exisiting Planner object to copy values from
         */
        Planner(const Planner& other);

        /**
         * @brief Set the values of a Planner object based on the values of an exisiting Planner object.
         * 
         * @param other the exisiting Planner object to copy values from
         */
        void operator = (const Planner& other);


        /**
         * @brief Adds an item to the list.
         * 
         * @param item the item to be added
         */
        void add(const node& item);

        /**
         * @brief Remove the first Assignment that matches a given name.
         * 
         * @param name the name to check the Assignments against
         */
        void remove(const std::string& name) const;


        /**
         * @brief Returns the number of minutes until the next assignment is due.
         * 
         * @return the number of minutes until the next assignment is due
         */
        unsigned int due_next() const;

        /**
         * @brief Returns the average wait time of all assignments.
         * 
         * @return the average wait time of all assignments
         */
        unsigned int average_wait() const;

        /**
         * @brief Returns the number of assignments that are still waiting to be completed.
         * 
         * @return the number of assignments that are still waiting to be completed
         */
        unsigned int waiting() const;

        /**
         * @brief Returns the number of minutes since the oldest assigment was entered.
         * 
         * @return the number of minutes since the oldest assigment was entered
         */
        unsigned int oldest() const;

        /**
         * @brief Returns the number of minutes since the newest assigment was entered.
         * 
         * @return the number of minutes since the newest assigment was entered
         */
        unsigned int newest() const;

        /**
         * @brief Find an Assignment by name.
         * 
         * @param name the name of the target Assignment
         * @return the first Assignment that matches
         */
        Assignment find(const std::string& name) const;


        /**
         * @brief Output all the items in the list.
         * 
         * @param outs the ostream to output to
         */
        void display(std::ostream& outs) const;

        /**
         * @brief Print all the assignments due by a given date to the screen.
         * 
         * @param due_date the date to check
         */
        void find_all(DateTime due_date) const;


        /**
         * @brief Load a Planner from an istream.
         * 
         * @param ins the istream to load the Planner from
         */
        void load(std::istream& ins);

        /**
         * @brief Output a Planner to an ostream.
         * 
         * @param outs the ostream to output the Planner to
         */
        void save(std::ostream& outs) const;

    private:
        node* head;              // pointer to the head of the list
        node* tail;              // pointer to the tail of the list
        unsigned int nodecount;  // number of nodes stored in the list
};

#endif