=begin
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
=end

# NOTE: the returned value type of Math.sqrt is Fixnum

# sudo gem install test-unit
require "test/unit"
require "awesome_print"

class Iter
  attr_reader :matrix
  attr_reader :row
  attr_reader :col

  def initialize(matrix, row, col)
    @matrix = matrix
    @row = row
    @col = col
  end

  def item
    @matrix[@row][@col]
  end

  def !=(other)
    # OPTIMIZE
    not (@matrix.equal?(other.matrix) and @row == other.row and @col == other.col)
  end
end

class HorizontalIter < Iter
  def go_next
    @col += 1
  end
end

class VerticalIter < Iter
  def go_next
    @row += 1
  end
end

class GridIter < Iter
  def go_next
    len = (Math.sqrt @matrix.size).to_i
    first = @col / len * len
    last = first + len
    if @col == last - 1
      # carriage and return
      @row += 1
      @col = first
    else
      @col += 1
    end
  end
end

# character iterator
def is_valid(b, e)
  arr = [] # linear hash
  i = b
  while i != e
    if i.item == '.'
      i.go_next
      next
    end

    return false if arr[i.item.to_i] # Check if there is duplicate element.
    arr[i.item.to_i] = true
    i.go_next
  end
  true
end

# @param {Character[][]} board
# @return {Boolean}
def is_valid_sudoku(board)
  board.size.times do |row|
    return false unless is_valid(HorizontalIter.new(board, row, 0),
                                 HorizontalIter.new(board, row, board.size))
  end

  board.size.times do |col|
    return false unless is_valid(VerticalIter.new(board, 0, col),
                                 VerticalIter.new(board, board.size, col))
  end

  len = (Math.sqrt board.size).to_i
  (0...len).each do |i|
    row = i * len
    (0...len).each do |j|
      col = j * len
      return false unless is_valid(GridIter.new(board, row, col),
                                   GridIter.new(board, row + len, col))
    end
  end

  true
end

$board1 = [
  ['2'],
]

$board2 = [
  ['1', '2', '3', '4'],
  ['.', '.', '.', '.'],
  ['.', '.', '1', '.'],
  ['.', '.', '.', '1'],
]

$board3 = [
  ['1', '2', '3', '4'],
  ['.', '.', '.', '.'],
  ['.', '.', '1', '.'],
  ['.', '.', '.', '1'],
]

$board4 = ["....5..1.",
           ".4.3.....",
           ".....3..1",
           "8......2.",
           "..2.7....",
           ".15......",
           ".....2...",
           ".2.9.....",
           "..4......"]

$board5 = [".87654321",
           "2........",
           "3........",
           "4........",
           "5........",
           "6........",
           "7........",
           "8........",
           "9........"]

class TestK < Test::Unit::TestCase
  def test_k
    # assert_equal(true, is_valid_sudoku($board1))
    # assert_equal(false, is_valid_sudoku($board2))
    # assert_equal(false, is_valid_sudoku($board3))
    # assert_equal(false, is_valid_sudoku($board4))
    assert_equal(true, is_valid_sudoku($board5))
  end
end
