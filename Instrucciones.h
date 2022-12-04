#pragma once

namespace forms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Instrucciones
	/// </summary>
	public ref class Instrucciones : public System::Windows::Forms::Form
	{
	public:
		Instrucciones(void)
		{
			InitializeComponent();
			//Buffer Graphics
		
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Instrucciones()
		{
			if (components)
			{
				delete components;
			}
		}










	protected:

	private:
		//Buffer Graphics
		
	private: System::Windows::Forms::Button^ volver;
	private: System::Windows::Forms::Button^ nivel1;
	private: System::Windows::Forms::Button^ nivel2;
	private: System::Windows::Forms::Button^ personajes;
	private: System::Windows::Forms::PictureBox^ pictureNivel1;
	private: System::Windows::Forms::PictureBox^ picturePersona;
	private: System::Windows::Forms::PictureBox^ PictureNivel2;




		   /// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Instrucciones::typeid));
			this->volver = (gcnew System::Windows::Forms::Button());
			this->nivel1 = (gcnew System::Windows::Forms::Button());
			this->nivel2 = (gcnew System::Windows::Forms::Button());
			this->personajes = (gcnew System::Windows::Forms::Button());
			this->pictureNivel1 = (gcnew System::Windows::Forms::PictureBox());
			this->picturePersona = (gcnew System::Windows::Forms::PictureBox());
			this->PictureNivel2 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureNivel1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picturePersona))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureNivel2))->BeginInit();
			this->SuspendLayout();
			// 
			// volver
			// 
			this->volver->Font = (gcnew System::Drawing::Font(L"Tempus Sans ITC", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->volver->Location = System::Drawing::Point(173, 519);
			this->volver->Name = L"volver";
			this->volver->Size = System::Drawing::Size(86, 23);
			this->volver->TabIndex = 0;
			this->volver->Text = L"Volver";
			this->volver->UseVisualStyleBackColor = true;
			this->volver->Click += gcnew System::EventHandler(this, &Instrucciones::volver_Click);
			// 
			// nivel1
			// 
			this->nivel1->Font = (gcnew System::Drawing::Font(L"Tempus Sans ITC", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nivel1->Location = System::Drawing::Point(265, 519);
			this->nivel1->Name = L"nivel1";
			this->nivel1->Size = System::Drawing::Size(87, 23);
			this->nivel1->TabIndex = 1;
			this->nivel1->Text = L"Nivel 1";
			this->nivel1->UseVisualStyleBackColor = true;
			this->nivel1->Click += gcnew System::EventHandler(this, &Instrucciones::nivel1_Click);
			// 
			// nivel2
			// 
			this->nivel2->Font = (gcnew System::Drawing::Font(L"Tempus Sans ITC", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nivel2->Location = System::Drawing::Point(358, 519);
			this->nivel2->Name = L"nivel2";
			this->nivel2->Size = System::Drawing::Size(89, 23);
			this->nivel2->TabIndex = 2;
			this->nivel2->Text = L"Nivel 2";
			this->nivel2->UseVisualStyleBackColor = true;
			this->nivel2->Click += gcnew System::EventHandler(this, &Instrucciones::button3_Click);
			// 
			// personajes
			// 
			this->personajes->Font = (gcnew System::Drawing::Font(L"Tempus Sans ITC", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->personajes->Location = System::Drawing::Point(453, 514);
			this->personajes->Name = L"personajes";
			this->personajes->Size = System::Drawing::Size(118, 33);
			this->personajes->TabIndex = 3;
			this->personajes->Text = L"Personajes";
			this->personajes->UseVisualStyleBackColor = true;
			this->personajes->Click += gcnew System::EventHandler(this, &Instrucciones::personajes_Click);
			// 
			// pictureNivel1
			// 
			this->pictureNivel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureNivel1.BackgroundImage")));
			this->pictureNivel1->Location = System::Drawing::Point(170, 8);
			this->pictureNivel1->Name = L"pictureNivel1";
			this->pictureNivel1->Size = System::Drawing::Size(412, 500);
			this->pictureNivel1->TabIndex = 4;
			this->pictureNivel1->TabStop = false;
			// 
			// picturePersona
			// 
			this->picturePersona->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picturePersona.BackgroundImage")));
			this->picturePersona->Location = System::Drawing::Point(170, 8);
			this->picturePersona->Name = L"picturePersona";
			this->picturePersona->Size = System::Drawing::Size(409, 497);
			this->picturePersona->TabIndex = 5;
			this->picturePersona->TabStop = false;
			// 
			// PictureNivel2
			// 
			this->PictureNivel2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PictureNivel2.BackgroundImage")));
			this->PictureNivel2->Location = System::Drawing::Point(171, 8);
			this->PictureNivel2->Name = L"PictureNivel2";
			this->PictureNivel2->Size = System::Drawing::Size(411, 499);
			this->PictureNivel2->TabIndex = 6;
			this->PictureNivel2->TabStop = false;
			this->PictureNivel2->Visible = false;
			this->PictureNivel2->Click += gcnew System::EventHandler(this, &Instrucciones::PictureNivel2_Click);
			// 
			// Instrucciones
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 19);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(774, 554);
			this->Controls->Add(this->PictureNivel2);
			this->Controls->Add(this->picturePersona);
			this->Controls->Add(this->pictureNivel1);
			this->Controls->Add(this->volver);
			this->Controls->Add(this->nivel2);
			this->Controls->Add(this->nivel1);
			this->Controls->Add(this->personajes);
			this->Font = (gcnew System::Drawing::Font(L"Unispace", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->Name = L"Instrucciones";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Instrucciones";
			this->Load += gcnew System::EventHandler(this, &Instrucciones::Instrucciones_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureNivel1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picturePersona))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureNivel2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Instrucciones_Load(System::Object^ sender, System::EventArgs^ e) {
		/*panel_instrucciones->BackColor = Color::FromArgb(100, 0, 0, 0);*/
		picturePersona->Visible = false;
		nivel1->Enabled = false;
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		PictureNivel2->Visible = true;
		picturePersona->Visible = false;
		pictureNivel1->Visible = false;
		nivel2->Enabled = false;
		personajes->Enabled = true;
		nivel1->Enabled = true;
	}
private: System::Void nivel1_Click(System::Object^ sender, System::EventArgs^ e) {
	pictureNivel1->Visible = true;
	picturePersona->Visible = false;
	PictureNivel2->Visible = false;
	nivel1->Enabled = false;
	personajes->Enabled = true;
	nivel2->Enabled = true;
}
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	
}
private: System::Void volver_Click(System::Object^ sender, System::EventArgs^ e) {
	Close();
}
private: System::Void personajes_Click(System::Object^ sender, System::EventArgs^ e) {
	picturePersona->Visible = true;
	pictureNivel1->Visible = false;
	PictureNivel2->Visible = false;
	nivel1->Enabled = true;
	personajes->Enabled = false;
	nivel2 -> Enabled = true;
}
private: System::Void PictureNivel2_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
