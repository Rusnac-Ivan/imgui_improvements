#ifndef _IMGUI_IMPROVEMENTS_
#define _IMGUI_IMPROVEMENTS_

#include <imgui.h>

namespace ImGui
{
    bool ColoredButtonV1(const char* label, const ImVec2& size, ImU32 text_color, ImU32 bg_color_1, ImU32 bg_color_2);

    bool BeginEx(const char* name, bool* p_open, ImGuiWindowFlags flags);
}

#endif _IMGUI_IMPROVEMENTS_