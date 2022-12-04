#pragma once

namespace forms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Creditos
	/// </summary>
	public ref class Creditos : public System::Windows::Forms::Form
	{
	public:
		Creditos(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Creditos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ volver;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ credito1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;

	protected:

	private:
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Creditos::typeid));
			this->volver = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->credito1 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// volver
			// 
			this->volver->Font = (gcnew System::Drawing::Font(L"Tempus Sans ITC", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->volver->Location = System::Drawing::Point(185, 519);
			this->volver->Name = L"volver";
			this->volver->Size = System::Drawing::Size(83, 30);
			this->volver->TabIndex = 1;
			this->volver->Text = L"Volver";
			this->volver->UseVisualStyleBackColor = true;
			this->volver->Click += gcnew System::EventHandler(this, &Creditos::volver_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->credito1);
			this->panel1->Font = (gcnew System::Drawing::Font(L"News Gothic MT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->panel1->Location = System::Drawing::Point(185, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(409, 497);
			this->panel1->TabIndex = 2;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(75, 81);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(260, 21);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Carrillo Guevara, Andreé Rodrigo";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(86, 276);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(224, 21);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Sovero Cubillas, John Davids";
			this->label2->Click += gcnew System::EventHandler(this, &Creditos::label2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(97, 171);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(201, 21);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Poma Astete, Luis Felipe";
			// 
			// credito1
			// 
			this->credito1->AutoSize = true;
			this->credito1->Location = System::Drawing::Point(86, 377);
			this->credito1->Name = L"credito1";
			this->credito1->Size = System::Drawing::Size(221, 21);
			this->credito1->TabIndex = 0;
			this->credito1->Text = L"Velarde Luyo, Piero Alberto";
			this->credito1->Click += gcnew System::EventHandler(this, &Creditos::label1_Click);
			// 
			// Creditos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(774, 554);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->volver);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Creditos";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Creditos";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void volver_Click(System::Object^ sender, System::EventArgs^ e) {
		Close();
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
