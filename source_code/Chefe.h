#ifndef CHEFE_H
#define CHEFE_H

#include "Pessoa.h"

class Chefe : public Pessoa{
public:
    Chefe(string nome, string usuario, string senha);
};

#endif