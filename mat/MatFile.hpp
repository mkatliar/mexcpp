#pragma once

#include <mat/Exception.hpp>

#include <mx/Array.hpp>

#include <matrix.h>
#include <mat.h>

#include <memory>


namespace mat
{
    class MatFile
    {
    public:
        MatFile(char const * filename, char const * mode)
        :   file_{matOpen(filename, mode)}
        {
        }


        void putVariable(char const * name, mx::Array const& pm)
        {
            auto const ret = matPutVariable(file_.get(), name, pm.get());

            if (ret != 0)
                BOOST_THROW_EXCEPTION(Exception {} << boost::errinfo_api_function("matPutVariable"));
        }


    private:
        struct MatClose
        {
            void operator()(MATFile * f)
            {
                matClose(f);
            }
        };


        std::unique_ptr<MATFile, MatClose> file_;
    };
}