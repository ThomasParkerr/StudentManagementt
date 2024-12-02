#pragma once

namespace StudentManagement {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient;

    /// <summary>
    /// Summary for PayFees
    /// </summary>
    public ref class PayFees : public System::Windows::Forms::Form
    {
    public:
        PayFees(void)
        {
            InitializeComponent();
            PopulateFeeTypes(); // Populate fee types on form load
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~PayFees()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        /// <summary>
        /// Required designer variable.
        /// </summary>
        System::ComponentModel::Container^ components;

        // Form Controls
        System::Windows::Forms::Label^ labelTitle;
        System::Windows::Forms::Label^ labelStudentID;
        System::Windows::Forms::Label^ labelFeeAmount;
        System::Windows::Forms::Label^ labelFeeType;
        System::Windows::Forms::TextBox^ txtStudentID;
        System::Windows::Forms::TextBox^ txtFeeAmount;
        System::Windows::Forms::ComboBox^ comboFeeType;
        System::Windows::Forms::Button^ btnPay;

        // Database connection string
        String^ connectionString = "Server=localhost;Database=studentenroll;User ID=root;Password=\"\";";

        // Database connection and command objects
        MySqlConnection^ conn;
        MySqlCommand^ cmd;
        MySqlDataReader^ reader;

        // Enum for Fee Types
        enum class fee_type
        {
            Tuition,
            LabFee,
            LibraryFee,
            HostelFee
        };

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void)
        {
            this->labelTitle = (gcnew System::Windows::Forms::Label());
            this->labelStudentID = (gcnew System::Windows::Forms::Label());
            this->labelFeeAmount = (gcnew System::Windows::Forms::Label());
            this->labelFeeType = (gcnew System::Windows::Forms::Label());
            this->txtStudentID = (gcnew System::Windows::Forms::TextBox());
            this->txtFeeAmount = (gcnew System::Windows::Forms::TextBox());
            this->comboFeeType = (gcnew System::Windows::Forms::ComboBox());
            this->btnPay = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // labelTitle
            // 
            this->labelTitle->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 16, System::Drawing::FontStyle::Bold));
            this->labelTitle->Location = System::Drawing::Point(50, 20);
            this->labelTitle->Name = L"labelTitle";
            this->labelTitle->Size = System::Drawing::Size(200, 40);
            this->labelTitle->TabIndex = 0;
            this->labelTitle->Text = L"Pay Fees";
            // 
            // labelStudentID
            // 
            this->labelStudentID->Location = System::Drawing::Point(30, 80);
            this->labelStudentID->Name = L"labelStudentID";
            this->labelStudentID->Size = System::Drawing::Size(100, 20);
            this->labelStudentID->TabIndex = 1;
            this->labelStudentID->Text = L"Student ID";
            // 
            // labelFeeAmount
            // 
            this->labelFeeAmount->Location = System::Drawing::Point(30, 120);
            this->labelFeeAmount->Name = L"labelFeeAmount";
            this->labelFeeAmount->Size = System::Drawing::Size(100, 20);
            this->labelFeeAmount->TabIndex = 2;
            this->labelFeeAmount->Text = L"Fee Amount";
            // 
            // labelFeeType
            // 
            this->labelFeeType->Location = System::Drawing::Point(30, 160);
            this->labelFeeType->Name = L"labelFeeType";
            this->labelFeeType->Size = System::Drawing::Size(100, 20);
            this->labelFeeType->TabIndex = 3;
            this->labelFeeType->Text = L"Fee Type";
            // 
            // txtStudentID
            // 
            this->txtStudentID->Location = System::Drawing::Point(140, 80);
            this->txtStudentID->Name = L"txtStudentID";
            this->txtStudentID->Size = System::Drawing::Size(150, 26);
            this->txtStudentID->TabIndex = 4;
            // 
            // txtFeeAmount
            // 
            this->txtFeeAmount->Location = System::Drawing::Point(140, 120);
            this->txtFeeAmount->Name = L"txtFeeAmount";
            this->txtFeeAmount->Size = System::Drawing::Size(150, 26);
            this->txtFeeAmount->TabIndex = 5;
            // 
            // comboFeeType
            // 
            this->comboFeeType->Location = System::Drawing::Point(140, 160);
            this->comboFeeType->Name = L"comboFeeType";
            this->comboFeeType->Size = System::Drawing::Size(150, 26);
            this->comboFeeType->TabIndex = 6;
            // 
            // btnPay
            // 
            this->btnPay->Location = System::Drawing::Point(80, 200);
            this->btnPay->Name = L"btnPay";
            this->btnPay->Size = System::Drawing::Size(100, 30);
            this->btnPay->TabIndex = 7;
            this->btnPay->Text = L"Pay";
            this->btnPay->UseVisualStyleBackColor = true;
            this->btnPay->Click += gcnew System::EventHandler(this, &PayFees::btnPay_Click);
            // 
            // PayFees
            // 
            this->ClientSize = System::Drawing::Size(320, 260);
            this->Controls->Add(this->btnPay);
            this->Controls->Add(this->comboFeeType);
            this->Controls->Add(this->txtFeeAmount);
            this->Controls->Add(this->txtStudentID);
            this->Controls->Add(this->labelFeeType);
            this->Controls->Add(this->labelFeeAmount);
            this->Controls->Add(this->labelStudentID);
            this->Controls->Add(this->labelTitle);
            this->Name = L"PayFees";
            this->Text = L"Pay Fees";
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

        // Method to populate ComboBox with fee types from the fee_type enum
        void PopulateFeeTypes()
        {
            // Get the enum values and add them to the ComboBox
            for each (int fee in Enum::GetValues(fee_type::typeid))
            {
                comboFeeType->Items->Add(Enum::GetName(fee_type::typeid, fee));
            }
        }

        // Handle the button click event to make the payment
        void btnPay_Click(System::Object^ sender, System::EventArgs^ e)
        {
            try
            {
                // Create a connection to the database
                conn = gcnew MySqlConnection(connectionString);
                conn->Open();

                // Create an SQL command to insert the payment
                String^ query = "INSERT INTO fee_payments (studentID, fee_type, fee_amount) VALUES (@studentID, @fee_type, @fee_amount)";
                cmd = gcnew MySqlCommand(query, conn);
                cmd->Parameters->AddWithValue("@studentID", txtStudentID->Text);
                cmd->Parameters->AddWithValue("@fee_type", comboFeeType->SelectedItem->ToString());
                cmd->Parameters->AddWithValue("@fee_amount", txtFeeAmount->Text);

                // Execute the query
                cmd->ExecuteNonQuery();

                // Show success message
                MessageBox::Show("Payment Successful!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
            catch (Exception^ ex)
            {
                // Show an error message if something goes wrong
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
    };
}
