/**
* (c) copyright 2020

changed that line in mysbranch

*

added a conflicting line in master branch

* @file ../src/app/rpy_generated/ringbuffer.h
* @author michaelmayer
* @brief 
*
* rhapsody: 7.6
* component: emc
* configuration: c166
* element: ringbuffer
*
*/

#ifndef ringbuffer_h
#define ringbuffer_h

//#[ ignore
#ifdef _msc_ver
// disable microsoft compiler warning (debug information truncated)
#pragma warning(disable: 4786)
#endif
//#]

#define a_non_conflicting_line

//## auto_generated
#include <oxf/oxf.h>
//## auto_generated
#include <string>
//## auto_generated
#include <algorithm>
//## auto_generated
#include "typespkg.h"
//## package typespkg

# define this will be dangling!!


#include "yetanothermasterfeature.h"
#include "yetanotherbugfix.h"   // mysbranch

//## class ringbuffer
///
///in opposition to the stl containers this one doesn't stretch with the amount of data you put in, but it has a fixed size 
///and if you write more than that into it it just overwrites the old data beginning with the first ...
template <class t> class ringbuffer {
public :

    //## auto_generated
    class iterator;
    
    ///
    ///
    //## class ringbuffer::iterator
    class iterator {
        ////    constructors and destructors    ////
        
    public :
    
        ///
        ///
        //## operation iterator(const iterator&)
        iterator(const iterator& other);
        
        ///
        ///
        //## operation iterator(uint16_t,const ringbuffer<t>*)
        iterator(uint16_t index, const ringbuffer<t>* ringbuffer);
        
        ////    operations    ////
        
        ///
        ///
        //## operation operator!=(const iterator&) const
        inline bool operator!=(const iterator& other) const;
        
        ///
        ///
        //## operation operator*() const
        inline t& operator*() const;
        
        ///
        ///
        //## operation operator+(int16_t) const
        inline typename ringbuffer<t>::iterator operator+(int16_t distance) const;
        
        ///
        ///
        //## operation operator++()
        inline typename ringbuffer<t>::iterator& operator++();
        
        ///
        ///
        //## operation operator+=(int16_t)
        typename ringbuffer<t>::iterator& operator+=(int16_t distance);
        
        ///
        ///
        //## operation operator-(const iterator&) const
        inline uint16_t operator-(const iterator& other) const;
        
        ///
        ///
        //## operation operator-(int16_t) const
        inline typename ringbuffer<t>::iterator operator-(int16_t distance) const;
        
        ///
        ///
        //## operation operator--()
        inline typename ringbuffer<t>::iterator& operator--();
        
        ///
        ///
        //## operation operator-=(int16_t)
        inline typename ringbuffer<t>::iterator& operator-=(int16_t distance);
        
        ///
        ///
        //## operation operator->() const
        inline const t* operator->() const;
        
        ///
        ///
        //## operation operator=(const iterator&)
        inline const typename ringbuffer<t>::iterator& operator=(const iterator& other);
        
        ///
        ///
        //## operation operator==(const iterator&) const
        inline bool operator==(const iterator& other) const;
        
        ////    attributes    ////
    
    private :
    
        ///
        ///
        uint16_t index;		//## attribute index
        
        ///
        ///
        const ringbuffer<t>* itsringbuffer;		//## attribute itsringbuffer
    };
    
    ////    constructors and destructors    ////
    
    ///
    ///
    //## operation ringbuffer(uint16_t)
    ringbuffer(uint16_t thecapacity);
    
    ///
    /// use this constructor when you already have a (linear) buffer and just want to wrapp a ringbuffer around that.
    ///
    /// capacity is the total size of the given array.
    /// size is number of already filled bytes of content.
    ///
    /// capacity must be bigger than size!!
    //## operation ringbuffer(t,uint16_t,uint16_t)
    ringbuffer(t* buffer, uint16_t capacity, uint16_t size);
    
    ///
    ///
    //## operation ~ringbuffer()
    ~ringbuffer();
    
    ////    operations    ////
    
    ///
    ///
    //## operation begin() const
    inline typename ringbuffer<t>::iterator begin() const;
    
    ///
    /// this returns the actual size of the reserved space. due to the internal handling it is indeed one more
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
    inline typename ringbuffer<t>::iterator end() const;
    
    ///
    /// how many elements could be stuffed in without overring any existing.
    //## operation free() const
    inline uint16_t free() const;
    
    ///
    ///
    //## operation front()
    inline t& front();
    
    ///
    ///
    //## operation full() const
    inline bool full() const;
    
    ///
    /// just take back the previously written character.
    ///
    /// precondition: !empty()
    //## operation pop_back()
    inline void pop_back();
    
    ///
    ///
    //## operation pop_front()
    inline void pop_front();
    
    ///
    ///
    //## operation push_back(const t&)
    inline void push_back(const t& element);
    
    ///
    ///
    //## operation size() const
    inline uint16_t size() const;
    
    ////    attributes    ////

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
    /// remember if we should delete the elements in destructor
    const bool dontdelete;		//## attribute dontdelete
    
    ///
    ///
    t* elements;		//## attribute elements
};

//## package typespkg

//## class ringbuffer
template <class t> ringbuffer<t>::ringbuffer(uint16_t thecapacity) : _capacity(thecapacity + 1), _read(0), _write(0), dontdelete(false), elements(new t[_capacity]) {
    //#[ operation ringbuffer(uint16_t)
    //#]
}

template <class t> ringbuffer<t>::ringbuffer(t* buffer, uint16_t capacity, uint16_t size) : _capacity(capacity), _read(0), _write(size), dontdelete(true), elements(buffer) {
    //#[ operation ringbuffer(t,uint16_t,uint16_t)
    //#]
}

template <class t> ringbuffer<t>::~ringbuffer() {
    //#[ operation ~ringbuffer()
    if (!dontdelete) delete[] elements;
    //#]
}

template <class t> inline typename ringbuffer<t>::iterator ringbuffer<t>::begin() const {
    //#[ operation begin() const
    iterator iter(_read, this);
    return iter;
    //#]
}

template <class t> inline uint16_t ringbuffer<t>::capacity() const {
    //#[ operation capacity() const
    return _capacity;
    //#]
}

template <class t> inline void ringbuffer<t>::clear() {
    //#[ operation clear()
    _read = _write;
    //#]
}

template <class t> inline bool ringbuffer<t>::empty() const {
    //#[ operation empty() const
    return (_read == _write);
    //#]
}

template <class t> inline typename ringbuffer<t>::iterator ringbuffer<t>::end() const {
    //#[ operation end() const
    iterator iter(_write, this);
    return iter;
    //#]
}

template <class t> inline uint16_t ringbuffer<t>::free() const {
    //#[ operation free() const
    return capacity() - size() - 1;
    //#]
}

template <class t> inline t& ringbuffer<t>::front() {
    //#[ operation front()
    return elements[_read];
    //#]
}

template <class t> inline bool ringbuffer<t>::full() const {
    //#[ operation full() const
    uint16_t idx = _write + 1;
    if (idx == _capacity) idx = 0;
    
    return (idx == _read);
    //#]
}

template <class t> inline void ringbuffer<t>::pop_back() {
    //#[ operation pop_back()
    if (_write == _capacity - 1) _write = 0;
    else --_write;
    //#]
}

template <class t> inline void ringbuffer<t>::pop_front() {
    //#[ operation pop_front()
    uint16_t idx = _read + 1;
    if (idx == _capacity) idx = 0;
    
    _read = idx;
    //#]
}

template <class t> inline void ringbuffer<t>::push_back(const t& element) {
    //#[ operation push_back(const t&)
    uint16_t idx = _write + 1;
    if (idx == _capacity) idx = 0;
    
    elements[_write] = element;
    _write = idx;
    
    /* this is dangerous! when a isr empties us right in this moment
       we set the buffer from empty to complete full!
    if (_end == _begin)
    {
        ++_begin;   // we just overwrite, the user takes care of the capacity!!
    }
    */
    //#]
}

template <class t> inline uint16_t ringbuffer<t>::size() const {
    //#[ operation size() const
    uint16_t size = _write - _read;
    if ((int16_t)size >= 0) return size;
    else return ((int16_t)size + _capacity);
    //#]
}

template <class t> ringbuffer<t>::iterator::iterator(const iterator& other) : itsringbuffer(other.itsringbuffer), index(other.index) {
    //#[ operation iterator(const iterator&)
    //#]
}

template <class t> ringbuffer<t>::iterator::iterator(uint16_t index, const ringbuffer<t>* ringbuffer) : itsringbuffer(ringbuffer), index(index) {
    //#[ operation iterator(uint16_t,const ringbuffer<t>*)
    //#]
}

template <class t> inline bool ringbuffer<t>::iterator::operator!=(const iterator& other) const {
    //#[ operation operator!=(const iterator&) const
    return (index != other.index);
    //#]
}

template <class t> inline t& ringbuffer<t>::iterator::operator*() const {
    //#[ operation operator*() const
    return itsringbuffer->elements[index];
    //#]
}

template <class t> inline typename ringbuffer<t>::iterator ringbuffer<t>::iterator::operator+(int16_t distance) const {
    //#[ operation operator+(int16_t) const
    iterator iter(*this);
    iter += distance;
    return iter;
    //#]
}

template <class t> inline typename ringbuffer<t>::iterator& ringbuffer<t>::iterator::operator++() {
    //#[ operation operator++()
    if (index == itsringbuffer->_capacity - 1)  // we already point to last element
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

template <class t> typename ringbuffer<t>::iterator& ringbuffer<t>::iterator::operator+=(int16_t distance) {
    //#[ operation operator+=(int16_t)
    int16_t newindex = index + distance;
    
    if (newindex >= itsringbuffer->_capacity) 
    {
        newindex = newindex % itsringbuffer->_capacity;
    }
    else if (newindex < 0)
    {
        newindex = -newindex;
        newindex = newindex % itsringbuffer->_capacity;
        newindex = itsringbuffer->_capacity - newindex;
    }
    
    index = newindex;
    
    return *this;
    //#]
}

template <class t> inline uint16_t ringbuffer<t>::iterator::operator-(const iterator& other) const {
    //#[ operation operator-(const iterator&) const
    uint16_t result = index - other.index;
    if ((int16_t)result < 0) result += itsringbuffer->_capacity;
    return result;
    //#]
}

template <class t> inline typename ringbuffer<t>::iterator ringbuffer<t>::iterator::operator-(int16_t distance) const {
    //#[ operation operator-(int16_t) const
    return operator+(-distance);
    //#]
}

template <class t> inline typename ringbuffer<t>::iterator& ringbuffer<t>::iterator::operator--() {
    //#[ operation operator--()
    if (index == 0)  // we already point to first element
    {
        index = itsringbuffer->_capacity - 1;
    }
    else
    {
        --index;
    }
    return *this;
    //#]
}

template <class t> inline typename ringbuffer<t>::iterator& ringbuffer<t>::iterator::operator-=(int16_t distance) {
    //#[ operation operator-=(int16_t)
    return operator+=(-distance);
    //#]
}

template <class t> inline const t* ringbuffer<t>::iterator::operator->() const {
    //#[ operation operator->() const
    return &itsringbuffer->elements[index];
    //#]
}

template <class t> inline const typename ringbuffer<t>::iterator& ringbuffer<t>::iterator::operator=(const iterator& other) {
    //#[ operation operator=(const iterator&)
    index = other.index;
    itsringbuffer = other.itsringbuffer;
    return *this;
    //#]
}

template <class t> inline bool ringbuffer<t>::iterator::operator==(const iterator& other) const {
    //#[ operation operator==(const iterator&) const
    return (index == other.index);
    //#]
}

#endif
/*********************************************************************
	file path	: ../src/app/rpy_generated/ringbuffer.h
*********************************************************************/
