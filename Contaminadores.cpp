#include "Contaminadores.h"
Contaminadores::Contaminadores(int _x, int _y) :Base() {
	cambiar_x(_x);
	cambiar_y(_y);
	fraccion_movimientoX = 5;
	fraccion_movimientoY = 5;
	Desplazamiento(direccion::derecha);
	vector<string>parametros = LeerINPUT();
	System::String^ aux_col = gcnew System::String(parametros.at(5).c_str());
	cambiar_max_col(System::Convert::ToInt32(aux_col));
	System::String^ aux_fil = gcnew System::String(parametros.at(4).c_str());
	cambiar_max_fil(System::Convert::ToInt32(aux_fil));
	cambiar_col(0);
	cambiar_fil(0);
}
Contaminadores::~Contaminadores() {
	for (int i = 0; i < arr_materiaO.size(); i++)
		delete arr_materiaO.at(i);
	for (int i = 0; i < arr_metal.size(); i++)
		delete arr_metal.at(i);
	for (int i = 0; i < arr_papel.size(); i++)
		delete arr_papel.at(i);
	for (int i = 0; i < arr_plastico.size(); i++)
		delete arr_plastico.at(i);
	for (int i = 0; i < arr_vidrio.size(); i++)
		delete arr_vidrio.at(i);
}
void Contaminadores::Mover(Graphics^ g) {
	if (x + dx<1 || x + dx + w>g->VisibleClipBounds.Width)
	{
		if (orientacion == direccion::derecha)
			Desplazamiento(direccion::izquierda);
		else if (orientacion == direccion::izquierda)
			Desplazamiento(direccion::derecha);
	}
	if (y + dy<1 || y + dy + h>g->VisibleClipBounds.Height)
	{
		if (orientacion == direccion::arriba)
			Desplazamiento(direccion::abajo);
		else if (orientacion == direccion::abajo)
			Desplazamiento(direccion::arriba);
	}
	x = x + dx;
	y = y + dy;
}
void Contaminadores::Tira_Basura(bool nivel2) {
	
	int aux = rand() % 1000;
	if (aux > 990 && nivel2 == false)
	{
		int aux3 = rand() % 3;
		if (aux3 == 0)
		{
			arr_materiaO.push_back(new MateriaO(x, y));
		}
		if (aux3 == 1)
		{
			arr_plastico.push_back(new Plastico(x, y));
		}
		if (aux3 == 2)
		{
			arr_vidrio.push_back(new Vidrios(x, y));
		}
	}
	if (aux > 990 && nivel2 == true)
	{
		int aux2 = rand() % 5;
		if (aux2 == 0)
		{
			arr_metal.push_back(new Metales(x, y));
		}
		if (aux2 == 1)
		{
			arr_materiaO.push_back(new MateriaO(x, y));
		}
		if (aux2 == 2)
		{
			arr_papel.push_back(new Papeles(x, y));
		}
		if (aux2 == 3)
		{
			arr_plastico.push_back(new Plastico(x, y));
		}
		if (aux2 == 4)
		{
			arr_vidrio.push_back(new Vidrios(x, y));
		}
	}
	
}
void Contaminadores::Dibujar_Basura(Graphics^ g, Bitmap^ bmp_metal, Bitmap^ bmp_materiaO,
	Bitmap^ bmp_papel, Bitmap^ bmp_plastico, Bitmap^ bmp_vidrio) {
	for (int i = 0; i < arr_metal.size(); i++)
	{
		if (arr_metal.at(i)->retornar_eliminar() == false)
		{
			arr_metal.at(i)->Dibujar_conImagen(g, bmp_metal);
		}
		if (arr_metal.at(i)->retornar_eliminar()) //Elimina la basura
		{
			arr_metal.erase(arr_metal.begin() + i);
		}
	}
	for (int i = 0; i < arr_materiaO.size(); i++)
	{
		if (arr_materiaO.at(i)->retornar_eliminar() == false)
		{
			arr_materiaO.at(i)->Dibujar_conImagen(g, bmp_materiaO);
		}
		if (arr_materiaO.at(i)->retornar_eliminar()) //Elimina la basura
		{
			arr_materiaO.erase(arr_materiaO.begin() + i);
		}
	}
	for (int i = 0; i < arr_papel.size(); i++)
	{
		if (arr_papel.at(i)->retornar_eliminar() == false)
		{
			arr_papel.at(i)->Dibujar_conImagen(g, bmp_papel);
		}
		if (arr_papel.at(i)->retornar_eliminar()) //Elimina la basura
		{
			arr_papel.erase(arr_papel.begin() + i);
		}
	}
	for (int i = 0; i < arr_plastico.size(); i++)
	{
		if (arr_plastico.at(i)->retornar_eliminar() == false)
		{
			arr_plastico.at(i)->Dibujar_conImagen(g, bmp_plastico);
		}
		if (arr_plastico.at(i)->retornar_eliminar()) //Elimina la basura
		{
			arr_plastico.erase(arr_plastico.begin() + i);
		}
	}
	for (int i = 0; i < arr_vidrio.size(); i++)
	{
		if (arr_vidrio.at(i)->retornar_eliminar() == false)
		{
			arr_vidrio.at(i)->Dibujar_conImagen(g, bmp_vidrio);
		}
		if (arr_vidrio.at(i)->retornar_eliminar()) //Elimina la basura
		{
			arr_vidrio.erase(arr_vidrio.begin() + i);
		}
	}
}
vector<Metales*>Contaminadores::retornar_arr_metal() { return arr_metal; }
vector<MateriaO*>Contaminadores::retornar_arr_materia() { return arr_materiaO; }
vector<Papeles*>Contaminadores::retornar_arr_papel() { return arr_papel; }
vector<Plastico*>Contaminadores::retornar_arr_plastico() { return arr_plastico; }
vector<Vidrios*>Contaminadores::retornar_arr_vidrio() { return arr_vidrio; }
int Contaminadores::retornar_can_metal() { return arr_metal.size(); }
int Contaminadores::retornar_can_materia() { return arr_materiaO.size(); }
int Contaminadores::retornar_can_papel() { return arr_papel.size(); }
int Contaminadores::retornar_can_plastico() { return arr_plastico.size(); }
int Contaminadores::retornar_can_vidrio() { return arr_vidrio.size(); }
Metales* Contaminadores::retornar_metal(int i) { return arr_metal.at(i); }
MateriaO* Contaminadores::retornar_materia(int i) { return arr_materiaO.at(i); }
Papeles* Contaminadores::retornar_papel(int i) { return arr_papel.at(i); }
Plastico* Contaminadores::retornar_plastico(int i) { return arr_plastico.at(i); }
Vidrios* Contaminadores::retornar_vidrio(int i) { return arr_vidrio.at(i); }