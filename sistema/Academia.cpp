#include "Academia.h"
#include "stdlib.h"
#include "time.h"
#include <fstream>
#include <sstream>
#include <filesystem>
#include <iostream>

Academia::Academia()
{
    gruposMusculares = {
        "Peitoral", "Costas", "Ombros",
        "Biceps", "Triceps", "Pernas",
        "Panturrilha", "Abdomem"
    };
}

bool Academia::exercicioExiste(const std::string& nome)
{
    for (auto& e : todosExercicios)
    {
        if (e.getNome() == nome)
            return true;
    }
    return false;
}

void Academia::adicionarExercicio(
    std::string nome,
    std::string grupo
)
{
    if (exercicioExiste(nome))
        return;

    Exercicio novoExercicio(nome, grupo);
    todosExercicios.push_back(novoExercicio);
}

void Academia::adicionarExercicio(std::string nome,std::string grupo,int id)
{
    if (exercicioExiste(nome))
        return;

    Exercicio novoExercicio(nome,grupo);
    todosExercicios.push_back(novoExercicio);

    std::ofstream arquivo("../../../dados/exercicios.txt",std::ios::app);
	arquivo <<nome<<";"<<grupo<<";"<<id<<std::endl;
}

std::vector<Exercicio>& Academia::getExercicios()
{
    return todosExercicios;
}

void Academia::adicionarTreino(Treino t)
{
    treinos.push_back(t);

    std::ofstream arq(
        "../../../dados/treinos.txt",
        std::ios::app
    );

    if (t.getIdUsuario() == -1)
        return;

    //Nao salvar e ressalvar os treinos padroes

    if (arq.is_open())
    {
        arq
            << t.getIdUsuario() << ";"
            << t.getId() << ";"
            << t.getNome() << ";"
            << t.getDia() << "\n";
    }

    arq.close();

    std::ofstream arqExercicios(
        "../../../dados/treinos_exercicios.txt",
        std::ios::app
    );

    for (auto& ex : t.getExercicios() )
    {
        arqExercicios
            << t.getIdUsuario() << ";"
            << t.getId() << ";"
            << t.getNome() << ";"
            << ex.getNome() << ";"
            << ex.getGrupoMuscular() << "\n";
    }

    arqExercicios.close();

    std::ofstream arqSeries(
        "../../../dados/series.txt",
        std::ios::app
    );

    for (auto& ex : t.getExercicios())
    {
        auto& lista = ex.getSeries(t.getId());

        for (auto& serie : lista)
        {
            arqSeries
                << t.getIdUsuario() << ";"
                << t.getId() << ";"
                << t.getNome() << ";"
                << ex.getNome() << ";"
                << serie.getCarga() << ";"
                << serie.getRepeticoes() << "\n";
        }
    }

    arqSeries.close();
}

std::vector<Treino>& Academia::getTreinos()
{
    return treinos;
}

std::vector<std::string>& Academia::getGruposMusculares()
{
    return gruposMusculares;
}

void Academia::adicionarRecursosParaTeste()
{
    srand(time(0));

    //TREINO PARA PEITO (A)

    static Treino treinoDePeitoParaTeste("Treino de Peitoral e Triceps", "Terca");

    adicionarExercicio("Supino Reto", "Peitoral");
    adicionarExercicio("Supino Inclinado", "Peitoral");
    adicionarExercicio("Elevacao Lateral", "Ombros");
    adicionarExercicio("Triceps na Polia", "Triceps");
    adicionarExercicio("Triceps Frances", "Triceps");

    for (int i = 0; i < 5; i++)
    {
        treinoDePeitoParaTeste.adicionarExercicio(todosExercicios[i]);
        for (int j = 0; j < 3; j++)
        {
            treinoDePeitoParaTeste.getExercicios()[i].adicionarSerie(treinoDePeitoParaTeste.getId(), (float)5 + j*10, (unsigned int)12 - j*2);
        }
    }

    adicionarTreino(treinoDePeitoParaTeste);

    //TREINO PARA COSTAS (B)

    static Treino treinoDeCostasParaTeste("Treino de Costas e Biceps", "Segunda");

    adicionarExercicio("Puxada Alta", "Costas");
    adicionarExercicio("Remada na Polia", "Costas");
    adicionarExercicio("Desenvolvimento de Ombros", "Ombros");
    adicionarExercicio("Rosca Biceps", "Biceps");
    adicionarExercicio("Rosca Scott", "Biceps");

    for (int i = 0; i < 5; i++)
    {
        treinoDeCostasParaTeste.adicionarExercicio(todosExercicios[i+5]);
        for (int j = 0; j < 3 + rand() % 3; j++)
        {
            treinoDeCostasParaTeste.getExercicios()[i].adicionarSerie(treinoDeCostasParaTeste.getId(), (float)10 + rand() % 11, (unsigned int)6 + rand() % 7);
        }
    }

    adicionarTreino(treinoDeCostasParaTeste);

    //TREINO PARA PERNAS (C)

    static Treino treinoDePernasParaTeste("Treino de Pernas e Abdomen", "Quarta");

    adicionarExercicio("LegPress", "Pernas");
    adicionarExercicio("Cadeira Extensora", "Pernas");
    adicionarExercicio("Mesa Flexora", "Pernas");
    adicionarExercicio("Agachamento", "Pernas");
    adicionarExercicio("Abdominal", "Abdomen");

    for (int i = 0; i < 5; i++)
    {
        treinoDePernasParaTeste.adicionarExercicio(todosExercicios[i+10]);
        for (int j = 0; j < 3 + rand() % 3; j++)
        {
            treinoDePernasParaTeste.getExercicios()[i].adicionarSerie(treinoDePernasParaTeste.getId(), (float)10 + rand() % 11, (unsigned int)6 + rand() % 7);
        }
    }
    adicionarTreino(treinoDePernasParaTeste);
}

void Academia::carregarTreinos(int idUsuario)
{
    std::cout << std::filesystem::current_path().string() << std::endl;

    treinos.clear();

    adicionarRecursosParaTeste();

    std::ifstream arq("../../../dados/treinos.txt");

    std::string linha;

    std::string idTreino;
    std::string nomeTreino;
    std::string diaTreino;

    while (std::getline(arq, linha))
    {
        size_t p1 = linha.find(';');
        size_t p2 = linha.find(';', p1 + 1);
        size_t p21 = linha.find(';', p2 + 1);

        if (p1 != std::string::npos &&
            p2 != std::string::npos &&
            p21 != std::string::npos)
        {
            std::string idUsuarioTreino = linha.substr(0, p1);
            std::string idTreino = linha.substr(p1 + 1, p2 - p1 - 1);
            std::string nomeTreino = linha.substr(p2 + 1, p21 - p2 - 1);
            std::string diaTreino = linha.substr(p21 + 1);

            if (std::stoi(idUsuarioTreino) == idUsuario)
            {
                Treino t(nomeTreino, diaTreino, std::stoi(idTreino));
                treinos.push_back(t);
            }
        }
        
    }

    std::string linhaExercicio;

    std::string idUsuarioExercicio;
    std::string idTreinoAssociado;
    std::string nomeDoTreinoDoExercicio;
    std::string nomeExercicio;
    std::string grupoMuscular;

    std::ifstream arqExer("../../../dados/treinos_exercicios.txt");

    while (std::getline(arqExer, linhaExercicio))
    {
        size_t p3 = linhaExercicio.find(';');
        size_t p4 = linhaExercicio.find(';', p3 + 1);
        size_t p5 = linhaExercicio.find(';', p4 + 1);
        size_t p6 = linhaExercicio.find(';', p5 + 1);

        if (p3 != std::string::npos &&
            p4 != std::string::npos &&
            p5 != std::string::npos &&
            p6 != std::string::npos)
        {
            std::string idUsuarioExercicio = linhaExercicio.substr(0, p3);
            std::string idTreinoAssociado = linhaExercicio.substr(p3 + 1, p4 - p3 - 1);
            std::string nomeDoTreinoDoExercicio = linhaExercicio.substr(p4 + 1, p5 - p4 - 1);
            std::string nomeExercicio = linhaExercicio.substr(p5 + 1, p6 - p5 - 1);
            std::string grupoMuscular = linhaExercicio.substr(p6 + 1);

            if (std::stoi(idUsuarioExercicio) == idUsuario)
            {
                for (int i = 0; i < treinos.size(); i++)
                {
                    if (std::stoi(idTreinoAssociado) == treinos[i].getId())
                    {
                        /*bool exercicioJaExiste = false;
                        for (auto& ex : todosExercicios)
                        {
                            if (ex.getNome() == nomeExercicio)
                            {
                                treinos[i].adicionarExercicio(ex);
                                exercicioJaExiste = true;
                                break;
                            }
                        }

                        if (!exercicioJaExiste)
                        {
                            Exercicio exercicioEncontrado(
                                nomeExercicio,
                                grupoMuscular
                            );

                            adicionarExercicio(exercicioEncontrado);

                            treinos[i].adicionarExercicio(exercicioEncontrado);
                        }*/

                        adicionarExercicio(nomeExercicio, grupoMuscular, std::stoi(idUsuarioExercicio));

                        for (auto& ex : todosExercicios)
                        {
                            if (ex.getNome() == nomeExercicio)
                            {
                                treinos[i].adicionarExercicio(ex);
                                break;
                            }
                        }

                        
                    }
                }
            }
        }

    }

    std::string linhaSerie;

    std::string idUsuarioSerie;
    std::string idTreinoAssociadoSerie;
    std::string nomeDoTreinoDaSerie;
    std::string nomeExercicioDaSerie;
    std::string carga;
    std::string repeticoes;

    std::ifstream arqSeries("../../../dados/series.txt");

    while (std::getline(arqSeries, linhaSerie))
    {
        size_t p7 = linhaSerie.find(';');
        size_t p8 = linhaSerie.find(';', p7 + 1);
        size_t p9 = linhaSerie.find(';', p8 + 1);
        size_t p10 = linhaSerie.find(';', p9 + 1);
        size_t p11 = linhaSerie.find(';', p10 + 1);

        if (p7 != std::string::npos &&
            p8 != std::string::npos &&
            p9 != std::string::npos &&
            p10 != std::string::npos &&
            p11 != std::string::npos)
        {
            std::string idUsuarioSerie = linhaSerie.substr(0, p7);
            std::string idTreinoAssociadoSerie = linhaSerie.substr(p7 + 1, p8 - p7 - 1);
            std::string nomeDoTreinoDaSerie = linhaSerie.substr(p8 + 1, p9 - p8 - 1);
            std::string nomeExercicioDaSerie = linhaSerie.substr(p9 + 1, p10 - p9 - 1);
            std::string carga = linhaSerie.substr(p10 + 1, p11 - p10 - 1);
            std::string repeticoes = linhaSerie.substr(p11 + 1);

            if (std::stoi(idUsuarioSerie) == idUsuario) //Verifica mesmo usuario
            {
                for (auto& treino : treinos)
                {
                    if (treino.getId() == std::stoi(idTreinoAssociadoSerie))    //Verifica mesmo treino
                    {
                        for (auto& ex : treino.getExercicios())
                        {
                            if (ex.getNome() == nomeExercicioDaSerie)       //Verifica mesmo exercicio
                            {
                                ex.adicionarSerie(
                                    treino.getId(),
                                    std::stof(carga),
                                    std::stoi(repeticoes)
                                );

                                break;
                            }
                        }
                    }
                }
            }
        }

    }       //while
}
