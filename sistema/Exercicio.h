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

	void setSeries(int s);
	void setRepeticoes(int r);
	void setCarga(float c);
	const std::string getNome();
	const std::string getGrupoMuscular();
};