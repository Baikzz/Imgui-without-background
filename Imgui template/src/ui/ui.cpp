#include "main.h"

void ui::before_loop() {
	auto& io = ImGui::GetIO();
	io.IniFilename = NULL;
	
	custom::style();
	custom::set_blur(hwnd);
}

void ui::render() {
	DWORD window_flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar;
	ImVec4 window_bg = ImColor(3, 3, 3, 100);
	ImVec2 text_size = ImGui::CalcTextSize("Hello world without background!");

	ImGui::PushStyleColor(ImGuiCol_WindowBg, window_bg);
	ImGui::Begin("Test", NULL, window_flags); 
	{
		ImGui::SetWindowSize(window::size);
		custom::move_window();

		ImGui::SetCursorPos({ (window::size.x - text_size.x) / 2, 30 });
		ImGui::Text("Hello world without background!");
	}
	ImGui::End();
	ImGui::PopStyleColor();
}