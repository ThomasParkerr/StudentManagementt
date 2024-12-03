namespace StudentManagement {

    using namespace System;
    using namespace System::Data;
    using namespace System::Windows::Forms;
    using namespace MySql::Data::MySqlClient;

    public ref class AdminManage : public System::Windows::Forms::Form
    {
    public:
        AdminManage(void)
        {
            InitializeComponent();
            LoadCourses();
        }

    protected:
        ~AdminManage()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::DataGridView^ dgvCourses;
        System::Windows::Forms::TextBox^ txtCourseID;
        System::Windows::Forms::TextBox^ txtCourseName;
        System::Windows::Forms::TextBox^ txtCredits;
        System::Windows::Forms::TextBox^ txtSchedule;
        System::Windows::Forms::TextBox^ txtStartTime;
        System::Windows::Forms::TextBox^ txtEndTime;
        System::Windows::Forms::TextBox^ txtFacultyID;
        System::Windows::Forms::Button^ btnAddCourse;
        System::Windows::Forms::Button^ btnUpdateCourse;
        System::Windows::Forms::Button^ btnDeleteCourse;

        System::String^ connectionString = "Server=localhost;Database=studentenroll;Uid=root;Pwd=\"\";";
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::Label^ label5;
    private: System::Windows::Forms::Label^ label6;
    private: System::Windows::Forms::Label^ label7;
           System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
    private: System::Void InitializeComponent() {
        this->dgvCourses = (gcnew System::Windows::Forms::DataGridView());
        this->txtCourseID = (gcnew System::Windows::Forms::TextBox());
        this->txtCourseName = (gcnew System::Windows::Forms::TextBox());
        this->txtCredits = (gcnew System::Windows::Forms::TextBox());
        this->txtSchedule = (gcnew System::Windows::Forms::TextBox());
        this->txtStartTime = (gcnew System::Windows::Forms::TextBox());
        this->txtEndTime = (gcnew System::Windows::Forms::TextBox());
        this->txtFacultyID = (gcnew System::Windows::Forms::TextBox());
        this->btnAddCourse = (gcnew System::Windows::Forms::Button());
        this->btnUpdateCourse = (gcnew System::Windows::Forms::Button());
        this->btnDeleteCourse = (gcnew System::Windows::Forms::Button());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->label2 = (gcnew System::Windows::Forms::Label());
        this->label3 = (gcnew System::Windows::Forms::Label());
        this->label4 = (gcnew System::Windows::Forms::Label());
        this->label5 = (gcnew System::Windows::Forms::Label());
        this->label6 = (gcnew System::Windows::Forms::Label());
        this->label7 = (gcnew System::Windows::Forms::Label());
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCourses))->BeginInit();
        this->SuspendLayout();
        // 
        // dgvCourses
        // 
        this->dgvCourses->ColumnHeadersHeight = 34;
        this->dgvCourses->Location = System::Drawing::Point(12, 12);
        this->dgvCourses->Name = L"dgvCourses";
        this->dgvCourses->RowHeadersWidth = 62;
        this->dgvCourses->Size = System::Drawing::Size(700, 150);
        this->dgvCourses->TabIndex = 0;
        // 
        // txtCourseID
        // 
        this->txtCourseID->Location = System::Drawing::Point(125, 180);
        this->txtCourseID->Name = L"txtCourseID";
        this->txtCourseID->Size = System::Drawing::Size(100, 26);
        this->txtCourseID->TabIndex = 1;
        // 
        // txtCourseName
        // 
        this->txtCourseName->Location = System::Drawing::Point(125, 220);
        this->txtCourseName->Name = L"txtCourseName";
        this->txtCourseName->Size = System::Drawing::Size(200, 26);
        this->txtCourseName->TabIndex = 2;
        // 
        // txtCredits
        // 
        this->txtCredits->Location = System::Drawing::Point(125, 260);
        this->txtCredits->Name = L"txtCredits";
        this->txtCredits->Size = System::Drawing::Size(100, 26);
        this->txtCredits->TabIndex = 3;
        // 
        // txtSchedule
        // 
        this->txtSchedule->Location = System::Drawing::Point(125, 300);
        this->txtSchedule->Name = L"txtSchedule";
        this->txtSchedule->Size = System::Drawing::Size(200, 26);
        this->txtSchedule->TabIndex = 4;
        // 
        // txtStartTime
        // 
        this->txtStartTime->Location = System::Drawing::Point(125, 340);
        this->txtStartTime->Name = L"txtStartTime";
        this->txtStartTime->Size = System::Drawing::Size(100, 26);
        this->txtStartTime->TabIndex = 5;
        // 
        // txtEndTime
        // 
        this->txtEndTime->Location = System::Drawing::Point(125, 380);
        this->txtEndTime->Name = L"txtEndTime";
        this->txtEndTime->Size = System::Drawing::Size(100, 26);
        this->txtEndTime->TabIndex = 6;
        // 
        // txtFacultyID
        // 
        this->txtFacultyID->Location = System::Drawing::Point(125, 420);
        this->txtFacultyID->Name = L"txtFacultyID";
        this->txtFacultyID->Size = System::Drawing::Size(100, 26);
        this->txtFacultyID->TabIndex = 7;
        // 
        // btnAddCourse
        // 
        this->btnAddCourse->Location = System::Drawing::Point(125, 460);
        this->btnAddCourse->Name = L"btnAddCourse";
        this->btnAddCourse->Size = System::Drawing::Size(100, 30);
        this->btnAddCourse->TabIndex = 8;
        this->btnAddCourse->Text = L"Add Course";
        this->btnAddCourse->Click += gcnew System::EventHandler(this, &AdminManage::btnAddCourse_Click);
        // 
        // btnUpdateCourse
        // 
        this->btnUpdateCourse->Location = System::Drawing::Point(250, 460);
        this->btnUpdateCourse->Name = L"btnUpdateCourse";
        this->btnUpdateCourse->Size = System::Drawing::Size(100, 30);
        this->btnUpdateCourse->TabIndex = 9;
        this->btnUpdateCourse->Text = L"Update Course";
        this->btnUpdateCourse->Click += gcnew System::EventHandler(this, &AdminManage::btnUpdateCourse_Click);
        // 
        // btnDeleteCourse
        // 
        this->btnDeleteCourse->Location = System::Drawing::Point(375, 460);
        this->btnDeleteCourse->Name = L"btnDeleteCourse";
        this->btnDeleteCourse->Size = System::Drawing::Size(100, 30);
        this->btnDeleteCourse->TabIndex = 10;
        this->btnDeleteCourse->Text = L"Delete Course";
        this->btnDeleteCourse->Click += gcnew System::EventHandler(this, &AdminManage::btnDeleteCourse_Click);
        // 
        // label1
        // 
        this->label1->Location = System::Drawing::Point(12, 180);
        this->label1->Text = L"Course ID:";
        // 
        // label2
        // 
        this->label2->Location = System::Drawing::Point(12, 220);
        this->label2->Text = L"Course Name:";
        // 
        // label3
        // 
        this->label3->Location = System::Drawing::Point(12, 260);
        this->label3->Text = L"Credits:";
        // 
        // label4
        // 
        this->label4->Location = System::Drawing::Point(12, 300);
        this->label4->Text = L"Schedule:";
        // 
        // label5
        // 
        this->label5->Location = System::Drawing::Point(12, 340);
        this->label5->Text = L"Start Time:";
        // 
        // label6
        // 
        this->label6->Location = System::Drawing::Point(12, 380);
        this->label6->Text = L"End Time:";
        // 
        // label7
        // 
        this->label7->Location = System::Drawing::Point(12, 420);
        this->label7->Text = L"Faculty ID:";
        // 
        // AdminManage
        // 
        this->AutoScaleDimensions = System::Drawing::SizeF(8, 20);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(800, 600);
        this->Controls->Add(this->label7);
        this->Controls->Add(this->label6);
        this->Controls->Add(this->label5);
        this->Controls->Add(this->label4);
        this->Controls->Add(this->label3);
        this->Controls->Add(this->label2);
        this->Controls->Add(this->label1);
        this->Controls->Add(this->btnDeleteCourse);
        this->Controls->Add(this->btnUpdateCourse);
        this->Controls->Add(this->btnAddCourse);
        this->Controls->Add(this->txtFacultyID);
        this->Controls->Add(this->txtEndTime);
        this->Controls->Add(this->txtStartTime);
        this->Controls->Add(this->txtSchedule);
        this->Controls->Add(this->txtCredits);
        this->Controls->Add(this->txtCourseName);
        this->Controls->Add(this->txtCourseID);
        this->Controls->Add(this->dgvCourses);
        this->Name = L"AdminManage";
        this->Text = L"Admin Manage";
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCourses))->EndInit();
        this->ResumeLayout(false);
        this->PerformLayout();
    }
#pragma endregion

    private: System::Void LoadCourses() {
        MySqlConnection^ conn = gcnew MySqlConnection(connectionString);
        MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter("SELECT * FROM courses", conn);
        DataTable^ dt = gcnew DataTable();
        adapter->Fill(dt);
        dgvCourses->DataSource = dt;
    }

    private: System::Void btnAddCourse_Click(System::Object^ sender, System::EventArgs^ e) {
        MySqlConnection^ conn = gcnew MySqlConnection(connectionString);
        MySqlCommand^ cmd = gcnew MySqlCommand("INSERT INTO courses (courseID, courseName, credits, schedule, start_time, end_time, facultyID) VALUES (@courseID, @courseName, @credits, @schedule, @start_time, @end_time, @facultyID)", conn);
        cmd->Parameters->AddWithValue("@courseID", txtCourseID->Text);
        cmd->Parameters->AddWithValue("@courseName", txtCourseName->Text);
        cmd->Parameters->AddWithValue("@credits", txtCredits->Text);
        cmd->Parameters->AddWithValue("@schedule", txtSchedule->Text);
        cmd->Parameters->AddWithValue("@start_time", txtStartTime->Text);
        cmd->Parameters->AddWithValue("@end_time", txtEndTime->Text);
        cmd->Parameters->AddWithValue("@facultyID", txtFacultyID->Text);

        conn->Open();
        cmd->ExecuteNonQuery();
        conn->Close();
        LoadCourses();
    }

    private: System::Void btnUpdateCourse_Click(System::Object^ sender, System::EventArgs^ e) {
        MySqlConnection^ conn = gcnew MySqlConnection(connectionString);
        MySqlCommand^ cmd = gcnew MySqlCommand("UPDATE courses SET courseName = @courseName, credits = @credits, schedule = @schedule, start_time = @start_time, end_time = @end_time, facultyID = @facultyID WHERE courseID = @courseID", conn);
        cmd->Parameters->AddWithValue("@courseID", txtCourseID->Text);
        cmd->Parameters->AddWithValue("@courseName", txtCourseName->Text);
        cmd->Parameters->AddWithValue("@credits", txtCredits->Text);
        cmd->Parameters->AddWithValue("@schedule", txtSchedule->Text);
        cmd->Parameters->AddWithValue("@start_time", txtStartTime->Text);
        cmd->Parameters->AddWithValue("@end_time", txtEndTime->Text);
        cmd->Parameters->AddWithValue("@facultyID", txtFacultyID->Text);

        conn->Open();
        cmd->ExecuteNonQuery();
        conn->Close();
        LoadCourses();
    }

    private: System::Void btnDeleteCourse_Click(System::Object^ sender, System::EventArgs^ e) {
        MySqlConnection^ conn = gcnew MySqlConnection(connectionString);
        MySqlCommand^ cmd = gcnew MySqlCommand("DELETE FROM courses WHERE courseID = @courseID", conn);
        cmd->Parameters->AddWithValue("@courseID", txtCourseID->Text);

        conn->Open();
        cmd->ExecuteNonQuery();
        conn->Close();
        LoadCourses();
    }
    };
}
