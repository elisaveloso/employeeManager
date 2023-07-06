#ifndef MENUCHEFE_H
#define MENUCHEFE_H

#include "Funcionario.h"
#include "Vendedor.h"
#include "Supervisor.h"
#include <vector>
#include <iostream>

using namespace std;

class MenuChefe {
public:
    Funcionario* cadastrarFuncionario();
    void listarFuncionarios(const vector<Funcionario*> &funcionarios);
    void checarPonto(Funcionario &funcionario);
};

#endif