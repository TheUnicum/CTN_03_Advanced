/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
}

void Game::ComposeFrame()
{
	if (wnd.mouse.LeftIsPressed())
	{
		gfx.DrawLine({ 50.0f, 50.0f }, (Vec2)wnd.mouse.GetPos(), Colors::Yellow);
	}
}

/*
(6:28) Plot a line from y = mx + b
https://www.mathsisfun.com/data/straight_line_graph.html

(31:07) Rasterization Rules
https://docs.microsoft.com/en-us/windows/win32/direct3d11/d3d10-graphics-programming-guide-rasterizer-stage-rules
(31:29) Bresenham's line algorithm
https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm

T-Q1-Q4
(9:14)
https://www.desmos.com/calculator

T-Q5-Q8
(3:30)  m' = - 1 / m (perpendicular)

T-Q9-Q12
d = |Am+Bn+C| / sqrt(A^2 + B^2)
https://www.intmath.com/plane-analytic-geometry/perpendicular-distance-point-line.php

*/
