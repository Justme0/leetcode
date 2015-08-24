# reference: http://www.felix021.com/blog/read.php?2040
# Array
def make_array(s)
	array = s.chars.join("#").chars
	array.unshift("#", "#")
	array.push("#")
end

# @param {String} s
# @return {String}
def longest_palindrome(s)
	fail unless !s.nil?
	return "" if s == ""

	array = make_array(s)
	aux = Array.new(array.size, 0)
	max_size = 0
	max_index = 0	# TODO: why
	array.each_index do |i|
		next if i == 0

		aux[i] = max_size > i ? [aux[2 * max_index - i], max_size - i].min : 1
		while array[i + aux[i]] == array[i - aux[i]]
			aux[i] += 1
		end
		if i + aux[i] > max_size
			max_size = i + aux[i]
			max_index = i
		end
	end

	p array
	p aux
	fail unless array.size == aux.size

	value, index = aux.each_with_index.max
	puts "value is #{value}"
	puts "index is #{index}"
	array[index - value + 1 .. index + value - 1].reject! { |x|
		x == "#"
	}.join
end

require "test/unit"

class TestKitty < Test::Unit::TestCase
	def test_kitty
		assert_equal("", longest_palindrome(""));
		assert_equal("a", longest_palindrome("a"));
		assert_equal("aba", longest_palindrome("aba"));
		assert_equal("12321", longest_palindrome("12212321"));
	end
end
