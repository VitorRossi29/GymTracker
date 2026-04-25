#pragma once
#include "../sistema/Academia.h"
#include "imgui.h"
#include "../sistema/Exercicio.h"

class Janela
{
private:
	Academia* sistemaAcademia;
	int itemAtual;
	bool mostrarTelaCadastrarExercicio;
	bool mostrarTelaVerExercicios;
	char nome[100];
public:
	Janela(Academia* sistema);
	void renderizar(Academia& sistema, ImFont* fonteGrande, ImFont* fonteNormal);
	void customizarEstilo();
	void telaCadastrarExercicio();
	void telaMostrarExercicios();
};