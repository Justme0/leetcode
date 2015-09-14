# Definition for singly-linked list.
class ListNode
	attr_accessor :val, :next
	def initialize(val)
		@val = val
		@next = nil
	end
end

# @param {ListNode} head
# @param {Integer} val
# @return {ListNode}
def remove_elements(head, val)
	dummy = ListNode.new(0)
	dummy.next = head

	pre = dummy
	while !pre.next.nil?
		if pre.next.val == val
			pre.next = pre.next.next
		else
			pre = pre.next
		end
	end

	dummy.next
end
