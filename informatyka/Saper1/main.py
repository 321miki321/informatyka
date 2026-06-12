import sys
import random
from PyQt6.QtWidgets import (QApplication, QWidget, QGridLayout,
                             QPushButton, QVBoxLayout, QLabel)
from PyQt6.QtCore import Qt
from PyQt6.QtGui import QFont


class Saper5x5(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Saper 5x5")
        self.setFixedSize(400, 500)

        # Parametry gry
        self.size = 5
        self.mines_count = 6

        # Interfejs
        self.layout = QVBoxLayout()


        self.status_label = QLabel("Powodzenia!")
        self.status_label.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.status_label.setFont(QFont("Arial", 22, QFont.Weight.Bold))
        self.layout.addWidget(self.status_label)

        self.grid = QGridLayout()
        self.buttons = []


        button_font = QFont("Arial", 16, QFont.Weight.Bold)

        for i in range(25):
            btn = QPushButton("")
            btn.setFixedSize(60, 60)
            btn.setFont(button_font)
            btn.clicked.connect(lambda ch, idx=i: self.handle_click(idx))
            self.grid.addWidget(btn, i // 5, i % 5)
            self.buttons.append(btn)

        self.layout.addLayout(self.grid)

        self.reset_btn = QPushButton("Nowa Gra")
        self.reset_btn.setFont(QFont("Arial", 14, QFont.Weight.Bold))
        self.reset_btn.clicked.connect(self.reset_game_ui)
        self.layout.addWidget(self.reset_btn)

        self.setLayout(self.layout)


        self.reset_game_ui()

    def reset_game(self):
        self.mines = random.sample(range(25), self.mines_count)
        self.revealed = [False] * 25
        self.game_over = False

    def reset_game_ui(self):
        self.reset_game()
        self.status_label.setText("Nowa gra rozpoczęta!")
        self.status_label.setStyleSheet("color: black;")

        for btn in self.buttons:
            btn.setText("")
            btn.setStyleSheet("background-color: black; border: 1px solid #444;")
            btn.setEnabled(True)

    def count_neighbors(self, index):
        r, c = index // 5, index % 5
        count = 0
        for dr in [-1, 0, 1]:
            for dc in [-1, 0, 1]:
                nr, nc = r + dr, c + dc
                if 0 <= nr < 5 and 0 <= nc < 5:
                    if (nr * 5 + nc) in self.mines:
                        count += 1
        return count

    def handle_click(self, index):
        if self.game_over or self.revealed[index]:
            return

        if index in self.mines:
            self.buttons[index].setText("💣")

            self.buttons[index].setStyleSheet("""
                background-color: red; 
                color: black; 
                border: 2px solid darkred;
            """)
            self.status_label.setText("KONIEC GRY! BUUM!")
            self.status_label.setStyleSheet("color: red;")
            self.game_over = True
            self.reveal_all_mines()
        else:
            count = self.count_neighbors(index)
            self.buttons[index].setText(str(count) if count > 0 else "")

            
            self.buttons[index].setStyleSheet("""
                QPushButton { background-color: white; color: black; border: 1px solid #aaa; }
                QPushButton:disabled { background-color: white; color: black; }
            """)
            self.buttons[index].setEnabled(False)
            self.revealed[index] = True
            self.check_win()

    def reveal_all_mines(self):
        for m in self.mines:
            if not self.revealed[m]:
                self.buttons[m].setText("💣")
                self.buttons[m].setStyleSheet("""
                    QPushButton { background-color: #ff6666; color: black; border: 1px solid red; }
                    QPushButton:disabled { background-color: #ff6666; color: black; }
                """)

    def check_win(self):
        safe_revealed = sum(1 for i, rev in enumerate(self.revealed) if rev and i not in self.mines)
        if safe_revealed == (25 - self.mines_count):
            self.status_label.setText("WYGRANA! Gratulacje!")
            self.status_label.setStyleSheet("color: green;")
            self.game_over = True


if __name__ == "__main__":
    app = QApplication(sys.argv)
    game = Saper5x5()
    game.show()
    sys.exit(app.exec())