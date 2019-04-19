// File "Array2.hpp" created April 2019
// Copyright (c) Lion Kortlepel 2019
// Licensed under MIT
#ifndef TEMPION_ARRAY2_HPP
#define TEMPION_ARRAY2_HPP

#include <array>

namespace tp
{
    template<typename T, std::size_t columns, std::size_t rows>
    class Array2
    {
    private:
        std::array<std::array<T, rows>, columns> raw;
    public:
        Array2 () = default;
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
    };
}


#endif //TEMPION_ARRAY2_HPP
