#include "Chatarrero.h"

Chatarrero::Chatarrero() :Base()
{
	cambiar_x(0);
	vector<string>parametros = LeerINPUT();
	System::String^ aux_col = gcnew System::String(parametros.at(8).c_str());
	cambiar_max_col(System::Convert::ToInt32(aux_col));
	System::String^ aux_fil = gcnew System::String(parametros.at(7).c_str());
	cambiar_max_fil(System::Convert::ToInt32(aux_fil));
	cambiar_col(0);
	cambiar_fil(0);
	cambiar_dx(20);
	int auxiliar = rand() % 3;
	if (auxiliar == 0)
	{
		cambiar_y(150 + rand() % 30);
	}
	if (auxiliar == 1)
	{
		cambiar_y(562 + rand() % 385);
	}
	if (auxiliar == 2)
	{
		cambiar_y(310 + rand() % 20);
	}
}

Chatarrero::~Chatarrero(){}

void Chatarrero::Mover(Graphics^ g)
{
	if (x + dx + w > g->VisibleClipBounds.Width) { dx = 0; eliminar = true; }
	x += dx;
}
