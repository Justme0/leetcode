=begin
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

  string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
=end

require 'pp'

# @param {String} s
# @param {Integer} num_rows
# @return {String}
def convert(s, num_rows)
  return s if 1 == num_rows
  m = Array.new(num_rows) { Array.new(s.size / 2 + 1) }
  is_down = true
  row = 0
  col = 0
  s.chars.each_with_index do |c, i|
    m[row][col] = c

    # prepare for next iteration:
    is_down = (i % (2 * (num_rows - 1))).between?(0, (num_rows - 2))
    if is_down
      row += 1
    else
      row -= 1
      col += 1
    end
  end

  #pp m
  ret = String.new
  m.each do |arr|
    arr.each do |c|
      ret << c if !c.nil?
    end
  end
  ret
end

require 'test/unit'

class TestKitty < Test::Unit::TestCase
  def test_kitty
    assert_equal("PAHNAPLSIIGYIR", convert("PAYPALISHIRING", 3))
    assert_equal("a", convert("a", 1))
    puts convert(
      "vldmgofucbtokobnfmwddnuluewlglwbyzneoubsxughkjwpvtsyinkctiobvmc \
      "umracmbujxcthmrxjkrivguxbenczaevoywqkzmvxqqeeidouvypdupfyejxgqt"
      "uorkyqyvnpmutwxhqufgazxfzbqzigseulrubpqreelyakhqhpyhqvoqzepjljn"
      "hwecxuuqaabaaoisvztcpqqhpuyyhjmpfsrfonvpnzppnzhiycmqtcxiyyhghvx"
      "nnqscdntqmkhbkojkrxckbcuaadihyfuovosaclsqvzshpdugdwseapeasoitte"
      "jqtbqxokpljjtzpphslcwordolryenfndaqwzegoqsaltpaajnefbxiqjcqnpvd"
      "uvtquyzlotlbmabojotqsqbibdapuwsornholizbbkcpmdfvuynmrowstwjnudc"
      "mrlactbgwlinxosukthykwuersqfntjbmudrpexnphaovsihlrfxpbehuumjpxk"
      "ctptitqvkxvavpicbbiarleyfamoqjaucpnmkfhueeubtegwgqxxbdxhejxwsaq"
      "wpfiamrwqvruqxandqmcrrz",
        245)
  end
end
