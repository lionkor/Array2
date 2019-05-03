// File "Array2.hpp" created April 2019
// Copyright (c) Lion Kortlepel 2019
// Licensed under MIT
#ifndef TEMPION_ARRAY2_HPP
#define TEMPION_ARRAY2_HPP

#include <array>
#include <iterator>

namespace tp
{
    template<typename T, std::size_t columns, std::size_t rows>
    class Array2;
    
    template<typename T, std::size_t columns, std::size_t rows>
    class ArrayIterator;
    
    template<typename T, std::size_t columns, std::size_t rows>
    class Array2
    {
    private:
        std::array<std::array<T, rows>, columns> raw;
    public:
        Array2 ()
        {
            raw = std::array<std::array<T, rows>, columns> ();
        }
        ~Array2 () = default;
        
        std::array<std::array<T, rows>, columns>& get ()
        {
            return raw;
        }
        
        std::array<std::array<T, rows>, columns> get () const 
        {
            return raw;
        }
        
        std::array<T, rows>& operator[] (const std::size_t x_index)
        {
            return raw[x_index];
        }
        
        std::array<T, rows> operator[] (const std::size_t x_index) const 
        {
            return raw[x_index];
        }
        
        T& at (const std::size_t x, const std::size_t y)        
        {
            return raw.at (x).at (y);
        }
        
        T at (const std::size_t x, const std::size_t y) const 
        {
            return raw.at (x).at (y);
        }
        
        void fill (const T& value)
        {
            for (std::array<T, rows>& row : raw)
            {
                row.fill (value);
            }
        }
    
        ArrayIterator<T, columns, rows> begin ()
        {
            return ArrayIterator<T, columns, rows> (this);
        }
    
        ArrayIterator<T, columns, rows> end ()
        {
            return ArrayIterator<T, columns, rows>::end (this);
        }
    };
    
    template<typename T, std::size_t columns, std::size_t rows>
    class ArrayIterator : public std::iterator<std::input_iterator_tag, Array2<T, columns, rows>>
    {
    private:
        int x_index;
        int y_index;
        mutable Array2<T, columns, rows>* arr;
    
        ArrayIterator (Array2<T, columns, rows>* arr, int x, int y)
                : arr (std::move (arr)), x_index (x), y_index (y)
        {}
        
    public:
        ArrayIterator (Array2<T, columns, rows>* arr)
            : arr (std::move (arr)), x_index (0), y_index (0)
        {}
        
        static ArrayIterator<T, columns, rows> end (Array2<T, columns, rows>* arr)
        {
            return ArrayIterator<T, columns, rows> (arr, columns - 1, rows - 1);
        }
        
        T& operator* () const
        {
            return arr->at (x_index, y_index);
        }
        
        T* operator-> () const 
        {
            return &arr->at (x_index, y_index);
        }
        
        bool operator== (const ArrayIterator& rhs)
        {
            return x_index == rhs.x_index && y_index == rhs.y_index; 
        }
        
        bool operator!= (const ArrayIterator& rhs)
        {
            return !(*this == rhs);
        }
        
        void operator++ ()
        {
            ++x_index;
            if (x_index == columns)
            {
                x_index = 0;
                ++y_index;
            }
        }
        
        void operator-- ()
        {
            
        }
    };
}


#endif //TEMPION_ARRAY2_HPP
