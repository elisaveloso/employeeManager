#ifndef VENDEDOR_H
#define VENDEDOR_H

#include <iostream>
#include <vector>

#include "Funcionario.h"
#include "Pessoa.h"

class Vendedor : public Funcionario {
private:
    float vendas;

public:
    Vendedor(string nome, string usuario, string senha,
             string funcaoFuncionario, float salarioHora,
             float horasTrabalhadas, float horasExtra, float horasPendentes,
             float vendas);

    float getVendas() const;
    void setVendas(float vendas);
    void adicionarVendas();
    void exibirSalarioVendedor();
};

#endif