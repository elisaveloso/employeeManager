/* GRUPO: BRUNA CRISTINA GONCALVES - 20.2.4123
          ELISA ALVES VELOSO - 20.2.4006
          LAVÍNIA FONSECA PEREIRA - 19.1.4170
          LUCAS GOMES DOS SANTOS - 20.1.4108

*/
#include <iostream>
#include <vector>
#include "Chefe.h"
#include "Funcionario.h"
#include "Vendedor.h"
#include "Supervisor.h"
#include "MenuChefe.h"

using namespace std;

int main()
{
    string nome, usuario, senha;
    cout << "=== Bem vindo ao gerenciador de funcionários  ===" << endl;
    cout << "=== Para iniciar o sistema, crie o login de um chefe  ===" << endl;
    cout << "Digite o nome do chefe:" << endl;
    getline(cin, nome);
    cout << "Digite o usuário do chefe:" << endl;
    cin >> usuario;
    cout << "Digite a senha do chefe:" << endl;
    cin >> senha;
    Chefe chefe(nome, usuario, senha);

    vector<Funcionario *> funcionarios;  // Vetor de ponteiros para guardar todos os funcionários
    MenuChefe menuChefe;

    while (true)
    {
        cout << "=== Tela Inicial ===" << endl;
        cout << "1. Menu Chefe" << endl;
        cout << "2. Menu Funcionário" << endl;
        cout << "3. Sair do sistema" << endl;

        int opcao;
        cin >> opcao;

        if (opcao == 1)
        {
            string usuario, senha;
            cout << "Digite o usuário do chefe: ";
            cin >> usuario;
            cout << "Digite a senha do chefe: ";
            cin >> senha;

            if (chefe.verificarAutenticacao(usuario, senha)) // Verifica autenticação do chefe
            {
                while (true)
                {
                    cout << "=== Menu Chefe ===" << endl;
                    cout << "1. Cadastrar funcionário" << endl;
                    cout << "2. Listar funcionários cadastrados" << endl;
                    cout << "3. Checar ponto" << endl;
                    cout << "4. Cálculo do salário" << endl;
                    cout << "5. Retornar à tela inicial" << endl;

                    cin >> opcao;

                    if (opcao == 1)
                    {
                        Funcionario *novoFuncionario = menuChefe.cadastrarFuncionario(); // Cadastra novo funcionário
                        if (novoFuncionario != nullptr)
                        {
                            funcionarios.push_back(novoFuncionario); // Adiciona novo funcionário ao vetor de funcionários
                            cout << "Funcionário cadastrado com sucesso!" << endl;
                        }
                        else
                        {
                            cout << "Não foi possível cadastrar funcionário!" << endl;
                        }
                    }
                    else if (opcao == 2)
                    {
                        menuChefe.listarFuncionarios(funcionarios); // Lista os funcionários cadastrados
                    }
                    else if (opcao == 3)
                    {
                        string nomeFuncionario;
                        cout << "Digite o nome do funcionário: ";
                        cin >> nomeFuncionario;

                        bool encontrado = false;
                        for (Funcionario *funcionario : funcionarios)
                        {
                            if (funcionario->getNome() == nomeFuncionario)
                            {
                                menuChefe.checarPonto(*funcionario); // Checa as horas de um funcionário
                                encontrado = true;
                                break;
                            }
                        }

                        if (!encontrado)
                        {
                            cout << "Funcionário não encontrado." << endl;
                        }
                    }
                    else if (opcao == 4)
                    {
                        string nomeFuncionario;
                        cout << "Digite o nome do funcionário: ";
                        cin >> nomeFuncionario;

                        bool encontrado = false;
                        for (Funcionario *funcionario : funcionarios)
                        {
                            if (funcionario->getNome() == nomeFuncionario)
                            {
                                encontrado = true;
                                if (Vendedor *vendedor = dynamic_cast<Vendedor *>(funcionario))
                                {
                                    vendedor->exibirSalarioVendedor(); // Calcula salário vendedor
                                }
                                else if (Supervisor *supervisor = dynamic_cast<Supervisor *>(funcionario))
                                {
                                    supervisor->exibirSalarioSupervisor(); // Calcula salário supervisor
                                }

                                break;
                            }
                        }

                        if (!encontrado)
                        {
                            cout << "Funcionário não encontrado." << endl;
                        }
                    }
                    else if (opcao == 5)
                    {
                        break; // Retorna a tela principal
                    }
                    else
                    {
                        cout << "Opção inválida." << endl;
                    }
                }
            }
            else
            {
                cout << "Usuário ou senha inválidos." << endl;
            }
        }
        else if (opcao == 2)
        { // Menu dos funcionários
            string usuario, senha;
            cout << "Digite o usuário do funcionário:" << endl;
            cin >> usuario;
            cout << "Digite a senha do funcionário:" << endl;
            cin >> senha;

            bool encontrado = false;
            Funcionario *funcionarioAutenticado = nullptr;
            for (Funcionario *funcionario : funcionarios)
            {
                if (funcionario->verificarAutenticacao(usuario, senha)) // Verifica autenticação do funcionário
                {
                    encontrado = true;
                    funcionarioAutenticado = funcionario;
                    break;
                }
            }

            if (encontrado)
            {
                while(true)
                {
                    cout << "=== Menu dos Funcionários ===" << endl;
                    cout << "Selecione a opção desejada:" << endl;
                    cout << "1. Cadastrar ponto" << endl;
                    cout << "2. Exibir salário detalhado" << endl;
                    cout << "3. Cadastrar venda" << endl;
                    cout << "4. Listar vendas" << endl;
                    cout << "5. Adicionar um vendedor a um supervisor" << endl;
                    cout << "6. Retornar à tela inicial" << endl;
                    cout << "Opção: ";
                    cin >> opcao;

                    if(opcao == 1)
                    {
                        funcionarioAutenticado->cadastraPonto(); // Registra o ponto do funcionário
                    }
                    else if(opcao == 2){
                        // Exibir salário detalhado
                        if (Vendedor *vendedor = dynamic_cast<Vendedor *>(funcionarioAutenticado))
                        {
                            vendedor->exibirSalarioVendedor();
                        }
                        else if (Supervisor *supervisor = dynamic_cast<Supervisor *>(funcionarioAutenticado))
                        {
                            supervisor->exibirSalarioSupervisor();
                        }
                        else
                        {
                            cout << "Funcionário não tem salário detalhado" << endl;
                        }
                    }
                    else if (opcao == 3){
                        // Cadastrar venda de um vendedor
                        if (Vendedor *vendedor = dynamic_cast<Vendedor *>(funcionarioAutenticado))
                        {
                            vendedor->adicionarVendas();
                        }
                        else
                        {
                            cout << "Apenas vendedores podem cadastrar vendas" << endl;
                        }
                    }
                    else if(opcao == 4)
                    {
                        // Listar vendas
                        if (Supervisor *supervisor = dynamic_cast<Supervisor *>(funcionarioAutenticado))
                        {
                            supervisor->listarVendasVendedores();
                        }
                        else if (Vendedor *vendedor = dynamic_cast<Vendedor *>(funcionarioAutenticado))
                        {
                            cout << "Vendas realizadas: " << vendedor->getVendas() << endl;
                        }
                    }
                    else if(opcao == 5){
                        // Adiciona Vendedor a um Supervisor
                        if (Supervisor *supervisor = dynamic_cast<Supervisor *>(funcionarioAutenticado))
                        {
                            string nomeVendedor;
                            cout << "Digite o nome do vendedor a ser adicionado: ";
                            cin >> nomeVendedor;

                            // Encontrar o vendedor pelo nome (supondo que cada vendedor tenha um nome único)
                            Vendedor *vendedorExistente = nullptr;
                            for (Funcionario *funcionario : funcionarios)
                            {
                                if (Vendedor *vendedor = dynamic_cast<Vendedor *>(funcionario))
                                {
                                    if (vendedor->getNome() == nomeVendedor)
                                    {
                                        vendedorExistente = vendedor;
                                        break;
                                    }
                                }
                            }

                            if (vendedorExistente)
                            {
                                supervisor->addVendedor(vendedorExistente);
                                cout << "Vendedor adicionado com sucesso!" << endl;
                            }
                            else
                            {
                                cout << "Vendedor não encontrado." << endl;
                            }
                        }
                        else
                        {
                            cout << "Apenas supervisores podem adicionar vendedores" << endl;
                        }
                    }
                    else if(opcao == 6)
                    {
                        break;
                    }
                    else{
                        cout << "Opção inválida." << endl;
                    }
                }
            }
            else
            {
                cout << "Usuário ou senha incorretos. Acesso negado." << endl;
            }
        }
        else if (opcao == 3)
        {
            cout << "Saindo do sistema..." << endl;
            break;
        }
        else
        {
            cout << "Opção inválida." << endl;
        }
    }

    // Libera a memória dos funcionários alocados dinamicamente
    for (Funcionario *funcionario : funcionarios)
    {
        delete funcionario;
    }

    return 0;
}