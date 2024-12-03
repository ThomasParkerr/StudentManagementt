CREATE DATABASE studentenroll;
USE studentenroll;

-- Create majors table first as it is referenced by students
CREATE TABLE majors (
    majorID INT(11) PRIMARY KEY AUTO_INCREMENT,
    major VARCHAR(100)
);

-- Create roles table
CREATE TABLE roles (
    roleID INT(11) PRIMARY KEY AUTO_INCREMENT,
    roleName VARCHAR(50)
);

-- Create users table
CREATE TABLE users (
    userID INT(11) PRIMARY KEY AUTO_INCREMENT,
    firstName VARCHAR(100),
    lastName VARCHAR(100),
    email VARCHAR(100),
    password VARCHAR(255),
    roleID INT(11),
    FOREIGN KEY (roleID) REFERENCES roles(roleID)
);

-- Create faculty table which references users
CREATE TABLE faculty (
    facultyID INT(11) PRIMARY KEY AUTO_INCREMENT,
    userID INT(11),
    department VARCHAR(100),
    date_of_appointment DATE,
    phone VARCHAR(15),
    email VARCHAR(100),
    address VARCHAR(255),
    date_of_birth DATE,
    FOREIGN KEY (userID) REFERENCES users(userID)
);

-- Create students table which references both users and majors
CREATE TABLE students (
    studentID INT(11) PRIMARY KEY AUTO_INCREMENT,
    userID INT(11),
    majorID INT(11),
    dob DATE,
    enrollmentDate DATE,
    fees_paid VARCHAR(5),
    FOREIGN KEY (userID) REFERENCES users(userID),
    FOREIGN KEY (majorID) REFERENCES majors(majorID)
);

-- Create courses table which references faculty
CREATE TABLE courses (
    courseID INT(11) PRIMARY KEY AUTO_INCREMENT,
    courseName VARCHAR(255),
    credits INT(11),
    schedule VARCHAR(50),
    facultyID INT(11),
    FOREIGN KEY (facultyID) REFERENCES faculty(facultyID),
    start_time VARCHAR(50),
    end_time VARCHAR(50)
);

-- Create enrollments table which references students and courses
CREATE TABLE enrollments (
    enrollmentID INT(11) PRIMARY KEY AUTO_INCREMENT,
    studentID INT(11),
    courseID INT(11),
    semester VARCHAR(50),
    grade VARCHAR(2),
    FOREIGN KEY (studentID) REFERENCES students(studentID),
    FOREIGN KEY (courseID) REFERENCES courses(courseID)
);

-- Create administrators table which references users
CREATE TABLE administrators (
    adminID INT(11) PRIMARY KEY AUTO_INCREMENT,
    userID INT(11),
    FOREIGN KEY (userID) REFERENCES users(userID)
);

-- Create fee_payments table
CREATE TABLE fee_payments (
    id INT AUTO_INCREMENT PRIMARY KEY,
    studentID INT NOT NULL,
    fee_type ENUM('Tuition', 'LabFee', 'LibraryFee', 'HostelFee') NOT NULL,
    fee_amount DECIMAL(10, 2) NOT NULL,
    FOREIGN KEY (studentID) REFERENCES students(studentID)
);

-- Insert into majors table
INSERT INTO majors (major) VALUES
('Computer Science'),
('Mathematics'),
('Physics'),
('Biology'),
('Chemistry'),
('Literature'),
('History'),
('Psychology'),
('Philosophy'),
('Engineering');

-- Insert into roles table
INSERT INTO roles (roleName) VALUES
('Student'),
('Faculty'),
('Administrator');

-- Insert into users table
INSERT INTO users (firstName, lastName, email, password, roleID) VALUES
('John', 'Doe', 'john.doe@example.com', 'password123', 3),
('Jane', 'Smith', 'jane.smith@example.com', 'password123', 2),
('Alice', 'Johnson', 'alice.johnson@example.com', 'password123', 1),
('Bob', 'Williams', 'bob.williams@example.com', 'password123', 1),
('Charlie', 'Brown', 'charlie.brown@example.com', 'password123', 3),
('David', 'Taylor', 'david.taylor@example.com', 'password123', 2),
('Emma', 'Wilson', 'emma.wilson@example.com', 'password123', 1),
('Frank', 'Miller', 'frank.miller@example.com', 'password123', 1),
('Grace', 'Davis', 'grace.davis@example.com', 'password123', 3),
('Helen', 'Martinez', 'helen.martinez@example.com', 'password123', 2);

-- Insert into administrators table
INSERT INTO administrators (userID) VALUES
(1),
(5),
(9);

-- Insert into faculty table
INSERT INTO faculty (userID, department, date_of_appointment, phone, email, address, date_of_birth) VALUES
(2, 'Physics', '2019-03-01', '555-123-4567', 'jane.smith@university.edu', '789 Science Rd, Brighttown', '1983-11-10'),
(6, 'History', '2020-10-10', '555-567-8901', 'david.taylor@university.edu', '404 Past Rd, Histown', '1990-01-22'),
(10, 'Literature', '2021-05-22', '555-234-5678', 'helen.martinez@university.edu', '202 Literature Ave, Oakville', '1992-08-25');

-- Insert into students table
INSERT INTO students (userID, majorID, dob, enrollmentDate, fees_paid) VALUES
(3, 1, '2000-01-15', '2018-09-01', 'Yes'),
(4, 2, '1999-02-22', '2017-09-01', 'No'),
(7, 3, '2001-03-30', '2020-09-01', 'Yes'),
(8, 4, '2000-04-10', '2019-09-01', 'Yes');

-- Insert into courses table
INSERT INTO courses (courseName, credits, schedule, facultyID, start_time, end_time) VALUES
('Introduction to Programming', 3, 'Mon, Wed, Fri', 1, '09:00:00', '11:00:00'),
('Calculus I', 4, 'Mon, Wed, Fri', 1, '11:00:00', '13:00:00'),
('Physics I', 3, 'Tue, Thu', 2, '15:00:00', '17:00:00'),
('Modern History', 3, 'Mon, Wed', 3, '06:00:00', '8:00:00');

-- Insert into enrollments table
INSERT INTO enrollments (studentID, courseID, semester, grade) VALUES
(1, 1, 'Semester 1', 'A'),
(2, 2, 'Semester 2', 'B'),
(3, 3, 'Semester 1', 'A'),
(4, 4, 'Semester 2', 'B');


