#pragma once
#include "MyForm2.h"
#include "Controladora.h"

namespace forms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//Objetos
			obj = new Controladora();
			
			//Buffer Graphics
			g = CreateGraphics();
			espacio = BufferedGraphicsManager::Current;
			bf = espacio->Allocate(g, ClientRectangle);

			//Imagenes de fondo
			bmpMapa = gcnew Bitmap(obj->retornar_imagen_mapa());
			

			//Personajes
			bmpContaminador = gcnew Bitmap(obj->retornar_imagen_contaminador());
			bmpJugador = gcnew Bitmap(obj->retornar_imagen_jugador());
			
			//Items
			bmpMetal = gcnew Bitmap(obj->retornar_imagen_metales());
			bmpMateriaO = gcnew Bitmap(obj->retornar_imagen_materia());;
			bmpPapel = gcnew Bitmap(obj->retornar_imagen_papeles());
			bmpPlastico = gcnew Bitmap(obj->retornar_imagen_plastico());
			bmpVidrio = gcnew Bitmap(obj->retornar_imagen_botella());
			bmpCurita = gcnew Bitmap(obj->retornar_imagen_curita());
			bmpVacuna = gcnew Bitmap(obj->retornar_imagen_vacuna());

		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			delete g, espacio, bf, bmpMapa, bmpJugador, bmpContaminador;
			delete bmpMetal, bmpMateriaO, bmpPapel, bmpPlastico, bmpVidrio, bmpCurita,bmpVacuna,nombre_jugador, obj;
		}

	private:
		//Objetos
		Controladora* obj;

		//Buffer Graphics
		Graphics^ g;
		BufferedGraphicsContext^ espacio;
		BufferedGraphics^ bf;

		//Imagenes de fondo
		Bitmap^ bmpMapa;		

		//Personajes imagenes
		Bitmap^ bmpJugador;
		Bitmap^ bmpContaminador;

		//Items
		Bitmap^ bmpMetal;
		Bitmap^ bmpMateriaO;
		Bitmap^ bmpPapel;
		Bitmap^ bmpPlastico;
		Bitmap^ bmpVidrio;
		Bitmap^ bmpCurita;
		Bitmap^ bmpVacuna;
		String^ nombre_jugador;


	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Panel^ datos;
	private: System::Windows::Forms::Label^ Vidas;
	private: System::Windows::Forms::Label^ Puntos;
	private: System::Windows::Forms::Label^ estado;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ tiempo;
	private: System::Windows::Forms::Label^ points;
	private: System::Windows::Forms::Label^ time;
	private: System::Windows::Forms::Button^ menu;
	private: System::Windows::Forms::Label^ manos;
	private: System::Windows::Forms::Button^ nivel2;
	private: System::Windows::Forms::Button^ button1;
	private: System::ComponentModel::IContainer^ components;
		   /// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->datos = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->manos = (gcnew System::Windows::Forms::Label());
			this->time = (gcnew System::Windows::Forms::Label());
			this->estado = (gcnew System::Windows::Forms::Label());
			this->Puntos = (gcnew System::Windows::Forms::Label());
			this->Vidas = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->nivel2 = (gcnew System::Windows::Forms::Button());
			this->menu = (gcnew System::Windows::Forms::Button());
			this->points = (gcnew System::Windows::Forms::Label());
			this->tiempo = (gcnew System::Windows::Forms::Label());
			this->datos->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
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
			this->datos->Size = System::Drawing::Size(1831, 61);
			this->datos->TabIndex = 5;
			this->datos->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::datos_Paint);
			// 
			// button1
			// 
			this->button1->CausesValidation = false;
			this->button1->Font = (gcnew System::Drawing::Font(L"Tempus Sans ITC", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(1788, 8);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(110, 43);
			this->button1->TabIndex = 4;
			this->button1->TabStop = false;
			this->button1->Text = L"Menu";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
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
			this->estado->Location = System::Drawing::Point(848, 9);
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
			this->Puntos->Location = System::Drawing::Point(488, 9);
			this->Puntos->Name = L"Puntos";
			this->Puntos->Size = System::Drawing::Size(93, 36);
			this->Puntos->TabIndex = 1;
			this->Puntos->Text = L"label1";
			this->Puntos->Click += gcnew System::EventHandler(this, &MyForm::label1_Click_1);
			// 
			// Vidas
			// 
			this->Vidas->AutoSize = true;
			this->Vidas->Font = (gcnew System::Drawing::Font(L"Times New Roman", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Vidas->Location = System::Drawing::Point(96, 9);
			this->Vidas->Name = L"Vidas";
			this->Vidas->Size = System::Drawing::Size(93, 36);
			this->Vidas->TabIndex = 0;
			this->Vidas->Text = L"label1";
			this->Vidas->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::YellowGreen;
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->Controls->Add(this->nivel2);
			this->panel1->Controls->Add(this->menu);
			this->panel1->Controls->Add(this->points);
			this->panel1->Controls->Add(this->tiempo);
			this->panel1->Location = System::Drawing::Point(520, 250);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(807, 540);
			this->panel1->TabIndex = 6;
			this->panel1->Visible = false;
			// 
			// nivel2
			// 
			this->nivel2->Font = (gcnew System::Drawing::Font(L"Tempus Sans ITC", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nivel2->Location = System::Drawing::Point(521, 437);
			this->nivel2->Name = L"nivel2";
			this->nivel2->Size = System::Drawing::Size(170, 47);
			this->nivel2->TabIndex = 3;
			this->nivel2->Text = L"Ir Nivel 2";
			this->nivel2->UseVisualStyleBackColor = true;
			this->nivel2->Click += gcnew System::EventHandler(this, &MyForm::nivel2_Click);
			// 
			// menu
			// 
			this->menu->Font = (gcnew System::Drawing::Font(L"Tempus Sans ITC", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->menu->Location = System::Drawing::Point(173, 437);
			this->menu->Name = L"menu";
			this->menu->Size = System::Drawing::Size(144, 47);
			this->menu->TabIndex = 2;
			this->menu->Text = L"Menu";
			this->menu->UseVisualStyleBackColor = true;
			this->menu->Visible = false;
			this->menu->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// points
			// 
			this->points->AutoSize = true;
			this->points->BackColor = System::Drawing::Color::Lavender;
			this->points->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->points->Location = System::Drawing::Point(312, 344);
			this->points->Name = L"points";
			this->points->Size = System::Drawing::Size(109, 39);
			this->points->TabIndex = 1;
			this->points->Text = L"label1";
			this->points->Visible = false;
			this->points->Click += gcnew System::EventHandler(this, &MyForm::points_Click);
			// 
			// tiempo
			// 
			this->tiempo->AutoSize = true;
			this->tiempo->BackColor = System::Drawing::Color::Lavender;
			this->tiempo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tiempo->Location = System::Drawing::Point(255, 253);
			this->tiempo->Name = L"tiempo";
			this->tiempo->Size = System::Drawing::Size(109, 39);
			this->tiempo->TabIndex = 0;
			this->tiempo->Text = L"label1";
			this->tiempo->Visible = false;
			this->tiempo->Click += gcnew System::EventHandler(this, &MyForm::label1_Click_2);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1831, 801);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->datos);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->datos->ResumeLayout(false);
			this->datos->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	public: void cambiar_nombre_jugador(String^ nuevo)
	{
		nombre_jugador = nuevo;
	}
	public: String^ retornar_nombre_jugador()
	{
		return nombre_jugador;
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {}
	
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	
		bf->Graphics->Clear(Color::White);
		bf->Graphics->DrawImage(bmpMapa, 0, 0,ClientRectangle.Width, ClientRectangle.Height);
		obj->Dibujar_Contaminadores(bf->Graphics, bmpContaminador);
		obj->Dibujar_Basura(bf->Graphics, bmpMetal,bmpMateriaO,bmpPapel,bmpPlastico,bmpVidrio);
		obj->Dibujar_Jugador(bf->Graphics, bmpJugador);
		obj->Dibujar_Curaciones(bf->Graphics, bmpCurita,bmpVacuna);
		obj->Dibujar_Obstaculos(bf->Graphics);
		Vidas->Text = Convert::ToString("Vidas: " + obj->retornar_jugador()->retornar_cant_vidas());
		Puntos->Text = Convert::ToString("Puntos: " + obj->retornar_jugador()->retornar_cant_puntos());
		time->Text = Convert::ToString("Tiempo: " + obj->retornar_tiempo() + " segundos");
		tiempo->Text = Convert::ToString("Tiempo: " + obj->retornar_tiempo() + " segundos");
		points->Text = Convert::ToString("Puntaje: " + obj->retornar_jugador()->retornar_cant_puntos());
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
		if (obj->estado()){estado->Text = Convert::ToString("Estado: "+ "Herido");}
		if (!obj->estado()) { estado->Text = Convert::ToString("Estado: " + "Sano"); }
		if (obj->acabar_nivel1()) { 
			timer1->Stop(); 
			datos->Visible = false;
			panel1->Visible = true;
			tiempo->Visible = true;
			points->Visible = true;
			menu->Visible = true;
			if (obj->retornar_jugador()->retornar_cant_puntos()>200 && obj->retornar_jugador()->retornar_cant_vidas()>0)
			{
				nivel2->Visible = true;
			}
			else {
				nivel2->Visible = false;
			}
		}

		bf->Render(g);
	}

	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Left) obj->Desplazar(direccion::izquierda);
		if (e->KeyCode == Keys::Right) obj->Desplazar(direccion::derecha);
		if (e->KeyCode == Keys::Up) obj->Desplazar(direccion::arriba);
		if (e->KeyCode == Keys::Down) obj->Desplazar(direccion::abajo);
	}
	
	private: System::Void datos_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click_2(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void points_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Close();
	}
	private: System::Void nivel2_Click(System::Object^ sender, System::EventArgs^ e) {
		MyForm2^ JugarNivel2 = gcnew MyForm2();
		JugarNivel2->cambiar_nombre_del_jugador(nombre_jugador);
		JugarNivel2->Show();
		Close();
		
	}
	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
		Close();
	}
};
}
