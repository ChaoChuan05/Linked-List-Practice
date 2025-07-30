#include	<iostream>
#include	<cstdlib>
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
//bool SearchStudent(List*, char* id, LibStudent&);
//bool computeAndDisplayStatistics(List*);
//bool printStuWithSameBook(List*, char*);
//bool displayWarnedStudent(List*, List*, List*);
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


			} while (continue_case_2 == 'Y' || continue_case_2 == 'y');
			
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
				cin.ignore();


			} while (continue_case_5 == 'y' || continue_case_5 == 'Y');

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

	while (current != NULL) {
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
		}

		*out << string(20, '*');
		current = current->next; //next node address value
	
	}

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
	char book_author[100];
	char book_title[250];
	char book_publisher[30];
	char book_ISBN[11];
	int book_year;
	char call_num[20];
	int borrow_day, borrow_month, borrow_year;
	int due_day, due_month, due_year;

	
	while (
		inFile >> student_id >> book_author >>
		book_title >> book_publisher >> book_ISBN >>
		book_year >> call_num >> borrow_day >> borrow_month >>
		borrow_year >> due_day >> due_month >> due_year
		) {
			
		LibBook book;

		strcpy_s(book.title, sizeof(book.title), book_title);
		strcpy_s(book.publisher, sizeof(book.publisher), book_publisher);
		strcpy_s(book.ISBN, sizeof(book.ISBN), book_ISBN);
		strcpy_s(book.callNum, sizeof(book.callNum), call_num);

		book.yearPublished = book_year;

		book.borrow.day = borrow_day;
		book.borrow.month = borrow_month;
		book.borrow.year = borrow_year;

		book.due.day = due_day;
		book.due.month = due_month;
		book.due.year = due_year;
		
		//split author / 
		int count = 0;


		//This is to cut out the author since  eg:  Alex/Ali contain two author
		char* context = nullptr;
		char* token = strtok_s(book_author, "/", &context);

		while (token != nullptr && count < 10) { //can't exceeds 10 author
			book.author[count] = new char[strlen(token) + 1]; //Dynamic allocate memory to store the author name +1 is for null terminator
			strcpy_s(book.author[count], sizeof(book_author[count]), token); 
			count++;
			token = strtok_s(nullptr, "/", &context); //continue to find the / 
		}

		//Calculate fine
		const double FINE = 0.50;

		Date current_date;
		current_date.day = 29;
		current_date.month = 3;
		current_date.year = 2020;

		bool julian_date_current = current_date.day + 
								   current_date.month * 30 + 
								   current_date.year * 365;

		bool julian_date_due = due_day +
							   due_month * 30 +
							   due_year * 365;

		int overdue = julian_date_current - julian_date_due;
	
		book.fine = overdue > 0 ? overdue * FINE : 0.0;

		//Search student ID
		Node* current = list->head;

		while (current != nullptr) {
			if (strcmp(current->item.id, student_id) == 0) {
				if (current->item.totalbook < 15) { //student can only borrow up to 15 book

					//eg current->item.book[2] - if total book is 2
					current->item.book[current->item.totalbook] = book; //insert book into next avaliable spot in the student book 
					current->item.totalbook++;

					current->item.calculateTotalFine();
				}
				break;
			}
			current = current->next;
		}

	}

	inFile.close();
	return true;
}


//bool SearchStudent(List* list, char* id, LibStudent&stu) {
//
//
//}
//
//bool computeAndDisplayStatistics(List* list) {
//
//
//}


//bool printStuWithSameBook(List* list, char*callNum) {
//
//
//}
//
//
//bool displayWarnedStudent(List* list, List*type1, List*type2) {
//
//	
//}



