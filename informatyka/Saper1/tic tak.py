import sys
from PyQt6.QtWidgets import (
    QApplication, QWidget, QVBoxLayout, QGridLayout, QPushButton, QLabel, QHBoxLayout
)
from PyQt6.QtGui import QFont
from PyQt6.QtCore import Qt



class TicTacToe:
    """Silnik gry w kółko i krzyżyk - logika."""

    EMPTY = " "
    PLAYER_X = "X"
    PLAYER_O = "O"

    WINNING_LINES = (
        (0, 1, 2), (3, 4, 5), (6, 7, 8),  # wiersze
        (0, 3, 6), (1, 4, 7), (2, 5, 8),  # kolumny
        (0, 4, 8), (2, 4, 6),  # przekątne
    )

    def __init__(self):
        self.board = [self.EMPTY] * 9
        self.current_player = self.PLAYER_X
        self.winner = None
        self.winning_line = None

    def make_move(self, index):
        """Wykonuje ruch bieżącego gracza na pole `index`."""
        if self.is_game_over():
            return False
        if not (0 <= index < 9):
            return False
        if self.board[index] != self.EMPTY:
            return False

        self.board[index] = self.current_player
        self._update_winner()
        if not self.is_game_over():
            self._switch_player()
        return True

    def reset(self):
        """Resetuje stan gry do warunków początkowych."""
        self.board = [self.EMPTY] * 9
        self.current_player = self.PLAYER_X
        self.winner = None
        self.winning_line = None

    def is_draw(self):
        return self.winner is None and all(cell != self.EMPTY for cell in self.board)

    def is_game_over(self):
        return self.winner is not None or self.is_draw()

    def get_board(self):
        """Zwraca kopię planszy jako listę 9 pól."""
        return list(self.board)

    def status(self):
        """Tekstowy opis bieżącego stanu."""
        if self.winner is not None:
            return f"Wygrał gracz {self.winner}!"
        if self.is_draw():
            return "Remis!"
        return f"Ruch gracza: {self.current_player}"

    def _update_winner(self):
        for line in self.WINNING_LINES:
            a, b, c = line
            if self.board[a] != self.EMPTY and self.board[a] == self.board[b] == self.board[c]:
                self.winner = self.board[a]
                self.winning_line = line
                return

    def _switch_player(self):
        self.current_player = self.PLAYER_O if self.current_player == self.PLAYER_X else self.PLAYER_X



class TicTacToeUI(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Kółko i krzyżyk")
        self.setFixedSize(360, 420)

        self.game = TicTacToe()  # Tworzymy obiekt logiki zdefiniowany wyżej
        self.cell_buttons = []

        layout = QVBoxLayout()

        self.status_label = QLabel(self.game.status())
        self.status_label.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.status_label.setFont(QFont("Arial", 14, QFont.Weight.Bold))
        layout.addWidget(self.status_label)

        grid = QGridLayout()
        grid.setSpacing(4)
        button_font = QFont("Arial", 32, QFont.Weight.Bold)

        for index in range(9):
            button = QPushButton(TicTacToe.EMPTY)
            button.setFixedSize(100, 100)
            button.setFont(button_font)
            button.clicked.connect(lambda _checked, i=index: self.handle_cell_click(i))
            self.cell_buttons.append(button)
            grid.addWidget(button, index // 3, index % 3)
        layout.addLayout(grid)

        controls = QHBoxLayout()
        self.reset_button = QPushButton("Nowa gra")
        self.reset_button.clicked.connect(self.reset_game)
        controls.addWidget(self.reset_button)
        layout.addLayout(controls)

        self.setLayout(layout)
        self.refresh()

    def handle_cell_click(self, index):
        if self.game.make_move(index):
            self.refresh()

    def reset_game(self):
        self.game.reset()
        self.refresh()

    def refresh(self):
        board = self.game.get_board()
        winning_cells = set(self.game.winning_line or ())

        for index, button in enumerate(self.cell_buttons):
            button.setText(board[index])
            button.setEnabled(board[index] == TicTacToe.EMPTY and not self.game.is_game_over())
            if index in winning_cells:
                button.setStyleSheet("background-color: #b6f5b6;")
            else:
                button.setStyleSheet("")
        self.status_label.setText(self.game.status())



if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = TicTacToeUI()
    window.show()
    sys.exit(app.exec())