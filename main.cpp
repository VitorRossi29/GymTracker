#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

#include <GLFW/glfw3.h>

//AQUI ESTÁ O TEMA ROXO QUE EU COLOQUEI PARA TESTAR

void SetupImGuiStyle()
{
    // Eggplant style by yo-ru from ImThemes
    ImGuiStyle& style = ImGui::GetStyle();

    style.Alpha = 1.0f;
    style.DisabledAlpha = 0.6f;
    style.WindowPadding = ImVec2(10.0f, 10.0f);
    style.WindowRounding = 10.0f;
    style.WindowBorderSize = 1.0f;
    style.WindowMinSize = ImVec2(20.0f, 32.0f);
    style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
    style.WindowMenuButtonPosition = ImGuiDir_None;
    style.ChildRounding = 10.0f;
    style.ChildBorderSize = 1.0f;
    style.PopupRounding = 10.0f;
    style.PopupBorderSize = 1.0f;
    style.FramePadding = ImVec2(15.0f, 5.8f);
    style.FrameRounding = 6.0f;
    style.FrameBorderSize = 0.0f;
    style.ItemSpacing = ImVec2(4.0f, 6.0f);
    style.ItemInnerSpacing = ImVec2(10.0f, 4.0f);
    style.CellPadding = ImVec2(4.0f, 4.0f);
    style.IndentSpacing = 20.0f;
    style.ColumnsMinSpacing = 4.0f;
    style.ScrollbarSize = 20.0f;
    style.ScrollbarRounding = 10.0f;
    style.GrabMinSize = 10.0f;
    style.GrabRounding = 10.0f;
    style.TabRounding = 6.0f;
    style.TabBorderSize = 0.0f;
    style.ColorButtonPosition = ImGuiDir_Right;
    style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
    style.SelectableTextAlign = ImVec2(0.0f, 0.0f);

    style.Colors[ImGuiCol_Text] = ImVec4(0.9490196f, 0.9490196f, 0.9490196f, 1.0f);
    style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.9490196f, 0.9490196f, 0.9490196f, 0.34509805f);
    style.Colors[ImGuiCol_WindowBg] = ImVec4(0.47843137f, 0.34901962f, 0.45882353f, 1.0f);
    style.Colors[ImGuiCol_ChildBg] = ImVec4(0.47843137f, 0.34901962f, 0.45882353f, 1.0f);
    style.Colors[ImGuiCol_PopupBg] = ImVec4(0.47843137f, 0.34901962f, 0.45882353f, 1.0f);
    style.Colors[ImGuiCol_Border] = ImVec4(0.16078432f, 0.10980392f, 0.1764706f, 1.0f);
    style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
    style.Colors[ImGuiCol_FrameBg] = ImVec4(0.16078432f, 0.10980392f, 0.1764706f, 1.0f);
    style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.16078432f, 0.10980392f, 0.1764706f, 1.0f);
    style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.16078432f, 0.10980392f, 0.1764706f, 0.8197425f);
    style.Colors[ImGuiCol_TitleBg] = ImVec4(0.16078432f, 0.10980392f, 0.1764706f, 1.0f);
    style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.16078432f, 0.10980392f, 0.1764706f, 1.0f);
    style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.16078432f, 0.10980392f, 0.1764706f, 1.0f);
    style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.16078432f, 0.10980392f, 0.1764706f, 1.0f);
    style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.16078432f, 0.10980392f, 0.1764706f, 1.0f);
    style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.6039216f, 0.41960785f, 0.5764706f, 0.3019608f);
    style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.6039216f, 0.41960785f, 0.5764706f, 0.4f);
    style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.6039216f, 0.41960785f, 0.5764706f, 0.6f);
    style.Colors[ImGuiCol_CheckMark] = ImVec4(0.6039216f, 0.41960785f, 0.5764706f, 1.0f);
    style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.6039216f, 0.41960785f, 0.5764706f, 0.3019608f);
    style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.6039216f, 0.41960785f, 0.5764706f, 0.6f);
    style.Colors[ImGuiCol_Button] = ImVec4(0.16078432f, 0.10980392f, 0.1764706f, 1.0f);
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.16078432f, 0.10980392f, 0.1764706f, 0.4f);
    style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.16078432f, 0.10980392f, 0.1764706f, 0.6f);
    style.Colors[ImGuiCol_Header] = ImVec4(0.16078432f, 0.10980392f, 0.1764706f, 1.0f);
    style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.16078432f, 0.10980392f, 0.1764706f, 1.0f);
    style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.16078432f, 0.10980392f, 0.1764706f, 1.0f);
    style.Colors[ImGuiCol_Separator] = ImVec4(0.16078432f, 0.10980392f, 0.1764706f, 1.0f);
    style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.16078432f, 0.10980392f, 0.1764706f, 1.0f);
    style.Colors[ImGuiCol_SeparatorActive] = ImVec4(0.16078432f, 0.10980392f, 0.1764706f, 1.0f);
    style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.16078432f, 0.10980392f, 0.1764706f, 0.4549356f);
    style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.16078432f, 0.10980392f, 0.1764706f, 0.7811159f);
    style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.16078432f, 0.10980392f, 0.1764706f, 0.9019608f);
    style.Colors[ImGuiCol_Tab] = ImVec4(0.16078432f, 0.10980392f, 0.1764706f, 1.0f);
    style.Colors[ImGuiCol_TabHovered] = ImVec4(0.16078432f, 0.10980392f, 0.1764706f, 0.8f);
    style.Colors[ImGuiCol_TabActive] = ImVec4(0.16078432f, 0.10980392f, 0.1764706f, 0.84313726f);
    style.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.16078432f, 0.10980392f, 0.1764706f, 0.81960785f);
    style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.16078432f, 0.10980392f, 0.1764706f, 0.8352941f);
    style.Colors[ImGuiCol_PlotLines] = ImVec4(0.9490196f, 0.9490196f, 0.9490196f, 1.0f);
    style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.47843137f, 0.34901962f, 0.45882353f, 1.0f);
    style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.60784316f, 0.42745098f, 0.5803922f, 1.0f);
    style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.60784316f, 0.42745098f, 0.5803922f, 0.639485f);
    style.Colors[ImGuiCol_TableHeaderBg] = ImVec4(0.16078432f, 0.10980392f, 0.1764706f, 1.0f);
    style.Colors[ImGuiCol_TableBorderStrong] = ImVec4(0.16078432f, 0.10980392f, 0.1764706f, 1.0f);
    style.Colors[ImGuiCol_TableBorderLight] = ImVec4(0.16078432f, 0.10980392f, 0.1764706f, 1.0f);
    style.Colors[ImGuiCol_TableRowBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
    style.Colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.0f, 1.0f, 1.0f, 0.01716739f);
    style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.6039216f, 0.41960785f, 0.5764706f, 0.6f);
    style.Colors[ImGuiCol_DragDropTarget] = ImVec4(0.60784316f, 0.42745098f, 0.5803922f, 1.0f);
    style.Colors[ImGuiCol_NavHighlight] = ImVec4(0.16078432f, 0.10980392f, 0.1764706f, 0.8f);
    style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(0.16078432f, 0.10980392f, 0.1764706f, 0.7019608f);
    style.Colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.16078432f, 0.10980392f, 0.1764706f, 0.2f);
    style.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.16078432f, 0.10980392f, 0.1764706f, 0.34901962f);
}

int main()
{
    glfwInit();

    GLFWwindow* window = glfwCreateWindow(
        1280, 720,
        "Meu Projeto",
        NULL,
        NULL
    );

    if (!window)
    {
        glfwTerminate();
        return 1;
    }

    glfwMakeContextCurrent(window);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO();
    (void)io;

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");


    // Main loop
    bool done = false;

    //!!!!!!!!!!!!!!!!!!!
    bool opened = true;
    bool checkbox = false;

    float value1 = 0.1f;
    int value2 = 1;

    const char* items[] = { "Supino Reto", "Supino Inclinado", "Desenvolvimento" };
    int currentitem = 0;

    //!!!!!!!!!!!!!!!!!!!  
    
    SetupImGuiStyle();

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        /*ImGui::Begin("Janela");

        ImGui::Text("Hello World!");

        ImGui::End();*/

        if (ImGui::Begin("Janelona", &opened, ImGuiWindowFlags_NoCollapse))
        {
            ImGui::SetCursorPosX(ImGui::GetWindowWidth() / 2.0f - 50);
            if (ImGui::Button("Meu butao", ImVec2(100, 50)))
            {

            }

            ImGui::Checkbox("Minha caixa de chques", &checkbox);

            ImGui::SliderFloat("slider float!", &value1, 0.0f, 100.0f);
            ImGui::SliderInt("Int slider", &value2, 0, 100);

            ImGui::Combo("Combo", &currentitem, items, IM_ARRAYSIZE(items));

            ImGui::SetCursorPosX(ImGui::GetWindowWidth() / 2.0f - ImGui::CalcTextSize("GymTracker").x / 2);
            ImGui::Text("GymTracker");
        }
        ImGui::End();

        ImGui::Render();

        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);

        glViewport(0, 0, display_w, display_h);

        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);

        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_RenderDrawData(
            ImGui::GetDrawData()
        );

        glfwSwapBuffers(window);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}