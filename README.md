# Псевдокод игры Tic-Tac-Toe
Создать пустое поле для игры в крестики-нолики

Вывести на экран правила игры

Определить. кто ходит первым

Отобразить поле

Если пока никто не победил и не наступила ничья

И если сейчас ход пользователя

Получить ход пользователя

Обновить игровое поле с учетом хода пользователя

Иначе

Вычислить ход компьютера

Обновить поле с учетом хода компьютера

Отобразить поле

Передать ход сопернику

Поздравить победителя или объявить ничью
# Функции для игры в Крестики-нолики
1) void instructions() - Отображает правила игры
2) char askYesNo(string question) - Задает вопрос, предполагающий ответ «да» или «нет». Получает вопрос. Возвращает символ y или n.
3) int askNumber(string question, int high, int low = 0) - Запрашивает число из диапазона. Получает вопрос,малое число и большое число. Возвращает число из
диапазона от low до high.
4) char humanPiece() - Определяет, какими фигурами будет ходить пользова-
тель. Возвращает Х или О
5) char opponent(char piece) - Зная, какими фигурами будет ходить пользователь,
определяет фигуру для компьютера. Получает Х или О.
Возвращает Х или O
6) void displayBoard(const vector<char>& board) - Отображает поле на экране. Получает поле
7) char winner(const vector<char>& board) - Определяет победителя игры. Получает поле. Возвращает символ Х, или О, или Т (этот случай соответствует
ничьей), или М (означает, что пока у обоих соперников остаются шансы на победу)
8) bool isLegal(const vector<char>& board, int move) - Определяет, по правилам ли сделан ход. Получает поле и ход, Возвращает true или false
9) int humanMove(const vector<char>& board, char human) - Узнает ход пользователя. Получает поле и фигуру, которой ходит пользователь. Возвращает ход пользователя
10) int computerMove(const vector<char>& board, char computer) - Узнает ход компьютера. Получает поле и фигуру, которой ходит компьютер. Возвращает ход компьютера
11) void announceWinner(char winner, char computer, char human) - Поздравляет победителя или объявляет ничью. Получает победившую сторону, фигуру, которой ходил пользователь, и фигуру, которой ходил компьютер
# Сборка и установка
Сборка с помощью любой IDE либо сборка из командной строки

# Системные требования
Компилятор С++ с поддержкой стандарта C++17 или новее
