class ListNode
	attr_accessor :val, :next

	def initialize(val)
		@val = val
		@next = nil
	end
end

def partition(head, x)
	less_dummy = ListNode.new(0)
	greater_equal_dummy = ListNode.new(0)
	less = less_dummy
	greater_equal = greater_equal_dummy

	while head != nil
		if head.val < x
			less.next = head
			less = less.next
		else
			greater_equal.next = head
			greater_equal = greater_equal.next
		end
		head = head.next
	end

	less.next = greater_equal_dummy.next
	greater_equal.next = nil
	less_dummy.next
end

n1 = ListNode.new(2)
n2 = ListNode.new(1)
n1.next = n2
x = 2
p partition(n1, x)
