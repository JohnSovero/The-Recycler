#include "Jugador.h"
Jugador::Jugador():Base()
{
	cambiar_x(250);
	cambiar_y(170);
	fraccion_movimientoX = 4;
	fraccion_movimientoY = 4;
	Desplazamiento(direccion::derecha);
	vector<string>parametros = LeerINPUT();
	System::String^ aux_col = gcnew System::String(parametros.at(2).c_str());
	cambiar_max_col(System::Convert::ToInt32(aux_col));
	System::String^ aux_fil = gcnew System::String(parametros.at(1).c_str());
	cambiar_max_fil(System::Convert::ToInt32(aux_fil));
	cambiar_col(0);
	cambiar_fil(0);
	ocupado = false;// bool que determina si el jugador tiene basura en la mano
	cant_vidas = 3;
	cant_puntos = 0;
	tipo = 0;// 1 = lleva metal, 2 = lleva materia, 3 = lleva papel, 4 = lleva plastico, 5 = lleva vidrio
	herido = false;
	covid = false;
	bonus = false;
}
Jugador::~Jugador() {}
void Jugador::Mover(Graphics^ g) {
	if (x + dx<1 || x + dx + w>g->VisibleClipBounds.Width) dx = 0;
	if (y + dy<1 || y + dy + h>g->VisibleClipBounds.Height) dy = 0;
	x = x + dx;
	y = y + dy;
}
Rectangle Jugador::retornar_rectangle2(int x, int y) { return Rectangle(x, y, w, h); }
bool Jugador::retornar_ocupado() { return ocupado; }
void Jugador::cambiar_ocupado(bool nuevo) {ocupado = nuevo;}
void Jugador::cambiar_cant_vidas(int nuevo) { cant_vidas = nuevo; }
int Jugador::retornar_cant_vidas() { return cant_vidas; }
void Jugador::cambiar_cant_puntos(int nuevo) { cant_puntos = nuevo; }
int Jugador::retornar_cant_puntos() { return cant_puntos; }
int Jugador::retornar_tipo() { return tipo; }
void Jugador::cambiar_tipo(int nuevo) { tipo = nuevo; }
bool Jugador::retornar_herido() { return herido; }
void Jugador::cambiar_herido(bool nuevo) { herido = nuevo; }
bool Jugador::retornar_covid() { return covid; }
void Jugador::cambiar_covid(bool nuevo) { covid = nuevo; }
bool Jugador::retornar_bonus() { return bonus; }
void Jugador::cambiar_bonus(bool nuevo) { bonus = nuevo; }