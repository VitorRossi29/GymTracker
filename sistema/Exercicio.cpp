#include "Exercicio.h"

Exercicio::Exercicio(std::string nomeP, std::string grupoMuscularP, int seriesP, int repeticoesP, float cargaP) : 
	nome(nomeP),
	grupoMuscular(grupoMuscularP),
	series(seriesP),
	repeticoes(repeticoesP),
	carga(cargaP)
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

void Exercicio::setSeries(int s) 
{ 
	series = s; 
}

void Exercicio::setRepeticoes(int r) 
{ 
	repeticoes = r; 
}

void Exercicio::setCarga(float c) 
{ 
	carga = c; 
}