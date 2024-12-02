#pragma once

using namespace System;
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient; // Include MySQL namespace

namespace StudentManagement {

    public ref class RegisterForm : public System::Windows::Forms::Form
    {
    public:
        RegisterForm(void)
        {
            InitializeComponent();
        }

    protected:
        ~RegisterForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Label^ labelEmail;
        System::Windows::Forms::Label^ labelPassword;
        System::Windows::Forms::TextBox^ textBoxEmail;
        System::Windows::Forms::TextBox^ textBoxPassword;
        System::Windows::Forms::Button^ buttonUpdatePassword;
        System::Windows::Forms::Label^ labelFeedback;
        System::ComponentModel::IContainer^ components;

        MySqlConnection^ sqlConn;
        MySqlCommand^ sqlCmd;

        void InitializeComponent(void)
        {
            this->labelEmail = (gcnew System::Windows::Forms::Label());
            this->labelPassword = (gcnew System::Windows::Forms::Label());
            this->textBoxEmail = (gcnew System::Windows::Forms::TextBox());
            this->textBoxPassword = (gcnew System::Windows::Forms::TextBox());
            this->buttonUpdatePassword = (gcnew System::Windows::Forms::Button());
            this->labelFeedback = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // labelEmail
            // 
            this->labelEmail->Location = System::Drawing::Point(159, 123);
            this->labelEmail->Name = L"labelEmail";
            this->labelEmail->Size = System::Drawing::Size(100, 30);
            this->labelEmail->TabIndex = 0;
            this->labelEmail->Text = L"Email:";
            // 
            // labelPassword
            // 
            this->labelPassword->Location = System::Drawing::Point(159, 176);
            this->labelPassword->Name = L"labelPassword";
            this->labelPassword->Size = System::Drawing::Size(100, 30);
            this->labelPassword->TabIndex = 1;
            this->labelPassword->Text = L"New Password:";
            // 
            // textBoxEmail
            // 
            this->textBoxEmail->Location = System::Drawing::Point(300, 120);
            this->textBoxEmail->Name = L"textBoxEmail";
            this->textBoxEmail->Size = System::Drawing::Size(300, 26);
            this->textBoxEmail->TabIndex = 2;
            // 
            // textBoxPassword
            // 
            this->textBoxPassword->Location = System::Drawing::Point(300, 180);
            this->textBoxPassword->Name = L"textBoxPassword";
            this->textBoxPassword->Size = System::Drawing::Size(300, 26);
            this->textBoxPassword->TabIndex = 3;
            this->textBoxPassword->UseSystemPasswordChar = true;
            // 
            // buttonUpdatePassword
            // 
            this->buttonUpdatePassword->Location = System::Drawing::Point(300, 240);
            this->buttonUpdatePassword->Name = L"buttonUpdatePassword";
            this->buttonUpdatePassword->Size = System::Drawing::Size(140, 40);
            this->buttonUpdatePassword->TabIndex = 4;
            this->buttonUpdatePassword->Text = L"Update Password";
            this->buttonUpdatePassword->Click += gcnew System::EventHandler(this, &RegisterForm::buttonUpdatePassword_Click);
            // 
            // labelFeedback
            // 
            this->labelFeedback->ForeColor = System::Drawing::Color::Red;
            this->labelFeedback->Location = System::Drawing::Point(300, 280);
            this->labelFeedback->Name = L"labelFeedback";
            this->labelFeedback->Size = System::Drawing::Size(300, 30);
            this->labelFeedback->TabIndex = 5;
            // 
            // RegisterForm
            // 
            this->ClientSize = System::Drawing::Size(800, 400);
            this->Controls->Add(this->labelEmail);
            this->Controls->Add(this->labelPassword);
            this->Controls->Add(this->textBoxEmail);
            this->Controls->Add(this->textBoxPassword);
            this->Controls->Add(this->buttonUpdatePassword);
            this->Controls->Add(this->labelFeedback);
            this->Name = L"RegisterForm";
            this->Text = L"Update Password";
            this->ResumeLayout(false);
            this->PerformLayout();
        }

        void buttonUpdatePassword_Click(System::Object^ sender, System::EventArgs^ e) {
            String^ email = this->textBoxEmail->Text;
            String^ password = this->textBoxPassword->Text;

            // Connection string: Update with your MySQL server details
            String^ connectionString = "Server=localhost;Database=studentenroll;Uid=root;Pwd='';";

            try {
                sqlConn = gcnew MySqlConnection(connectionString);
                sqlConn->Open();

                // Query to check if the email exists and update the password
                String^ query = "UPDATE users SET password = @password WHERE email = @email";
                sqlCmd = gcnew MySqlCommand(query, sqlConn);
                sqlCmd->Parameters->AddWithValue("@email", email);
                sqlCmd->Parameters->AddWithValue("@password", password);

                int rowsAffected = sqlCmd->ExecuteNonQuery();

                if (rowsAffected > 0) {
                    this->labelFeedback->Text = L"Password updated successfully!";
                    this->labelFeedback->ForeColor = System::Drawing::Color::Green;
                }
                else {
                    this->labelFeedback->Text = L"No user found with that email.";
                    this->labelFeedback->ForeColor = System::Drawing::Color::Red;
                }

                sqlConn->Close();
            }
            catch (MySqlException^ ex) {
                this->labelFeedback->Text = L"Database error: " + ex->Message;
                this->labelFeedback->ForeColor = System::Drawing::Color::Red;
            }
            catch (Exception^ ex) {
                this->labelFeedback->Text = L"Error: " + ex->Message;
                this->labelFeedback->ForeColor = System::Drawing::Color::Red;
            }
        }
    };
}
