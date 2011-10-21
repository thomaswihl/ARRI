/**
* (C) copyright 2020

Changed that line in mysBranch

*

added a conflicting line in master branch

* @file ../src/app/rpy_generated/RingBuffer.h
* @author MichaelMayer
* @brief 
*
* Rhapsody: 7.6
* Component: EMC
* Configuration: C166
* Element: RingBuffer
*
*/

#ifndef RingBuffer_H
#define RingBuffer_H

//#[ ignore
#ifdef _MSC_VER
// disable Microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif
//#]

#define A_NON_CONFLICTING_LINE

//## auto_generated
#include <oxf/oxf.h>
//## auto_generated
#include <string>
//## auto_generated
#include <algorithm>
//## auto_generated
#include "TypesPkg.h"
//## package TypesPkg

#include "YetAnotherMasterFeature.h"


//## class RingBuffer
///
///In opposition to the STL containers this one doesn't stretch with the amount of data you put in, but it has a fixed size 
///and if you write more than that into it it just overwrites the old data beginning with the first ...
template <class T> class RingBuffer {
public :

    //## auto_generated
    class iterator;
    
    ///
    ///
    //## class RingBuffer::iterator
    class iterator {
        ////    Constructors and destructors    ////
        
    public :
    
        ///
        ///
        //## operation iterator(const iterator&)
        iterator(const iterator& other);
        
        ///
        ///
        //## operation iterator(uint16_t,const RingBuffer<T>*)
        iterator(uint16_t index, const RingBuffer<T>* ringBuffer);
        
        ////    Operations    ////
        
        ///
        ///
        //## operation operator!=(const iterator&) const
        inline bool operator!=(const iterator& other) const;
        
        ///
        ///
        //## operation operator*() const
        inline T& operator*() const;
        
        ///
        ///
        //## operation operator+(int16_t) const
        inline typename RingBuffer<T>::iterator operator+(int16_t distance) const;
        
        ///
        ///
        //## operation operator++()
        inline typename RingBuffer<T>::iterator& operator++();
        
        ///
        ///
        //## operation operator+=(int16_t)
        typename RingBuffer<T>::iterator& operator+=(int16_t distance);
        
        ///
        ///
        //## operation operator-(const iterator&) const
        inline uint16_t operator-(const iterator& other) const;
        
        ///
        ///
        //## operation operator-(int16_t) const
        inline typename RingBuffer<T>::iterator operator-(int16_t distance) const;
        
        ///
        ///
        //## operation operator--()
        inline typename RingBuffer<T>::iterator& operator--();
        
        ///
        ///
        //## operation operator-=(int16_t)
        inline typename RingBuffer<T>::iterator& operator-=(int16_t distance);
        
        ///
        ///
        //## operation operator->() const
        inline const T* operator->() const;
        
        ///
        ///
        //## operation operator=(const iterator&)
        inline const typename RingBuffer<T>::iterator& operator=(const iterator& other);
        
        ///
        ///
        //## operation operator==(const iterator&) const
        inline bool operator==(const iterator& other) const;
        
        ////    Attributes    ////
    
    private :
    
        ///
        ///
        uint16_t index;		//## attribute index
        
        ///
        ///
        const RingBuffer<T>* itsRingBuffer;		//## attribute itsRingBuffer
    };
    
    ////    Constructors and destructors    ////
    
    ///
    ///
    //## operation RingBuffer(uint16_t)
    RingBuffer(uint16_t theCapacity);
    
    ///
    /// Use this constructor when you already have a (linear) buffer and just want to wrapp a RingBuffer around that.
    ///
    /// capacity is the total size of the given array.
    /// size is number of already filled bytes of content.
    ///
    /// capacity must be bigger than size!!
    //## operation RingBuffer(T,uint16_t,uint16_t)
    RingBuffer(T* buffer, uint16_t capacity, uint16_t size);
    
    ///
    ///
    //## operation ~RingBuffer()
    ~RingBuffer();
    
    ////    Operations    ////
    
    ///
    ///
    //## operation begin() const
    inline typename RingBuffer<T>::iterator begin() const;
    
    ///
    /// This returns the actual size of the reserved space. Due to the internal handling it is indeed one more
    /// than the capacity argument provided in the constructor!
    //## operation capacity() const
    inline uint16_t capacity() const;
    
    ///
    ///
    //## operation clear()
    inline void clear();
    
    ///
    ///
    //## operation empty() const
    inline bool empty() const;
    
    ///
    ///
    //## operation end() const
    inline typename RingBuffer<T>::iterator end() const;
    
    ///
    /// How many elements could be stuffed in without overring any existing.
    //## operation free() const
    inline uint16_t free() const;
    
    ///
    ///
    //## operation front()
    inline T& front();
    
    ///
    ///
    //## operation full() const
    inline bool full() const;
    
    ///
    /// Just take back the previously written character.
    ///
    /// Precondition: !empty()
    //## operation pop_back()
    inline void pop_back();
    
    ///
    ///
    //## operation pop_front()
    inline void pop_front();
    
    ///
    ///
    //## operation push_back(const T&)
    inline void push_back(const T& element);
    
    ///
    ///
    //## operation size() const
    inline uint16_t size() const;
    
    ////    Attributes    ////

private :

    ///
    ///
    const uint16_t _capacity;		//## attribute _capacity
    
    ///
    ///
    uint16_t _read;		//## attribute _read
    
    ///
    ///
    uint16_t _write;		//## attribute _write
    
    ///
    /// Remember if we should delete the elements in destructor
    const bool dontDelete;		//## attribute dontDelete
    
    ///
    ///
    T* elements;		//## attribute elements
};

//## package TypesPkg

//## class RingBuffer
template <class T> RingBuffer<T>::RingBuffer(uint16_t theCapacity) : _capacity(theCapacity + 1), _read(0), _write(0), dontDelete(false), elements(new T[_capacity]) {
    //#[ operation RingBuffer(uint16_t)
    //#]
}

template <class T> RingBuffer<T>::RingBuffer(T* buffer, uint16_t capacity, uint16_t size) : _capacity(capacity), _read(0), _write(size), dontDelete(true), elements(buffer) {
    //#[ operation RingBuffer(T,uint16_t,uint16_t)
    //#]
}

template <class T> RingBuffer<T>::~RingBuffer() {
    //#[ operation ~RingBuffer()
    if (!dontDelete) delete[] elements;
    //#]
}

template <class T> inline typename RingBuffer<T>::iterator RingBuffer<T>::begin() const {
    //#[ operation begin() const
    iterator iter(_read, this);
    return iter;
    //#]
}

template <class T> inline uint16_t RingBuffer<T>::capacity() const {
    //#[ operation capacity() const
    return _capacity;
    //#]
}

template <class T> inline void RingBuffer<T>::clear() {
    //#[ operation clear()
    _read = _write;
    //#]
}

template <class T> inline bool RingBuffer<T>::empty() const {
    //#[ operation empty() const
    return (_read == _write);
    //#]
}

template <class T> inline typename RingBuffer<T>::iterator RingBuffer<T>::end() const {
    //#[ operation end() const
    iterator iter(_write, this);
    return iter;
    //#]
}

template <class T> inline uint16_t RingBuffer<T>::free() const {
    //#[ operation free() const
    return capacity() - size() - 1;
    //#]
}

template <class T> inline T& RingBuffer<T>::front() {
    //#[ operation front()
    return elements[_read];
    //#]
}

template <class T> inline bool RingBuffer<T>::full() const {
    //#[ operation full() const
    uint16_t idx = _write + 1;
    if (idx == _capacity) idx = 0;
    
    return (idx == _read);
    //#]
}

template <class T> inline void RingBuffer<T>::pop_back() {
    //#[ operation pop_back()
    if (_write == _capacity - 1) _write = 0;
    else --_write;
    //#]
}

template <class T> inline void RingBuffer<T>::pop_front() {
    //#[ operation pop_front()
    uint16_t idx = _read + 1;
    if (idx == _capacity) idx = 0;
    
    _read = idx;
    //#]
}

template <class T> inline void RingBuffer<T>::push_back(const T& element) {
    //#[ operation push_back(const T&)
    uint16_t idx = _write + 1;
    if (idx == _capacity) idx = 0;
    
    elements[_write] = element;
    _write = idx;
    
    /* This is dangerous! When a ISR empties us right in this moment
       we set the buffer from empty to complete full!
    if (_end == _begin)
    {
        ++_begin;   // we just overwrite, the user takes care of the capacity!!
    }
    */
    //#]
}

template <class T> inline uint16_t RingBuffer<T>::size() const {
    //#[ operation size() const
    uint16_t size = _write - _read;
    if ((int16_t)size >= 0) return size;
    else return ((int16_t)size + _capacity);
    //#]
}

template <class T> RingBuffer<T>::iterator::iterator(const iterator& other) : itsRingBuffer(other.itsRingBuffer), index(other.index) {
    //#[ operation iterator(const iterator&)
    //#]
}

template <class T> RingBuffer<T>::iterator::iterator(uint16_t index, const RingBuffer<T>* ringBuffer) : itsRingBuffer(ringBuffer), index(index) {
    //#[ operation iterator(uint16_t,const RingBuffer<T>*)
    //#]
}

template <class T> inline bool RingBuffer<T>::iterator::operator!=(const iterator& other) const {
    //#[ operation operator!=(const iterator&) const
    return (index != other.index);
    //#]
}

template <class T> inline T& RingBuffer<T>::iterator::operator*() const {
    //#[ operation operator*() const
    return itsRingBuffer->elements[index];
    //#]
}

template <class T> inline typename RingBuffer<T>::iterator RingBuffer<T>::iterator::operator+(int16_t distance) const {
    //#[ operation operator+(int16_t) const
    iterator iter(*this);
    iter += distance;
    return iter;
    //#]
}

template <class T> inline typename RingBuffer<T>::iterator& RingBuffer<T>::iterator::operator++() {
    //#[ operation operator++()
    if (index == itsRingBuffer->_capacity - 1)  // we already point to last element
    {
        index = 0;
    }
    else
    {
        ++index;
    }
    return *this;
    //#]
}

template <class T> typename RingBuffer<T>::iterator& RingBuffer<T>::iterator::operator+=(int16_t distance) {
    //#[ operation operator+=(int16_t)
    int16_t newIndex = index + distance;
    
    if (newIndex >= itsRingBuffer->_capacity) 
    {
        newIndex = newIndex % itsRingBuffer->_capacity;
    }
    else if (newIndex < 0)
    {
        newIndex = -newIndex;
        newIndex = newIndex % itsRingBuffer->_capacity;
        newIndex = itsRingBuffer->_capacity - newIndex;
    }
    
    index = newIndex;
    
    return *this;
    //#]
}

template <class T> inline uint16_t RingBuffer<T>::iterator::operator-(const iterator& other) const {
    //#[ operation operator-(const iterator&) const
    uint16_t result = index - other.index;
    if ((int16_t)result < 0) result += itsRingBuffer->_capacity;
    return result;
    //#]
}

template <class T> inline typename RingBuffer<T>::iterator RingBuffer<T>::iterator::operator-(int16_t distance) const {
    //#[ operation operator-(int16_t) const
    return operator+(-distance);
    //#]
}

template <class T> inline typename RingBuffer<T>::iterator& RingBuffer<T>::iterator::operator--() {
    //#[ operation operator--()
    if (index == 0)  // we already point to first element
    {
        index = itsRingBuffer->_capacity - 1;
    }
    else
    {
        --index;
    }
    return *this;
    //#]
}

template <class T> inline typename RingBuffer<T>::iterator& RingBuffer<T>::iterator::operator-=(int16_t distance) {
    //#[ operation operator-=(int16_t)
    return operator+=(-distance);
    //#]
}

template <class T> inline const T* RingBuffer<T>::iterator::operator->() const {
    //#[ operation operator->() const
    return &itsRingBuffer->elements[index];
    //#]
}

template <class T> inline const typename RingBuffer<T>::iterator& RingBuffer<T>::iterator::operator=(const iterator& other) {
    //#[ operation operator=(const iterator&)
    index = other.index;
    itsRingBuffer = other.itsRingBuffer;
    return *this;
    //#]
}

template <class T> inline bool RingBuffer<T>::iterator::operator==(const iterator& other) const {
    //#[ operation operator==(const iterator&) const
    return (index == other.index);
    //#]
}

#endif
/*********************************************************************
	File Path	: ../src/app/rpy_generated/RingBuffer.h
*********************************************************************/
