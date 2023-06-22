#include "MenuChefe.h"

Funcionario* MenuChefe::cadastrarFuncionario() {
    string nome, usuario, senha, funcaoFuncionario;
    float salarioHora = 0.0;
    float horasTrabalhadas = 0.0;
    float horasExtra = 0.0;
    float horasPendentes = 40.0;

    cout << "Digite o nome do funcionário: ";
    cin >> nome;
    cout << "Digite o nome de usuário: ";
    cin >> usuario;
    cout << "Digite a senha: ";
    cin >> senha;
    cout << "Digite a função do funcionário: ";
    cin >> funcaoFuncionario;
    cout << "Digite o salário por hora: ";
    cin >> salarioHora;

    Funcionario* novoFuncionario = nullptr;

    if (funcaoFuncionario == "vendedor") {
        float vendas = 0.0;
        novoFuncionario = new Vendedor(nome, usuario, senha, funcaoFuncionario, salarioHora, horasTrabalhadas, horasExtra, horasPendentes, vendas);
    } else if (funcaoFuncionario == "supervisor") {
        vector<Vendedor*> vendedores;
        float totalVendas = 0.0;
        novoFuncionario = new Supervisor(nome, usuario, senha, funcaoFuncionario, salarioHora, horasTrabalhadas, horasExtra, horasPendentes, vendedores, totalVendas);
    } else {
        cout << "Função inválida." << endl;
        return nullptr;
    }

    return novoFuncionario;
}


void MenuChefe::listarFuncionarios(const vector<Funcionario*>& funcionarios) {
    cout << "Lista de Funcionários:" << endl;
    for (const Funcionario* funcionario : funcionarios) {
        cout << "Nome: " << funcionario->getNome() << endl;
        cout << "Função: " << funcionario->getFuncaoFuncionario() << endl;
        cout << "Salário por Hora: " << funcionario->getSalarioHora() << endl;
        cout << "-------------------------" << endl;
    }
}

void MenuChefe::checarPonto(Funcionario& funcionario) {
    cout << "Nome do funcionario: " << funcionario.getNome() << endl;
    cout << "Horas Trabalhadas: " << funcionario.getHorasTrabalhadas() << endl;
    cout << "Horas Extras: " << funcionario.getHorasExtra() << endl;
    cout << "Horas Pendentes: " << funcionario.getHorasPendentes() << endl;
    cout << "-------------------------" << endl;
}

