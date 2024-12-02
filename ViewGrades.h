#pragma once

namespace StudentManagement {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient; // MySQL Database Interaction

	public ref class ViewGrades : public System::Windows::Forms::Form
	{
	public:
		ViewGrades(void)
		{
			InitializeComponent();
		}

	protected:
		~ViewGrades()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ gradess;
	private: System::Windows::Forms::Label^ subj;
	private: System::Windows::Forms::Label^ grade;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::TextBox^ grds;
	private: System::Windows::Forms::Label^ label1;



	private: System::Windows::Forms::TextBox^ textBox2;

	private: System::Windows::Forms::Button^ btnFetchGrade;

	protected:

	private: System::ComponentModel::Container^ components;
	private:
		MySqlConnection^ sqlConn;
		MySqlCommand^ sqlCmd;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label2;
		   String^ connectionString = "Server=localhost;Database=studentenroll;Uid=root;Pwd='';";

#pragma region Windows Form Designer generated code 
		void InitializeComponent(void)
		{
			this->gradess = (gcnew System::Windows::Forms::Label());
			this->subj = (gcnew System::Windows::Forms::Label());
			this->grade = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->grds = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->btnFetchGrade = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// gradess
			// 
			this->gradess->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 16, System::Drawing::FontStyle::Bold));
			this->gradess->Location = System::Drawing::Point(232, 9);
			this->gradess->Name = L"gradess";
			this->gradess->Size = System::Drawing::Size(296, 40);
			this->gradess->TabIndex = 31;
			this->gradess->Text = L"GRADES";
			this->gradess->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// subj
			// 
			this->subj->AutoSize = true;
			this->subj->Location = System::Drawing::Point(63, 104);
			this->subj->Name = L"subj";
			this->subj->Size = System::Drawing::Size(78, 20);
			this->subj->TabIndex = 30;
			this->subj->Text = L"COURSE";
			// 
			// grade
			// 
			this->grade->AutoSize = true;
			this->grade->Location = System::Drawing::Point(64, 315);
			this->grade->Name = L"grade";
			this->grade->Size = System::Drawing::Size(79, 20);
			this->grade->TabIndex = 29;
			this->grade->Text = L"GRADES";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(67, 159);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(428, 28);
			this->comboBox1->TabIndex = 17;
			// 
			// grds
			// 
			this->grds->Location = System::Drawing::Point(67, 365);
			this->grds->Name = L"grds";
			this->grds->Size = System::Drawing::Size(100, 26);
			this->grds->TabIndex = 18;
			this->grds->TextChanged += gcnew System::EventHandler(this, &ViewGrades::grds_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(64, 216);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(105, 20);
			this->label1->TabIndex = 28;
			this->label1->Text = L"STUDENT ID";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(67, 258);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 26);
			this->textBox2->TabIndex = 23;
			// 
			// btnFetchGrade
			// 
			this->btnFetchGrade->Location = System::Drawing::Point(67, 544);
			this->btnFetchGrade->Name = L"btnFetchGrade";
			this->btnFetchGrade->Size = System::Drawing::Size(100, 30);
			this->btnFetchGrade->TabIndex = 25;
			this->btnFetchGrade->Text = L"Fetch Grade";
			this->btnFetchGrade->Click += gcnew System::EventHandler(this, &ViewGrades::btnFetchGrade_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(564, 145);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(209, 110);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 32;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &ViewGrades::pictureBox1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(618, 104);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(55, 20);
			this->label2->TabIndex = 33;
			this->label2->Text = L"USER";
			// 
			// ViewGrades
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(979, 670);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->btnFetchGrade);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->grds);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->grade);
			this->Controls->Add(this->subj);
			this->Controls->Add(this->gradess);
			this->Name = L"ViewGrades";
			this->Text = L"ViewGrades";
			this->Load += gcnew System::EventHandler(this, &ViewGrades::ViewGrades_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		// Load available courses into comboBox1 and majors into comboBox2
	private: System::Void ViewGrades_Load(System::Object^ sender, System::EventArgs^ e)
	{
		sqlConn = gcnew MySqlConnection(connectionString);
		sqlConn->Open();

		// Fetch distinct course names into comboBox1
		sqlCmd = gcnew MySqlCommand("SELECT DISTINCT courseName FROM courses", sqlConn);
		MySqlDataReader^ reader = sqlCmd->ExecuteReader();

		while (reader->Read())
		{
			comboBox1->Items->Add(reader->GetString("courseName"));
		}

		reader->Close();

		// Fetch distinct majors into comboBox2
		sqlCmd = gcnew MySqlCommand("SELECT DISTINCT major FROM Majors", sqlConn);
		reader = sqlCmd->ExecuteReader();

		this->pictureBox1->Image = Image::FromFile("user.jpg");

		while (reader->Read())
		{
		}

		reader->Close();
		sqlConn->Close();
	}

		   // Fetch student grades when "Fetch Grade" button is clicked
	private: System::Void btnFetchGrade_Click(System::Object^ sender, System::EventArgs^ e)
	{
		sqlConn = gcnew MySqlConnection(connectionString);
		sqlConn->Open();

		// SQL to get the grade for the selected course and student
		String^ query = "SELECT E.grade FROM Enrollments E "
			"JOIN Courses C ON E.courseID = C.courseID "
			"WHERE C.courseName = @courseName AND E.studentID = @studentID";
		sqlCmd = gcnew MySqlCommand(query, sqlConn);
		sqlCmd->Parameters->AddWithValue("@courseName", comboBox1->SelectedItem->ToString());
		sqlCmd->Parameters->AddWithValue("@studentID", textBox2->Text);

		MySqlDataReader^ reader = sqlCmd->ExecuteReader();

		if (reader->Read())
		{
			grds->Text = reader->GetString("grade");
		}
		else
		{
			MessageBox::Show("Grade not found for this student.");
		}

		reader->Close();
	}
	private: System::Void grds_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {

}
};
}
