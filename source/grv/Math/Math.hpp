#pragma once

#include <System.hpp>

namespace grv
{
	namespace math
	{
		f32 Clamp(const f32 value, const f32 min, const f32 max)
		{
			return (value < min) ? min : (value > max) ? max : value;
		}
	}
}