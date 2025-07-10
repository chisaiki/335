#include<iostream>

using namespace std;

template <typename T>
class Queue
{
private:
    T* data_;          // Pointer to dynamically allocated array
    size_t size_;      // Number of elements currently in the vector
    size_t capacity_;  // Capacity of the vector (how many elements it can hold)

public:
    Queue() : size_(0), capacity_(1) // Constructor
    {
        cout<<"constructor called"<<endl;
        data_ = new T[capacity_];  // Allocate memory for 1 element
    }
    

    Queue(const Queue& other)//copy constuctor
    {
        cout<<"copy constructor called"<<endl;
        size_ = other.size_;
        capacity_ = other.capacity_;
        data_ = new T[capacity_];
        for(int i =0;i<size_;i++)   data_[i]=other.data_[i];
    }


    Queue& operator=(const Queue &rhs) //copy assignment operator
    {
        cout<<"copy assignment called "<<endl;
        size_ = rhs.size_;
        capacity_ = rhs.capacity_;
        delete[] data_; // clear what was there before
        data_ = new T[capacity_];
        for(int i =0;i<size_;i++)   data_[i]=rhs.data_[i];
        return *this;
    }


    Queue(Queue&& other)//move constuctor
    {
        cout<<"move constructor called"<<endl;
        size_ = other.size_;
        capacity_ = other.capacity_;
        data_=other.data_;

        // must delete cause you want to rid the data of other object
        other.size_=0;
        other.capacity_=1;
        other.data_=new T[other.capacity_];
        //Makes the original pointer to point to an empty array, prevent dangling pointer
    }


    Queue& operator=(Queue &&rhs) //move assignment operator
    {
        cout<<"move assignment called"<<endl;
        size_ = rhs.size_;
        capacity_ = rhs.capacity_;
        delete[] data_; // clear what was there before
        data_ = rhs.data_;

        // must delete cause you want to rid the data of rhs object
        rhs.size_=0;
        rhs.capacity_=1;
        rhs.data_=new T[rhs.capacity_];

        return *this;
    }

    
    // Destructor
    ~Queue()
    {
        cout<<"destructor called"<<endl;
        delete[] data_;  // Free dynamically allocated memory

        //To prevent dangling pointer
        size_ = 0;
        capacity_ = 1;
        data_ = new T[capacity_]; //can use data_ = nullptr; but because of the way the code was written, it could lead to issues down the line
    }


    // Method to add an element to the back of queue
    void push(const T& value)
    {
        if (size_ == capacity_) resize();  // Resize if capacity is reached

        data_[size_] = value;
        size_++;
    }


    // Method to remove an element from the front of queue
    T pop()
    {
        if (size_ == 0) throw std::out_of_range("Nothing to pop");
        T popped = data_[0];
        for(int i=1;i<size_;i++) data_[i-1]=data_[i];
        size_--;
        return popped;
    } //O(n) so its better to use a linked list, since push and pop would be O(1)
    //circular array?


    //return first element
    T front() const
    {
        if (size_ == 0) throw std::out_of_range("Empty queue");
        else return data_[0];
    }


    //return last element
    T back() const
    {
        if (size_ == 0) throw std::out_of_range("Empty queue");
        else return data_[size_-1];
    }


    // check is queue is empty 
    bool isEmpty() const
    {
        if(size_==0)return true;
        else return false;
    }


    // Method to get the size of the vector
    size_t getSize() const { return size_; }

private:
    // Helper method to resize the vector when capacity is reached
    void resize() 
    {
        capacity_ *= 2;  // Double the capacity
        T* newData = new T[capacity_];  // Allocate larger array

        // Copy old data to new array
        for (size_t i = 0; i < size_; i++)  newData[i] = data_[i];

        delete[] data_;  // Delete old array
        data_ = newData;  // Point to new array
    }

};


int main()
{
    Queue<int> q1; // object created using constructor

    // Add elements to the queue
    q1.push(10);
    q1.push(20);
    q1.push(30);
    q1.push(15);
    q1.push(25);
    q1.push(35);
    q1.push(1);
    q1.push(100);

    //Queue<int> q2(std::move(q1)); // move constructor called

    //Queue<int> q2(q1); // copy constructor called
    
    Queue<int> q2;
    q2.push(11);
    q2.push(22);
    q2.push(33);
    cout<<"q2: "<<q2.back()<<endl;

    //q2=q1; //copy assignment
    q2=move(q1);//move assignment

    cout<<"q2: "<<q2.back()<<endl;
    cout<<"q1: "<<q1.back()<<endl;

    return 0;
}