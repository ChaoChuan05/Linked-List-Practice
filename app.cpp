#include	<iostream>
#include	<cstdlib>
#include	<iomanip>
#include	<cstdio>
#include    <fstream>
#include    <string>
#include	"List.h"
#include    "LibStudent.h"
#include    "LibBook.h"

using namespace std;

bool ReadFile(string, List*);
bool DeleteRecord(List*, char*);
bool Display(List*, int, int);
bool InsertBook(string, List*);
bool SearchStudent(List*, char* id, LibStudent&);
bool computeAndDisplayStatistics(List*);
bool printStuWithSameBook(List*, char*);
bool displayWarnedStudent(List*, List*, List*);
int menu();


int main() {
	int user_input; 
	char user_continue_input;

	List student_list;

	do {
		menu();

		cout << endl;
		cout << "Enter your choice: ";
		cin >> user_input; 
		cin.ignore();

		switch (user_input) {

		case 1: {
			string user_file_name;
			char continue_case_1;

			do {
				cout << "Please insert your filename here: ";
				getline(cin, user_file_name);

				ReadFile(user_file_name, &student_list);

				cout << student_list.size() << " record have been successfully read" << endl;
				cout << endl;

				//For debug purpose only
				/*Node* current = student_list.head;

				while (current != nullptr) {
					cout << "Name: " << current->item.name << endl;
					cout << "ID: " << current->item.id << endl;
					cout << "Course: " << current->item.course << endl;
					cout << "Phone: " << current->item.phone_no << endl;

					current = current->next;
				}*/

				cout << "Do you still want continue to read file (Y - yes, N - no): ";
				cin >> continue_case_1;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');  // <-- THIS CLEARS THE BUFFER

				while (continue_case_1 != 'Y' && continue_case_1 != 'y' && continue_case_1 != 'n' && continue_case_1 != 'N') {
					cout << endl;
					cout << "Invalid selection, please try again" << endl;
					cout << "Do you still want continue to read file (Y - yes, N - no): ";
					cin >> continue_case_1;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');  // <-- THIS CLEARS THE BUFFER
				}


			} while (continue_case_1 == 'Y' || continue_case_1 == 'y');

			break;

		}

		case 2: {
			char student_id[10];
			char continue_case_2;

			do {
				cout << "Please enter a student ID to delete: ";
				cin >> student_id;
				cin.ignore();

				if (DeleteRecord(&student_list, student_id)) {
					cout << "Student with ID:" << student_id << " have been deleted successfully" << endl;
				}

				else {
					cout << student_id << " record is not found" << endl;
				}

				//For debug purpose only
				/*Node* current = student_list.head;

				while (current != nullptr) {
					cout << "Name: " << current->item.name << endl;
					cout << "ID: " << current->item.id << endl;
					cout << "Course: " << current->item.course << endl;
					cout << "Phone: " << current->item.phone_no << endl;

					current = current->next;
				}*/

				cout << "Do you still want continue to delete record (Y - yes, N - no): ";
				cin >> continue_case_2;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');  // <-- THIS CLEARS THE BUFFER

				while (continue_case_2 != 'Y' && continue_case_2 != 'y' && continue_case_2 != 'n' && continue_case_2 != 'N') {
					cout << endl;
					cout << "Invalid selection, please try again" << endl;
					cout << "Do you still want continue to read file (Y - yes, N - no): ";
					cin >> continue_case_2;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');  // <-- THIS CLEARS THE BUFFER
				}


			} while (continue_case_2 == 'Y' || continue_case_2 == 'y');
			
			break;
		}

		case 3: {
			char continue_case_3;

			do {

				//Put your code here
				cout << endl << "-------------" << endl;
				cout << "SEARCH RECORD" << endl;
				cout << "-------------" << endl;

				char searchId[10];
				LibStudent foundStudent;
				cout << "Enter the id that you want to search: ";
				cin >> searchId;
				if (SearchStudent(&student_list, searchId, foundStudent)) {
					cout << "Student found:";
					foundStudent.print(cout);
					cout << "\n";
				}

				else {
					cout << "Student not found.\n\n";
				}

				break;


				//DO NOT DELETE THE WHOLE THING
				cout << "Do you still want continue to Search Student (Y - yes, N - no): ";
				cin >> continue_case_3;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');  // <-- THIS CLEARS THE BUFFER

				while (continue_case_3 != 'Y' && continue_case_3 != 'y' && continue_case_3 != 'n' && continue_case_3 != 'N') {
					cout << endl;
					cout << "Invalid selection, please try again" << endl;
					cout << "Do you still want continue to read file (Y - yes, N - no): ";
					cin >> continue_case_3;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');  // <-- THIS CLEARS THE BUFFER
				}


			} while (continue_case_3 == 'Y' || continue_case_3 == 'y');

			break;
		}

		case 4: {
			string user_file_name;
			char continue_case_4;

			do {
				cout << "Please insert your filename here: ";
				getline(cin, user_file_name);

				InsertBook(user_file_name, &student_list);

				cout << "Insert sucessfully" << endl;

				cout << "Do you still want continue to read file (Y - yes, N - no): ";
				cin >> continue_case_4;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');  // <-- THIS CLEARS THE BUFFER

				while (continue_case_4 != 'Y' && continue_case_4 != 'y' && continue_case_4 != 'n' && continue_case_4 != 'N') {
					cout << endl;
					cout << "Invalid selection, please try again" << endl;
					cout << "Do you still want continue to Insert Book (Y - yes, N - no): ";
					cin >> continue_case_4;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');  // <-- THIS CLEARS THE BUFFER
				}

			} while (continue_case_4 == 'Y' || continue_case_4 == 'y');

			break;

		}

		case 5: {
			int user_source, user_detail;
			char continue_case_5;

			do {
				cout << "Where do you want to display the output(1 - File / 2 - Screen): ";
				cin >> user_source;
				cin.ignore();

				cout << "Do you want to display book list for every student (1 - YES / 2 - NO): ";
				cin >> user_detail;
				cin.ignore();

				Display(&student_list, user_source, user_detail);

				cout << "Do you still want continue to delete record (Y - yes, N - no): ";
				cin >> continue_case_5;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');  // <-- THIS CLEARS THE BUFFER

				while (continue_case_5 != 'Y' && continue_case_5 != 'y' && continue_case_5 != 'n' && continue_case_5 != 'N') {
					cout << endl;
					cout << "Invalid selection, please try again" << endl;
					cout << "Do you still want continue to Display (Y - yes, N - no): ";
					cin >> continue_case_5;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');  // <-- THIS CLEARS THE BUFFER
				}


			} while (continue_case_5 == 'y' || continue_case_5 == 'Y');

			break;
		}
		
		case 6: {

			char continue_case_6;

			do {

				//Put your code here
				if (!computeAndDisplayStatistics(&student_list)) {
					cout << "The list is empty.\n" << endl;
				}

				//DO NOT DELETE THE WHOLE THING
				cout << "Do you still want continue to delete record (Y - yes, N - no): ";
				cin >> continue_case_6;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');  // <-- THIS CLEARS THE BUFFER

				while (continue_case_6 != 'Y' && continue_case_6 != 'y' && continue_case_6 != 'n' && continue_case_6 != 'N') {
					cout << endl;
					cout << "Invalid selection, please try again" << endl;
					cout << "Do you still want continue to compute & Display Statistics (Y - yes, N - no): ";
					cin >> continue_case_6;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');  // <-- THIS CLEARS THE BUFFER
				}


			} while (continue_case_6 == 'Y' || continue_case_6 == 'y');

			break;
		}
		
		case 7: {
			char continue_case_7;
			char callNum[30];

			do {

				//Put your code here
				cout << "Please enter the book call number to search: ";
				cin.getline(callNum, 30);

				if (!printStuWithSameBook(&student_list, callNum)) {
					cout << "Error finding students with the same book" << endl;
				}


				//DO NOT DELETE THE WHOLE THING
				cout << "Do you still want continue to delete record (Y - yes, N - no): ";
				cin >> continue_case_7;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');  // <-- THIS CLEARS THE BUFFER

				while (continue_case_7 != 'Y' && continue_case_7 != 'y' && continue_case_7 != 'n' && continue_case_7 != 'N') {
					cout << endl;
					cout << "Invalid selection, please try again" << endl;
					cout << "Do you still want continue to print student with same book (Y - yes, N - no): ";
					cin >> continue_case_7;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');  // <-- THIS CLEARS THE BUFFER
				}


			} while (continue_case_7 == 'Y' || continue_case_7 == 'y');

			break;

		}

		case 8: {
			char continue_case_8;

			do {

				//Put your code here
				List type1, type2;

				if (!displayWarnedStudent(&student_list, &type1, &type2)) {
					cout << "Error displaying warned students" << endl;
				}

				//DO NOT DELETE THE WHOLE THING
				cout << "Do you still want continue to delete record (Y - yes, N - no): ";
				cin >> continue_case_8;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');  // <-- THIS CLEARS THE BUFFER

				while (continue_case_8 != 'Y' && continue_case_8 != 'y' && continue_case_8 != 'n' && continue_case_8 != 'N') {
					cout << endl;
					cout << "Invalid selection, please try again" << endl;
					cout << "Do you still want continue to display warned student (Y - yes, N - no): ";
					cin >> continue_case_8;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');  // <-- THIS CLEARS THE BUFFER
				}


			} while (continue_case_8 == 'Y' || continue_case_8 == 'y');

			break;

		}

		case 9: {
			cout << "Good Bye!!!" << endl;
			system("pause");
			return 0;
		}


		default:
			cout << "Invalid choice" << endl;
			break;

		}

		cout << "Do you still want to continue to menu (Y - yes, N - no): ";
		cin >> user_continue_input;
		cin.ignore();
		cout << endl;
		system("cls");


	} while (user_continue_input == 'y' || user_continue_input == 'Y');
	
	cout << "\n\n";
	system("pause");
	return 0;
}

int menu() {
	cout << "1. Read File" << endl;
	cout << "2. Delete Record" << endl;
	cout << "3. Search Student" << endl;
	cout << "4. Insert Book" << endl;
	cout << "5. Display Output" << endl;
	cout << "6. Compute and Display Statistics" << endl;
	cout << "7. Student with Same Book" << endl;
	cout << "8. Display Warned Student" << endl;
	cout << "9. Exit" << endl;

	return 0;
}

bool ReadFile(string filename, List* list) {

	ifstream inFile;

	inFile.open(filename);

	if (!inFile.is_open()) {
		cout << "Unable to open file" << endl;
		return false;
	}

	string line, id_line, name_line, course_line, phone_line;

	while (getline(inFile, id_line)) {

		if (!getline(inFile, name_line) ||
			!getline(inFile, course_line) ||
			!getline(inFile, phone_line)
			) {
			cout << "Skip due to invalid getline" << endl;
			continue;
		}

		//To eat out the empty line between student
		getline(inFile, line);
		getline(inFile, line);


		/*
		you might confuse about the line below...

		Let me explain :)

		Student Id = 1200233
		Name = Matt Damon
		course = CS
		Phone Number = 790-3233

		I want to extract the student information, however I just want the value
		after the equal sign. So the id_line.find function help us to find the equal sign

		BTW the size_t is string size

		BUT WHAT ABOUT THE SECOND LINE, IT'S SO CONFUSED!!!

		Hold up let me explain

		string:npos mean "not found"

		if the find function successfully find out the equal sign, then it won't
		appear the string::npos else you get trouble

		In this case, we just want to validate to make sure that the code is not broke
		*/

		// Find values after '='
		size_t pos;
		string id, name, course, phone;

		pos = id_line.find("=");
		if (pos == string::npos) continue;
		id = id_line.substr(pos + 1);

		pos = name_line.find("=");
		if (pos == string::npos) continue;
		name = name_line.substr(pos + 1);

		pos = course_line.find("=");
		if (pos == string::npos) continue;
		course = course_line.substr(pos + 1);

		pos = phone_line.find("=");
		if (pos == string::npos) continue;
		phone = phone_line.substr(pos + 1);

		// Trim leading spaces
		id = id.substr(id.find_first_not_of(" "));
		name = name.substr(name.find_first_not_of(" "));
		course = course.substr(course.find_first_not_of(" "));
		phone = phone.substr(phone.find_first_not_of(" "));

		bool is_duplicate = false;

		type temporary;


		//Checking duplication
		for (int i = 1; i <= list->size(); i++) {
			if (list->get(i, temporary)) {
				if (strcmp(temporary.id, id.c_str()) == 0) {
					is_duplicate = true;
					cout << "Student ID duplicate found!" << endl;
					break;
				}

			}
		}

		if (!is_duplicate) {
			type student_information;

			if (id.length() >= sizeof(student_information.id) ||
				name.length() >= sizeof(student_information.name) ||
				course.length() >= sizeof(student_information.course) ||
				phone.length() >= sizeof(student_information.phone_no)) {

				cout << "Skipping due to invalid field length" << endl;
				continue;
			}

			strcpy_s(student_information.id, sizeof(student_information.id), id.c_str());
			strcpy_s(student_information.name, sizeof(student_information.name),  name.c_str());
			strcpy_s(student_information.course, sizeof(student_information.course), course.c_str());
			strcpy_s(student_information.phone_no, sizeof(student_information.phone_no), phone.c_str());

			list->insert(student_information);


		}

	}

	inFile.close();


	return true;
}

bool DeleteRecord(List* list, char* id) {
	type temporary;

	for (int i = 1; i <= list->size(); i++) {
		if (list->get(i, temporary)) { //retrieve student information at position i & store in temporary
			if (strcmp(temporary.id, id) == 0) { //if the student id is same mean equal to 0, then we remove it
				list->remove(i);
				return true;
			}
		}

	}
	
	//if everything doesn't match
	return false;

}

bool Display(List*list, int source, int detail) {
	/*
		1. Check list is empty or not (special case)
		2. Open the output stream based on the number source
		3. Loop each student by using Node
		
		source = 1 (display to file)
		source = 2 (display to screen)
		detail = 1 (display student info and book info)
		detail = 2 (display student info only)
	
	*/

	if (list->empty()) {
		cout << "The list is empty" << endl;
		return false;
	}

	ostream* out; //for screen
	ofstream OutFile; //for file

	if (source == 1) {
		if (detail == 1) OutFile.open("student_booklist.txt");
		else if (detail == 2) OutFile.open("student_info.txt");

		if (!OutFile) {
			cout << "File is unable to open" << endl;
			return false;
		}
		
		//printing to the file
		out = &OutFile; // pass the ofstream address to the pointer
	}

	else {
		//if source = 2 then print to the console
		//printing to the console

		out = &std::cout;
	}

	Node* current = list->head;
	int count = 1;

	while (current != nullptr) {
		*out << "Student" << count++ << endl;

		//print book & student
		if (detail == 1) {
			current->item.print(*out);
		}

		else if (detail == 2) {
			*out << "Name: " << current->item.name << endl;
			*out << "ID: " << current->item.id << endl;
			*out << "Course: " << current->item.course << endl;
			*out << "Phone No: " << current->item.phone_no << endl;
			*out << "Total Fine: RM" << current->item.total_fine << endl;
			*out << endl;
		}

		*out << string(20, '*');
		*out << endl << endl;
		current = current->next; //next node address value
	
	}

	if (source == 1) OutFile.close();

	cout << endl;
	cout << "Successfully display output" << endl;

	return true;
	
}

bool InsertBook(string filename, List* list) {
	ifstream inFile;

	inFile.open(filename);

	if (!inFile) {
		cout << "The file is unable to open" << endl;
		return false;
	}

	char student_id[10];
	char book_title[250];
	char book_publisher[100];
	char book_ISBN[15];
	int book_year;
	char call_num[30];
	int borrow_day, borrow_month, borrow_year;
	int due_day, due_month, due_year;

	while (!inFile.eof()) {

		//Take input respectively
		inFile >> ws >> student_id;
		inFile.ignore();

		char author_buffer[250];
		inFile >> author_buffer;

		//Debug only
		//cout << "Author buffer: [" << author_buffer << "]" << endl;

		//Divide the author eg: alex/ali in author buffer to alex in authors[1] ali to authors[2]
		char* authors[10] = { nullptr };
		int count = 0;
		char* next_pointer = nullptr;

		char* token = strtok_s(author_buffer, "/", &next_pointer);

		while (token != nullptr && count < 10) {
			size_t length = strlen(token);
			authors[count] = new char[length + 1];
			strcpy_s(authors[count], length + 1, token);
			count++;
			token = strtok_s(nullptr, "/", &next_pointer);
		}

		inFile.ignore();
		inFile.getline(book_title, 250, ' ');
		inFile.getline(book_publisher, 100, ' ');
		inFile >> book_ISBN;
		inFile.ignore();
			
		if (!inFile) {
			cout << "Error reading title, publisher, ISBN" << endl;
			break;
		}

		inFile >> book_year;
		inFile.ignore();

		inFile.getline(call_num, 30, ' ');

		char borrow_date_buffer[20];

		inFile.getline(borrow_date_buffer, 20, ' ');

		if (sscanf_s(borrow_date_buffer, "%d/%d/%d", &borrow_day, &borrow_month, &borrow_year) != 3) {
			cout << "Error: The borrow date data is failing" << endl;
			break;
		}

		char due_date_buffer[20];

		inFile.getline(due_date_buffer, 20, '\n');

		if (sscanf_s(due_date_buffer, "%d/%d/%d", &due_day, &due_month, &due_year) != 3) {
			cout << "Error: The due date data is failing" << endl;
			break;
		}

		inFile.ignore();
		
		//Debug only
		//cout << student_id << endl;

		//for (int i = 0; i < count; ++i) {
		//	cout << "Author[" << i << "]: " << authors[i] << endl;
		//}

		//cout << book_title << endl;
		//cout << book_publisher << endl;
		//cout << book_ISBN << endl;
		//cout << book_year << endl;
		//cout << call_num << endl;
		//cout << borrow_day << endl;
		//cout << borrow_month << endl;
		//cout << borrow_year << endl;
		//cout << due_day << endl;
		//cout << due_month << endl;
		//cout << due_year << endl;
		//cout << endl;
		

		//Insert data
		LibBook book;

		strcpy_s(book.title, sizeof(book.title), book_title);
		strcpy_s(book.publisher, sizeof(book.publisher), book_publisher);
		strcpy_s(book.ISBN, sizeof(book.ISBN), book_ISBN);
		strcpy_s(book.callNum, sizeof(book.callNum), call_num);

		for (int i = 0; i < count; ++i) {
			book.author[i] = new char[strlen(authors[i]) + 1];
			strcpy_s(book.author[i], strlen(authors[i]) + 1, authors[i]);
		}

		book.yearPublished = book_year;
		book.borrow.day = borrow_day;
		book.borrow.month = borrow_month;
		book.borrow.year = borrow_year;

		book.due.day = due_day;
		book.due.month = due_month;
		book.due.year = due_year;

		//Calculate fine
		const double FINE = 0.50;

		Date current_date;
		current_date.day = 29;
		current_date.month = 3;
		current_date.year = 2020;

		int julian_date_current = current_date.day + current_date.month * 30 + current_date.year * 365;
		int julian_date_due = due_day + due_month * 30 + due_year * 365;

		int overdue = julian_date_current - julian_date_due;

		book.fine = overdue > 0 ? overdue * FINE : 0.0;

		//Debug only

		/*for (int i = 0; i < count; ++i) {
			cout << "Author[" << i << "]: " << book.author[i] << endl;
		}

		cout << book.title << endl;
		cout << book.publisher << endl;
		cout << book.ISBN << endl;
		cout << book.callNum << endl;
		cout << book.yearPublished << endl;
		cout << book.borrow.day << "/" << book.borrow.month << "/" << book.borrow.year << endl;
		cout << book.due.day << "/" << book.due.month << "/" << book.due.year << endl;
		cout << book.fine << endl;*/

		//Search student ID
		Node* current = list->head;

		if (list->empty()) cout << "The list is empty" << endl;

		while (current != nullptr) {
			if (strcmp(current->item.id, student_id) == 0) {

				cout << endl;
				cout << "Match found: inserting book for the student with ID: " << student_id << endl;
				cout << "Current total book: " << current->item.totalbook << endl;
				cout << endl;

				if (current->item.totalbook < 15) { //student can only borrow up to 15 book

					//eg current->item.book[2] - if total book is 2
					current->item.book[current->item.totalbook] = book; //insert book into next avaliable spot in the student book 
					current->item.totalbook++;

					cout << "Book title: " << current->item.book[current->item.totalbook - 1].title << endl;
					cout << "Current total book: " << current->item.totalbook << endl;


					current->item.calculateTotalFine();

					cout << "Current total fine: RM" << current->item.total_fine << endl;
					cout << endl;

				}
				break;
			}
			current = current->next;
		}
	}

	inFile.close();
	return true;
}

bool SearchStudent(List* list, char* id, LibStudent& stu) {
	Node* cur = list->head;

	// Traverse the linked list
	while (cur != NULL) {
		// Compare ids
		if (strcmp(cur->item.id, id) == 0) {
			// If id matches, copy student information to stu
			stu = cur->item;
			// Return true as student is found
			return true;
		}
		cur = cur->next;
	}

	// If student with given id is not found, return false
	return false;
}

bool computeAndDisplayStatistics(List* list1) {
	if (list1 == nullptr || list1->empty()) {
		return false;
	}

	struct CourseStatistics {
		int numStudents = 0;
		int totalBooksBorrowed = 0;
		int totalOverdueBooks = 0;
		double totalOverdueFine = 0.0;
	};

	// Proper initialization of the stats array
	CourseStatistics stats[5] = {};

	const char* courseCodes[5] = { "CS", "IA", "IB", "CN", "CT" };

	Node* current = list1->head;

	while (current != nullptr) {
		LibStudent& student = current->item;

		int courseIndex = -1;
		for (int i = 0; i < 5; ++i) {
			if (strcmp(student.course, courseCodes[i]) == 0) {
				courseIndex = i;
				break;
			}
		}

		if (courseIndex != -1) {
			CourseStatistics& courseStat = stats[courseIndex];
			courseStat.numStudents++;
			courseStat.totalBooksBorrowed += student.totalbook;
			courseStat.totalOverdueFine += student.total_fine;

			for (int i = 0; i < student.totalbook; ++i) {
				if (student.book[i].fine > 0) {
					courseStat.totalOverdueBooks++;
				}
			}
		}

		current = current->next;
	}

	cout << left << setw(15) << "Course"
		<< setw(25) << "Number of Students"
		<< setw(25) << "Total Books Borrowed"
		<< setw(25) << "Total Overdue Books"
		<< setw(25) << "Total Overdue Fine (RM)" << endl;

	for (int i = 0; i < 5; ++i) {
		cout << left << setw(15) << courseCodes[i]
			<< setw(25) << stats[i].numStudents
			<< setw(25) << stats[i].totalBooksBorrowed
			<< setw(25) << stats[i].totalOverdueBooks
			<< setw(25) << fixed << setprecision(2) << stats[i].totalOverdueFine << endl;
	}

	cout << endl;

	return true;
}

bool printStuWithSameBook(List* list, char* callNum) {
	// Checking the list if the list is empty
	if (list->empty()) {
		cout << "The list is empty" << endl;
		return false;
	}

	int count = 0;
	Node* current = list->head;

	// Count how many students have the book with given call number
	while (current != nullptr) {
		// Check each book in the student's book list
		for (int i = 0; i < current->item.totalbook; i++) {
			if (strcmp(current->item.book[i].callNum, callNum) == 0) {
				count++;
				break; // Only per  one student
			}
		}
		current = current->next;
	}

	// If no students borrow this book
	if (count == 0) {
		cout << "No students found borrowing book with call number: " << callNum << endl;
		return true;
	}

	// Print the count of students have borrow
	cout << "There are " << count << " students that borrow the book with call number "
		<< callNum << " as shown below:" << endl << endl;

	// Print details of students who have the book
	current = list->head;
	while (current != nullptr) {
		for (int i = 0; i < current->item.totalbook; i++) {
			if (strcmp(current->item.book[i].callNum, callNum) == 0) {
				// Print student information
				cout << "Student Id = " << current->item.id << endl;
				cout << "Name = " << current->item.name << endl;
				cout << "Course = " << current->item.course << endl;
				cout << "Phone Number = " << current->item.phone_no << endl;

				// Print borrow and due dates
				cout << "Borrow Date: ";
				current->item.book[i].borrow.print(cout);
				cout << endl;
				cout << "Due Date: ";
				current->item.book[i].due.print(cout);
				cout << endl << endl;
				break; // Only print once per student
			}
		}
		current = current->next;
	}

	return true;
}

bool displayWarnedStudent(List* list, List* type1, List* type2) {
	// Check if the list is empty
	if (list->empty()) {
		cout << "The list is empty" << endl;
		return false;
	}

	// Constants for checking conditions
	Date current_date;
	current_date.day = 29; //Day
	current_date.month = 3; //March
	current_date.year = 2020; //Year
	const double FINE_THRESHOLD = 50.00; // RM50 threshold for type2 warning

	Node* current = list->head;
	while (current != nullptr) {
		int overdue_books = 0;       // Count of books overdue >= 10 days
		bool all_books_overdue = true; // Flag for all books being overdue
		double total_fine = 0.0;      // Accumulated fine for student

		// Check each book in student's book list
		for (int i = 0; i < current->item.totalbook; i++) {
			LibBook& book = current->item.book[i];

			// Calculate days overdue using Julian date method
			int current_julian = current_date.day + current_date.month * 30 + current_date.year * 365;
			int due_julian = book.due.day + book.due.month * 30 + book.due.year * 365;
			int days_overdue = current_julian - due_julian;

			if (days_overdue > 0) {
				// Book is overdue
				total_fine += days_overdue * 0.50; // RM0.50 per day
				if (days_overdue >= 10) {
					overdue_books++;
				}
			}
			else {
				// Book is not overdue
				all_books_overdue = false;
			}
		}

		// Check type1 condition: more than 2 books overdue >= 10 days
		if (overdue_books > 2) {
			type1->insert(current->item);
		}

		// Check type2 condition: total fine > RM50 and all books overdue
		if (total_fine > FINE_THRESHOLD && all_books_overdue) {
			type2->insert(current->item);
		}

		current = current->next;
	}

	// Display type1 warned students
	cout << "Students with more than 2 books overdue >= 10 days:" << endl;
	if (type1->empty()) {
		cout << "No students found for this warning type." << endl;
	}
	else {
		Node* current = type1->head;
		while (current != nullptr) {
			current->item.print(cout);
			cout << "BOOK LIST:" << endl;
			for (int i = 0; i < current->item.totalbook; i++) {
				cout << "Book " << i + 1 << endl;
				current->item.book[i].print(cout);
				cout << endl;
			}
			cout << string(50, '*') << endl << endl;
			current = current->next;
		}
	}

	// Display type2 warned students
	cout << "Students with total fine > RM50.00 and all books overdue:" << endl;
	if (type2->empty()) {
		cout << "No students found for this warning type." << endl;
	}
	else {
		Node* current = type2->head;
		while (current != nullptr) {
			current->item.print(cout);
			cout << "BOOK LIST:" << endl;
			for (int i = 0; i < current->item.totalbook; i++) {
				cout << "Book " << i + 1 << endl;
				current->item.book[i].print(cout);
				cout << endl;
			}
			cout << string(50, '*') << endl << endl;
			current = current->next;
		}
	}

	return true;
}



