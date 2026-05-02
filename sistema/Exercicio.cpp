#include "Exercicio.h"
#include "Serie.h"
#include <stdexcept>

Exercicio::Exercicio(std::string nomeP, std::string grupoMuscularP) :
    nome(nomeP),
    grupoMuscular(grupoMuscularP)
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

//Importante
int Exercicio::getNumeroDeSeries(unsigned int idTreino)
{
    if(!seriesEmSi[idTreino].empty())
        return seriesEmSi[idTreino].size();
    return 0;
}

int Exercicio::getSeriesConcluidas(unsigned int idTreino)
{
    int seriesConcluidas = 0;
    int i = 0;

    if (seriesEmSi[idTreino].empty())
        return 0;

    for(i = 0; i < seriesEmSi[idTreino].size(); i++)
    {
        if (seriesEmSi[idTreino][i].getConcluida() == true)
            seriesConcluidas++;
    }

    return seriesConcluidas;
}

bool& Exercicio::getConcluidaRef(int idTreino, int idSerie)
{
       if (idSerie >= seriesEmSi[idTreino].size())
        throw std::out_of_range("idSerie invalido");

    return seriesEmSi[idTreino][idSerie].getConcluidaRef();
}

void Exercicio::setSeriesConcluidas(unsigned int idTreino, int s, bool conc)
{
    if (seriesEmSi[idTreino].empty())
        return;

    int i;
    for (i = 0; seriesEmSi[idTreino].size() && i < s; i++)
    {
        seriesEmSi[idTreino][i].setConcluida(conc);
    }
}

void Exercicio::concluirSerie(unsigned int idTreino, int idSerie)
{
    if (seriesEmSi[idTreino].empty())
        return;
    
    seriesEmSi[idTreino][idSerie].setConcluida(true);
}

//void Exercicio::incrementarSerie(unsigned int idTreino)
//{
//    if (getSeriesConcluidas(idTreino) < getNumeroDeSeries(idTreino))
//        serieEmsI[idTreino]++;
//}

float Exercicio::getProgresso(unsigned int idTreino)
{
    if (getNumeroDeSeries(idTreino) == 0) 
        return 0.0f;
    return (float) getSeriesConcluidas(idTreino) / (float) getNumeroDeSeries(idTreino);
}

const int Exercicio::getRepeticoes(unsigned int idTreino, unsigned int idSerie) 
{
    return seriesEmSi[idTreino][idSerie].getRepeticoes();
}


const float Exercicio::getCarga(unsigned int idTreino, unsigned int idSerie)
{
    return seriesEmSi[idTreino][idSerie].getCarga();
}

void Exercicio::adicionarSerie(unsigned int idTreino, float car, unsigned int reps)
{
    Serie novaSerie(car, reps);
    seriesEmSi[idTreino].push_back(novaSerie);
}

std::vector<Serie>& Exercicio::getSeries(unsigned int idTreino)
{
    return seriesEmSi[idTreino];
}


