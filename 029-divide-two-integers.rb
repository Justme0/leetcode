# TODO: use bitwise operation

INT_MAX = 2 ** 31 - 1
INT_MIN = -INT_MAX - 1

# @param {Integer} dividend
# @param {Integer} divisor
# @return {Integer}
def divide(dividend, divisor)
  is_positive = (dividend >= 0 == divisor >= 0)
  dividend = dividend.abs
  divisor = divisor.abs

  result = dividend / divisor
  result = -result unless is_positive
  if not result.between?(INT_MIN, INT_MAX)
    return INT_MAX
  end
  result
end

require 'test/unit'

class TestHello < Test::Unit::TestCase
  def test_hello
    assert_equal(0, divide(1004958205, -2137325331))
    assert_equal(INT_MAX, divide(-2147483648, -1))
  end
end
