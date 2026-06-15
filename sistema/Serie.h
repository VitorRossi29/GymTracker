#pragma once 

class Serie
{
private:
    float carga;
    unsigned int repeticoes;
    // AQUI: Adicionado a variavel de minutos
    unsigned int minutos; 
    bool concluida;
public:
    // AQUI: Construtor atualizado com valor padrao para minutos
    Serie(float carga = 0.f, unsigned int reps = 0, unsigned int min = 0);

    void setRepeticoes(int reps);
    void setCarga(float carg);
    // AQUI: Novo setter
    void setMinutos(int min); 
    void setConcluida(bool conclusao);

    const int getRepeticoes() const;
    const float getCarga() const;
    // AQUI: Novo getter
    const int getMinutos() const; 
    const bool getConcluida() const;

    bool& getConcluidaRef();
};