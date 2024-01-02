#pragma once

namespace courseworkWinForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for LogsForm
	/// </summary>
	public ref class LogsForm : public System::Windows::Forms::Form
	{
	public:
		LogsForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			LoadLogsText();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LogsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ CloseLoggerButton;
	private: System::Windows::Forms::Label^ LogsLabel;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->CloseLoggerButton = (gcnew System::Windows::Forms::Button());
			this->LogsLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// CloseLoggerButton
			// 
			this->CloseLoggerButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->CloseLoggerButton->Location = System::Drawing::Point(172, 321);
			this->CloseLoggerButton->Name = L"CloseLoggerButton";
			this->CloseLoggerButton->Size = System::Drawing::Size(212, 57);
			this->CloseLoggerButton->TabIndex = 0;
			this->CloseLoggerButton->Text = L"Вернуться в меню";
			this->CloseLoggerButton->UseVisualStyleBackColor = true;
			this->CloseLoggerButton->Click += gcnew System::EventHandler(this, &LogsForm::CloseLoggerButton_Click);
			// 
			// LogsLabel
			// 
			this->LogsLabel->AutoSize = true;
			this->LogsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LogsLabel->Location = System::Drawing::Point(28, 26);
			this->LogsLabel->Name = L"LogsLabel";
			this->LogsLabel->Size = System::Drawing::Size(0, 18);
			this->LogsLabel->TabIndex = 1;
			// 
			// LogsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(571, 390);
			this->Controls->Add(this->LogsLabel);
			this->Controls->Add(this->CloseLoggerButton);
			this->Name = L"LogsForm";
			this->Text = L"LogsForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	private: System::Void LoadLogsText() {
		String^ logsText = gcnew String("");
		try {
			StreamReader^ sr = gcnew StreamReader("..\\log.txt");
			logsText = sr->ReadToEnd();
			sr->Close();
		}
		catch (Exception^ e) {
			MessageBox::Show("Файл логов не найден");
			this->Close();
		}
		LogsLabel->Text = logsText;
	}
#pragma endregion
	private: System::Void CloseLoggerButton_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->Close();
	}
	};
}
