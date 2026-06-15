#pragma once
#include "../sistema/Academia.h"
#include "imgui.h"
#include "../sistema/Exercicio.h"
#include "../sistema/Treino.h"
#include <vector>

class Janela
{
private:
    Academia* sistemaAcademia;

    int idAtual;

    int itemAtual;
    bool mostrarTelaInicial;
    bool mostrarTelaCadastro;
    bool mostrarTelaLogin;

    bool mostrarTelaCadastrarExercicio;
    bool mostrarTelaVerExercicios;

    bool mostrarTelaCriarTreino;
    bool mostrarTelaRealizarTreino;
    bool mostrarTelaEditarTreino;
    bool mostrarTelaVerTreinos; // Movido para cá para organizar os booleanos

    char nome[100];

    char nomeTreino[100];
    char diaTreino[100];

    int exercicioSelecionado;

    std::vector<Exercicio> exerciciosSelecionados;

    int treinoSelecionado;
    std::vector<int> exerciciosConcluidos;

    std::string usuarioLogado;

public:
    Janela(Academia* sistema);

    void renderizar(Academia& sistema, ImFont* fonteGrande, ImFont* fonteNormal);
    void customizarEstilo();

    void telaLogin();
    void telaCadastro();

    void telaVerTreinos();
    void telaCadastrarExercicio();
    void telaMostrarExercicios();
    void telaCriarTreino();
    void telaRealizarTreino();
    void telaEditarTreino(); // Mantida apenas uma declaração desta função
};