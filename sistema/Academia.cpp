#include "Academia.h"
#include "stdlib.h"
#include "time.h"
#include <fstream>

Academia::Academia()
{
    gruposMusculares = {
        "Peitoral", "Costas", "Ombros",
        "Biceps", "Triceps", "Pernas",
        "Panturrilha", "Abdomem"
    };

    adicionarRecursosParaTeste();
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
    std::string grupo
)
{
    if (exercicioExiste(nome))
        return;

    Exercicio novoExercicio(nome, grupo);
    todosExercicios.push_back(novoExercicio);
}

void Academia::adicionarExercicio(std::string nome,std::string grupo,int id)
{
    if (exercicioExiste(nome))
        return;

    Exercicio novoExercicio(nome,grupo);
    todosExercicios.push_back(novoExercicio);

    std::ofstream arquivo("exercicios.txt",std::ios::app);
	arquivo <<nome<<";"<<grupo<<";"<<id<<std::endl;
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

void Academia::adicionarRecursosParaTeste()
{
    srand(time(0));

    //TREINO PARA PEITO (A)

    static Treino treinoDePeitoParaTeste("Treino de Peitoral e Triceps", "Terca");

    adicionarExercicio("Supino Reto", "Peitoral");
    adicionarExercicio("Supino Inclinado", "Peitoral");
    adicionarExercicio("Elevacao Lateral", "Ombros");
    adicionarExercicio("Triceps na Polia", "Triceps");
    adicionarExercicio("Triceps Frances", "Triceps");

    for (int i = 0; i < 5; i++)
    {
        treinoDePeitoParaTeste.adicionarExercicio(todosExercicios[i]);
        for (int j = 0; j < 3; j++)
        {
            treinoDePeitoParaTeste.getExercicios()[i].adicionarSerie(treinoDePeitoParaTeste.getId(), (float)5 + j*10, (unsigned int)12 - j*2);
        }
    }

    adicionarTreino(treinoDePeitoParaTeste);

    //TREINO PARA COSTAS (B)

    static Treino treinoDeCostasParaTeste("Treino de Costas e Biceps", "Segunda");

    adicionarExercicio("Puxada Alta", "Costas");
    adicionarExercicio("Remada na Polia", "Costas");
    adicionarExercicio("Desenvolvimento de Ombros", "Ombros");
    adicionarExercicio("Rosca Biceps", "Biceps");
    adicionarExercicio("Rosca Scott", "Biceps");

    for (int i = 0; i < 5; i++)
    {
        treinoDeCostasParaTeste.adicionarExercicio(todosExercicios[i+5]);
        for (int j = 0; j < 3 + rand() % 3; j++)
        {
            treinoDeCostasParaTeste.getExercicios()[i].adicionarSerie(treinoDeCostasParaTeste.getId(), (float)10 + rand() % 11, (unsigned int)6 + rand() % 7);
        }
    }

    adicionarTreino(treinoDeCostasParaTeste);

    //TREINO PARA PERNAS (C)

    static Treino treinoDePernasParaTeste("Treino de Pernas e Abdomen", "Quarta");

    adicionarExercicio("LegPress", "Pernas");
    adicionarExercicio("Cadeira Extensora", "Pernas");
    adicionarExercicio("Mesa Flexora", "Pernas");
    adicionarExercicio("Agachamento", "Pernas");
    adicionarExercicio("Abdominal", "Abdomen");

    for (int i = 0; i < 5; i++)
    {
        treinoDePernasParaTeste.adicionarExercicio(todosExercicios[i+10]);
        for (int j = 0; j < 3 + rand() % 3; j++)
        {
            treinoDePernasParaTeste.getExercicios()[i].adicionarSerie(treinoDePernasParaTeste.getId(), (float)10 + rand() % 11, (unsigned int)6 + rand() % 7);
        }
    }
    adicionarTreino(treinoDePernasParaTeste);
}
