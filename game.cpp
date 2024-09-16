#include <iostream>
#include <string>

bool isWin(char game[3][3]) {
    // Check rows and columns for a win
    for (int i = 0; i < 3; i++) {
        if ((game[i][0] == game[i][1] && game[i][1] == game[i][2] && (game[i][0] == 'X' || game[i][0] == 'O')) ||
            (game[0][i] == game[1][i] && game[1][i] == game[2][i] && (game[0][i] == 'X' || game[0][i] == 'O'))) {
            return true;
        }
    }
    // Check diagonals for a win
    if ((game[0][0] == game[1][1] && game[1][1] == game[2][2] && (game[0][0] == 'X' || game[0][0] == 'O')) ||
        (game[0][2] == game[1][1] && game[1][1] == game[2][0] && (game[0][2] == 'X' || game[0][2] == 'O'))) {
        return true;
    }
    return false;
}

int main() {
    int i, j, n;
    char game[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}; // Tic-tac-toe board
    bool turn = true; // Start with Player 1

    std::cout << "X = Player 1" << std::endl << "O = Player 2" << std::endl;

    for (n = 0; n < 9; n++) {
        std::cout << (turn ? "Player 1: " : "Player 2: ") << "Which cell to mark? i:[1..3], j:[1..3]: ";
        std::cin >> i >> j;
        i--; // Adjust for 0-based index
        j--; // Adjust for 0-based index

        if (i < 0 || i > 2 || j < 0 || j > 2 || game[i][j] != ' ') {
            std::cout << "Invalid move, try again." << std::endl;
            continue; // Skip the turn toggle and retry the loop
        }

        game[i][j] = turn ? 'X' : 'O';

        if (isWin(game)) {
            std::cout << "Win for " << (turn ? "Player 1" : "Player 2") << "!" << std::endl;
            break;
        }

        turn = !turn; // Toggle turn only after a valid move
    }

    if (n == 9) {
        std::cout << "Tie!" << std::endl;
    }

    // Display the final board
    for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
            std::cout << game[k][l] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}