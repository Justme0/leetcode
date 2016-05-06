=begin
   Given a digit string, return all possible letter combinations that the number could represent.
   A mapping of digit to letters (just like on the telephone buttons) is given below.
Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
=end

# @param {String} digits
# @return {String[]}
def letter_combinations(digits)
  return [] if digits == ""
  map = [nil, nil, "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
  arrays = []
  digits.each_char do |digit|
    arrays << map[digit.to_i].chars if digit.to_i >= 2
  end
  # p arrays
  return [] if arrays.empty? # e.g. "0"
  arrays[0].product(*arrays[1..-1]).map do |arr| # Array.product(*arrays)
    arr.join
  end
end

p letter_combinations("220")
p letter_combinations("0")
