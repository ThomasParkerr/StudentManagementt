#pragma once
using namespace MySql::Data::MySqlClient;

namespace StudentManagement {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class GetUserDetails : public System::Windows::Forms::Form
    {
    public:
        GetUserDetails(void)
        {
            InitializeComponent();
        }

    protected:
        ~GetUserDetails()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Label^ labelStudentID;
        System::Windows::Forms::TextBox^ textBoxStudentID;
        System::Windows::Forms::Button^ buttonFetchDetails;
        System::Windows::Forms::Label^ labelFirstName;
        System::Windows::Forms::Label^ labelLastName;
        System::Windows::Forms::Label^ labelSemester;
        System::Windows::Forms::TextBox^ textBoxFirstName;
        System::Windows::Forms::TextBox^ textBoxLastName;
        System::Windows::Forms::TextBox^ textBoxSemester;
        System::Windows::Forms::DataGridView^ dataGridCourses;

        System::ComponentModel::Container^ components;
        MySqlConnection^ sqlConn;
    private: System::Windows::Forms::PictureBox^ pictureBox1;
           String^ connectionString = "Server=localhost;Database=studentenroll;Uid=root;Pwd='';";

    private:
        void InitializeComponent(void)
        {
            this->labelStudentID = (gcnew System::Windows::Forms::Label());
            this->textBoxStudentID = (gcnew System::Windows::Forms::TextBox());
            this->buttonFetchDetails = (gcnew System::Windows::Forms::Button());
            this->labelFirstName = (gcnew System::Windows::Forms::Label());
            this->labelLastName = (gcnew System::Windows::Forms::Label());
            this->labelSemester = (gcnew System::Windows::Forms::Label());
            this->textBoxFirstName = (gcnew System::Windows::Forms::TextBox());
            this->textBoxLastName = (gcnew System::Windows::Forms::TextBox());
            this->textBoxSemester = (gcnew System::Windows::Forms::TextBox());
            this->dataGridCourses = (gcnew System::Windows::Forms::DataGridView());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridCourses))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->SuspendLayout();
            // 
            // labelStudentID
            // 
            this->labelStudentID->Location = System::Drawing::Point(50, 30);
            this->labelStudentID->Name = L"labelStudentID";
            this->labelStudentID->Size = System::Drawing::Size(100, 25);
            this->labelStudentID->TabIndex = 0;
            this->labelStudentID->Text = L"STUDENT ID";
            // 
            // textBoxStudentID
            // 
            this->textBoxStudentID->Location = System::Drawing::Point(200, 30);
            this->textBoxStudentID->Name = L"textBoxStudentID";
            this->textBoxStudentID->Size = System::Drawing::Size(150, 26);
            this->textBoxStudentID->TabIndex = 1;
            // 
            // buttonFetchDetails
            // 
            this->buttonFetchDetails->Location = System::Drawing::Point(400, 30);
            this->buttonFetchDetails->Name = L"buttonFetchDetails";
            this->buttonFetchDetails->Size = System::Drawing::Size(75, 26);
            this->buttonFetchDetails->TabIndex = 2;
            this->buttonFetchDetails->Text = L"Fetch Details";
            this->buttonFetchDetails->Click += gcnew System::EventHandler(this, &GetUserDetails::buttonFetchDetails_Click);
            // 
            // labelFirstName
            // 
            this->labelFirstName->Location = System::Drawing::Point(50, 80);
            this->labelFirstName->Name = L"labelFirstName";
            this->labelFirstName->Size = System::Drawing::Size(100, 23);
            this->labelFirstName->TabIndex = 3;
            this->labelFirstName->Text = L"First Name:";
            // 
            // labelLastName
            // 
            this->labelLastName->Location = System::Drawing::Point(50, 120);
            this->labelLastName->Name = L"labelLastName";
            this->labelLastName->Size = System::Drawing::Size(100, 23);
            this->labelLastName->TabIndex = 4;
            this->labelLastName->Text = L"Last Name:";
            // 
            // labelSemester
            // 
            this->labelSemester->Location = System::Drawing::Point(50, 160);
            this->labelSemester->Name = L"labelSemester";
            this->labelSemester->Size = System::Drawing::Size(100, 23);
            this->labelSemester->TabIndex = 5;
            this->labelSemester->Text = L"Semester:";
            // 
            // textBoxFirstName
            // 
            this->textBoxFirstName->Location = System::Drawing::Point(200, 80);
            this->textBoxFirstName->Name = L"textBoxFirstName";
            this->textBoxFirstName->ReadOnly = true;
            this->textBoxFirstName->Size = System::Drawing::Size(100, 26);
            this->textBoxFirstName->TabIndex = 6;
            // 
            // textBoxLastName
            // 
            this->textBoxLastName->Location = System::Drawing::Point(200, 120);
            this->textBoxLastName->Name = L"textBoxLastName";
            this->textBoxLastName->ReadOnly = true;
            this->textBoxLastName->Size = System::Drawing::Size(100, 26);
            this->textBoxLastName->TabIndex = 7;
            // 
            // textBoxSemester
            // 
            this->textBoxSemester->Location = System::Drawing::Point(200, 160);
            this->textBoxSemester->Name = L"textBoxSemester";
            this->textBoxSemester->ReadOnly = true;
            this->textBoxSemester->Size = System::Drawing::Size(100, 26);
            this->textBoxSemester->TabIndex = 8;
            // 
            // dataGridCourses
            // 
            this->dataGridCourses->ColumnHeadersHeight = 34;
            this->dataGridCourses->Location = System::Drawing::Point(50, 220);
            this->dataGridCourses->Name = L"dataGridCourses";
            this->dataGridCourses->RowHeadersWidth = 62;
            this->dataGridCourses->Size = System::Drawing::Size(600, 200);
            this->dataGridCourses->TabIndex = 9;
            // 
            // pictureBox1
            // 
            this->pictureBox1->Location = System::Drawing::Point(518, 30);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(132, 113);
            this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox1->TabIndex = 10;
            this->pictureBox1->TabStop = false;
            this->pictureBox1->Click += gcnew System::EventHandler(this, &GetUserDetails::pictureBox1_Click);
            // 
            // GetUserDetails
            // 
            this->ClientSize = System::Drawing::Size(712, 751);
            this->Controls->Add(this->pictureBox1);
            this->Controls->Add(this->labelStudentID);
            this->Controls->Add(this->textBoxStudentID);
            this->Controls->Add(this->buttonFetchDetails);
            this->Controls->Add(this->labelFirstName);
            this->Controls->Add(this->labelLastName);
            this->Controls->Add(this->labelSemester);
            this->Controls->Add(this->textBoxFirstName);
            this->Controls->Add(this->textBoxLastName);
            this->Controls->Add(this->textBoxSemester);
            this->Controls->Add(this->dataGridCourses);
            this->Name = L"GetUserDetails";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridCourses))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();
            this->pictureBox1->Image = Image::FromFile("user.jpg");

        }

        

        void buttonFetchDetails_Click(System::Object^ sender, System::EventArgs^ e)
        {
            String^ studentID = this->textBoxStudentID->Text;
            if (String::IsNullOrEmpty(studentID))
            {
                MessageBox::Show("Please enter a valid Student ID.");
                return;
            }

            try
            {
                sqlConn = gcnew MySqlConnection(connectionString);
                sqlConn->Open();

                // Query for Student Information
                String^ queryStudent = R"(
            SELECT u.firstName, u.lastName, e.semester 
            FROM students s
            INNER JOIN users u ON s.userID = u.userID
            INNER JOIN enrollments e ON e.studentID = s.studentID
            WHERE s.studentID = @StudentID
            LIMIT 1;
        )";

                MySqlCommand^ cmdStudent = gcnew MySqlCommand(queryStudent, sqlConn);
                cmdStudent->Parameters->AddWithValue("@StudentID", studentID);

                MySqlDataReader^ readerStudent = cmdStudent->ExecuteReader();
                if (readerStudent->Read())
                {
                    this->textBoxFirstName->Text = readerStudent["firstName"]->ToString();
                    this->textBoxLastName->Text = readerStudent["lastName"]->ToString();
                    this->textBoxSemester->Text = readerStudent["semester"]->ToString();
                }
                else
                {
                    MessageBox::Show("No student found with the given ID.");
                    readerStudent->Close();
                    sqlConn->Close();
                    return;
                }
                readerStudent->Close();

                // Query for Courses and Grades
                String^ queryCourses = R"(
            SELECT c.courseName, e.grade 
            FROM enrollments e
            INNER JOIN courses c ON e.courseID = c.courseID
            WHERE e.studentID = @StudentID;
        )";

                MySqlCommand^ cmdCourses = gcnew MySqlCommand(queryCourses, sqlConn);
                cmdCourses->Parameters->AddWithValue("@StudentID", studentID);

                MySqlDataAdapter^ dataAdapter = gcnew MySqlDataAdapter(cmdCourses);
                DataTable^ dataTable = gcnew DataTable();
                dataAdapter->Fill(dataTable);
                this->dataGridCourses->DataSource = dataTable;

                sqlConn->Close();
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("An error occurred: " + ex->Message);
            }
            
        }
    private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
    }
};
}
