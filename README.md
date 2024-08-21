# TicTacToe Game

Implementing the concepts of AI Minimax algorithm for a tic-tac-toe game using the C language. Its interface is terminal-based and uses a matrix for the board. So the player can choose a position from 1 to 9.

## Screenshots
![img](doc/screenshot.png)

## The Minimax Algorithm

The Minimax algorithm is a decision-making AI algorithm used in two-player turn-based games like Tic-Tac-Toe. It aims to minimize the possible loss in a worst-case scenario, ensuring that the AI makes the best possible move.

### Basic Principles

1. **Game Tree**: A tree representation of all possible moves in the game.
2. **Min and Max Players**: The algorithm assumes two players: the maximizing player (AI) and the minimizing player (opponent).
3. **Utility Function**: A function that assigns a numerical value to each terminal state (win, loss, or draw) of the game.
4. **Minimax Decision**: The process of selecting the move that maximizes the AI's minimum payoff.

### How It Works

1. **Generate Game Tree**: Construct the game tree with the current state of the board as the root, and all possible subsequent moves as branches.
2. **Evaluate Terminal States**: Assign values to terminal states: +1 for a win, -1 for a loss, and 0 for a draw.
3. **Backpropagate Values**: Propagate these values up the tree:
   - If it's the AI's turn (maximizing player), choose the move with the highest value.
   - If it's the opponent's turn (minimizing player), choose the move with the lowest value.
4. **Choose Optimal Move**: At the root, select the move corresponding to the highest value from the AI's perspective.

### Example in Tic-Tac-Toe

1. **Current State**: Assume the AI is 'X' and it's the AI's turn.
2. **Generate Game Tree**: Explore all possible moves 'X' can make, followed by all possible responses from 'O', and so on.
3. **Evaluate**: For each terminal state, determine if it's a win, loss, or draw.
4. **Backpropagate**: Starting from terminal states, propagate the values back to the root:
   - If 'X' can force a win in any branch, it will choose that move.
   - If 'O' can force a loss, 'X' will avoid that move if possible.
5. **Optimal Move**: The AI selects the move that maximizes its chances of winning or minimizes its chances of losing.

The Minimax algorithm ensures that the AI plays optimally, making the best possible moves in Tic-Tac-Toe to either win or draw the game.

## Stack

- C language.

## License
MIT by Wolney Oliveira
