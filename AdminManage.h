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
        System::Windows::Forms::TextBox^ txtStartTime; // New TextBox for Start Time
        System::Windows::Forms::TextBox^ txtEndTime;   // New TextBox for End Time
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
    private: System::Windows::Forms::Label^ label6; // Label for Start Time
    private: System::Windows::Forms::Label^ label7; // Label for End Time
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
        this->dgvCourses->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
        this->dgvCourses->Location = System::Drawing::Point(20, 20);
        this->dgvCourses->Name = L"dgvCourses";
        this->dgvCourses->RowHeadersWidth = 62;
        this->dgvCourses->Size = System::Drawing::Size(600, 200);
        this->dgvCourses->TabIndex = 0;
        // 
        // Other UI Components Initialization
        // ...

        // TextBoxes for StartTime and EndTime
        this->txtStartTime->Location = System::Drawing::Point(260, 450);
        this->txtStartTime->Name = L"txtStartTime";
        this->txtStartTime->Size = System::Drawing::Size(200, 26);
        this->txtStartTime->TabIndex = 6;

        this->txtEndTime->Location = System::Drawing::Point(260, 490);
        this->txtEndTime->Name = L"txtEndTime";
        this->txtEndTime->Size = System::Drawing::Size(200, 26);
        this->txtEndTime->TabIndex = 7;

        // Labels for StartTime and EndTime
        this->label6->AutoSize = true;
        this->label6->Location = System::Drawing::Point(72, 456);
        this->label6->Name = L"label6";
        this->label6->Size = System::Drawing::Size(92, 20);
        this->label6->TabIndex = 14;
        this->label6->Text = L"START TIME";

        this->label7->AutoSize = true;
        this->label7->Location = System::Drawing::Point(72, 496);
        this->label7->Name = L"label7";
        this->label7->Size = System::Drawing::Size(87, 20);
        this->label7->TabIndex = 15;
        this->label7->Text = L"END TIME";

        this->Controls->Add(this->txtStartTime);
        this->Controls->Add(this->txtEndTime);
        this->Controls->Add(this->label6);
        this->Controls->Add(this->label7);
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
                String^ query = "INSERT INTO Courses (CourseName, Credits, Schedule, StartTime, EndTime, FacultyID) VALUES (@CourseName, @Credits, @Schedule, @StartTime, @EndTime, @FacultyID)";
                MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
                cmd->Parameters->AddWithValue("@CourseName", txtCourseName->Text);
                cmd->Parameters->AddWithValue("@Credits", Int32::Parse(txtCredits->Text));
                cmd->Parameters->AddWithValue("@Schedule", txtSchedule->Text);
                cmd->Parameters->AddWithValue("@StartTime", txtStartTime->Text);
                cmd->Parameters->AddWithValue("@EndTime", txtEndTime->Text);
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
                String^ query = "UPDATE Courses SET CourseName=@CourseName, Credits=@Credits, Schedule=@Schedule, StartTime=@StartTime, EndTime=@EndTime, FacultyID=@FacultyID WHERE CourseID=@CourseID";
                MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
                cmd->Parameters->AddWithValue("@CourseName", txtCourseName->Text);
                cmd->Parameters->AddWithValue("@Credits", Int32::Parse(txtCredits->Text));
                cmd->Parameters->AddWithValue("@Schedule", txtSchedule->Text);
                cmd->Parameters->AddWithValue("@StartTime", txtStartTime->Text);
                cmd->Parameters->AddWithValue("@EndTime", txtEndTime->Text);
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
    };
}
