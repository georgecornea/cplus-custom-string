//  Iterator.hpp class interface
//  Name: George Cornea
//  Date: May 2023

#ifndef Iterator_h
#define Iterator_h

struct Iterator
{
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = char;
    using pointer = char*;
    using reference = char&;
    
    Iterator(pointer ptr):cPtr(ptr){} // c-tor
    
    reference operator* () { return *cPtr;} // operator *
    pointer operator-> () { return cPtr;} // operator ->
    
    // operator ++()
    Iterator& operator++ ()
    {
        ++cPtr;
        return *this;
    }
    
    // operator ()++
    Iterator operator++(int)
    {
        Iterator temp = *this;
        ++cPtr;
        return temp;
    }
    
    // operator ==
    friend bool operator== (const Iterator& it1, const Iterator& it2)
    {
        return strcmp(it1.cPtr, it2.cPtr) == 0;
    }
    
    // operator !=
    friend bool operator!= (const Iterator& it1, const Iterator& it2) { return !(it1 == it2);}
    
private:
    pointer cPtr; // data member
};



#endif /* Iterator_h */
