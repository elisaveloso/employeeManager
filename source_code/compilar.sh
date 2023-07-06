#!/bin/bash

# Comando para compilar os arquivos .cpp e gerar o executável

g++ -std=c++11 \
    Chefe.cpp \
    Chefe.h \
    Funcionario.cpp \
    Funcionario.h \
    main.cpp \
    MenuChefe.cpp \
    MenuChefe.h \
    Pessoa.cpp \
    Pessoa.h \
    Supervisor.cpp \
    Supervisor.h \
    Vendedor.cpp \
    Vendedor.h -o executavel