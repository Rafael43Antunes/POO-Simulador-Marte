cmake_minimum_required(VERSION 4.3)
project(Projeto)

set(CMAKE_CXX_STANDARD 20)

add_executable(Projeto main.cpp
        Ecra/Ecra.cpp
        Ecra/Ecra.h
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
        comandos/ComandoCarrega.h)

target_include_directories(Projeto PRIVATE ${CMAKE_SOURCE_DIR})
