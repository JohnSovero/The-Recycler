#pragma once
#include "Base.h"

class Obstaculo :
    public Base
{  
public:
    Obstaculo();
    Obstaculo(int px, int py, int pw, int ph);
    void Dibujar(Graphics^g);
    ~Obstaculo();
};

