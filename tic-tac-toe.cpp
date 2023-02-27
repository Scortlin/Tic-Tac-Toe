#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
	// глобальные константы
const char X = 'X';
const char O = 'O';
const char ЕМРТY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';
	// прототипы функций
void instructions();
char askYesNo(string question);
int askNumber(string question, int high, int low = 0);
char humanPiece();
char opponent(char piece);
void displayBoard(const vector<char>& board);
char winner(const vector<char>& board);
bool isLegal(const vector<char>& board, int move);
int humanMove(const vector<char>& board, char human);
int computerMove(vector<char> board, char computer);
void announceWinner(char winner, char computer, char human);

int main() {
	setlocale(LC_ALL, "rus");
	int move;
	const int NUM_SQUARES = 9;
	vector<char> board(NUM_SQUARES, ЕМРТY);
	instructions();
	char human = humanPiece();
	char computer = opponent(human);
	char turn = 'X';
	displayBoard(board);
	while (winner(board) == NO_ONE) {
		if (turn == human){
			move = humanMove(board, human);
			board[move] = human;
		}
		else{
			move = computerMove(board, computer);
			board[move] = computer;
		}
		displayBoard(board);
		turn = opponent(turn);
	}
	announceWinner(winner(board), computer, human);
	return 0;
}

void instructions() {
	cout << "Добро пожаловать в The Ultimate Man-Machine Showdown: Tic-Tac-Toe.\n";
	cout << "где человеческий мозг будет сражаться с процессором\n\n";
	cout << "Введи число от 0 до 8. Число\n";
	cout << "соответствует желаемой позиции доски, как показано здесь:\n\n";
	cout << " 0 | 1 | 2\n";
	cout << " ---------\n";
	cout << " 3 | 4 | 5\n";
	cout << " ---------\n";
	cout << " 6 | 7 | 8\n\n";
	cout << "Приготовься, человек. Битва начинается!\n\n";
}
char askYesNo(string question){
	char response;
	do{
		cout << question << " (y/n):";
		cin >> response;
	} while (response != 'y' && response != 'n');
	return response;
}
int askNumber(string question, int high, int low){
	int number;
	do{
		cout << question << " (" << low << " - " << high << "): ";
		cin >> number;
	} while (number > high || number < low);
	return number;
}
char humanPiece(){
	char go_first = askYesNo("Вы хотите сделать первый ход?");
	if (go_first == 'y') {
		cout << "\nТогда сделайте первый ход. Вам это нужнее.\n";
		return X;
	}
	else{
		cout << "\nТвоя храбрость тебя разрушит... Я хожу первым.\n";
		return O;
	}
}
char opponent(char piece) {
	if (piece == X) {
		return O;
	}
	else
	{
		return X;
	}
}
void displayBoard(const vector<char>& board){
	cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2];
	cout << "\n\t" << "---------";
	cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];
	cout << "\n\t" << "---------";
	cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8];
	cout << "\n\n";
}
char winner(const vector<char>& board){
	// все возможные выигрышные ряды
	const int WINNING_ROWS[8][3] = { {0,1, 2}, {3, 4, 5},
	{6, 7, 8},
	{0, 3, 6},
	{1, 4, 7},
	{2, 5, 8},
	{0, 4, 8},
	{2, 4, 6} };
	const int TOTAL_ROWS = 8;
	// если в одном из выигрышных рядов уже присутствуют три одинаковых значения
		// (причем они не равны ЕМРТУ).то победитель определился
	for (int row = 0; row < TOTAL_ROWS; ++row) {
		if ((board[WINNING_ROWS[row][0]] != ЕМРТY) &&
			(board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]]) &&
			(board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]])) {
			return board[WINNING_ROWS[row][0]];
		}
	}
	// поскольку победитель не определился.проверяем.не наступила ли ничья
		// (остались ли на поле пустые клетки)
	if (count(board.begin(), board.end(), ЕМРТY) == 0)
		return TIE;
	// Поскольку победитель не определился.но и ничья еще не наступила.
		// игра продолжается
	return NO_ONE;
}
	inline bool isLegal(const vector<char>& board, int move){
		return (board[move] == ЕМРТY);
	}
	int humanMove(const vector<char>& board, char human) {
		int move = askNumber("Где ты сделаешь ход?", (board.size() - 1));
		
		while (!isLegal(board, move)) {
			cout << "\nЭтот квадрат занят, глупый человек.\n";
			move = askNumber("Где ты сделаешь ход?", (board.size() - 1));
		}

		cout << "Хорошо\n";
		return move;
	}
	int computerMove(vector<char> board, char computer) {
		unsigned int move = 0;
		bool found = false;
		// если компьютер может выиграть следующим ходом.то он делает этот ход
		while (!found && move < board.size())
		{
			if (isLegal(board, move))
			{
				board[move] = computer;
				found = winner(board) == computer;
				board[move] = ЕМРТY;
			}

			if (!found)
			{
				++move;
			}
		}
		if (!found)
		{
			move = 0;
			char human = opponent(computer);
			while (!found && move < board.size())
			{
				if (isLegal(board, move))
				{
					board[move] = human;
					found = winner(board) == human;
					board[move] = ЕМРТY;
				}

				if (!found)
				{
					++move;
				}
			}
		}
		// иначе занять следующим ходом оптимальную свободную клетку
		if (!found)
		{
			move = 0;
			unsigned int i = 0;
			const int BEST_MOVES[] = { 4, 0, 2, 6, 8, 1, 3, 5, 7 };
			// выбрать оптимальную свободную клетку
			while (!found && i < board.size())
			{
				move = BEST_MOVES[i];
				if (isLegal(board, move))
				{
					found = true;
				}
				++i;
			}
		}
		cout << "Делаю свой ход в клетке  " << move << endl;
		return move;
	}
	void announceWinner(char winner, char computer, char human)
	{
		if (winner == computer)
		{
			cout << winner << " выиграл!\n";
			cout << "Как я и предсказывал, человек. Я Непобедим!\n";
			cout << "Компьютеры превосходят людей во всех отношениях!\n";
		}

		else if (winner == human)
		{
			cout << winner << "' выиграл!\n";
			cout << "Нет, НЕТ! Этого не может быть! Как ты меня обхитрил, человек? \n";
			cout << "Но, не радуйся. В следующий раз я обязательно выиграю\n";
		}
		else
		{

			cout << "Ничья.\n";
			cout << "Тебе повезло, человек. Каким-то образом ты смог сыграть в ничью\n";
			cout << "Веселись, человек. Это лучшее, чего вы когда-либо достигли\n";
		}
	}

