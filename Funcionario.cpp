#include "Funcionario.h"

Funcionario::Funcionario(string nome, string usuario, string senha,
                         string funcaoFuncionario, float salarioHora,
                         float horasTrabalhadas, float horasExtra, float horasPendentes)
    : Pessoa(nome, usuario, senha), funcaoFuncionario(funcaoFuncionario),
      salarioHora(salarioHora), horasTrabalhadas(0.0),
      horasExtra(0.0), horasPendentes(40.0) {}


string Funcionario::getFuncaoFuncionario() const
{
    return funcaoFuncionario;
}

void Funcionario::setFuncaoFuncionario(string funcaoFuncionario)
{
    this->funcaoFuncionario = funcaoFuncionario;
}

float Funcionario::getSalarioHora() const
{
    return salarioHora;
}

void Funcionario::setSalarioHora(float salarioHora)
{
    this->salarioHora = salarioHora;
}

float Funcionario::getHorasTrabalhadas() const
{
    return horasTrabalhadas;
}

void Funcionario::setHorasTrabalhadas(float horasTrabalhadas)
{
    this->horasTrabalhadas = horasTrabalhadas;
}

float Funcionario::getHorasExtra() const
{
    return horasExtra;
}

void Funcionario::setHorasExtra(float horasExtra)
{
    this->horasExtra = horasExtra;
}

float Funcionario::getHorasPendentes() const
{
    return horasPendentes;
}

void Funcionario::setHorasPendentes(float horasPendentes)
{
    this->horasPendentes = horasPendentes;
}

void Funcionario::cadastraPonto()
{
    string horarioInicio;
    string horarioFinal;

    cout << "Digite o horário de início (HH:MM): ";
    cin >> horarioInicio;
    cout << "Digite o horário final (HH:MM): ";
    cin >> horarioFinal;

    // Extrai as horas e minutos do horário de início
    int horaInicio = stoi(horarioInicio.substr(0, 2));
    int minutoInicio = stoi(horarioInicio.substr(3, 2));

    // Extrai as horas e minutos do horário final
    int horaFinal = stoi(horarioFinal.substr(0, 2));
    int minutoFinal = stoi(horarioFinal.substr(3, 2));

    // Calcula a duração do expediente em horas e minutos
    int horasTrabalhadas = horaFinal - horaInicio;
    int minutosTrabalhados = minutoFinal - minutoInicio;

    // Verifica se houve horas extras
    if (horasTrabalhadas > 8)
    {
        int horasNormais = 8;
        int minutosNormais = 0;

        int horasExtras = horasTrabalhadas - 8;
        int minutosExtras = minutosTrabalhados;

        // Limita as horas extras a no máximo 10 horas
        if (horasExtras > 2)
        {
            cout << "Hora Extra limitada a 2 horas/dia" << endl;
            horasExtras = 2;
            minutosExtras = 0;
        }

        // Atualiza as horas extras
        this->horasExtra += horasExtras + minutosExtras / 60.0;
        // Atualiza as horas trabalhadas normais
        this->horasTrabalhadas += horasNormais + minutosNormais / 60.0;
    }
    else
    {
        // Atualiza apenas as horas trabalhadas
        this->horasTrabalhadas += horasTrabalhadas + minutosTrabalhados / 60.0;
    }

    // Atualiza as horas pendentes
    this->horasPendentes -= (horasTrabalhadas + minutosTrabalhados / 60.0);

    cout << "Ponto registrado com sucesso!" << endl;
}
