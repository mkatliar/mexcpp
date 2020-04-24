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


    public:
        auto getM() const noexcept
        {
            return mxGetM(get());
        }


        auto getN() const noexcept
        {
            return mxGetN(get());
        }


        auto getNumberOfDimensions() const noexcept
        {
            return mxGetNumberOfDimensions(get());
        }


        auto getNumberOfElements() const noexcept
        {
            return mxGetNumberOfElements(get());
        }


    protected:
        Array(Array&&) = default;


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