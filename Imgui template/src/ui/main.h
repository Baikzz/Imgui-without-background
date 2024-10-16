#pragma once
#define IMGUI_DEFINE_MATH_OPERATORS

#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"

#include <windows.h>
#include <dwmapi.h>
#include <d3d11.h>
#include <tchar.h>

extern HWND hwnd;

namespace ui {
	void render();
	void before_loop();
}

namespace window {
	inline ImVec2 size = { 600, 700 };
}

namespace custom {
	void style();
	void move_window();
	void set_blur(HWND hwnd);
}