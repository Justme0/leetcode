=begin
Given a string containing only digits, restore it by returning all possible
valid IP address combinations.

  For example:
  Given "25525511135",

  return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
=end

class String
  def valid?
    return false unless self.to_i.between?(0, 255)
    return false if self.size >= 2 and self[0] == '0'
    true
  end
end

# split s to get n valid IP fields
# return nil if failed
# @param {String} s, {Integer} n
# @return {Integer[]}
def restore(s, n)
  fail if s.nil?
  return nil if !s.empty? and n == 0
  return nil if s.empty? and n != 0 # e.g. "", 1
  return [[s.to_i]] if s.valid? and n == 1

  ret = [] # element is Integer[]
  i = 0
  while i < s.size and (prefix = s[0..i]; prefix.valid?)
    other = restore(s[i+1 .. -1], n - 1)
    # e.g. "34", 2, i is 1
    if !other.nil?
      other.each do |arr|
        ret << ([prefix.to_i] + arr)
      end
    end
    i += 1
  end

  ret
end

# @param {String} s
# @return {String[]}
def restore_ip_addresses(s)
  result = restore(s, 4)
  return [] if result.nil?
  result.map { |x| x.join(".") }
end

require "test/unit"

class TestKitty < Test::Unit::TestCase
  def test_kitty
    assert_equal(nil, restore("", 1))
    assert_equal([], restore("1", 2))
    assert_equal(nil, restore("12", 0))
    assert_equal([], restore("", 0))
    assert_equal([[1]], restore("1", 1))
    assert_equal([[12]], restore("12", 1))
    assert_equal([[1, 2]], restore("12", 2))
    assert_equal([[1, 2, 3]], restore("123", 3))
    assert_equal([[23]], restore("23", 1))
    assert_equal([[1, 23], [12, 3]], restore("123", 2))
    assert_equal([[1, 2, 3, 4]], restore("1234", 4))

    assert_equal(["0.10.0.10", "0.100.1.0"], restore_ip_addresses("010010"))
    assert_equal(["1.2.3.4"], restore_ip_addresses("1234"))
    assert_equal([], restore_ip_addresses(""))
    assert_equal([], restore_ip_addresses("3"))
    assert_equal([], restore_ip_addresses("251"))
    assert_equal(["255.255.121.135"], restore_ip_addresses("255255121135"))
    assert_equal(["255.255.11.135", "255.255.111.35"],
                 restore_ip_addresses("25525511135"))
  end
end
