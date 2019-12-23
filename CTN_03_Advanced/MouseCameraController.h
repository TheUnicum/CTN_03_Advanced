#pragma once
#include "Camera.h"
#include "Mouse.h"

class MouseCameraController
{
public:
	MouseCameraController(Mouse& mouse, Camera& cam)
		:
		mouse(mouse),
		cam(cam)
	{}
	void Update()
	{
		while (!mouse.IsEmpty())
		{
			const auto e = mouse.Read();
			switch (e.GetType())
			{
			case Mouse::Event::Type::LPress:
				engaged = true;
				lastPos = (Vec2)e.GetPos();
				break;
			case Mouse::Event::Type::LRelease:
				engaged = false;
				break;
			case Mouse::Event::Type::WheelUp:
				cam.SetScale(cam.GetScale() * zoomFactor);
				break;
			case Mouse::Event::Type::WheelDown:
				cam.SetScale(cam.GetScale() / zoomFactor);
				break;
			}
		}

		if (engaged)
		{
			const auto curPos = (Vec2)mouse.GetPos();
			auto delta = curPos - lastPos;
			delta.x = -delta.x;
			cam.MoveBy(delta);
			lastPos = curPos;
		}
	}
private:
	static constexpr float zoomFactor = 1.05;
	bool engaged = false;
	Vec2 lastPos;
	Mouse& mouse;
	Camera& cam;
};
