#include "Treino.h"

unsigned int Treino::id_acumulativo = 0;

Treino::Treino(std::string nomeP, std::string diaP, int usuario) :
    id(id_acumulativo++),
    idUsuario(usuario)
{
    nome = nomeP;
    diaSemana = diaP;
}

void Treino::adicionarExercicio(const Exercicio& e)
{
    exercicios.push_back(e); 
}

void Treino::tiraExercicio(int pos)
{
    if (pos >= 0 && pos < exercicios.size())
        exercicios.erase(exercicios.begin() + pos);
}

void Treino::setNome(std::string n)
{
    nome = n;
}

std::string Treino::getNome()
{
    return nome;
}

std::string Treino::getDia()
{
    return diaSemana;
}

void Treino::setDia(std::string d)
{
    diaSemana = d;
}

std::vector<Exercicio>& Treino::getExercicios()
{
    return exercicios;
}

const unsigned int Treino::getId() const
{
    return id;
}

unsigned int Treino::getId_acumulativo()
{
    return id_acumulativo;
}

void Treino::setIdUsuario(int usuario)
{
    idUsuario = usuario;
}

int Treino::getIdUsuario() const
{
    return idUsuario;
}
