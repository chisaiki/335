#include <iostream>
#include <cstdlib>
#include <string>


class Customer
{
    private:
        std::string name_;
        int service_time_;
        int priority_level_;

    public:
        /*Constructors*/
        Customer() : name_("Unknown"), service_time_(0), priority_level_(0) {}
        
        Customer(std::string name) : name_(name) 
        {
            SetPriorityLevel();
        }

        /*Member Functions*/
        void SetPriorityLevel() 
        {
            this->priority_level_ = (rand() % 100) + 1;
        }

        void SetServiceTime()
        {
            this->service_time_ = (rand() % 60) + 1;
        }

        /*Getter methods*/
        std::string getName() const { return name_; }
        int getPriorityLevel() const { return priority_level_; }
        int getServiceTime() const { return service_time_; }

        /*Add comparison operators to make Customer work with heaps*/
        bool operator<(const Customer& other) const 
        {
            return this->priority_level_ < other.priority_level_;
        }
        
        bool operator>(const Customer& other) const 
        {
            return this->priority_level_ > other.priority_level_;
        }
};