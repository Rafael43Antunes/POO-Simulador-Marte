#ifndef PROJETO_SIMULADOR_H
#define PROJETO_SIMULADOR_H

#include "simulador/Fabrica.h"


class Simulador {
private:
    Fabrica* fabrica;
    bool a_executar;

public:
    Simulador();
    ~Simulador();
    Simulador(const Simulador&) = delete;
    Simulador& operator=(const Simulador&) = delete;

    Fabrica* getFabrica() const ;

    void defineFabrica(Fabrica* nova);

    bool estaAExecutar() const;
    void termina();
};


#endif //PROJETO_SIMULADOR_H
