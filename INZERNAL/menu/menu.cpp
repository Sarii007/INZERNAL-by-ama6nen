#pragma once
#include <core/utils.h>
#include <menu/menu.h>

void menu::animate() {
    static bool direction = false;

    //most imgui controls have a custom added fading effect
    global::fade += direction ? -0.003f : 0.003f;
    if (global::fade <= 0.0f) {
        direction = !direction;
        global::fade = 0.0f;
    }
    else if (global::fade >= 0.3f) {
        direction = !direction;
        global::fade = 0.3f;
    }
}

void menu::EndScene(IDirect3DDevice9* device, bool active) {
    if (!global::load) { //init imgui
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
        ImGui_ImplDX9_Init(device);
        ImGui::StyleColorsDark();
        //load_config();
        utils::printc("93", "dx9 and imgui init done");
        global::load = true;
    }
    if (global::load) {
        ImGui_ImplDX9_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();

        ImGui::SetNextWindowPos(ImVec2{ 0, 0 }, ImGuiCond_Once);
        ImGui::SetNextWindowSize(ImVec2{ 800, 450 }, ImGuiCond_Once);

        if (global::draw && ImGui::Begin(std::string("INZERNAL " + global::version).c_str(), &global::draw, ImGuiWindowFlags_NoCollapse)) {
            animate();
            static char* tab_names[] = { (char*)"Enhancements", (char*)"Cheats", (char*)"Framework" };
            static int active_tab = 0;

            auto& style = ImGui::GetStyle();
            ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2{ 0, style.WindowPadding.y });

            float group_w = ImGui::GetCurrentWindow()->Size.x - style.WindowPadding.x * 2;
            ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 10));
            ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 0.f);
            imwrap::horizontal_tabs(tab_names, active_tab, group_w / _countof(tab_names), 33.0f);
            ImGui::PopStyleVar(3);

            switch (active_tab) {
                case 0: enhancements_tab(); break;
                case 1: cheats_tab(); break;
                case 2: framework_tab(); break;
            }
            ImGui::End();
        }
        ImGui::EndFrame();
        ImGui::Render();
        ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
    }
}

bool menu::WndProc(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam) {
    static bool init = false;
    if (!global::d9init)
        return false;

    if (global::load && !init) {
        ImGui_ImplWin32_Init(wnd);
        init = true;
    }

    if (msg == WM_KEYUP && wparam == VK_F2)
        global::draw = !global::draw;

    /*  if (msg == WM_KEYUP && wparam == VK_F4)
        load_config();*/

    return ImGui_ImplWin32_WndProcHandler(wnd, msg, wparam, lparam);
}
