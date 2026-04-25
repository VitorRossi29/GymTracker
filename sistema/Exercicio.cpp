#include "Exercicio.h"

Exercicio::Exercicio(
    std::string nomeP,
    std::string grupoMuscularP,
    int seriesP,
    int repeticoesP,
    float cargaP
) :
    nome(nomeP),
    grupoMuscular(grupoMuscularP),
    series(seriesP),
    repeticoes(repeticoesP),
    carga(cargaP),
    seriesConcluidas(0)
{
}

const std::string Exercicio::getNome()
{
    return nome;
}

const std::string Exercicio::getGrupoMuscular()
{
    return grupoMuscular;
}

int Exercicio::getSeries() const
{
    return series;
}

int Exercicio::getSeriesConcluidas() const
{
    return seriesConcluidas;
}

void Exercicio::setSeries(int s)
{
    if (s < 0)
        series = 0;
    else
        series = s;
}

void Exercicio::setRepeticoes(int r)
{
    if (r < 0)
        repeticoes = 0;
    else
        repeticoes = r;
}

void Exercicio::setCarga(float c)
{
    if (c < 0)
        carga = 0;
    else
        carga = c;
}

void Exercicio::setSeriesConcluidas(int s)
{
    seriesConcluidas = s;
}

void Exercicio::incrementarSerie()
{
    if (seriesConcluidas < series)
        seriesConcluidas++;
}

float Exercicio::getProgresso() const
{
    if (series == 0) return 0.0f;
    return (float)seriesConcluidas / (float)series;
}

int Exercicio::getRepeticoes() 
{ 
	return repeticoes; 
}

float Exercicio::getCarga() 
{ 
	return carga; 
}