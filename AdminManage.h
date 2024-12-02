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
        System::Windows::Forms::TextBox^ txtSchedule;  // New TextBox for schedule
        System::Windows::Forms::TextBox^ txtFacultyID;  // New TextBox for faculty ID
        System::Windows::Forms::Button^ btnAddCourse;
        System::Windows::Forms::Button^ btnUpdateCourse;
        System::Windows::Forms::Button^ btnDeleteCourse;

        System::String^ connectionString = "Server=localhost;Database=studentenroll;Uid=root;Pwd=\"\";";
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::Label^ label5;
           System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
    private: System::Void InitializeComponent() {
        this->dgvCourses = (gcnew System::Windows::Forms::DataGridView());
        this->txtCourseID = (gcnew System::Windows::Forms::TextBox());
        this->txtCourseName = (gcnew System::Windows::Forms::TextBox());
        this->txtCredits = (gcnew System::Windows::Forms::TextBox());
        this->txtSchedule = (gcnew System::Windows::Forms::TextBox());
        this->txtFacultyID = (gcnew System::Windows::Forms::TextBox());
        this->btnAddCourse = (gcnew System::Windows::Forms::Button());
        this->btnUpdateCourse = (gcnew System::Windows::Forms::Button());
        this->btnDeleteCourse = (gcnew System::Windows::Forms::Button());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->label2 = (gcnew System::Windows::Forms::Label());
        this->label3 = (gcnew System::Windows::Forms::Label());
        this->label4 = (gcnew System::Windows::Forms::Label());
        this->label5 = (gcnew System::Windows::Forms::Label());
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCourses))->BeginInit();
        this->SuspendLayout();
        // 
        // dgvCourses
        // 
        this->dgvCourses->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
        this->dgvCourses->Location = System::Drawing::Point(20, 20);
        this->dgvCourses->Name = L"dgvCourses";
        this->dgvCourses->RowHeadersWidth = 62;
        this->dgvCourses->Size = System::Drawing::Size(500, 200);
        this->dgvCourses->TabIndex = 0;
        // 
        // txtCourseID
        // 
        this->txtCourseID->Location = System::Drawing::Point(260, 235);
        this->txtCourseID->Name = L"txtCourseID";
        this->txtCourseID->Size = System::Drawing::Size(200, 26);
        this->txtCourseID->TabIndex = 1;
        // 
        // txtCourseName
        // 
        this->txtCourseName->Location = System::Drawing::Point(260, 278);
        this->txtCourseName->Name = L"txtCourseName";
        this->txtCourseName->Size = System::Drawing::Size(200, 26);
        this->txtCourseName->TabIndex = 2;
        // 
        // txtCredits
        // 
        this->txtCredits->Location = System::Drawing::Point(260, 328);
        this->txtCredits->Name = L"txtCredits";
        this->txtCredits->Size = System::Drawing::Size(200, 26);
        this->txtCredits->TabIndex = 3;
        // 
        // txtSchedule
        // 
        this->txtSchedule->Location = System::Drawing::Point(260, 368);
        this->txtSchedule->Name = L"txtSchedule";
        this->txtSchedule->Size = System::Drawing::Size(200, 26);
        this->txtSchedule->TabIndex = 4;
        // 
        // txtFacultyID
        // 
        this->txtFacultyID->Location = System::Drawing::Point(260, 415);
        this->txtFacultyID->Name = L"txtFacultyID";
        this->txtFacultyID->Size = System::Drawing::Size(200, 26);
        this->txtFacultyID->TabIndex = 5;
        // 
        // btnAddCourse
        // 
        this->btnAddCourse->Location = System::Drawing::Point(80, 479);
        this->btnAddCourse->Name = L"btnAddCourse";
        this->btnAddCourse->Size = System::Drawing::Size(75, 35);
        this->btnAddCourse->TabIndex = 6;
        this->btnAddCourse->Text = L"Add Course";
        this->btnAddCourse->Click += gcnew System::EventHandler(this, &AdminManage::btnAddCourse_Click);
        // 
        // btnUpdateCourse
        // 
        this->btnUpdateCourse->Location = System::Drawing::Point(200, 479);
        this->btnUpdateCourse->Name = L"btnUpdateCourse";
        this->btnUpdateCourse->Size = System::Drawing::Size(75, 35);
        this->btnUpdateCourse->TabIndex = 7;
        this->btnUpdateCourse->Text = L"Update Course";
        this->btnUpdateCourse->Click += gcnew System::EventHandler(this, &AdminManage::btnUpdateCourse_Click);
        // 
        // btnDeleteCourse
        // 
        this->btnDeleteCourse->Location = System::Drawing::Point(326, 479);
        this->btnDeleteCourse->Name = L"btnDeleteCourse";
        this->btnDeleteCourse->Size = System::Drawing::Size(75, 35);
        this->btnDeleteCourse->TabIndex = 8;
        this->btnDeleteCourse->Text = L"Delete Course";
        this->btnDeleteCourse->Click += gcnew System::EventHandler(this, &AdminManage::btnDeleteCourse_Click);
        // 
        // label1
        // 
        this->label1->AutoSize = true;
        this->label1->Location = System::Drawing::Point(72, 241);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(95, 20);
        this->label1->TabIndex = 9;
        this->label1->Text = L"COURSEID";
        // 
        // label2
        // 
        this->label2->AutoSize = true;
        this->label2->Location = System::Drawing::Point(72, 284);
        this->label2->Name = L"label2";
        this->label2->Size = System::Drawing::Size(128, 20);
        this->label2->TabIndex = 10;
        this->label2->Text = L"COURSE NAME";
        // 
        // label3
        // 
        this->label3->AutoSize = true;
        this->label3->Location = System::Drawing::Point(72, 334);
        this->label3->Name = L"label3";
        this->label3->Size = System::Drawing::Size(80, 20);
        this->label3->TabIndex = 11;
        this->label3->Text = L"CREDITS";
        // 
        // label4
        // 
        this->label4->AutoSize = true;
        this->label4->Location = System::Drawing::Point(72, 374);
        this->label4->Name = L"label4";
        this->label4->Size = System::Drawing::Size(98, 20);
        this->label4->TabIndex = 12;
        this->label4->Text = L"SCHEDULE";
        // 
        // label5
        // 
        this->label5->AutoSize = true;
        this->label5->Location = System::Drawing::Point(76, 421);
        this->label5->Name = L"label5";
        this->label5->Size = System::Drawing::Size(82, 20);
        this->label5->TabIndex = 13;
        this->label5->Text = L"FACULTY";
        // 
        // AdminManage
        // 
        this->ClientSize = System::Drawing::Size(892, 776);
        this->Controls->Add(this->label5);
        this->Controls->Add(this->label4);
        this->Controls->Add(this->label3);
        this->Controls->Add(this->label2);
        this->Controls->Add(this->label1);
        this->Controls->Add(this->dgvCourses);
        this->Controls->Add(this->txtCourseID);
        this->Controls->Add(this->txtCourseName);
        this->Controls->Add(this->txtCredits);
        this->Controls->Add(this->txtSchedule);
        this->Controls->Add(this->txtFacultyID);
        this->Controls->Add(this->btnAddCourse);
        this->Controls->Add(this->btnUpdateCourse);
        this->Controls->Add(this->btnDeleteCourse);
        this->Name = L"AdminManage";
        this->Text = L"Admin - Manage Courses";
        this->Load += gcnew System::EventHandler(this, &AdminManage::AdminManage_Load);
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCourses))->EndInit();
        this->ResumeLayout(false);
        this->PerformLayout();

    }

#pragma endregion

    private:
        void LoadCourses()
        {
            try
            {
                MySqlConnection^ conn = gcnew MySqlConnection(connectionString);
                MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter("SELECT * FROM Courses", conn);
                DataTable^ dt = gcnew DataTable();
                adapter->Fill(dt);
                dgvCourses->DataSource = dt;
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error loading courses: " + ex->Message);
            }
        }

        void btnAddCourse_Click(Object^ sender, EventArgs^ e)
        {
            try
            {
                MySqlConnection^ conn = gcnew MySqlConnection(connectionString);
                conn->Open();
                String^ query = "INSERT INTO Courses (CourseName, Credits, Schedule, FacultyID) VALUES (@CourseName, @Credits, @Schedule, @FacultyID)";
                MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
                cmd->Parameters->AddWithValue("@CourseName", txtCourseName->Text);
                cmd->Parameters->AddWithValue("@Credits", Int32::Parse(txtCredits->Text));
                cmd->Parameters->AddWithValue("@Schedule", txtSchedule->Text);
                cmd->Parameters->AddWithValue("@FacultyID", Int32::Parse(txtFacultyID->Text));
                cmd->ExecuteNonQuery();
                MessageBox::Show("Course added successfully.");
                LoadCourses();
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error adding course: " + ex->Message);
            }
        }

        void btnUpdateCourse_Click(Object^ sender, EventArgs^ e)
        {
            try
            {
                MySqlConnection^ conn = gcnew MySqlConnection(connectionString);
                conn->Open();
                String^ query = "UPDATE Courses SET CourseName=@CourseName, Credits=@Credits, Schedule=@Schedule, FacultyID=@FacultyID WHERE CourseID=@CourseID";
                MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
                cmd->Parameters->AddWithValue("@CourseName", txtCourseName->Text);
                cmd->Parameters->AddWithValue("@Credits", Int32::Parse(txtCredits->Text));
                cmd->Parameters->AddWithValue("@Schedule", txtSchedule->Text);
                cmd->Parameters->AddWithValue("@FacultyID", Int32::Parse(txtFacultyID->Text));
                cmd->Parameters->AddWithValue("@CourseID", Int32::Parse(txtCourseID->Text));
                cmd->ExecuteNonQuery();
                MessageBox::Show("Course updated successfully.");
                LoadCourses();
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error updating course: " + ex->Message);
            }
        }

        void btnDeleteCourse_Click(Object^ sender, EventArgs^ e)
        {
            try
            {
                MySqlConnection^ conn = gcnew MySqlConnection(connectionString);
                conn->Open();
                String^ query = "DELETE FROM Courses WHERE CourseID=@CourseID";
                MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
                cmd->Parameters->AddWithValue("@CourseID", Int32::Parse(txtCourseID->Text));
                cmd->ExecuteNonQuery();
                MessageBox::Show("Course deleted successfully.");
                LoadCourses();
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error deleting course: " + ex->Message);
            }
        }
    private: System::Void AdminManage_Load(System::Object^ sender, System::EventArgs^ e) {
    }
};
}
