#pragma once
#include "Base.h"
class Jugador :
    public Base
{
private:
    bool ocupado;
    int cant_vidas;
    int cant_puntos;
    int tipo;
    bool herido;
    bool covid;
    bool bonus;
public:
    Jugador();
    ~Jugador();
    void Mover(Graphics^ g);
    Rectangle retornar_rectangle2(int x, int y);
    bool retornar_ocupado();
    void cambiar_ocupado(bool nuevo);
    void cambiar_cant_vidas(int nuevo);
    int retornar_cant_vidas();
    void cambiar_cant_puntos(int nuevo);
    int retornar_cant_puntos();
    int retornar_tipo();
    void cambiar_tipo(int nuevo);
    bool retornar_herido();
    void cambiar_herido(bool nuevo);
    bool retornar_covid();
    void cambiar_covid(bool nuevo);
    bool retornar_bonus();
    void cambiar_bonus(bool nuevo);
};