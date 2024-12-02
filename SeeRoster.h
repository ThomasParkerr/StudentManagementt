#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace MySql::Data::MySqlClient; // Include the MySQL library

public ref class SeeRoster : public System::Windows::Forms::Form
{
public:
    SeeRoster(void)
    {
        InitializeComponent();
    }

protected:
    ~SeeRoster()
    {
        if (components)
        {
            delete components;
        }
    }

private:
    System::Windows::Forms::Label^ labelTitle;
    System::Windows::Forms::ComboBox^ comboCourse;
    System::Windows::Forms::Label^ labelCourse;
    System::Windows::Forms::Button^ btnViewRoster;
    System::Windows::Forms::DataGridView^ dgvRoster;

    System::ComponentModel::Container^ components;

private:
    // Button click event to view the roster based on the selected course
    System::Void btnViewRoster_Click(System::Object^ sender, System::EventArgs^ e)
    {
        String^ courseID = comboCourse->SelectedItem->ToString();
        courseID = courseID->Substring(0, courseID->IndexOf(" -")); // Extract courseID

        if (String::IsNullOrEmpty(courseID))
        {
            MessageBox::Show("Please select a course.");
            return;
        }

        DataTable^ studentData = GetStudentsForCourse(courseID);
        dgvRoster->DataSource = studentData;
    }

private:
    // Fetching the students enrolled in the selected course from the database
    DataTable^ GetStudentsForCourse(String^ courseID)
    {
        DataTable^ studentData = gcnew DataTable();
        studentData->Columns->Add("First Name");
        studentData->Columns->Add("Last Name");

        String^ connStr = "Server=localhost;Database=studentenroll;Uid=root;Pwd='';";
        MySqlConnection^ conn = gcnew MySqlConnection(connStr);

        try
        {
            conn->Open();
            String^ query = "SELECT u.firstName, u.lastName "
                "FROM users u "
                "JOIN students s ON u.userID = s.userID "
                "JOIN enrollments e ON s.studentID = e.studentID "
                "JOIN courses c ON e.courseID = c.courseID "
                "WHERE e.courseID = @courseID";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@courseID", courseID);

            MySqlDataReader^ reader = cmd->ExecuteReader();

            while (reader->Read())
            {
                studentData->Rows->Add(reader->GetString("firstName"), reader->GetString("lastName"));
            }

            reader->Close();
        }
        catch (Exception^ ex)
        {
            MessageBox::Show("Error: " + ex->Message);
        }
        finally
        {
            if (conn->State == ConnectionState::Open)
            {
                conn->Close();
            }
        }

        return studentData;
    }

private:
    // Populating the course ComboBox with all courses
    System::Void FillCourseComboBox(void)
    {
        String^ connStr = "Server=localhost;Database=studentenroll;Uid=root;Pwd='';";
        MySqlConnection^ conn = gcnew MySqlConnection(connStr);

        try
        {
            conn->Open();
            String^ query = "SELECT courseID, courseName FROM courses"; // Retrieve all courses

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);

            MySqlDataReader^ reader = cmd->ExecuteReader();

            comboCourse->Items->Clear();

            while (reader->Read())
            {
                String^ courseID = reader->GetString("courseID");
                String^ courseName = reader->GetString("courseName");
                String^ comboItem = courseID + " - " + courseName; // Combine courseID and courseName
                comboCourse->Items->Add(comboItem);
            }

            if (comboCourse->Items->Count > 0)
            {
                comboCourse->SelectedIndex = 0; // Select the first item by default
            }

            reader->Close();
        }
        catch (Exception^ ex)
        {
            MessageBox::Show("Error: " + ex->Message);
        }
        finally
        {
            if (conn->State == ConnectionState::Open)
            {
                conn->Close();
            }
        }
    }

private:
    // Initialize components and layout
    System::Void InitializeComponent(void)
    {
        this->labelTitle = (gcnew System::Windows::Forms::Label());
        this->comboCourse = (gcnew System::Windows::Forms::ComboBox());
        this->labelCourse = (gcnew System::Windows::Forms::Label());
        this->btnViewRoster = (gcnew System::Windows::Forms::Button());
        this->dgvRoster = (gcnew System::Windows::Forms::DataGridView());
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRoster))->BeginInit();
        this->SuspendLayout();
        // 
        // labelTitle
        // 
        this->labelTitle->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 16, System::Drawing::FontStyle::Bold));
        this->labelTitle->Location = System::Drawing::Point(387, 25);
        this->labelTitle->Name = L"labelTitle";
        this->labelTitle->Size = System::Drawing::Size(447, 54);
        this->labelTitle->TabIndex = 0;
        this->labelTitle->Text = L"VIEW ROSTER";
        // 
        // comboCourse
        // 
        this->comboCourse->Location = System::Drawing::Point(439, 140);
        this->comboCourse->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
        this->comboCourse->Name = L"comboCourse";
        this->comboCourse->Size = System::Drawing::Size(324, 28);
        this->comboCourse->TabIndex = 1;
        // 
        // labelCourse
        // 
        this->labelCourse->Location = System::Drawing::Point(312, 139);
        this->labelCourse->Name = L"labelCourse";
        this->labelCourse->Size = System::Drawing::Size(126, 29);
        this->labelCourse->TabIndex = 2;
        this->labelCourse->Text = L"Course";
        // 
        // btnViewRoster
        // 
        this->btnViewRoster->Location = System::Drawing::Point(947, 142);
        this->btnViewRoster->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
        this->btnViewRoster->Name = L"btnViewRoster";
        this->btnViewRoster->Size = System::Drawing::Size(94, 29);
        this->btnViewRoster->TabIndex = 3;
        this->btnViewRoster->Text = L"View";
        this->btnViewRoster->UseVisualStyleBackColor = true;
        this->btnViewRoster->Click += gcnew System::EventHandler(this, &SeeRoster::btnViewRoster_Click);
        // 
        // dgvRoster
        // 
        this->dgvRoster->ColumnHeadersHeight = 34;
        this->dgvRoster->Location = System::Drawing::Point(45, 227);
        this->dgvRoster->Name = L"dgvRoster";
        this->dgvRoster->RowHeadersWidth = 62;
        this->dgvRoster->Size = System::Drawing::Size(1098, 372);
        this->dgvRoster->TabIndex = 4;
        // 
        // SeeRoster
        // 
        this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(1206, 632);
        this->Controls->Add(this->dgvRoster);
        this->Controls->Add(this->btnViewRoster);
        this->Controls->Add(this->labelCourse);
        this->Controls->Add(this->comboCourse);
        this->Controls->Add(this->labelTitle);
        this->Name = L"SeeRoster";
        this->Text = L"SeeRoster";
        this->Load += gcnew System::EventHandler(this, &SeeRoster::SeeRoster_Load);
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRoster))->EndInit();
        this->ResumeLayout(false);

    }

private:
    // Form load event to populate the ComboBox with courses
    System::Void SeeRoster_Load(System::Object^ sender, System::EventArgs^ e)
    {
        FillCourseComboBox();
    }
};
