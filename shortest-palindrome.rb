# reference: http://www.felix021.com/blog/read.php?2040

# @param {String} s
# @return {Array of String}
def make_array(s)
	array = s.chars.join("#").chars
	array.unshift("#", "#")
	array.push("#")
end

# @param {Array of String} array
# @return {Array of Integer}
def get_aux(array)
	return array if array.nil? or array.empty?

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
	aux
end

# @param {String} s
# @return {String}
def shortest_palindrome(s)
	fail unless !s.nil?
	return "" if s == ""

	array = make_array(s)
	aux = get_aux(array)
	p array
	p aux
	fail unless array.size == aux.size

	center = 0
	aux.each_with_index do |x, i|	# OPTIMIZE: it's enough to iterate to middle
		if x == i
			center = i
		end
	end
	puts "center is #{center}"

	start_index = 2 * center
	puts "start_index is #{start_index}"
	tail = array[start_index..array.size - 1]
	return s if tail.empty?

	s.insert(0, tail.reject!{|x| x == "#"}.join.reverse!)
end

require "test/unit"

class TestKitty < Test::Unit::TestCase
	def test_kitty
		assert_equal("", shortest_palindrome(""));
		assert_equal("aaacecaaa", shortest_palindrome("aacecaaa"));
		assert_equal("dcbabcd", shortest_palindrome("abcd"));
	end
end
