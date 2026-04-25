#include "Academia.h"

Academia::Academia()
{
    gruposMusculares = {
        "Peitoral", "Costas", "Ombros",
        "Biceps", "Triceps", "Pernas",
        "Panturrilha", "Abdomem"
    };
}

bool Academia::exercicioExiste(const std::string& nome)
{
    for (auto& e : todosExercicios)
    {
        if (e.getNome() == nome)
            return true;
    }
    return false;
}

void Academia::adicionarExercicio(
    std::string nome,
    std::string grupo,
    int series,
    int repeticoes,
    float carga
)
{
    if (exercicioExiste(nome))
        return;

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