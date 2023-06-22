#include "Pessoa.h"

Pessoa::Pessoa(string nome, string usuario, string senha)  {
    this->nome = nome;
    this->usuario = usuario;
    this->senha = senha;
}


string Pessoa::getNome() const{
    return nome;
}

void Pessoa::setNome(string nome){
    this->nome = nome;
}

string Pessoa::getUsuario() const{
    return usuario;
}

void Pessoa::setUsuario(string usuario){
    this->usuario = usuario;
}

string Pessoa::getSenha() const{
    return senha;
}

void Pessoa::setSenha(string senha){
    this->senha = senha;
}

bool Pessoa::verificarAutenticacao(string usuario, string senha){
    return (this->usuario == usuario && this->senha == senha);
}