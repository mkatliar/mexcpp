#pragma once

#include <mx/Array.hpp>
#include <mx/ClassId.hpp>

#include <complex>


namespace mx
{
    template <typename T>
    class NumericArray
    :   public Array
    {
    public:
        NumericArray(Array&& rhs);
        NumericArray(mwSize m, mwSize n);
        
        T * data();
        T const * data() const;
        

    private:
    };


    template <typename T>
    class NumericArray<std::complex<T>>
    :   public Array
    {
    public:
        NumericArray(Array&& rhs);
        NumericArray(mwSize m, mwSize n);
        
        std::complex<T> * data();
        std::complex<T> const * data() const;
        

    private:
    };


    template <typename T>
    inline NumericArray<T>::NumericArray(Array&& rhs)
    :   Array {std::move(rhs)}
    {
    }


    template <typename T>
    inline NumericArray<T>::NumericArray(mwSize m, mwSize n)
    :   Array {mxCreateNumericMatrix(m, n, classId<T>(), mxREAL)}
    {
    }


    template <typename T>
    inline NumericArray<std::complex<T>>::NumericArray(mwSize m, mwSize n)
    :   Array {mxCreateNumericMatrix(m, n, classId<T>(), mxCOMPLEX)}
    {
    }


    template <>
    inline mxDouble * NumericArray<mxDouble>::data()
    {
        return mxGetDoubles(get());
    }


    template <>
    inline mxDouble const * NumericArray<mxDouble>::data() const
    {
        return mxGetDoubles(get());
    }
}