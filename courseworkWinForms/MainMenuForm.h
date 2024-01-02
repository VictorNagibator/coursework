#include "LogsForm.h"
#pragma once

namespace courseworkWinForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainMenuForm
	/// </summary>
	public ref class MainMenuForm : public System::Windows::Forms::Form
	{
	public:
		MainMenuForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainMenuForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ DataWorkingButton;
	private: System::Windows::Forms::Button^ ChooseFileButton;
	private: System::Windows::Forms::Button^ PlayGameButton;
	private: System::Windows::Forms::Button^ OpenLogggerButton;
	private: System::Windows::Forms::Button^ ExitButton;
	private: System::Windows::Forms::Label^ AboutMenuLabel;
	protected:

	protected:





	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->DataWorkingButton = (gcnew System::Windows::Forms::Button());
			this->ChooseFileButton = (gcnew System::Windows::Forms::Button());
			this->PlayGameButton = (gcnew System::Windows::Forms::Button());
			this->OpenLogggerButton = (gcnew System::Windows::Forms::Button());
			this->ExitButton = (gcnew System::Windows::Forms::Button());
			this->AboutMenuLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// DataWorkingButton
			// 
			this->DataWorkingButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->DataWorkingButton->Location = System::Drawing::Point(71, 117);
			this->DataWorkingButton->Name = L"DataWorkingButton";
			this->DataWorkingButton->Size = System::Drawing::Size(240, 51);
			this->DataWorkingButton->TabIndex = 0;
			this->DataWorkingButton->Text = L"Работа с данными";
			this->DataWorkingButton->UseVisualStyleBackColor = true;
			// 
			// ChooseFileButton
			// 
			this->ChooseFileButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->ChooseFileButton->Location = System::Drawing::Point(71, 174);
			this->ChooseFileButton->Name = L"ChooseFileButton";
			this->ChooseFileButton->Size = System::Drawing::Size(240, 51);
			this->ChooseFileButton->TabIndex = 1;
			this->ChooseFileButton->Text = L"Выбрать файл";
			this->ChooseFileButton->UseVisualStyleBackColor = true;
			// 
			// PlayGameButton
			// 
			this->PlayGameButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->PlayGameButton->Location = System::Drawing::Point(71, 231);
			this->PlayGameButton->Name = L"PlayGameButton";
			this->PlayGameButton->Size = System::Drawing::Size(240, 51);
			this->PlayGameButton->TabIndex = 2;
			this->PlayGameButton->Text = L"Играть";
			this->PlayGameButton->UseVisualStyleBackColor = true;
			// 
			// OpenLogggerButton
			// 
			this->OpenLogggerButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->OpenLogggerButton->Location = System::Drawing::Point(71, 288);
			this->OpenLogggerButton->Name = L"OpenLogggerButton";
			this->OpenLogggerButton->Size = System::Drawing::Size(240, 51);
			this->OpenLogggerButton->TabIndex = 3;
			this->OpenLogggerButton->Text = L"Открыть логи";
			this->OpenLogggerButton->UseVisualStyleBackColor = true;
			this->OpenLogggerButton->Click += gcnew System::EventHandler(this, &MainMenuForm::OpenLogggerButton_Click);
			// 
			// ExitButton
			// 
			this->ExitButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ExitButton->Location = System::Drawing::Point(71, 345);
			this->ExitButton->Name = L"ExitButton";
			this->ExitButton->Size = System::Drawing::Size(240, 51);
			this->ExitButton->TabIndex = 4;
			this->ExitButton->Text = L"Выйти";
			this->ExitButton->UseVisualStyleBackColor = true;
			this->ExitButton->Click += gcnew System::EventHandler(this, &MainMenuForm::ExitButton_Click);
			// 
			// AboutMenuLabel
			// 
			this->AboutMenuLabel->AutoSize = true;
			this->AboutMenuLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->AboutMenuLabel->Location = System::Drawing::Point(21, 48);
			this->AboutMenuLabel->Name = L"AboutMenuLabel";
			this->AboutMenuLabel->Size = System::Drawing::Size(347, 29);
			this->AboutMenuLabel->TabIndex = 5;
			this->AboutMenuLabel->Text = L"Сервис работы с ноутбуками";
			// 
			// MainMenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(380, 412);
			this->Controls->Add(this->AboutMenuLabel);
			this->Controls->Add(this->ExitButton);
			this->Controls->Add(this->OpenLogggerButton);
			this->Controls->Add(this->PlayGameButton);
			this->Controls->Add(this->ChooseFileButton);
			this->Controls->Add(this->DataWorkingButton);
			this->Name = L"MainMenuForm";
			this->Text = L"MainMenuForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ExitButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Application::Exit();
	}
	private: System::Void OpenLogggerButton_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		LogsForm^ logsForm = gcnew LogsForm();
		logsForm->Show();
	}
};
}
