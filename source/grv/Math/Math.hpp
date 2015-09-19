#pragma once

#include <System.hpp>

namespace grv
{
	namespace math
	{
#define PI 3.14159265358979323846f
#define TAU 6.2831853071795864769f
#define CIRCLE_MIN_DEGREES 0.0f
#define CIRCLE_HALF_DEGREES 180.0f
#define CIRCLE_MAX_DEGREES 360.0f

		f32 Clamp(const f32 value, const f32 min, const f32 max)
		{
			return (value < min) ? min : (value > max) ? max : value;
		}

		f32 Clamp(const f32 value)
		{
			return (value < 0.0f) ? 0.0f : (value > 1.0f) ? 1.0f : value;
		}

		f32 Lerp(const f32 start, const f32 end, const f32 fraction)
		{
			return ((1.0f - fraction) * start) + (fraction * end);
		}

		f32 Hermite(const f32 start, const f32 end, const f32 fraction)
		{
			return Lerp(start, end, fraction * fraction * (3.0f - 2.0f * fraction));
		}

		f32 Sinerp(const f32 start, const f32 end, const f32 fraction)
		{
			return Lerp(start, end, sin(fraction * PI * 0.5f));
		}

		f32 Coserp(const f32 start, const f32 end, const f32 fraction)
		{
			return Lerp(start, end, cos(fraction * PI * 0.5f));
		}

		f32 Cubic(const f32 y0, const f32 y1, const f32 y2, const f32 y3, const f32 fraction)
		{
			f32 a0, a1, a2, a3;

			a0 = y3 - y2 - y0 + y1;
			a1 = y0 - y1 - a0;
			a2 = y2 - y0;
			a3 = y1;

			return ((a0 * fraction * fraction * fraction) + (a1 * fraction * fraction) + (a2 * fraction) + a3);
		}

		f32 Berp(const f32 start, const f32 end, f32 fraction)
		{
			fraction = Clamp(fraction);
			fraction = (sin(fraction * PI * (0.2f + 2.5f * fraction * fraction * fraction)) * pow(1.0f - fraction, 2.2f) + fraction) * (1.0f + (1.2f * (1.0f - fraction)));
			return start + (end - start) * fraction;
		}

		f32 SmoothStep(f32 x, const f32 min, const f32 max)
		{
			x = Clamp((x - min)/(max - min), 0.0f, 1.0f);
			return x*x*(3 - 2 * x);
		}

		f32 Clerp(const f32 start, const f32 end, const f32 fraction)
		{
			f32 returnValue = 0.0f;
			f32 diff = 0.0f;

			if ((end - start) < -CIRCLE_HALF_DEGREES)
			{
				diff = ((CIRCLE_MAX_DEGREES - start) + end) * fraction;
				returnValue = start + diff;
			}
			else if ((end - start) > CIRCLE_HALF_DEGREES)
			{
				diff = -((CIRCLE_MAX_DEGREES - end) + start) * fraction;
				returnValue = start + diff;
			}
			else
			{
				returnValue = start + (end - start) * fraction;
			}
			return returnValue;
		}
	
		f32 Bounce(const f32 x)
		{
			return abs(sin(TAU * (x + 1.0f) * (x + 1.0f)) * (1.0f - x));
		}
	}
}