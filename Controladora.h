#pragma once
#include <vector>
#include <time.h>
#include "Contaminadores.h"
#include "Jugador.h"
#include "Obstaculo.h"
#include "Curita.h"
#include "Chatarrero.h"
#include "Bonus.h"
#include "Vacuna.h"
using namespace std;
class Controladora
{
private:
	vector<Contaminadores*>arreglo_Contaminadores;
	vector<Obstaculo*>arreglo_Obstaculos;
	vector<Bonus*>arreglo_bonus;
	Jugador* objJugador;
	Curita* objCurita;
	Vacuna* objVacuna;
	vector<Chatarrero*>arreglo_Chatarreros;
	string imagen_jugador;
	string imagen_contaminador;
	string imagen_chatarrero;
	string imagen_metales;
	string imagen_materia;
	string imagen_papeles;
	string imagen_plastico;
	string imagen_botella;
	string imagen_curita;
	string imagen_vacuna;
	string imagen_lata;
	string imagen_mapa;
	string imagen_mapados;
	bool nivel2;
	int cant_contaminadores;
	time_t tiempo_juego, insertar_chatarrero, insertar_bonus, inicio_bonus;
	vector<string>real_nombres;
public:
	Controladora();
	~Controladora();
	void Dibujar_Contaminadores(Graphics^ g, Bitmap^ bmp);
	void Dibujar_Curaciones(Graphics^g,Bitmap^bmp_curita,Bitmap^bmp_vacuna);
	void Dibujar_Basura(Graphics^g, Bitmap^ bmp_metal, Bitmap^ bmp_materiaO,
		Bitmap^ bmp_papel, Bitmap^ bmp_plastico, Bitmap^ bmp_vidrio);
	void Dibujar_Jugador(Graphics^g,Bitmap^bmp);
	void Dibujar_Chatarrero(Graphics^ g, Bitmap^ bmp);
	void Insertar_Chatarrero();
	void Dibujar_Bonus(Graphics^ g, Bitmap^ bmp);
	//Opcional para ver las restricciones
	void Dibujar_Obstaculos(Graphics^ g);
	void Desplazar(direccion nueva);
	bool Colision_Items();
	bool Colision_Deposito();
	void Colision_Herido();
	void Colision_Covid();
	void Colision_Chatarrero();
	void Colision_Chatarrero_Jugador();
	void Colision_Lata();
	bool estado(); //retorna estado para el panel
	bool covid();//retorna estado para el panel
	int retornar_tiempo();//retorna tiempo para el panel
	bool acabar_nivel1();
	bool acabar_nivel2();
	void cambiar_nivel2(bool nueva);
	void Enfermo();
	Jugador* retornar_jugador();
	System::String^ retornar_imagen_jugador();
	System::String^ retornar_imagen_contaminador();
	System::String^ retornar_imagen_chatarrero();
	System::String^ retornar_imagen_metales();
	System::String^ retornar_imagen_materia();
	System::String^ retornar_imagen_papeles();
	System::String^ retornar_imagen_plastico();
	System::String^ retornar_imagen_botella();
	System::String^ retornar_imagen_curita();
	System::String^ retornar_imagen_vacuna();
	System::String^ retornar_imagen_lata();
	System::String^ retornar_imagen_mapa();
	System::String^ retornar_imagen_mapados();
	void Grabar_puntajes(vector<string>datos);
	void Grabar_nombre(vector<string> datos);
	vector<int> retornar_rank();
	void cambiar_rank_nombres(vector<string>nombres);
	vector<string> retornar_rank_nombres();
};