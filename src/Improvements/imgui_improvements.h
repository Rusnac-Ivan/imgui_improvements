#ifndef _IMGUI_IMPROVEMENTS_
#define _IMGUI_IMPROVEMENTS_

#include <imgui.h>

// Enumeration for PushStyleColor() / PopStyleColor()
enum ImGuiColGrad_
{
    ImGuiColGrad_Text_F,
    ImGuiColGrad_Text_S,
    ImGuiColGrad_TextDisabled_F,
    ImGuiColGrad_TextDisabled_S,
    ImGuiColGrad_WindowBg_F,              // Background of normal windows
    ImGuiColGrad_WindowBg_S,              // Background of normal windows
    ImGuiColGrad_ChildBg_F,               // Background of child windows
    ImGuiColGrad_ChildBg_S,               // Background of child windows
    ImGuiColGrad_PopupBg_F,               // Background of popups, menus, tooltips windows
    ImGuiColGrad_PopupBg_S,               // Background of popups, menus, tooltips windows
    ImGuiColGrad_Border_F,
    ImGuiColGrad_Border_S,
    ImGuiColGrad_BorderShadow_F,
    ImGuiColGrad_BorderShadow_S,
    ImGuiColGrad_FrameBg_F,               // Background of checkbox, radio button, plot, slider, text input
    ImGuiColGrad_FrameBg_S,               // Background of checkbox, radio button, plot, slider, text input
    ImGuiColGrad_FrameBgHovered_F,
    ImGuiColGrad_FrameBgHovered_S,
    ImGuiColGrad_FrameBgActive_F,
    ImGuiColGrad_FrameBgActive_S,
    ImGuiColGrad_TitleBg_F,
    ImGuiColGrad_TitleBg_S,
    ImGuiColGrad_TitleBgActive_F,
    ImGuiColGrad_TitleBgActive_S,
    ImGuiColGrad_TitleBgCollapsed_F,
    ImGuiColGrad_TitleBgCollapsed_S,
    ImGuiColGrad_MenuBarBg_F,
    ImGuiColGrad_MenuBarBg_S,
    ImGuiColGrad_ScrollbarBg_F,
    ImGuiColGrad_ScrollbarBg_S,
    ImGuiColGrad_ScrollbarGrab_F,
    ImGuiColGrad_ScrollbarGrab_S,
    ImGuiColGrad_ScrollbarGrabHovered_F,
    ImGuiColGrad_ScrollbarGrabHovered_S,
    ImGuiColGrad_ScrollbarGrabActive_F,
    ImGuiColGrad_ScrollbarGrabActive_S,
    ImGuiColGrad_CheckMark_F,
    ImGuiColGrad_CheckMark_S,
    ImGuiColGrad_SliderGrab_F,
    ImGuiColGrad_SliderGrab_S,
    ImGuiColGrad_SliderGrabActive_F,
    ImGuiColGrad_SliderGrabActive_S,
    ImGuiColGrad_Button_F,
    ImGuiColGrad_Button_S,
    ImGuiColGrad_ButtonHovered_F,
    ImGuiColGrad_ButtonHovered_S,
    ImGuiColGrad_ButtonActive_F,
    ImGuiColGrad_ButtonActive_S,
    ImGuiColGrad_Header_F,                // Header* colors are used for CollapsingHeader, TreeNode, Selectable, MenuItem
    ImGuiColGrad_Header_S,                // Header* colors are used for CollapsingHeader, TreeNode, Selectable, MenuItem
    ImGuiColGrad_HeaderHovered_F,
    ImGuiColGrad_HeaderHovered_S,
    ImGuiColGrad_HeaderActive_F,
    ImGuiColGrad_HeaderActive_S,
    ImGuiColGrad_Separator_F,
    ImGuiColGrad_Separator_S,
    ImGuiColGrad_SeparatorHovered_F,
    ImGuiColGrad_SeparatorHovered_S,
    ImGuiColGrad_SeparatorActive_F,
    ImGuiColGrad_SeparatorActive_S,
    ImGuiColGrad_ResizeGrip_F,
    ImGuiColGrad_ResizeGrip_S,
    ImGuiColGrad_ResizeGripHovered_F,
    ImGuiColGrad_ResizeGripHovered_S,
    ImGuiColGrad_ResizeGripActive_F,
    ImGuiColGrad_ResizeGripActive_S,
    ImGuiColGrad_Tab_F,
    ImGuiColGrad_Tab_S,
    ImGuiColGrad_TabHovered_F,
    ImGuiColGrad_TabHovered_S,
    ImGuiColGrad_TabActive_F,
    ImGuiColGrad_TabActive_S,
    ImGuiColGrad_TabUnfocused_F,
    ImGuiColGrad_TabUnfocused_S,
    ImGuiColGrad_TabUnfocusedActive_F,
    ImGuiColGrad_TabUnfocusedActive_S,
    ImGuiColGrad_PlotLines_F,
    ImGuiColGrad_PlotLines_S,
    ImGuiColGrad_PlotLinesHovered_F,
    ImGuiColGrad_PlotLinesHovered_S,
    ImGuiColGrad_PlotHistogram_F,
    ImGuiColGrad_PlotHistogram_S,
    ImGuiColGrad_PlotHistogramHovered_F,
    ImGuiColGrad_PlotHistogramHovered_S,
    ImGuiColGrad_TableHeaderBg_F,         // Table header background
    ImGuiColGrad_TableHeaderBg_S,         // Table header background
    ImGuiColGrad_TableBorderStrong_F,     // Table outer and header borders (prefer using Alpha=1.0 here)
    ImGuiColGrad_TableBorderStrong_S,     // Table outer and header borders (prefer using Alpha=1.0 here)
    ImGuiColGrad_TableBorderLight_F,      // Table inner borders (prefer using Alpha=1.0 here)
    ImGuiColGrad_TableBorderLight_S,      // Table inner borders (prefer using Alpha=1.0 here)
    ImGuiColGrad_TableRowBg_F,            // Table row background (even rows)
    ImGuiColGrad_TableRowBg_S,            // Table row background (even rows)
    ImGuiColGrad_TableRowBgAlt_F,         // Table row background (odd rows)
    ImGuiColGrad_TableRowBgAlt_S,         // Table row background (odd rows)
    ImGuiColGrad_TextSelectedBg_F,
    ImGuiColGrad_TextSelectedBg_S,
    ImGuiColGrad_DragDropTarget_F,
    ImGuiColGrad_DragDropTarget_S,
    ImGuiColGrad_NavHighlight_F,          // Gamepad/keyboard: current highlighted item
    ImGuiColGrad_NavHighlight_S,          // Gamepad/keyboard: current highlighted item
    ImGuiColGrad_NavWindowingHighlight_F, // Highlight window when using CTRL+TAB
    ImGuiColGrad_NavWindowingHighlight_S, // Highlight window when using CTRL+TAB
    ImGuiColGrad_NavWindowingDimBg_F,     // Darken/colorize entire screen behind the CTRL+TAB window list, when active
    ImGuiColGrad_NavWindowingDimBg_S,     // Darken/colorize entire screen behind the CTRL+TAB window list, when active
    ImGuiColGrad_ModalWindowDimBg_F,      // Darken/colorize entire screen behind a modal window, when one is active
    ImGuiColGrad_ModalWindowDimBg_S,      // Darken/colorize entire screen behind a modal window, when one is active
    ImGuiColGrad_COUNT
};


namespace ImGui
{
    bool ColoredButtonV1(const char* label, const ImVec2& size, ImU32 text_color, ImU32 bg_color_1, ImU32 bg_color_2);

    //bool BeginEx(const char* name, bool* p_open, ImGuiWindowFlags flags);
}

#endif _IMGUI_IMPROVEMENTS_