#pragma once
#include <string>
#include <vector>
#include "Exercicio.h"

class Treino
{
private:
    std::string nome;
    std::string diaSemana;
    std::vector<Exercicio> exercicios;

public:
    Treino(std::string nomeP = "", std::string diaP = "");

    void adicionarExercicio(const Exercicio& e);

    std::string getNome();
    std::string getDia();

    std::vector<Exercicio>& getExercicios();
};