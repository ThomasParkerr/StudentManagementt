#pragma once

namespace StudentManagement {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for LogoutForm
	/// </summary>
	public ref class LogoutForm : public System::Windows::Forms::Form
	{
	public:
		LogoutForm(void)
		{
			InitializeComponent();
		}

	protected:
		~LogoutForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::Label^ labelConfirmLogout;
		System::Windows::Forms::Button^ btnYes;
		System::Windows::Forms::Button^ btnNo;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->labelConfirmLogout = (gcnew System::Windows::Forms::Label());
			this->btnYes = (gcnew System::Windows::Forms::Button());
			this->btnNo = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// labelConfirmLogout
			// 
			this->labelConfirmLogout->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 14, System::Drawing::FontStyle::Bold));
			this->labelConfirmLogout->Location = System::Drawing::Point(50, 30);
			this->labelConfirmLogout->Name = L"labelConfirmLogout";
			this->labelConfirmLogout->Size = System::Drawing::Size(655, 40);
			this->labelConfirmLogout->TabIndex = 0;
			this->labelConfirmLogout->Text = L"Are you sure you want to log out\?";
			this->labelConfirmLogout->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btnYes
			// 
			this->btnYes->Location = System::Drawing::Point(189, 317);
			this->btnYes->Name = L"btnYes";
			this->btnYes->Size = System::Drawing::Size(100, 30);
			this->btnYes->TabIndex = 1;
			this->btnYes->Text = L"Yes";
			this->btnYes->UseVisualStyleBackColor = true;
			this->btnYes->Click += gcnew System::EventHandler(this, &LogoutForm::btnYes_Click);
			// 
			// btnNo
			// 
			this->btnNo->Location = System::Drawing::Point(455, 317);
			this->btnNo->Name = L"btnNo";
			this->btnNo->Size = System::Drawing::Size(100, 30);
			this->btnNo->TabIndex = 2;
			this->btnNo->Text = L"No";
			this->btnNo->UseVisualStyleBackColor = true;
			this->btnNo->Click += gcnew System::EventHandler(this, &LogoutForm::btnNo_Click);
			// 
			// LogoutForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(799, 638);
			this->Controls->Add(this->btnNo);
			this->Controls->Add(this->btnYes);
			this->Controls->Add(this->labelConfirmLogout);
			this->Name = L"LogoutForm";
			this->Text = L"Logout";
			this->ResumeLayout(false);

		}
#pragma endregion

	private:
		System::Void btnYes_Click(System::Object^ sender, System::EventArgs^ e) {
			// Logic to handle logout
			// Example: Redirect to login form or close the application
			Application::Exit(); // Exit the application
		}

		System::Void btnNo_Click(System::Object^ sender, System::EventArgs^ e) {
			// Close the logout confirmation dialog
			this->Close();
		}
	};
}
