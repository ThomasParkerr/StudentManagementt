#pragma once

namespace StudentManagement {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient;

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

            // Title Label
            this->labelTitle->Text = L"Register Student";
            this->labelTitle->Font = (gcnew System::Drawing::Font(L"Arial", 16, FontStyle::Bold));
            this->labelTitle->Location = System::Drawing::Point(120, 20);
            this->labelTitle->AutoSize = true;

            // First Name Label
            this->labelFirstName->Text = L"First Name:";
            this->labelFirstName->Location = System::Drawing::Point(20, 60);

            // Last Name Label
            this->labelLastName->Text = L"Last Name:";
            this->labelLastName->Location = System::Drawing::Point(20, 100);

            // Email Label
            this->labelEmail->Text = L"Email:";
            this->labelEmail->Location = System::Drawing::Point(20, 140);

            // Major Label
            this->labelMajor->Text = L"Major:";
            this->labelMajor->Location = System::Drawing::Point(20, 180);

            // DOB Label
            this->labelDOB->Text = L"Date of Birth:";
            this->labelDOB->Location = System::Drawing::Point(20, 220);

            // TextBoxes and Controls
            this->txtFirstName->Location = System::Drawing::Point(120, 60);
            this->txtLastName->Location = System::Drawing::Point(120, 100);
            this->txtEmail->Location = System::Drawing::Point(120, 140);
            this->comboMajor->Location = System::Drawing::Point(120, 180);
            this->comboMajor->DropDownStyle = ComboBoxStyle::DropDownList;
            this->datePickerDOB->Location = System::Drawing::Point(120, 220);
            this->btnRegister->Text = L"Register";
            this->btnRegister->Location = System::Drawing::Point(120, 260);
            this->btnRegister->Click += gcnew System::EventHandler(this, &RegisterStudent::btnRegister_Click);

            // Add Controls to Form
            this->Controls->Add(this->labelTitle);
            this->Controls->Add(this->labelFirstName);
            this->Controls->Add(this->labelLastName);
            this->Controls->Add(this->labelEmail);
            this->Controls->Add(this->labelMajor);
            this->Controls->Add(this->labelDOB);
            this->Controls->Add(this->txtFirstName);
            this->Controls->Add(this->txtLastName);
            this->Controls->Add(this->txtEmail);
            this->Controls->Add(this->comboMajor);
            this->Controls->Add(this->datePickerDOB);
            this->Controls->Add(this->btnRegister);

            // Form Properties
            this->Text = L"Register Student";
            this->Size = System::Drawing::Size(400, 350);
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

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

        void btnRegister_Click(System::Object^ sender, System::EventArgs^ e)
        {
            try
            {
                MySqlConnection^ conn = gcnew MySqlConnection("server=localhost;user=root;database=studentenroll;password='';");
                conn->Open();

                String^ firstName = txtFirstName->Text;
                String^ lastName = txtLastName->Text;
                String^ email = txtEmail->Text;
                int selectedIndex = comboMajor->SelectedIndex;
                int majorID = majorIDs[selectedIndex];
                String^ dob = datePickerDOB->Value.ToString("yyyy-MM-dd");

                MySqlCommand^ cmd = gcnew MySqlCommand(
                    "INSERT INTO Users (firstName, lastName, email, roleID) VALUES (@firstName, @lastName, @email, 1); SELECT LAST_INSERT_ID();", conn);
                cmd->Parameters->AddWithValue("@firstName", firstName);
                cmd->Parameters->AddWithValue("@lastName", lastName);
                cmd->Parameters->AddWithValue("@email", email);

                int userID = Convert::ToInt32(cmd->ExecuteScalar());

                MySqlCommand^ cmdStudent = gcnew MySqlCommand(
                    "INSERT INTO Students (userID, majorID, dob) VALUES (@userID, @majorID, @dob)", conn);
                cmdStudent->Parameters->AddWithValue("@userID", userID);
                cmdStudent->Parameters->AddWithValue("@majorID", majorID);
                cmdStudent->Parameters->AddWithValue("@dob", dob);

                cmdStudent->ExecuteNonQuery();

                conn->Close();

                MessageBox::Show("Student Registered Successfully with UserID: " + userID.ToString());
                this->Close();
            }
            catch (Exception^ e)
            {
                MessageBox::Show(e->Message);
            }
        }
    };
}
