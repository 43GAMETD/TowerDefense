#pragma once

#include "sga.hpp"
#include "enemy.h"

class Alpha : public MainWindow<Alpha>
{
	typedef Alpha Me;
	typedef MainWindow<Alpha> Base;
public :
	Alpha()
	{
	}
	~Alpha()
	{
	}
protected :
	void SetEventMap()
	{
		AddEventHandler(WM_CREATE, &Me::OnCreate);
		AddEventHandler(WM_DESTROY, &Me::OnDestroy);
		AddEventHandler(WM_PAINT, &Me::OnPaint);
		AddEventHandler(WM_TIMER, &Me::OnTimer);
	}
	LRESULT OnCreate(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		enemy.Draw(hdc);
		return 0;
	}
	LRESULT OnDestroy(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		::PostQuitMessage(0);

		return 0;
	}
	LRESULT OnPaint(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		enemy.Move();
		return 0;
	}
	LRESULT OnTimer(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		return 0;
	}
	
	
	
private :
	HWND hWnd;
	RECT rcClient;
	HDC hdc;

	Enemy enemy;
};