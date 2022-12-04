#include "Bonus.h"

Bonus::Bonus() :Base()
{
	vector<string>parametros = LeerINPUT();
	System::String^ aux_col = gcnew System::String(parametros.at(32).c_str());
	cambiar_max_col(System::Convert::ToInt32(aux_col));
	System::String^ aux_fil = gcnew System::String(parametros.at(31).c_str());
	cambiar_max_fil(System::Convert::ToInt32(aux_fil));
	cambiar_col(0);
	cambiar_fil(0);
	int auxiliar = rand() % 2;
	if (auxiliar == 0)
	{
		cambiar_x(15 + rand() % 1635);
		cambiar_y(155 + rand() % 145);
		
	}
	if (auxiliar == 1)
	{
		cambiar_x(150 + rand() % 1580);
		cambiar_y(562 + rand() % 385);
	}
}

Bonus::~Bonus()
{
}
