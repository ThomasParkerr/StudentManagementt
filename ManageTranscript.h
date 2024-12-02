using namespace MySql::Data::MySqlClient;

#pragma once

namespace StudentManagement {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class ManageTranscript : public System::Windows::Forms::Form
    {
    public:
        ManageTranscript(void)
        {
            InitializeComponent();
        }

    protected:
        ~ManageTranscript()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Label^ labelStudentID;
        System::Windows::Forms::Label^ labelName;
        System::Windows::Forms::Label^ labelDateOfAdmission;
        System::Windows::Forms::Label^ labelFaculty;
        System::Windows::Forms::Label^ labelSemester;
        System::Windows::Forms::Label^ labelCourseGrade;

        System::Windows::Forms::TextBox^ textBoxStudentID;
        System::Windows::Forms::TextBox^ textBoxName;
        System::Windows::Forms::TextBox^ textBoxDateOfAdmission;
        System::Windows::Forms::TextBox^ textBoxFaculty;
        System::Windows::Forms::RichTextBox^ richTextBoxSemester;
        System::Windows::Forms::RichTextBox^ richTextBoxCourseGrade;

        System::Windows::Forms::Button^ buttonFetch;
        System::Windows::Forms::Button^ buttonPrint;

        System::Drawing::Printing::PrintDocument^ printDocument1;

        System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            this->labelStudentID = (gcnew System::Windows::Forms::Label());
            this->labelName = (gcnew System::Windows::Forms::Label());
            this->labelDateOfAdmission = (gcnew System::Windows::Forms::Label());
            this->labelFaculty = (gcnew System::Windows::Forms::Label());
            this->labelSemester = (gcnew System::Windows::Forms::Label());
            this->labelCourseGrade = (gcnew System::Windows::Forms::Label());

            this->textBoxStudentID = (gcnew System::Windows::Forms::TextBox());
            this->textBoxName = (gcnew System::Windows::Forms::TextBox());
            this->textBoxDateOfAdmission = (gcnew System::Windows::Forms::TextBox());
            this->textBoxFaculty = (gcnew System::Windows::Forms::TextBox());
            this->richTextBoxSemester = (gcnew System::Windows::Forms::RichTextBox());
            this->richTextBoxCourseGrade = (gcnew System::Windows::Forms::RichTextBox());

            this->buttonFetch = (gcnew System::Windows::Forms::Button());
            this->buttonPrint = (gcnew System::Windows::Forms::Button());
            this->printDocument1 = (gcnew System::Drawing::Printing::PrintDocument());

            this->SuspendLayout();

            // Label StudentID
            this->labelStudentID->AutoSize = true;
            this->labelStudentID->Location = System::Drawing::Point(20, 20);
            this->labelStudentID->Name = L"labelStudentID";
            this->labelStudentID->Size = System::Drawing::Size(68, 13);
            this->labelStudentID->Text = L"Student ID:";

            // TextBox StudentID
            this->textBoxStudentID->Location = System::Drawing::Point(120, 20);
            this->textBoxStudentID->Name = L"textBoxStudentID";
            this->textBoxStudentID->Size = System::Drawing::Size(150, 20);

            // Label Name
            this->labelName->AutoSize = true;
            this->labelName->Location = System::Drawing::Point(20, 60);
            this->labelName->Name = L"labelName";
            this->labelName->Size = System::Drawing::Size(38, 13);
            this->labelName->Text = L"Name:";

            // TextBox Name
            this->textBoxName->Location = System::Drawing::Point(120, 60);
            this->textBoxName->Name = L"textBoxName";
            this->textBoxName->Size = System::Drawing::Size(150, 20);

            // Label Date of Admission
            this->labelDateOfAdmission->AutoSize = true;
            this->labelDateOfAdmission->Location = System::Drawing::Point(20, 100);
            this->labelDateOfAdmission->Name = L"labelDateOfAdmission";
            this->labelDateOfAdmission->Size = System::Drawing::Size(95, 13);
            this->labelDateOfAdmission->Text = L"Date of Admission:";

            // TextBox Date of Admission
            this->textBoxDateOfAdmission->Location = System::Drawing::Point(120, 100);
            this->textBoxDateOfAdmission->Name = L"textBoxDateOfAdmission";
            this->textBoxDateOfAdmission->Size = System::Drawing::Size(150, 20);

            // Label Faculty
            this->labelFaculty->AutoSize = true;
            this->labelFaculty->Location = System::Drawing::Point(20, 140);
            this->labelFaculty->Name = L"labelFaculty";
            this->labelFaculty->Size = System::Drawing::Size(45, 13);
            this->labelFaculty->Text = L"Faculty:";

            // TextBox Faculty
            this->textBoxFaculty->Location = System::Drawing::Point(120, 140);
            this->textBoxFaculty->Name = L"textBoxFaculty";
            this->textBoxFaculty->Size = System::Drawing::Size(150, 20);

            // Label Semester
            this->labelSemester->AutoSize = true;
            this->labelSemester->Location = System::Drawing::Point(20, 180);
            this->labelSemester->Name = L"labelSemester";
            this->labelSemester->Size = System::Drawing::Size(54, 13);
            this->labelSemester->Text = L"Semesters:";

            // RichTextBox Semester
            this->richTextBoxSemester->Location = System::Drawing::Point(120, 180);
            this->richTextBoxSemester->Name = L"richTextBoxSemester";
            this->richTextBoxSemester->Size = System::Drawing::Size(200, 100);

            // Label Course Grade
            this->labelCourseGrade->AutoSize = true;
            this->labelCourseGrade->Location = System::Drawing::Point(20, 300);
            this->labelCourseGrade->Name = L"labelCourseGrade";
            this->labelCourseGrade->Size = System::Drawing::Size(75, 13);
            this->labelCourseGrade->Text = L"Course Grades:";

            // RichTextBox Course Grade
            this->richTextBoxCourseGrade->Location = System::Drawing::Point(120, 300);
            this->richTextBoxCourseGrade->Name = L"richTextBoxCourseGrade";
            this->richTextBoxCourseGrade->Size = System::Drawing::Size(200, 100);

            // Button Fetch
            this->buttonFetch->Location = System::Drawing::Point(20, 420);
            this->buttonFetch->Name = L"buttonFetch";
            this->buttonFetch->Size = System::Drawing::Size(75, 23);
            this->buttonFetch->Text = L"Fetch";
            this->buttonFetch->UseVisualStyleBackColor = true;
            this->buttonFetch->Click += gcnew System::EventHandler(this, &ManageTranscript::ButtonFetch_Click);

            // Button Print
            this->buttonPrint->Location = System::Drawing::Point(120, 420);
            this->buttonPrint->Name = L"buttonPrint";
            this->buttonPrint->Size = System::Drawing::Size(75, 23);
            this->buttonPrint->Text = L"Print";
            this->buttonPrint->UseVisualStyleBackColor = true;
            this->buttonPrint->Click += gcnew System::EventHandler(this, &ManageTranscript::buttonPrint_Click);

            // ManageTranscript Form
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(400, 480);
            this->Controls->Add(this->labelStudentID);
            this->Controls->Add(this->textBoxStudentID);
            this->Controls->Add(this->labelName);
            this->Controls->Add(this->textBoxName);
            this->Controls->Add(this->labelDateOfAdmission);
            this->Controls->Add(this->textBoxDateOfAdmission);
            this->Controls->Add(this->labelFaculty);
            this->Controls->Add(this->textBoxFaculty);
            this->Controls->Add(this->labelSemester);
            this->Controls->Add(this->richTextBoxSemester);
            this->Controls->Add(this->labelCourseGrade);
            this->Controls->Add(this->richTextBoxCourseGrade);
            this->Controls->Add(this->buttonFetch);
            this->Controls->Add(this->buttonPrint);
            this->Name = L"ManageTranscript";
            this->Text = L"Manage Transcript";
            this->ResumeLayout(false);
            this->PerformLayout();
        }

        void ButtonFetch_Click(System::Object^ sender, System::EventArgs^ e)
        {
            String^ studentID = this->textBoxStudentID->Text;

            String^ connStr = L"server=localhost;user id=root;password=\"\";database=studentenroll;";
            MySqlConnection^ conn = gcnew MySqlConnection(connStr);
            try
            {
                conn->Open();
                String^ query = L"SELECT u.firstName, u.lastName, s.enrollmentDate, f.department, e.semester, c.courseName, e.grade "
                    L"FROM students s "
                    L"INNER JOIN users u ON s.userID = u.userID "
                    L"INNER JOIN enrollments e ON s.studentID = e.studentID "
                    L"INNER JOIN courses c ON e.courseID = c.courseID "
                    L"INNER JOIN faculty f ON c.facultyID = f.facultyID "
                    L"WHERE s.studentID = @studentID;";

                MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
                cmd->Parameters->AddWithValue("@studentID", studentID);

                MySqlDataReader^ reader = cmd->ExecuteReader();

                this->textBoxName->Clear();
                this->textBoxDateOfAdmission->Clear();
                this->textBoxFaculty->Clear();
                this->richTextBoxSemester->Clear();
                this->richTextBoxCourseGrade->Clear();

                while (reader->Read())
                {
                    this->textBoxName->Text = reader["firstName"]->ToString() + " " + reader["lastName"]->ToString();
                    this->textBoxDateOfAdmission->Text = reader["enrollmentDate"]->ToString();
                    this->textBoxFaculty->Text = reader["department"]->ToString();
                    this->richTextBoxSemester->AppendText(reader["semester"]->ToString() + Environment::NewLine);
                    this->richTextBoxCourseGrade->AppendText(reader["courseName"]->ToString() + " - " + reader["grade"]->ToString() + Environment::NewLine);
                }
                reader->Close();
                conn->Close();
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error: " + ex->Message);
            }
        }

        void buttonPrint_Click(System::Object^ sender, System::EventArgs^ e)
        {
            PrintDialog^ printDialog1 = gcnew PrintDialog();
            printDialog1->Document = this->printDocument1;

            if (printDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
            {
                this->printDocument1->Print();
            }
        }

        System::Drawing::Font^ font = gcnew System::Drawing::Font("Arial", 12);

        void PrintDocument1_PrintPage(Object^ sender, System::Drawing::Printing::PrintPageEventArgs^ e)
        {
            e->Graphics->DrawString("Transcript for " + textBoxName->Text, font, Brushes::Black, 10, 10);
            e->Graphics->DrawString("Student ID: " + textBoxStudentID->Text, font, Brushes::Black, 10, 30);
            e->Graphics->DrawString("Date of Admission: " + textBoxDateOfAdmission->Text, font, Brushes::Black, 10, 50);
            e->Graphics->DrawString("Faculty: " + textBoxFaculty->Text, font, Brushes::Black, 10, 70);
            e->Graphics->DrawString("Semester: " + richTextBoxSemester->Text,font, Brushes::Black, 10, 90);
            e->Graphics->DrawString("Course Grades: " + richTextBoxCourseGrade->Text, font, Brushes::Black, 10, 110);
        }
    };
}
