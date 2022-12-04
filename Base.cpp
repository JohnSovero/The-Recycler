#include "Base.h"
Base::Base(){
	dx = dy = 0;
	orientacion = direccion::ninguno;
	eliminar = false;
}
Base::Base(int px, int py, int pw, int ph) /*solo imagen*/ {
	x = px;
	y = py;
	w = pw;
	h = ph;
	dx = dy = 0;
	orientacion = direccion::ninguno;
	eliminar = false;
}
Base::Base(int px, int py, int pw, int ph, int pmaxfil, int pmaxcol, int pfil, int pcol)/*con sprites*/ {
	x = px;
	y = py;
	w = pw;
	h = ph;
	max_fil = pmaxfil;
	max_col = pmaxcol;
	fil = pfil;
	col = pcol;
	dx = dy = 0;
	orientacion = direccion::ninguno;
	eliminar = false;
}
Base::~Base(){}
void Base::cambiar_x(int nuevo) { x = nuevo; }
void Base::cambiar_y(int nuevo) { y = nuevo; }
void Base::cambiar_dx(int nuevo) { dx = nuevo; }
void Base::cambiar_dy(int nuevo) { dy = nuevo; }
void Base::cambiar_w(int nuevo) { w = nuevo; }
void Base::cambiar_h(int nuevo) { h = nuevo; }
void Base::cambiar_max_fil(int nuevo) { max_fil = nuevo; }
void Base::cambiar_max_col(int nuevo) { max_col = nuevo; }
void Base::cambiar_fil(int nuevo) { fil = nuevo; }
void Base::cambiar_col(int nuevo) { col = nuevo; }
void Base::cambiar_eliminar(bool nuevo) { eliminar = nuevo;}
void Base::Desplazamiento(direccion nuevo){
	orientacion = nuevo;
	dx = dy = 0;
	if (orientacion == direccion::arriba) { dy = -(h / fraccion_movimientoY); fil = 3; }
	if (orientacion == direccion::abajo) { dy = (h / fraccion_movimientoY); fil = 0; }
	if (orientacion == direccion::izquierda) { dx = -(w / fraccion_movimientoX); fil = 1; }
	if (orientacion == direccion::derecha) { dx = (w / fraccion_movimientoX); fil = 2; }
}
void Base::Desplazamiento_Items() {
	dx = dy = 0;
	if (orientacion == direccion::arriba) { dy = -(h / fraccion_movimientoY); fil = 3; }
	if (orientacion == direccion::abajo) { dy = (h / fraccion_movimientoY); fil = 0; }
	if (orientacion == direccion::izquierda) { dx = -(w / fraccion_movimientoX); fil = 1; }
	if (orientacion == direccion::derecha) { dx = (w / fraccion_movimientoX); fil = 2; }
}
int Base::retornar_x() { return x; }
int Base::retornar_y() { return y; }
int Base::retornar_dx() { return dx; }
int Base::retornar_dy() { return dy; }
int Base::retornar_w() { return w; }
int Base::retornar_h() { return h; }
int Base::retornar_max_fil(){ return fil; }
int Base::retornar_max_col(){ return col; }
bool Base::retornar_eliminar() { return eliminar; }
Rectangle Base::retornar_rectangle() { return Rectangle(x, y, w, h); }
Rectangle Base::retornar_rectangle(int x, int y) { return Rectangle(x, y, w, h); }
void Base::Mover(Graphics^ g) {}
void Base::Dibujar(Graphics^ g) {}
void Base::Dibujar_conImagen(Graphics^ g, Bitmap^ bmp) 
{
	w = bmp->Width / max_col;
	h = bmp->Height / max_fil;
	Rectangle porcion = Rectangle(col * w, fil * h, w, h);
	g->DrawImage(bmp, x, y, porcion, GraphicsUnit::Pixel);
	col++;
	if (col >= max_col)
		col = 0;
}
void Base::Borrar(Graphics^ g) {}
void Base::cambiar_fraccion_movimientoX(int nuevo) { fraccion_movimientoX = nuevo; }
void Base::cambiar_fraccion_movimientoY(int nuevo) { fraccion_movimientoY = nuevo; }
int Base::retornar_fraccion_movimientoX() { return fraccion_movimientoX; }
int Base::retornar_fraccion_movimientoY() { return fraccion_movimientoY; }
direccion Base::retornar_orientacion() { return orientacion; }

vector<string> Base::LeerINPUT()
{
	string linea;
	vector<string>resultado;
	ifstream miarchivo("INPUT.txt");
	if (!miarchivo.fail())
	{
		while (!miarchivo.eof())
		{
			getline(miarchivo, linea);
			resultado.push_back(linea);
		}
		miarchivo.close();
	}
	return resultado;
}

vector<string> Base::LeerOUTPUT()
{
	string linea;
	vector<string>resultado;
	ifstream miarchivo("OUTPUT.txt");
	if (!miarchivo.fail())
	{
		while (!miarchivo.eof())
		{
			getline(miarchivo, linea);
			resultado.push_back(linea);
		}
		miarchivo.close();
	}
	return resultado;
}

vector<string> Base::LeerOUTPUT2()
{
	string linea;
	vector<string>resultado;
	ifstream miarchivo("OUTPUT2.txt");
	if (!miarchivo.fail())
	{
		while (!miarchivo.eof())
		{
			getline(miarchivo, linea);
			resultado.push_back(linea);
		}
		miarchivo.close();
	}
	return resultado;
}

void Base::GrabarOUTPUT(vector<string> datos)
{
	//ofstream miarchivo("OUTPUT.txt"); // BORRA EL CONTENIDO DEL ARCHIVO
	ofstream miarchivo("OUTPUT.txt", std::ofstream::app); // MANTIENE EL CONTENIDO DEL ARCHIVO
	if (!miarchivo.fail())
	{
		for (int i = 0; i < datos.size(); i++)
			miarchivo << datos.at(i) << "\n";
		miarchivo.flush();
		miarchivo.close();
	}
}
void Base::GrabarOUTPUT2(vector<string> datos)
{
	//ofstream miarchivo("OUTPUT.txt"); // BORRA EL CONTENIDO DEL ARCHIVO
	ofstream miarchivo("OUTPUT2.txt", std::ofstream::app); // MANTIENE EL CONTENIDO DEL ARCHIVO
	if (!miarchivo.fail())
	{
		for (int i = 0; i < datos.size(); i++)
			miarchivo << datos.at(i) << "\n";
		miarchivo.flush();
		miarchivo.close();
	}
}