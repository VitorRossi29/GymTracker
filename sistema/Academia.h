#pragma once
#include <vector>
#include "Exercicio.h"
#include "Treino.h"

class Academia
{
private:
    std::vector<Exercicio> todosExercicios;
    std::vector<Treino> treinos;
    std::vector<std::string> gruposMusculares;

public:
    Academia();

    void adicionarExercicio(
        std::string nome = "",
        std::string grupo = ""
    );

    bool exercicioExiste(const std::string& nome);

    void adicionarTreino(Treino t);

    std::vector<Treino>& getTreinos();
    std::vector<Exercicio>& getExercicios();
    std::vector<std::string>& getGruposMusculares();

    void adicionarRecursosParaTeste();
};