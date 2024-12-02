#pragma once

namespace StudentManagement {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient; // MySQL Connector namespace

    public ref class GRADES : public System::Windows::Forms::Form
    {
    public:
        GRADES(void)
        {
            InitializeComponent();
        }

    protected:
        ~GRADES()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::ComponentModel::Container^ components;
        System::Windows::Forms::Label^ lblTitle;
        System::Windows::Forms::Label^ lblCourse;
        System::Windows::Forms::Label^ lblMajor;
        System::Windows::Forms::Label^ lblStudentID;
        System::Windows::Forms::Label^ lblGrade;
        System::Windows::Forms::ComboBox^ cbCourse;
        System::Windows::Forms::ComboBox^ cbMajor;
        System::Windows::Forms::TextBox^ txtStudentID;
        System::Windows::Forms::TextBox^ txtGrade;
        System::Windows::Forms::Button^ btnUpdateGrade;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->lblTitle = (gcnew System::Windows::Forms::Label());
            this->lblCourse = (gcnew System::Windows::Forms::Label());
            this->lblMajor = (gcnew System::Windows::Forms::Label());
            this->lblStudentID = (gcnew System::Windows::Forms::Label());
            this->lblGrade = (gcnew System::Windows::Forms::Label());
            this->cbCourse = (gcnew System::Windows::Forms::ComboBox());
            this->cbMajor = (gcnew System::Windows::Forms::ComboBox());
            this->txtStudentID = (gcnew System::Windows::Forms::TextBox());
            this->txtGrade = (gcnew System::Windows::Forms::TextBox());
            this->btnUpdateGrade = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // lblTitle
            // 
            this->lblTitle->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 16, System::Drawing::FontStyle::Bold));
            this->lblTitle->Location = System::Drawing::Point(200, 20);
            this->lblTitle->Name = L"lblTitle";
            this->lblTitle->Size = System::Drawing::Size(300, 40);
            this->lblTitle->TabIndex = 0;
            this->lblTitle->Text = L"Update Grades";
            this->lblTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // lblCourse
            // 
            this->lblCourse->AutoSize = true;
            this->lblCourse->Location = System::Drawing::Point(50, 100);
            this->lblCourse->Name = L"lblCourse";
            this->lblCourse->Size = System::Drawing::Size(66, 20);
            this->lblCourse->TabIndex = 1;
            this->lblCourse->Text = L"Course:";
            // 
            // cbCourse
            // 
            this->cbCourse->FormattingEnabled = true;
            this->cbCourse->Location = System::Drawing::Point(150, 100);
            this->cbCourse->Name = L"cbCourse";
            this->cbCourse->Size = System::Drawing::Size(400, 28);
            this->cbCourse->TabIndex = 2;
            // 
            // lblMajor
            // 
            this->lblMajor->AutoSize = true;
            this->lblMajor->Location = System::Drawing::Point(50, 150);
            this->lblMajor->Name = L"lblMajor";
            this->lblMajor->Size = System::Drawing::Size(54, 20);
            this->lblMajor->TabIndex = 3;
            this->lblMajor->Text = L"Major:";
            // 
            // cbMajor
            // 
            this->cbMajor->FormattingEnabled = true;
            this->cbMajor->Location = System::Drawing::Point(150, 150);
            this->cbMajor->Name = L"cbMajor";
            this->cbMajor->Size = System::Drawing::Size(400, 28);
            this->cbMajor->TabIndex = 4;
            // 
            // lblStudentID
            // 
            this->lblStudentID->AutoSize = true;
            this->lblStudentID->Location = System::Drawing::Point(50, 200);
            this->lblStudentID->Name = L"lblStudentID";
            this->lblStudentID->Size = System::Drawing::Size(87, 20);
            this->lblStudentID->TabIndex = 5;
            this->lblStudentID->Text = L"Student ID:";
            // 
            // txtStudentID
            // 
            this->txtStudentID->Location = System::Drawing::Point(150, 200);
            this->txtStudentID->Name = L"txtStudentID";
            this->txtStudentID->Size = System::Drawing::Size(400, 26);
            this->txtStudentID->TabIndex = 6;
            // 
            // lblGrade
            // 
            this->lblGrade->AutoSize = true;
            this->lblGrade->Location = System::Drawing::Point(50, 250);
            this->lblGrade->Name = L"lblGrade";
            this->lblGrade->Size = System::Drawing::Size(54, 20);
            this->lblGrade->TabIndex = 7;
            this->lblGrade->Text = L"Grade:";
            // 
            // txtGrade
            // 
            this->txtGrade->Location = System::Drawing::Point(150, 250);
            this->txtGrade->Name = L"txtGrade";
            this->txtGrade->Size = System::Drawing::Size(100, 26);
            this->txtGrade->TabIndex = 8;
            // 
            // btnUpdateGrade
            // 
            this->btnUpdateGrade->Location = System::Drawing::Point(250, 300);
            this->btnUpdateGrade->Name = L"btnUpdateGrade";
            this->btnUpdateGrade->Size = System::Drawing::Size(150, 40);
            this->btnUpdateGrade->TabIndex = 9;
            this->btnUpdateGrade->Text = L"Update Grade";
            this->btnUpdateGrade->UseVisualStyleBackColor = true;
            this->btnUpdateGrade->Click += gcnew System::EventHandler(this, &GRADES::UpdateGrade_Click);
            // 
            // GRADES
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(650, 400);
            this->Controls->Add(this->btnUpdateGrade);
            this->Controls->Add(this->txtGrade);
            this->Controls->Add(this->lblGrade);
            this->Controls->Add(this->txtStudentID);
            this->Controls->Add(this->lblStudentID);
            this->Controls->Add(this->cbMajor);
            this->Controls->Add(this->lblMajor);
            this->Controls->Add(this->cbCourse);
            this->Controls->Add(this->lblCourse);
            this->Controls->Add(this->lblTitle);
            this->Name = L"GRADES";
            this->Text = L"Update Grades";
            this->Load += gcnew System::EventHandler(this, &GRADES::GRADES_Load);
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

    private:
        void GRADES_Load(System::Object^ sender, System::EventArgs^ e) {
            LoadCoursesAndMajors();
        }

        void LoadCoursesAndMajors() {
            String^ connectionString = "Server=localhost;Database=studentenroll;Uid=root;Pwd='';";
            try {
                MySqlConnection^ conn = gcnew MySqlConnection(connectionString);
                conn->Open();

                // Load Courses
                String^ queryCourses = "SELECT courseName FROM Courses";
                MySqlCommand^ cmdCourses = gcnew MySqlCommand(queryCourses, conn);
                MySqlDataReader^ readerCourses = cmdCourses->ExecuteReader();
                while (readerCourses->Read()) {
                    cbCourse->Items->Add(readerCourses["courseName"]->ToString());
                }
                readerCourses->Close();

                // Load Majors
                String^ queryMajors = "SELECT DISTINCT major FROM majors";
                MySqlCommand^ cmdMajors = gcnew MySqlCommand(queryMajors, conn);
                MySqlDataReader^ readerMajors = cmdMajors->ExecuteReader();
                while (readerMajors->Read()) {
                    cbMajor->Items->Add(readerMajors["major"]->ToString());
                }
                readerMajors->Close();

                conn->Close();
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error loading data: " + ex->Message);
            }
        }

        void UpdateGrade_Click(System::Object^ sender, System::EventArgs^ e) {
            String^ connectionString = "Server=localhost;Database=studentenroll;Uid=root;Pwd='';";
            try {
                MySqlConnection^ conn = gcnew MySqlConnection(connectionString);
                conn->Open();

                String^ studentID = txtStudentID->Text;
                String^ course = cbCourse->Text;
                String^ grade = txtGrade->Text;

                String^ query = "UPDATE Enrollments " +
                    "SET grade = @grade " +
                    "WHERE studentID = @studentID AND courseID = " +
                    "(SELECT courseID FROM Courses WHERE courseName = @course)";
                MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
                cmd->Parameters->AddWithValue("@grade", grade);
                cmd->Parameters->AddWithValue("@studentID", studentID);
                cmd->Parameters->AddWithValue("@course", course);

                int rowsAffected = cmd->ExecuteNonQuery();
                if (rowsAffected > 0) {
                    MessageBox::Show("Grade updated successfully.");
                }
                else {
                    MessageBox::Show("No records were updated. Check the inputs.");
                }

                conn->Close();
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error updating grade: " + ex->Message);
            }
        }
    };
}
