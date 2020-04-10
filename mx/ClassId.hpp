#pragma once

#include <matrix.h>

#include <cstdint>


namespace mx
{
	template <typename T>
	mxClassID constexpr classId();

	
	template <>
	inline mxClassID constexpr classId<std::uint32_t>()
	{
		return mxUINT32_CLASS;
	};


	template <>
	inline mxClassID constexpr classId<std::int32_t>()
	{
		return mxINT32_CLASS;
	};


	template <>
	inline mxClassID constexpr classId<double>()
	{
		return mxDOUBLE_CLASS;
	};
}