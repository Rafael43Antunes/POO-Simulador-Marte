cmake_minimum_required(VERSION 4.3)
project(Projeto)

set(CMAKE_CXX_STANDARD 20)

add_executable(Projeto main.cpp
        ecra/Ecra.cpp
        ecra/Ecra.h
        terreno/Terreno.cpp
        terreno/Terreno.h
        simulador/Fabrica.cpp
        simulador/Fabrica.h
        simulador/Simulador.cpp
        simulador/Simulador.h
        comandos/Comando.cpp
        comandos/Comando.h
        comandos/ComandoFim.cpp
        comandos/ComandoFim.h
        comandos/ComandoLposicao.cpp
        comandos/ComandoLposicao.h
        comandos/Interpretador.cpp
        comandos/Interpretador.h
        comandos/ComandoFabrica.cpp
        comandos/ComandoFabrica.h
        comandos/ComandoCarrega.cpp
        comandos/ComandoCarrega.h
        itens/Item.cpp
        itens/Item.h
        maquinas/Direcao.cpp
        maquinas/Direcao.h
        maquinas/Maquina.cpp
        maquinas/Maquina.h
        maquinas/Perfuradora.cpp
        maquinas/Perfuradora.h
        maquinas/Transportador.cpp
        maquinas/Transportador.h
        maquinas/Refinaria.cpp
        maquinas/Refinaria.h
        maquinas/Oficina.cpp
        maquinas/Oficina.h
        maquinas/Lancador.cpp
        maquinas/Lancador.h
        maquinas/Silo.cpp
        maquinas/Silo.h
        comandos/ComandoAvanca.cpp
        comandos/ComandoAvanca.h
        comandos/ComandoCompra.cpp
        comandos/ComandoCompra.h
        comandos/ComandoVende.cpp
        comandos/ComandoVende.h
        comandos/ComandoRoda.cpp
        comandos/ComandoRoda.h
        comandos/ComandoEstado.cpp
        comandos/ComandoEstado.h
        comandos/ComandoAjuda.cpp
        comandos/ComandoAjuda.h
        comandos/ComandoExecuta.cpp
        comandos/ComandoExecuta.h)

target_include_directories(Projeto PRIVATE ${CMAKE_SOURCE_DIR})
