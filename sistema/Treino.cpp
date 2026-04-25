#include "Treino.h"

Treino::Treino(std::string nomeP, std::string diaP)
{
    nome = nomeP;
    diaSemana = diaP;
}

void Treino::adicionarExercicio(const Exercicio& e)
{
    exercicios.push_back(e); 
}

std::string Treino::getNome()
{
    return nome;
}

std::string Treino::getDia()
{
    return diaSemana;
}

std::vector<Exercicio>& Treino::getExercicios()
{
    return exercicios;
}