def dfs(n, k, array, index, result)
	if k == array.size
		result.push(array.dup)
		return
	end

	(index..n).each {|i|
		array.push(i)
		dfs(n, k, array, 1 + i, result)
		array.pop
	}
end

# @param {Integer} n
# @param {Integer} k
# @return {Integer[][]}
def combine(n, k)
	result = []
	dfs(n, k, [], 1, result)
	return result
end

p combine(2, 1)
