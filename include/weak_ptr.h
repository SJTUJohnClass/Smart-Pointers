#ifndef WEAK_PTR
#define WEAK_PTR

#include "shared_ptr.h" // Include SharedPtr definition

template <typename T>
class WeakPtr {
public:
    // Constructors
    WeakPtr();  // Default constructor
    WeakPtr(const WeakPtr& other);  // Copy constructor
    WeakPtr(WeakPtr&& other) noexcept;  // Move constructor
    WeakPtr(const SharedPtr<T>& other);  // Construct from SharedPtr
    
    // Destructor
    ~WeakPtr();
    
    // Assignment operators
    WeakPtr& operator=(const WeakPtr& other);  // Copy assignment
    WeakPtr& operator=(WeakPtr&& other) noexcept;  // Move assignment
    WeakPtr& operator=(const SharedPtr<T>& other);  // SharedPtr assignment
    
    // Basic operations
    void reset();  // Reset to empty state
    size_t use_count() const;  // Get the number of shared owners
    bool expired() const;  // Check if the managed object was deleted
    SharedPtr<T> lock() const;  // Get a SharedPtr to the managed object
    
    // Utility functions
    void swap(WeakPtr& other) noexcept;  // Swap with another WeakPtr

private:
    // Add your private members here
    // Typically includes:
    // - Pointer to the managed object
    // - Pointer to control block
    // - Helper functions for reference counting
};

// Non-member swap function
template <typename T>
void swap(WeakPtr<T>& lhs, WeakPtr<T>& rhs) noexcept {
    lhs.swap(rhs);
}

#endif //WEAK_PTR