#include "Vendedor.h"

Vendedor::Vendedor(string nome, string usuario, string senha,
                   string funcaoFuncionario, float salarioHora,
                   float horasTrabalhadas, float horasExtra, float horasPendentes,
                   float vendas)
    : Funcionario(nome, usuario, senha, funcaoFuncionario, salarioHora,
                  horasTrabalhadas, horasExtra, horasPendentes),
      vendas(0.0) {}

float Vendedor::getVendas() const {
    return vendas;
}

void Vendedor::setVendas(float vendas) {
    this->vendas = vendas;
}

void Vendedor::adicionarVendas(){ // Função para cadastrar uma venda
    float valor;
    cout << "Digite o valor da venda: ";
    cin >> valor;
    vendas += valor;
}

void Vendedor::exibirSalarioVendedor() { // Calculo do salário do vendedor, levando em conta 100% a hora extra e 10% de bonificação sobre as vendas
    float salarioTotal = 0;
    salarioTotal = (horasTrabalhadas + (horasExtra * 2)) * salarioHora + (vendas * 0.1);
    
    cout << "Nome do vendedor: " << getNome() << endl;
    cout << "Salário por hora: " << salarioHora << endl;
    cout << "Horas trabalhadas: " << horasTrabalhadas << endl;
    cout << "Horas extras: " << horasExtra << endl;
    cout << "Vendas realizadas: " << vendas << endl;
    cout << "Bonificação: " << (vendas * 0.1) << endl;
    cout << "Salário total: " << salarioTotal << endl;
}