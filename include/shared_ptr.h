#ifndef SHARED_PTR
#define SHARED_PTR

template <class _Tp> // Template type parameter
struct SharedPtr {
  private:
    // Add whatever you want to add.

  public:
    /**
     * @brief Constructors and assignments of SharedPtr.
     */

    SharedPtr();
    ~SharedPtr();

    SharedPtr(const SharedPtr &);
    SharedPtr(SharedPtr &&);

    SharedPtr& operator = (const SharedPtr &);
    SharedPtr& operator = (SharedPtr &&);

    explicit SharedPtr(_Tp *);

    /**
     * @brief Please implement all these member functions.
     */

    _Tp *get() const;
    std::size_t use_count() const;

    _Tp &operator * () const;
    _Tp *operator ->() const;

    void reset();
    void reset(_Tp *);

    int *use_count() const;
};


#endif //SHARED_PTR