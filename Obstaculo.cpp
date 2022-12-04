#include "Obstaculo.h"

Obstaculo::Obstaculo() :Base() {}
Obstaculo::Obstaculo(int px, int py, int pw, int ph) : Base(px,py,pw,ph) {}
void Obstaculo::Dibujar(Graphics^ g)
{
	Pen^ p = gcnew Pen(Color::Red,2);
	g->DrawRectangle(p, x, y, w, h);
}
Obstaculo::~Obstaculo(){}