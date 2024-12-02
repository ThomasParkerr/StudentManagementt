#pragma once

using namespace System;
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient;

namespace StudentManagement {

    public ref class AssignFaculty : public System::Windows::Forms::Form
    {
    public:
        AssignFaculty(void)
        {
            InitializeComponent();
        }

    protected:
        ~AssignFaculty()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Label^ lblTitle;
        System::Windows::Forms::Label^ lblCourseID;
        System::Windows::Forms::Label^ lblFaculty;
        System::Windows::Forms::ComboBox^ cbCourseID;
        System::Windows::Forms::ComboBox^ cbFaculty;
        System::Windows::Forms::Button^ btnAssign;
        System::ComponentModel::Container^ components;

        String^ connectionString = "Server=localhost;Database=studentenroll;Uid=root;Pwd='';";

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->lblTitle = (gcnew System::Windows::Forms::Label());
            this->lblCourseID = (gcnew System::Windows::Forms::Label());
            this->lblFaculty = (gcnew System::Windows::Forms::Label());
            this->cbCourseID = (gcnew System::Windows::Forms::ComboBox());
            this->cbFaculty = (gcnew System::Windows::Forms::ComboBox());
            this->btnAssign = (gcnew System::Windows::Forms::Button());

            this->SuspendLayout();

            // lblTitle
            this->lblTitle->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 16, System::Drawing::FontStyle::Bold));
            this->lblTitle->Location = System::Drawing::Point(200, 20);
            this->lblTitle->Name = L"lblTitle";
            this->lblTitle->Size = System::Drawing::Size(300, 40);
            this->lblTitle->TabIndex = 0;
            this->lblTitle->Text = L"Assign Faculty";
            this->lblTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

            // lblCourseID
            this->lblCourseID->AutoSize = true;
            this->lblCourseID->Location = System::Drawing::Point(50, 100);
            this->lblCourseID->Name = L"lblCourseID";
            this->lblCourseID->Size = System::Drawing::Size(83, 20);
            this->lblCourseID->TabIndex = 1;
            this->lblCourseID->Text = L"Course ID:";

            // cbCourseID
            this->cbCourseID->FormattingEnabled = true;
            this->cbCourseID->Location = System::Drawing::Point(150, 100);
            this->cbCourseID->Name = L"cbCourseID";
            this->cbCourseID->Size = System::Drawing::Size(200, 28);
            this->cbCourseID->TabIndex = 2;

            // lblFaculty
            this->lblFaculty->AutoSize = true;
            this->lblFaculty->Location = System::Drawing::Point(50, 150);
            this->lblFaculty->Name = L"lblFaculty";
            this->lblFaculty->Size = System::Drawing::Size(65, 20);
            this->lblFaculty->TabIndex = 3;
            this->lblFaculty->Text = L"Faculty:";

            // cbFaculty
            this->cbFaculty->FormattingEnabled = true;
            this->cbFaculty->Location = System::Drawing::Point(150, 150);
            this->cbFaculty->Name = L"cbFaculty";
            this->cbFaculty->Size = System::Drawing::Size(200, 28);
            this->cbFaculty->TabIndex = 4;

            // btnAssign
            this->btnAssign->Location = System::Drawing::Point(150, 200);
            this->btnAssign->Name = L"btnAssign";
            this->btnAssign->Size = System::Drawing::Size(100, 40);
            this->btnAssign->TabIndex = 5;
            this->btnAssign->Text = L"Assign";
            this->btnAssign->UseVisualStyleBackColor = true;
            this->btnAssign->Click += gcnew System::EventHandler(this, &AssignFaculty::AssignFacultyToCourse);

            // AssignFaculty
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(400, 300);
            this->Controls->Add(this->btnAssign);
            this->Controls->Add(this->cbFaculty);
            this->Controls->Add(this->lblFaculty);
            this->Controls->Add(this->cbCourseID);
            this->Controls->Add(this->lblCourseID);
            this->Controls->Add(this->lblTitle);
            this->Name = L"AssignFaculty";
            this->Text = L"Assign Faculty";
            this->Load += gcnew System::EventHandler(this, &AssignFaculty::AssignFaculty_Load);
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

    private:
        void AssignFaculty_Load(System::Object^ sender, System::EventArgs^ e)
        {
            try {
                MySqlConnection^ conn = gcnew MySqlConnection(connectionString);
                conn->Open();

                // Load Courses
                MySqlCommand^ cmdCourses = gcnew MySqlCommand("SELECT courseID, courseName FROM courses", conn);
                MySqlDataReader^ readerCourses = cmdCourses->ExecuteReader();
                while (readerCourses->Read()) {
                    cbCourseID->Items->Add(readerCourses["courseID"]->ToString() + " - " + readerCourses["courseName"]->ToString());
                }
                readerCourses->Close();

                // Load Faculty
                MySqlCommand^ cmdFaculty = gcnew MySqlCommand("SELECT facultyID, CONCAT(firstName, ' ', lastName) AS fullName FROM faculty INNER JOIN users ON faculty.userID = users.userID", conn);
                MySqlDataReader^ readerFaculty = cmdFaculty->ExecuteReader();
                while (readerFaculty->Read()) {
                    cbFaculty->Items->Add(readerFaculty["facultyID"]->ToString() + " - " + readerFaculty["fullName"]->ToString());
                }
                readerFaculty->Close();

                conn->Close();
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error loading data: " + ex->Message);
            }
        }

        void AssignFacultyToCourse(System::Object^ sender, System::EventArgs^ e)
        {
            if (String::IsNullOrEmpty(cbCourseID->Text) || String::IsNullOrEmpty(cbFaculty->Text)) {
                MessageBox::Show("All fields are required.");
                return;
            }

            try {
                // Extract selected values
                array<String^>^ courseInfo = cbCourseID->Text->Split(' ');  // CourseID and CourseName are concatenated
                String^ courseId = courseInfo[0];

                array<String^>^ facultyInfo = cbFaculty->Text->Split(' ');  // FacultyID and FullName are concatenated
                String^ facultyId = facultyInfo[0];

                MySqlConnection^ conn = gcnew MySqlConnection(connectionString);
                conn->Open();

                // Update course with faculty
                MySqlCommand^ cmdAssign = gcnew MySqlCommand("UPDATE courses SET facultyID = @facultyId WHERE courseID = @courseId", conn);
                cmdAssign->Parameters->AddWithValue("@facultyId", facultyId);
                cmdAssign->Parameters->AddWithValue("@courseId", courseId);

                cmdAssign->ExecuteNonQuery();

                conn->Close();
                MessageBox::Show("Faculty assigned successfully.");
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error assigning faculty: " + ex->Message);
            }
        }
    };
}
