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

/**
 * @note If you cannot understand, please refer to the following link:
 * https://en.cppreference.com/w/cpp/language/parameter_pack
 * Otherwise, you may contact the TA.
 */
template <class _Tp, class ..._Args>
UniquePtr <_Tp> make_unique(_Args &&...);

#endif //UNIQUE_PTR
