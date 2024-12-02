#pragma once

namespace StudentManagement {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient;

    public ref class GenerateReports : public System::Windows::Forms::Form
    {
    public:
        GenerateReports(void)
        {
            InitializeComponent();
        }

    protected:
        ~GenerateReports()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::TextBox^ userIDTextBox;
        System::Windows::Forms::Button^ generateStudentReportButton;
        System::Windows::Forms::Button^ generateFacultyReportButton;
        System::Windows::Forms::DataGridView^ dataGridView;
        System::Windows::Forms::Label^ label1;
        System::ComponentModel::Container^ components;

    private:
        void InitializeComponent(void)
        {
            this->userIDTextBox = (gcnew System::Windows::Forms::TextBox());
            this->generateStudentReportButton = (gcnew System::Windows::Forms::Button());
            this->generateFacultyReportButton = (gcnew System::Windows::Forms::Button());
            this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
            this->label1 = (gcnew System::Windows::Forms::Label());

            this->SuspendLayout();

            // 
            // userIDTextBox
            // 
            this->userIDTextBox->Location = System::Drawing::Point(142, 20);
            this->userIDTextBox->Name = L"userIDTextBox";
            this->userIDTextBox->Size = System::Drawing::Size(200, 26);
            this->userIDTextBox->TabIndex = 0;

            // 
            // generateStudentReportButton
            // 
            this->generateStudentReportButton->Location = System::Drawing::Point(50, 60);
            this->generateStudentReportButton->Name = L"generateStudentReportButton";
            this->generateStudentReportButton->Size = System::Drawing::Size(200, 30);
            this->generateStudentReportButton->Text = L"Generate Student Report";
            this->generateStudentReportButton->Click += gcnew System::EventHandler(this, &GenerateReports::generateStudentReportButton_Click);

            // 
            // generateFacultyReportButton
            // 
            this->generateFacultyReportButton->Location = System::Drawing::Point(300, 60);
            this->generateFacultyReportButton->Name = L"generateFacultyReportButton";
            this->generateFacultyReportButton->Size = System::Drawing::Size(200, 30);
            this->generateFacultyReportButton->Text = L"Generate Faculty Report";
            this->generateFacultyReportButton->Click += gcnew System::EventHandler(this, &GenerateReports::generateFacultyReportButton_Click);

            // 
            // dataGridView
            // 
            this->dataGridView->Location = System::Drawing::Point(50, 100);
            this->dataGridView->Name = L"dataGridView";
            this->dataGridView->Size = System::Drawing::Size(600, 300);
            this->dataGridView->TabIndex = 3;

            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(50, 25);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(76, 20);
            this->label1->TabIndex = 4;
            this->label1->Text = L"USER ID";

            // 
            // GenerateReports
            // 
            this->ClientSize = System::Drawing::Size(704, 450);
            this->Controls->Add(this->dataGridView);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->userIDTextBox);
            this->Controls->Add(this->generateStudentReportButton);
            this->Controls->Add(this->generateFacultyReportButton);
            this->Name = L"GenerateReports";
            this->Text = L"Generate Reports";
            this->ResumeLayout(false);
            this->PerformLayout();
        }

        void generateStudentReportButton_Click(System::Object^ sender, System::EventArgs^ e)
        {
            String^ userID = userIDTextBox->Text;
            String^ query = "SELECT u.firstName AS 'First Name', u.lastName AS 'Last Name', u.email AS 'Email', m.major AS 'Major', s.dob AS 'Date of Birth', s.enrollmentDate AS 'Enrollment Date' "
                "FROM users u "
                "JOIN students s ON u.userID = s.userID "
                "JOIN majors m ON s.majorID = m.majorID "
                "WHERE u.userID = @userID";

            populateDataGrid(query, userID);
        }

        void generateFacultyReportButton_Click(System::Object^ sender, System::EventArgs^ e)
        {
            String^ userID = userIDTextBox->Text;
            String^ query = "SELECT u.firstName AS 'First Name', u.lastName AS 'Last Name', u.email AS 'Email', f.department AS 'Department', f.date_of_appointment AS 'Date of Appointment', "
                "f.phone AS 'Phone', f.address AS 'Address', f.date_of_birth AS 'Date of Birth' "
                "FROM users u "
                "JOIN faculty f ON u.userID = f.userID "
                "WHERE u.userID = @userID";

            populateDataGrid(query, userID);
        }

        void populateDataGrid(String^ query, String^ userID)
        {
            MySqlConnection^ conn = gcnew MySqlConnection("Server=localhost;Database=studentenroll;Uid=root;Pwd='';");
            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@userID", userID);
            MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter(cmd);
            DataTable^ table = gcnew DataTable();

            try
            {
                conn->Open();
                adapter->Fill(table);
                dataGridView->DataSource = table;
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
            finally
            {
                conn->Close();
            }
        }
    };
}
