#include "Metales.h"

Metales::Metales(int px, int py):Base(){
	cambiar_x(px);
	cambiar_y(py);
	vector<string>parametros = LeerINPUT();
	System::String^ aux_col = gcnew System::String(parametros.at(11).c_str());
	cambiar_max_col(System::Convert::ToInt32(aux_col));
	System::String^ aux_fil = gcnew System::String(parametros.at(10).c_str());
	cambiar_max_fil(System::Convert::ToInt32(aux_fil));
	cambiar_col(0);
	cambiar_fil(0);
}
Metales::~Metales(){}