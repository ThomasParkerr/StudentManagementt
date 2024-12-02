#pragma once

namespace StudentManagement {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient;  // For MySQL database operations

    public ref class Enroll : public System::Windows::Forms::Form
    {
    public:
        Enroll(void)
        {
            InitializeComponent();
        }

    protected:
        ~Enroll()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::Label^ FNAME;
    protected:
    private: System::Windows::Forms::Label^ email;
    private: System::Windows::Forms::StatusStrip^ statusStrip1;
    private: System::Windows::Forms::ComboBox^ comboBox1;
    private: System::Windows::Forms::Label^ courses;
    private: System::Windows::Forms::Label^ enrolll;
    private: System::Windows::Forms::TextBox^ textBox1;
    private: System::Windows::Forms::ComboBox^ comboBox2;
    private: System::Windows::Forms::Label^ label1;

    private: System::Windows::Forms::Button^ enrollButton;
    private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;

    private: System::ComponentModel::Container^ components;
    private:
        MySqlConnection^ sqlConn;
        MySqlCommand^ sqlCmd;
        String^ connectionString = "Server=localhost;Database=studentenroll;Uid=root;Pwd='';";  // MySQL connection string

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->FNAME = (gcnew System::Windows::Forms::Label());
            this->email = (gcnew System::Windows::Forms::Label());
            this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
            this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
            this->courses = (gcnew System::Windows::Forms::Label());
            this->enrolll = (gcnew System::Windows::Forms::Label());
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->enrollButton = (gcnew System::Windows::Forms::Button());
            this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
            this->SuspendLayout();
            // 
            // FNAME
            // 
            this->FNAME->AutoSize = true;
            this->FNAME->Location = System::Drawing::Point(50, 50);
            this->FNAME->Name = L"FNAME";
            this->FNAME->Size = System::Drawing::Size(87, 20);
            this->FNAME->TabIndex = 0;
            this->FNAME->Text = L"Student ID";
            // 
            // email
            // 
            this->email->AutoSize = true;
            this->email->Location = System::Drawing::Point(50, 100);
            this->email->Name = L"email";
            this->email->Size = System::Drawing::Size(48, 20);
            this->email->TabIndex = 1;
            this->email->Text = L"Major";
            // 
            // statusStrip1
            // 
            this->statusStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
            this->statusStrip1->Location = System::Drawing::Point(0, 0);
            this->statusStrip1->Name = L"statusStrip1";
            this->statusStrip1->Size = System::Drawing::Size(200, 22);
            this->statusStrip1->TabIndex = 0;
            // 
            // comboBox1
            // 
            this->comboBox1->FormattingEnabled = true;
            this->comboBox1->Location = System::Drawing::Point(150, 150);
            this->comboBox1->Name = L"comboBox1";
            this->comboBox1->Size = System::Drawing::Size(121, 28);
            this->comboBox1->TabIndex = 2;
            // 
            // courses
            // 
            this->courses->AutoSize = true;
            this->courses->Location = System::Drawing::Point(50, 150);
            this->courses->Name = L"courses";
            this->courses->Size = System::Drawing::Size(68, 20);
            this->courses->TabIndex = 3;
            this->courses->Text = L"Courses";
            // 
            // enrolll
            // 
            this->enrolll->AutoSize = true;
            this->enrolll->Location = System::Drawing::Point(50, 200);
            this->enrolll->Name = L"enrolll";
            this->enrolll->Size = System::Drawing::Size(124, 20);
            this->enrolll->TabIndex = 4;
            this->enrolll->Text = L"Enrollment Date";
            // 
            // textBox1
            // 
            this->textBox1->Location = System::Drawing::Point(150, 50);
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(121, 26);
            this->textBox1->TabIndex = 5;
            // 
            // comboBox2
            // 
            this->comboBox2->FormattingEnabled = true;
            this->comboBox2->Location = System::Drawing::Point(150, 100);
            this->comboBox2->Name = L"comboBox2";
            this->comboBox2->Size = System::Drawing::Size(121, 28);
            this->comboBox2->TabIndex = 6;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(50, 250);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(111, 20);
            this->label1->TabIndex = 7;
            this->label1->Text = L"Course Status";
            // 
            // enrollButton
            // 
            this->enrollButton->Location = System::Drawing::Point(167, 250);
            this->enrollButton->Name = L"enrollButton";
            this->enrollButton->Size = System::Drawing::Size(121, 32);
            this->enrollButton->TabIndex = 9;
            this->enrollButton->Text = L"Enroll";
            this->enrollButton->UseVisualStyleBackColor = true;
            this->enrollButton->Click += gcnew System::EventHandler(this, &Enroll::enrollButton_Click);
            // 
            // dateTimePicker1
            // 
            this->dateTimePicker1->Location = System::Drawing::Point(180, 200);
            this->dateTimePicker1->Name = L"dateTimePicker1";
            this->dateTimePicker1->Size = System::Drawing::Size(121, 26);
            this->dateTimePicker1->TabIndex = 8;
            // 
            // Enroll
            // 
            this->ClientSize = System::Drawing::Size(800, 450);
            this->Controls->Add(this->dateTimePicker1);
            this->Controls->Add(this->enrollButton);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->comboBox2);
            this->Controls->Add(this->textBox1);
            this->Controls->Add(this->enrolll);
            this->Controls->Add(this->courses);
            this->Controls->Add(this->comboBox1);
            this->Controls->Add(this->email);
            this->Controls->Add(this->FNAME);
            this->Name = L"Enroll";
            this->Text = L"Student Enrollment";
            this->Load += gcnew System::EventHandler(this, &Enroll::Enroll_Load);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

        void enrollButton_Click(System::Object^ sender, System::EventArgs^ e)
        {
            String^ studentID = textBox1->Text;
            String^ majorID = comboBox2->Text;
            String^ courseID = comboBox1->Text;
            DateTime^ enrollmentDate = dateTimePicker1->Value;

            // Validate inputs
            if (String::IsNullOrEmpty(studentID) || String::IsNullOrEmpty(majorID) || String::IsNullOrEmpty(courseID))
            {
                MessageBox::Show("Please fill all the fields.");
                return;
            }

            try
            {
                sqlConn = gcnew MySqlConnection(connectionString);
                sqlConn->Open();

                // Get majorID from Majors table
                MySqlCommand^ majorIdCmd = gcnew MySqlCommand("SELECT majorID FROM Majors WHERE major = @major", sqlConn);
                majorIdCmd->Parameters->AddWithValue("@major", majorID);
                int majorId = Convert::ToInt32(majorIdCmd->ExecuteScalar());

                // Get courseID from Courses table
                MySqlCommand^ courseIdCmd = gcnew MySqlCommand("SELECT courseID FROM Courses WHERE courseName = @courseName", sqlConn);
                courseIdCmd->Parameters->AddWithValue("@courseName", courseID);
                int courseId = Convert::ToInt32(courseIdCmd->ExecuteScalar());

                // Start a transaction
                MySqlTransaction^ transaction = sqlConn->BeginTransaction();

                // Insert new record into Enrollments table for the student's course selection
                MySqlCommand^ enrollCmd = gcnew MySqlCommand(
                    "INSERT INTO Enrollments (studentID, courseID, semester) VALUES (@studentID, @courseID, @semester)", sqlConn);
                enrollCmd->Parameters->AddWithValue("@studentID", studentID);
                enrollCmd->Parameters->AddWithValue("@courseID", courseId);
                enrollCmd->Parameters->AddWithValue("@semester", enrollmentDate->ToString("yyyy-MM"));
                enrollCmd->Transaction = transaction;

                // Execute the enrollment insert command
                enrollCmd->ExecuteNonQuery();

                // Commit the transaction
                transaction->Commit();

                MessageBox::Show("Enrollment added successfully!");
            }
            catch (Exception^ ex)
            {
                // Rollback the transaction in case of error
                if (sqlConn->State == ConnectionState::Open)
                {
                    sqlConn->Close();
                }
                MessageBox::Show("Error: " + ex->Message);
            }
        }


        // Event handler to populate ComboBox with course and major
        void Enroll_Load(System::Object^ sender, System::EventArgs^ e)
        {
            try
            {
                sqlConn = gcnew MySqlConnection(connectionString);
                sqlConn->Open();

                // Load courses into comboBox1
                MySqlCommand^ cmd = gcnew MySqlCommand("SELECT courseName FROM Courses", sqlConn);
                MySqlDataReader^ reader = cmd->ExecuteReader();
                while (reader->Read())
                {
                    comboBox1->Items->Add(reader->GetString(0));
                }
                reader->Close();

                // Load majors into comboBox2
                cmd = gcnew MySqlCommand("SELECT major FROM Majors", sqlConn);
                reader = cmd->ExecuteReader();
                while (reader->Read())
                {
                    comboBox2->Items->Add(reader->GetString(0));
                }
                reader->Close();
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error: " + ex->Message);
            }
        }
    };
}
