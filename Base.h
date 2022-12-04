#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace System::Drawing;
using namespace std;
public enum direccion {arriba,izquierda,abajo,derecha,ninguno};
class Base
{
	protected:
		int x, y, w, h, dx, dy;
		bool eliminar;
		int max_fil, max_col, fil, col; //Sprites
		direccion orientacion;
		int fraccion_movimientoX, fraccion_movimientoY; //Relacion con el Weight y Height
	public:
		Base();
		Base(int px, int py, int pw, int ph);
		Base(int px, int py, int pw, int ph, int pmaxfil, int pmaxcol, int pfil, int pcol);
		~Base();
		void cambiar_x(int nuevo);
		void cambiar_y(int nuevo);
		void cambiar_fraccion_movimientoX(int nuevo);
		void cambiar_fraccion_movimientoY(int nuevo);
		void cambiar_dx(int nuevo);
		void cambiar_dy(int nuevo);
		void cambiar_w(int nuevo);
		void cambiar_h(int nuevo);
		void cambiar_max_fil(int nuevo);
		void cambiar_max_col(int nuevo);
		void cambiar_fil(int nuevo);
		void cambiar_col(int nuevo);
		void cambiar_eliminar(bool nuevo);
		void Desplazamiento(direccion nuevo);
		void Desplazamiento_Items();
		int retornar_x();
		int retornar_y();
		int retornar_fraccion_movimientoX();
		int retornar_fraccion_movimientoY();
		int retornar_dx();
		int retornar_dy();
		int retornar_w();
		int retornar_h();
		int retornar_max_fil();
		int retornar_max_col();
		bool retornar_eliminar();
		virtual Rectangle retornar_rectangle();
		Rectangle retornar_rectangle(int w, int h);
		virtual void Mover(Graphics ^g);
		void Dibujar(Graphics^ g);
		void Dibujar_conImagen(Graphics^ g, Bitmap^ bmp);
		void Borrar(Graphics^ g);
		direccion retornar_orientacion();
		vector<string>LeerINPUT();
		vector<string>LeerOUTPUT();
		vector<string>LeerOUTPUT2();
		void GrabarOUTPUT(vector<string>datos);
		void GrabarOUTPUT2(vector<string> datos);
};

