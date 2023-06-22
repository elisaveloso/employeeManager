#include "Supervisor.h"

Supervisor::Supervisor(string nome, string usuario, string senha,
                       string funcaoFuncionario, float salarioHora,
                       float horasTrabalhadas, float horasExtra, float horasPendentes,
                       const vector<Vendedor*>& vendedores, float totalVendas)
    : Funcionario(nome, usuario, senha, funcaoFuncionario, salarioHora,
                  horasTrabalhadas, horasExtra, horasPendentes),
      vendedores(vendedores), totalVendas(0.0) {}

const vector<Vendedor*>& Supervisor::getVendedores() const {
    return vendedores;
}

void Supervisor::addVendedor(Vendedor* vendedor) {
    vendedores.push_back(vendedor);
}

void Supervisor::listarVendasVendedores() {
    for (Vendedor* vendedor : vendedores) {
        cout << "Nome do vendedor: " << vendedor->getNome() << endl;
        cout << "Vendas: " << vendedor->getVendas() << endl;
        cout << "-------------------------" << endl;
        totalVendas += vendedor->getVendas();
    }
    cout << "Total de vendas dos vendedores: " << totalVendas << endl;
}

void Supervisor::exibirSalarioSupervisor() {
    float salarioTotal = 0;
    salarioTotal = (horasTrabalhadas + (horasExtra * 2.5)) * salarioHora;
    // Calcula a bonificação dos vendedores
    float bonificacaoVendedores = 0.0;
    for (Vendedor* vendedor : vendedores) {
        bonificacaoVendedores += vendedor->getVendas() * 0.01;
    }

    salarioTotal += bonificacaoVendedores;

    cout << "Nome do supervisor: " << getNome() << endl;
    cout << "Salário por hora: " << salarioHora << endl;
    cout << "Horas trabalhadas: " << horasTrabalhadas << endl;
    cout << "Horas extras: " << horasExtra << endl;
    cout << "Bonificação dos vendedores: " << bonificacaoVendedores << endl;
    cout << "Salário total: " << salarioTotal << endl;
}