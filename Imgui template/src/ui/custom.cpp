#include "main.h"

void custom::style() {
	auto& style = ImGui::GetStyle();

	style.WindowRounding = 10.f;
	style.WindowPadding = ImVec2(0, 0);
	style.WindowBorderSize = 0.f;
}

void custom::move_window() {
	RECT rc;

	GetWindowRect(hwnd, &rc);
	MoveWindow(hwnd, rc.left + ImGui::GetWindowPos().x, rc.top + ImGui::GetWindowPos().y, window::size.x, window::size.y, TRUE);
	ImGui::SetWindowPos({ 0, 0 });
}

void custom::set_blur(HWND hwnd) {
	struct ACCENTPOLICY
	{
		int na;
		int nf;
		int nc;
		int nA;
	};
	struct WINCOMPATTRDATA
	{
		int na;
		PVOID pd;
		ULONG ul;
	};

	const HINSTANCE hm = LoadLibrary(L"user32.dll");
	if (hm)
	{
		typedef BOOL(WINAPI* pSetWindowCompositionAttribute)(HWND, WINCOMPATTRDATA*);

		const pSetWindowCompositionAttribute SetWindowCompositionAttribute = (pSetWindowCompositionAttribute)GetProcAddress(hm, "SetWindowCompositionAttribute");
		if (SetWindowCompositionAttribute)
		{
			ACCENTPOLICY policy = { 3, 0, 0, 0 }; // 4,0,155,0 (Acrylic blur) 3,0,0,0 
			WINCOMPATTRDATA data = { 19, &policy,sizeof(ACCENTPOLICY) };
			SetWindowCompositionAttribute(hwnd, &data);
		}
		FreeLibrary(hm);
	}
}
