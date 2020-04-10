#pragma once

#include <mat/Forward.hpp>

#include <matrix.h>

#include <memory>


namespace mx
{
    class Array
    {
        friend class StructArray;
        friend class ::mat::MatFile;


    protected:
        explicit Array(mxArray * arr) noexcept
        :   array_{arr}
        {
        }


        mxArray * get() noexcept
        {
            return array_.get();
        }


        mxArray const * get() const noexcept
        {
            return array_.get();
        }


        mxArray * release() noexcept
        {
            return array_.release();
        }
        

    private:
        struct DestroyArray
        {
            void operator()(mxArray * p)
            {
                mxDestroyArray(p);
            }
        };


        std::unique_ptr<mxArray, DestroyArray> array_;
    };
}