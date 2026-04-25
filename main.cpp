#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include "sistema/Academia.h"
#include "menu/Janela.h"

#include <GLFW/glfw3.h>

int main()
{
    //IMPORTANTE
    Academia sistema;

    Janela janela(&sistema);

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
    
    janela.customizarEstilo();

    ImFont* fonteNormal =
        io.Fonts->AddFontFromFileTTF(
            "assets/fontes/Michroma-Regular.ttf",
            16.0f
        );

    if (fonteNormal == nullptr)
    {
        printf("Erro ao carregar fonte\n");
    }

   ImFont* fonteGrande =
        io.Fonts->AddFontFromFileTTF("assets/fontes/Tourney-Regular.ttf", 32.0f);
    
   if (fonteGrande == nullptr)
   {
       printf("Erro ao carregar fonte\n");
   }

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        janela.renderizar(sistema, fonteGrande, fonteNormal);

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