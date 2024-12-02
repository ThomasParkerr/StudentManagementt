#pragma once

namespace StudentManagement {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient;

    public ref class ManageFinances : public System::Windows::Forms::Form
    {
    public:
        ManageFinances(void)
        {
            InitializeComponent();
            LoadStudents();
        }

    private:
        System::ComponentModel::Container^ components;

    protected:
        ~ManageFinances()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::ComboBox^ cbStudents;
        System::Windows::Forms::DataGridView^ dgvPayments;
        System::Windows::Forms::Button^ btnConfirmPayment;
        System::Windows::Forms::Label^ lblStudent;
        System::Windows::Forms::Label^ lblPaymentHistory;
        String^ connectionString = "Server=localhost;Database=studentenroll;User ID=root;Password=\"\"";

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->cbStudents = (gcnew System::Windows::Forms::ComboBox());
            this->dgvPayments = (gcnew System::Windows::Forms::DataGridView());
            this->btnConfirmPayment = (gcnew System::Windows::Forms::Button());
            this->lblStudent = (gcnew System::Windows::Forms::Label());
            this->lblPaymentHistory = (gcnew System::Windows::Forms::Label());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvPayments))->BeginInit();
            this->SuspendLayout();

            // cbStudents
            this->cbStudents->FormattingEnabled = true;
            this->cbStudents->Location = System::Drawing::Point(12, 30);
            this->cbStudents->Name = L"cbStudents";
            this->cbStudents->Size = System::Drawing::Size(200, 28);
            this->cbStudents->TabIndex = 0;
            this->cbStudents->SelectedIndexChanged += gcnew System::EventHandler(this, &ManageFinances::cbStudents_SelectedIndexChanged);

            // dgvPayments
            this->dgvPayments->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dgvPayments->Location = System::Drawing::Point(12, 100);
            this->dgvPayments->Name = L"dgvPayments";
            this->dgvPayments->RowHeadersWidth = 62;
            this->dgvPayments->Size = System::Drawing::Size(360, 150);
            this->dgvPayments->TabIndex = 1;

            // btnConfirmPayment
            this->btnConfirmPayment->Location = System::Drawing::Point(12, 260);
            this->btnConfirmPayment->Name = L"btnConfirmPayment";
            this->btnConfirmPayment->Size = System::Drawing::Size(120, 30);
            this->btnConfirmPayment->TabIndex = 2;
            this->btnConfirmPayment->Text = L"Confirm Payment";
            this->btnConfirmPayment->UseVisualStyleBackColor = true;
            this->btnConfirmPayment->Click += gcnew System::EventHandler(this, &ManageFinances::btnConfirmPayment_Click);

            // lblStudent
            this->lblStudent->AutoSize = true;
            this->lblStudent->Location = System::Drawing::Point(12, 10);
            this->lblStudent->Name = L"lblStudent";
            this->lblStudent->Size = System::Drawing::Size(70, 20);
            this->lblStudent->TabIndex = 3;
            this->lblStudent->Text = L"Student:";

            // lblPaymentHistory
            this->lblPaymentHistory->AutoSize = true;
            this->lblPaymentHistory->Location = System::Drawing::Point(12, 80);
            this->lblPaymentHistory->Name = L"lblPaymentHistory";
            this->lblPaymentHistory->Size = System::Drawing::Size(128, 20);
            this->lblPaymentHistory->TabIndex = 4;
            this->lblPaymentHistory->Text = L"Payment History:";

            // ManageFinances
            this->ClientSize = System::Drawing::Size(400, 300);
            this->Controls->Add(this->lblPaymentHistory);
            this->Controls->Add(this->lblStudent);
            this->Controls->Add(this->btnConfirmPayment);
            this->Controls->Add(this->dgvPayments);
            this->Controls->Add(this->cbStudents);
            this->Name = L"ManageFinances";
            this->Text = L"Manage Finances";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvPayments))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

        void LoadStudents()
        {
            try
            {
                MySqlConnection^ conn = gcnew MySqlConnection(connectionString);
                conn->Open();
                String^ query = "SELECT UserID, FirstName, LastName FROM Users";
                MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
                MySqlDataReader^ reader = cmd->ExecuteReader();

                while (reader->Read())
                {
                    String^ studentName = reader->GetString(1) + " " + reader->GetString(2);
                    cbStudents->Items->Add(studentName);
                }
                conn->Close();
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error loading students: " + ex->Message);
            }
        }

        int GetStudentIDByName(String^ studentName)
        {
            array<String^>^ nameParts = studentName->Split(' ');
            String^ firstName = nameParts[0];
            String^ lastName = nameParts[1];
            int userID = 0;

            try
            {
                MySqlConnection^ conn = gcnew MySqlConnection(connectionString);
                conn->Open();
                String^ query = "SELECT UserID FROM Users WHERE FirstName=@FirstName AND LastName=@LastName";
                MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
                cmd->Parameters->AddWithValue("@FirstName", firstName);
                cmd->Parameters->AddWithValue("@LastName", lastName);
                userID = Convert::ToInt32(cmd->ExecuteScalar());
                conn->Close();
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error fetching user ID: " + ex->Message);
            }
            return userID;
        }

        void LoadPaymentHistory(int studentID)
        {
            try
            {
                MySqlConnection^ conn = gcnew MySqlConnection(connectionString);
                conn->Open();

                String^ query = "SELECT fee_amount, fee_type FROM  fee_payments WHERE StudentID = @StudentID";
                MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
                cmd->Parameters->AddWithValue("@StudentID", studentID);
                MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter(cmd);
                DataTable^ dt = gcnew DataTable();

                adapter->Fill(dt);
                dgvPayments->DataSource = dt;

                conn->Close();
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error loading payment history: " + ex->Message);
            }
        }

        void cbStudents_SelectedIndexChanged(Object^ sender, EventArgs^ e)
        {
            if (cbStudents->SelectedItem == nullptr)
                return;

            String^ selectedStudent = cbStudents->SelectedItem->ToString();
            int studentID = GetStudentIDByName(selectedStudent);

            if (studentID > 0)
            {
                LoadPaymentHistory(studentID);
            }
            else
            {
                MessageBox::Show("Unable to load payment history for the selected student.");
            }
        }

        void btnConfirmPayment_Click(Object^ sender, EventArgs^ e)
        {
            if (cbStudents->SelectedItem == nullptr)
            {
                MessageBox::Show("Please select a student to confirm payment.");
                return;
            }

            String^ selectedStudent = cbStudents->SelectedItem->ToString();
            int studentID = GetStudentIDByName(selectedStudent);

            if (studentID == 0)
            {
                MessageBox::Show("Unable to fetch student details. Please try again.");
                return;
            }

            try
            {
                MySqlConnection^ conn = gcnew MySqlConnection(connectionString);
                conn->Open();

                String^ updateQuery = "UPDATE students SET fees_paid = 'YES' WHERE StudentID = @StudentID";
                MySqlCommand^ cmd = gcnew MySqlCommand(updateQuery, conn);
                cmd->Parameters->AddWithValue("@StudentID", studentID);

                int rowsAffected = cmd->ExecuteNonQuery();
                conn->Close();

                if (rowsAffected > 0)
                {
                    MessageBox::Show("Payment confirmed successfully for: " + selectedStudent);
                    LoadPaymentHistory(studentID);
                }
                else
                {
                    MessageBox::Show("No payment records were updated. Please check the database.");
                }
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error confirming payment: " + ex->Message);
            }
        }
    };
}
