#include "max_heap.h"
#include "customer.h"

using namespace std;

/*Vector to store customer history*/
vector<Customer> customerHistory;

int main()
{
    /*Seed the random number generator once at the beginning*/
    srand(time(NULL));
    
    /*Create a MaxHeap for Customer objects*/
    MaxHeap<Customer> customerHeap;
    
    /*Create customers and insert them into the max heap*/
    Customer customer1("Alice");
    Customer customer2("Bob");
    Customer customer3("Charlie");
    Customer customer4("Diana");
    Customer customer5("Eve");
    Customer customer6("Frank");
    Customer customer7("Grace");
    Customer customer8("Henry");
    
    customerHeap.insert(customer1);
    customerHeap.insert(customer2);
    customerHeap.insert(customer3);
    customerHeap.insert(customer4);
    customerHeap.insert(customer5);
    customerHeap.insert(customer6);
    customerHeap.insert(customer7);
    customerHeap.insert(customer8);
        
    /*Test deleting customers (highest priority first)*/
    cout << "Deleting customers in priority order..." << endl;
    while(customerHeap.getSize() > 0) 
    {
        Customer deletedCustomer = customerHeap.deleteMax();
        
        /*Set service time for the deleted customer and add to history vector*/
        deletedCustomer.SetServiceTime();
        customerHistory.push_back(deletedCustomer);
    }
    
    /*Display customer history*/
    cout << "\n=== Customer Service History ===" << endl;
    for(size_t i = 0; i < customerHistory.size(); i++) {
        cout << "Customer: " << customerHistory[i].getName()
             << " (Priority: " << customerHistory[i].getPriorityLevel()
             << "), Service Time: " << customerHistory[i].getServiceTime() << " minutes." << endl;
    }

    /*Sort history based on Service Time*/
    sort(customerHistory.begin(), customerHistory.end(), [](const Customer& a, const Customer& b) {
        return a.getServiceTime() < b.getServiceTime();  // Sort by service time ascending
    });
    
    /*Display sorted history*/
    cout << "\n=== Customer Service History SORTED BY SERVICE TIME ===" << endl;
    for(size_t i = 0; i < customerHistory.size(); i++) {
        cout << "Customer: " << customerHistory[i].getName()
             << " (Priority: " << customerHistory[i].getPriorityLevel()
             << "), Service Time: " << customerHistory[i].getServiceTime() << " minutes." << endl;
    }

    return 0;
}