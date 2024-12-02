using namespace MySql::Data::MySqlClient;

#pragma once

namespace StudentManagement {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class AddTranscript : public System::Windows::Forms::Form
    {
    public:
        AddTranscript(void)
        {
            InitializeComponent();
        }

    protected:
        ~AddTranscript()
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

            // 
            // labelStudentID
            // 
            this->labelStudentID->AutoSize = true;
            this->labelStudentID->Location = System::Drawing::Point(20, 20);
            this->labelStudentID->Name = L"labelStudentID";
            this->labelStudentID->Size = System::Drawing::Size(70, 13);
            this->labelStudentID->TabIndex = 0;
            this->labelStudentID->Text = L"Student ID:";

            // 
            // textBoxStudentID
            // 
            this->textBoxStudentID->Location = System::Drawing::Point(120, 20);
            this->textBoxStudentID->Name = L"textBoxStudentID";
            this->textBoxStudentID->Size = System::Drawing::Size(200, 20);
            this->textBoxStudentID->TabIndex = 1;

            // 
            // labelName
            // 
            this->labelName->AutoSize = true;
            this->labelName->Location = System::Drawing::Point(20, 60);
            this->labelName->Name = L"labelName";
            this->labelName->Size = System::Drawing::Size(38, 13);
            this->labelName->TabIndex = 2;
            this->labelName->Text = L"Name:";

            // 
            // textBoxName
            // 
            this->textBoxName->Location = System::Drawing::Point(120, 60);
            this->textBoxName->Name = L"textBoxName";
            this->textBoxName->Size = System::Drawing::Size(200, 20);
            this->textBoxName->TabIndex = 3;

            // 
            // labelDateOfAdmission
            // 
            this->labelDateOfAdmission->AutoSize = true;
            this->labelDateOfAdmission->Location = System::Drawing::Point(20, 100);
            this->labelDateOfAdmission->Name = L"labelDateOfAdmission";
            this->labelDateOfAdmission->Size = System::Drawing::Size(101, 13);
            this->labelDateOfAdmission->TabIndex = 4;
            this->labelDateOfAdmission->Text = L"Date of Admission:";

            // 
            // textBoxDateOfAdmission
            // 
            this->textBoxDateOfAdmission->Location = System::Drawing::Point(120, 100);
            this->textBoxDateOfAdmission->Name = L"textBoxDateOfAdmission";
            this->textBoxDateOfAdmission->Size = System::Drawing::Size(200, 20);
            this->textBoxDateOfAdmission->TabIndex = 5;

            // 
            // labelFaculty
            // 
            this->labelFaculty->AutoSize = true;
            this->labelFaculty->Location = System::Drawing::Point(20, 140);
            this->labelFaculty->Name = L"labelFaculty";
            this->labelFaculty->Size = System::Drawing::Size(46, 13);
            this->labelFaculty->TabIndex = 6;
            this->labelFaculty->Text = L"Faculty:";

            // 
            // textBoxFaculty
            // 
            this->textBoxFaculty->Location = System::Drawing::Point(120, 140);
            this->textBoxFaculty->Name = L"textBoxFaculty";
            this->textBoxFaculty->Size = System::Drawing::Size(200, 20);
            this->textBoxFaculty->TabIndex = 7;

            // 
            // labelSemester
            // 
            this->labelSemester->AutoSize = true;
            this->labelSemester->Location = System::Drawing::Point(20, 180);
            this->labelSemester->Name = L"labelSemester";
            this->labelSemester->Size = System::Drawing::Size(58, 13);
            this->labelSemester->TabIndex = 8;
            this->labelSemester->Text = L"Semester:";

            // 
            // richTextBoxSemester
            // 
            this->richTextBoxSemester->Location = System::Drawing::Point(120, 180);
            this->richTextBoxSemester->Name = L"richTextBoxSemester";
            this->richTextBoxSemester->Size = System::Drawing::Size(200, 60);
            this->richTextBoxSemester->TabIndex = 9;
            this->richTextBoxSemester->Text = L"";

            // 
            // labelCourseGrade
            // 
            this->labelCourseGrade->AutoSize = true;
            this->labelCourseGrade->Location = System::Drawing::Point(20, 260);
            this->labelCourseGrade->Name = L"labelCourseGrade";
            this->labelCourseGrade->Size = System::Drawing::Size(77, 13);
            this->labelCourseGrade->TabIndex = 10;
            this->labelCourseGrade->Text = L"Course Grades:";

            // 
            // richTextBoxCourseGrade
            // 
            this->richTextBoxCourseGrade->Location = System::Drawing::Point(120, 260);
            this->richTextBoxCourseGrade->Name = L"richTextBoxCourseGrade";
            this->richTextBoxCourseGrade->Size = System::Drawing::Size(200, 60);
            this->richTextBoxCourseGrade->TabIndex = 11;
            this->richTextBoxCourseGrade->Text = L"";

            // 
            // buttonFetch
            // 
            this->buttonFetch->Location = System::Drawing::Point(120, 330);
            this->buttonFetch->Name = L"buttonFetch";
            this->buttonFetch->Size = System::Drawing::Size(75, 23);
            this->buttonFetch->TabIndex = 12;
            this->buttonFetch->Text = L"Fetch";
            this->buttonFetch->Click += gcnew System::EventHandler(this, &AddTranscript::ButtonFetch_Click);

            // 
            // buttonPrint
            // 
            this->buttonPrint->Location = System::Drawing::Point(240, 330);
            this->buttonPrint->Name = L"buttonPrint";
            this->buttonPrint->Size = System::Drawing::Size(75, 23);
            this->buttonPrint->TabIndex = 13;
            this->buttonPrint->Text = L"Print";
            this->buttonPrint->Click += gcnew System::EventHandler(this, &AddTranscript::buttonPrint_Click);

            // 
            // printDocument1
            // 
            this->printDocument1->PrintPage += gcnew System::Drawing::Printing::PrintPageEventHandler(this, &AddTranscript::PrintDocument1_PrintPage);

            // 
            // AddTranscript
            // 
            this->ClientSize = System::Drawing::Size(400, 380);
            this->Controls->Add(this->buttonPrint);
            this->Controls->Add(this->buttonFetch);
            this->Controls->Add(this->richTextBoxCourseGrade);
            this->Controls->Add(this->labelCourseGrade);
            this->Controls->Add(this->richTextBoxSemester);
            this->Controls->Add(this->labelSemester);
            this->Controls->Add(this->textBoxFaculty);
            this->Controls->Add(this->labelFaculty);
            this->Controls->Add(this->textBoxDateOfAdmission);
            this->Controls->Add(this->labelDateOfAdmission);
            this->Controls->Add(this->textBoxName);
            this->Controls->Add(this->labelName);
            this->Controls->Add(this->textBoxStudentID);
            this->Controls->Add(this->labelStudentID);
            this->Name = L"AddTranscript";
            this->Text = L"Add Transcript";
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
