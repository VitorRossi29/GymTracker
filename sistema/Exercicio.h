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
public:
	Exercicio(std::string nomeP = " nome",
				std::string grupoMuscularP = "",
				int seriesP = 0,
				int repeticoesP = 0,
				float cargaP = 0
			);
	const std::string getNome();
	const std::string getGrupoMuscular();
};