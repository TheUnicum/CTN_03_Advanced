#pragma once

#include "Graphics.h"
#include <vector>
#include "Vec2.h"

class Drawable
{
public:
	Drawable(const std::vector<Vec2>& model, Color c)
		:
		c(c),
		model(&model)
	{}
	void ApplyTransformation(const Mat3& transformatrion_in)
	{
		transformation = transformatrion_in *transformation;
	}
	void Render(Graphics& gfx) const
	{
		gfx.DrawClosedPolyline(*model, transformation, c);
	}
private:
	Color c;
	const std::vector<Vec2>* model;
	Mat3 transformation = Mat3::Identity();
};
