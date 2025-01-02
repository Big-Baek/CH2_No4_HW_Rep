#include <iostream>
#include <vector>
#include <string>
#include <map>


using namespace std; // namespace std 사용

class Book {
public:
	string title;
	string author;
	Book(const string& title, const string& author)
		: title(title), author(author) {
	}
};

class BookManager {
private:
	vector<Book> books; // 책 목록 저장

public:
	// 책 추가 메서드
	void addBook(const string& title, const string& author) {
		books.push_back(Book(title, author)); // push_back 사용
		cout << "책이 추가되었습니다: " << title << " by " << author << endl;
	}

	// 모든 책 출력 메서드
	void displayAllBooks() const {
		if (books.empty()) {
			cout << "현재 등록된 책이 없습니다." << endl;
			return;
		}

		cout << "현재 도서 목록:" << endl;
		for (size_t i = 0; i < books.size(); i++) { // 일반적인 for문 사용
			cout << "- " << books[i].title << " by " << books[i].author << endl;
		}
	}



	void searchByTitle(string title) {
		for (int i = 0; i < books.size(); i++) {
			if (books[i].title == title) {
				cout << title << "by" << books[i].author << endl;
				return;
			}
		}
		cout << "그런 책은 없어요 ㅎㅎ" << endl;
	}
	void searchByAuthor(string author) {
		for (int i = 0; i < books.size(); i++) {
			if (books[i].author == author) {
				cout << books[i].title << "by" << author << endl;
				return;
			}
		}
		cout << "그런 작가는 없어요 ㅎㅎ" << endl;
	}
};

class BorrowManager {
public:
	map<string, int> stock; //책 제목과 재고 갯수
	
	void borrow_book() {
		string title;
		cin >> title;
		if (stock[title] != 0) {
			stock[title]--;
			
			cout << "대여되었습니다. 남은책은 "<<stock[title]<<"권입니다." << endl;
		}
		else cout << "대여가능 재고가 없습니다" << endl; //0권이라면
	}
	void return_book() {
		string title;
		cin >> title;
		if (stock[title] == 3) { //3권이 다있다면
			cout << "이미 반납되어있습니다" << endl;
			return;
		}
		else {
			stock[title]++;
			cout << "반납처리됬습니다" << endl;
		}
	}
	void displayStock() {
		map<string, int>::iterator it;
		for (it = stock.begin(); it != stock.end(); it++) {
			cout << it->first << ": " << it->second << "권, " << endl;
		}
		cout << "입니다" << endl;
	}
};

int main() {
	BookManager manager;
	BorrowManager s_manager;
	// 도서관 관리 프로그램의 기본 메뉴를 반복적으로 출력하여 사용자 입력을 처리합니다.
	// 프로그램 종료를 선택하기 전까지 계속 동작합니다.
	while (true) {
		cout << "\n도서관 관리 프로그램" << endl;
		cout << "1. 책 추가" << endl; // 책 정보를 입력받아 책 목록에 추가
		cout << "2. 모든 책 출력" << endl; // 현재 책 목록에 있는 모든 책 출력
		cout << "3 작가로 검색" << endl;
		cout << "4 제목으로 검색" << endl;
		cout << "5 대여가능 책" << endl;
		cout << "6 책 대여" << endl;
		cout << "7 책 반납" << endl;
		cout << "8. 종료" << endl; // 프로그램 종료
		cout << "선택: ";

		int choice; // 사용자의 메뉴 선택을 저장
		cin >> choice;

		if (choice == 1) {
			// 1번 선택: 책 추가
			// 사용자로부터 책 제목과 저자명을 입력받아 BookManager에 추가합니다.
			string title, author;
			cout << "책 제목: ";
			cin.ignore(); // 이전 입력의 잔여 버퍼를 제거
			getline(cin, title); // 제목 입력 (공백 포함)
			cout << "책 저자: ";
			getline(cin, author); // 저자명 입력 (공백 포함)
			manager.addBook(title, author); // 입력받은 책 정보를 추가
			s_manager.stock[title] = 3; //재고량은 3권으로 고정
		}
		else if (choice == 2) {
			// 2번 선택: 모든 책 출력
			// 현재 BookManager에 저장된 책 목록을 출력합니다.
			manager.displayAllBooks();
		}
		else if (choice == 3) {
			cout << "작가를 입력하세요" << endl;
			string some;
			cin >> some;
			manager.searchByAuthor(some);
		}

		else if (choice == 4) {
			cout << "제목을 입력하세요" << endl;
			string some;
			cin >> some;
			manager.searchByTitle(some);
		}
		else if (choice == 5) {
			cout << "대여가능한 책은" << endl;
			s_manager.displayStock();
		}
		else if (choice == 6) {
			cout << "대여할 책을 입력해주세요" << endl;
			s_manager.borrow_book();
		}
		else if (choice == 7) {
			cout << "반납할 책을 입력해주세요" << endl;
			s_manager.return_book();
		}
		else if (choice == 8) {
			// 3번 선택: 종료
			// 프로그램을 종료하고 사용자에게 메시지를 출력합니다.
			cout << "프로그램을 종료합니다." << endl;
			break; // while 루프 종료
		}
		else {
			// 잘못된 입력 처리
			// 메뉴에 없는 번호를 입력했을 경우 경고 메시지를 출력합니다.
			cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
			break; //실수로 책제목 입력하면 else에서 안멈추고 무한루프를 돌아버려서 그냥 프로그램 종료...
		}
	}

	return 0; // 프로그램 정상 종료
}

