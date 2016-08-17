=begin
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.
=end

require "awesome_print"

# @param {Character[][]} board
# @return {Void} Do not return anything, modify board in-place instead.
def solve_sudoku(board)
  # min blank number
  kind = nil

  blank_row = nil
  blank_col = nil

  m = 10

  9.times do |i|
    empty = 0
    tmp_j = nil
    9.times do |j|
      if board[i][j] == '.'
        empty += 1
        tmp_j = j if tmp_j.nil?
      end
    end
    if 0 < empty and empty < m
      blank_row = i
      blank_col = tmp_j
      m = empty
      kind = "h"
    end
  end
  if m == 10 # finished
    return true
  end
  # puts "horizonal min blank is #{m}"

  9.times do |j|
    empty = 0
    tmp_i = nil
    9.times do |i|
      if board[i][j] == '.'
        empty += 1
        tmp_i = i if tmp_i.nil?
      end
    end
    if 0 < empty and empty < m
      blank_row = tmp_i
      blank_col = j
      m = empty
      kind = "v"
    end
  end
  # puts "after virtical, min blank is #{m}"

  3.times do |row|
    row *= 3
    3.times do |col|
      col *= 3
      empty = 0

      tmp_i = nil
      tmp_j = nil
      (row...row+3).each do |i|
        (col...col+3).each do |j|
          if board[i][j] == '.'
            empty += 1
            tmp_i = i if tmp_i.nil?
            tmp_j = j if tmp_j.nil?
          end
        end
      end
      if 0 < empty and empty < m
        m = empty
        kind = "g"
        blank_row = tmp_i
        blank_col = tmp_j
      end
    end
  end
  # puts "after grid, min blank is #{m}"
  # puts "kind is #{kind}, blank position is (#{blank_row}, #{blank_col})"

  full = ['1', '2', '3', '4', '5', '6', '7', '8', '9']

  fail if blank_row.nil? or blank_col.nil? or board[blank_row][blank_col] != '.'

  arr = []
  9.times do |j|
    if board[blank_row][j] != '.'
      arr << board[blank_row][j]
    end
  end
  9.times do |i|
    if board[i][blank_col] != '.'
      arr << board[i][blank_col]
    end
  end
  start_r = blank_row / 3 * 3
  start_c = blank_col / 3 * 3
  (start_r...start_r+3).each do |i|
    (start_c...start_c+3).each do |j|
      if board[i][j] != '.'
        arr << board[i][j]
      end
    end
  end

  candidate = full - arr
  # puts "candidate is #{candidate}"

  return false if candidate.empty?

  candidate.each do |char|
    board[blank_row][blank_col] = char
    # puts
    # ap board
    if solve_sudoku(board)
      return true
    end
    board[blank_row][blank_col] = '.'
  end
  # puts "current iteration's candidate has end"
  false
end

board1 = [".........",
          ".........",
          ".........",
          ".........",
          ".........",
          ".........",
          ".........",
          ".........",
          "........."]

board2 = [".........",
          "2........",
          "3........",
          "4........",
          "5........",
          "6........",
          "7........",
          "8........",
          "9........"]

solve_sudoku(board1)
solve_sudoku(board2)
