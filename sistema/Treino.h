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
	void tiraExercicio(int pos);

	void setNome(std::string n);
    std::string getNome();

    void setDia(std::string d);
    std::string getDia();

    std::vector<Exercicio>& getExercicios();
};