#pragma once

#include <boost/exception/all.hpp>

#include <stdexcept>


namespace mat
{
    struct Exception
    :   std::runtime_error
    ,   virtual boost::exception
    {
        Exception()
        :   std::runtime_error("MATLAB MAT-file API has returned an error")
        {
        }


        Exception(Exception const&) = default;
        Exception(Exception &&) = default;
    };
}