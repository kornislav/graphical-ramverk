#include <Math/Vector2.hpp>
#include <Math/Math.hpp>

void grv::v2::Lerp(const v2& start, const v2& end, const f32 fraction)
{
	x = math::Clamp(start.x + (end.x - start.x) * fraction, start.x, end.x);
	y = math::Clamp(start.y + (end.y - start.y) * fraction, start.y, end.y);
}

void grv::v2::LerpUnclamped(const v2& start, const v2& end, const f32 fraction)
{
	x = start.x + (end.x - start.x) * fraction;
	y = start.y + (end.y - start.y) * fraction;
}