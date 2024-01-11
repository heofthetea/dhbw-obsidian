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


def knights():
    pass


def get_possible_jumps(board, current:tuple):
    jumps = []
    for relative in knight_jumps:
        jump_to = (
            current[0] + relative[0], 
            current[1] + relative[1]
        )


def main():
    pass


if __name__ == "__main__":
    main()
