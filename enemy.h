#pragma once

class Enemy
{
public :
	Enemy()
		:x(10), y(50)
	{
		::GetClientRect(hWnd, &rcClient);
	}
	~Enemy()
	{
	}
	void Draw(HDC hdc)
	{
		hdc = ::BeginPaint(hWnd, &ps);
		::Ellipse(hdc, x-10, y-10, x+10, y+10);
		::EndPaint(hWnd, &ps);
	}
	void Move()
	{
		x += 10;
		if(x + 20 > rcClient.right) 
		{
			x = rcClient.right - 10;
			y += 10;

		}
		if(y + 20 > rcClient.bottom)
		{
			x -= 10;
			y = rcClient.bottom - 10;
		}
		
		::InvalidateRgn(hWnd, NULL, TRUE);
	}
private :
	HWND hWnd;
	PAINTSTRUCT ps;
	RECT rcClient;

	int x;
	int y;
};
