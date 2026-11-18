#ifndef PROJETO_SIMULADOR_H
#define PROJETO_SIMULADOR_H

#include "simulador/Fabrica.h"
#include "ecra/Ecra.h"

class Simulador {
private:
    Fabrica* fabrica;
    bool a_executar;
    Ecra ecra;

public:
    Simulador();
    ~Simulador();
    Simulador(const Simulador&) = delete;
    Simulador& operator=(const Simulador&) = delete;

    Fabrica* getFabrica() const;
    void defineFabrica(Fabrica* nova);

    bool estaAExecutar() const;
    void termina();
    
    void mostraEcra();
};

#endif //PROJETO_SIMULADOR_H