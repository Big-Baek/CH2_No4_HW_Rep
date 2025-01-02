#include <iostream>
#include <vector>
#include <string>
#include <map>


using namespace std; // namespace std ���

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
	vector<Book> books; // å ��� ����

public:
	// å �߰� �޼���
	void addBook(const string& title, const string& author) {
		books.push_back(Book(title, author)); // push_back ���
		cout << "å�� �߰��Ǿ����ϴ�: " << title << " by " << author << endl;
	}

	// ��� å ��� �޼���
	void displayAllBooks() const {
		if (books.empty()) {
			cout << "���� ��ϵ� å�� �����ϴ�." << endl;
			return;
		}

		cout << "���� ���� ���:" << endl;
		for (size_t i = 0; i < books.size(); i++) { // �Ϲ����� for�� ���
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
		cout << "�׷� å�� ����� ����" << endl;
	}
	void searchByAuthor(string author) {
		for (int i = 0; i < books.size(); i++) {
			if (books[i].author == author) {
				cout << books[i].title << "by" << author << endl;
				return;
			}
		}
		cout << "�׷� �۰��� ����� ����" << endl;
	}
};

class BorrowManager {
public:
	map<string, int> stock; //å ����� ��� ����
	
	void borrow_book() {
		string title;
		cin >> title;
		if (stock[title] != 0) {
			stock[title]--;
			
			cout << "�뿩�Ǿ����ϴ�. ����å�� "<<stock[title]<<"���Դϴ�." << endl;
		}
		else cout << "�뿩���� ��� �����ϴ�" << endl; //0���̶��
	}
	void return_book() {
		string title;
		cin >> title;
		if (stock[title] == 3) { //3���� ���ִٸ�
			cout << "�̹� �ݳ��Ǿ��ֽ��ϴ�" << endl;
			return;
		}
		else {
			stock[title]++;
			cout << "�ݳ�ó������ϴ�" << endl;
		}
	}
	void displayStock() {
		map<string, int>::iterator it;
		for (it = stock.begin(); it != stock.end(); it++) {
			cout << it->first << ": " << it->second << "��, " << endl;
		}
		cout << "�Դϴ�" << endl;
	}
};

int main() {
	BookManager manager;
	BorrowManager s_manager;
	// ������ ���� ���α׷��� �⺻ �޴��� �ݺ������� ����Ͽ� ����� �Է��� ó���մϴ�.
	// ���α׷� ���Ḧ �����ϱ� ������ ��� �����մϴ�.
	while (true) {
		cout << "\n������ ���� ���α׷�" << endl;
		cout << "1. å �߰�" << endl; // å ������ �Է¹޾� å ��Ͽ� �߰�
		cout << "2. ��� å ���" << endl; // ���� å ��Ͽ� �ִ� ��� å ���
		cout << "3 �۰��� �˻�" << endl;
		cout << "4 �������� �˻�" << endl;
		cout << "5 �뿩���� å" << endl;
		cout << "6 å �뿩" << endl;
		cout << "7 å �ݳ�" << endl;
		cout << "8. ����" << endl; // ���α׷� ����
		cout << "����: ";

		int choice; // ������� �޴� ������ ����
		cin >> choice;

		if (choice == 1) {
			// 1�� ����: å �߰�
			// ����ڷκ��� å ����� ���ڸ��� �Է¹޾� BookManager�� �߰��մϴ�.
			string title, author;
			cout << "å ����: ";
			cin.ignore(); // ���� �Է��� �ܿ� ���۸� ����
			getline(cin, title); // ���� �Է� (���� ����)
			cout << "å ����: ";
			getline(cin, author); // ���ڸ� �Է� (���� ����)
			manager.addBook(title, author); // �Է¹��� å ������ �߰�
			s_manager.stock[title] = 3; //����� 3������ ����
		}
		else if (choice == 2) {
			// 2�� ����: ��� å ���
			// ���� BookManager�� ����� å ����� ����մϴ�.
			manager.displayAllBooks();
		}
		else if (choice == 3) {
			cout << "�۰��� �Է��ϼ���" << endl;
			string some;
			cin >> some;
			manager.searchByAuthor(some);
		}

		else if (choice == 4) {
			cout << "������ �Է��ϼ���" << endl;
			string some;
			cin >> some;
			manager.searchByTitle(some);
		}
		else if (choice == 5) {
			cout << "�뿩������ å��" << endl;
			s_manager.displayStock();
		}
		else if (choice == 6) {
			cout << "�뿩�� å�� �Է����ּ���" << endl;
			s_manager.borrow_book();
		}
		else if (choice == 7) {
			cout << "�ݳ��� å�� �Է����ּ���" << endl;
			s_manager.return_book();
		}
		else if (choice == 8) {
			// 3�� ����: ����
			// ���α׷��� �����ϰ� ����ڿ��� �޽����� ����մϴ�.
			cout << "���α׷��� �����մϴ�." << endl;
			break; // while ���� ����
		}
		else {
			// �߸��� �Է� ó��
			// �޴��� ���� ��ȣ�� �Է����� ��� ��� �޽����� ����մϴ�.
			cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
			break; //�Ǽ��� å���� �Է��ϸ� else���� �ȸ��߰� ���ѷ����� ���ƹ����� �׳� ���α׷� ����...
		}
	}

	return 0; // ���α׷� ���� ����
}

