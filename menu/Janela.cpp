#include "Janela.h"
#include <iostream>


Janela::Janela(Academia* sistema) :
	sistemaAcademia(sistema),
	itemAtual(0),
	nome(""),
	mostrarTelaCadastrarExercicio(false),
	mostrarTelaVerExercicios(false)
{
}

void Janela::renderizar(Academia& sistema, ImFont* fonteGrande, ImFont* fonteNormal)
{
    ImGui::Begin("Menu Principal");

	ImGui::PushFont(fonteGrande);

    ImGui::SetCursorPosX(ImGui::GetWindowWidth() / 2.0f - ImGui::CalcTextSize("GymTracker").x / 2);
    ImGui::Text("GymTracker");
	
	ImGui::PopFont();

	ImGui::PushFont(fonteNormal);

	ImGui::SetCursorPosX(ImGui::GetWindowWidth() / 2.0f - ImGui::CalcTextSize("O GymTracker eh um programa feito para registrar e gerenciar seus treinos de academia!").x / 2);
	ImGui::Text("O GymTracker eh um programa feito para registrar e gerenciar seus treinos de academia!");

	ImGui::SetCursorPosX(ImGui::GetWindowWidth() / 2.0f - ImGui::CalcTextSize("Realizar Treino").x / 2);
	if (ImGui::Button("Realizar Treino"))
	{
		
	}
	ImGui::SetCursorPosX(ImGui::GetWindowWidth() / 2.0f - ImGui::CalcTextSize("Cadastrar Treino").x / 2);
	if (ImGui::Button("Cadastrar Treino"))
	{

	}
	ImGui::SetCursorPosX(ImGui::GetWindowWidth() / 2.0f - ImGui::CalcTextSize("Cadastrar Exercicio").x / 2);
	if (ImGui::Button("Cadastrar Exercicio"))
	{
		mostrarTelaCadastrarExercicio = true;
	}
	ImGui::SetCursorPosX(ImGui::GetWindowWidth() / 2.0f - ImGui::CalcTextSize("Ver Exercicios").x / 2);
	if (ImGui::Button("Ver Exercicios"))
	{
		mostrarTelaVerExercicios = true;
	}

	ImGui::PopFont();

	if (mostrarTelaCadastrarExercicio)
	{
		telaCadastrarExercicio();
	}

	if (mostrarTelaVerExercicios)
	{
		telaMostrarExercicios();
	}

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
	ImGui::Begin("Cadastrar Exercicio", &mostrarTelaCadastrarExercicio);

	ImGui::InputText("Nome do Exercicio", nome, 100);
		
	std::vector<std::string> listaMusculos = sistemaAcademia->getGruposMusculares();

	std::vector<const char*> musculosConstChar;
	musculosConstChar.reserve(listaMusculos.size());
	for (const auto& m : listaMusculos)
	{
		musculosConstChar.push_back(m.c_str());
	}
	ImGui::Combo("Grupo Muscular", &itemAtual, musculosConstChar.data(), static_cast<int>(musculosConstChar.size()));	

	if (ImGui::Button("Cadastrar"))
	{
		std::string nomeExercicio = nome;
		std::string grupoSelecionado = listaMusculos[itemAtual];

		sistemaAcademia->adicionarExercicio(nomeExercicio, grupoSelecionado);
		mostrarTelaCadastrarExercicio = false;
	}

	ImGui::End();
}

void Janela::telaMostrarExercicios()
{
	std::vector<Exercicio> listaExercicios = sistemaAcademia->getExercicios();

	ImGui::Begin("Lista de Exercicios", &mostrarTelaVerExercicios);

	ImGui::Text("Aqui estao listados todos os exercicios cadastrados:");

	for (int i = 0; i < listaExercicios.size(); i++)
	{
		std::string exercicio = listaExercicios[i].getNome() + " (" + listaExercicios[i].getGrupoMuscular() + ")";
		ImGui::Text(exercicio.c_str());
	}

	if (ImGui::Button("Sair"))
	{
		mostrarTelaVerExercicios = false;
	}

	ImGui::End();
}
