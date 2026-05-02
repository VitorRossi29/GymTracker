#include "Serie.h"
#include "Exercicio.h"

Serie::Serie(float carg, unsigned int reps) :
	carga(carg),
	repeticoes(reps),
	concluida(false)
{
}

void Serie::setRepeticoes(int reps)
{
    if (reps < 0)
        repeticoes = 0;
    else
        repeticoes = reps;
}

void Serie::setCarga(float carg)
{
    if (carg < 0)
        carga = 0;
    else
        carga = carg;
}

const int Serie::getRepeticoes() const
{
    return repeticoes;
}


const float Serie::getCarga() const
{
    return carga;
}

void Serie::setConcluida(bool conclusao)
{
    concluida = conclusao;
}

const bool Serie::getConcluida() const
{
    return concluida;
}

bool& Serie::getConcluidaRef()
{
    return concluida;
}
