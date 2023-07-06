#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <string>

using namespace std;

class Pessoa {
private:
    string nome;
    string usuario;
    string senha;
public:
    Pessoa(string nome, string usuario, string senha);

    string getNome() const;
    void setNome(string nome);

    string getUsuario() const;
    void setUsuario(string usuario);

    string getSenha() const;
    void setSenha(string senha);

    bool verificarAutenticacao(string usuario, string senha);

};

#endif