#include "Janela.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <functional>

Janela::Janela(Academia* sistema) :
    sistemaAcademia(sistema),
    itemAtual(0),
    nome(""),

    mostrarTelaInicial(true),
    mostrarTelaCadastro(false),
	mostrarTelaLogin(false),

    mostrarTelaCadastrarExercicio(false),
    mostrarTelaVerExercicios(false),

    mostrarTelaCriarTreino(false),     
    mostrarTelaRealizarTreino(false),  
	mostrarTelaEditarTreino(false),

    exercicioSelecionado(0),
    nomeTreino(""),
    treinoSelecionado(-1)

{
}

void Janela::renderizar(Academia& sistema, ImFont* fonteGrande, ImFont* fonteNormal)
{
    ImGuiIO& io = ImGui::GetIO();

    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(io.DisplaySize);

    ImGui::Begin("Menu Principal", nullptr,
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoCollapse |
        ImGuiWindowFlags_NoTitleBar
    );

    if(mostrarTelaInicial)
    {
        ImGui::SetCursorPosY(io.DisplaySize.y*0.25f);

        ImGui::PushFont(fonteGrande);
        ImGui::SetCursorPosX(ImGui::GetWindowWidth()/2.0f-ImGui::CalcTextSize("GymTracker").x/2);
        ImGui::Text("GymTracker");
        ImGui::PopFont();

        ImGui::Spacing();

        ImGui::PushFont(fonteNormal);
        ImGui::SetCursorPosX(ImGui::GetWindowWidth()/2.0f-
            ImGui::CalcTextSize("O GymTracker eh um programa feito para registrar e gerenciar seus treinos de academia!").x/2);

        ImGui::Text("O GymTracker eh um programa feito para registrar e gerenciar seus treinos de academia!");
        ImGui::PopFont();

        ImGui::Spacing();
        ImGui::Spacing();

        float center=ImGui::GetWindowWidth()/2.0f;

        ImGui::SetCursorPosX(center-100);
        if(ImGui::Button("Login", ImVec2(200, 40)))
        {
            mostrarTelaInicial=false;
            mostrarTelaLogin=true;
        }

        ImGui::SetCursorPosX(center-100);
        if(ImGui::Button("Cadastrar", ImVec2(200, 40)))
        {
            mostrarTelaInicial=false;
			mostrarTelaCadastro=true;
        }

    }

    else
    {
        ImGui::PushFont(fonteGrande);
        ImGui::SetCursorPosX(ImGui::GetWindowWidth() / 2.0f - ImGui::CalcTextSize("GymTracker").x / 2);
        ImGui::Text("GymTracker");

        ImGui::PopFont();
        ImGui::PushFont(fonteNormal);

        ImGui::SetCursorPosX(ImGui::GetWindowWidth() / 2.0f -
            ImGui::CalcTextSize("O GymTracker eh um programa feito para registrar e gerenciar seus treinos de academia!").x / 2);

        ImGui::Text("O GymTracker eh um programa feito para registrar e gerenciar seus treinos de academia!");

        ImGui::Spacing();

        float center = ImGui::GetWindowWidth() / 2.0f;

        ImGui::SetCursorPosX(center - 100);
        if (ImGui::Button("Realizar Treino", ImVec2(200, 40)))
            mostrarTelaRealizarTreino = true;

        ImGui::SetCursorPosX(center - 100);
        if (ImGui::Button("Cadastrar Treino", ImVec2(200, 40)))
            mostrarTelaCriarTreino = true;

        ImGui::SetCursorPosX(center - 100);
        if (ImGui::Button("Editar Treino", ImVec2(200, 40)))
            mostrarTelaEditarTreino = true;

        ImGui::SetCursorPosX(center - 100);
        if (ImGui::Button("Cadastrar Exercicio", ImVec2(200, 40)))
            mostrarTelaCadastrarExercicio = true;

        ImGui::SetCursorPosX(center - 100);
        if (ImGui::Button("Ver Exercicios", ImVec2(200, 40)))
            mostrarTelaVerExercicios = true;



        ImGui::PopFont();

        if (mostrarTelaCadastrarExercicio) telaCadastrarExercicio();
        if (mostrarTelaVerExercicios) telaMostrarExercicios();
        if (mostrarTelaCriarTreino) telaCriarTreino();
        if (mostrarTelaRealizarTreino) telaRealizarTreino();
        if (mostrarTelaEditarTreino) telaEditarTreino();
    }

    if (mostrarTelaCadastro) telaCadastro();
    if (mostrarTelaLogin) telaLogin();
    ImGui::End();

}

void Janela::customizarEstilo()
{
	// Soft Cherry style by Patitotective from ImThemes
	ImGuiStyle& style = ImGui::GetStyle();

	style.Alpha = 1.0f;
	style.DisabledAlpha = 0.4f;
	style.WindowPadding = ImVec2(10.0f, 10.0f);
	style.WindowRounding = 4.0f;
	style.WindowBorderSize = 0.0f;
	style.WindowMinSize = ImVec2(50.0f, 50.0f);
	style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
	style.WindowMenuButtonPosition = ImGuiDir_Left;
	style.ChildRounding = 0.0f;
	style.ChildBorderSize = 1.0f;
	style.PopupRounding = 1.0f;
	style.PopupBorderSize = 1.0f;
	style.FramePadding = ImVec2(5.0f, 3.0f);
	style.FrameRounding = 3.0f;
	style.FrameBorderSize = 0.0f;
	style.ItemSpacing = ImVec2(6.0f, 6.0f);
	style.ItemInnerSpacing = ImVec2(3.0f, 2.0f);
	style.CellPadding = ImVec2(3.0f, 3.0f);
	style.IndentSpacing = 6.0f;
	style.ColumnsMinSpacing = 6.0f;
	style.ScrollbarSize = 13.0f;
	style.ScrollbarRounding = 16.0f;
	style.GrabMinSize = 20.0f;
	style.GrabRounding = 4.0f;
	style.TabRounding = 4.0f;
	style.TabBorderSize = 1.0f;
	style.ColorButtonPosition = ImGuiDir_Right;
	style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
	style.SelectableTextAlign = ImVec2(0.0f, 0.0f);

	style.Colors[ImGuiCol_Text] = ImVec4(0.85882354f, 0.92941177f, 0.8862745f, 1.0f);
	style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.52156866f, 0.54901963f, 0.53333336f, 1.0f);
	style.Colors[ImGuiCol_WindowBg] = ImVec4(0.12941177f, 0.13725491f, 0.16862746f, 1.0f);
	style.Colors[ImGuiCol_ChildBg] = ImVec4(0.14901961f, 0.15686275f, 0.1882353f, 1.0f);
	style.Colors[ImGuiCol_PopupBg] = ImVec4(0.2f, 0.21960784f, 0.26666668f, 1.0f);
	style.Colors[ImGuiCol_Border] = ImVec4(0.13725491f, 0.11372549f, 0.13333334f, 1.0f);
	style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
	style.Colors[ImGuiCol_FrameBg] = ImVec4(0.16862746f, 0.18431373f, 0.23137255f, 1.0f);
	style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.45490196f, 0.19607843f, 0.29803923f, 1.0f);
	style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.45490196f, 0.19607843f, 0.29803923f, 1.0f);
	style.Colors[ImGuiCol_TitleBg] = ImVec4(0.23137255f, 0.2f, 0.27058825f, 1.0f);
	style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.5019608f, 0.07450981f, 0.25490198f, 1.0f);
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.2f, 0.21960784f, 0.26666668f, 1.0f);
	style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.2f, 0.21960784f, 0.26666668f, 1.0f);
	style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.23921569f, 0.23921569f, 0.21960784f, 1.0f);
	style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.3882353f, 0.3882353f, 0.37254903f, 1.0f);
	style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.69411767f, 0.69411767f, 0.6862745f, 1.0f);
	style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.69411767f, 0.69411767f, 0.6862745f, 1.0f);
	style.Colors[ImGuiCol_CheckMark] = ImVec4(0.65882355f, 0.13725491f, 0.1764706f, 1.0f);
	style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.6509804f, 0.14901961f, 0.34509805f, 1.0f);
	style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.70980394f, 0.21960784f, 0.26666668f, 1.0f);
	style.Colors[ImGuiCol_Button] = ImVec4(0.6509804f, 0.14901961f, 0.34509805f, 1.0f);
	style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.45490196f, 0.19607843f, 0.29803923f, 1.0f);
	style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.45490196f, 0.19607843f, 0.29803923f, 1.0f);
	style.Colors[ImGuiCol_Header] = ImVec4(0.45490196f, 0.19607843f, 0.29803923f, 1.0f);
	style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.6509804f, 0.14901961f, 0.34509805f, 1.0f);
	style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.5019608f, 0.07450981f, 0.25490198f, 1.0f);
	style.Colors[ImGuiCol_Separator] = ImVec4(0.42745098f, 0.42745098f, 0.49803922f, 1.0f);
	style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.09803922f, 0.4f, 0.7490196f, 1.0f);
	style.Colors[ImGuiCol_SeparatorActive] = ImVec4(0.09803922f, 0.4f, 0.7490196f, 1.0f);
	style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.6509804f, 0.14901961f, 0.34509805f, 1.0f);
	style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.45490196f, 0.19607843f, 0.29803923f, 1.0f);
	style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.45490196f, 0.19607843f, 0.29803923f, 1.0f);
	style.Colors[ImGuiCol_Tab] = ImVec4(0.1764706f, 0.34901962f, 0.5764706f, 1.0f);
	style.Colors[ImGuiCol_TabHovered] = ImVec4(0.25882354f, 0.5882353f, 0.9764706f, 1.0f);
	style.Colors[ImGuiCol_TabActive] = ImVec4(0.19607843f, 0.40784314f, 0.6784314f, 1.0f);
	style.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.06666667f, 0.101960786f, 0.14509805f, 1.0f);
	style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.13333334f, 0.25882354f, 0.42352942f, 1.0f);
	style.Colors[ImGuiCol_PlotLines] = ImVec4(0.85882354f, 0.92941177f, 0.8862745f, 1.0f);
	style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.45490196f, 0.19607843f, 0.29803923f, 1.0f);
	style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.30980393f, 0.7764706f, 0.19607843f, 1.0f);
	style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.45490196f, 0.19607843f, 0.29803923f, 1.0f);
	style.Colors[ImGuiCol_TableHeaderBg] = ImVec4(0.1882353f, 0.1882353f, 0.2f, 1.0f);
	style.Colors[ImGuiCol_TableBorderStrong] = ImVec4(0.30980393f, 0.30980393f, 0.34901962f, 1.0f);
	style.Colors[ImGuiCol_TableBorderLight] = ImVec4(0.22745098f, 0.22745098f, 0.24705882f, 1.0f);
	style.Colors[ImGuiCol_TableRowBg] = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
	style.Colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
	style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.38431373f, 0.627451f, 0.91764706f, 1.0f);
	style.Colors[ImGuiCol_DragDropTarget] = ImVec4(1.0f, 1.0f, 0.0f, 1.0f);
	style.Colors[ImGuiCol_NavHighlight] = ImVec4(0.25882354f, 0.5882353f, 0.9764706f, 1.0f);
	style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
	style.Colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.8f, 0.8f, 0.8f, 1.0f);
	style.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.8f, 0.8f, 0.8f, 0.3f);
}

void Janela::telaCadastrarExercicio()
{
    ImGuiIO& io = ImGui::GetIO();

    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(io.DisplaySize);

    ImGui::Begin("Cadastrar Exercicio", &mostrarTelaCadastrarExercicio,
        ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);

    ImGui::InputText("Nome", nome, 100);

   /* static int series = 0;
    static int repeticoes = 0;
    static float carga = 0;

    ImGui::InputInt("Series", &series);
    ImGui::InputInt("Repeticoes", &repeticoes);
    ImGui::InputFloat("Carga em KG", &carga);*/

    auto listaMusculos = sistemaAcademia->getGruposMusculares();

    std::vector<const char*> musculos;
    for (auto& m : listaMusculos)
        musculos.push_back(m.c_str());

    ImGui::Combo("Grupo Muscular", &itemAtual, musculos.data(), musculos.size());

    if (ImGui::Button("Cadastrar"))
    {
        std::string nomeEx = nome;

        sistemaAcademia->adicionarExercicio(
            nomeEx,
            listaMusculos[itemAtual],
            idAtual/*,
            series,
            repeticoes,
            carga*/
        );

        nome[0] = '\0';
       /* series = repeticoes = 0;
        carga = 0;*/
        itemAtual = 0;

        mostrarTelaCadastrarExercicio = false;
    }

    ImGui::End();
}

void Janela::telaMostrarExercicios()
{
    auto& lista = sistemaAcademia->getExercicios();

    ImGuiIO& io = ImGui::GetIO();

    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(io.DisplaySize);

    ImGui::Begin("Lista de Exercicios", &mostrarTelaVerExercicios,
        ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);

    ImGui::Text("Exercicios cadastrados:");
    ImGui::Separator();

    for (auto& e : lista)
    {
        ImGui::Text("Nome: %s", e.getNome().c_str());
        ImGui::Text("Grupo: %s", e.getGrupoMuscular().c_str());

        /*ImGui::Text("Series: %d | Repeticoes: %d | Carga: %.2f",
            e.getSeries(),
            e.getRepeticoes(),
            e.getCarga()
        );*/

        ImGui::Separator();
    }

    if (ImGui::Button("Sair"))
        mostrarTelaVerExercicios = false;

    ImGui::End();
}

void Janela::telaCriarTreino()
{
    ImGuiIO& io = ImGui::GetIO();

    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(io.DisplaySize);

    ImGui::Begin("Criar Treino", &mostrarTelaCriarTreino,
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoMove
    );

    float center = ImGui::GetWindowWidth() / 2.0f;
    ImGui::SetCursorPosX(center - 100);
    ImGui::Text("Criacao de Treino");

    ImGui::Spacing();
    ImGui::Separator();

    ImGui::InputText("Nome do Treino", nomeTreino, 100);

    static int diaSelecionado = 0;

    const char* dias[] = {
        "Segunda",
        "Terca",
        "Quarta",
        "Quinta",
        "Sexta",
        "Sabado",
        "Domingo"
    };

    ImGui::Combo("Dia do Treino", &diaSelecionado, dias, IM_ARRAYSIZE(dias));

    ImGui::Spacing();

    auto& lista = sistemaAcademia->getExercicios();

    if (exercicioSelecionado >= lista.size())
        exercicioSelecionado = 0;

    std::vector<std::string> nomesStr;
    for (auto& e : lista)
        nomesStr.push_back(e.getNome());

    std::vector<const char*> nomes;
    nomes.reserve(nomesStr.size());

    for (auto& s : nomesStr)
        nomes.push_back(s.c_str());

    
    static Treino treinoTemp("", "");

    if (!nomes.empty())
    {
        ImGui::Combo("Exercicios", &exercicioSelecionado, nomes.data(), nomes.size());

        if (ImGui::Button("Adicionar Exercicio", ImVec2(200, 30)))
        {
            if (exercicioSelecionado < lista.size())
            {
                treinoTemp.adicionarExercicio(lista[exercicioSelecionado]);
            }
        }
    }
    else
    {
        ImGui::Text("Nenhum exercicio cadastrado ainda!");
    }

    ImGui::Separator();
    ImGui::Text("Exercicios no treino:");

    auto& exerciciosDoTreino = treinoTemp.getExercicios();

    static int editarSerieIndex = -1;
    static int repeticoesTemp = 0;
    static float cargaTemp = 0.0f;

    for (int i = 0; i < exerciciosDoTreino.size(); i++)
    {
        ImGui::PushID(i);

        ImGui::Text("%s", exerciciosDoTreino[i].getNome().c_str());

        if (exerciciosDoTreino[i].getNumeroDeSeries(treinoTemp.getId()) > 0)
        {
            ImGui::Text("%d Series",
                exerciciosDoTreino[i].getNumeroDeSeries(treinoTemp.getId()));

            for (int j = 0;
                j < exerciciosDoTreino[i].getNumeroDeSeries(treinoTemp.getId());
                j++)
            {
                ImGui::Text(
                    "Serie %d: %.1f kg de Carga | %d Repeticoes",
                    j + 1,
                    exerciciosDoTreino[i].getCarga(treinoTemp.getId(), j),
                    exerciciosDoTreino[i].getRepeticoes(treinoTemp.getId(), j)
                );
            }
        }

        if (ImGui::Button("Adicionar Serie"))
        {
            editarSerieIndex = i;
            repeticoesTemp = 0;
            cargaTemp = 0.0f;
        }

        ImGui::SameLine();

        if (ImGui::Button("Remover"))
        {
            treinoTemp.tiraExercicio(i);
            ImGui::PopID();
            break;
        }

        ImGui::Separator();
        ImGui::PopID();
    }

    if (editarSerieIndex != -1)
    {
        ImGui::OpenPopup("AdicionarSerie");
    }

    if (ImGui::BeginPopupModal("AdicionarSerie", NULL, ImGuiWindowFlags_AlwaysAutoResize))
    {
        ImGui::InputFloat("Carga", &cargaTemp);
        ImGui::InputInt("Repeticoes", &repeticoesTemp);

        if (ImGui::Button("OK"))
        {
            exerciciosDoTreino[editarSerieIndex].adicionarSerie(
                treinoTemp.getId(),
                cargaTemp,
                repeticoesTemp
            );

            editarSerieIndex = -1;
            ImGui::CloseCurrentPopup();
        }

        ImGui::SameLine();

        if (ImGui::Button("Cancelar"))
        {
            editarSerieIndex = -1;
            ImGui::CloseCurrentPopup();
        }

        ImGui::EndPopup();
    }

    ImGui::Spacing();
    ImGui::SetCursorPosX(center - 100);

    if (ImGui::Button("Salvar Treino", ImVec2(200, 40)))
    {
        if (strlen(nomeTreino) > 0 && !exerciciosDoTreino.empty())
        {
            treinoTemp.setNome(nomeTreino);
            treinoTemp.setDia(dias[diaSelecionado]);

            sistemaAcademia->adicionarTreino(treinoTemp);

            treinoTemp = Treino("", "");

            exercicioSelecionado = 0;
            nomeTreino[0] = '\0';
            diaSelecionado = 0;

            mostrarTelaCriarTreino = false;
        }
        else
        {
            ImGui::OpenPopup("Erro");
        }
    }

    if (ImGui::BeginPopup("Erro"))
    {
        ImGui::Text("Preencha o nome e adicione pelo menos 1 exercicio!");

        if (ImGui::Button("OK"))
            ImGui::CloseCurrentPopup();

        ImGui::EndPopup();
    }

    ImGui::End();
}

void Janela::telaRealizarTreino()
{
    ImGuiIO& io = ImGui::GetIO();

    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(io.DisplaySize);

    ImGui::Begin("Realizar Treino", &mostrarTelaRealizarTreino,
        ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);

    auto& treinos = sistemaAcademia->getTreinos();

    if (treinos.empty())
    {
        ImGui::Text("Nenhum treino cadastrado!");
        if (ImGui::Button("Voltar"))
            mostrarTelaRealizarTreino = false;

        ImGui::End();
        return;
    }

    if (treinoSelecionado >= (int)treinos.size())
        treinoSelecionado = -1;

    if (treinoSelecionado == -1)
    {
        ImGui::Text("Escolha um treino:");

        for (int i = 0; i < treinos.size(); i++)
        {
            if (ImGui::Button(treinos[i].getNome().c_str()))
            {
                treinoSelecionado = i;

                auto& exs = treinos[i].getExercicios();
                exerciciosConcluidos = std::vector<int>(exs.size(), 0);
            }
        }
    }
    else
    {
        auto& treino = treinos[treinoSelecionado];
        auto& exs = treino.getExercicios();

        ImGui::Text("Treino: %s", treino.getNome().c_str());

        if (exerciciosConcluidos.size() != exs.size())
            exerciciosConcluidos = std::vector<int>(exs.size(), 0);

        int totalSeries = 0;
        int feitas = 0;

        for (int i = 0; i < exs.size(); i++)
        {
            ImGui::PushID(i);

            ImGui::Text("%s", exs[i].getNome().c_str());
            
            ImGui::SameLine();

            ImGui::Text("%d/%d", exerciciosConcluidos[i], exs[i].getNumeroDeSeries(treino.getId()));

            auto& series = exs[i].getSeries(treino.getId());

            for (int j = 0; j < series.size(); j++)
            {
                ImGui::PushID(j);

                bool& concluida = exs[i].getConcluidaRef(treino.getId(), j);
                bool antes = concluida;

                if (ImGui::Checkbox("##Serie", &concluida))
                {
                    if (!antes && concluida)
                    {
                        exerciciosConcluidos[i]++;
                    }

                    if (antes && !concluida)
                    {
                        exerciciosConcluidos[i]--;
                    }
                }

                ImGui::SameLine();

                ImGui::Text("Serie %d: %.1f kg de Carga | %d Repeticoes", j + 1,
                    exs[i].getCarga(treino.getId(), j),
                    exs[i].getRepeticoes(treino.getId(), j)
                );

                ImGui::PopID();
            }

            totalSeries += exs[i].getNumeroDeSeries(treino.getId());
            feitas += exerciciosConcluidos[i];

            ImGui::PopID();
        }

        float progresso = totalSeries > 0 ?
            (float)feitas / (float)totalSeries : 0.0f;

        ImGui::ProgressBar(progresso, ImVec2(300, 20));

        if (ImGui::Button("Finalizar"))
        {
            for (int i = 0; i < exs.size(); i++)
            {
                exs[i].setSeriesConcluidas(treino.getId(), exs[i].getNumeroDeSeries(treino.getId()), false);
            }
            treinoSelecionado = -1;
            exerciciosConcluidos.clear();
        }
    }

    ImGui::End();
}

void Janela::telaEditarTreino()
{
    ImGuiIO& io=ImGui::GetIO();

    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(io.DisplaySize);

    ImGui::Begin("Editar Treino", &mostrarTelaEditarTreino,
        ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);

    auto& treinos = sistemaAcademia->getTreinos();
    
    if (treinos.empty())
    {
        ImGui::Text("Nenhum treino cadastrado!");
        if (ImGui::Button("Voltar"))
            mostrarTelaEditarTreino=false;

        ImGui::End();
        return;
    }

    if(treinoSelecionado>=(int)treinos.size())
		treinoSelecionado=-1;

    if(treinoSelecionado==-1)
    {
        ImGui::Text("Escolha um treino para editar:");

        for (int i=0; i<treinos.size(); i++)
        {
            if (ImGui::Button(treinos[i].getNome().c_str()))
            {
                treinoSelecionado=i;
            }
        }
	}
    else
    {
        auto& treino=treinos[treinoSelecionado];

        ImGui::Text("Editando treino:");
 
        static char novoNome[100];
        strcpy_s(novoNome, treino.getNome().c_str());

        //edita o nome
        if(ImGui::InputText("Nome", novoNome, 100))
        {
            treino.setNome(novoNome);
        }

		//edita o dia
        static int diaSelecionado=0;
        const char* dias[]={
            "Segunda",
            "Terca",
            "Quarta",
            "Quinta",
            "Sexta",
            "Sabado",
            "Domingo"
        };
        for(int i=0; i<7; i++)
        {
            if(strcmp(treino.getDia().c_str(), dias[i])==0)
            {
                diaSelecionado=i;
                break;
            }
        }
        if(ImGui::Combo("Dia do Treino", &diaSelecionado, dias, IM_ARRAYSIZE(dias)))
        {
            treino.setDia(dias[diaSelecionado]);
		}

		ImGui::Separator();

		//adiciona exercicios
        auto& lista = sistemaAcademia->getExercicios();

        if (exercicioSelecionado>=lista.size())
            exercicioSelecionado=0;

        std::vector<std::string> nomesStr;
        for (auto& e : lista)
            nomesStr.push_back(e.getNome());

        std::vector<const char*> nomes;
        nomes.reserve(nomesStr.size());

        for (auto& s : nomesStr)
            nomes.push_back(s.c_str());

        if (!nomes.empty())
        {
            ImGui::Combo("Exercicios", &exercicioSelecionado, nomes.data(), nomes.size());

            if (ImGui::Button("Adicionar Exercicio", ImVec2(200, 30)))
            {
                if (exercicioSelecionado<lista.size())
                    treino.adicionarExercicio(lista[exercicioSelecionado]);
            }
        }

		ImGui::Separator();

        //remove exercicios
        auto& exs=treino.getExercicios();

        for (int i=0; i<exs.size(); i++)
        {
            ImGui::PushID(i);

            ImGui::Text("%s", exs[i].getNome().c_str());

            ImGui::SameLine();

            if (ImGui::Button("Remover"))
            {
                treino.tiraExercicio(i);
                ImGui::PopID();
                break; 
            }

            ImGui::PopID();
        }

		ImGui::Separator();

        //volta
        if (ImGui::Button("Salvar"))
        {
			mostrarTelaEditarTreino=false;  
			treinoSelecionado=-1;
        }
    }

    ImGui::End();
}

void Janela::telaLogin()
{
    ImGuiIO& io = ImGui::GetIO();
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(io.DisplaySize);
    ImGui::Begin("Login", &mostrarTelaLogin,
        ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);

    static char username[100];
    static char password[100];
    static bool errou=false;

	ImGui::Text("Username");
    if (ImGui::InputText("##Username", username, 100))
    {
        errou=false;
    }

	ImGui::Text("Password");
    if (ImGui::InputText("##Password", password, 100, ImGuiInputTextFlags_Password))
    {
        errou=false;
    }

    if(ImGui::Button("Login"))
    {   
		std::ifstream arquivo("usuarios.txt");

        if (arquivo.is_open())
        {
            std::string linha;
            bool encontrado=false;
            std::string hashSenha=std::to_string(std::hash<std::string>{}(password));

            while (std::getline(arquivo,linha))
            {
                size_t pos=linha.find(';');
				size_t pos2=linha.find(';',pos+1);

                if (pos!=std::string::npos && pos2!=std::string::npos)
                {
                    std::string user=linha.substr(0,pos);
                    std::string senha=linha.substr(pos+1,pos2-pos-1);
                    if (user==username && senha==hashSenha)
                    {
                        idAtual=std::stoi(linha.substr(pos2+1));
                        encontrado=true;
                        break;
                    }
                }
            }
            
            if (!encontrado)
            {
				errou=true;
            }
            else
            {
                mostrarTelaLogin=false;
            }
            arquivo.close();
        }
    }

    if(errou)
    {
        ImGui::SameLine(0,50);
        ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "Login nao encontrado!");
    }

    if(ImGui::Button("Voltar"))
        mostrarTelaLogin=false;
    
    ImGui::End();
}

void Janela::telaCadastro()
{
    ImGuiIO& io = ImGui::GetIO();
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(io.DisplaySize);
    ImGui::Begin("Cadastro", &mostrarTelaCadastro,
        ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);

    static char username[100];
    static char password[100];
    static char confirmPassword[100];
	static bool erroSenha=false;

    ImGui::Text("Username");
    if(ImGui::InputText("##Username", username, 100)) erroSenha=false;

	ImGui::Text("Password");
    if(ImGui::InputText("##Password", password, 100, ImGuiInputTextFlags_Password)) erroSenha=false;

	ImGui::Text("Confirmar Password");
    if(ImGui::InputText("##ConfirmPassword", confirmPassword, 100, ImGuiInputTextFlags_Password)) erroSenha=false;

    if(ImGui::Button("Cadastrar"))
    {
		std::ifstream arquivoLeitura("usuarios.txt");
        int maiorId=0;
        std::string linha;

        while (std::getline(arquivoLeitura, linha))
        {
            size_t pos1=linha.find(';');
            size_t pos2=linha.find(';',pos1+1);

            if (pos1!=std::string::npos && pos2!=std::string::npos)
            {
                int id=std::stoi(linha.substr(pos2+1));

                if (id>maiorId)
                    maiorId=id;
            }
        } 
		arquivoLeitura.close();

        if(strcmp(password, confirmPassword)!=0)
        {
			erroSenha=true;
        }
        else
        {
			erroSenha=false;

            std::ofstream arquivoEscrita("usuarios.txt", std::ios::app);

            if (arquivoEscrita.is_open())
            {
				std::string hashSenha = std::to_string(std::hash<std::string>{}(password));
                arquivoEscrita<<username<<";"<<hashSenha<<";"<<maiorId+1<<"\n";
                arquivoEscrita.close();
            }

            mostrarTelaCadastro=false;
			mostrarTelaInicial=true;
        }
    }

    ImGui::SameLine(0,20);

    if(ImGui::Button("Voltar"))
        mostrarTelaCadastro=false;

    if (erroSenha)
    {
        ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "As senhas não coincidem");
    }

    ImGui::End();
}