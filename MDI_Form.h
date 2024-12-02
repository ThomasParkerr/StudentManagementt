#pragma once
#include "Logout.h"
#include "CourseRegistrationForm.h"
#include "ViewGrades.h"
#include "SeeRoster.h"
#include "AssignFaculty.h"
#include "RegisterStudent.h"
#include "GetEnrollmentDetails.h"
#include "EnterGrades.h"
#include "PayFees.h"
#include "ViewSchedule.h"
#include "UpdateProfile.h"
#include "AdminManage.h"
#include "ManageFinances.h"
#include "GenerateReports.h"
#include "AccessProfile.h"
#include "ManageTranscript.h"

namespace StudentManagement {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient;

    public ref class MDI_Form : public System::Windows::Forms::Form
    {
        String^ userID;
    private: System::Windows::Forms::ToolStripMenuItem^ payFeesToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^ updateProfileToolStripMenuItem;

    private: System::Windows::Forms::ToolStripMenuItem^ manageCoursesToolStripMenuItem1;
    private: System::Windows::Forms::ToolStripMenuItem^ manageFinancialsToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^ generateReportsToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^ logoutToolStripMenuItem1;
    private: System::Windows::Forms::ToolStripMenuItem^ logoutToolStripMenuItem3;
    private: System::Windows::Forms::ToolStripMenuItem^ logoutToolStripMenuItem4;
    private: System::Windows::Forms::ToolStripMenuItem^ logoutToolStripMenuItem5;
    private: System::Windows::Forms::ToolStripMenuItem^ transcriptToolStripMenuItem;
           int userRole;  // Change to int to match roleID in database

    public:
        MDI_Form(String^ userID)
        {
            this->userID = userID;
            InitializeComponent();
            ConnectToDatabase();  // Connect to database and set user role
            UpdateMenuBasedOnRole();  // Update menu based on user role
        }

    protected:
        ~MDI_Form()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::ToolStripMenuItem^ enrollToolStripMenuItem;
        System::Windows::Forms::MenuStrip^ menuStrip1;
        System::ComponentModel::IContainer^ components;

        // MySQL-related members
        MySqlConnection^ sqlConn;
        MySqlCommand^ sqlCmd;
        MySqlDataReader^ sqlRd;

    private: System::Windows::Forms::ToolStripMenuItem^ studentToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^ viewGradesToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^ courseRegistrationToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^ facultyToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^ enterGradesToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^ seeRosterToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^ adminToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^ assignFacultyToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^ registerStudentToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^ getEnrollmentDetailsToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^ logoutToolStripMenuItem;

    private: System::Windows::Forms::ToolStripMenuItem^ logoutToolStripMenuItem2;

           // Method to update the menu items based on user role
           void UpdateMenuBasedOnRole()
           {
               if (userRole == 1)  // Assume 1 is for student
               {
                   studentToolStripMenuItem->Visible = true;
                   facultyToolStripMenuItem->Visible = false;
                   adminToolStripMenuItem->Visible = false;
               }
               else if (userRole == 2)  // Assume 2 is for faculty
               {
                   studentToolStripMenuItem->Visible = false;
                   facultyToolStripMenuItem->Visible = true;
                   adminToolStripMenuItem->Visible = false;
               }
               else if (userRole == 3)  // Assume 3 is for admin
               {
                   studentToolStripMenuItem->Visible = false;
                   facultyToolStripMenuItem->Visible = false;
                   adminToolStripMenuItem->Visible = true;
               }
           }

           // MySQL connection for verifying login and setting role
           void ConnectToDatabase()
           {
               String^ connectionString = "Server=localhost;Database=studentenroll;Uid=root;Pwd='';";
               try
               {
                   sqlConn = gcnew MySqlConnection(connectionString);
                   sqlConn->Open();

                   // Query to get the user's role based on userID
                   String^ query = "SELECT roleID FROM users WHERE userID = @userID";
                   sqlCmd = gcnew MySqlCommand(query, sqlConn);
                   sqlCmd->Parameters->AddWithValue("@userID", userID);

                   sqlRd = sqlCmd->ExecuteReader();
                   if (sqlRd->Read())
                   {
                       userRole = sqlRd["roleID"]->ToString() != nullptr ? Convert::ToInt32(sqlRd["roleID"]) : 0;
                   }
                   else
                   {
                       MessageBox::Show("Invalid user.");
                   }

                   sqlConn->Close();
               }
               catch (Exception^ ex)
               {
                   MessageBox::Show(ex->Message);
               }
           }

#pragma region Windows Form Designer generated code
           void InitializeComponent(void)
           {
               this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
               this->studentToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->viewGradesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->courseRegistrationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->logoutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->payFeesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->logoutToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->logoutToolStripMenuItem5 = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->facultyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->enterGradesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->seeRosterToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->updateProfileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->logoutToolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->adminToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->assignFacultyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->registerStudentToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->getEnrollmentDetailsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->manageCoursesToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->manageFinancialsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->generateReportsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->logoutToolStripMenuItem4 = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->logoutToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->transcriptToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->menuStrip1->SuspendLayout();
               this->SuspendLayout();
               // 
               // menuStrip1
               // 
               this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
               this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
               this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
                   this->studentToolStripMenuItem,
                       this->facultyToolStripMenuItem, this->adminToolStripMenuItem
               });
               this->menuStrip1->Location = System::Drawing::Point(0, 0);
               this->menuStrip1->Name = L"menuStrip1";
               this->menuStrip1->Size = System::Drawing::Size(778, 33);
               this->menuStrip1->TabIndex = 0;
               this->menuStrip1->Text = L"menuStrip1";
               // 
               // studentToolStripMenuItem
               // 
               this->studentToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
                   this->viewGradesToolStripMenuItem,
                       this->courseRegistrationToolStripMenuItem, this->logoutToolStripMenuItem, this->payFeesToolStripMenuItem, this->logoutToolStripMenuItem1,
                       this->logoutToolStripMenuItem5, this->transcriptToolStripMenuItem
               });
               this->studentToolStripMenuItem->Name = L"studentToolStripMenuItem";
               this->studentToolStripMenuItem->Size = System::Drawing::Size(89, 29);
               this->studentToolStripMenuItem->Text = L"Student";
               // 
               // viewGradesToolStripMenuItem
               // 
               this->viewGradesToolStripMenuItem->Name = L"viewGradesToolStripMenuItem";
               this->viewGradesToolStripMenuItem->Size = System::Drawing::Size(268, 34);
               this->viewGradesToolStripMenuItem->Text = L"ViewGrades";
               this->viewGradesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MDI_Form::viewGradesToolStripMenuItem_Click);
               // 
               // courseRegistrationToolStripMenuItem
               // 
               this->courseRegistrationToolStripMenuItem->Name = L"courseRegistrationToolStripMenuItem";
               this->courseRegistrationToolStripMenuItem->Size = System::Drawing::Size(268, 34);
               this->courseRegistrationToolStripMenuItem->Text = L"Course Registration";
               this->courseRegistrationToolStripMenuItem->Click += gcnew System::EventHandler(this, &MDI_Form::courseRegistrationToolStripMenuItem_Click);
               // 
               // logoutToolStripMenuItem
               // 
               this->logoutToolStripMenuItem->Name = L"logoutToolStripMenuItem";
               this->logoutToolStripMenuItem->Size = System::Drawing::Size(268, 34);
               this->logoutToolStripMenuItem->Text = L"PayFees";
               this->logoutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MDI_Form::logoutToolStripMenuItem_Click);
               // 
               // payFeesToolStripMenuItem
               // 
               this->payFeesToolStripMenuItem->Name = L"payFeesToolStripMenuItem";
               this->payFeesToolStripMenuItem->Size = System::Drawing::Size(268, 34);
               this->payFeesToolStripMenuItem->Text = L"ViewSchedule";
               this->payFeesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MDI_Form::payFeesToolStripMenuItem_Click);
               // 
               // logoutToolStripMenuItem1
               // 
               this->logoutToolStripMenuItem1->Name = L"logoutToolStripMenuItem1";
               this->logoutToolStripMenuItem1->Size = System::Drawing::Size(268, 34);
               this->logoutToolStripMenuItem1->Text = L"AccessProfile";
               this->logoutToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MDI_Form::logoutToolStripMenuItem1_Click);
               // 
               // logoutToolStripMenuItem5
               // 
               this->logoutToolStripMenuItem5->Name = L"logoutToolStripMenuItem5";
               this->logoutToolStripMenuItem5->Size = System::Drawing::Size(268, 34);
               this->logoutToolStripMenuItem5->Text = L"Logout";
               this->logoutToolStripMenuItem5->Click += gcnew System::EventHandler(this, &MDI_Form::logoutToolStripMenuItem5_Click);
               // 
               // facultyToolStripMenuItem
               // 
               this->facultyToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
                   this->enterGradesToolStripMenuItem,
                       this->seeRosterToolStripMenuItem, this->updateProfileToolStripMenuItem, this->logoutToolStripMenuItem3
               });
               this->facultyToolStripMenuItem->Name = L"facultyToolStripMenuItem";
               this->facultyToolStripMenuItem->Size = System::Drawing::Size(82, 29);
               this->facultyToolStripMenuItem->Text = L"Faculty";
               // 
               // enterGradesToolStripMenuItem
               // 
               this->enterGradesToolStripMenuItem->Name = L"enterGradesToolStripMenuItem";
               this->enterGradesToolStripMenuItem->Size = System::Drawing::Size(270, 34);
               this->enterGradesToolStripMenuItem->Text = L"Enter Grades";
               this->enterGradesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MDI_Form::enterGradesToolStripMenuItem_Click);
               // 
               // seeRosterToolStripMenuItem
               // 
               this->seeRosterToolStripMenuItem->Name = L"seeRosterToolStripMenuItem";
               this->seeRosterToolStripMenuItem->Size = System::Drawing::Size(270, 34);
               this->seeRosterToolStripMenuItem->Text = L"See Roster";
               this->seeRosterToolStripMenuItem->Click += gcnew System::EventHandler(this, &MDI_Form::seeRosterToolStripMenuItem_Click);
               // 
               // updateProfileToolStripMenuItem
               // 
               this->updateProfileToolStripMenuItem->Name = L"updateProfileToolStripMenuItem";
               this->updateProfileToolStripMenuItem->Size = System::Drawing::Size(270, 34);
               this->updateProfileToolStripMenuItem->Text = L"Update Profile";
               this->updateProfileToolStripMenuItem->Click += gcnew System::EventHandler(this, &MDI_Form::updateProfileToolStripMenuItem_Click);
               // 
               // logoutToolStripMenuItem3
               // 
               this->logoutToolStripMenuItem3->Name = L"logoutToolStripMenuItem3";
               this->logoutToolStripMenuItem3->Size = System::Drawing::Size(270, 34);
               this->logoutToolStripMenuItem3->Text = L"Logout";
               this->logoutToolStripMenuItem3->Click += gcnew System::EventHandler(this, &MDI_Form::logoutToolStripMenuItem3_Click);
               // 
               // adminToolStripMenuItem
               // 
               this->adminToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
                   this->assignFacultyToolStripMenuItem,
                       this->registerStudentToolStripMenuItem, this->getEnrollmentDetailsToolStripMenuItem, this->manageCoursesToolStripMenuItem1, this->manageFinancialsToolStripMenuItem,
                       this->generateReportsToolStripMenuItem, this->logoutToolStripMenuItem4
               });
               this->adminToolStripMenuItem->Name = L"adminToolStripMenuItem";
               this->adminToolStripMenuItem->Size = System::Drawing::Size(81, 29);
               this->adminToolStripMenuItem->Text = L"Admin";
               // 
               // assignFacultyToolStripMenuItem
               // 
               this->assignFacultyToolStripMenuItem->Name = L"assignFacultyToolStripMenuItem";
               this->assignFacultyToolStripMenuItem->Size = System::Drawing::Size(289, 34);
               this->assignFacultyToolStripMenuItem->Text = L"Assign Faculty";
               this->assignFacultyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MDI_Form::assignFacultyToolStripMenuItem_Click);
               // 
               // registerStudentToolStripMenuItem
               // 
               this->registerStudentToolStripMenuItem->Name = L"registerStudentToolStripMenuItem";
               this->registerStudentToolStripMenuItem->Size = System::Drawing::Size(289, 34);
               this->registerStudentToolStripMenuItem->Text = L"Register Student";
               this->registerStudentToolStripMenuItem->Click += gcnew System::EventHandler(this, &MDI_Form::registerStudentToolStripMenuItem_Click);
               // 
               // getEnrollmentDetailsToolStripMenuItem
               // 
               this->getEnrollmentDetailsToolStripMenuItem->Name = L"getEnrollmentDetailsToolStripMenuItem";
               this->getEnrollmentDetailsToolStripMenuItem->Size = System::Drawing::Size(289, 34);
               this->getEnrollmentDetailsToolStripMenuItem->Text = L"Get Enrollment Details";
               this->getEnrollmentDetailsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MDI_Form::getEnrollmentDetailsToolStripMenuItem_Click);
               // 
               // manageCoursesToolStripMenuItem1
               // 
               this->manageCoursesToolStripMenuItem1->Name = L"manageCoursesToolStripMenuItem1";
               this->manageCoursesToolStripMenuItem1->Size = System::Drawing::Size(289, 34);
               this->manageCoursesToolStripMenuItem1->Text = L"Manage Courses";
               this->manageCoursesToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MDI_Form::manageCoursesToolStripMenuItem1_Click);
               // 
               // manageFinancialsToolStripMenuItem
               // 
               this->manageFinancialsToolStripMenuItem->Name = L"manageFinancialsToolStripMenuItem";
               this->manageFinancialsToolStripMenuItem->Size = System::Drawing::Size(289, 34);
               this->manageFinancialsToolStripMenuItem->Text = L"ManageFinancials";
               this->manageFinancialsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MDI_Form::manageFinancialsToolStripMenuItem_Click);
               // 
               // generateReportsToolStripMenuItem
               // 
               this->generateReportsToolStripMenuItem->Name = L"generateReportsToolStripMenuItem";
               this->generateReportsToolStripMenuItem->Size = System::Drawing::Size(289, 34);
               this->generateReportsToolStripMenuItem->Text = L"Generate Reports";
               this->generateReportsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MDI_Form::generateReportsToolStripMenuItem_Click);
               // 
               // logoutToolStripMenuItem4
               // 
               this->logoutToolStripMenuItem4->Name = L"logoutToolStripMenuItem4";
               this->logoutToolStripMenuItem4->Size = System::Drawing::Size(289, 34);
               this->logoutToolStripMenuItem4->Text = L"Logout";
               this->logoutToolStripMenuItem4->Click += gcnew System::EventHandler(this, &MDI_Form::logoutToolStripMenuItem4_Click);
               // 
               // logoutToolStripMenuItem2
               // 
               this->logoutToolStripMenuItem2->Name = L"logoutToolStripMenuItem2";
               this->logoutToolStripMenuItem2->Size = System::Drawing::Size(32, 19);
               // 
               // transcriptToolStripMenuItem
               // 
               this->transcriptToolStripMenuItem->Name = L"transcriptToolStripMenuItem";
               this->transcriptToolStripMenuItem->Size = System::Drawing::Size(270, 34);
               this->transcriptToolStripMenuItem->Text = L"Transcript";
               this->transcriptToolStripMenuItem->Click += gcnew System::EventHandler(this, &MDI_Form::transcriptToolStripMenuItem_Click);
               // 
               // MDI_Form
               // 
               this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
               this->ClientSize = System::Drawing::Size(778, 587);
               this->Controls->Add(this->menuStrip1);
               this->MainMenuStrip = this->menuStrip1;
               this->Name = L"MDI_Form";
               this->Text = L"MDI_Form";
               this->menuStrip1->ResumeLayout(false);
               this->menuStrip1->PerformLayout();
               this->ResumeLayout(false);
               this->PerformLayout();

           }
    private: System::Void viewGradesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
        this->Hide();
        ViewGrades^ registerStudentForm = gcnew ViewGrades();
        registerStudentForm->ShowDialog();
        this->Show();
    }
private: System::Void courseRegistrationToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    this->Hide();
    Enroll^ registerStudentForm = gcnew Enroll();
    registerStudentForm->ShowDialog();
    this->Show();
}
private: System::Void logoutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    this->Hide();
    PayFees^ registerStudentForm = gcnew PayFees();
    registerStudentForm->ShowDialog();
    this->Show();
}
private: System::Void enterGradesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    this->Hide();
    GRADES^ registerStudentForm = gcnew GRADES();
    registerStudentForm->ShowDialog();
    this->Show();
}
private: System::Void seeRosterToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    this->Hide();
    SeeRoster^ registerStudentForm = gcnew SeeRoster();
    registerStudentForm->ShowDialog();
    this->Show();
}
private: System::Void assignFacultyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    this->Hide();
    AssignFaculty^ registerStudentForm = gcnew AssignFaculty();
    registerStudentForm->ShowDialog();
    this->Show();
    
}
private: System::Void registerStudentToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    this->Hide();
    RegisterStudent^ registerStudentForm = gcnew RegisterStudent();
    registerStudentForm->ShowDialog();
    this->Show();
}
private: System::Void getEnrollmentDetailsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    this->Hide();
    GetEnrollmentDetails^ registerStudentForm = gcnew GetEnrollmentDetails();
    registerStudentForm->ShowDialog();
    this->Show();
}
private: System::Void payFeesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    this->Hide();
    ViewSchedule^ registerStudentForm = gcnew ViewSchedule();
    registerStudentForm->ShowDialog();
    this->Show();

}
private: System::Void updateProfileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    this->Hide();
    FacultyProfile^ registerStudentForm = gcnew FacultyProfile();
    registerStudentForm->ShowDialog();
    this->Show();

}
private: System::Void manageCoursesToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
    this->Hide();
    AdminManage^ registerStudentForm = gcnew AdminManage();
    registerStudentForm->ShowDialog();
    this->Show();

}
private: System::Void manageFinancialsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    this->Hide();
    ManageFinances^ registerStudentForm = gcnew ManageFinances();
    registerStudentForm->ShowDialog();
    this->Show();

}
private: System::Void generateReportsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    this->Hide();
    GenerateReports^ registerStudentForm = gcnew GenerateReports();
    registerStudentForm->ShowDialog();
    this->Show();
}
private: System::Void logoutToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
    this->Hide();
    GetUserDetails^ registerStudentForm = gcnew GetUserDetails();
    registerStudentForm->ShowDialog();
    this->Show();
}
private: System::Void logoutToolStripMenuItem3_Click(System::Object^ sender, System::EventArgs^ e) {
    this->Hide();
    LogoutForm^ registerStudentForm = gcnew LogoutForm();
    registerStudentForm->ShowDialog();
    this->Show();
}
private: System::Void logoutToolStripMenuItem4_Click(System::Object^ sender, System::EventArgs^ e) {
    this->Hide();
    LogoutForm^ registerStudentForm = gcnew LogoutForm();
    registerStudentForm->ShowDialog();
    this->Show();
}
private: System::Void logoutToolStripMenuItem5_Click(System::Object^ sender, System::EventArgs^ e) {
    this->Hide();
    LogoutForm^ registerStudentForm = gcnew LogoutForm();
    registerStudentForm->ShowDialog();
    this->Show();

}
private: System::Void manageCoursesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    this->Hide();
    LogoutForm^ registerStudentForm = gcnew LogoutForm();
    registerStudentForm->ShowDialog();
    this->Show();

}
private: System::Void transcriptToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    this->Hide();
    ManageTranscript^ registerStudentForm = gcnew ManageTranscript();
    registerStudentForm->ShowDialog();
    this->Show();
}
};
}
