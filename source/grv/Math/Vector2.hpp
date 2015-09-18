#pragma once

#include <System.hpp>

namespace grv
{
	class v2
	{
	public:
		v2();
		v2(const f32 scalar)			: x(scalar), y(scalar) {}
		v2(const f32 X, const f32 Y)	: x(X), y(Y) {}
		v2(const v2& in)				: x(in.x), y(in.y) {}

		~v2();

		f32 x;
		f32 y;

		// Assignment

		v2& operator= (const v2& in)
		{
			x = in.x;
			y = in.y;
			return *this;
		}

		// Addition

		v2 operator+ (const v2& in) const
		{
			return v2(x + in.x, y + in.y);
		}

		v2 operator+ (const f32 scalar) const
		{
			return v2(x + scalar, y + scalar);
		}

		// Subtraction

		v2 operator- (const v2& in) const
		{
			return v2(x - in.x, y - in.y);
		}

		v2 operator- (const f32 scalar) const
		{
			return v2(x - scalar, y - scalar);
		}

		// Multiplication

		v2 operator* (const v2& in) const
		{
			return v2(x * in.x, y * in.y);
		}

		v2 operator* (const f32 scalar) const
		{
			return v2(x * scalar, y * scalar);
		}

		// Division

		v2 operator/ (const v2& in) const
		{
			return v2(x / in.x, y / in.y);
		}

		v2 operator/ (const f32 scalar) const
		{
			return v2(x / scalar, y / scalar);
		}

		// Addition assignment

		v2& operator+= (const v2& in)
		{
			x += in.x;
			y += in.y;
			return *this;
		}

		v2& operator+= (const f32 scalar)
		{
			x += scalar;
			y += scalar;
			return *this;
		}

		// Subtraction assignment

		v2& operator-= (const v2& in)
		{
			x -= in.x;
			y -= in.y;
			return *this;
		}

		v2& operator-= (const f32 scalar)
		{
			x -= scalar;
			y -= scalar;
			return *this;
		}

		// Multiplication assignment

		v2& operator*= (const v2& in)
		{
			x *= in.x;
			y *= in.y;
			return *this;
		}

		v2& operator*= (const f32 scalar)
		{
			x *= scalar;
			y *= scalar;
			return *this;
		}

		// Division assignment

		v2& operator/= (const v2& in)
		{
			x /= in.x;
			y /= in.y;
			return *this;
		}

		v2& operator/= (const f32 scalar)
		{
			x /= scalar;
			y /= scalar;
			return *this;
		}

		// Equal to

		bool operator== (const v2& in) const
		{
			return (x == in.x && y == in.y);
		}

		bool operator== (const f32 scalar) const
		{
			return (x == scalar && y == scalar);
		}

		// Not equal to

		bool operator!= (const v2& in) const
		{
			return (x != in.x && y != in.y);
		}

		bool operator!= (const f32 scalar) const
		{
			return (x != scalar && y != scalar);
		}

		// Component subscript accessor
		f32& operator[] (const u32 index) { assert(index < 2, "Index is out of bounds!"); return (f32&)*(&x + index); }

		const f32& operator[] (const u32 index) const { assert(index < 2, "Index is out of bounds!"); return (f32&)*(&x + index); }

		// Mathematical functions

		/**
		* Squares this vector
		* \return A reference to this vector
		*/
		v2& Square()
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
		v2& Square(const v2& in)
		{
			x = in.x * in.x;
			y = in.y * in.y;
			return *this;
		}

		/**
		* Calculates the Reciprocal of this vector
		* \return A reference to this vector
		*/
		v2& Reciprocal()
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
		v2& Reciprocal(const v2& in)
		{
			x = 1.0f / in.x;
			y = 1.0f / in.y;
			return *this;
		}

		/**
		* Calculates the Dot Product of this vector
		* \return The dot product of this vector with itself
		*/
		f32 DotProduct() const
		{
			return (x * x) + (y * y);
		}

		/**
		* Calculates the Dot Product of this vector and in
		* \param in A reference to the vector that will be dotted with this vector
		* \return The dot product of in and this vector
		*/
		f32 DotProduct(const v2& in) const
		{
			return (x * in.x) + (y * in.y);
		}

		/**
		* Checks if this vector is between min and max
		* \param min A reference to the vector that is the minimum allowed vector
		* \param max A reference to the vector that is the maximum allowed vector
		* \return true if this vector is between min and max, false otherwise
		*/
		bool Between(const v2& min, const v2&max) const
		{
			return ((x > min.x && y > min.y) && (x < max.x && y < max.y));
		}

		/**
		* Calculates the Length of this vector
		* \return The length of this vector
		*/
		f32 Magnitude() const
		{
			return sqrt((x*x + y*y));
		}

		/**
		* Calculates the Squared Length of this vector
		* \return The squared length of this vector
		*/
		f32 SqrMagnitude() const
		{
			return DotProduct();
		}

		/**
		* Normalizes this vector
		*/
		void Normalize()
		{
			f32 length = this->Magnitude();
			x /= length;
			y /= length;
		}

		/**
		* Normalizes this vector
		* \return The length of this vector
		*/
		v2 Normalized()
		{
			f32 length = this->Magnitude();
			return v2(x / length, y / length);
		}

		void Lerp(const v2& start, const v2& end, const f32 fraction);
		void LerpUnclamped(const v2& start, const v2& end, const f32 fraction);



	private:


	};

}