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

    unsigned int id;
    static unsigned int id_acumulativo;

    int idUsuario;

public:
    Treino(std::string nomeP = "", std::string diaP = "", int usuario = -1);

    void adicionarExercicio(const Exercicio& e);
	void tiraExercicio(int pos);

	void setNome(std::string n);
    std::string getNome();

    void setDia(std::string d);
    std::string getDia();

    std::vector<Exercicio>& getExercicios();

    const unsigned int getId() const;
    static unsigned int getId_acumulativo();

    void setIdUsuario(int usuario);
    int getIdUsuario() const;
};