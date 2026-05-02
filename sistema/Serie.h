#pragma once

class Serie
{
private:
	float carga;
    unsigned int repeticoes;
    bool concluida;
public:
	Serie(float carga = 0.f, unsigned int reps = 0);

    void setRepeticoes(int reps);
    void setCarga(float carg);
    void setConcluida(bool conclusao);

    const int getRepeticoes() const;
    const float getCarga() const;
    const bool getConcluida() const;

    bool& getConcluidaRef();
};