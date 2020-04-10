#pragma once

#include <mx/Array.hpp>
#include <mx/ClassId.hpp>

#include <initializer_list>


namespace mx
{
    class StructArray
    :   public Array
    {
    public:
        StructArray(std::initializer_list<mwSize> dims, std::initializer_list<char const *> fieldnames)
        :   Array {mxCreateStructArray(dims.size(), dims.begin(), fieldnames.size(), const_cast<char const **>(fieldnames.begin()))}
        {
        }


        void setField(mwIndex index, char const * fieldname, Array&& value)
        {
            mxSetField(get(), index, fieldname, value.release());
        }
        

    private:
    };
}