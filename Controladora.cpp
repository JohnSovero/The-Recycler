#include "Controladora.h"

Controladora::Controladora() {
	srand(time(NULL));
	nivel2 = false;
	cant_contaminadores = 3;
	arreglo_Contaminadores.push_back(new Contaminadores(1500,250));
	arreglo_Contaminadores.push_back(new Contaminadores(280, 260));
	arreglo_Contaminadores.push_back(new Contaminadores(800, 690));
	
	objJugador = new Jugador();
	
	//Amarillo
	arreglo_Obstaculos.push_back(new Obstaculo(0, 0, 1920, 136));
	//verde
	arreglo_Obstaculos.push_back(new Obstaculo(955, 399, 958, 162));
	//rojo
	arreglo_Obstaculos.push_back(new Obstaculo(0, 399, 720, 162));
	////tachos abajo a la derecha
	arreglo_Obstaculos.push_back(new Obstaculo(1795, 870, 110, 35));
	////Carro
	arreglo_Obstaculos.push_back(new Obstaculo(1707, 255, 214, 30));
	////boca de incendios abajo a la derecha
	arreglo_Obstaculos.push_back(new Obstaculo(1560, 592, 22, 28));
	////boca de incendios abajo a la izquierda
	arreglo_Obstaculos.push_back(new Obstaculo(235, 800, 22, 28));
	////boca de incendios arriba
	arreglo_Obstaculos.push_back(new Obstaculo(552, 162, 27, 28));
	////conos arriba
	arreglo_Obstaculos.push_back(new Obstaculo(0, 273, 13, 35));
	////conos abajo
	arreglo_Obstaculos.push_back(new Obstaculo(0, 212, 13, 35));
	////tacho de papeles
	arreglo_Obstaculos.push_back(new Obstaculo(7, 820, 25, 50));
	////tacho de materia
	arreglo_Obstaculos.push_back(new Obstaculo(7, 570, 25, 50));
	
	objCurita = new Curita();
	objVacuna = new Vacuna();
	tiempo_juego = time(0);
	insertar_chatarrero = time(0);
	insertar_bonus = time(0);
	vector<string>imagenes = objJugador->LeerINPUT();
	imagen_jugador = imagenes.at(0);
	imagen_contaminador = imagenes.at(3);
	imagen_chatarrero = imagenes.at(6);
	imagen_metales = imagenes.at(9);
	imagen_materia = imagenes.at(12);
	imagen_papeles = imagenes.at(15);
	imagen_plastico = imagenes.at(18);
	imagen_botella = imagenes.at(21);
	imagen_curita = imagenes.at(24);
	imagen_vacuna = imagenes.at(27);
	imagen_lata = imagenes.at(30);
	imagen_mapa = imagenes.at(33);
	imagen_mapados = imagenes.at(34);
}
Controladora::~Controladora() {
	for (int i = 0; i < arreglo_Contaminadores.size(); i++)
		delete arreglo_Contaminadores.at(i);
	for (int i = 0; i < arreglo_Chatarreros.size(); i++)
		delete arreglo_Chatarreros.at(i);
	for (int i = 0; i < arreglo_Obstaculos.size(); i++)
		delete arreglo_Contaminadores.at(i);
	for (int i = 0; i <arreglo_bonus.size(); i++)
		delete arreglo_bonus.at(i);
	delete objJugador,objVacuna,objCurita;
}
void Controladora::Dibujar_Contaminadores(Graphics^ g, Bitmap^ bmp) {
	int aux;
	for (int i = 0; i < arreglo_Contaminadores.size(); i++)
	{
		Rectangle r1 = arreglo_Contaminadores.at(i)->retornar_rectangle(arreglo_Contaminadores.at(i)->retornar_x() + arreglo_Contaminadores.at(i)->retornar_dx(), arreglo_Contaminadores.at(i)->retornar_y() + arreglo_Contaminadores.at(i)->retornar_dy());
		for (int j = 0; j < arreglo_Obstaculos.size(); j++)
		{
			Rectangle r2 = arreglo_Obstaculos.at(j)->retornar_rectangle();
			if (r1.IntersectsWith(r2))
			{
				if (arreglo_Contaminadores.at(i)->retornar_orientacion() == direccion::derecha)
					arreglo_Contaminadores.at(i)->Desplazamiento(direccion::izquierda);
				else if (arreglo_Contaminadores.at(i)->retornar_orientacion() == direccion::izquierda)
					arreglo_Contaminadores.at(i)->Desplazamiento(direccion::derecha);
				else if (arreglo_Contaminadores.at(i)->retornar_orientacion() == direccion::arriba)
					arreglo_Contaminadores.at(i)->Desplazamiento(direccion::abajo);
				else if (arreglo_Contaminadores.at(i)->retornar_orientacion() == direccion::abajo)
					arreglo_Contaminadores.at(i)->Desplazamiento(direccion::arriba);
			}
		}
	}
	for (int i = 0; i < arreglo_Contaminadores.size(); i++)
	{
		aux = rand() % 15 + 1;
		arreglo_Contaminadores.at(i)->Dibujar_conImagen(g, bmp);
		if (aux == 1)arreglo_Contaminadores.at(i)->Desplazamiento(direccion::derecha);
		if (aux == 2)arreglo_Contaminadores.at(i)->Desplazamiento(direccion::izquierda);
		if (aux == 3)arreglo_Contaminadores.at(i)->Desplazamiento(direccion::arriba);
		if (aux == 4)arreglo_Contaminadores.at(i)->Desplazamiento(direccion::abajo);
		arreglo_Contaminadores.at(i)->Mover(g);
		arreglo_Contaminadores.at(i)->Tira_Basura(nivel2);
	}
}
void Controladora::Dibujar_Curaciones(Graphics^ g, Bitmap^ bmp_curita, Bitmap^ bmp_vacuna) {
	objCurita->Dibujar_conImagen(g, bmp_curita);
	if (nivel2 == true)
	{
		objVacuna->Dibujar_conImagen(g, bmp_vacuna);
	}
}
void Controladora::Dibujar_Basura(Graphics^ g,Bitmap^ bmp_metal, Bitmap^ bmp_materiaO,
	Bitmap^ bmp_papel, Bitmap^ bmp_plastico, Bitmap^ bmp_vidrio) {
	for (int i = 0; i < arreglo_Contaminadores.size(); i++)
	{
		arreglo_Contaminadores.at(i)->Dibujar_Basura(g, bmp_metal,bmp_materiaO,bmp_papel,
			bmp_plastico,bmp_vidrio);
	}
}
void Controladora::Dibujar_Jugador(Graphics^ g, Bitmap^ bmp) {
	bool aux = false;
	objJugador->Dibujar_conImagen(g,bmp);
	Rectangle r1 = objJugador->retornar_rectangle2(objJugador->retornar_x() + objJugador->retornar_dx(), objJugador->retornar_y() + objJugador->retornar_dy());
	for (int i = 0; !aux && i < arreglo_Obstaculos.size(); i++)
	{
		Rectangle r2 = arreglo_Obstaculos.at(i)->retornar_rectangle();
		if (r1.IntersectsWith(r2))
			aux = true;
	}
	if(!aux)objJugador->Mover(g);
	if (objJugador->retornar_herido()) objJugador->cambiar_ocupado(true);
	Colision_Items();
	Colision_Herido();
	Colision_Deposito();
	if (nivel2)
	{
		Colision_Covid();
		Colision_Lata();
		Colision_Chatarrero_Jugador();
		Enfermo();
	}
}
void Controladora::Dibujar_Chatarrero(Graphics^ g, Bitmap^ bmp)
{
	Insertar_Chatarrero();
	for (int i = 0; i < arreglo_Chatarreros.size(); i++)
	{
		arreglo_Chatarreros.at(i)->Dibujar_conImagen(g, bmp);
		arreglo_Chatarreros.at(i)->Mover(g);
	}
	for (int i = 0; i < arreglo_Chatarreros.size(); i++)
	{
		if (arreglo_Chatarreros.at(i)->retornar_eliminar())
		{
			arreglo_Chatarreros.erase(arreglo_Chatarreros.begin() + i);
		}
	}
	Colision_Chatarrero();
}
void Controladora::Insertar_Chatarrero()
{
	if (nivel2 == true)
	{
		if (difftime(time(0), insertar_chatarrero) > 6)
		{
			arreglo_Chatarreros.push_back(new Chatarrero());
			insertar_chatarrero = time(0);
		}
	}
}
void Controladora::Dibujar_Bonus(Graphics^ g, Bitmap^ bmp)
{
	if (difftime(time(0), insertar_bonus) > 20)
	{
		arreglo_bonus.push_back(new Bonus());
		insertar_bonus = time(0);
	}
	for (int i = 0; i < arreglo_bonus.size(); i++)
	{
		arreglo_bonus.at(i)->Dibujar_conImagen(g, bmp);
	}
}
void Controladora::Dibujar_Obstaculos(Graphics^ g){
	if (nivel2)
	{
		////tacho de metales
		arreglo_Obstaculos.push_back(new Obstaculo(1900, 147, 25, 50));
		////tacho de vidrios
		arreglo_Obstaculos.push_back(new Obstaculo(1900, 318, 25, 50));
		////tacho de plasticos
		arreglo_Obstaculos.push_back(new Obstaculo(1900, 559, 25, 50));
	}
	arreglo_Obstaculos.at(0)->cambiar_w(g->VisibleClipBounds.Width-arreglo_Obstaculos.at(0)->retornar_x());
	arreglo_Obstaculos.at(1)->cambiar_w(g->VisibleClipBounds.Width-arreglo_Obstaculos.at(1)->retornar_x());
	//Para ver los obstaculos
	for each (Obstaculo * r in arreglo_Obstaculos) 
		r->Dibujar(g);
}
void Controladora::Desplazar(direccion nueva) {
	objJugador->Desplazamiento(nueva);
}
bool Controladora::Colision_Items() {
	Rectangle r1 = objJugador->retornar_rectangle();
	bool colision = false;
	//Colision para recoger la basura
	for (int i = 0; !colision && !objJugador->retornar_ocupado() && i < arreglo_Contaminadores.size(); i++)
	{
		// Colision del Metal
		for (int j = 0; j < arreglo_Contaminadores.at(i)->retornar_can_metal(); j++)
		{
			Rectangle r2 = arreglo_Contaminadores.at(i)->retornar_metal(j)->retornar_rectangle();
			if (r1.IntersectsWith(r2))
			{
				arreglo_Contaminadores.at(i)->retornar_metal(j)->cambiar_eliminar(true);
				objJugador->cambiar_ocupado(true);
				objJugador->cambiar_tipo(1);
				
				colision = true;
			}
		}
		// Colision de la materia
		for (int j = 0; j < arreglo_Contaminadores.at(i)->retornar_can_materia(); j++)
		{
			Rectangle r2 = arreglo_Contaminadores.at(i)->retornar_materia(j)->retornar_rectangle();
			if (r1.IntersectsWith(r2))
			{
				arreglo_Contaminadores.at(i)->retornar_materia(j)->cambiar_eliminar(true);
				objJugador->cambiar_ocupado(true);
				objJugador->cambiar_tipo(2);
				colision = true;
			}
		}
		// Colision del papel
		for (int j = 0; j < arreglo_Contaminadores.at(i)->retornar_can_papel(); j++)
		{
			Rectangle r2 = arreglo_Contaminadores.at(i)->retornar_papel(j)->retornar_rectangle();
			if (r1.IntersectsWith(r2))
			{
				arreglo_Contaminadores.at(i)->retornar_papel(j)->cambiar_eliminar(true);
				objJugador->cambiar_ocupado(true);
				objJugador->cambiar_tipo(3);
				colision = true;
			}
		}
		// Colision del plastico
		for (int j = 0; j < arreglo_Contaminadores.at(i)->retornar_can_plastico(); j++)
		{
			Rectangle r2 = arreglo_Contaminadores.at(i)->retornar_plastico(j)->retornar_rectangle();
			if (r1.IntersectsWith(r2))
			{
				arreglo_Contaminadores.at(i)->retornar_plastico(j)->cambiar_eliminar(true);
				objJugador->cambiar_ocupado(true);
				objJugador->cambiar_tipo(4);
				colision = true;
			}
		}
		// Colision del vidrio
		for (int j = 0; j < arreglo_Contaminadores.at(i)->retornar_can_vidrio(); j++)
		{
			Rectangle r2 = arreglo_Contaminadores.at(i)->retornar_vidrio(j)->retornar_rectangle();
			if (r1.IntersectsWith(r2))
			{
				arreglo_Contaminadores.at(i)->retornar_vidrio(j)->cambiar_eliminar(true);
				objJugador->cambiar_ocupado(true);
				objJugador->cambiar_tipo(5);
				int aux = rand() % 100 + 1;
				if (aux > 80)
				{
					objJugador->cambiar_herido(true);
					objJugador->cambiar_cant_vidas(objJugador->retornar_cant_vidas() - 1);
				}
				colision = true;
			}
		}
	}
	return colision;
}
bool Controladora::Colision_Deposito() {
	//Tachos del nivel 1
	if (nivel2==false)
	{
		// colision solo si el jugador tiene basura en las manos y no esta herido
		if (objJugador->retornar_ocupado() && objJugador->retornar_herido() == false)
		{
			Rectangle r1 = objJugador->retornar_rectangle();
			bool colision = false;
			//rectangle del tacho inorganico (rojo)
			Rectangle r2 = Rectangle(52, 814, 87, 50);
			//colision con metales en las manos
			if (r1.IntersectsWith(r2) == true)
			{
				//colision con materia inorganica en las manos
				if (objJugador->retornar_tipo() != 2)
				{
					objJugador->cambiar_cant_puntos(objJugador->retornar_cant_puntos() + 100);
				}
				//colision con materia organica en las manos
				if (objJugador->retornar_tipo() == 2)
				{
					objJugador->cambiar_cant_puntos(objJugador->retornar_cant_puntos() - 50);
				}
				objJugador->cambiar_ocupado(false);
				objJugador->cambiar_tipo(0);
				colision = true;
			}
			//rectangle del tacho organico (verde)
			Rectangle r3 = Rectangle(48, 589, 87, 50);
			//colision con metal en la mano
			if (r1.IntersectsWith(r3) == true)
			{
				//colision con materia inorganico en las manos
				if (objJugador->retornar_tipo() != 2)
				{
					objJugador->cambiar_cant_puntos(objJugador->retornar_cant_puntos() - 50);
				}
				//colision con materia organica en las manos
				if (objJugador->retornar_tipo() == 2)
				{
					objJugador->cambiar_cant_puntos(objJugador->retornar_cant_puntos() + 100);
				}
				objJugador->cambiar_ocupado(false);
				objJugador->cambiar_tipo(0);
				colision = true;
			}
			return colision;
		}
	}
	else if (nivel2 == true)
	{
		if (objJugador->retornar_ocupado() && objJugador->retornar_herido() == false && objJugador->retornar_covid() == false)
		{
			Rectangle r1 = objJugador->retornar_rectangle();
			bool colision = false;
			//rectangle del tacho organico (verde)
			Rectangle r2 = Rectangle(48, 589, 87, 50);
			if (r1.IntersectsWith(r2))
			{
				if (objJugador->retornar_tipo() != 2)
				{
					objJugador->cambiar_cant_puntos(objJugador->retornar_cant_puntos() - 50);
				}
				if (objJugador->retornar_tipo() == 2)
				{
					objJugador->cambiar_cant_puntos(objJugador->retornar_cant_puntos() + 100);
				}
				objJugador->cambiar_ocupado(false);
				objJugador->cambiar_tipo(0);
				colision = true;
			}
			//rectangle del tacho celeste (papel)
			Rectangle r3 = Rectangle(52, 814, 87, 50);
			if (r1.IntersectsWith(r3))
			{
				if (objJugador->retornar_tipo() != 3)
				{
					objJugador->cambiar_cant_puntos(objJugador->retornar_cant_puntos() - 50);
				}
				if (objJugador->retornar_tipo() == 3)
				{
					objJugador->cambiar_cant_puntos(objJugador->retornar_cant_puntos() + 100);
				}
				objJugador->cambiar_ocupado(false);
				objJugador->cambiar_tipo(0);
				colision = true;
			}
			//rectangle del tacho plomo (metales)
			Rectangle r4 = Rectangle(1848, 169, 87, 50);
			if (r1.IntersectsWith(r4))
			{
				if (objJugador->retornar_tipo() != 1)
				{
					objJugador->cambiar_cant_puntos(objJugador->retornar_cant_puntos() - 50);
				}
				if (objJugador->retornar_tipo() == 1)
				{
					objJugador->cambiar_cant_puntos(objJugador->retornar_cant_puntos() + 100);
				}
				objJugador->cambiar_ocupado(false);
				objJugador->cambiar_tipo(0);
				colision = true;
			}
			//rectangle del tacho celeste oscuro (vidrios)
			Rectangle r5 = Rectangle(1848, 340, 87, 50);
			if (r1.IntersectsWith(r5))
			{
				if (objJugador->retornar_tipo() != 5)
				{
					objJugador->cambiar_cant_puntos(objJugador->retornar_cant_puntos() - 50);
				}
				if (objJugador->retornar_tipo() == 5)
				{
					objJugador->cambiar_cant_puntos(objJugador->retornar_cant_puntos() + 100);
				}
				objJugador->cambiar_ocupado(false);
				objJugador->cambiar_tipo(0);
				colision = true;
			}
			//rectangle del tacho amarillo (plastico)
			Rectangle r6 = Rectangle(1848, 588, 87, 50);
			if (r1.IntersectsWith(r6))
			{
				if (objJugador->retornar_tipo() != 4)
				{
					objJugador->cambiar_cant_puntos(objJugador->retornar_cant_puntos() - 50);
				}
				if (objJugador->retornar_tipo() == 4)
				{
					objJugador->cambiar_cant_puntos(objJugador->retornar_cant_puntos() + 100);
				}
				objJugador->cambiar_ocupado(false);
				objJugador->cambiar_tipo(0);
				colision = true;
			}
		}
	}
}
void Controladora::Colision_Herido() 
{
	if (objJugador->retornar_herido())
	{
		Rectangle l1 = objJugador->retornar_rectangle();
		Rectangle l2 = Rectangle(300, 181, 53, 30);
		if (l1.IntersectsWith(l2))
		{
			objJugador->cambiar_herido(false);
			objJugador->cambiar_cant_puntos(objJugador->retornar_cant_puntos() - 50);
		}
	}
}
void Controladora::Colision_Covid() 
{
	if (nivel2 == true && objJugador->retornar_covid())
	{
		Rectangle l1 = objJugador->retornar_rectangle();
		Rectangle l2 = Rectangle(123, 182, 53, 30);
		if (l1.IntersectsWith(l2))
		{
			objJugador->cambiar_covid(false);
			objJugador->cambiar_cant_puntos(objJugador->retornar_cant_puntos() - 50);
		}
	}
}
void Controladora::Colision_Chatarrero()
{
	bool colision = false;
	//Recoger basura
	for (int i = 0; !colision && i < arreglo_Chatarreros.size(); i++)
	{
		Rectangle r1 = arreglo_Chatarreros.at(i)->retornar_rectangle();
		for (int j = 0; j < arreglo_Contaminadores.size(); j++)
		{
			//Colision con MateriaO
			for (int k = 0; k < arreglo_Contaminadores.at(j)->retornar_arr_materia().size(); k++)
			{
				Rectangle r2 = arreglo_Contaminadores.at(j)->retornar_arr_materia().at(k)->retornar_rectangle();
				if (r1.IntersectsWith(r2))
				{
					arreglo_Contaminadores.at(j)->retornar_arr_materia().at(k)->cambiar_eliminar(true);
					colision = true;
				}
			}
			//Colision con Metal
			for (int k = 0; k < arreglo_Contaminadores.at(j)->retornar_arr_metal().size(); k++)
			{
				Rectangle r2 = arreglo_Contaminadores.at(j)->retornar_arr_metal().at(k)->retornar_rectangle();
				if (r1.IntersectsWith(r2))
				{
					arreglo_Contaminadores.at(j)->retornar_arr_metal().at(k)->cambiar_eliminar(true);
					colision = true;
				}
			}
			//Colision con Papel
			for (int k = 0; k < arreglo_Contaminadores.at(j)->retornar_arr_papel().size(); k++)
			{
				Rectangle r2 = arreglo_Contaminadores.at(j)->retornar_arr_papel().at(k)->retornar_rectangle();
				if (r1.IntersectsWith(r2))
				{
					arreglo_Contaminadores.at(j)->retornar_arr_papel().at(k)->cambiar_eliminar(true);
					colision = true;
				}
			}
			//Colision con Plastico
			for (int k = 0; k < arreglo_Contaminadores.at(j)->retornar_arr_plastico().size(); k++)
			{
				Rectangle r2 = arreglo_Contaminadores.at(j)->retornar_arr_plastico().at(k)->retornar_rectangle();
				if (r1.IntersectsWith(r2))
				{
					arreglo_Contaminadores.at(j)->retornar_arr_plastico().at(k)->cambiar_eliminar(true);
					colision = true;
				}
			}
			//Colision con Vidrio
			for (int k = 0; k < arreglo_Contaminadores.at(j)->retornar_arr_vidrio().size(); k++)
			{
				Rectangle r2 = arreglo_Contaminadores.at(j)->retornar_arr_vidrio().at(k)->retornar_rectangle();
				if (r1.IntersectsWith(r2))
				{
					arreglo_Contaminadores.at(j)->retornar_arr_vidrio().at(k)->cambiar_eliminar(true);
					colision = true;
				}
			}
		}
	}
}
void Controladora::Colision_Chatarrero_Jugador() {
	if (nivel2 == true)
	{
		Rectangle r1 = objJugador->retornar_rectangle();
		bool colision = false;
		for (int i = 0; i < arreglo_Chatarreros.size(); i++)
		{
			Rectangle r2 = arreglo_Chatarreros.at(i)->retornar_rectangle();
			if (r1.IntersectsWith(r2))
			{
				int aux = rand() % 100;
				if (aux > 75)
				{
					objJugador->cambiar_covid(true);
				}
			}
		}
	}
}
void Controladora::Colision_Lata()
{
	bool resultado_colision = false;
	Rectangle r1 = objJugador->retornar_rectangle();
	for (int i = 0; !resultado_colision && i < arreglo_bonus.size(); i++)
	{
		Rectangle r2 = arreglo_bonus.at(i)->retornar_rectangle();
		if (r1.IntersectsWith(r2))
		{
			resultado_colision = true;
			objJugador->cambiar_fraccion_movimientoX(2.5);
			objJugador->cambiar_fraccion_movimientoY(2.5);
			arreglo_bonus.at(i)->cambiar_eliminar(true);
			inicio_bonus = time(0);
			objJugador->cambiar_bonus(true);
		}
	}
	for (int j = 0; j < arreglo_bonus.size(); j++)
	{
		if (arreglo_bonus.at(j)->retornar_eliminar())
		{
			arreglo_bonus.erase(arreglo_bonus.begin() + j);
		}
	}
	if (difftime(time(0), inicio_bonus) > 8)
	{
		objJugador->cambiar_fraccion_movimientoX(4);
		objJugador->cambiar_fraccion_movimientoY(4);
		objJugador->cambiar_bonus(false);
	}
}
bool Controladora::acabar_nivel1()
{
	if (difftime(time(0), tiempo_juego) >= 120)  return true;
	if (objJugador->retornar_cant_vidas() == 0) return true;
	return false;
}
bool Controladora::acabar_nivel2()
{
	if (difftime(time(0), tiempo_juego) >= 120)return true;
	if (objJugador->retornar_cant_vidas() == 0) return true;
	return false;
}
void Controladora::Enfermo() {
	if (covid())
	{
		objJugador->cambiar_fraccion_movimientoX(6);
		objJugador->cambiar_fraccion_movimientoY(6);
	}
	if (!covid() && objJugador->retornar_bonus() == false)
	{
		objJugador->cambiar_fraccion_movimientoX(4);
		objJugador->cambiar_fraccion_movimientoY(4);
	}
	
}
int Controladora::retornar_tiempo() { return time(0) - tiempo_juego; }
void Controladora::cambiar_nivel2(bool nueva) { nivel2 = nueva; }
Jugador* Controladora::retornar_jugador() { return objJugador; }
bool Controladora::estado() { return objJugador->retornar_herido(); }
bool Controladora::covid() { return objJugador->retornar_covid(); }
System::String^ Controladora::retornar_imagen_jugador(){return gcnew System::String(imagen_jugador.c_str());}
System::String^ Controladora::retornar_imagen_contaminador(){return gcnew System::String(imagen_contaminador.c_str());}
System::String^ Controladora::retornar_imagen_chatarrero(){	return gcnew System::String(imagen_chatarrero.c_str());}
System::String^ Controladora::retornar_imagen_metales(){return gcnew System::String(imagen_metales.c_str());}
System::String^ Controladora::retornar_imagen_materia(){return gcnew System::String(imagen_materia.c_str());}
System::String^ Controladora::retornar_imagen_papeles(){return gcnew System::String(imagen_papeles.c_str());}
System::String^ Controladora::retornar_imagen_plastico(){return gcnew System::String(imagen_plastico.c_str());}
System::String^ Controladora::retornar_imagen_botella(){return gcnew System::String(imagen_botella.c_str());}
System::String^ Controladora::retornar_imagen_curita(){	return gcnew System::String(imagen_curita.c_str());}
System::String^ Controladora::retornar_imagen_vacuna(){	return gcnew System::String(imagen_vacuna.c_str());}
System::String^ Controladora::retornar_imagen_lata(){return gcnew System::String(imagen_lata.c_str());}
System::String^ Controladora::retornar_imagen_mapa(){return gcnew System::String(imagen_mapa.c_str());}
System::String^ Controladora::retornar_imagen_mapados(){return gcnew System::String(imagen_mapados.c_str());}
void Controladora::Grabar_puntajes(vector<string> datos){objJugador->GrabarOUTPUT(datos);}
void Controladora::Grabar_nombre(vector<string> datos){	objJugador->GrabarOUTPUT2(datos);}
vector<int> Controladora::retornar_rank()
{
	vector<string>puntajes = objJugador->LeerOUTPUT();
	vector<string>nombres = objJugador->LeerOUTPUT2();
	vector<int>puntos;
	for (int i = 1; i < puntajes.size(); i++)
	{
		System::String^ aux_points = gcnew System::String(puntajes.at(i - 1).c_str());
		puntos.push_back(System::Convert::ToInt32(aux_points));
	}
	for (int i = 0; i < puntos.size()-1; i++)
	{
		for (int j = i+1; j < puntos.size(); j++)
		{
			if (puntos.at(j) >= puntos.at(i))
			{
				swap(puntos.at(i), puntos.at(j));
				swap(nombres.at(i), nombres.at(j));
			}
		}
	}
	cambiar_rank_nombres(nombres);
	return puntos;
}
void Controladora::cambiar_rank_nombres(vector<string>nombres){	real_nombres = nombres;}
vector<string> Controladora::retornar_rank_nombres(){return real_nombres;}