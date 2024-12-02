#pragma once

namespace StudentManagement {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient; // MySQL namespace

    public ref class RegisterStudent : public System::Windows::Forms::Form
    {
    public:
        RegisterStudent(void)
        {
            InitializeComponent();
            LoadMajors(); // Load majors into the combo box
        }

    protected:
        ~RegisterStudent()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Label^ labelTitle;
        System::Windows::Forms::Label^ labelFirstName;
        System::Windows::Forms::Label^ labelLastName;
        System::Windows::Forms::Label^ labelEmail;
        System::Windows::Forms::Label^ labelMajor;
        System::Windows::Forms::Label^ labelDOB;
        System::Windows::Forms::TextBox^ txtFirstName;
        System::Windows::Forms::TextBox^ txtLastName;
        System::Windows::Forms::TextBox^ txtEmail;
        System::Windows::Forms::ComboBox^ comboMajor;
        System::Windows::Forms::DateTimePicker^ datePickerDOB;
        System::Windows::Forms::Button^ btnRegister;
        System::ComponentModel::Container^ components;
        // Store major IDs to use when saving the student data
        System::Collections::Generic::List<int>^ majorIDs;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->labelTitle = (gcnew System::Windows::Forms::Label());
            this->labelFirstName = (gcnew System::Windows::Forms::Label());
            this->labelLastName = (gcnew System::Windows::Forms::Label());
            this->labelEmail = (gcnew System::Windows::Forms::Label());
            this->labelMajor = (gcnew System::Windows::Forms::Label());
            this->labelDOB = (gcnew System::Windows::Forms::Label());
            this->txtFirstName = (gcnew System::Windows::Forms::TextBox());
            this->txtLastName = (gcnew System::Windows::Forms::TextBox());
            this->txtEmail = (gcnew System::Windows::Forms::TextBox());
            this->comboMajor = (gcnew System::Windows::Forms::ComboBox());
            this->datePickerDOB = (gcnew System::Windows::Forms::DateTimePicker());
            this->btnRegister = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // labelTitle
            // 
            this->labelTitle->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 16, System::Drawing::FontStyle::Bold));
            this->labelTitle->Location = System::Drawing::Point(225, 20);
            this->labelTitle->Name = L"labelTitle";
            this->labelTitle->Size = System::Drawing::Size(281, 40);
            this->labelTitle->TabIndex = 0;
            this->labelTitle->Text = L"Register Student";
            this->labelTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // labelFirstName
            // 
            this->labelFirstName->AutoSize = true;
            this->labelFirstName->Location = System::Drawing::Point(56, 100);
            this->labelFirstName->Name = L"labelFirstName";
            this->labelFirstName->Size = System::Drawing::Size(86, 20);
            this->labelFirstName->TabIndex = 1;
            this->labelFirstName->Text = L"First Name";
            // 
            // labelLastName
            // 
            this->labelLastName->AutoSize = true;
            this->labelLastName->Location = System::Drawing::Point(56, 150);
            this->labelLastName->Name = L"labelLastName";
            this->labelLastName->Size = System::Drawing::Size(86, 20);
            this->labelLastName->TabIndex = 3;
            this->labelLastName->Text = L"Last Name";
            // 
            // labelEmail
            // 
            this->labelEmail->AutoSize = true;
            this->labelEmail->Location = System::Drawing::Point(56, 200);
            this->labelEmail->Name = L"labelEmail";
            this->labelEmail->Size = System::Drawing::Size(48, 20);
            this->labelEmail->TabIndex = 5;
            this->labelEmail->Text = L"Email";
            // 
            // labelMajor
            // 
            this->labelMajor->AutoSize = true;
            this->labelMajor->Location = System::Drawing::Point(56, 253);
            this->labelMajor->Name = L"labelMajor";
            this->labelMajor->Size = System::Drawing::Size(48, 20);
            this->labelMajor->TabIndex = 9;
            this->labelMajor->Text = L"Major";
            // 
            // labelDOB
            // 
            this->labelDOB->AutoSize = true;
            this->labelDOB->Location = System::Drawing::Point(56, 350);
            this->labelDOB->Name = L"labelDOB";
            this->labelDOB->Size = System::Drawing::Size(99, 20);
            this->labelDOB->TabIndex = 11;
            this->labelDOB->Text = L"Date of Birth";
            // 
            // txtFirstName
            // 
            this->txtFirstName->Location = System::Drawing::Point(225, 100);
            this->txtFirstName->Name = L"txtFirstName";
            this->txtFirstName->Size = System::Drawing::Size(337, 26);
            this->txtFirstName->TabIndex = 2;
            // 
            // txtLastName
            // 
            this->txtLastName->Location = System::Drawing::Point(225, 150);
            this->txtLastName->Name = L"txtLastName";
            this->txtLastName->Size = System::Drawing::Size(337, 26);
            this->txtLastName->TabIndex = 4;
            // 
            // txtEmail
            // 
            this->txtEmail->Location = System::Drawing::Point(225, 200);
            this->txtEmail->Name = L"txtEmail";
            this->txtEmail->Size = System::Drawing::Size(337, 26);
            this->txtEmail->TabIndex = 6;
            // 
            // comboMajor
            // 
            this->comboMajor->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->comboMajor->FormattingEnabled = true;
            this->comboMajor->Location = System::Drawing::Point(225, 250);
            this->comboMajor->Name = L"comboMajor";
            this->comboMajor->Size = System::Drawing::Size(337, 28);
            this->comboMajor->TabIndex = 10;
            // 
            // datePickerDOB
            // 
            this->datePickerDOB->Location = System::Drawing::Point(225, 350);
            this->datePickerDOB->Name = L"datePickerDOB";
            this->datePickerDOB->Size = System::Drawing::Size(337, 26);
            this->datePickerDOB->TabIndex = 12;
            // 
            // btnRegister
            // 
            this->btnRegister->Location = System::Drawing::Point(281, 420);
            this->btnRegister->Name = L"btnRegister";
            this->btnRegister->Size = System::Drawing::Size(112, 30);
            this->btnRegister->TabIndex = 13;
            this->btnRegister->Text = L"Register";
            this->btnRegister->UseVisualStyleBackColor = true;
            this->btnRegister->Click += gcnew System::EventHandler(this, &RegisterStudent::btnRegister_Click);
            // 
            // RegisterStudent
            // 
            this->ClientSize = System::Drawing::Size(600, 500);
            this->Controls->Add(this->btnRegister);
            this->Controls->Add(this->datePickerDOB);
            this->Controls->Add(this->comboMajor);
            this->Controls->Add(this->txtEmail);
            this->Controls->Add(this->txtLastName);
            this->Controls->Add(this->txtFirstName);
            this->Controls->Add(this->labelDOB);
            this->Controls->Add(this->labelMajor);
            this->Controls->Add(this->labelEmail);
            this->Controls->Add(this->labelLastName);
            this->Controls->Add(this->labelFirstName);
            this->Controls->Add(this->labelTitle);
            this->Name = L"RegisterStudent";
            this->Text = L"Register Student";
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

        // Method to load majors from the database into the combo box
        void LoadMajors()
        {
            majorIDs = gcnew System::Collections::Generic::List<int>();
            try
            {
                MySqlConnection^ conn = gcnew MySqlConnection("server=localhost;user=root;database=studentenroll;password='';");
                conn->Open();
                MySqlCommand^ cmd = gcnew MySqlCommand("SELECT * FROM Majors", conn);
                MySqlDataReader^ reader = cmd->ExecuteReader();

                while (reader->Read())
                {
                    String^ majorName = reader["major"]->ToString();
                    int majorID = Convert::ToInt32(reader["majorID"]);
                    majorIDs->Add(majorID);
                    comboMajor->Items->Add(majorName);
                }
                conn->Close();
            }
            catch (Exception^ e)
            {
                MessageBox::Show(e->Message);
            }
        }

        // Method to handle registration
        void btnRegister_Click(System::Object^ sender, System::EventArgs^ e)
        {
            try
            {
                // Connect to the MySQL database
                MySqlConnection^ conn = gcnew MySqlConnection("server=localhost;user=root;database=studentenroll;password='';");
                conn->Open();

                // Get user input values
                String^ firstName = txtFirstName->Text;
                String^ lastName = txtLastName->Text;
                String^ email = txtEmail->Text;
                int selectedIndex = comboMajor->SelectedIndex;
                int majorID = majorIDs[selectedIndex]; // Get the selected major ID
                String^ dob = datePickerDOB->Value.ToString("yyyy-MM-dd");

                // Insert the student's details into the Users table (not Students table)
                MySqlCommand^ cmd = gcnew MySqlCommand("INSERT INTO Users (firstName, lastName, email, roleID) VALUES (@firstName, @lastName, @email, 1)", conn);
                cmd->Parameters->AddWithValue("@firstName", firstName);
                cmd->Parameters->AddWithValue("@lastName", lastName);
                cmd->Parameters->AddWithValue("@email", email);

                // Execute the query to insert data into Users table
                cmd->ExecuteNonQuery();

                // Now insert student details into the Students table if needed
                MySqlCommand^ cmdStudent = gcnew MySqlCommand("INSERT INTO Students (majorID, dob) VALUES (@majorID, @dob)", conn);
                cmdStudent->Parameters->AddWithValue("@majorID", majorID);
                cmdStudent->Parameters->AddWithValue("@dob", dob);

                // Execute the query to insert student data
                cmdStudent->ExecuteNonQuery();

                // Close the connection
                conn->Close();

                // Show success message and close form
                MessageBox::Show("Student Registered Successfully!");
                this->Close();
            }
            catch (Exception^ e)
            {
                MessageBox::Show(e->Message);
            }
        }
    };
}
