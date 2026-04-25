#pragma once
#include <string>

class Exercicio
{
private:
    std::string nome;
    std::string grupoMuscular;
    int series;
    int repeticoes;
    float carga;

    int seriesConcluidas = 0;

public:
    Exercicio(
        std::string nomeP = "nome",
        std::string grupoMuscularP = "",
        int seriesP = 0,
        int repeticoesP = 0,
        float cargaP = 0
    );

    void setSeries(int s);
    void setRepeticoes(int r);
    void setCarga(float c);

    void setSeriesConcluidas(int s);
    void incrementarSerie();

    float getProgresso() const;

    const std::string getNome();
    const std::string getGrupoMuscular();

    int getSeries() const;
    int getSeriesConcluidas() const;
	int getRepeticoes();
	float getCarga();
};