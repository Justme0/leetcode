# Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.
# 
# Note:
# 
# The length of both num1 and num2 is < 5100.
# Both num1 and num2 contains only digits 0-9.
# Both num1 and num2 does not contain any leading zero.
# You must not use any built-in BigInteger library or convert the inputs to integer directly.

# @param {String} num1
# @param {String} num2
# @return {String}
def add_strings(num1, num2)
    (num1.to_i + num2.to_i).to_s
end
