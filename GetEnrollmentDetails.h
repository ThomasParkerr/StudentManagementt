#pragma once
using namespace MySql::Data::MySqlClient;

namespace StudentManagement {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GetEnrollmentDetails
	/// </summary>
	public ref class GetEnrollmentDetails : public System::Windows::Forms::Form
	{
	public:
		GetEnrollmentDetails(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GetEnrollmentDetails()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ gradess;

	private: System::Windows::Forms::TextBox^ textBoxEnrollmentID;
	private: System::Windows::Forms::TextBox^ textBoxCourseID;
	private: System::Windows::Forms::TextBox^ textBoxSemester;
	private: System::Windows::Forms::TextBox^ textBoxGrade;
	private: System::Windows::Forms::TextBox^ textBoxFirstName;  // Added First Name TextBox
	private: System::Windows::Forms::TextBox^ textBoxLastName;   // Added Last Name TextBox
	private: System::Windows::Forms::TextBox^ textBoxCourseName; // Added Course Name TextBox
	private: System::Windows::Forms::Button^ buttonFetchDetails; // Button to fetch enrollment details

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;
		MySqlConnection^ sqlConn;   // MySQL connection object
		MySqlCommand^ sqlCmd;       // MySQL command object
		MySqlDataReader^ sqlReader; // MySQL data reader object
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ labelFirstName;   // Added label for First Name
	private: System::Windows::Forms::Label^ labelLastName;    // Added label for Last Name
	private: System::Windows::Forms::Label^ labelCourseName;  // Added label for Course Name

		   String^ connectionString = "Server=localhost;Database=studentenroll;Uid=root;Pwd='';";

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->label5 = (gcnew System::Windows::Forms::Label());
			   this->gradess = (gcnew System::Windows::Forms::Label());
			   this->textBoxEnrollmentID = (gcnew System::Windows::Forms::TextBox());
			   this->textBoxCourseID = (gcnew System::Windows::Forms::TextBox());
			   this->textBoxSemester = (gcnew System::Windows::Forms::TextBox());
			   this->textBoxGrade = (gcnew System::Windows::Forms::TextBox());
			   this->buttonFetchDetails = (gcnew System::Windows::Forms::Button());
			   this->label6 = (gcnew System::Windows::Forms::Label());
			   this->label7 = (gcnew System::Windows::Forms::Label());
			   this->labelFirstName = (gcnew System::Windows::Forms::Label());
			   this->labelLastName = (gcnew System::Windows::Forms::Label());
			   this->labelCourseName = (gcnew System::Windows::Forms::Label());
			   this->textBoxFirstName = (gcnew System::Windows::Forms::TextBox());
			   this->textBoxLastName = (gcnew System::Windows::Forms::TextBox());
			   this->textBoxCourseName = (gcnew System::Windows::Forms::TextBox());
			   this->SuspendLayout();
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Location = System::Drawing::Point(396, 277);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(105, 20);
			   this->label1->TabIndex = 0;
			   this->label1->Text = L"STUDENT ID";
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Location = System::Drawing::Point(12, 181);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(138, 20);
			   this->label2->TabIndex = 1;
			   this->label2->Text = L"ENROLLMENT ID";
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Location = System::Drawing::Point(393, 335);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(99, 20);
			   this->label3->TabIndex = 2;
			   this->label3->Text = L"COURSE ID";
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->Location = System::Drawing::Point(396, 427);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(98, 20);
			   this->label4->TabIndex = 3;
			   this->label4->Text = L"SEMESTER";
			   // 
			   // label5
			   // 
			   this->label5->AutoSize = true;
			   this->label5->Location = System::Drawing::Point(394, 529);
			   this->label5->Name = L"label5";
			   this->label5->Size = System::Drawing::Size(68, 20);
			   this->label5->TabIndex = 4;
			   this->label5->Text = L"GRADE";
			   // 
			   // gradess
			   // 
			   this->gradess->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->gradess->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 16, System::Drawing::FontStyle::Bold));
			   this->gradess->Location = System::Drawing::Point(180, 44);
			   this->gradess->Name = L"gradess";
			   this->gradess->Size = System::Drawing::Size(722, 40);
			   this->gradess->TabIndex = 16;
			   this->gradess->Text = L"ENROLLMENT DETAILS";
			   this->gradess->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   // 
			   // textBoxEnrollmentID
			   // 
			   this->textBoxEnrollmentID->Location = System::Drawing::Point(12, 224);
			   this->textBoxEnrollmentID->Name = L"textBoxEnrollmentID";
			   this->textBoxEnrollmentID->Size = System::Drawing::Size(196, 26);
			   this->textBoxEnrollmentID->TabIndex = 6;
			   // 
			   // textBoxCourseID
			   // 
			   this->textBoxCourseID->Location = System::Drawing::Point(398, 375);
			   this->textBoxCourseID->Name = L"textBoxCourseID";
			   this->textBoxCourseID->Size = System::Drawing::Size(540, 26);
			   this->textBoxCourseID->TabIndex = 7;
			   // 
			   // textBoxSemester
			   // 
			   this->textBoxSemester->Location = System::Drawing::Point(398, 467);
			   this->textBoxSemester->Name = L"textBoxSemester";
			   this->textBoxSemester->Size = System::Drawing::Size(540, 26);
			   this->textBoxSemester->TabIndex = 8;
			   // 
			   // textBoxGrade
			   // 
			   this->textBoxGrade->Location = System::Drawing::Point(398, 559);
			   this->textBoxGrade->Name = L"textBoxGrade";
			   this->textBoxGrade->Size = System::Drawing::Size(540, 26);
			   this->textBoxGrade->TabIndex = 9;
			   // 
			   // buttonFetchDetails
			   // 
			   this->buttonFetchDetails->Location = System::Drawing::Point(12, 520);
			   this->buttonFetchDetails->Name = L"buttonFetchDetails";
			   this->buttonFetchDetails->Size = System::Drawing::Size(143, 41);
			   this->buttonFetchDetails->TabIndex = 10;
			   this->buttonFetchDetails->Text = L"Fetch Details";
			   this->buttonFetchDetails->UseVisualStyleBackColor = true;
			   this->buttonFetchDetails->Click += gcnew System::EventHandler(this, &GetEnrollmentDetails::buttonFetchDetails_Click);
			   // 
			   // label6
			   // 
			   this->label6->Location = System::Drawing::Point(0, 0);
			   this->label6->Name = L"label6";
			   this->label6->Size = System::Drawing::Size(100, 23);
			   this->label6->TabIndex = 0;
			   // 
			   // label7
			   // 
			   this->label7->Location = System::Drawing::Point(0, 0);
			   this->label7->Name = L"label7";
			   this->label7->Size = System::Drawing::Size(100, 23);
			   this->label7->TabIndex = 0;
			   // 
			   // labelFirstName
			   // 
			   this->labelFirstName->AutoSize = true;
			   this->labelFirstName->Location = System::Drawing::Point(396, 193);
			   this->labelFirstName->Name = L"labelFirstName";
			   this->labelFirstName->Size = System::Drawing::Size(106, 20);
			   this->labelFirstName->TabIndex = 11;
			   this->labelFirstName->Text = L"FIRST NAME";
			   // 
			   // labelLastName
			   // 
			   this->labelLastName->AutoSize = true;
			   this->labelLastName->Location = System::Drawing::Point(396, 233);
			   this->labelLastName->Name = L"labelLastName";
			   this->labelLastName->Size = System::Drawing::Size(99, 20);
			   this->labelLastName->TabIndex = 12;
			   this->labelLastName->Text = L"LAST NAME";
			   // 
			   // labelCourseName
			   // 
			   this->labelCourseName->AutoSize = true;
			   this->labelCourseName->Location = System::Drawing::Point(396, 273);
			   this->labelCourseName->Name = L"labelCourseName";
			   this->labelCourseName->Size = System::Drawing::Size(128, 20);
			   this->labelCourseName->TabIndex = 13;
			   this->labelCourseName->Text = L"COURSE NAME";
			   // 
			   // textBoxFirstName
			   // 
			   this->textBoxFirstName->Location = System::Drawing::Point(561, 190);
			   this->textBoxFirstName->Name = L"textBoxFirstName";
			   this->textBoxFirstName->Size = System::Drawing::Size(377, 26);
			   this->textBoxFirstName->TabIndex = 14;
			   // 
			   // textBoxLastName
			   // 
			   this->textBoxLastName->Location = System::Drawing::Point(561, 234);
			   this->textBoxLastName->Name = L"textBoxLastName";
			   this->textBoxLastName->Size = System::Drawing::Size(377, 26);
			   this->textBoxLastName->TabIndex = 15;
			   // 
			   // textBoxCourseName
			   // 
			   this->textBoxCourseName->Location = System::Drawing::Point(561, 271);
			   this->textBoxCourseName->Name = L"textBoxCourseName";
			   this->textBoxCourseName->Size = System::Drawing::Size(377, 26);
			   this->textBoxCourseName->TabIndex = 16;
			   // 
			   // GetEnrollmentDetails
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1131, 806);
			   this->Controls->Add(this->textBoxCourseName);
			   this->Controls->Add(this->textBoxLastName);
			   this->Controls->Add(this->textBoxFirstName);
			   this->Controls->Add(this->labelCourseName);
			   this->Controls->Add(this->labelLastName);
			   this->Controls->Add(this->labelFirstName);
			   this->Controls->Add(this->buttonFetchDetails);
			   this->Controls->Add(this->textBoxGrade);
			   this->Controls->Add(this->textBoxSemester);
			   this->Controls->Add(this->textBoxCourseID);
			   this->Controls->Add(this->textBoxEnrollmentID);
			   this->Controls->Add(this->gradess);
			   this->Controls->Add(this->label5);
			   this->Controls->Add(this->label4);
			   this->Controls->Add(this->label3);
			   this->Controls->Add(this->label2);
			   this->Controls->Add(this->label1);
			   this->Name = L"GetEnrollmentDetails";
			   this->Text = L"Enrollment Details";
			   this->Load += gcnew System::EventHandler(this, &GetEnrollmentDetails::GetEnrollmentDetails_Load);
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

	private: System::Void buttonFetchDetails_Click(System::Object^ sender, System::EventArgs^ e) {
		// MySQL query to fetch details from the database
		sqlConn = gcnew MySqlConnection(connectionString);
		sqlConn->Open();

		// Assuming you are passing the Enrollment ID to get the student details
		sqlCmd = gcnew MySqlCommand(
			"SELECT users.firstName, users.lastName, courses.courseName, enrollments.studentID, enrollments.courseID, enrollments.semester, enrollments.grade "
			"FROM enrollments "
			"INNER JOIN students ON enrollments.studentID = students.studentID "
			"INNER JOIN users ON students.userID = users.userID "
			"INNER JOIN courses ON enrollments.courseID = courses.courseID "
			"WHERE enrollments.enrollmentID = @enrollmentID", sqlConn);

		sqlCmd->Parameters->AddWithValue("@enrollmentID", textBoxEnrollmentID->Text);

		sqlReader = sqlCmd->ExecuteReader();

		if (sqlReader->Read()) {
			// Set values from the database to the textboxes
			textBoxCourseID->Text = sqlReader["courseID"]->ToString();
			textBoxSemester->Text = sqlReader["semester"]->ToString();
			textBoxGrade->Text = sqlReader["grade"]->ToString();

			// Display fetched First Name, Last Name, and Course Name
			textBoxFirstName->Text = sqlReader["firstName"]->ToString();
			textBoxLastName->Text = sqlReader["lastName"]->ToString();
			textBoxCourseName->Text = sqlReader["courseName"]->ToString();
		}
		else {
			MessageBox::Show("Enrollment ID not found.");
		}

		sqlConn->Close();
	}
	private: System::Void GetEnrollmentDetails_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}