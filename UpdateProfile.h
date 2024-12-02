#pragma once

namespace StudentManagement {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient;

    public ref class FacultyProfile : public System::Windows::Forms::Form
    {
    public:
        FacultyProfile(void)
        {
            InitializeComponent();
            LoadDepartments(); // Populate the ComboBox with department names
        }

    protected:
        ~FacultyProfile()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::ComponentModel::Container^ components;
        System::Windows::Forms::Label^ labelFacultyID;

        System::Windows::Forms::Label^ labelEmail;
        System::Windows::Forms::Label^ labelPhone;
        System::Windows::Forms::Label^ labelDepartment;

        System::Windows::Forms::Label^ labelAddress;
        System::Windows::Forms::TextBox^ txtFacultyID;

        System::Windows::Forms::TextBox^ txtEmail;
        System::Windows::Forms::TextBox^ txtPhone;
        System::Windows::Forms::TextBox^ txtAddress;
        System::Windows::Forms::DateTimePicker^ dtpDOB;
        System::Windows::Forms::ComboBox^ cmbDepartment;
        System::Windows::Forms::Button^ btnUpdateProfile;
        System::Windows::Forms::Button^ btnLoadProfile;

        String^ connectionString = "Server=localhost;Database=studentenroll;User ID=root;Password=\"\";";
        MySqlConnection^ conn;
        MySqlCommand^ cmd;
        MySqlDataReader^ reader;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->labelFacultyID = (gcnew System::Windows::Forms::Label());
            this->labelEmail = (gcnew System::Windows::Forms::Label());
            this->labelPhone = (gcnew System::Windows::Forms::Label());
            this->labelDepartment = (gcnew System::Windows::Forms::Label());
            this->labelAddress = (gcnew System::Windows::Forms::Label());
            this->txtFacultyID = (gcnew System::Windows::Forms::TextBox());
            this->txtEmail = (gcnew System::Windows::Forms::TextBox());
            this->txtPhone = (gcnew System::Windows::Forms::TextBox());
            this->cmbDepartment = (gcnew System::Windows::Forms::ComboBox());
            this->txtAddress = (gcnew System::Windows::Forms::TextBox());
            this->dtpDOB = (gcnew System::Windows::Forms::DateTimePicker());
            this->btnUpdateProfile = (gcnew System::Windows::Forms::Button());
            this->btnLoadProfile = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // labelFacultyID
            // 
            this->labelFacultyID->Location = System::Drawing::Point(20, 20);
            this->labelFacultyID->Name = L"labelFacultyID";
            this->labelFacultyID->Size = System::Drawing::Size(100, 23);
            this->labelFacultyID->TabIndex = 14;
            this->labelFacultyID->Text = L"Faculty ID:";
            // 
            // labelEmail
            // 
            this->labelEmail->Location = System::Drawing::Point(20, 81);
            this->labelEmail->Name = L"labelEmail";
            this->labelEmail->Size = System::Drawing::Size(100, 23);
            this->labelEmail->TabIndex = 12;
            this->labelEmail->Text = L"Email:";
            // 
            // labelPhone
            // 
            this->labelPhone->Location = System::Drawing::Point(20, 131);
            this->labelPhone->Name = L"labelPhone";
            this->labelPhone->Size = System::Drawing::Size(100, 23);
            this->labelPhone->TabIndex = 11;
            this->labelPhone->Text = L"Phone:";
            // 
            // labelDepartment
            // 
            this->labelDepartment->Location = System::Drawing::Point(20, 185);
            this->labelDepartment->Name = L"labelDepartment";
            this->labelDepartment->Size = System::Drawing::Size(100, 23);
            this->labelDepartment->TabIndex = 10;
            this->labelDepartment->Text = L"Department:";
            // 
            // labelAddress
            // 
            this->labelAddress->Location = System::Drawing::Point(20, 248);
            this->labelAddress->Name = L"labelAddress";
            this->labelAddress->Size = System::Drawing::Size(100, 23);
            this->labelAddress->TabIndex = 8;
            this->labelAddress->Text = L"Address:";
            // 
            // txtFacultyID
            // 
            this->txtFacultyID->Location = System::Drawing::Point(130, 20);
            this->txtFacultyID->Name = L"txtFacultyID";
            this->txtFacultyID->Size = System::Drawing::Size(150, 26);
            this->txtFacultyID->TabIndex = 7;
            // 
            // txtEmail
            // 
            this->txtEmail->Location = System::Drawing::Point(130, 81);
            this->txtEmail->Name = L"txtEmail";
            this->txtEmail->Size = System::Drawing::Size(150, 26);
            this->txtEmail->TabIndex = 5;
            // 
            // txtPhone
            // 
            this->txtPhone->Location = System::Drawing::Point(130, 131);
            this->txtPhone->Name = L"txtPhone";
            this->txtPhone->Size = System::Drawing::Size(150, 26);
            this->txtPhone->TabIndex = 4;
            // 
            // cmbDepartment
            // 
            this->cmbDepartment->Location = System::Drawing::Point(130, 180);
            this->cmbDepartment->Name = L"cmbDepartment";
            this->cmbDepartment->Size = System::Drawing::Size(150, 28);
            this->cmbDepartment->TabIndex = 3;
            // 
            // txtAddress
            // 
            this->txtAddress->Location = System::Drawing::Point(130, 248);
            this->txtAddress->Name = L"txtAddress";
            this->txtAddress->Size = System::Drawing::Size(150, 26);
            this->txtAddress->TabIndex = 2;
            // 
            // dtpDOB
            // 
            this->dtpDOB->Format = System::Windows::Forms::DateTimePickerFormat::Short;
            this->dtpDOB->Location = System::Drawing::Point(130, 220);
            this->dtpDOB->Name = L"dtpDOB";
            this->dtpDOB->Size = System::Drawing::Size(200, 26);
            this->dtpDOB->TabIndex = 0;
            // 
            // btnUpdateProfile
            // 
            this->btnUpdateProfile->Location = System::Drawing::Point(109, 308);
            this->btnUpdateProfile->Name = L"btnUpdateProfile";
            this->btnUpdateProfile->Size = System::Drawing::Size(75, 23);
            this->btnUpdateProfile->TabIndex = 0;
            this->btnUpdateProfile->Text = L"Update Profile";
            this->btnUpdateProfile->Click += gcnew System::EventHandler(this, &FacultyProfile::btnUpdateProfile_Click);
            // 
            // btnLoadProfile
            // 
            this->btnLoadProfile->Location = System::Drawing::Point(109, 351);
            this->btnLoadProfile->Name = L"btnLoadProfile";
            this->btnLoadProfile->Size = System::Drawing::Size(75, 23);
            this->btnLoadProfile->TabIndex = 1;
            this->btnLoadProfile->Text = L"Load Profile";
            // 
            // FacultyProfile
            // 
            this->ClientSize = System::Drawing::Size(300, 400);
            this->Controls->Add(this->btnUpdateProfile);
            this->Controls->Add(this->btnLoadProfile);
            this->Controls->Add(this->txtAddress);
            this->Controls->Add(this->cmbDepartment);
            this->Controls->Add(this->txtPhone);
            this->Controls->Add(this->txtEmail);
            this->Controls->Add(this->txtFacultyID);
            this->Controls->Add(this->labelAddress);
            this->Controls->Add(this->labelDepartment);
            this->Controls->Add(this->labelPhone);
            this->Controls->Add(this->labelEmail);
            this->Controls->Add(this->labelFacultyID);
            this->Name = L"FacultyProfile";
            this->Text = L"Faculty Profile Update";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

        void LoadDepartments()
        {
            conn = gcnew MySqlConnection(connectionString);
            String^ query = "SELECT department FROM faculty";
            cmd = gcnew MySqlCommand(query, conn);

            try
            {
                conn->Open();
                reader = cmd->ExecuteReader();
                while (reader->Read())
                {
                    cmbDepartment->Items->Add(reader["department"]->ToString());
                }
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error loading departments: " + ex->Message);
            }
            finally
            {
                if (conn->State == ConnectionState::Open)
                {
                    conn->Close();
                }
            }
        }

        void btnUpdateProfile_Click(System::Object^ sender, System::EventArgs^ e)
        {
            conn = gcnew MySqlConnection(connectionString);
            String^ facultyID = txtFacultyID->Text;
            String^ email = txtEmail->Text;
            String^ phone = txtPhone->Text;
            String^ department = cmbDepartment->Text; // Get selected department
            DateTime dob = dtpDOB->Value;
            String^ address = txtAddress->Text;

            String^ query = "UPDATE faculty SET email = @email, phone = @phone, department = @department, address = @address WHERE facultyID = @facultyID";
            cmd = gcnew MySqlCommand(query, conn);

            cmd->Parameters->AddWithValue("@facultyID", facultyID);
            cmd->Parameters->AddWithValue("@email", email);
            cmd->Parameters->AddWithValue("@phone", phone);
            cmd->Parameters->AddWithValue("@department", department);
            cmd->Parameters->AddWithValue("@address", address);

            try
            {
                conn->Open();
                cmd->ExecuteNonQuery();
                MessageBox::Show("Profile updated successfully!");
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error updating profile: " + ex->Message);
            }
            finally
            {
                if (conn->State == ConnectionState::Open)
                {
                    conn->Close();
                }
            }
        }
    };
}
