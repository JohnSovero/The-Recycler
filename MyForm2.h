#pragma once
#include "Controladora.h"
#include "Ranking.h"

namespace forms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm2
	/// </summary>
	public ref class MyForm2 : public System::Windows::Forms::Form
	{
	public:
		MyForm2(void)
		{
			InitializeComponent();
			//Objetos
			obj = new Controladora();

			//Buffer Graphics
			g = CreateGraphics();
			espacio = BufferedGraphicsManager::Current;
			bf = espacio->Allocate(g, ClientRectangle);
			//Personajes
			bmpContaminador = gcnew Bitmap(obj->retornar_imagen_contaminador());
			bmpJugador = gcnew Bitmap(obj->retornar_imagen_jugador());
			bmpChatarrero = gcnew Bitmap(obj->retornar_imagen_chatarrero());

			//Items
			bmpMetal = gcnew Bitmap(obj->retornar_imagen_metales());
			bmpMateriaO = gcnew Bitmap(obj->retornar_imagen_materia());;
			bmpPapel = gcnew Bitmap(obj->retornar_imagen_papeles());
			bmpPlastico = gcnew Bitmap(obj->retornar_imagen_plastico());
			bmpVidrio = gcnew Bitmap(obj->retornar_imagen_botella());
			bmpCurita = gcnew Bitmap(obj->retornar_imagen_curita());
			bmpVacuna = gcnew Bitmap(obj->retornar_imagen_vacuna());
			bmplata = gcnew Bitmap(obj->retornar_imagen_lata());

			//Imagenes de fondo
			bmpNivel2 = gcnew Bitmap(obj->retornar_imagen_mapados());

		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm2()
		{
			if (components)
			{
				delete components;
			}
			delete g, espacio, bf, bmpNivel2, bmpJugador, bmpContaminador,bmpChatarrero;
			delete bmpMetal, bmpMateriaO, bmpPapel, bmpPlastico, bmpVidrio, bmpCurita,bmpVacuna, obj;
			delete bmplata, nombre_del_jugador;
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		//Objetos
		Controladora* obj;
		String^ nombre_del_jugador;

		//Buffer Graphics
		Graphics^ g;
		BufferedGraphicsContext^ espacio;
		BufferedGraphics^ bf;

		//Imagenes de fondo
		Bitmap^ bmpNivel2;

		//Personajes imagenes
		Bitmap^ bmpJugador;
		Bitmap^ bmpContaminador;
		Bitmap^ bmpChatarrero;

		//Items
		Bitmap^ bmpMetal;
		Bitmap^ bmpMateriaO;
		Bitmap^ bmpPapel;
		Bitmap^ bmpPlastico;
		Bitmap^ bmpVidrio;
		Bitmap^ bmpCurita;
		Bitmap^ bmpVacuna;
		Bitmap^ bmplata;
	private: System::Windows::Forms::Panel^ datos;
	private: System::Windows::Forms::Label^ manos;
	private: System::Windows::Forms::Label^ time;
	private: System::Windows::Forms::Label^ estado;
	private: System::Windows::Forms::Label^ Puntos;
	private: System::Windows::Forms::Label^ Vidas;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ nivel2;
	private: System::Windows::Forms::Button^ menu;
	private: System::Windows::Forms::Label^ name;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ ptos;







#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm2::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->datos = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->manos = (gcnew System::Windows::Forms::Label());
			this->time = (gcnew System::Windows::Forms::Label());
			this->estado = (gcnew System::Windows::Forms::Label());
			this->Puntos = (gcnew System::Windows::Forms::Label());
			this->Vidas = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->name = (gcnew System::Windows::Forms::Label());
			this->nivel2 = (gcnew System::Windows::Forms::Button());
			this->menu = (gcnew System::Windows::Forms::Button());
			this->ptos = (gcnew System::Windows::Forms::Label());
			this->datos->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm2::timer1_Tick);
			// 
			// datos
			// 
			this->datos->Controls->Add(this->button1);
			this->datos->Controls->Add(this->manos);
			this->datos->Controls->Add(this->time);
			this->datos->Controls->Add(this->estado);
			this->datos->Controls->Add(this->Puntos);
			this->datos->Controls->Add(this->Vidas);
			this->datos->Dock = System::Windows::Forms::DockStyle::Top;
			this->datos->Location = System::Drawing::Point(0, 0);
			this->datos->Name = L"datos";
			this->datos->Size = System::Drawing::Size(1924, 61);
			this->datos->TabIndex = 6;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Tempus Sans ITC", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(1818, 8);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(98, 43);
			this->button1->TabIndex = 5;
			this->button1->TabStop = false;
			this->button1->Text = L"Menu";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm2::button1_Click);
			// 
			// manos
			// 
			this->manos->AutoSize = true;
			this->manos->Font = (gcnew System::Drawing::Font(L"Times New Roman", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->manos->Location = System::Drawing::Point(1446, 9);
			this->manos->Name = L"manos";
			this->manos->Size = System::Drawing::Size(93, 36);
			this->manos->TabIndex = 8;
			this->manos->Text = L"label1";
			// 
			// time
			// 
			this->time->AutoSize = true;
			this->time->Font = (gcnew System::Drawing::Font(L"Times New Roman", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->time->Location = System::Drawing::Point(1118, 9);
			this->time->Name = L"time";
			this->time->Size = System::Drawing::Size(93, 36);
			this->time->TabIndex = 7;
			this->time->Text = L"label1";
			// 
			// estado
			// 
			this->estado->AutoSize = true;
			this->estado->Font = (gcnew System::Drawing::Font(L"Times New Roman", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->estado->Location = System::Drawing::Point(707, 9);
			this->estado->Name = L"estado";
			this->estado->Size = System::Drawing::Size(93, 36);
			this->estado->TabIndex = 2;
			this->estado->Text = L"label1";
			// 
			// Puntos
			// 
			this->Puntos->AutoSize = true;
			this->Puntos->Font = (gcnew System::Drawing::Font(L"Times New Roman", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Puntos->Location = System::Drawing::Point(361, 9);
			this->Puntos->Name = L"Puntos";
			this->Puntos->Size = System::Drawing::Size(93, 36);
			this->Puntos->TabIndex = 1;
			this->Puntos->Text = L"label1";
			// 
			// Vidas
			// 
			this->Vidas->AutoSize = true;
			this->Vidas->Font = (gcnew System::Drawing::Font(L"Times New Roman", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Vidas->Location = System::Drawing::Point(56, 9);
			this->Vidas->Name = L"Vidas";
			this->Vidas->Size = System::Drawing::Size(93, 36);
			this->Vidas->TabIndex = 0;
			this->Vidas->Text = L"label1";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::YellowGreen;
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->Controls->Add(this->name);
			this->panel1->Controls->Add(this->nivel2);
			this->panel1->Controls->Add(this->menu);
			this->panel1->Controls->Add(this->ptos);
			this->panel1->Location = System::Drawing::Point(520, 250);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(807, 540);
			this->panel1->TabIndex = 7;
			this->panel1->Visible = false;
			// 
			// name
			// 
			this->name->AutoSize = true;
			this->name->BackColor = System::Drawing::Color::Lavender;
			this->name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->name->Location = System::Drawing::Point(245, 244);
			this->name->Name = L"name";
			this->name->Size = System::Drawing::Size(109, 39);
			this->name->TabIndex = 4;
			this->name->Text = L"label1";
			this->name->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->name->Visible = false;
			// 
			// nivel2
			// 
			this->nivel2->Font = (gcnew System::Drawing::Font(L"Tempus Sans ITC", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nivel2->Location = System::Drawing::Point(517, 437);
			this->nivel2->Name = L"nivel2";
			this->nivel2->Size = System::Drawing::Size(160, 47);
			this->nivel2->TabIndex = 3;
			this->nivel2->Text = L"Ranking";
			this->nivel2->UseVisualStyleBackColor = true;
			this->nivel2->Visible = false;
			this->nivel2->Click += gcnew System::EventHandler(this, &MyForm2::nivel2_Click);
			// 
			// menu
			// 
			this->menu->Font = (gcnew System::Drawing::Font(L"Tempus Sans ITC", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->menu->Location = System::Drawing::Point(167, 437);
			this->menu->Name = L"menu";
			this->menu->Size = System::Drawing::Size(144, 47);
			this->menu->TabIndex = 2;
			this->menu->Text = L"Menu";
			this->menu->UseVisualStyleBackColor = true;
			this->menu->Visible = false;
			this->menu->Click += gcnew System::EventHandler(this, &MyForm2::menu_Click);
			// 
			// ptos
			// 
			this->ptos->AutoSize = true;
			this->ptos->BackColor = System::Drawing::Color::Lavender;
			this->ptos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ptos->Location = System::Drawing::Point(245, 319);
			this->ptos->Name = L"ptos";
			this->ptos->Size = System::Drawing::Size(109, 39);
			this->ptos->TabIndex = 0;
			this->ptos->Text = L"label1";
			this->ptos->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->ptos->Visible = false;
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1924, 977);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->datos);
			this->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Name = L"MyForm2";
			this->Text = L"MyForm2";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &MyForm2::MyForm2_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm2::MyForm2_KeyDown);
			this->datos->ResumeLayout(false);
			this->datos->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	public: void cambiar_nombre_del_jugador(String^ nuevo)
	{
		nombre_del_jugador = nuevo;
	}
	private: System::Void MyForm2_Load(System::Object^ sender, System::EventArgs^ e) {
	
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		bf->Graphics->Clear(Color::White);
		bf->Graphics->DrawImage(bmpNivel2, 0, 0, ClientRectangle.Width, ClientRectangle.Height);
		obj->cambiar_nivel2(true);
		obj->Dibujar_Contaminadores(bf->Graphics, bmpContaminador);
		obj->Dibujar_Basura(bf->Graphics, bmpMetal, bmpMateriaO, bmpPapel, bmpPlastico, bmpVidrio);
		obj->Dibujar_Jugador(bf->Graphics, bmpJugador);
		obj->Dibujar_Curaciones(bf->Graphics, bmpCurita,bmpVacuna);
		obj->Dibujar_Obstaculos(bf->Graphics);
		obj->Dibujar_Chatarrero(bf->Graphics, bmpChatarrero);
		obj->Dibujar_Bonus(bf->Graphics, bmplata);
		Vidas->Text = Convert::ToString("Vidas: " + obj->retornar_jugador()->retornar_cant_vidas());
		Puntos->Text = Convert::ToString("Puntos: " + obj->retornar_jugador()->retornar_cant_puntos());
		time->Text = Convert::ToString("Tiempo: " + obj->retornar_tiempo() + " segundos");
		name->Text = Convert::ToString("¡Enhorabuena " + nombre_del_jugador + "!");
		ptos->Text = Convert::ToString("Obtuviste " + obj->retornar_jugador()->retornar_cant_puntos() + " puntos");
		if (obj->retornar_jugador()->retornar_tipo() == 1)
		{
			manos->Text = Convert::ToString("Manos: Metal");
		}
		else if (obj->retornar_jugador()->retornar_tipo() == 2)
		{
			manos->Text = Convert::ToString("Manos: Materia.O ");
		}
		else if (obj->retornar_jugador()->retornar_tipo() == 3)
		{
			manos->Text = Convert::ToString("Manos: Papel");
		}
		else if (obj->retornar_jugador()->retornar_tipo() == 4)
		{
			manos->Text = Convert::ToString("Manos: Plástico");
		}
		else if (obj->retornar_jugador()->retornar_tipo() == 5)
		{
			manos->Text = Convert::ToString("Manos: Vidrio");
		}
		else {
			manos->Text = Convert::ToString("Manos: Desocupadas");
		}
		if (obj->estado()&&!obj->covid()) { estado->Text = Convert::ToString("Estado: " + "Herido"); }
		if (!obj->estado()&&!obj->covid()) { estado->Text = Convert::ToString("Estado: " + "Sano"); }
		if (obj->covid() && obj->estado()) { estado->Text = Convert::ToString("Estado: " + "Herido y con Covid"); }
		if (obj->covid() && !obj->estado()) { estado->Text = Convert::ToString("Estado: " + "con Covid"); }
		if (obj->acabar_nivel2())
		{
			timer1->Enabled = false;
			datos->Visible = false;
			panel1->Visible = true;
			name->Visible = true;
			menu->Visible = true;
			ptos->Visible = true;
			nivel2->Visible = true;
			vector<string>datosagrabar;
			vector<string>nombreagrabar;
			char auxiliar[100];
			sprintf(auxiliar, "%s", nombre_del_jugador);
			nombreagrabar.push_back(auxiliar);
			datosagrabar.push_back(std::to_string(obj->retornar_jugador()->retornar_cant_puntos()));
			obj->Grabar_puntajes(datosagrabar);
			obj->Grabar_nombre(nombreagrabar);
		}
		bf->Render(g);
	}
	private: System::Void MyForm2_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Left) obj->Desplazar(direccion::izquierda);
		if (e->KeyCode == Keys::Right) obj->Desplazar(direccion::derecha);
		if (e->KeyCode == Keys::Up) obj->Desplazar(direccion::arriba);
		if (e->KeyCode == Keys::Down) obj->Desplazar(direccion::abajo);
	}
private: System::Void nivel2_Click(System::Object^ sender, System::EventArgs^ e) {
	forms::Ranking^ ranking = gcnew forms::Ranking();
	ranking->Show();
}
private: System::Void menu_Click(System::Object^ sender, System::EventArgs^ e) {
	Close();
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	Close();
}
};
}
