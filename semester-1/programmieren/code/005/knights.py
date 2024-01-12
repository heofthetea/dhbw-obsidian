def main():
    start = input("enter starting coordinate: ")
    start = (ord(start[0]) - 97, int(start[1]) - 1)

    print(start)

    board = []
    for _ in range(0, 8):
        board.append([0] * 8)

    board = knight_jump(start, board, 1)
    print_board(board)


def print_board(board):
    for row in board:
        row_format = "["
        for cell in row:
            row_format += "{0:02d}, ".format(cell)
        print(f"{row_format[:-2]}]")


def full(board):
    for row in board:
        for cell in row:
            if not cell:
                return False
    return True

# it's actually not working aaaaa
def knight_jump(coordinates, board:list, move):
    updated_board = [row[:] for row in board]
    updated_board[coordinates[0]][coordinates[1]] = move

    if full(updated_board):
        return updated_board

    jumps = get_possible_jumps(coordinates, updated_board)
    for jump in jumps:
        result = knight_jump(jump, updated_board, move + 1)
        if result:
            return result
        
    updated_board[coordinates[0]][coordinates[1]] = 0

    return None


knight_jumps = {
    (-1, -2),
    (-1, 2),
    (1, -2),
    (1, 2),
    (-2, -1),
    (-2, 1),
    (2, -1),
    (2, 1),
}

def get_possible_jumps(current: tuple, board):
    jumps = []
    for relative in knight_jumps:
        jump_to = (current[0] + relative[0], current[1] + relative[1])

        if (jump_to[0] not in range(0, 8)) or (jump_to[1] not in range(0, 8)):
            continue
        jumps.append(jump_to)

    possible_jumps = []
    for option in jumps:
        if not board[option[0]][option[1]]:
            possible_jumps.append(option)

    return possible_jumps


if __name__ == "__main__":
    main()
