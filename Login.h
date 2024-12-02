#pragma once
#include "Register.h"
#include "MDI_Form.h"  // Include MDI_Form header

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace MySql::Data::MySqlClient;

namespace StudentManagement {

    public ref class MainForm : public System::Windows::Forms::Form
    {
    public:
        MainForm(void)
        {
            InitializeComponent();
        }

    protected:
        ~MainForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Label^ labelTitle;
        System::Windows::Forms::Label^ labelEmail;
        System::Windows::Forms::Label^ labelPassword;
        System::Windows::Forms::TextBox^ textBoxEmail;
        System::Windows::Forms::TextBox^ textBoxPassword;
        System::Windows::Forms::Button^ buttonLogin;
        System::Windows::Forms::Button^ buttonClear;
        System::Windows::Forms::Label^ labelFeedback;
        System::Windows::Forms::LinkLabel^ linkLabelRegister;

        System::ComponentModel::IContainer^ components;

        // MySQL-related members
    private:
        MySqlConnection^ sqlConn;
        MySqlCommand^ sqlCmd;
        DataTable^ sqlDt;
        MySqlDataAdapter^ sqlDta;
        MySqlDataReader^ sqlRd;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->labelTitle = (gcnew System::Windows::Forms::Label());
            this->labelEmail = (gcnew System::Windows::Forms::Label());
            this->labelPassword = (gcnew System::Windows::Forms::Label());
            this->textBoxEmail = (gcnew System::Windows::Forms::TextBox());
            this->textBoxPassword = (gcnew System::Windows::Forms::TextBox());
            this->buttonLogin = (gcnew System::Windows::Forms::Button());
            this->buttonClear = (gcnew System::Windows::Forms::Button());
            this->labelFeedback = (gcnew System::Windows::Forms::Label());
            this->linkLabelRegister = (gcnew System::Windows::Forms::LinkLabel());
            this->SuspendLayout();
            // 
            // labelTitle
            // 
            this->labelTitle->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 16, System::Drawing::FontStyle::Bold));
            this->labelTitle->Location = System::Drawing::Point(300, 50);
            this->labelTitle->Name = L"labelTitle";
            this->labelTitle->Size = System::Drawing::Size(200, 40);
            this->labelTitle->TabIndex = 0;
            this->labelTitle->Text = L"Login Page";
            this->labelTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // labelEmail
            // 
            this->labelEmail->Location = System::Drawing::Point(159, 123);
            this->labelEmail->Name = L"labelEmail";
            this->labelEmail->Size = System::Drawing::Size(100, 30);
            this->labelEmail->TabIndex = 1;
            this->labelEmail->Text = L"Email:";
            // 
            // labelPassword
            // 
            this->labelPassword->Location = System::Drawing::Point(159, 176);
            this->labelPassword->Name = L"labelPassword";
            this->labelPassword->Size = System::Drawing::Size(100, 30);
            this->labelPassword->TabIndex = 2;
            this->labelPassword->Text = L"Password:";
            // 
            // textBoxEmail
            // 
            this->textBoxEmail->Location = System::Drawing::Point(300, 120);
            this->textBoxEmail->Name = L"textBoxEmail";
            this->textBoxEmail->Size = System::Drawing::Size(300, 26);
            this->textBoxEmail->TabIndex = 3;
            // 
            // textBoxPassword
            // 
            this->textBoxPassword->Location = System::Drawing::Point(300, 180);
            this->textBoxPassword->Name = L"textBoxPassword";
            this->textBoxPassword->Size = System::Drawing::Size(300, 26);
            this->textBoxPassword->TabIndex = 4;
            this->textBoxPassword->UseSystemPasswordChar = true;
            // 
            // buttonLogin
            // 
            this->buttonLogin->Location = System::Drawing::Point(300, 250);
            this->buttonLogin->Name = L"buttonLogin";
            this->buttonLogin->Size = System::Drawing::Size(140, 40);
            this->buttonLogin->TabIndex = 5;
            this->buttonLogin->Text = L"Login";
            this->buttonLogin->Click += gcnew System::EventHandler(this, &MainForm::buttonLogin_Click);
            // 
            // buttonClear
            // 
            this->buttonClear->Location = System::Drawing::Point(460, 250);
            this->buttonClear->Name = L"buttonClear";
            this->buttonClear->Size = System::Drawing::Size(140, 40);
            this->buttonClear->TabIndex = 6;
            this->buttonClear->Text = L"Clear";
            this->buttonClear->Click += gcnew System::EventHandler(this, &MainForm::buttonClear_Click);
            // 
            // labelFeedback
            // 
            this->labelFeedback->ForeColor = System::Drawing::Color::Red;
            this->labelFeedback->Location = System::Drawing::Point(300, 280);
            this->labelFeedback->Name = L"labelFeedback";
            this->labelFeedback->Size = System::Drawing::Size(300, 30);
            this->labelFeedback->TabIndex = 7;
            // 
            // linkLabelRegister
            // 
            this->linkLabelRegister->AutoSize = true;
            this->linkLabelRegister->Location = System::Drawing::Point(300, 333);
            this->linkLabelRegister->Name = L"linkLabelRegister";
            this->linkLabelRegister->Size = System::Drawing::Size(153, 20);
            this->linkLabelRegister->TabIndex = 8;
            this->linkLabelRegister->TabStop = true;
            this->linkLabelRegister->Text = L"Click here to register";
            this->linkLabelRegister->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MainForm::linkLabelRegister_LinkClicked);
            // 
            // MainForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(800, 400);
            this->Controls->Add(this->linkLabelRegister);
            this->Controls->Add(this->labelTitle);
            this->Controls->Add(this->labelEmail);
            this->Controls->Add(this->labelPassword);
            this->Controls->Add(this->textBoxEmail);
            this->Controls->Add(this->textBoxPassword);
            this->Controls->Add(this->buttonLogin);
            this->Controls->Add(this->buttonClear);
            this->Controls->Add(this->labelFeedback);
            this->Name = L"MainForm";
            this->Text = L"Login";
            this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

        // Login button click event
    private: System::Void buttonLogin_Click(System::Object^ sender, System::EventArgs^ e) {
        String^ email = this->textBoxEmail->Text;
        String^ password = this->textBoxPassword->Text;

        String^ connectionString = "Server=localhost;Database=studentenroll;Uid=root;Pwd='';";

        try {
            sqlConn = gcnew MySqlConnection(connectionString);
            sqlConn->Open();

            String^ query = "SELECT userID, roleID FROM users WHERE email = @Email AND password = @Password";
            sqlCmd = gcnew MySqlCommand(query, sqlConn);
            sqlCmd->Parameters->AddWithValue("@Email", email);
            sqlCmd->Parameters->AddWithValue("@Password", password);

            sqlRd = sqlCmd->ExecuteReader();

            if (sqlRd->Read()) {
                int roleID = (int)sqlRd["roleID"];
                String^ userID = sqlRd["userID"]->ToString();

                this->Hide();
                MDI_Form^ mdiForm = gcnew MDI_Form(userID);
                mdiForm->ShowDialog();
            }
            else {
                labelFeedback->Text = "Invalid email or password.";
            }
        }
        catch (Exception^ ex) {
            labelFeedback->Text = "Error connecting to database: " + ex->Message;
        }
        finally {
            if (sqlRd != nullptr) sqlRd->Close();
            if (sqlConn != nullptr) sqlConn->Close();
        }
    }

    private: System::Void buttonClear_Click(System::Object^ sender, System::EventArgs^ e) {
        this->textBoxEmail->Text = "";
        this->textBoxPassword->Text = "";
        this->labelFeedback->Text = "";
    }

    private: System::Void linkLabelRegister_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
        this->Hide();
        RegisterForm^ registerForm = gcnew RegisterForm();
        registerForm->ShowDialog();
    }

    private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
        this->textBoxPassword->UseSystemPasswordChar = true;
    }
    };
}
