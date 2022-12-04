#include "MyForm.h"
#include "Inicio.h"
#include "Instrucciones.h"
using namespace System;
using namespace System::Windows::Forms; [STAThread]
void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 
	Application::Run(gcnew forms::Inicio()); //Project 1 es el nombre del proyecto
}