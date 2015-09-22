#pragma once

#include <System.hpp>
#include "Math.hpp"

namespace grv
{
	class v2
	{
	public:
		API v2() : x(0), y(0) {}
		API v2(const f32 scalar) : x(scalar), y(scalar) {}
		API v2(const f32 X, const f32 Y) : x(X), y(Y) {}
		API v2(const v2& in) : x(in.x), y(in.y) {}

		API ~v2() {}

		f32 x;
		f32 y;

		// Assignment

		API v2& operator= (const v2& in)
		{
			x = in.x;
			y = in.y;
			return *this;
		}

		// Addition

		API v2 operator+ (const v2& in) const
		{
			return v2(x + in.x, y + in.y);
		}

		API v2 operator+ (const f32 scalar) const
		{
			return v2(x + scalar, y + scalar);
		}

		// Subtraction

		API v2 operator- (const v2& in) const
		{
			return v2(x - in.x, y - in.y);
		}

		API v2 operator- (const f32 scalar) const
		{
			return v2(x - scalar, y - scalar);
		}

		// Multiplication

		API v2 operator* (const v2& in) const
		{
			return v2(x * in.x, y * in.y);
		}

		API v2 operator* (const f32 scalar) const
		{
			return v2(x * scalar, y * scalar);
		}

		// Division

		API v2 operator/ (const v2& in) const
		{
			return v2(x / in.x, y / in.y);
		}

		API v2 operator/ (const f32 scalar) const
		{
			return v2(x / scalar, y / scalar);
		}

		// Addition assignment

		API v2& operator+= (const v2& in)
		{
			x += in.x;
			y += in.y;
			return *this;
		}

		API v2& operator+= (const f32 scalar)
		{
			x += scalar;
			y += scalar;
			return *this;
		}

		// Subtraction assignment

		API v2& operator-= (const v2& in)
		{
			x -= in.x;
			y -= in.y;
			return *this;
		}

		API v2& operator-= (const f32 scalar)
		{
			x -= scalar;
			y -= scalar;
			return *this;
		}

		// Multiplication assignment

		API v2& operator*= (const v2& in)
		{
			x *= in.x;
			y *= in.y;
			return *this;
		}

		API v2& operator*= (const f32 scalar)
		{
			x *= scalar;
			y *= scalar;
			return *this;
		}

		// Division assignment

		API v2& operator/= (const v2& in)
		{
			x /= in.x;
			y /= in.y;
			return *this;
		}

		API v2& operator/= (const f32 scalar)
		{
			x /= scalar;
			y /= scalar;
			return *this;
		}

		// Equal to

		API bool operator== (const v2& in) const
		{
			return (x == in.x && y == in.y);
		}

		API bool operator== (const f32 scalar) const
		{
			return (x == scalar && y == scalar);
		}

		// Not equal to

		API bool operator!= (const v2& in) const
		{
			return (x != in.x && y != in.y);
		}

		API bool operator!= (const f32 scalar) const
		{
			return (x != scalar && y != scalar);
		}

		// Component subscript accessor
		API f32& operator[] (const u32 index) { assert(index < 2, "Index is out of bounds!"); return (f32&)*(&x + index); }

		API const f32& operator[] (const u32 index) const { assert(index < 2, "Index is out of bounds!"); return (f32&)*(&x + index); }

		// Mathematical functions

		/**
		* Squares this vector
		* \return A reference to this vector
		*/
		API v2& Square()
		{
			x *= x;
			y *= y;
			return *this;
		}

		/**
		* Squares in and stores the result into this vector
		* \param in A reference to the vector that will be squared
		* \return A reference to this vector
		*/
		API v2& Square(const v2& in)
		{
			x = in.x * in.x;
			y = in.y * in.y;
			return *this;
		}

		/**
		* Calculates the Reciprocal of this vector
		* \return A reference to this vector
		*/
		API v2& Reciprocal()
		{
			x = 1.0f / x;
			y = 1.0f / y;
			return *this;
		}

		/**
		* Calculates the Reciprocal of in and stores the result in this vector
		* \param in A reference to the vector that will be Reciprocated
		* \return A reference to this vector
		*/
		API v2& Reciprocal(const v2& in)
		{
			x = 1.0f / in.x;
			y = 1.0f / in.y;
			return *this;
		}

		/**
		* Calculates the Dot Product of this vector
		* \return The dot product of this vector with itself
		*/
		API f32 DotProduct() const
		{
			return (x * x) + (y * y);
		}

		/**
		* Calculates the Dot Product of this vector and in
		* \param in A reference to the vector that will be dotted with this vector
		* \return The dot product of in and this vector
		*/
		API f32 DotProduct(const v2& in) const
		{
			return (x * in.x) + (y * in.y);
		}

		/**
		* Checks if this vector is between min and max
		* \param min A reference to the vector that is the minimum allowed vector
		* \param max A reference to the vector that is the maximum allowed vector
		* \return true if this vector is between min and max, false otherwise
		*/
		API bool Between(const v2& min, const v2&max) const
		{
			return ((x > min.x && y > min.y) && (x < max.x && y < max.y));
		}

		/**
		* Calculates the Length of this vector
		* \return The length of this vector
		*/
		API f32 Magnitude() const
		{
			return sqrt((x*x + y*y));
		}

		/**
		* Calculates the Squared Length of this vector
		* \return The squared length of this vector
		*/
		API f32 SqrMagnitude() const
		{
			return DotProduct();
		}

		/**
		* Normalizes this vector
		*/
		API void Normalize()
		{
			f32 length = this->Magnitude();
			x /= length;
			y /= length;
		}

		/**
		* Normalizes this vector
		* \return The length of this vector
		*/
		API v2 Normalized()
		{
			f32 length = this->Magnitude();
			return v2(x / length, y / length);
		}
		
		// Static functions
		API static const v2 One;
		API static const v2 Zero;
		API static const v2 Up;
		API static const v2 Down;
		API static const v2 Right;
		API static const v2 Left;

		API static v2 Clamp(const v2& value, const v2& min, const v2& max)
		{
			return v2((value.x < min.x) ? min.x : (value.x > max.x) ? max.x : value.x, (value.y < min.y) ? min.y : (value.y > max.y) ? max.y : value.y);
		}

		API static v2 Lerp(const v2& start, const v2& end, const f32 fraction)
		{
			return Clamp(start + (end - start) * fraction, start, end);
		}

		API static v2 LerpUnclamped(const v2& start, const v2& end, const f32 fraction)
		{
			return start + (end - start) * fraction;
		}
		
		API static v2 Coserp(const v2& start, const v2& end, const f32 fraction)
		{
			return Lerp(start, end, cos(fraction * PI * 0.5f));
		}

	private:


	};


}