#include "Academia.h"

Academia::Academia()
{
	gruposMusculares.push_back("Peitoral");
	gruposMusculares.push_back("Costas");
	gruposMusculares.push_back("Ombros");
	gruposMusculares.push_back("Biceps");
	gruposMusculares.push_back("Triceps");
	gruposMusculares.push_back("Pernas");
	gruposMusculares.push_back("Panturrilha");
	gruposMusculares.push_back("Abdomem");
}

void Academia::adicionarExercicio(std::string nome, std::string grupo, int series, int repeticoes, float carga)
{
	Exercicio novoExercicio(nome, grupo, series, repeticoes, carga);

	todosExercicios.push_back(novoExercicio);
}

std::vector<Exercicio>& Academia::getExercicios()
{
	return todosExercicios;
}

void Academia::adicionarTreino(Treino t)
{
    treinos.push_back(t);
}

std::vector<Treino>& Academia::getTreinos()
{
    return treinos;
}

std::vector<std::string>& Academia::getGruposMusculares()
{
	return gruposMusculares;
}

