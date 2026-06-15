#pragma once
#include <string>
#include <vector>
#include <map>
#include "Serie.h"

class Exercicio
{
private:
    std::string nome;
    std::string grupoMuscular;

    std::map<int, std::vector<Serie>> seriesEmSi;

public:
    Exercicio(
        std::string nomeP = "nome",
        std::string grupoMuscularP = ""
    );

    const std::string getNome();
    const std::string getGrupoMuscular();

    /*void setNumeroDeSeries(unsigned int idTreino, int numS);*/

    //void aumentarNumeroDeSeries(unsigned int idTreino);

    void setSeriesConcluidas(unsigned int idTreino, int s, bool conc);
    void concluirSerie(unsigned int idTreino, int idSerie);
    /*void incrementarSerie(unsigned int idTreino);*/

    // AQUI: Nova funcao para verificar se e cardio
    bool isCardio() const;

    const int getRepeticoes(unsigned int idTreino, unsigned int idSerie);
    const float getCarga(unsigned int idTreino, unsigned int idSerie);
    // AQUI: Get de Minutos
    const int getMinutos(unsigned int idTreino, unsigned int idSerie);

    // AQUI: Adicionado minutos no final (padrao = 0 para nao quebrar o resto)
    void adicionarSerie(unsigned int idTreino, float car, unsigned int reps, unsigned int min = 0);
    float getProgresso(unsigned int idTreino);

    int getNumeroDeSeries(unsigned int idTreino);
    int getSeriesConcluidas(unsigned int idTreino);
    bool& getConcluidaRef(int idTreino, int idSerie);

    std::vector<Serie>& getSeries(unsigned int idTreino);
};