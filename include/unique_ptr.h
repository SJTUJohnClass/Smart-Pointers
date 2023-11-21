#ifndef UNIQUE_PTR
#define UNIQUE_PTR

template <class _Tp> // Template type parameter
struct UniquePtr {
  private:
    // Add whatever you want to add.

  public:
    /**
     * @brief Constructors and assignments of UniquePtr.
     * 
     * @note To guarantee the uniqueness of the pointer,
     * you should invalidate some of the constructors.
     * A recommended implementation is to set as deleted.
     * Use = delete to set a function as deleted.
     * 
     */

    UniquePtr();
    ~UniquePtr();

    UniquePtr(const UniquePtr &);
    UniquePtr(UniquePtr &&);

    UniquePtr& operator = (const UniquePtr &);
    UniquePtr& operator = (UniquePtr &&);

    explicit UniquePtr(_Tp *);

    /**
     * @brief Please implement all these member functions.
     */

    _Tp *get() const;
    _Tp *release();

    _Tp &operator * () const;
    _Tp *operator ->() const;

    void reset();
    void reset(_Tp *);
};

#endif //UNIQUE_PTR
