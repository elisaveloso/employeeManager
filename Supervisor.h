#ifndef SUPERVISOR_H
#define SUPERVISOR_H

#include <iostream>
#include <vector>

#include "Funcionario.h"
#include "Vendedor.h"

class Supervisor : public Funcionario {
private:
    vector<Vendedor*> vendedores;
    float totalVendas;

public:
    Supervisor(string nome, string usuario, string senha,
               string funcaoFuncionario, float salarioHora,
               float horasTrabalhadas, float horasExtra, float horasPendentes,
               const vector<Vendedor*>& vendedores, float totalVendas);

    const vector<Vendedor*>& getVendedores() const;
    void addVendedor(Vendedor* vendedor);
    void listarVendasVendedores();
    void exibirSalarioSupervisor();
};

#endif