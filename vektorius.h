#include <iostream>
#include <memory>
#include <algorithm>
// #include <vector>
#include <chrono>

using std::allocator;
using std::cin;
using std::copy;
using std::cout;
using std::endl;
using std::max;
using std::vector;

using std::uninitialized_copy;
using std::uninitialized_fill;
using hrClock = std::chrono::high_resolution_clock;

template <class T>
class Vektorius
{
public:
    typedef T *iterator;
    typedef const T *const_iterator;
    typedef size_t size_type;
    typedef T value_type;

    Vektorius() { create(); }
    explicit Vektorius(size_type n, const T &val = T()) { create(n, val); }
    Vektorius(const Vektorius &v) { create(v.begin(), v.end()); } // copy construct
    ~Vektorius() { uncreate(); }

    Vektorius &operator=(const Vektorius &rhs)
    {
        if (&rhs != this)
        {
            uncreate();
            create(rhs.begin(), rhs.end());
        }
        return *this;
    } // assignment
    T &operator[](size_type i) { return data[i]; }
    const T &operator[](size_type i) const { return data[i]; }

    iterator begin() { return data; }
    const_iterator begin() const { return data; }
    iterator end() { return limit; }
    const_iterator end() const { return limit; }
    size_type size() const { return (avail - data); }
    size_type capacity() const { return (limit - data); }

    void push_back(const T &val)
    {
        if (avail == limit)
            grow();
        unchecked_append(val);
    }
    bool empty()
    {
        if (data == limit)
            return true;
        else
            return false;
    }
    void reserve(size_type n)
    {
        if (n >= this->size())
        {
            size_type new_size = n; // max( 2 * n , ptrdiff_t(1)); //max(2 * (limit - data), ptrdiff_t(1));
            iterator new_data = alloc.allocate(new_size);
            iterator new_avail = uninitialized_copy(data, avail, new_data);
            uncreate();
            data = new_data;
            avail = new_avail;
            limit = data + new_size;
            ++reallocationCount;
        }
    }
    void shrink_to_fit() { limit = avail; }
    void clear() { uncreate(); }
    void resize(size_type n)
    {
        if (n == size())
            return;
        if (n < size())
        {
            iterator new_avail = data + n;
            while (avail != new_avail)
                std::allocator_traits<allocator<T>>::destroy(alloc, --avail);
            avail = new_avail;
        }
        else
        {
            if (n > capacity())
                reserve(n);
            for (size_type i = size(); i < n; ++i)
                unchecked_append(T());
        }
    }
    iterator erase(iterator position)
    {
        if (position >= data && position < avail)
        {
            iterator next = position + 1;
            std::copy(next, avail, position);
            std::allocator_traits<allocator<T>>::destroy(alloc, avail - 1);
            --avail;
            return position;
        }
        return avail; // If position is invalid, return end iterator
    }
    void pop_back()
    {
        if (size() > 0)
        {
            --avail;
            std::allocator_traits<allocator<T>>::destroy(alloc, avail);
        }
    }

    int getReallocationCount() const {
        return reallocationCount;
    }

private:
    iterator data;
    iterator limit;
    iterator avail;
    allocator<T> alloc;
    int reallocationCount = 0;

    void create()
    {
        data = avail = limit = nullptr;
    }
    void create(size_type n, const T &val)
    {
        data = alloc.allocate(n);
        limit = avail = data + n;
        uninitialized_fill(data, limit, val);
    }
    void create(const_iterator i, const_iterator j)
    {
        data = alloc.allocate(j - i);
        limit = avail = uninitialized_copy(i, j, data);
    }
    void uncreate()
    {
        if (data)
        {
            iterator it = avail;
            while (it != data)
                std::allocator_traits<allocator<T>>::destroy(alloc, --it); // alloc.destroy(--it);
            alloc.deallocate(data, limit - data);
        }
        data = limit = avail = nullptr;
    }
    void grow()
    {
        size_type new_size = max(2 * (limit - data), ptrdiff_t(1));
        iterator new_data = alloc.allocate(new_size);
        iterator new_avail = uninitialized_copy(data, avail, new_data);
        uncreate();
        data = new_data;
        avail = new_avail;
        limit = data + new_size;
        ++reallocationCount;
    }
    void unchecked_append(const T &val) { std::allocator_traits<allocator<T>>::construct(alloc, avail++, val); }
};