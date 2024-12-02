#pragma once

namespace StudentManagement {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient;

    public ref class ViewSchedule : public System::Windows::Forms::Form
    {
    public:
        ViewSchedule(void)
        {
            InitializeComponent();
            // Initialize the UI when the form loads
            PopulateSchedule();
        }

    protected:
        ~ViewSchedule()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::ComponentModel::Container^ components;
        System::Windows::Forms::Label^ labelStudentID;
        System::Windows::Forms::TextBox^ txtStudentID;
        System::Windows::Forms::Button^ btnViewSchedule;
        System::Windows::Forms::DataGridView^ dgvSchedule;

        String^ connectionString = "Server=localhost;Database=studentenroll;User ID=root;Password=\"\";";
        MySqlConnection^ conn;
        MySqlCommand^ cmd;
        MySqlDataReader^ reader;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->labelStudentID = (gcnew System::Windows::Forms::Label());
            this->txtStudentID = (gcnew System::Windows::Forms::TextBox());
            this->btnViewSchedule = (gcnew System::Windows::Forms::Button());
            this->dgvSchedule = (gcnew System::Windows::Forms::DataGridView());

            this->labelStudentID->Location = System::Drawing::Point(20, 20);
            this->labelStudentID->Name = L"labelStudentID";
            this->labelStudentID->Size = System::Drawing::Size(100, 20);
            this->labelStudentID->Text = L"Student ID:";

            this->txtStudentID->Location = System::Drawing::Point(130, 20);
            this->txtStudentID->Name = L"txtStudentID";
            this->txtStudentID->Size = System::Drawing::Size(150, 20);

            this->btnViewSchedule->Location = System::Drawing::Point(130, 60);
            this->btnViewSchedule->Name = L"btnViewSchedule";
            this->btnViewSchedule->Size = System::Drawing::Size(120, 30);
            this->btnViewSchedule->Text = L"View Schedule";
            this->btnViewSchedule->Click += gcnew System::EventHandler(this, &ViewSchedule::btnViewSchedule_Click);

            this->dgvSchedule->Location = System::Drawing::Point(20, 100);
            this->dgvSchedule->Size = System::Drawing::Size(460, 150);
            this->dgvSchedule->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dgvSchedule->TabIndex = 4;

            // Adding columns to the DataGridView
            this->dgvSchedule->Columns->Add("courseID", "Course ID");
            this->dgvSchedule->Columns->Add("courseName", "Course Name");
            this->dgvSchedule->Columns->Add("day", "Day");
            this->dgvSchedule->Columns->Add("start_time", "Start Time");
            this->dgvSchedule->Columns->Add("end_time", "End Time");

            this->ClientSize = System::Drawing::Size(500, 300);
            this->Controls->Add(this->dgvSchedule);
            this->Controls->Add(this->btnViewSchedule);
            this->Controls->Add(this->txtStudentID);
            this->Controls->Add(this->labelStudentID);
            this->Text = L"View Schedule";
        }
#pragma endregion

        void PopulateSchedule()
        {
            conn = gcnew MySqlConnection(connectionString);

            // Modified query to fetch courseName as well
            String^ query = "SELECT s.courseID, c.courseName, s.day, s.start_time, s.end_time "
                "FROM schedule s "
                "JOIN courses c ON s.courseID = c.courseID "
                "WHERE s.studentID = @studentID";
            cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@studentID", txtStudentID->Text);

            try
            {
                conn->Open();
                reader = cmd->ExecuteReader();

                // Clear existing rows in the DataGridView
                dgvSchedule->Rows->Clear();

                while (reader->Read())
                {
                    // Add the data to the DataGridView
                    dgvSchedule->Rows->Add(reader["courseID"], reader["courseName"], reader["day"], reader["start_time"], reader["end_time"]);
                }
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error: " + ex->Message + "\n" + ex->StackTrace, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
            finally
            {
                if (conn != nullptr && conn->State == ConnectionState::Open)
                {
                    conn->Close();
                }
            }
        }

        // Handle button click event to fetch and display the schedule
        void btnViewSchedule_Click(System::Object^ sender, System::EventArgs^ e)
        {
            PopulateSchedule();
        }
    };
}
