class ListNode
	attr_accessor :val, :next

	def initialize(val)
		@val = val
		@next = nil
	end
end

def partition(head, x)
	return nil if head == nil

	less = nil
	less_tail = nil
	greater_equal = nil
	greater_equal_tail = nil

	p = head
	while p != nil
		if p.val < x
			if less == nil
				less = p
				less_tail = p
			else
				fail unless less_tail != nil
				less_tail.next = p
				less_tail = less_tail.next
			end
		else
			if greater_equal == nil
				greater_equal = p
				greater_equal_tail = p
			else
				fail unless greater_equal_tail != nil
				greater_equal_tail.next = p
				greater_equal_tail = greater_equal_tail.next
			end
		end
		p = p.next
	end

	if greater_equal == nil
		less_tail.next = nil
		return less
	end
	if less == nil
		greater_equal_tail.next = nil
		return greater_equal
	end
	less_tail.next = greater_equal
	greater_equal_tail.next = nil

	return less
end

n1 = ListNode.new(2)
n2 = ListNode.new(1)
n1.next = n2
x = 2
p partition(n1, x)
