=begin
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
=end

require 'test/unit'

# @param {String} s
# @return {Integer}
def roman_to_int(s)
  chars = "IVXLCDM"
  h = {
    'I' => 1,
    'V' => 5,
    'X' => 10,
    'L' => 50,
    'C' => 100,
    'D' => 500,
    'M' => 1000,
  }
  ret = 0
  pre = nil
  s.each_char do |c|
    ret += h[c]
    if !pre.nil? and h[pre] < h[c]
      ret -= 2 * h[pre]
    end
    pre = c
  end
  ret
end

class TestKitty < Test::Unit::TestCase
  def test_kitty
    assert_equal(1000, roman_to_int("M"))
    assert_equal(1, roman_to_int("I"))
    assert_equal(1400, roman_to_int("MCD"))
    assert_equal(1437, roman_to_int("MCDXXXVII"))
    assert_equal(1500, roman_to_int("MD"))
    assert_equal(1800, roman_to_int("MDCCC"))
    assert_equal(1880, roman_to_int("MDCCCLXXX"))
    assert_equal(1900, roman_to_int("MCM"))
    assert_equal(2000, roman_to_int("MM"))
    assert_equal(3000, roman_to_int("MMM"))
    assert_equal(3333, roman_to_int("MMMCCCXXXIII"))
  end
end
