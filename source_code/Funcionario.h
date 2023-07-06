#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "Pessoa.h"

class Funcionario : public Pessoa {
protected:
    string funcaoFuncionario;
    float salarioHora;
    float horasTrabalhadas;
    float horasExtra;
    float horasPendentes;

public:
    Funcionario(string nome, string usuario, string senha,
                string funcaoFuncionario, float salarioHora,
                float horasTrabalhadas, float horasExtra, float horasPendentes);

    virtual ~Funcionario(){}
    string getFuncaoFuncionario() const;
    void setFuncaoFuncionario(string funcaoFuncionario);

    float getSalarioHora() const;
    void setSalarioHora(float salarioHora);

    float getHorasTrabalhadas() const;
    void setHorasTrabalhadas(float horasTrabalhadas);

    float getHorasExtra() const;
    void setHorasExtra(float horasExtra);

    float getHorasPendentes() const;
    void setHorasPendentes(float horasPendentes);

    virtual void cadastraPonto();

};

#endif