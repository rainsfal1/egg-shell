#include "../include/utils.h"

// Constants representing players and board size
#define AI 1
#define PLAYER 2
#define BOARD_SIZE 3

// Macro to get the maximum of two values
#define max(a,b) ((a) > (b) ? (a) : (b))
// Macro to get the minimum of two values
#define min(a,b) ((a) < (b) ? (a) : (b))

// Structure representing a move with row and column
typedef struct {
    int row, col;
} Move ;

// Symbols for AI and player
char ai = 'x', player = 'o';

// Function to check if there are any moves left on the board
bool isMovesLeft(char board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            if (board[i][j] == '_')
                return true;
    return false;
}

// Function to check if a line on the board has the same symbol
bool checkLine(char board[BOARD_SIZE][BOARD_SIZE], int startRow, int startCol, int dRow, int dCol) {
    char startCell = board[startRow][startCol];
    if (startCell == '_') return false;
    for (int i = 1; i < BOARD_SIZE; i++) {
        if (board[startRow + i * dRow][startCol + i * dCol] != startCell) return false;
    }
    return true;
}

// Function to evaluate the board and assign a score
int evaluate(char board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (checkLine(board, i, 0, 0, 1) || checkLine(board, 0, i, 1, 0)) {
            if (board[i][0] == ai) return +10;
            else return -10;
        }
    }
    if (checkLine(board, 0, 0, 1, 1) || checkLine(board, 0, BOARD_SIZE - 1, 1, -1)) {
        if (board[0][0] == ai) return +10;
        else return -10;
    }
    return 0;
}


// Minimax algorithm for finding the best move
int minimax(char board[BOARD_SIZE][BOARD_SIZE], int depth, bool isMaximizingPlayer)
{
    int score = evaluate(board);
    if (score == 10 || score == -10) return score;
    if (!isMovesLeft(board)) return 0;

    if (isMaximizingPlayer) {
        int bestScore = -1000;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == '_') {
                    board[i][j] = ai;
                    score = minimax(board, depth + 1, false);
                    board[i][j] = '_';
                    bestScore = max(score, bestScore);
                }
            }
        }
        return bestScore;
    } else {
        int bestScore = 1000;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == '_') {
                    board[i][j] = player;
                    score = minimax(board, depth + 1, true);
                    board[i][j] = '_';
                    bestScore = min(score, bestScore);
                }
            }
        }
        return bestScore;
    }
}

// Function to find the best move using the minimax algorithm
Move findBestMove(char board[BOARD_SIZE][BOARD_SIZE])
{
    int bestVal = -1000;
    Move bestMove = {-1, -1};

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == '_') {
                board[i][j] = ai;
                int moveVal = minimax(board, 0, false);
                board[i][j] = '_';
                if (moveVal > bestVal) {
                    bestMove.row = i;
                    bestMove.col = j;
                    bestVal = moveVal;
                }
            }
        }
    }
    return bestMove;
}

// Function to display the game board
void showBoard(char board[BOARD_SIZE][BOARD_SIZE])
{
    printf("\n\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("\t\t\t %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < BOARD_SIZE - 1) {
            printf("\t\t\t----------\n");
        }
    }
    printf("\n");
}

// Function to show the instructions
void showInstructions()
{
    printf("\t\t\t Tic-Tac-Toe\n\n");
    printf("Choose a cell numbered from 1 to 9 as below and play\n\n");

    int cell = 1;
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("\t\t\t");
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", cell++);
            if (j < BOARD_SIZE - 1) {
                printf("| ");
            }
        }
        printf("\n");
        if (i < BOARD_SIZE - 1) {
            printf("\t\t\t----------\n");
        }
    }
    printf("\n");
}

// Function to initialise the game
void initialise(char board[BOARD_SIZE][BOARD_SIZE], int moves[])
{
    srand(time(NULL));

    // Initially, the board is empty
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++)
            board[i][j] = '_';
    }

    // Fill the moves with numbers
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++)
        moves[i] = i;

    // Randomize the moves
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++)
    {
        int randIndex = rand() % (BOARD_SIZE * BOARD_SIZE);
        int temp = moves[i];
        moves[i] = moves[randIndex];
        moves[randIndex] = temp;
    }
}

// Function to declare the winner of the game
void declareWinner(int whoseTurn)
{
    if (whoseTurn == AI)
        printf("PLAYER has won\n");
    else
        printf("AI has won\n");
}

// Function to check if any row, column or diagonal is crossed with the same player's move
int isGameOver(char board[BOARD_SIZE][BOARD_SIZE])
{
    return (evaluate(board) != 0 || !isMovesLeft(board));
}

// Function to play Tic-Tac-Toe
void playTicTacToe(int whoseTurn)
{
    // A 3*3 Tic-Tac-Toe board for playing
    char board[BOARD_SIZE][BOARD_SIZE];
    int moves[BOARD_SIZE * BOARD_SIZE];

    // Initialise the game
    initialise(board, moves);

    // Show the instructions before playing
    showInstructions();

    int moveIndex = 0, x, y;

    // Keep playing until the game is over, or it is a draw
    while (!isGameOver(board) && moveIndex != BOARD_SIZE * BOARD_SIZE) {
        if (whoseTurn == AI) {
             Move thisMove = findBestMove(board);
            x = thisMove.row;
            y = thisMove.col;

            board[x][y] = ai;
            int cell = x * BOARD_SIZE + y + 1; // Convert 2D indices to a single number
            printf("AI has put a %c in cell %d\n", ai, cell); // Display the cell number instead of the indices
            showBoard(board);
            moveIndex++;
            whoseTurn = PLAYER;
        }

        else if (whoseTurn == PLAYER) {
            int move;
            printf("Enter your move (1-9): ");
            scanf("%d", &move);
            if (move < 1 || move > 9) {
                printf("Invalid input! Please enter a number between 1 and 9.\n");
                continue;
            }
            x = (move - 1) / BOARD_SIZE;
            y = (move - 1) % BOARD_SIZE;
            if (board[x][y] == '_') {
                board[x][y] = player;
                showBoard(board);
                moveIndex++;
                if (isGameOver(board)) {
                    declareWinner(PLAYER);
                    return;
                }
                whoseTurn = AI;
            }
            else {
                printf("Cell %d is already occupied. Try again.\n", move);
            }
        }
    }

    // If the game has drawn
    if (!isGameOver(board) && moveIndex == BOARD_SIZE * BOARD_SIZE)
        printf("It's a draw\n");
    else {
        // Toggling the user to declare the actual winner
        if (whoseTurn == PLAYER)
            whoseTurn = PLAYER;
        else if (whoseTurn == PLAYER)
            whoseTurn = AI;

        // Declare the winner
        declareWinner(whoseTurn);
    }
}