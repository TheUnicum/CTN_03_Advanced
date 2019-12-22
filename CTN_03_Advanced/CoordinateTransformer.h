#pragma once
#include <vector>
#include "Vec2.h"
#include "Graphics.h"

class CoordinateTransformer
{
public:
	CoordinateTransformer(Graphics& gfx)
		:
		gfx(gfx)
	{}
	void DrawClosedPolyline(std::vector<Vec2> poly, Color c)
	{
		Vec2 offset = { float(Graphics::ScreenHeight / 2), float(Graphics::ScreenHeight / 2) };
		for (auto& v : poly)
		{
			v.y *= -1;	// FLIP the y axis direction
			v += offset;
		}
		gfx.DrawClosedPolyline(poly, c);
	}
private:
	Graphics& gfx;
};
