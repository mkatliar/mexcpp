#pragma once

#include <mx/Array.hpp>

#include <string>


namespace mx
{
    class String
    :   public Array
    {
    public:
        String(char const * str)
        :   Array {mxCreateString(str)}
        {
        }


        String(std::string const& str)
        :   Array {mxCreateString(str.c_str())}
        {
        }
        

    private:
    };
}